/* vi:set tabstop=2 cindent shiftwidth=2: */
/*
 *  Boa, an http server
 *  Copyright (C) 1995 Paul Phillips <psp@well.com>
 *  Some changes Copyright (C) 1996 Charles F. Randall <crandall@goldsys.com>
 *  Some changes Copyright (C) 1996 Larry Doolittle <ldoolitt@jlab.org>
 *  Some changes Copyright (C) 1996,97,98 Jon Nelson <nels0988@tc.umn.edu>
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
 */

int upgrading = 0;
int g_bLogin = 0;
int filter_client_cur_index = 0;
int forward_port_cur_index = 0;
int static_route_cur_index = 0;
int trigger_port_cur_index = 0;
int dhcpc_res_cur_index = 0;
int qos_cur_index = 0;

/* boa: boa.c */
int main(int argc, char **argv)
{
	int c;						/* command line arg */
	int s_port = 80;

	websAspInit(argc,argv);

}

int copy_httpc_info_to_client(char *ptr)
{
	
	
}

int sys_restart(void)
{
	
}

int sys_reboot(void)
{
	
}	

int firewall_starting(void)
{

}	
