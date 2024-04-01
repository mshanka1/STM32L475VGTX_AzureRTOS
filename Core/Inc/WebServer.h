/*
 * WebServer.h
 *
 *  Created on: Mar 24, 2024
 *      Author: Shankar
 */

#ifndef INC_WEBSERVER_H_
#define INC_WEBSERVER_H_
#include "main.h"
#include "tx_api.h"
#include "nx_api.h"
#include "nxd_dns.h"
#include   "nxd_http_server.h"

#define htmlresponse "HTTP/1.0 200 \r\nContent-Type: text/html\r\n\r\n"
#define htmldoctype  "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\n"
#define htmltag      "<HTML>"
#define htmlendtag   "</HTML>"
#define bodyendtag "</body>\r\n"
#define formtag       "<form action=\"/test.htm\" method=\"get\">"
#define bodybegin(__str,__attr)                  sprintf(__str,"<body %s > \r\n",__attr)
#define formbegin(__str,__url,__attr)           sprintf(__str,"<form action=\"%s\" %s > \n",__url,__attr)
#define formendtag                              "</form>"
#define tablebegin(__str,__attr)                sprintf(__str,"<table %s > \n",__attr)
#define tableHeader(__str, content, __attr)     sprintf(__str,"<th %s> %s </th> \n",__attr,content)
#define tablerowbegin(__str, __attr)            sprintf(__str,"<tr %s>\n",__attr)
#define tabledatabegin(__str, __attr)           sprintf(__str,"<td %s>\n",__attr)
#define tablerowend                             "</TR>\n"
#define tabledataend                            "</TD>\n"
#define tableend                                "</TABLE>"
#define Parabegin(__str,__attr)                 sprintf(__str,"<p %s> \n",__attr)
#define Paraend                                 "</p>"
#define doublebr                                "<br><br>"
#define singlebr                                "<br>"
#define forminput(__str,__type, __name, __value, __attr)           sprintf(__str,"<input type=\"%s\" name=\"%s\" value=\"%s\" %s > \n",__type, __name, __value, __attr)
#define h1line(__str, __dispstr)              sprintf(__str,"<H1> %s </H1>\n",__dispstr)
#define h2line(__str, __dispstr)              sprintf(__str,"<H2> %s </H2>\n",__dispstr)
#define trtag                                 "<TR>"
#define tdtag                                 "<TD>"


extern uint8_t wifi_mac[6];
extern UCHAR wifi_ip_address[4];
extern UCHAR wifi_ip_mask[4];
extern UCHAR wifi_gateway_address[4];
extern UCHAR wifi_dns_address_1[4];
extern UCHAR wifi_dns_address_2[4];


extern int         webserver_framework_root         (NX_PACKET*, NX_HTTP_SERVER*);
extern int         webserver_framework_top          (NX_PACKET*, NX_HTTP_SERVER*);
extern int         webserver_framework_index        (NX_PACKET*, NX_HTTP_SERVER*);
extern int         webserver_page_overview          (NX_PACKET*, NX_HTTP_SERVER*);
extern int         webserver_page_version           (NX_PACKET*, NX_HTTP_SERVER*);
extern int         webserver_page_contact           (NX_PACKET* , NX_HTTP_SERVER*);
extern int         webserver_page_login             (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr, char* pFilename, char* pFormdata);
extern int         webserver_page_logout            (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr);
extern int         webserver_page_deviceconfig      (NX_PACKET*, NX_HTTP_SERVER*, char*, char*);
extern int 		   webserver_page_shankariot		(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char*,char*);


#endif /* INC_WEBSERVER_H_ */
