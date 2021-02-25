# ev_ftp_server

ev_ftp_server是linux环境下基于libevent的简易FTP服务器。

## 具体功能介绍：

### ev_ftp中使用了简易版的FTP协议：

> 命令通道 5001

> 主动模式

> 匿名登录

> 明文传输

### 已实现FTP协议：
>连接成功 
>
     server send:   220 welcome.\r\n
>USER用户登录
>
     server recv:   USER root\r\n
     server send:   230 Login successful.\r\n
>PWD获取当前目录
>
     server recv:   PWD\r\n
     server send:   257 "/" is current directory.\r\n
>CWD进入目录
>
     server recv:   CWD test\r\n
     server send:   250 Directory success changed.\r\n
>CDUP返回上层目录
>
     server recv:   CDUP\r\n
     server send:   250 Directory success changed.\r\n 
>PORT客户端发送数据传送地址和端口
>
     server recv:   PORT n1,n2,n3,n4,n5,n6\r\n    //端口计算方法port=n5*256+n6
     server send:   200 PORT command successful.\r\n
     
>LIST获取目录
>
     server recv:   LIST\r\n
     server send:   150 Here comes the directory.\r\n or 450 file open failed.\r\n
     ---数据通道连接--- 
     server send:   ls -l的结果
     server send:   226 Transfer complete.\r\n
     ---关闭数据通道---
   
>RETR下载文件
>
     server recv:   RETR filepath\r\n
     server send:   150 Transfer start.\r\n or 450 file open failed.\r\n
     ---数据通道连接--- 
     server send:   文件数据给客户端
     server send:   226 Transfer complete.\r\n
     ---关闭数据通道---
     
>STOR下载文件
>
     server recv:   STOR filepath\r\n
     server send:   125 file ok.\r\n
     ---数据通道连接--- 
     server recv:   读取上传文件 
     ---客户端发送结束主动关闭数据通道---
     server send:   226 Transfer complete.

## 环境配置：
### server端：

Linux c++11

g++、libevent、openssl

### client端：

FileZilla客户端

## 编译运行：
### server端：
>
    cd ev_ftp_server
    make

### client端：
>配置站点管理器：
>>
    -常规-
    协议     FTP-文件传输协议 
    主机     设置为服务器ip    
    端口     5001
    加密     只使用明文FTP
    登录类型 匿名
>>
    -传输设置-
    传输模式 主动

>连接成功后即可使用上传、下载等功能。

## 待完善内容：

1、FTP其他协议

2、加密传输文件

3、客户端程序

4、用户管理

5、日志系统

## 相关参考：

libevent_C++高并发网络编程 from夏曹俊老师


