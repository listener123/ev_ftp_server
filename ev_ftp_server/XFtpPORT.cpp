#include "XFtpPORT.h"
#include <vector>
#include <iostream>
using namespace std;
void XFtpPORT::Parse(string type,string msg)
{
	//PORT n1,n2,n3,n4,n5,n6\r\n
    //port=n5*256+n6
	
	//只获取ip和端口，不连接
	//取出ip
	vector<string> vals;
	string tmp="";
	for(int i=5;i<msg.size();i++)
	{
		if(msg[i]==','||msg[i]=='\r')
		{
			vals.push_back(tmp);
			tmp="";
			continue;
		}
		tmp+=msg[i];
	}
	if(vals.size()!=6)
	{
		//PORT格式数据有误
		ResCMD("501 Syntax");
		return;
	}
	ip=vals[0]+"."+vals[1]+"."+vals[2]+"."+vals[3];
	port=atoi(vals[4].c_str())*256+atoi(vals[5].c_str());
	cout<<"IP is "<<ip<<endl;
	cout<<"PORT is "<<port<<endl;
	ResCMD("200 PORT command successful.\r\n");
}
