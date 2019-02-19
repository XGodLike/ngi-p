#pragma once

#include <queue>
#include <string>
#include <curl/curl.h>

#include "VcyberVoiceSDK.h"
using namespace std;

typedef struct _QueueBuf
{
	string buf;
	bool b_Last;
}qBuf;
typedef struct _Databuf
{
	queue<qBuf> q_buf;
	ResultData m_result;//vd���
	bool b_start;//�߳��Ƿ�����
	bool b_run;//�߳��Ƿ�Ҫ����
	bool b_last;//�Ƿ��������һ����Ƶ
	CURLcode c_code;//���緵����
}dataBuf;

class Configs {
public:
	// ��ѡ ��������ַ
	std::string m_server_addr;
	std::string m_server_ip;
	std::string m_server_port;
	// ��ѡ Ӧ�ó���ID
	std::string m_app_id;
	// ��ѡ���ն˷�������ʱ�Ķ�λ��Ϣ��
	// ��ʽ�ǡ�γ��, ���ȡ���ע��˳�򣩣����磺39.983085, 116.80619��
	std::string m_gps;
	// ��ѡ ����vin�롣
	std::string m_vin;
	// ��ѡ �ն�mac��ַ��
	std::string m_mac;
	// ��ѡ���ն�������ַ��
	std::string m_bluetooth;
	// ��ѡ���û��ֻ����롣
	std::string m_tel;
	// ��ѡ�����ƺš�
	std::string m_carnum;
	// ��ѡ���������š�
	std::string m_engine;
	// ��ѡ����ǰ�������ơ� 
	std::string m_city;
	//��ѡ��Ĭ�������־
	bool b_log;
	//��ѡ��Ĭ��ѡ������DNS
	bool b_dns;


	bool Init(const char *str);

};

class SessionParam
{
public:
	//�ж�����״̬
	_eReturnCode  m_state;
	//�������У��߳�״̬����Ƶ״̬������״̬�Ľṹ��
	dataBuf* m_data;
	//�Ƿ�put�����һ����Ƶ
	bool put_last_audio;
	// 
	curl_slist* m_http_headers;
	// ������id
	int m_packet_id;
	// ��������ID
	int m_audio_index;
	// ������
	int m_error_code;
	// ������Ϣ	
	std::string m_error_message;

	/////////////////////beginʱ���п��ܻ���µ�����/////////////////////////////////////
	// ��ѡ���ն˷�������ʱ�Ķ�λ��Ϣ��
	// ��ʽ�ǡ�γ��, ���ȡ���ע��˳�򣩣����磺39.983085, 116.80619��
	std::string m_gps;
	// ��ѡ ����vin�롣
	std::string m_vin;
	// ��ѡ �ն�mac��ַ��
	std::string m_mac;
	// ��ѡ���ն�������ַ��
	std::string m_bluetooth;
	// ��ѡ���û��ֻ����롣
	std::string m_tel;
	// ��ѡ�����ƺš�
	std::string m_carnum;
	// ��ѡ���������š�	
	std::string m_engine;
	// ��ѡ����ǰ�������ơ� 
	std::string m_city;

	//������չ;
	std::string m_other;

/////////////////////////////////////////////////
	// ��ѡ��������Ƶ�ĸ�ʽ��
	// 1��8Khz��16bit��1channel
	// 2��16Khz��16bit��1channel��Ĭ�ϣ�
	int m_audio_format;
	
	//��ѡ����Ƶѹ���ȼ�����Χ��[0 - 10]��0��ʾ��ѹ����
	// Ĭ��10��
	// ֻ������������ʶ������ƶ�֮��Ľ�������Ӱ��ӿڳ������Ƶ���ݡ�
	int m_audio_quality;

	// ��ѡ���Ƿ񷵻������������ݡ�
	// 0�������أ�Ĭ�ϣ�
	// 1������
	std::string m_tts;

	// ��ѡ���������ӳ�ʱʱ�䣬��λ�롣Ĭ��5�롣
	//std::string m_time_out;
	int m_time_out;
	
	// ��ѡ����ǰҵ�����ͣ���poi������tel������music������radio��...��
	// Ӧ��ȷ����ǰҵ��ʱ������ͨ���ò���ָ�����Ա���߷�����ʶ��Ч�ʡ�
	std::string m_business;
	

	
	// ����
	void *tsilk_enc;
	// ����
	void *tsilk_dec;

	SessionParam(const char *str);
	~SessionParam();
};
