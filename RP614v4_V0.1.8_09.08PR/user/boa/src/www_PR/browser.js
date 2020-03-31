function isIE(){
		var browser = new Object();
		browser.version = parseInt(navigator.appVersion);
		browser.isNs = false;
		browser.isIe = false;
		if(navigator.appName.indexOf("Netscape") != -1)
			browser.isNs = true;
		else if(navigator.appName.indexOf("Microsoft") != -1)
			browser.isIe = true;
			
		if(browser.isNs)
			return false;
		else if (browser.isIe)
			return true;

}
 function add(out,in1,in2,in3,in4)
{
  var Total;
  Total=in1.value+"."+in2.value+"."+in3.value+"."+in4.value; 
 // document.mytemp.all.value=Total;//mark
   out.value=Total;
 // document.write(document.mytemp.all.value);
 //  document.write(out);
 
} 
function load4(Mydata,ip1,ip2,ip3,ip4)
{
  
   var len;
   var ad;
   var temp;
   var Myall;
   Myall=Mydata.value; 
   //ip1
   len=Myall.length;
   temp=Myall.indexOf(".");
   ad=Myall.substring(0,temp);
   ip1.value=ad;
   
   //ip2
   Myall=Myall.substring(temp+1,len);
   len=Myall.length;
   temp=Myall.indexOf(".");
   ad=Myall.substring(0,temp);
   ip2.value=ad;
   
   //ip3
   Myall=Myall.substring(temp+1,len);
   len=Myall.length;
   temp=Myall.indexOf(".");
   ad=Myall.substring(0,temp);
   ip3.value=ad;
   
   //ip4
   Myall=Myall.substring(temp+1,len);
   ad=Myall;
   ip4.value=ad;
  
}

function OScheck()
{
	var theAgent = navigator.userAgent;
	if (theAgent.indexOf("Mac") >= 0) {
		return "MacOS";
	}
	if (theAgent.indexOf("Win") >= 0) {
		return "Windows95/98/NT";
	}
	return "UNIX";	
}

function browserVer()
{
	var version;
	version = navigator.appVersion;
	if (version.indexOf("5.0") >= 0) {
		return "new";
	}
	else 
		return "old";
}