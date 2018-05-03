#pragma once

#include "Stdafx.h"


namespace EsForeignWrapper
{

	public ref class EsQuotApi
	{
	private:
		IEsunnyQuotClient* pQuotClient;
		IEsunnyQuotNotify* pQuotNotify;
		int errorID;
		bool bLogin;

	public:
		/**
		*��ʼ��API��Կ
		* @param secretkey ��Կ
		* @param option 1��ʾ��Ҫ������ȨƷ�֣�0��ʾ����Ҫ������Ȩ
		* @return 0��ʾ�ɹ�������ʧ��
		*/
		EsQuotApi(String^ secretkey, int option);
		~EsQuotApi(void);

	public:
		/*
		*�����������ݷ�����IP���˿�
		* @param ip ��������IP
		* @param port �������Ķ˿�
		* @return 0��ʾ���ӳɹ�������ʧ��
		*/
		 int  Connect(String^ ip, int port);

		/*
		*�Ͽ���ǰ����
		*/
		 void  DisConnect();

		 /*
		   �ͷŶ���
		 */
		 void Free();

		/*
		*��¼�������ݷ�����
		* @param user ��¼�û���
		* @param password ��¼����
		* @return 0��ʾ��¼ָ��ͳɹ���������ʧ�ܣ��Ƿ��¼�ɹ�ͨ���ص�OnRspLogin
		*/
		 int Login(String^ user, String^ password);

		/*
		*����/ȡ������Ʒ�ּ�ʱ����
		* @param market �г�������
		* @param stk ��Լ����
		* @param need 1��ʾ���ģ�0��ʾȡ������
		* @return 0��ʾ��������ɹ�������ʧ�ܣ��ɹ�֮�󽫻���OnStkQuot���յ�Ʒ�ֵļ�ʱ����
		*/
		 int  RequestQuot(String^ market, String^ stk, int need);

		/*
		*����Ʒ����ʷ����
		* @param market �г�������
		* @param stk ��Լ����
		* @param period ���� 1��1���ӣ�2��5���ӣ�3��60���ӣ�4������
		* @return 0��ʾ����ɹ�������ʧ�ܣ���ʷ���ݽ����OnRspHistoryQuot����
		*/
		 int  RequestHistory(String^ market, String^ stk, int period);

		/*
		*����Ʒ����ϸ����
		* @param market �г�������
		* @param stk ��Լ����
		* @param date Ҫ������ϸ�����ڣ�����20090901
		* @return 0��ʾ����ɹ�������ʧ�ܣ���ʷ���ݽ����OnRspTraceData����
		*/
		 int  RequestTrace(String^ market, String^ stk, String^ date);

		/*
		*��Զ���Ʒ�ֱȽ϶�ʱ����ѭ������AddReqStk��������һ��SendReqStk
		* @param market �г�������
		* @param stk ��Լ����
		* @param need 1��ʾ���ģ�0��ʾȡ������
		* @return 0��ʾ��������ɹ�������ʧ�ܣ��ɹ�֮�󽫻���OnStkQuot���յ�Ʒ�ֵļ�ʱ����
		*/
		 int  AddReqStk(String^ market, String^ stk, int need);

		/*
		*������������Ʒ�ֶ�������
		* @return 0��ʾ��������ɹ�������ʧ�ܣ��ɹ�֮�󽫻���OnStkQuot���յ�Ʒ�ֵļ�ʱ����
		*/
		 int  SendReqStk();




	public:
		RspQuotLogin^		OnRspLogin;
		ChannelLost^		OnChannelLost;
		StkQuot^			OnStkQuot;
		RspHistoryQuot^		OnRspHistoryQuot;
		RspTraceData^		OnRspTraceData;
		RspMarketInfo^		OnRspMarketInfo;

	//public:
	//	/**
	//	*��¼�����ص�����
	//	* @param err ����� 0��ʾ��¼�ɹ�������ʧ��
	//	* @param errtext ������Ϣ
	//	* @return 0��ʾ�ɹ�������ʧ��
	//	*/
	//	event RspQuotLogin^ OnRspLogin
	//	{
	//		void add(RspQuotLogin^ handler)
	//		{
	//			this->delegate_RspLogin += handler;
	//		}
	//		void remove(RspQuotLogin^ handler)
	//		{
	//			this->delegate_RspLogin -= handler;
	//		}
	//		void raise(int err, String^ errtext)
	//		{
	//			if (this->delegate_RspLogin != nullptr)
	//				this->delegate_RspLogin(err, errtext);
	//		}
	//	}

	//	/**
	//	*�������ӳ���ص�����
	//	* @param err �����
	//	* @param errtext ������Ϣ
	//	* @return 0��ʾ�ɹ�������ʧ��
	//	*/
	//	event ChannelLost^ OnChannelLost
	//	{
	//		void add(ChannelLost^ handler)
	//		{
	//			this->delegate_ChannelLost += handler;
	//		}
	//		void remove(ChannelLost^ handler)
	//		{
	//			this->delegate_ChannelLost -= handler;
	//		}
	//		void raise(int err, String^ errtext)
	//		{
	//			if (this->delegate_ChannelLost)
	//				 this->delegate_ChannelLost(err, errtext);
	//		}
	//	}

	//	/**
	//	*��ʱ����ص�����
	//	* @param pData ����ṹָ��
	//	* @return 0��ʾ�ɹ�������ʧ��
	//	*/
	//	event StkQuot^ OnStkQuot
	//	{
	//		void add(StkQuot^ handler)
	//		{
	//			this->delegate_StkQuot += handler;
	//		}
	//		void remove(StkQuot^ handler)
	//		{
	//			this->delegate_StkQuot -= handler;
	//		}
	//		void raise(StkData^ pData)
	//		{
	//			if (this->delegate_StkQuot)
	//				this->delegate_StkQuot(pData);
	//		}
	//	}

	//	/**
	//	*��ʷ���鷴���ص�����
	//	* @param pHisData ��ʷ�������ݽṹָ��
	//	* @return 0��ʾ�ɹ�������ʧ��
	//	*/
	//	event RspHistoryQuot^ OnRspHistoryQuot
	//	{
	//		void add(RspHistoryQuot^ handler)
	//		{
	//			this->delegate_RspHistoryQuot += handler;
	//		}
	//		void remove(RspHistoryQuot^ handler)
	//		{
	//			this->delegate_RspHistoryQuot -= handler;
	//		}
	//		void raise(StkHisData^ pHisData)
	//		{
	//			if (this->delegate_RspHistoryQuot)
	//				 this->delegate_RspHistoryQuot(pHisData);

	//		}
	//	}

	//	/**
	//	*��ϸ���ݷ����ص�����
	//	* @param pTraceData ��ϸ���ݽṹָ��
	//	* @return 0��ʾ�ɹ�������ʧ��
	//	*/
	//	event RspTraceData^ OnRspTraceData
	//	{
	//		void add(RspTraceData^ handler)
	//		{
	//			this->delegate_RspTraceData += handler;
	//		}
	//		void remove(RspTraceData^ handler)
	//		{
	//			this->delegate_RspTraceData -= handler;
	//		}
	//		void raise(StkTraceData^ pTraceData)
	//		{
	//			if (this->delegate_RspTraceData)
	//				 this->delegate_RspTraceData(pTraceData);
	//		}
	//	}

	//	/**
	//	*�г���Ϣ�������������յ��г���Ϣ��ʾ�����Ѿ���ʼ������ˣ�
	//	* @param pMarketInfo �г���Ϣ����ָ��
	//	* @param bLast �Ƿ�Ϊ���һ���г���bLastΪ1��ʾ�����һ����0��ʾ���滹���г�����
	//	* @return 0��ʾ�ɹ�������ʧ��,
	//	*/
	//	event RspMarketInfo^ OnRspMarketInfo
	//	{
	//		void add(RspMarketInfo^ handler)
	//		{
	//			this->delegate_RspMarketInfo += handler;
	//		}
	//		void remove(RspMarketInfo^ handler)
	//		{
	//			this->delegate_RspMarketInfo -= handler;
	//		}
	//		void raise(WMarketInfo^ pMarketInfo, int bLast)
	//		{
	//			if (this->delegate_RspMarketInfo)
	//				 this->delegate_RspMarketInfo(pMarketInfo, bLast);
	//		}
	//	}
	};

	public  class IEsQuotSpi {
		void OnRspLogin();
	};


	class  EsQuotSpi : public IEsunnyQuotNotify
	{
	private:
		gcroot<EsQuotApi^ > client;
	public:
		EsQuotSpi(EsQuotApi^ esQuotClient) {
			this->client = esQuotClient;
		}
		void SetQuotClient(EsQuotApi^ esQuotClient) {
			this->client = esQuotClient;
		}

	public:
		/**
		*��¼�����ص�����
		* @param err ����� 0��ʾ��¼�ɹ�������ʧ��
		* @param errtext ������Ϣ
		* @return 0��ʾ�ɹ�������ʧ��
		*/
		virtual int __cdecl OnRspLogin(int err, const char *errtext);

		/**
		*�������ӳ���ص�����
		* @param err �����
		* @param errtext ������Ϣ
		* @return 0��ʾ�ɹ�������ʧ��
		*/
		virtual int __cdecl OnChannelLost(int err, const char *errtext);

		/**
		*��ʱ����ص�����
		* @param pData ����ṹָ��
		* @return 0��ʾ�ɹ�������ʧ��
		*/
		virtual int __cdecl OnStkQuot(struct STKDATA *pData);

		/**
		*��ʷ���鷴���ص�����
		* @param pHisData ��ʷ�������ݽṹָ��
		* @return 0��ʾ�ɹ�������ʧ��
		*/
		virtual int __cdecl OnRspHistoryQuot(struct STKHISDATA *pHisData);

		/**
		*��ϸ���ݷ����ص�����
		* @param pTraceData ��ϸ���ݽṹָ��
		* @return 0��ʾ�ɹ�������ʧ��
		*/
		virtual int __cdecl OnRspTraceData(struct STKTRACEDATA *pTraceData);

		/**
		*�г���Ϣ�������������յ��г���Ϣ��ʾ�����Ѿ���ʼ������ˣ�
		* @param pMarketInfo �г���Ϣ����ָ��
		* @param bLast �Ƿ�Ϊ���һ���г���bLastΪ1��ʾ�����һ����0��ʾ���滹���г�����
		* @return 0��ʾ�ɹ�������ʧ��,
		*/
		virtual int __cdecl OnRspMarketInfo(struct MarketInfo *pMarketInfo, int bLast);
	};


};