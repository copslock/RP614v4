//public message
var msg_blank = "%s不能为空。\n";
var msg_space = "%s不允许有空白或者空格\n";
var msg_blank_in = "%s不允许有空白\n";
var msg_invalid = "\n%s中有一到多个无效字符\n有效字符为：\n%s\n\n";
var msg_check_invalid = "%s包含一个无效字符。";
var msg_greater = "%s必须大于%s";
var msg_less = "%s必须小于%s";
var msg_first = "第一";
var msg_second = "第二";
var msg_third = "第三";
var msg_fourth = "第四";

function isIPaddr(addr)
{
	var i;
	var a;
	if(addr.split)
	{	/* If method exists use it...*/
		a = addr.split(".");
		/*alert('using builtin split method';*/
	}
	else
	{	/* otherwise, use our alternative implementation*/
		a = cdisplit(addr,".");
		/*alert('using proprietary split function cdisplit()');*/
	}
	if(a.length != 4)
	{
		alert('非法IP地址，IP地址必须采用a.b.c.d的形式\n' +
		'其中a、b、c和d均为十进制数，介于0到255之间。');
		return false;
	}
	for(i = 0; i < a.length; i++)
	{
		var x = a[i];
		if( x == null || x == "" || !isNumeric(x) || x < 0 || x > 255 )
		{
			alert('错误IP地址，IP地址必须采用a.b.c.d的形式\n' +
			'其中a、b、c和d均为十进制数，介于0到255之间。');
			return false;
		}
	}
	return true;
}

function _isNumeric(str)
{
	var i;
	for(i = 0; i < str.length; i++)
	{
		var c = str.substring(i, i+1);
		if("0" <= c && c <= "9")
		{
			continue;
		}
		return false;
	}
	return true;
}

function isHex(str)
{
	var i;
	for(i = 0; i < str.length; i++)
	{
		var c = str.substring(i, i+1);
		if(("0" <= c && c <= "9") || ("a" <= c && c <= "f") || ("A" <= c && c <= "F"))
		{
			continue;
		}
		return false;
	}
	return true;
}

/* Check Mac Address Format*/
function checkMacMain(mac)
{
	if(mac.value.length == 0)
	{
		mac.focus();
		return true;
	}
	for(i = 0; i < mac.value.length; i++)
	{
		var c = mac.value.substring(i, i+1)
		if(("0" <= c && c <= "9") || ("a" <= c && c <= "f") || ("A" <= c && c <= "F"))
		{
			continue;
		}
		mac.focus();
		return true;
	}
	if(mac.value.length == 1)
	{
		mac.value = "0"+mac.value;
	}
	mac.value = mac.value.toUpperCase();
	return false;
}
/*pamela20060125
function checkMacAddress(mac1, mac2, mac3, mac4, mac5, mac6)
{
	if(checkMacMain(mac1)) return true;
	if(checkMacMain(mac2)) return true;
	if(checkMacMain(mac3)) return true;
	if(checkMacMain(mac4)) return true;
	if(checkMacMain(mac5)) return true;
	if(checkMacMain(mac6)) return true;
	// else return false
	return false;
}
*/
/* Check IP Address Format*/
function checkIPMain(ip, max)
{
	x = ip.value;

	if( isNumeric(ip, max) )
	{
		ip.focus();
		return true;
	}
}

function checkIP(ip1, ip2, ip3, ip4, max)
{
	if(checkIPMain(ip1, 255)) return true;
	if(checkIPMain(ip2, 255)) return true;
	if(checkIPMain(ip3, 255)) return true;
	if(checkIPMain(ip4, max)) return true;
	if((parseInt(ip1.value)==0)||(parseInt(ip1.value)==0)&&(parseInt(ip2.value)==0)&&(parseInt(ip3.value)==0)&&(parseInt(ip4.value)==0))
		return true;
	/* else return false*/
	return false;
}

/* Check Numeric*/
function isNumeric(str, max)
{
	if(str.value.length == 0 || str.value == null || str.value == "")
	{
		str.focus();
		return true;
	}
	
	var i = parseInt(str.value);
	if(i > max)
	{
		str.focus();
		return true;
	}

	for(i = 0; i < str.value.length; i++)
	{
		var c = str.value.substring(i, i+1);
		if("0" <= c && c <= "9")
		{
		continue;
		}
		str.focus();
		/*alert("Ineger only!")*/
		return true;
	}
	return false;
}

/* Check Blank*/
function isBlank(str)
{
	if(str.value == "")
	{
		str.focus();
		return true;
	}
	else
		return false;
}

/* Check Phone Number*/
function isPhonenum(str)
{
	var i;
	if(str.value.length == 0)
	{
		str.focus();
		return true;
	}
	
	for (i = 0; i<str.value.length; i++)
	{
		var c = str.value.substring(i, i+1);
		if (c >= "0" && c <= "9")
			continue;
		/* if '-' and not leading or trailing...*/
		if ( c == '-' && i !=0 && i != (str.value.length-1) )
			continue;
		if (c == ',')	continue;
		if (c == ' ')	continue;
		if (c>= 'A' && c <= 'Z')	continue;
		if (c>= 'a' && c <= 'z')	continue;
		str.focus();
		return true;
	}
	return false;
}

/* 0:close 1:open*/
function openHelpWindow(filename)
{
	helpWindow = window.open(filename,"thewindow","width=300,height=400,scrollbars=yes,resizable=yes,menubar=no");
}

function checkSave()
{
	answer = confirm("是否保存了本页？");
	if (answer !=0)
		return true;
	else
		return false;
}

function alertPassword(formObj)
{
	alert("重新确认密码！");
	formObj.focus();
}

//Amy add 2005,12,28
function addstr(input_msg)
{
	var last_msg = "";
	var str_location;
	var temp_str_1 = "";
	var temp_str_2 = "";
	var str_num = 0;
	temp_str_1 = addstr.arguments[0];
	while(1)
	{
		str_location = temp_str_1.indexOf("%s");
		if(str_location >= 0)
		{
			str_num++;
			temp_str_2 = temp_str_1.substring(0,str_location);
			last_msg += temp_str_2 + addstr.arguments[str_num];
			temp_str_1 = temp_str_1.substring(str_location+2,temp_str_1.length);
			continue;
		}
		if(str_location < 0)
		{
			last_msg += temp_str_1;
			break;
		}
	}
	return last_msg;
}

function checkInt(text_input_field, field_name, min_value, max_value, required)
// NOTE: Doesn't allow negative numbers, required is true/false
{
	var str = text_input_field.value;
	var error_msg= "";

	if (text_input_field.value.length==0) // blank
	{
		if (required)
			error_msg = addstr(msg_blank,field_name);
	}
	else // not blank, check contents
	{
		for (var i=0; i < str.length; i++)
		{
			if ((str.charAt(i) < '0') || (str.charAt(i) > '9'))
				error_msg = addstr(msg_check_invalid,field_name);
		}
		if (error_msg.length < 2) // don't parse if invalid
		{
			var int_value = parseInt(str);
			if (int_value < min_value)
				error_msg = addstr(msg_greater,field_name,(min_value - 1));
			if (int_value > max_value)
				error_msg = addstr(msg_less,field_name,(max_value + 1));
		}
	}
	if (error_msg.length > 1)
		error_msg = error_msg + "\n";
	return(error_msg);
}
/*pamela20060125
function checkMacStr(mac)
{
	if((mac.value.indexOf(':') != -1)||(mac.value.indexOf('-') != -1))
	{
		mac.value = mac.value.replace(/:/g,"");
		mac.value = mac.value.replace(/-/g,"");
	}
	var temp = mac.value;
	if(mac.value.length != 12)
	{
		mac.focus();
		return true;
	}
	for(i = 0; i < mac.value.length; i++)
	{
		var c = mac.value.substring(i, i+1)
		if(("0" <= c && c <= "9") || ("a" <= c && c <= "f") || ("A" <= c && c <= "F"))
		{
			continue;
		}
		mac.focus();
		return true;
	}
	mac.value = temp.toUpperCase();
	return false;
}
*/
//Amy add end
//Added by Pamela
function isValidName(str,length)
{
	if( CheckIsEmpty(str) || str.length > length)
	    return false;
	    
	for(j = 0; j < str.length; j++)
	{
	    ch = str.charAt(j);
	    if(ch.search(/^[A-Za-z0-9_@.-]/i) == -1)
	        return false;           
	}
    return true;
}
function CheckIsEmpty(s) {
	for(var i = 0; i < s.length; i++) {
		var c = s.charAt(i);
		if((c !=' ') && (c!='\n') && (c !='\t')) return false;
	}
	return true;

}

//check IP address
function isValidIP (addr)
{
    var sub_addr;
    var net_id;
    var host_id;
    if (addr.search(/^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}$/) == -1)
        return false;
    sub_addr = addr.split(/\./);
    if (sub_addr[0] > 0xff || sub_addr[1] > 0xff || sub_addr[2] > 0xff || sub_addr[3] > 0xff)
        return false;        
	
    if(sub_addr[0] == 0 && sub_addr[1] == 0 && sub_addr[2] == 0 && sub_addr[3] == 0)
	return false;

    if(sub_addr[0] == 0xff && sub_addr[1] == 0xff && sub_addr[2] == 0xff && sub_addr[3] == 0xff)
	return false;

    if(sub_addr[0] < 128) /* A class */
    {
        if(sub_addr[0] == 0 || sub_addr[0] == 127)
            return false;
        host_id = sub_addr[1] * 0x10000 + sub_addr[2] * 0x100 + sub_addr[3] * 0x1;
        if(host_id == 0 || host_id == 0xffffff)
            return false;
    }
    else if(sub_addr[0] < 192) /* B class */
    {
        host_id = sub_addr[2] * 0x100 + sub_addr[3] * 0x1; 
        if(host_id == 0 || host_id == 0xffff)
            return false;           
    }
    else if(sub_addr[0] < 224) /* C class */
    {
        host_id = sub_addr[3] * 0x1;
        if(host_id == 0 || host_id == 0xff)
            return false;             
    }
    else  /* Limit broadcast, Multicast net */
    {
        return false;                                         
    }
    
    return true;
}
//check subnet mask
function isValidMask(s) 
{
    var netmask;
    var vaildmask = new Array(0,128,192,224,240,248,252,255);
    var flag=true;
    
    if (s.search(/^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}$/) == -1)
        return false;
    netmask = s.split(/\./);
    
    for(i=0;i<4;i++)
    {
        if(eval(netmask[0])== 0)
           return false;        
        for(j=0;j<=8;j++)
        {
            if(eval(netmask[i]) == vaildmask[j])
            {
                if(!flag && eval(netmask[i])>0)
                    return false;
                if(eval(netmask[i])==255)
                    flag=true;
                else
                    flag=false;
                break;    
            }
        }
        if (j > 8)
            return false;
    }

    
  return true;
}
//marge IP Address to String
function IPv4toString()
{
    var i;
    var argc = IPv4toString.arguments.length;
    var args = IPv4toString.arguments;
    var addr = new Array();
    if(argc > 4)
        return false;    
    for(i = 0; i < argc; i++)
    {
        addr[i] = args[i];    
    }
    
    return addr.join(".");
}
function getValue(str)
{
	var temp = '';
	var flag = 0;
	var i = 0;
	
	if((str.length - 1	) <= 0)
	{
		temp = str.charAt(i) ;
	}
	else
	{
		for(i = 0 ; i <= str.length ;i++)
		{
			if(flag == 0)
			{
		
				if( str.charAt(i) != '0')
				{
					flag = 1;	
					temp += str.charAt(i) ;
				}
			}
			else
			{
				temp += str.charAt(i);
			}
		}
	} 
	
	
	return temp;
}
function isInteger(val)
{
	if(isNaN(val))
		return false;
	
	if(parseInt(val) != val)
		return false;
		
	return true;
}

function isValidPortRange(port)
{
	if(!isInteger(port))
		return false;
	
	if(!isInValidRange(port,1,65534))
		return false;
	
	return true;
}

function isInValidRange(s,low,high) 
{
 	if((isNaN(s))||( s < low || s > high))
 	   	return false;
	else
		return true;
}
function StringtoMac(mac)
{
	var i;
	var octe = "";
	var mac_length = 12;
	for(i=mac_length; i>=0; i--)
	{
		octe = mac.charAt(i)+octe;
		if((((mac_length-i)%2)==0)&&(i!=0)&&(i<mac_length))
			octe = ":"+octe;
	}
	return octe;
}
function isValidMAC(mac)
{
    var i;
    var j;
    var ch;
    var octe = new Array();
  
    mac = mac.toLowerCase();
    octe = mac.split(':');    

    if(mac == "00:00:00:00:00:00" || mac == "ff:ff:ff:ff:ff:ff")
    	return false;
    
    if(octe.length != 6)
        return false;
    else
    {
        tmpLength = octe[0].length;
		ch = octe[0].charAt(tmpLength - 1);
	
		if(ch == "|")
		    return false;
		   
		if(ch.search(/^[0|2|4|6|8|a|c|e]/i) == -1)
			return false;
			
        for(i = 0; i < 6; i++)
        {
            if(octe[i].length != 2 || CheckIsEmpty(octe[i]))
               return false;
            else
            {
                for(j = 0; j < octe[i].length; j++)
                {
                    ch = octe[i].charAt(j);
                    if(ch == "|")
                    {
		                return false;     
		            }                  
                    if(ch.search(/^[0|1|2|3|4|5|6|7|8|9|a|b|c|d|e|f|]/i) == -1)
                    {
                        return false; 
                    }
                }    
            }          
        }        
    }
    return true;
}

function isStringsEqual(s1,s2){
    if(s1.length != s2.length)
        return false;

	for(var i=0;i<s1.length;i++) {
		if (s1.charAt(i) != s2.charAt(i))
			return false;
	}
	return true;
}
function chk_num(event)
{
  if (event.keyCode < 48 || event.keyCode > 57) 
    event.returnValue = false;
}   	
