function PresentHead()
{
	var strHtml;
	strHtml = //'<table border="0" cellspacing="0" cellpadding="0" align="left" width="100%" height="100%">'+
  				//'<tr>'+ 
    				//'<td colspan="3" bordercolor="#FFFFFF" height="1%">'+ 
      				//	'<table width="100%" border="1" cellspacing="0" cellpadding="0" >'+
          					'<tr>'+ 
          						//'<td rowspan="3" width="18" valign="bottom">'+
          							//'<a href="http://www.belkin.com">'+
          							'<img src="/img/CA_v4_r3_c1.jpg" border="0" width="100%" height="18">'+
          							//'</a>'+
          						//'</td>'+
            					//'<td colspan="4" height="21" align="right" nowrap>&nbsp;'+ 
            					//'</td>'+
          					'</tr>'+
          					'<tr>'+ 
          							'<img src="/img/RP614v4_cfig_screen.gif" border="0" width="750" height="85">'+
          					'</tr>'+
           					'<tr>'+ 
          							'<img src="/img/CA_v4_r4_c1.jpg" border="0" width="100%" height="6">'+
          					'</tr>';         					
      				//	'</table>';
    				//'</td>'+
  				//'</tr>';         	
	document.write(strHtml); 
}
function PresentMenu(menuItem)
{
	var ScrHeight = window.innerHeight - 109;
	var NavigatorName = navigator.appName;
	var NavigatorVer = navigator.appVersion;
	//var yellow   ='#FFFF00';
	var white    ='#FFFFFF';
	//var red    	 ='#FF0000';
	//var blue   	 ='#E8F8FF';
	//var darkBlue ='#94CAE4';
	//var black    ='#000000';
	var gray	 ='#CCCCCC';
	var strHtml;

	strHtml='<tr>'+ 
				//'<td valign="top" width="20%" height="100%" bgcolor="#360199">'+ 
				'<td valign="top" width="20%" height="'+ScrHeight+'" bgcolor="#360199">'+ 
  				'<table width="100%" border="0" cellspacing="0" cellpadding="0" align="left" height="100%">';
  	document.write(strHtml);
	if(menuItem=='1')
		PrintMenuItem(show1, white);
	else
		PrintMenuItem(show1, gray);
	if(menuItem=='2')
		PrintMenuItem(show2, white);
	else
		PrintMenuItem(show2, gray);
	if(menuItem=='3')
		PrintMenuItem(show3, white);
	else
		PrintMenuItem(show3, gray);
				
	if(menuItem=='4')
		PrintMenuItem(show4, white);
	else
		PrintMenuItem(show4, gray);
	if(menuItem=='5')
		PrintMenuItem(show5, white);
	else
		PrintMenuItem(show5, gray);
		
	strHtml=
				'<tr>'+  
      				'<td width="5" bgcolor="#360199" height="100%">&nbsp;</td>'+ 
      				'<td bgcolor="#360199">'+  
      				'</td>'+ 
     			'</tr>'+ 
				'<tr>'+  
      				'<td width="5" bgcolor="#360199" height="100%">&nbsp;</td>'+ 
      				'<td bgcolor="#360199">'+  
      				'</td>'+ 
     			'</tr>'; 
	document.write(strHtml);
      	
	strHtml=		'</table>'+
    				'</td>'+
    				'<td valign="top" width="2" bgcolor="#FFFFFF" height="100%">'+
    					'<img src="/img/CA_v4_r5_c5.jpg" width="6" height="100%">'+
    				'</td>';
   	document.write(strHtml); 
}
function PrintMenuItem(content, color)
{
	var background = '#360199';
	var strHtml;	
	strHtml=
					'<tr>'+  
          				'<td width="5" bgcolor="#360199">&nbsp;</td>'+ 
          				'<td bgcolor="#360199">'+  
          				'</td>'+ 
         			'</tr>'+ 
					'<tr>'+  
          				'<td width="5" bgcolor="#360199">&nbsp;</td>'+ 
          				'<td bgcolor="#360199">'+
          				'<font face="Arial">';
    document.write(strHtml);
	document.write(content.fontcolor(color).bold().fontsize(3));  
	strHtml=
          					//'<B><font color="' + color + '" face="Arial">' + content + '</font></B>'+ 
          				'</font>'+
          				'</td>'+ 
         			'</tr>'; 
	document.write(strHtml);
}