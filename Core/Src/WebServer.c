/*
 * WebServer.c
 *
 *  Created on: Mar 24, 2024
 *      Author: Shankar
 */

/*===========================================================================*/
#include "WebServer.h"

#define htmlwrite(p,server_ptr,string)  (nx_packet_data_append(p,string,strlen(string), server_ptr-> nx_http_server_packet_pool_ptr, NX_WAIT_FOREVER))

static int         AddHtmlHeader                    (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* htmlheader,char* bodyattr);
static int         AddHtmlFooter                    (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr);
static int         AddH1                            (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr, char* str, char* dispstr);
static int         AddH2                            (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr, char* str, char* dispstr);
static int         AddTableData                     (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr, char* str, char* attr, char* strbuf);
static int         AddTableRowWithoutAttribute      (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* str1, char* attr1,char* str2, char* attr2, char* htmlheader);
static int         AddParagraph                     (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* str, char* attr,char* htmlheader);
static int         CreateHtmlTable                  (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* strbuffer,char* attribute);
static int         CreateTableRow                   (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* strbuffer,char* attribute);
static int         CreateTableData                  (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* strbuffer,char* attribute);
static int         CloseTable                       (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr);
static int         CloseTableRow                    (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr);
static int         CloseTableData                   (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr);
static int         CloseHtmlTag                     (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr);
static int         SingleBrTag                      (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr);
static int         DoubleBrTag                      (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr);
static int         WriteStringToHtmlBuffer          (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* strbuffer);
static int         AddStyleSheet                    (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* strbuffer);
static int         AddHtmlForm                      (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* strbuffer,char* attribute,char* Filename);
static int         AddTableHeader                   (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* strbuffer,char* attribute,char* string);
static int         WriteTag                         (NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* strbuffer);

/**
 * The function AddHtmlHeader()
 * This function adds the following html tags as html header.
 *      a. html respone "HTTP/1.0 200 \r\nContent-Type: text/html\r\n\r\n"
 *      b. html document type "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\n"
 *      b. html header
 *      b. html body
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
 * @param[in] htmlheader
 * - type : char *
 * @param[in] bodyattr
 * - type : char *
 */
//static int get_user_type( FILE* pClient, unsigned char *pType, unsigned char *pStatus)
static int AddHtmlHeader(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* htmlheader,char* bodyattr)
{
  int status;
   /* Allocate the html buffer*/
  status = nx_packet_allocate(server_ptr -> nx_http_server_packet_pool_ptr, &resp_packet_ptr, NX_TCP_PACKET, NX_WAIT_FOREVER);
  status += WriteTag(resp_packet_ptr, server_ptr, htmlresponse);
  status += WriteTag(resp_packet_ptr, server_ptr, htmldoctype);
  status += WriteTag(resp_packet_ptr, server_ptr, htmlheader );
  bodybegin(htmlheader,bodyattr);
  status += WriteTag(resp_packet_ptr, server_ptr, htmlheader );
  /* Send the buffer data*/
  status +=  nx_tcp_socket_send(&(server_ptr -> nx_http_server_socket), resp_packet_ptr, NX_HTTP_SERVER_TIMEOUT);
  if(status)
  {
    /* Any error occurs then release the buffer*/
    nx_packet_release(resp_packet_ptr);
    /*Increase the Failcount*/
    //u32WebFailcount++;
  }

  return status;
}
/**
 * The function AddHtmlFooter()
 * This function adds the following html tags as html footer.
 *      a. html body end tag
 *      b. html end tag
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
 */
static int AddHtmlFooter(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr)
{
   int status;
    /* Allocate the html buffer*/
   status = nx_packet_allocate(server_ptr -> nx_http_server_packet_pool_ptr, &resp_packet_ptr, NX_TCP_PACKET, NX_WAIT_FOREVER);
   status += WriteTag(resp_packet_ptr, server_ptr, bodyendtag );
   status += WriteTag(resp_packet_ptr, server_ptr, htmlendtag );
  /* Send the buffer data*/
  status +=  nx_tcp_socket_send(&(server_ptr -> nx_http_server_socket), resp_packet_ptr, NX_HTTP_SERVER_TIMEOUT);
  if(status)
  {
    /* Any error occurs then release the buffer*/
    nx_packet_release(resp_packet_ptr);
    /*Increase the Failcount*/
    //u32WebFailcount++;
  }
   return status;
}
/**
 * The function AddH1()
 * This function adds the header1 tag.
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
 * @param[in] str - string to display using H1 tag
 * - type : char *
 * @param[in] strbuf - buffer to use format the string with H1 tag
 * - type : char *
 */
static int AddH1(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr, char* str, char* strbuf)
{
  int status;
  h1line(strbuf,str);
  status = WriteTag(resp_packet_ptr, server_ptr, strbuf );
  return status;
}
/**
 * The function AddH2()
 * This function adds the header2 tag.
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
 * @param[in] str - string to display using H2 tag
 * - type : char *
 * @param[in] strbuf - buffer to use format the string with H2 tag
 * - type : char *
 */
static int AddH2(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr, char* str, char* strbuf)
{
  int status;
  h2line(strbuf,str);
  status = WriteTag(resp_packet_ptr, server_ptr, strbuf );
  return status;
}
/**
 * The function createtable()
 * This function creates the table with given attribute.
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
 * @param[in] strbuffer - string buffer used to format the table attribute with table tag.
 * - type : char *
 * @param[in] attribute - table attribute
 * - type : char *
 */
static int CreateHtmlTable(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* strbuffer,char* attribute)
{
  int status;
  tablebegin(strbuffer,attribute);
  status = WriteTag(resp_packet_ptr, server_ptr, strbuffer );
  return status;
}
/**
 * The function createtablerow()
 * This function creates the table row with given attribute.
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
 * @param[in] strbuffer - string buffer used to format the table row attribute row with table row tag.
 * - type : char *
 * @param[in] attribute - table row attribute
 * - type : char *
 */
static int CreateTableRow(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* strbuffer,char* attribute)
{
  int status;
  tablerowbegin(strbuffer,attribute);
  status = WriteTag(resp_packet_ptr, server_ptr, strbuffer );
  return status;
}
/**
 * The function createtabledata()
 * This function creates the table data with given attribute.
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
 * @param[in] strbuffer - string buffer used to format the table data attribute row with table data tag.
 * - type : char *
 * @param[in] attribute - table data attribute
 * - type : char *
 */
static int CreateTableData(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* strbuffer,char* attribute)
{
  int status;
  tabledatabegin(strbuffer,attribute);
  status = WriteTag(resp_packet_ptr, server_ptr, strbuffer );
  return status;
}
/**
 * The function closetable()
 * This function closes the table.
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
 */
static int CloseTable(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr)
{
  int status;
  status = WriteTag(resp_packet_ptr, server_ptr, tableend );
  return status;
}
/**
 * The function closetablerow()
 * This function closes the table row.
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
 */
static int CloseTableRow(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr)
{
  int status;
  status = WriteTag(resp_packet_ptr, server_ptr, tablerowend );
  return status;
}
/**
 * The function closetabledata()
 * This function closes the table data.
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
 */
static int CloseTableData(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr)
{
  int status;
  status = WriteTag(resp_packet_ptr, server_ptr, tabledataend );
  return status;
}
/**
 * The function CloseHtmlEndTag()
 * This function closes the html data.
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
 */
static int CloseHtmlTag(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr)
{
  int status;
  status = WriteTag(resp_packet_ptr, server_ptr, htmlendtag );
  return status;
}
/**
 * The function SingleBrTag()
 * This function insert single br.
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
 */
static int SingleBrTag(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr)
{
  int status;
  status = WriteTag(resp_packet_ptr, server_ptr, singlebr );
  return status;
}
/**
 * The function DoubleBrTag()
 * This function double single br.
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
 */
static int DoubleBrTag(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr)
{
  int status;
  status = WriteTag(resp_packet_ptr, server_ptr, doublebr );
  return status;
}
/**
 * The function WriteStringToHtmlBuffer()
 * This function writes the string to html buffer.
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
  * @param[in] strbuffer
 * - type : char *
 */
static int WriteStringToHtmlBuffer(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* strbuffer)
{
    int status;
    status = WriteTag(resp_packet_ptr, server_ptr, strbuffer );
    return status;
}
/**
 * The function AddStyleSheet()
 * This function writes the style sheet to buffer.
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
  * @param[in] strbuffer
 * - type : char *
 */
static int AddStyleSheet(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* strbuffer)
{
    int status;
    status = WriteTag(resp_packet_ptr, server_ptr, strbuffer );
    return status;
}
/**
 * The function AddHtmlForm()
 * This function writes the html form to buffer.
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
  * @param[in] strbuffer
 * - type : char *
  * @param[in] attribute
 * - type : char *
  * @param[in] Filename
 * - type : char *
 */
static int AddHtmlForm(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* strbuffer,char* attribute,char* Filename)
{
    int status;
    formbegin(strbuffer,Filename,attribute);
    status = WriteTag(resp_packet_ptr, server_ptr, strbuffer );
    return status;
}
/**
 * The function AddTableHeader()
 * This function writes the html table header to buffer.
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
  * @param[in] strbuffer
 * - type : char *
  * @param[in] attribute
 * - type : char *
  * @param[in] string
 * - type : char *
 */
static int AddTableHeader(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* strbuffer,char* attribute,char* string)
{
    int status;
    tableHeader(strbuffer,string,attribute);
    status = WriteTag(resp_packet_ptr, server_ptr, strbuffer );
    return status;
}
/**
 * The function WriteTag()
 * This function writes the html tag to buffer.
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
  * @param[in] strbuffer
 * - type : char *
  * @param[in] attribute
 * - type : char *
  * @param[in] string
 * - type : char *
 */
static int WriteTag(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* strbuffer)
{
    int status;
    status = htmlwrite(resp_packet_ptr, server_ptr, strbuffer);
    return status;
}
/**
 * The function AddTableData()
 * This function adds the table data tag with content.
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
 * @param[in] str - table data string
 * - type : char *
 * @param[in] attr - Table data attribute
 * - type : char *
 * @param[in] strbuf - buffer to use format the attribute with td tag
 * - type : char *
 */
static int AddTableData(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr, char* str, char* attr, char* strbuf)
{
  int status;
  status = CreateTableData(resp_packet_ptr,server_ptr,strbuf,attr);
  status += WriteStringToHtmlBuffer(resp_packet_ptr, server_ptr,str);
  status += CloseTableData(resp_packet_ptr,server_ptr);
  return status;
}
/**
 * The function AddTableRowWithoutAttribute()
 * This function adds the table row with content.
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
 * @param[in] str1 - First table data string
 * - type : char *
 * @param[in] attr1 - First Table data attribute
 * - type : char *
 * @param[in] str2 - Second table data string
 * - type : char *
 * @param[in] attr2 - Second Table data attribute
 * - type : char *
 * @param[in] htmlheader - buffer to use format the attribute with table data and table row tag
 * - type : char *
 */
static int AddTableRowWithoutAttribute(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr, \
                                       char* str1, char* attr1,char* str2, char* attr2, char* htmlheader)
{
  int status;
  /* Begin the table row without attribute*/
  status = CreateTableRow(resp_packet_ptr,server_ptr,htmlheader,"");
  {
    /*Begin the first table data with attribute (attr1) and content(str1)*/
    status += AddTableData(resp_packet_ptr,server_ptr,str1,attr1,htmlheader);
    /*Begin the second table data with attribute(atr2) and content(str2)*/
    status += AddTableData(resp_packet_ptr,server_ptr,str2,attr2,htmlheader);
  }
  /*Close the table row*/
  status += CloseTableRow(resp_packet_ptr, server_ptr);
  /*return the status*/
  return status;
}
/**
 * The function AddParagraph()
 * This function adds the paragraph with content.
 * @return
 * - type : int
 * @param[in] resp_packet_ptr
 * - type : NX_PACKET *
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER *
 * @param[in] str - Paragraph string
 * - type : char *
 * @param[in] attr - Paragraph attribute
 * @param[in] htmlheader - buffer to use format the attribute with paragraph tag
 * - type : char *
 */
static int AddParagraph(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr,char* str, char* attr,char* htmlheader)
{
   int status;
   Parabegin(htmlheader,attr);
   status = WriteTag(resp_packet_ptr, server_ptr, htmlheader);
   status += WriteTag(resp_packet_ptr, server_ptr, str);
   //status += WriteTag(resp_packet_ptr, server_ptr, str);
   /*return the status*/
   return status;
}
/*===========================================================================*/

/**
 * The function webserver_framework_root() sends the index page to the web browser. The webpage
 * consists of a framework with three frames. This function only transmits the layout of the
 * framework and the browser then requests the content of the frames by additional requests to the
 * addresses /top.html, /index.html and /main_overview.html
 *
 * Layout:
\verbatim
 ===============================================
 =              header(top.html)               =
 =---------------------------------------------=
 =            |                                =
 =            |                                =
 =            |                                =
 = navigation |          mainframe             =
 =(index.html)|     (e.g. overview.html)       =
 =            |                                =
 =            |                                =
 =            |                                =
 =            |                                =
 ===============================================
\endverbatim
 *
 * @return
 * - type  : int
 * @param[out] resp_packet_ptr
 * - type : NX_PACKET*
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER*
 */
int webserver_framework_root(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr)
{
 /* page status*/
  int status;
  /* html header information for this page*/
  char root_htmlheader[] = {"<head><title>SHANKARIOT</title><meta http-equiv=\"content-type\" content=\"text/html; charset=ISO-8859-1\"> </head> \
                       <link rel=\"icon\" type=\"image/ico\" href=\"/favicon.ico\"> <head>\n \
                       <frameset rows=\"116,*\" border=\"0\">\n \
                       <frame src=\"/top.html\" name=\"header\" noresize=\"noresize\" scrolling=\"no\">\n \
                       <frameset cols=\"260,*\" border=\"0\"> \
                       <frame src=\"/index.html\" name=\"navigation\" noresize=\"noresize\">\n \
                       <frame src=\"/main_overview.html\" name=\"mainframe\" noresize=\"noresize\">\n \
                       </frameset>\n \
                       <noframes><body><h1>Willkommen!</h1><p>This project uses Frames.</p></body></noframes> \
                       </frameset>\n"};

    /* Add the HTML header for this page. it includes header and body tag also; body attribute is null*/
  //strncpy(verProductName, GFWebServerAPI_getProductName(), sizeof(verProductName));
  status = AddHtmlHeader(resp_packet_ptr,server_ptr,root_htmlheader,"");
   /* Allocate the html buffer*/
  status = nx_packet_allocate(server_ptr -> nx_http_server_packet_pool_ptr, &resp_packet_ptr, NX_TCP_PACKET, NX_WAIT_FOREVER);

  status += CloseHtmlTag(resp_packet_ptr,server_ptr);

   /* Send the buffer data*/
  status +=  nx_tcp_socket_send(&(server_ptr -> nx_http_server_socket), resp_packet_ptr, NX_HTTP_SERVER_TIMEOUT);
  if(status)
  {
    /* Any error occurs then release the buffer*/
    nx_packet_release(resp_packet_ptr);
    /*Increase the Failcount*/
    //u32WebFailcount++;
  }

   /*return the status of this page creation*/
   return status;
}

/*===========================================================================*/

/**
 * The function webserver_framework_top() sends the page for the top frame to the
 * web browser. The page URL is /top.html.
 *
 * @return
 * - type  : int
 * @param[out] resp_packet_ptr
 * - type : NX_PACKET*
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER*
 */

int webserver_framework_top(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr)
{
    /* page status*/
  int status;
  char tempStr[100] = {'\0'};
  char top_htmlheader[] = {"<head><title>SHANKARIOT</title><meta http-equiv=\"content-type\" content=\"text/html; charset=ISO-8859-1\"></head> \
                       <style type=\"text/css\">\n \
                       td {font-family:arial, sans-serif; font-size:12px;}\n \
                       table.list {width:623px; margin:0 0 18px 13px; background-color: #FFFFFF; border-collapse:collapse; font-family:arial, sans-serif; font-size:12px;}\n \
                       th.list {height:30px; padding:0 3px 0 5px; text-align:left; background-color: #BFD0DA; border-top:2px groove #EEEEEE; border-left:2px groove #EEEEEE; border-bottom:1px solid #E4EBEE;}\n \
                       td.list {border-left:1px solid #E4EBEE; border-bottom:1px solid #E4EBEE; padding:7px 10px 7px 5px; vertical-align:top;}\n \
                       </style>\n"};
  /* html header information for this page*/

    /* Add the HTML header for this page. it includes header and body tag also; body attribute is "style=\"margin:0; background-color:#ffffff;\""*/
  status = AddHtmlHeader(resp_packet_ptr,server_ptr,top_htmlheader,"style=\"margin:0; background-color:#ffffff;\"");
  {
    /* Allocate the html buffer*/
    status = nx_packet_allocate(server_ptr -> nx_http_server_packet_pool_ptr, &resp_packet_ptr, NX_TCP_PACKET, NX_WAIT_FOREVER);

    /* Begin the table with attribute*/

    status += CreateHtmlTable(resp_packet_ptr,server_ptr,top_htmlheader,"width=\"100%\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\" "
                              "style=\"background-color: #064b86;\"");
    {
      /* Begin the table row with  attribute */
      status += CreateTableRow(resp_packet_ptr,server_ptr,top_htmlheader,"style=\"height:60px\"");
      {
        /*Begin the table data with attribute and content("&nbsp;")*/
        status += AddTableData(resp_packet_ptr,server_ptr,"&nbsp;","colspan=\"5\"",top_htmlheader);

        /*Close the table row*/
        status += CloseTableRow(resp_packet_ptr, server_ptr);
      }

      /* Begin the table row with  attribute*/
      status += CreateTableRow(resp_packet_ptr,server_ptr,top_htmlheader,"style=\"height:36px\"");
      {
        /*Begin the table data with attribute and content("&nbsp;")*/
        status += AddTableData(resp_packet_ptr,server_ptr,"&nbsp;","style=\"width:40px\"",top_htmlheader);
        /*Begin the table data with attribute and logo.gif*/
        status += AddTableData(resp_packet_ptr,server_ptr,"<img src=\"/logo.gif\" alt=\"logo.gif\" width=\"210\" border=\"0\" height=\"31\">","valign=\"middle\" style=\"width:210px\" align=\"center\"",top_htmlheader);
         /*Begin the table data without attribute and content("&nbsp;")*/
        status += AddTableData(resp_packet_ptr,server_ptr,"&nbsp;","",top_htmlheader);
       /*Begin the table data with attribute and logo.gif*/
        //sprintf(tempStr,"<b>%s</b>",verProductName);
        strcat(tempStr," - Shankar IOT");
        status += AddTableData(resp_packet_ptr,server_ptr,tempStr,"valign=\"bottom\" align=\"right\" style=\"font-weight:bold; color: #ffffff\"",top_htmlheader);
        /*Begin the table data with attribute and content("&nbsp;")*/
        status += AddTableData(resp_packet_ptr,server_ptr,"&nbsp;","style=\"width:40px\"",top_htmlheader);
        /*Close the table row*/
        status += CloseTableRow(resp_packet_ptr, server_ptr);
      }

      /* Begin the table row with  attribute*/
      status += CreateTableRow(resp_packet_ptr,server_ptr,top_htmlheader,"style=\"height:10px\"");
      {
        /*Begin the table data with attribute and content("&nbsp;")*/
        status += AddTableData(resp_packet_ptr,server_ptr,"&nbsp;","colspan=\"5\"",top_htmlheader);
        /*Close the table row*/
        status += CloseTableRow(resp_packet_ptr, server_ptr);

      }
    }
        /*Close the table */
    status += CloseTable(resp_packet_ptr, server_ptr);
  }
    /* Send the buffer data*/
    status +=  nx_tcp_socket_send(&(server_ptr -> nx_http_server_socket), resp_packet_ptr, NX_HTTP_SERVER_TIMEOUT);
    if(status)
    {
      /* Any error occurs then release the buffer*/
      nx_packet_release(resp_packet_ptr);
      /*Increase the Failcount*/
      //u32WebFailcount++;
    }
    /*Add html footer contains body and html closure tag*/
   status += AddHtmlFooter(resp_packet_ptr,server_ptr);
   /*return the status of this page creation*/
   return status;
}


/*===========================================================================*/

/**
 * The function webserver_framework_index() sends the page for the navigation frame to the
 * web browser. The page URL is /index.html. The content is dynamically adapted depending
 * on the rights of the client.
 *
 * @return
 * - type  : int
 * @param[out] resp_packet_ptr
 * - type : NX_PACKET*
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER*
 */

int webserver_framework_index(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr )
{
  //uint8_t userType = USERMAN_TYPE_DEFAULT;
  //uint8_t userStatus = 0;
  char index_htmlheader[] = {"<head><title>SHANKARIOT</title><meta http-equiv=\"content-type\" content=\"text/html; charset=ISO-8859-1\"></head> \
                       <style type=\"text/css\">\n \
                       td.nav {width:190px; background-color:#E4EBEE; border-top:2px groove #EEEEEE; border-left:2px groove #EEEEEE; padding:2px 0px 2px 6px;}\n \
                       td.topnav {width:190px; border-top:2px groove #EEEEEE; border-left:2px groove #EEEEEE; padding:2px 0px 2px 6px; font-family:arial, sans-serif; font-size:12px; font-weight:bold; color:#000000;}\n \
                       a.nav:link {font-family:arial, sans-serif; font-size:12px; font-weight:regular; color:#7899AD; text-decoration:none;}\n \
                       a.nav:visited {font-family:arial, sans-serif; font-size:12px; font-weight:regular; color:#7899AD; text-decoration:none;}\n \
                       a.nav:hover {color:#000000; text-decoration:none;}\n \
                       a.nav:active {font-family:arial, sans-serif; font-size:12px; font-weight:regular; color:#000000; text-decoration:none;}\n \
                       </style>\n"};

  /* Get User type */
  int iUserIndex = 0;//get_user_type( &userType, &userStatus,server_ptr);

  /* page status*/
  int status;
  /* html header information for this page*/

   /* Add the HTML header for this page. it includes header and body tag also; body attribute is "style=\"margin:0;\""*/
  status = AddHtmlHeader(resp_packet_ptr,server_ptr,index_htmlheader,"style=\"margin:0;\"");
  {
    /* Allocate the html buffer*/
    status = nx_packet_allocate(server_ptr -> nx_http_server_packet_pool_ptr, &resp_packet_ptr, NX_TCP_PACKET, NX_WAIT_FOREVER);

    /* Begin the table row with  attribute */
    status += CreateHtmlTable(resp_packet_ptr,server_ptr,index_htmlheader,"style=\"height:100%;\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\"");
    {
      /* Begin the table row without attribute */
      status += CreateTableRow(resp_packet_ptr, server_ptr,index_htmlheader,"");
      {
        /* Begin the table data with  attribute */
        status += CreateTableData(resp_packet_ptr,server_ptr,index_htmlheader,"valign=\"top\" bgcolor=\"#cccccc\"");

        /* Begin the table with  attribute */
         status += CreateHtmlTable(resp_packet_ptr,server_ptr,index_htmlheader,"width=\"250\" border=\"0\" cellpadding=\"15\" cellspacing=\"0\"");
        {
          /* Begin the table row without attribute */
          status += CreateTableRow(resp_packet_ptr, server_ptr,index_htmlheader,"");
          {
            /* Begin the table data without attribute */
           status += CreateTableData(resp_packet_ptr, server_ptr,index_htmlheader,"");
            {
              /* Begin the table with  attribute */
              status += CreateHtmlTable(resp_packet_ptr,server_ptr,index_htmlheader,"border=\"0\" cellpadding=\"0\" cellspacing=\"0\"");
              {
                /* Begin the table row without attribute - Information */
                status += CreateTableRow(resp_packet_ptr, server_ptr,index_htmlheader,"");
                {
                   /*Begin the table data with attribute and "Information"*/
                  status += AddTableData(resp_packet_ptr,server_ptr,"Information","class=\"topnav\"",index_htmlheader);
                  /*Close the table row*/
                  status += CloseTableRow(resp_packet_ptr, server_ptr);
                }

                 /* Begin the table row without attribute - System menu */
                status += CreateTableRow(resp_packet_ptr, server_ptr,index_htmlheader,"");
                {
                   /*Begin the table data with attribute and system menu link*/
                  status += AddTableData(resp_packet_ptr,server_ptr,"<a href=\"/main_overview.html\" class=\"nav\" target=\"mainframe\">System</a>","class=\"nav\"",index_htmlheader);
                  /*Close the table row*/
                  status += CloseTableRow(resp_packet_ptr, server_ptr);
                }

                 /* Begin the table row without attribute - version menu */
                status += CreateTableRow(resp_packet_ptr, server_ptr,index_htmlheader,"");
                {
                   /*Begin the table data with attribute and version menu link*/
                  status += AddTableData(resp_packet_ptr,server_ptr,"<a href=\"/version.html\" class=\"nav\" target=\"mainframe\">Version</a>","class=\"nav\"",index_htmlheader);
                  /*Close the table row*/
                  status += CloseTableRow(resp_packet_ptr, server_ptr);
                }

                 /* Begin the table row without attribute - Licence menu */
//                status += CreateTableRow(resp_packet_ptr, server_ptr,index_htmlheader,"");
//                {
//                   /*Begin the table data with attribute and Licence menu link*/
//                  status += AddTableData(resp_packet_ptr,server_ptr,"<a href=\"/licence.html\" class=\"nav\" target=\"mainframe\">Licence</a>","class=\"nav\"",index_htmlheader);
//                  /*Close the table row*/
//                  status += CloseTableRow(resp_packet_ptr, server_ptr);
//                }

                /*Close the table */
                status += CloseTable(resp_packet_ptr, server_ptr);
              }

              /* Send the buffer data*/
              status +=  nx_tcp_socket_send(&(server_ptr -> nx_http_server_socket), resp_packet_ptr, NX_HTTP_SERVER_TIMEOUT);
              if(status)
              {
                /* Any error occurs then release the buffer*/
                nx_packet_release(resp_packet_ptr);
                /*Increase the Failcount*/
                //u32WebFailcount++;
              }

              /* Allocate the html buffer*/
              status = nx_packet_allocate(server_ptr -> nx_http_server_packet_pool_ptr, &resp_packet_ptr, NX_TCP_PACKET, NX_WAIT_FOREVER);

#if 0
              if (userType >= USERMAN_TYPE_CONFIG)
              {
                /* add single break tag*/
                status += SingleBrTag(resp_packet_ptr, server_ptr);
                /* Begin the table with  attribute */
                status += CreateHtmlTable(resp_packet_ptr,server_ptr,index_htmlheader,"border=\"0\" cellpadding=\"0\" cellspacing=\"0\"");
                {
                    /* Begin the table row without attribute - Configuration */
                    status += CreateTableRow(resp_packet_ptr, server_ptr,index_htmlheader,"");
                    {
                       /*Begin the table data with attribute and "Configuration"*/
                      status += AddTableData(resp_packet_ptr,server_ptr,"Configuration","class=\"topnav\"",index_htmlheader);
                      /*Close the table row*/
                      status += CloseTableRow(resp_packet_ptr, server_ptr);
                    }

                      /* Begin the table row without attribute - SHANKAR IOT Server Setup menu */
                    status += CreateTableRow(resp_packet_ptr, server_ptr,index_htmlheader,"");
                    {
                       /*Begin the table data with attribute and SHANKAR IOT Server Setup menu link*/
                      status += AddTableData(resp_packet_ptr,server_ptr,"<a href=\"/device.html\" class=\"nav\" target=\"mainframe\">SHANKAR IOT Server Setup</a>","class=\"nav\"",index_htmlheader);
                      /*Close the table row*/
                      status += CloseTableRow(resp_packet_ptr, server_ptr);
                    }

                    /* Begin the table row without attribute - Network Settings menu */
                    status += CreateTableRow(resp_packet_ptr, server_ptr,index_htmlheader,"");
                    {
                       /*Begin the table data with attribute and Network Settings menu link*/
                      status += AddTableData(resp_packet_ptr,server_ptr,"<a href=\"/network.html\" class=\"nav\" target=\"mainframe\">Network Settings</a>","class=\"nav\"",index_htmlheader);
                      /*Close the table row*/
                      status += CloseTableRow(resp_packet_ptr, server_ptr);
                    }

                    /* Begin the table row without attribute - Time menu */
                    status += CreateTableRow(resp_packet_ptr, server_ptr,index_htmlheader,"");
                    {
                       /*Begin the table data with attribute and Time link*/
                      status += AddTableData(resp_packet_ptr,server_ptr,"<a href=\"/time.html\" class=\"nav\" target=\"mainframe\">Time</a>","class=\"nav\"",index_htmlheader);
                      /*Close the table row*/
                      status += CloseTableRow(resp_packet_ptr, server_ptr);
                    }

                     /* Begin the table row without attribute - User Management menu */
                    status += CreateTableRow(resp_packet_ptr, server_ptr,index_htmlheader,"");
                    {
                       /*Begin the table data with attribute and User Management link*/
                      status += AddTableData(resp_packet_ptr,server_ptr,"<a href=\"/user.html\" class=\"nav\" target=\"mainframe\">User Management</a>","class=\"nav\"",index_htmlheader);
                      /*Close the table row*/
                      status += CloseTableRow(resp_packet_ptr, server_ptr);
                    }

                    if (userType ==  USERMAN_TYPE_ADMIN)
                    {
                      /* Begin the table row without attribute - Firmware Management menu */
                      status += CreateTableRow(resp_packet_ptr, server_ptr,index_htmlheader,"");
                      {
                         /*Begin the table data with attribute and Firmware Management link*/
                        status += AddTableData(resp_packet_ptr,server_ptr,"<a href=\"/firmware.html\" class=\"nav\" target=\"mainframe\">Firmware Update</a>","class=\"nav\"",index_htmlheader);
                        /*Close the table row*/
                        status += CloseTableRow(resp_packet_ptr, server_ptr);
                      }
                    }
                    /*Close the table */
                    status += CloseTable(resp_packet_ptr, server_ptr);
                  }
                }
#endif
              /* add single break tag*/
              status += SingleBrTag(resp_packet_ptr, server_ptr);
              /* Begin the table with  attribute */
              status += CreateHtmlTable(resp_packet_ptr,server_ptr,index_htmlheader,"border=\"0\" cellpadding=\"0\" cellspacing=\"0\"");
              {
                  /* Begin the table row without attribute - Login/logout menu */
                  status += CreateTableRow(resp_packet_ptr,server_ptr,index_htmlheader,"");
                  {
                     /*Begin the table data with attribute and Login link*/
                    //if (userType == USERMAN_TYPE_DEFAULT)
                      status += AddTableData(resp_packet_ptr,server_ptr,"<a href=\"/login.html\" class=\"nav\" target=\"mainframe\">Login</a>","class=\"nav\"",index_htmlheader);
                    //else
                      //status += AddTableData(resp_packet_ptr,server_ptr,"<a href=\"/logout.html\" class=\"nav\" target=\"mainframe\">Logout</a>","class=\"nav\"",index_htmlheader);
                    /*Close the table row*/
                    status += CloseTableRow(resp_packet_ptr, server_ptr);
                  }
                /*Close the table */
                status += CloseTable(resp_packet_ptr, server_ptr);
              }
              /* add single break tag*/
              status += SingleBrTag(resp_packet_ptr, server_ptr);
              /* Begin the table with  attribute */
              status += CreateHtmlTable(resp_packet_ptr, server_ptr, index_htmlheader,"border=\"0\" cellpadding=\"0\" cellspacing=\"0\"");
              {
                  /* Begin the table row without attribute - Contact menu */
                  status += CreateTableRow(resp_packet_ptr, server_ptr,index_htmlheader,"");
                  {
                     /*Begin the table data with attribute and Contact link*/
                       status += AddTableData(resp_packet_ptr,server_ptr,"<a href=\"/contact.html\" class=\"nav\" target=\"mainframe\">Contact</a>","class=\"nav\"",index_htmlheader);
                     /*Close the table row*/
                       status += CloseTableRow(resp_packet_ptr, server_ptr);
                  }
                /*Close the table */
                status += CloseTable(resp_packet_ptr, server_ptr);
              }

            }
            /*Close the table data*/
            status += CloseTableData(resp_packet_ptr, server_ptr);
          }
          /*Close the table row*/
          status += CloseTableRow(resp_packet_ptr, server_ptr);
        }
        /*Close the table */
        status += CloseTable(resp_packet_ptr, server_ptr);

        /*Close the table data*/
        status += CloseTableData(resp_packet_ptr, server_ptr);

        /*Begin the table data with attribute and space*/
        status += AddTableData(resp_packet_ptr,server_ptr,"&nbsp;","width=\"11\" align=\"center\" bgcolor=\"#ffffff\"",index_htmlheader);
      }
      /*Close the table row*/
       status += CloseTableRow(resp_packet_ptr, server_ptr);
    }
    /*Close the table */
    status += CloseTable(resp_packet_ptr, server_ptr);
  }
    /* Send the buffer data*/
    status +=  nx_tcp_socket_send(&(server_ptr -> nx_http_server_socket), resp_packet_ptr, NX_HTTP_SERVER_TIMEOUT);
    if(status)
    {
      /* Any error occurs then release the buffer*/
      nx_packet_release(resp_packet_ptr);
      /*Increase the Failcount*/
      //u32WebFailcount++;
    }
    /*Add html footer contains body and html closure tag*/
   status += AddHtmlFooter(resp_packet_ptr,server_ptr);
   /*return the status of this page creation*/
   return status;
}

////////////////////////////////////////////////////////////////////////////////
/*===========================================================================*/

/**
 * The function webserver_page_overview() sends the overview page for the mainframe frame to the
 * web browser. The page URL is /main_overview.html. The page shows the basic informations about
 * the RTEM. For example the MAC Addresses, Devicename, IP settings...
 *
 * @return
 * - type  : int
 * @param[out] resp_packet_ptr
 * - type : NX_PACKET*
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER*
 */

int webserver_page_overview(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr)
{
  /* string buffer*/
  char tempStr[200] = {'\0'};
  //time_t              RawTime_temp;
  char overview_htmlheader[] = {"<head><title>SHANKARIOT</title><meta http-equiv=\"content-type\" content=\"text/html; charset=ISO-8859-1\"> \
                       <link rel=\"stylesheet\" type=\"text/css\" href=\"/stylesheet.css\"> \
                       <script type=\"text/javascript\"> function refresh(){parent.frames[\"navigation\"].location.replace(\"/index.html\");}</script></head>\n"};
  /* network address structure*/
  //NETWORK_ADDRESS networkaddress;
  /* page status*/
  int status;
  /* html header information for this page*/

  /* Get the network addresses like ip address,DNS,gateway,DHCP enble status */
  //set_sdcard_status(2,65535,65535,2,1464875795,1464875795);
  //get_network_addresses(&networkaddress);

  /* Add the HTML header for this page. it includes header and body tag also; body attribute is null*/
  status = AddHtmlHeader(resp_packet_ptr,server_ptr,overview_htmlheader,"");
  {
    /* Allocate the html buffer*/
    status = nx_packet_allocate(server_ptr -> nx_http_server_packet_pool_ptr, &resp_packet_ptr, NX_TCP_PACKET, NX_WAIT_FOREVER);

    /* add header 1 text*/
    status += AddH1(resp_packet_ptr,server_ptr,"System Information",overview_htmlheader);
    /* add single break tag*/
    status += SingleBrTag(resp_packet_ptr, server_ptr);
    /* add header 2 text*/
    status += AddH2(resp_packet_ptr,server_ptr,"Shankar IOT",overview_htmlheader);
    /* Begin the table with null attribute*/
    status += CreateHtmlTable(resp_packet_ptr, server_ptr,overview_htmlheader,"");
    {
      /*Add the row content:
        Add the first table data with attribute("width=\"150\"") and content("Connected product ")
        Add the second table data with attribute("") and content("<b>One Product Connected</b>")
      */
      //status += AddTableRowWithoutAttribute(resp_packet_ptr,server_ptr,"Connected product ","width=\"150\"",strGFProductbus,"",overview_htmlheader);
      /*Close the table */
      status += CloseTable(resp_packet_ptr, server_ptr);
    }
    /* add single break tag*/
    status += SingleBrTag(resp_packet_ptr, server_ptr);

     /* Begin the table without attribute*/
    status += CreateHtmlTable(resp_packet_ptr, server_ptr,overview_htmlheader,"");
    {
      /*Add the row content:
        Add the first table data with attribute("width=\"150\"") and content("Connected product on GLOWPan:")
        Add the second table data with attribute("") and content("<b>No Product Connected</b>")
      */
      //status += AddTableRowWithoutAttribute(resp_packet_ptr,server_ptr,"Connected product on GLOWPan:","width=\"150\"",strGFProductglowpan,"",overview_htmlheader);
      /*Close the table */
      status += CloseTable(resp_packet_ptr, server_ptr);
    }
    /* add single break tag*/
    status += SingleBrTag(resp_packet_ptr, server_ptr);

    /* add header 2 "Real Time Ethernet Protocol" text*/
    status += AddH2(resp_packet_ptr,server_ptr,"Real Time Ethernet Protocol",overview_htmlheader);

    /* Begin the table without attribute*/
    status += CreateHtmlTable(resp_packet_ptr, server_ptr,overview_htmlheader,"");
    {
      /*Add the row content:
        Add the first table data with attribute("") and content("Active protocol:")
        Add the second table data with attribute("") and content("<b>No Product Connected</b>")
      */
      status += AddTableRowWithoutAttribute(resp_packet_ptr,server_ptr,"Active protocol:","width=\"150\"","<b>SHankar IOT MQTT</b>","",overview_htmlheader);

      /*check the network link status. If link_status is TRUE then dispaly "Yes"  otherwise display "No".*/
      //if(networkaddress.link_status == TRUE)
        //sprintf(tempStr, "<b>%s</b>","Yes");
      //else
        //sprintf(tempStr, "<b>%s</b>","No");

      /*Add the row content:
        Add the first table data with attribute("") and content("Communication status:").
        Add the second table data with attribute("") and content("Yes") or ("No").
      */
      status += AddTableRowWithoutAttribute(resp_packet_ptr,server_ptr,"Communication status:","width=\"150\"",tempStr,"",overview_htmlheader);

      /* Begin the table row without attribute*/
      status += CreateTableRow(resp_packet_ptr,server_ptr,overview_htmlheader,"");
      {
        /* Add the empty table header with attribute ("align=\"left\"")*/
        tableHeader(overview_htmlheader,"&nbsp;","align=\"left\"");
      }
      /*Close the table row*/
      status += CloseTableRow(resp_packet_ptr, server_ptr);
      /* Begin the table row without attribute*/
       status += CreateTableRow(resp_packet_ptr,server_ptr,overview_htmlheader,"");
      {
        /* Add the empty table header with attribute ("align=\"left\"")*/
        tableHeader(overview_htmlheader,"&nbsp;","align=\"left\"");
      }
      /*Close the table row*/
      status += CloseTableRow(resp_packet_ptr,server_ptr);
      /*Close the table */
      status += CloseTable(resp_packet_ptr, server_ptr);
    }
      /* add header 2 "Network Settings" text*/
    status += AddH2(resp_packet_ptr,server_ptr,"Network Settings",overview_htmlheader);
     /* Begin the table without attribute*/
    status += CreateHtmlTable(resp_packet_ptr, server_ptr, overview_htmlheader,"");
    {
       /* format the received mac address into string and store to 'tempstr' variable*/
       sprintf(tempStr, "<b>%02X:%02X:%02X:%02X:%02X:%02X</b>", wifi_mac[0], wifi_mac[1], wifi_mac[2], wifi_mac[3], wifi_mac[4], wifi_mac[5]);

      /*Add the row content:
        Add the first table data with attribute("width=\"150\"") and content("MAC Address:").
        Add the second table data with attribute("") and MAC address.
      */
      status += AddTableRowWithoutAttribute(resp_packet_ptr,server_ptr,"MAC Address:","width=\"150\"",tempStr,"",overview_htmlheader);

      /* format the received ip address into string and store to 'tempstr' variable*/
      sprintf(tempStr, "<b>%d.%d.%d.%d</b>", (uint8_t)wifi_ip_address[0], (uint8_t)wifi_ip_address[1], (uint8_t)wifi_ip_address[2], (uint8_t)wifi_ip_address[3]);

      /*Add the row content:
        Add the first table data with attribute("width=\"150\"") and content("IP Address:").
        Add the second table data with attribute("") and IP address.
      */
      status += AddTableRowWithoutAttribute(resp_packet_ptr,server_ptr,"IP Address:","width=\"150\"",tempStr,"",overview_htmlheader);

      /* format the received subnet address into string and store to 'tempstr' variable*/
      sprintf(tempStr, "<b>%d.%d.%d.%d</b>", (uint8_t)wifi_ip_mask[0], (uint8_t)wifi_ip_mask[1], (uint8_t)wifi_ip_mask[2], (uint8_t)wifi_ip_mask[3]);

      /*Add the row content:
        Add the first table data with attribute("") and content("Subnet Mask:").
        Add the second table data with attribute("") and subnet address.
      */
      status += AddTableRowWithoutAttribute(resp_packet_ptr,server_ptr,"Subnet Mask:","",tempStr,"",overview_htmlheader);

      /* format the received gateway address into string and store to 'tempstr' variable*/
      sprintf(tempStr, "<b>%d.%d.%d.%d</b>", (uint8_t)wifi_gateway_address[0], (uint8_t)wifi_gateway_address[1], (uint8_t)wifi_gateway_address[2], (uint8_t)wifi_gateway_address[3]);

      /*Add the row content:
        Add the first table data with attribute("") and content("Gateway:").
        Add the second table data with attribute("") and Gateway address.
      */
      status += AddTableRowWithoutAttribute(resp_packet_ptr,server_ptr,"Gateway:","",tempStr,"",overview_htmlheader);

      /* check the DHCP status, format the received DHCP status into string and store to 'tempstr' variable*/
        //if(WebManagement.DHCPServerOptions & DHCP_SETTINGS_VALID)
        //{
           sprintf(tempStr, "<b>%s</b>","Yes");
        //}
        //else
        //{
          //if(networkaddress.dhcp_status == TRUE)
            // sprintf(tempStr, "<b>%s</b>","Yes");
          //else
            // sprintf(tempStr, "<b>%s</b>","No");
        //}

       /*Add the row content:
        Add the first table data with attribute("") and content("DHCP active:").
        Add the second table data with attribute("") and DHCP status.
      */
      status += AddTableRowWithoutAttribute(resp_packet_ptr,server_ptr,"DHCP active:","",tempStr,"",overview_htmlheader);

      /* Begin the table row without attribute*/
      status += CreateTableRow(resp_packet_ptr,server_ptr,overview_htmlheader,"");
      {
        /* Add the empty table header with attribute ("align=\"left\"")*/
        tableHeader(overview_htmlheader,"&nbsp;","align=\"left\"");
      }
      /*Close the table row*/
      status += CloseTableRow(resp_packet_ptr, server_ptr);

      /* format the received DNS servet address into string and store to 'tempstr' variable*/
      sprintf(tempStr, "<b>%d.%d.%d.%d</b>", (uint8_t)wifi_dns_address_1[0],(uint8_t)wifi_dns_address_1[1],(uint8_t)wifi_dns_address_1[2],(uint8_t)wifi_dns_address_1[3]);

      /*Add the row content:
        Add the first table data with attribute("width=\"150\"") and content("DNS Server:").
        Add the second table data with attribute("") and DNS server address.
      */
      status += AddTableRowWithoutAttribute(resp_packet_ptr,server_ptr,"DNS Server:","width=\"150\"",tempStr,"",overview_htmlheader);

       /* Begin the table row without attribute*/
      status += CreateTableRow(resp_packet_ptr,server_ptr,overview_htmlheader,"");
      {
        /* Add the empty table header with attribute ("align=\"left\"")*/
        tableHeader(overview_htmlheader,"&nbsp;","align=\"left\"");
      }
      /*Close the table row*/
      status += CloseTableRow(resp_packet_ptr, server_ptr);

      /*Add the row content:
        Add the first table data with attribute("") and content("TCP Port:").
        Add the second table data with attribute("") and TCP port number.
      */
      //status += AddTableRowWithoutAttribute(resp_packet_ptr,server_ptr,"TCP Port:","","<b>49152<b>","",overview_htmlheader);

      /*Add the row content:
      Add the first table data with attribute("") and content(" comm. status:").
        Add the second table data with attribute("") and "<b>Ready</b>" string.
      */
      //status += AddTableRowWithoutAttribute(resp_packet_ptr,server_ptr,"comm. status:","","<b>Ready</b>","",overview_htmlheader);

      /*Close the table */
      status += CloseTable(resp_packet_ptr, server_ptr);
    }

  /* Send the buffer data*/
  status +=  nx_tcp_socket_send(&(server_ptr -> nx_http_server_socket), resp_packet_ptr, NX_HTTP_SERVER_TIMEOUT);
  if(status)
  {
    /* Any error occurs then release the buffer*/
    nx_packet_release(resp_packet_ptr);
  }

      /* Allocate the html buffer*/
      status = nx_packet_allocate(server_ptr -> nx_http_server_packet_pool_ptr, &resp_packet_ptr, NX_TCP_PACKET, NX_WAIT_FOREVER);

  }
  /* Send the buffer data*/
  status +=  nx_tcp_socket_send(&(server_ptr -> nx_http_server_socket), resp_packet_ptr, NX_HTTP_SERVER_TIMEOUT);
  if(status)
  {
    /* Any error occurs then release the buffer*/
    nx_packet_release(resp_packet_ptr);
  }
    /*Add html footer contains body and html closure tag*/
   status += AddHtmlFooter(resp_packet_ptr,server_ptr);
   /*return the status of this page creation*/
   return status;
}

/*===========================================================================*/

/**
 * The function webserver_page_version() sends the version page for the mainframe frame to the
 * web browser. The page URL is /version.html. The page shows version numbers of the currently
 * used stack.
 *
 * @return
 * - type  : int
 * @param[out] resp_packet_ptr
 * - type : NX_PACKET*
 * @param[in] server_ptr
 * - type : NX_HTTP_SERVER*
 */
#if 0
int webserver_page_version(NX_PACKET* resp_packet_ptr, NX_HTTP_SERVER* server_ptr)
{
  char version_htmlheader[] = {"<head><title>SHANKARIOT</title><meta http-equiv=\"content-type\" content=\"text/html; charset=ISO-8859-1\"> \
                       <link rel=\"stylesheet\" type=\"text/css\" href=\"/stylesheet.css\"> \
                       <script type=\"text/javascript\"> function refresh(){parent.frames[\"navigation\"].location.replace(\"/index.html\");}</script></head>\n"};
  /* Declaration of various components version buffer*/
  char ver[VERSION_STR_LENGTH+1]    = {0};
  char verAppl[VERSION_STR_LENGTH+1]    = {0};
  char verDevSerialNo[VERSION_STR_LENGTH+1]      = {0};
//  char verProductName[VERSION_STR_LENGTH+1]   = {0};
  char verSAP[VERSION_STR_LENGTH+1]     = {0};
//  char verSHANKARIOTIP[VERSION_STR_LENGTH+1]   = {0};
    /* string buffer*/
  char tempStr[100] = {'\0'};
  GF_UINT32 Version;
  GF_UINT8 Version_temp[4] = {'\0'};
   /* page status*/
  int status;
  Version = VERSION;
  Version_temp[0] = (GF_UINT8)(Version/0x10000);
  Version_temp[1] = (GF_UINT8)(Version/0x100);
  Version_temp[2] = (GF_UINT8)Version;

  /* html header information for this page*/

  /* copy the version into corresponding version buffer*/
  strncpy(verProductName, GFWebServerAPI_getProductName(), sizeof(verProductName));
  strncpy(verAppl, GFWebServerAPI_getProductversion(), sizeof(verAppl));
  strncpy(verSAP, GFWebServerAPI_getSAPnumber(), sizeof(verSAP));
  strncpy(ver, GFWebServerAPI_getProversion(), sizeof(ver));
  RTE_GetDeviceSerialNumber(verDevSerialNo);
  //strncpy(verTLS, GFWebServerAPI_getTLSversion(), sizeof(verTLS));

  /* Add the HTML header for this page. it includes header and body tag also; body attribute is null*/
  status = AddHtmlHeader(resp_packet_ptr,server_ptr,version_htmlheader,"");
  {
     /* Allocate the html buffer*/
    status = nx_packet_allocate(server_ptr -> nx_http_server_packet_pool_ptr, &resp_packet_ptr, NX_TCP_PACKET, NX_WAIT_FOREVER);

    /* add header 1 text*/
    status += AddH1(resp_packet_ptr,server_ptr,"Version Information",version_htmlheader);
    /* add single break tag*/
    status += SingleBrTag(resp_packet_ptr, server_ptr);
    /* Begin the table with null attribute*/
    status += CreateHtmlTable(resp_packet_ptr, server_ptr, version_htmlheader,"");
    {
      /* format the received application version number into string and store to 'tempstr' variable*/
        sprintf(tempStr,"<b>%s</b>",verDevSerialNo);

      /*Add the row content:
        Add the first table data with attribute("") and content("Application version:").
        Add the second table data with attribute("") and Application version number.
      */
      status += AddTableRowWithoutAttribute(resp_packet_ptr,server_ptr,"Device Serial Number:","style=\"width:200px;height:25px;\"",tempStr,"",version_htmlheader);

      /* format the received application version number into string and store to 'tempstr' variable*/
        sprintf(tempStr,"<b>%s</b>",verProductName);

      /*Add the row content:
        Add the first table data with attribute("") and content("Application version:").
        Add the second table data with attribute("") and Application version number.
      */
      status += AddTableRowWithoutAttribute(resp_packet_ptr,server_ptr,"Product name:","style=\"width:200px;height:25px;\"",tempStr,"",version_htmlheader);

        sprintf(tempStr,"<b>%s</b>",verSAP);

      /*Add the row content:
        Add the first table data with attribute("") and content("Application version:").
        Add the second table data with attribute("") and Application version number.
      */
      status += AddTableRowWithoutAttribute(resp_packet_ptr,server_ptr,"Shankar IOT SAP number :","style=\"width:200px;height:25px;\"",tempStr,"",version_htmlheader);
      /* format the received application version number into string and store to 'tempstr' variable*/
        sprintf(tempStr,"<b>%s</b>",verAppl);

      /*Add the row content:
        Add the first table data with attribute("") and content("Application version:").
        Add the second table data with attribute("") and Application version number.
      */
      status += AddTableRowWithoutAttribute(resp_packet_ptr,server_ptr,"Application version:","style=\"width:200px;height:25px;\"",tempStr,"",version_htmlheader);

      /* format the received version number into string and store to 'tempstr' variable*/
      sprintf(tempStr,"<b>%s</b>",ver);

      /*Add the row content:
        Add the first table data with attribute("") and content(" version:").
        Add the second table data with attribute("") and  version number.
      */
      status += AddTableRowWithoutAttribute(resp_packet_ptr,server_ptr,"version:","style=\"width:200px;height:25px;\"",tempStr,"",version_htmlheader);

       /* format the received GLOWPan version number into string and store to 'tempstr' variable*/
      sprintf(tempStr,"<b>%d.%d.%d</b>",Version_temp[0],Version_temp[1],Version_temp[2]);

      /*Add the row content:
        Add the first table data with attribute("") and content("GLOWPan version:").
        Add the second table data with attribute("") and WolfSSL version number.
      */
      status += AddTableRowWithoutAttribute(resp_packet_ptr,server_ptr,"Glowpan version:","style=\"width:200px;height:25px;\"",tempStr,"",version_htmlheader);

       /* format the received GLOWPan version number into string and store to 'tempstr' variable*/
      sprintf(tempStr,"<b>%s</b>","Not Available");

      /*Add the row content:
        Add the first table data with attribute("") and content("GLOWPan version:").
        Add the second table data with attribute("") and WolfSSL version number.
      */
      status += AddTableRowWithoutAttribute(resp_packet_ptr,server_ptr,"SDCARD Reader version:","style=\"width:200px;height:25px;\"",tempStr,"",version_htmlheader);

      /*Close the table */
      status += CloseTable(resp_packet_ptr, server_ptr);
    }
  }
    /* Send the buffer data*/
  status +=  nx_tcp_socket_send(&(server_ptr -> nx_http_server_socket), resp_packet_ptr, NX_HTTP_SERVER_TIMEOUT);
  if(status)
  {
    /* Any error occurs then release the buffer*/
    nx_packet_release(resp_packet_ptr);
    /*Increase the Failcount*/
    u32WebFailcount++;
  }
    /*Add html footer contains body and html closure tag*/
   status += AddHtmlFooter(resp_packet_ptr,server_ptr);
   /*return the status of this page creation*/
   return status;
}

#endif
