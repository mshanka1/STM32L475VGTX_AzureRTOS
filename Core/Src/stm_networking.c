/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */
#include <inttypes.h>
#include "stm_networking.h"

#include "nx_api.h"
#include "nx_driver_stm32l4.h"
//#include "nx_secure_tls_api.h"
#include "nxd_dns.h"

#include "wifi.h"
#include "WebServer.h"
#include "sntp_client.h"
#ifndef      NX_HTTP_NO_FILEX
#include    "fx_api.h"
#else
#include    "filex_stub.h"
#endif

#include "nxd_dhcp_client.h"
#include   "nxd_http_server.h"
#include "nxd_mqtt_client.h"

#define NETX_IP_STACK_SIZE 2048
#define NETX_PACKET_COUNT  20
#define NETX_PACKET_SIZE   1200 // Set the default value to 1200 since WIFI payload size (ES_WIFI_PAYLOAD_SIZE) is 1200
#define NETX_POOL_SIZE     ((NETX_PACKET_SIZE + sizeof(NX_PACKET)) * NETX_PACKET_COUNT)

#define NETX_IPV4_ADDRESS IP_ADDRESS(0, 0, 0, 0)
#define NETX_IPV4_MASK    IP_ADDRESS(255, 255, 255, 0)
#define HTTP_SERVER_ADDRESS  IP_ADDRESS(1,2,3,4)
#define MQTT_SERVER_ADDRESS  IP_ADDRESS(0, 0, 0, 0)


static UCHAR netx_ip_stack[NETX_IP_STACK_SIZE];
static UCHAR netx_ip_pool[NETX_POOL_SIZE];

static CHAR* netx_ssid;
static CHAR* netx_password;
static WIFI_Ecn_t netx_mode;
static ULONG     ip_status;


NX_DHCP   my_dhcp;
char  my_dhcp_name[]          = "SHANKAR";
NX_IP nx_ip;
NX_PACKET_POOL nx_pool ;
NX_DNS nx_dns_client;
ULONG           host_ip_address;
/* Define the ARP cache area.  */
ULONG             arp_space_area[512 / sizeof(ULONG)];
//http server
/* For NetX Duo applications, determine which IP version to use. For IPv6,
   set IP_TYPE to 6; for IPv4 set to 4. Note that for IPv6, you must enable
   USE_DUO so the application 'knows' to enabled IPv6 services on the IP task.  */

#ifdef NX_DISABLE_IPV4
#define     IP_TYPE     6
#else
#define     IP_TYPE     4
#endif /* NX_DISABLE_IPV4 */


#define     DEMO_STACK_SIZE         4096


/* Set up FileX and file memory resources. */
//UCHAR           ram_disk_memory[32000];
FX_MEDIA        ram_disk;
unsigned char   media_memory[512];
ULONG           http_server_stack_area[1024];
/////global wifi vareables///////
uint8_t wifi_mac[6];
UCHAR wifi_ip_address[4];
UCHAR wifi_ip_mask[4];
UCHAR wifi_gateway_address[4];
UCHAR wifi_dns_address_1[4];
UCHAR wifi_dns_address_2[4];

/* Define device drivers.  */
extern void _fx_ram_driver(FX_MEDIA *media_ptr);

/* Replace the 'ram' driver with your Ethernet driver. */
VOID        _nx_ram_network_driver(NX_IP_DRIVER *driver_req_ptr);
UINT 		http_request_notify(NX_HTTP_SERVER *server_ptr, UINT request_type,CHAR *resource, NX_PACKET *packet_ptr);

UINT        http_check_authentication(NX_HTTP_SERVER *server_ptr, UINT request_type,
                                 CHAR *resource, CHAR **name, CHAR **password, CHAR **realm);

NX_HTTP_SERVER  my_server;
NX_PACKET_POOL  server_pool;
TX_THREAD       server_thread;
NX_IP           server_ip;
NXD_ADDRESS     server_ip_address;
#define         SERVER_PACKET_SIZE  (NX_HTTP_SERVER_MIN_PACKET_SIZE * 2)
#define HTTP_SERVER_ADDRESS  IP_ADDRESS(1,2,3,4)
static int mqtt_connect_status;
// WiFi firmware version required
static const UINT wifi_required_version[] = {3, 5, 2, 7};
/* Define the application's authentication check.  This is called by
   the HTTP server whenever a new request is received.  */
UINT  http_check_authentication(NX_HTTP_SERVER *server_ptr, UINT request_type,
            CHAR *resource, CHAR **name, CHAR **password, CHAR **realm)
{
//    NX_PARAMETER_NOT_USED(server_ptr);
//    NX_PARAMETER_NOT_USED(request_type);
//    NX_PARAMETER_NOT_USED(resource);

    /* Just use a simple name, password, and realm for all
       requests and resources.  */
//    *name =     "name";
//    *password = "password";
//    *realm =    "NetX Duo HTTP demo";

    /* Request basic authentication.  */
//    return(NX_HTTP_BASIC_AUTHENTICATE);
	return(NX_SUCCESS);
}
/////////MQTT///////////////////////////////////
#define  MQTT_CLIENT_ID_STRING           "mytestclient"
#define  MQTT_CLIENT_STACK_SIZE     2048

#define  STRLEN(p)                  (sizeof(p) - 1)


/* Declare the MQTT thread stack space. */
static ULONG                        mqtt_client_stack[MQTT_CLIENT_STACK_SIZE / sizeof(ULONG)];

/* Declare the MQTT client control block. */
static NXD_MQTT_CLIENT              mqtt_client;

/* Define the symbol for signaling a received message. */


/* Define the test threads.  */
#define TOPIC_NAME                  "topic"
#define MESSAGE_STRING              "This is a message. "

#define  MQTT_LOCAL_SERVER_ADDRESS (IP_ADDRESS(10, 0, 0, 15))
/* Define the priority of the MQTT internal thread. */
#define MQTT_THREAD_PRIORTY         13

/* Define the MQTT keep alive timer for 5 minutes */
#define MQTT_KEEP_ALIVE_TIMER       300

#define QOS0                        0
#define QOS1                        1

/* Declare event flag, which is used in this demo. */
TX_EVENT_FLAGS_GROUP                mqtt_app_flag;
#define MQTT_DEMO_MESSAGE_EVENT          1
#define MQTT_DEMO_ALL_EVENTS             3

NXD_ADDRESS mqtt_server_ip;
ULONG           host_mqtt_ip_address;

/* Declare buffers to hold message and topic. */
static UCHAR MQTT_message_buffer[NXD_MQTT_MAX_MESSAGE_LENGTH];
static UCHAR MQTT_topic_buffer[NXD_MQTT_MAX_TOPIC_NAME_LENGTH];

/* Declare the disconnect notify function. */
static VOID MQTT_my_disconnect_func(NXD_MQTT_CLIENT *client_ptr)
{
    NX_PARAMETER_NOT_USED(client_ptr);
    printf("client disconnected from server\n");
}


static VOID MQTT_my_notify_func(NXD_MQTT_CLIENT* client_ptr, UINT number_of_messages)
{
    NX_PARAMETER_NOT_USED(client_ptr);
    NX_PARAMETER_NOT_USED(number_of_messages);
    tx_event_flags_set(&mqtt_app_flag, MQTT_DEMO_MESSAGE_EVENT, TX_OR);
    return;

}

//////////MQTT START////////////////////////////
/*===========================================================================*/

UINT http_request_notify(NX_HTTP_SERVER *server_ptr, UINT request_type,CHAR *resource, NX_PACKET *packet_ptr)
{
	unsigned int status;
    NX_PACKET *resp_packet_ptr = NULL;
    /** \brief static array holding the stylesheet.css file used on the webpage */
     unsigned const char style_sheet_css[] = {"BODY {margin-top: 0px;margin-left: 10pt;color: #000000;background-color: #eaeaea; font-size : 10pt;line-height : 11pt;font-family : Arial, Helvetica, sans-serif;}"
                                         "TH   {margin-top: 0px;margin-bottom: 0px;font-size : 10pt;line-height : 11pt;}"
                                         "TD   {margin-top: 0px;margin-bottom: 0px;font-size : 10pt;line-height : 11pt;}"
                                         "H1   {margin-top: 7pt;margin-bottom: 3pt;font-size : 14pt;line-height : 14pt;}"
                                         "H2   {margin-top: 8pt;margin-bottom: 6pt;font-size : 12pt;line-height : 12pt;}"};

     if(strcmp(resource,"/") == 0)
   {
     /* Found it, override the GET processing by sending the resource
     contents directly. */
     //nx_http_server_callback_data_send(server_ptr,
     //"HTTP/1.0 200 \r\nContent-Length: 103\r\nContent-Type: text/html\r\n\r\n", 63);
     //nx_http_server_callback_data_send(server_ptr, "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\">\n<html>\n<head><title>Shankar IOT</title><meta http-equiv=""content-type"" content=""text/html; charset=ISO-8859-1"">\n<link rel=""icon"" type=""image/ico"" href=""/favicon.ico""/>\n</head>\n<frameset rows=""193,*"" border=""0""/>\n<frame src=""/top.html"" name=""header"" noresize=""noresize"" scrolling=""no""/>\n<frameset cols=""243,*"" border=""0""/>\n<frame src=""/index.html"" name=""navigation"" noresize=""noresize""/>\n<frame src=""/main_overview.html"" name=""mainframe"" noresize=""noresize""/>\n</frameset>\n<noframes><body><h1>Willkommen!</h1><p>Dieses Projekt verwendet Frames.</p></body></noframes>\n</frameset>\n</html>\n", 700);
    	 status = webserver_framework_root(resp_packet_ptr,server_ptr);

     /* Return completion status. */
     //return(NX_HTTP_CALLBACK_COMPLETED);
   }
    else if(strcmp(resource,"/top.html") == 0)
   {
     /* Found it, override the GET processing by sending the resource
     contents directly. */
     //nx_http_server_callback_data_send(server_ptr,
     //"HTTP/1.0 200 \r\nContent-Length: 103\r\nContent-Type: text/html\r\n\r\n", 63);
     //nx_http_server_callback_data_send(server_ptr, "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\n<html>\n<title>Shankar IOT</title><meta http-equiv=""content-type"" content=""text/html; charset=ISO-8859-1""><style type=""text/css"">td {font-family:arial, sans-serif; font-size:12px;}table.list {width:623px; margin:0 0 18px 13px; background-color: #FFFFFF; border-collapse:collapse; font-family:arial, sans-serif; font-size:12px;}th.list {height:30px; padding:0 3px 0 5px; text-align:left; background-color: #BFD0DA; border-top:2px groove #EEEEEE; border-left:2px groove #EEEEEE; border-bottom:1px solid #E4EBEE;}td.list {border-left:1px solid #E4EBEE; border-bottom:1px solid #E4EBEE; padding:7px 10px 7px 5px; vertical-align:top;}</style><body style=""margin:0; background-color:#ffffff;"">\n", 900);
    	status = webserver_framework_top(resp_packet_ptr,server_ptr);

     /* Return completion status. */
     //return(NX_HTTP_CALLBACK_COMPLETED);
   }
    else if(strcmp(resource,"/main_overview.html") == 0)
   {
     /* Found it, override the GET processing by sending the resource
     contents directly. */
     //nx_http_server_callback_data_send(server_ptr,
     //"HTTP/1.0 200 \r\nContent-Length: 103\r\nContent-Type: text/html\r\n\r\n", 63);
     //nx_http_server_callback_data_send(server_ptr, "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\n<html>\n<title>Shankar IOT</title><meta http-equiv=""content-type"" content=""text/html; charset=ISO-8859-1""><style type=""text/css"">td {font-family:arial, sans-serif; font-size:12px;}table.list {width:623px; margin:0 0 18px 13px; background-color: #FFFFFF; border-collapse:collapse; font-family:arial, sans-serif; font-size:12px;}th.list {height:30px; padding:0 3px 0 5px; text-align:left; background-color: #BFD0DA; border-top:2px groove #EEEEEE; border-left:2px groove #EEEEEE; border-bottom:1px solid #E4EBEE;}td.list {border-left:1px solid #E4EBEE; border-bottom:1px solid #E4EBEE; padding:7px 10px 7px 5px; vertical-align:top;}</style><body style=""margin:0; background-color:#ffffff;"">\n", 900);

     /* Return completion status. */
     //return(NX_HTTP_CALLBACK_COMPLETED);
    	status = webserver_page_overview(resp_packet_ptr, server_ptr);
   }
    else if(strcmp(resource,"/index.html") == 0)
   {
     /* Found it, override the GET processing by sending the resource
     contents directly. */
     //nx_http_server_callback_data_send(server_ptr,
     //"HTTP/1.0 200 \r\nContent-Length: 103\r\nContent-Type: text/html\r\n\r\n", 63);
    	status = webserver_framework_index(resp_packet_ptr,server_ptr);

     /* Return completion status. */
     //return(NX_HTTP_CALLBACK_COMPLETED);
   }
    else if(strcmp(resource,"/stylesheet.css")==0)
    {
      /* send the stylesheet css file */
        nx_http_server_callback_data_send(server_ptr, (UCHAR*)style_sheet_css, sizeof(style_sheet_css));
    }
    else
    {
    	return(NX_SUCCESS);
    }

	return(NX_HTTP_CALLBACK_COMPLETED);
}
static void print_address(CHAR* preable, uint8_t address[4])
{
    printf("\t%s: %d.%d.%d.%d\r\n", preable, address[0], address[1], address[2], address[3]);
}

static bool check_firmware_version(CHAR* data)
{
    UINT status = 0;
    UINT version[4];

    status = sscanf(data, "C%d.%d.%d.%d.STM", &version[0], &version[1], &version[2], &version[3]);

    if (status <= 0)
    {
        printf("ERROR: Unable to decode WiFi firmware\r\n");
        return false;
    }

    for (int i = 0; i < 4; ++i)
    {
        if (version[i] > wifi_required_version[i])
        {
            return true;
        }
        else if (version[i] < wifi_required_version[i])
        {
            printf("ERROR: WIFI FIRMWARE IS OUTDATED, PLEASE UPDATE TO AVOID CONNECTION ISSUES\r\n");
            return false;
        }
    }

    return true;
}

static UINT wifi_init()
{
    CHAR data[32];

    printf("\r\nInitializing WiFi\r\n");

    if (netx_ssid[0] == 0)
    {
        printf("ERROR: wifi_ssid is empty\r\n");
        return NX_NOT_SUCCESSFUL;
    }

    if (WIFI_Init() != WIFI_STATUS_OK)
    {
        printf("ERROR: WIFI_Init\r\n");
        return NX_NOT_SUCCESSFUL;
    }

    WIFI_GetModuleID(data);
    printf("\tModule: %s\r\n", data);

    WIFI_GetMAC_Address(wifi_mac);
    printf("\tMAC address: %02X:%02X:%02X:%02X:%02X:%02X\r\n", wifi_mac[0], wifi_mac[1], wifi_mac[2], wifi_mac[3], wifi_mac[4], wifi_mac[5]);

    WIFI_GetModuleFwRevision(data);
    printf("\tFirmware revision: %s\r\n", data);

    if (check_firmware_version(data))
    {
        printf("SUCCESS: WiFi initialized\r\n");
    }

    return NX_SUCCESS;
}

static UINT dhcp_connect()
{
    UINT status;

    printf("\r\nInitializing DHCP\r\n");

    // Get WIFI information
    WIFI_GetIP_Address(wifi_ip_address);
    WIFI_GetIP_Mask(wifi_ip_mask);
    WIFI_GetGateway_Address(wifi_gateway_address);

    // Output IP address and gateway address
    print_address("IP address", wifi_ip_address);
    print_address("Mask", wifi_ip_mask);
    print_address("Gateway", wifi_gateway_address);

    // Set IP address
    if ((status = nx_ip_address_set(&nx_ip,
             IP_ADDRESS(wifi_ip_address[0], wifi_ip_address[1], wifi_ip_address[2], wifi_ip_address[3]),
             IP_ADDRESS(wifi_ip_mask[0], wifi_ip_mask[1], wifi_ip_mask[2], wifi_ip_mask[3]))))
    {
        printf("ERROR: nx_ip_address_set (0x%08x)\r\n", status);
        return status;
    }

    // Set gateway address
    if ((status = nx_ip_gateway_address_set(
             &nx_ip, IP_ADDRESS(wifi_gateway_address[0], wifi_gateway_address[1], wifi_gateway_address[2], wifi_gateway_address[3]))))
    {
        printf("ERROR: nx_ip_gateway_address_set (0x%08x)\r\n", status);
        return status;
    }

    printf("SUCCESS: DHCP initialized\r\n");

    return NX_SUCCESS;
}

static UINT dns_connect()
{
    UINT status;
    //UCHAR wifi_dns_address_1[4] = {0};
    //UCHAR wifi_dns_address_2[4] = {0};

    printf("\r\nInitializing DNS client\r\n");

    if (WIFI_GetDNS_Address(wifi_dns_address_1, wifi_dns_address_2) != WIFI_STATUS_OK)
    {
        printf("ERROR: WIFI_GetDNS_Address\r\n");
        return NX_NOT_SUCCESSFUL;
    }

    // Output DNS Server address
    print_address("DNS address 1", wifi_dns_address_1);
    print_address("DNS address 2", wifi_dns_address_2);

    if ((status = nx_dns_server_remove_all(&nx_dns_client)))
    {
        printf("ERROR: nx_dns_server_remove_all (0x%08x)\r\n", status);
    }
    else if (status = nx_dns_server_add(&nx_dns_client, IP_ADDRESS(wifi_dns_address_1[0], wifi_dns_address_1[1], wifi_dns_address_1[2], wifi_dns_address_1[3])))
    {
        printf("ERROR: nx_dns_server_add (0x%08x)\r\n", status);

     }
    else if ((status = nx_dns_server_add(
                  &nx_dns_client, IP_ADDRESS(wifi_dns_address_2[0], wifi_dns_address_2[1], wifi_dns_address_2[2], wifi_dns_address_2[3]))))
    {
        printf("ERROR: nx_dns_server_add (0x%08x)\r\n", status);
    }
    else
    {
        printf("SUCCESS: DNS client initialized\r\n");
    }
    return status;
}

UINT stm_network_init(CHAR* ssid, CHAR* password, WiFi_Mode mode)
{
    UINT status;
    ULONG     ip_address;
    ULONG     network_mask;
    //ULONG events;
    //UINT topic_length, message_length;

    // Stash WiFi credentials
    netx_ssid     = ssid;
    netx_password = password;
    if (netx_ssid[0] == 0)
    {
    	return 255;
    }

    switch (mode)
    {
        case None:
            netx_mode = WIFI_ECN_OPEN;
            break;
        case WEP:
            netx_mode = WIFI_ECN_WEP;
            break;
        case WPA_PSK_TKIP:
            netx_mode = WIFI_ECN_WPA_PSK;
            break;
        case WPA2_PSK_AES:
        default:
            netx_mode = WIFI_ECN_WPA2_PSK;
            break;
    };

    // Initialize the NetX system
    nx_system_initialize();

    // Initialize Wifi
    if ((status = wifi_init()))
    {
        printf("ERROR: wifi_init (0x%08x)\r\n", status);
    }

    // Create a packet pool
    if ((status = nx_packet_pool_create(
                 &nx_pool, "NetX Packet Pool", NETX_PACKET_SIZE, netx_ip_pool, NETX_POOL_SIZE)))
    {
        printf("ERROR: nx_packet_pool_create (0x%08x)\r\n", status);
    }

    // Create an IP instance
    if ((status = nx_ip_create(&nx_ip,
                  "NetX IP Instance 0",
                  NETX_IPV4_ADDRESS,
                  NETX_IPV4_MASK,
                  &nx_pool,
                  nx_driver_stm32l4,
                  (UCHAR*)netx_ip_stack,
                  NETX_IP_STACK_SIZE,
                  1)))
    {
        nx_packet_pool_delete(&nx_pool);
        printf("ERROR: nx_ip_create (0x%08x)\r\n", status);
    }
#ifndef NX_DISABLE_IPV4
    if(status = nx_arp_enable( &nx_ip,(void *)arp_space_area, sizeof(arp_space_area)))
    {
        nx_ip_delete(&nx_ip);
        nx_packet_pool_delete(&nx_pool);
        printf("ERROR: nx_arp_enable (0x%08x)\r\n", status);

    }
#endif
    // Enable ICMP traffic
    if ((status = nx_icmp_enable(&nx_ip)))
    {
        nx_ip_delete(&nx_ip);
        nx_packet_pool_delete(&nx_pool);
        printf("ERROR: nx_udp_enable (0x%08x)\r\n", status);
    }
    // Enable TCP traffic
    if ((status = nx_tcp_enable(&nx_ip)))
    {
        nx_ip_delete(&nx_ip);
        nx_packet_pool_delete(&nx_pool);
        printf("ERROR: nx_tcp_enable (0x%08x)\r\n", status);
    }

    // Enable UDP traffic
    if ((status = nx_udp_enable(&nx_ip)))
    {
        nx_ip_delete(&nx_ip);
        nx_packet_pool_delete(&nx_pool);
        printf("ERROR: nx_udp_enable (0x%08x)\r\n", status);
    }


    // Enable ip fragment
    if ((status = nx_ip_fragment_enable(&nx_ip)))
    {
        nx_ip_delete(&nx_ip);
        nx_packet_pool_delete(&nx_pool);
        printf("ERROR: nx_udp_enable (0x%08x)\r\n", status);
    }

    if ((status = nx_dns_create(&nx_dns_client, &nx_ip, (UCHAR*)"DNS Client")))
    {
        nx_ip_delete(&nx_ip);
        nx_packet_pool_delete(&nx_pool);
        printf("ERROR: nx_dns_create (0x%08x)\r\n", status);
    }



    // Use the packet pool here
#ifdef NX_DNS_CLIENT_USER_CREATE_PACKET_POOL
    if ((status = nx_dns_packet_pool_set(&nx_dns_client, nx_ip.nx_ip_default_packet_pool)))
    {
        nx_dns_delete(&nx_dns_client);
        nx_ip_delete(&nx_ip);
        nx_packet_pool_delete(&nx_pool);
        printf("ERROR: nx_dns_packet_pool_set (%0x08)\r\n", status);
    }
#endif
    // Initialize the SNTP client
    if ((status = sntp_init()))
    {
        nx_dns_delete(&nx_dns_client);
        nx_ip_delete(&nx_ip);
        nx_packet_pool_delete(&nx_pool);
        printf("ERROR: Failed to init the SNTP client (0x%08x)\r\n", status);
    }
    do
    {
      /* Wait for the link to become ready */
      status = nx_ip_status_check(&nx_ip, NX_IP_ADDRESS_RESOLVED, &ip_status, 100);
    } while(status != TX_SUCCESS);

    /* Create the DHCP instance */
    if(status = nx_dhcp_create(&my_dhcp, &nx_ip, my_dhcp_name))
    {
    	printf("ERROR: Failed to create dhcp client (0x%08x)\r\n", status);
    }
    //create_dhcp_client();

    /* Set the network_enabled flag */
    //set_network_enabled(true);
    if(status = stm_network_connect())
    {
    	printf("ERROR: Failed to connect to network (0x%08x)\r\n", status);
    }
    nx_dhcp_stop(&my_dhcp);
    nx_dhcp_reinitialize(&my_dhcp);
    nx_dhcp_start(&my_dhcp);
    do
    {
      /* Wait for the link to become ready */
      status = nx_ip_status_check(&nx_ip, NX_IP_ADDRESS_RESOLVED, &ip_status, 100);
    } while(status != TX_SUCCESS);
#if 0
    /* Create the HTTP Server.  */
    if(status = nx_http_server_create(&my_server, "Shankar HTTP Server", &nx_ip,&ram_disk,
                          (ULONG*)http_server_stack_area, sizeof(http_server_stack_area), &nx_pool, http_check_authentication, http_request_notify))
    {
    	nx_http_server_delete(&my_server);
    	printf("ERROR: Failed to create http server (0x%08x)\r\n", status);
    }

    /* OK to start the HTTP Server.   */
    if(status = nx_http_server_start(&my_server))
    {
    	printf("ERROR: Failed to start http server (0x%08x)\r\n", status);
    }
    tx_thread_sleep(2000);
#endif
    return status;
}
UINT stm_http_server()
{
    UINT status;
    /* Create the HTTP Server.  */
    if(status = nx_http_server_create(&my_server, "Shankar HTTP Server", &nx_ip,&ram_disk,
                          (ULONG*)http_server_stack_area, sizeof(http_server_stack_area), &nx_pool, http_check_authentication, http_request_notify))
    {
    	nx_http_server_delete(&my_server);
    	printf("ERROR: Failed to create http server (0x%08x)\r\n", status);
    }

    /* OK to start the HTTP Server.   */
    if(status = nx_http_server_start(&my_server))
    {
    	printf("ERROR: Failed to start http server (0x%08x)\r\n", status);
    }
    tx_thread_sleep(2000);

    return status;

}
/*MQTT API
 *
 */
UINT stm_mqtt_pubsub()
{
    UINT status;
    ULONG events;
    UINT topic_length, message_length;
    ULONG     ip_address;
    ULONG     network_mask;

    if(mqtt_connect_status==0)
    {
    	mqtt_connect_status=1;
        if(status =  nx_ip_address_get(&nx_ip, &ip_address, &network_mask))
        {
        	printf("ERROR: Failed to get ip (0x%08x)\r\n", status);
        }
        if(status = nxd_mqtt_client_create(&mqtt_client, "my_client", MQTT_CLIENT_ID_STRING, STRLEN(MQTT_CLIENT_ID_STRING),
        							&nx_ip,
    								&nx_pool,
    								(VOID*)mqtt_client_stack,
    								sizeof(mqtt_client_stack),
                                        MQTT_THREAD_PRIORTY, NX_NULL, 0))
        {
        	printf("Error in creating MQTT client: 0x%02x\n", status);
        }
		if(host_ip_address==0)
		{
			if(WIFI_GetHostAddress("xyz",&host_ip_address) != WIFI_STATUS_OK)
			{
				printf("ERROR: WIFI_GetDNS_Address\r\n");
				return NX_NOT_SUCCESSFUL;
			}
		}
		host_ip_address=__builtin_bswap32(host_ip_address);
	#ifdef NXD_MQTT_OVER_WEBSOCKET
		//status = nxd_mqtt_client_websocket_set(&mqtt_client, (UCHAR *)"MY-PC", sizeof("MY-PC") - 1,
			//								   (UCHAR *)"mqtt://MY-PC:1883", sizeof("mqtt://MY-PC:1883") - 1);
		//if (status)
		//{
			//printf("Error in setting MQTT over WebSocket: 0x%02x\r\n", status);
			//error_counter++;
		//}
	#endif /* NXD_MQTT_OVER_WEBSOCKET */

		/* Register the disconnect notification function. */
		nxd_mqtt_client_disconnect_notify_set(&mqtt_client, MQTT_my_disconnect_func);

		/* Create an event flag for this demo. */
		status = tx_event_flags_create(&mqtt_app_flag, "my app event");


		mqtt_server_ip.nxd_ip_version = 4;
		mqtt_server_ip.nxd_ip_address.v4 = host_ip_address;//MQTT_LOCAL_SERVER_ADDRESS;//


		/* Start the connection to the server. */
		status = nxd_mqtt_client_login_set(&mqtt_client,"xyz", strlen("xyz"),"xyz",strlen("xyz"));
		status = nxd_mqtt_client_connect(&mqtt_client, &mqtt_server_ip, NXD_MQTT_PORT,
										 MQTT_KEEP_ALIVE_TIMER, 0, NX_WAIT_FOREVER);

		/* Subscribe to the topic with QoS level 0. */
		status = nxd_mqtt_client_subscribe(&mqtt_client, TOPIC_NAME, STRLEN(TOPIC_NAME), QOS0);

		/* Set the receive notify function. */
		status = nxd_mqtt_client_receive_notify_set(&mqtt_client, MQTT_my_notify_func);

		/* Publish a message with QoS Level 1. */
		status = nxd_mqtt_client_publish(&mqtt_client, TOPIC_NAME, STRLEN(TOPIC_NAME),
										 (CHAR*)MESSAGE_STRING, STRLEN(MESSAGE_STRING), 0, QOS1, NX_WAIT_FOREVER);

		if(status!=0){
		mqtt_connect_status=0;
		}
	}

    /* Now wait for the broker to publish the message. */
    if(mqtt_connect_status==1)
    {

		tx_event_flags_get(&mqtt_app_flag, MQTT_DEMO_ALL_EVENTS, TX_OR_CLEAR, &events, 1000);
		if(events & MQTT_DEMO_MESSAGE_EVENT)
		{
			status = nxd_mqtt_client_message_get(&mqtt_client, MQTT_topic_buffer, sizeof(MQTT_topic_buffer), &topic_length,
												 MQTT_message_buffer, sizeof(MQTT_message_buffer), &message_length);
			if(status == NXD_MQTT_SUCCESS)
			{
				MQTT_topic_buffer[topic_length] = 0;
				MQTT_message_buffer[message_length] = 0;
				printf("topic = %s, message = %s\n", MQTT_topic_buffer, MQTT_message_buffer);
			}
		}
    }
    if(mqtt_connect_status==0)
    {

    /* Now unsubscribe the topic. */
    nxd_mqtt_client_unsubscribe(&mqtt_client, TOPIC_NAME, STRLEN(TOPIC_NAME));
    /* Disconnect from the broker. */
	nxd_mqtt_client_disconnect(&mqtt_client);

	/* Delete the client instance, release all the resources. */
	nxd_mqtt_client_delete(&mqtt_client);
    }
    return status;

}
UINT stm_network_connect()
{
    UINT status;
    int32_t wifiConnectCounter = 1;
    WIFI_Status_t join_result;

    // Check if Wifi is already connected
    if (WIFI_IsConnected() != WIFI_STATUS_OK)
    {
        printf("\r\nConnecting WiFi\r\n");

        // Connect to the specified SSID
        printf("\tConnecting to SSID '%s'\r\n", netx_ssid);
        do
        {
            printf("\tAttempt %ld...\r\n", wifiConnectCounter++);

            // Obtain the IP internal mutex before reconnecting WiFi
            tx_mutex_get(&(nx_ip.nx_ip_protection), TX_WAIT_FOREVER);
            join_result = WIFI_Connect(netx_ssid, netx_password, netx_mode);
            tx_mutex_put(&(nx_ip.nx_ip_protection));

            tx_thread_sleep(5 * TX_TIMER_TICKS_PER_SECOND);
        } while (join_result != NX_SUCCESS);

        printf("SUCCESS: WiFi connected\r\n");
    }

    // Fetch IP details
    if ((status = dhcp_connect()))
    {
        printf("ERROR: dhcp_connect\r\n");
    }

    // Create DNS
    else if ((status = dns_connect()))
    {
        printf("ERROR: dns_connect\r\n");
    }
    // Wait for an SNTP sync
    else if ((status = sntp_sync()))
    {
        printf("ERROR: Failed to sync SNTP time (0x%08x)\r\n", status);
    }
    return status;
}
