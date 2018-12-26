#pragma once

#include <curl/curl.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include "pthread.h"
#include <signal.h>
#include <TimeLog.h>
#ifndef WIN32
	#include <setjmp.h>
	#include <netdb.h>
	#include <arpa/inet.h>
	#include <signal.h>
	#include <unistd.h>
	#include <pthread.h>
	#include <arpa/inet.h>
	#include <netinet/in.h>
	#include <err.h>
	#include <sys/ioctl.h>
	#include <sys/socket.h>
	#include <netdb.h>
#else
	#include <vld.h>
	#include "winsock2.h"
	#include "Ws2tcpip.h"
	#pragma comment(lib, "Ws2_32.lib")  
#endif

//http://119.29.29.29/d?dn=[�������ܺ���ַ���]&id=[��ȨID]&ttl=1
#define DNS "http://119.29.29.29/d?dn="
#define ID "&id=[7191]"


std::string Get_IP(void* url);
std::string Get_Port(void* url);
std::string Get_Domain(void* url);
std::string DNS_pod(void* url);
 size_t writeToString(void *ptr, size_t size, size_t count, void *stream);
//int Get_IP_normal(char* IP, const char* url);
std::string Parsing_IP(const char *url);
void set_share_handle(CURL* curl_handle);
void Time_sleep(unsigned long time_ms);


//���������߳��ж����Ǹ��߳̽���Ļ�ȡ��IP
typedef enum STATUS {
	INIT_STATUS = 0,
	SUCCEEDED,//�Ƿ��ȡIP
	UNSUCCEEDED,//��ȡIPʧ��
	POD_TIME_OUT,//����DNS��ʱ����������������ȡIP���̵߳��˳�*******����DNS�߳���*******	
}dns_status;

typedef struct Thread_IP
{
	bool b_start; //�߳��Ƿ�����
	dns_status b_status; //��ǰ�̻߳�ȡIP��״̬
	std::string url;
	std::string IP;	
}ip_param;

extern CTimeLog* p_Timelog;