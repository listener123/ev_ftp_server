#pragma once
#include "XFtpTask.h"
class XFtpPORT:public XFtpTask
{
public:
	//解析协议
	virtual void Parse(std::string type,std::string msg);
};