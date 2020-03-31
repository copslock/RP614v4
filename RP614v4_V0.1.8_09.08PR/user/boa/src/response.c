/*
 *  Boa, an http server
 *  Copyright (C) 1995 Paul Phillips <psp@well.com>
 *  Some changes Copyright (C) 1996 Larry Doolittle <ldoolitt@jlab.org>
 *  Some changes Copyright (C) 1996,97 Jon Nelson <nels0988@tc.umn.edu>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 1, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  $Id: response.c,v 1.1 2005/04/19 04:58:15 tony Exp $
 */

/* boa: response.c */

#include "asp_page.h"
#include "syslog.h"
#include "boa.h"

static char e_s[MAX_HEADER_LENGTH * 3];
	
void print_content_type(request * req)
{
	req_write(req, "Content-Type: ");
	
#if !defined(DNI)	
	if (req->content_type)
		req_write(req,req->content_type);
	else	req_write(req, get_mime_type(req->request_uri));
#else	
	if (strstr(req->request_uri, ".cfg")) {	
		req_write(req,"application/cfg");		
		//req_write(req, "application/octet-stream");		
	}
	/* for proxy http */
	if (strstr(req->request_uri, ".cgi")) {	
		req_write(req,"text/html");		
		//req_write(req, "application/octet-stream");		
	}	
	else if (req->content_type)
		req_write(req,req->content_type);
	else req_write(req, get_mime_type(req->request_uri));		
#endif
	
#ifdef USE_CHARSET_HEADER
#ifdef USE_BROWSERMATCH
       if (req->send_charset)
#endif
         {
	  req_write(req,"; charset=");
#ifdef USE_NLS
		if (req->cp_name)
		{
			req_write(req,req->cp_name);
		}else
#endif
	  if (local_codepage)
	    req_write(req,local_codepage);
	  else req_write(req,DEFAULT_CHARSET);
         }
#endif
	req_write(req, "\r\n");
}

void print_content_length(request * req)
{

#if !defined(DNI)	
	req_write(req, "Content-Length: ");
	req_write(req, simple_itoa(req->filesize));
	req_write(req, "\r\n");
#endif	
}

void print_last_modified(request * req)
{
#if !defined(DNI)	
	req_write(req, "Last-Modified: ");
	req_write_rfc822_time(req, req->last_modified);
	req_write(req, "\r\n");
#endif	
}

void print_http_headers(request * req)
{

	req_write(req, "Date: ");
	req_write_rfc822_time(req, 0);
	req_write(req, "\r\nServer: " SERVER_VERSION "\r\n");

	if (req->keepalive == KA_ACTIVE) {
		req_write(req, "Connection: Keep-Alive\r\n" \
			"Keep-Alive: timeout=");
		req_write(req, simple_itoa(ka_timeout));
		req_write(req, ", max=");
		req_write(req, simple_itoa(ka_max));
		req_write(req, "\r\n");
	} else
		req_write(req, "Connection: close\r\n");
}

/* The routines above are only called by the routines below.
 * The rest of Boa only enters through the routines below.
 */

/* R_REQUEST_OK: 200 */
void send_r_request_ok(request * req)
{
	req->response_status = R_REQUEST_OK;
	if (req->simple)
		return;

	req_write(req, "HTTP/1.0 200 OK\r\n");
	print_http_headers(req);

	
	if (req->is_cgi)
	{
#ifdef SUPPORT_ASP
		req->content_type="text/html";
#endif
		if (req->content_type)
			print_content_type(req);
#ifndef SUPPORT_ASP
		else
			if (req->is_cgi)
			{
				req_write(req, req->header_line);
				req_write(req, "\r\n");
			}
#endif		
#ifndef NO_COOKIES
		if (req->cookie)
		{
			req_write(req, req->cookie);
			req_write(req, "\r\n");	
		}
#endif
	}else
	{
		print_content_type(req);
		print_content_length(req);
		print_last_modified(req);
	}		
		req_write(req, "\r\n");	/* terminate header */
}

/* R_MOVED_PERM: 301 */
void send_redirect_perm(request * req, char *url)
{
	req->response_status = R_MOVED_PERM;
	if (!req->simple) {
		req_write(req, "HTTP/1.0 301 Moved Permanently\r\n");
		print_http_headers(req);
		req_write(req, "Content-Type: text/html\r\n");

		req_write(req, "Location: ");
		req_write(req, escape_string(url, e_s));
		req_write(req, "\r\n\r\n");
	}
	if (req->method != M_HEAD) {
		req_write(req, "<HTML><HEAD><TITLE>301 Moved Permanently</TITLE></HEAD>\n"
					 "<BODY>\n<H1>301 Moved</H1>The document has moved\n"
					 "<A HREF=\"");
		req_write(req, escape_string(url, e_s));
		req_write(req, "\">here</A>.\n</BODY></HTML>\n");
	}
	req_flush(req);
}

/* R_MOVED_TEMP: 302 */
void send_redirect_temp(request * req, char *url)
{

	req->response_status = R_MOVED_TEMP;
	if (!req->simple) {
		req_write(req, "HTTP/1.0 302 Moved Temporarily\r\n");
		print_http_headers(req);
		req_write(req, "Content-Type: text/html\r\n");

		req_write(req, "Location: ");
		req_write(req, escape_string(url, e_s));
		req_write(req, "\r\n\r\n");
	}
	if (req->method != M_HEAD) {
		req_write(req, "<HTML><HEAD><TITLE>302 Moved Temporarily</TITLE></HEAD>\n"
					 "<BODY>\n<H1>302 Moved</H1>The document has moved\n"
					 "<A HREF=\"");
		req_write(req, escape_string(url, e_s));
		req_write(req, "\">here</A>.\n</BODY></HTML>\n");
	}
	req_flush(req);
}

/* R_NOT_MODIFIED: 304 */
void send_r_not_modified(request * req)
{
	req_write(req, "HTTP/1.0 304 Not Modified\r\n");
	req->response_status = R_NOT_MODIFIED;
	print_http_headers(req);
	print_content_type(req);
	req_write(req, "\r\n");		/* terminate header */
	req_flush(req);
}

/* R_BAD_REQUEST: 400 */
void send_r_bad_request(request * req)
{
	req->response_status = R_BAD_REQUEST;
	if (!req->simple) {
		req_write(req, "HTTP/1.0 400 Bad Request\r\n");
		print_http_headers(req);
		req_write(req, "Content-Type: text/html\r\n\r\n");	/* terminate header */
	}
	if (req->method != M_HEAD) {
		req_write(req, "<HTML><HEAD><TITLE>400 Bad Request</TITLE></HEAD>\n"
				"<BODY><H1>400 Bad Request</H1>\nYour client has issued "
					 "a malformed or illegal request.\n</BODY></HTML>\n");
	}
	req_flush(req);
}

/* R_UNAUTHORIZED: 401 */
void send_r_unauthorized(request * req, char *realm_name)
{
	char AppendText[]={"<head><meta http-equiv='content-type' content='text/html;charset=ISO-8859-1'><META http-equiv='Pragma' CONTENT='no-cache'><META HTTP-EQUIV='Cache-Control' CONTENT='no-cache'><title>Authorization warning</title><script language='javascript' type='text/javascript'><!--\r\nfunction DoPost() {document.formname.submit();}\r\n--></script></head><body bgcolor='#ffffff' onload='DoPost();'><form name='formname' method='POST' action='/cgi-bin/TraceWanDet.cgi'><input type='hidden' name='page' value='ErrorAuthCancel.htm'></form><noframes><body>Please upgrade to a version 4 or higher browser so that you can use this setup tool (and see lots of great sites on the Internet!)</body></noframes></html>\r\n"}; //KEVIN:05DEC16:ADD:BlankState

	req->response_status = R_UNAUTHORIZED;
	if (!req->simple) {
		req_write(req, "HTTP/1.0 401 Unauthorized\r\n");
		print_http_headers(req);
		req_write(req, "WWW-Authenticate: Basic realm=\"");
		req_write(req, realm_name);
		req_write(req, "\"\r\n");
		req_write(req, "Content-Type: text/html\r\n\r\n");	/* terminate header */
	}
	if (req->method != M_HEAD) {
		////KEVIN:05DEC16:ADD:BlankState+++
//		req_write(req, "<HTML><HEAD><TITLE>401 Unauthorized</TITLE></HEAD>\n"
//				 "<BODY><H1>401 Unauthorized</H1>\nYour client does not "
//					 "have permission to get URL ");
//		req_write(req, escape_string(req->request_uri, e_s));
//		req_write(req, " from this server.\n</BODY></HTML>\n");
		req_write(req, AppendText);
		//KEVIN:BlankState---
	}
	req_flush(req);
}

/* R_FORBIDDEN: 403 */
void send_r_forbidden(request * req)
{
	req->response_status = R_FORBIDDEN;
	if (!req->simple) {
		req_write(req, "HTTP/1.0 403 Forbidden\r\n");
		print_http_headers(req);
		req_write(req, "Content-Type: text/html\r\n\r\n");	/* terminate header */
	}
	if (req->method != M_HEAD) {
		req_write(req, "<HTML><HEAD><TITLE>403 Forbidden</TITLE></HEAD>\n"
					 "<BODY><H1>403 Forbidden</H1>\nYour client does not "
					 "have permission to get URL ");
		req_write(req, escape_string(req->request_uri, e_s));
		req_write(req, " from this server.\n</BODY></HTML>\n");
	}
	req_flush(req);
}

/* R_NOT_FOUND: 404 */
void send_r_not_found(request * req)
{
	req->response_status = R_NOT_FOUND;
	if (!req->simple) {
		req_write(req, "HTTP/1.0 404 Not Found\r\n");
		print_http_headers(req);
		req_write(req, "Content-Type: text/html\r\n\r\n");	/* terminate header */
	}
	if (req->method != M_HEAD) {
		req_write(req, "<HTML><HEAD><TITLE>404 Not Found</TITLE></HEAD>\n"
					 "<BODY><H1>404 Not Found</H1>\nThe requested URL ");
		req_write(req, escape_string(req->request_uri, e_s));
		req_write(req, " was not found on this server.\n</BODY></HTML>\n");
	}
	req_flush(req);
}

/* R_ERROR: 500 */
void send_r_error(request * req)
{
	req->response_status = R_ERROR;
	if (!req->simple) {
		req_write(req, "HTTP/1.0 500 Server Error\r\n");
		print_http_headers(req);
		req_write(req, "Content-Type: text/html\r\n\r\n");	/* terminate header */
	}
	if (req->method != M_HEAD) {
		req_write(req, "<HTML><HEAD><TITLE>500 Server Error</TITLE></HEAD>\n"
			   "<BODY><H1>500 Server Error</H1>\nThe server encountered "
			   "an internal error and could not complete your request.\n"
					 "</BODY></HTML>\n");
	}
	req_flush(req);
}

/* R_NOT_IMP: 501 */
void send_r_not_implemented(request * req)
{
	req->response_status = R_NOT_IMP;
	if (!req->simple) {
		req_write(req, "HTTP/1.0 501 Not Implemented\r\n");
		print_http_headers(req);
		req_write(req, "Content-Type: text/html\r\n\r\n");	/* terminate header */
	}
	if (req->method != M_HEAD) {
		req_write(req, "<HTML><HEAD><TITLE>501 Not Implemented</TITLE></HEAD>\n"
				"<BODY><H1>501 Not Implemented</H1>\nPOST to non-script "
					 "is not supported in Boa.\n</BODY></HTML>\n");
	}
	req_flush(req);
}

/* R_NOT_IMP: 505 */
void send_r_bad_version(request * req)
{
	req->response_status = R_BAD_VERSION;
	if (!req->simple) {
		req_write(req, "HTTP/1.0 505 HTTP Version Not Supported\r\n");
		print_http_headers(req);
		req_write(req, "Content-Type: text/html\r\n\r\n");	/* terminate header */
	}
	if (req->method != M_HEAD) {
		req_write(req, "<HTML><HEAD><TITLE>505 HTTP Version Not Supported</TITLE></HEAD>\n"
				"<BODY><H1>505 HTTP Version Not Supported</H1>\nHTTP versions "
					 "other than 0.9 and 1.0 "
					 "are not supported in Boa.\n<p><p>Version encountered: ");
		req_write(req, req->http_version);
		req_write(req, "<p><p></BODY></HTML>\n");
	}
	req_flush(req);
}
