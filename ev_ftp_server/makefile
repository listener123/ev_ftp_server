SRC=ev_ftp_server.cpp XThreadPool.cpp XThread.cpp XFtpServerCMD.cpp\
XFtpFactory.cpp XFtpTask.cpp XFtpLIST.cpp XFtpPORT.cpp XFtpUSER.cpp XFtpRETR.cpp XFtpSTOR.cpp
evftpserver:$(SRC) 
	g++ -std=c++11 $^ -o $@ -levent -lpthread
	./$@
clean:
	rm -rf evftpserver
	rm -rf *.o
