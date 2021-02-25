#include "XFtpUSER.h"
#include <iostream>
using namespace std;
//解析协议
void XFtpUSER::Parse(string type,string msg)
{
	cout<<"XFtpUSER::Parse "<<type<<" "<<msg<<endl;
	ResCMD("230 Login successful.\r\n");
}
XFtpUSER::XFtpUSER()
{
	
}
XFtpUSER::~XFtpUSER()
{
	
}
