#pragma once
#include "Stdafx.h"
#include "include/EsunnyForeignApi.h"

using namespace ESForeign;
namespace EsForeignWrapper
{

	public ref  class EsTradeApi
	{
	private:
		IEsunnyTradeApi* pIEsunnyTradeApi;
		IEsunnyTradeSpi* pIEsunnyTradeSpi;
		int errorID;
		bool bLogin;

	public:
		RspOpen^            OnRspOpen;
		RspClose^           OnRspClose;
		RspLogin^           OnRspLogin;
		RspInitFinished^    OnRspInitFinished;
		RspLogOut^          OnRspLogOut;
		
		
		RspOrderInsert^  OnRspOrderInsert;
		RspOrderModify^  OnRspOrderModify;
		RspOrderDeleteError^  OnRspOrderDeleteError;
		RspQryOrder^     OnRspQryOrder;
		RspHistOrderQry^ OnRspHistOrderQry;
		RtnOrderState^   OnRtnOrderState;
		RtnOrderInfo^    OnRtnOrderInfo;
		
		RspMatchQry^     OnRspMatchQry;
		RtnMatchState^   OnRtnMatchState;
		RtnMatchInfo^    OnRtnMatchInfo;
		RspHistMatchQry^ OnRspHistMatchQry;
		
		QryContract^     OnQryContract;
		RtnOrderRemove^  OnRtnOrderRemove;
		RtnMatchRemove^  OnRtnMatchRemove;

		QryMoney^        OnQryMoney;
		QryHold^		 OnQryHold;
		QryCommodity^    OnQryCommodity;
		RspQryCurrency^  OnRspQryCurrency;
		RtnExchangeState^ OnRtnExchangeState;

	public:
		EsTradeApi(String^ cer, String^ filePath,String^ appId);
		~EsTradeApi();

#pragma region API
	public:


		// �ر����Ӳ��ͷŵ�ǰapi�Ự
		void  Free();

		// ��ȡ���������������(���ֽڱ���)
		String^  GetErrcodeDesc(int iErrcode);

		//���ӽ��׷����������سɹ�ֻ�����ɹ��������������Ƿ���������Ҫ
		bool  Open(AddressField^ addr);


		//��ȡ�Ƿ��뽻�׷�������������
		bool  IsOpen();


		//���͵�¼������ʱ֧�ֵ��ͻ���½
		int  Login(LoginReqField^ loginReqField, int iReqID);


		///�����˳�����
		int  LogOut(int iReqID) ;
		//���������֤
		int  SetVertificateCode(String^ CertificateCode, int iReqID);

		String^  GetCertCodeExpireDate();


		// ��������
		int  OrderInsert(OrderInsertReqField^ orderInsertReqField, int iReqID);



		// ��������
		int  OrderDelete(int orderId, int iReqID);


		///��ѯ�ͻ��ʽ�
		int QryMoney(MoneyQryReqField^ qryMoney, int iReqID) ;

		//��ѯ�����,����Ȩ��
		//int  QryCashOper(CashOperQryReqField^ req, int iReqID);


		//��ѯ�ͻ�ί�У���ѯ�������� ������0
		int QryOrder(OrderQryReqField^ qryOrder, int iReqID) ;


		///��ѯ�ͻ��ɽ�
		int  QryMatch( MatchQryReqField^ qryMatch, int iReqID) ;


		//��ѯ�ֲ�
		int  QryHold( HoldQryReqField^ qryHold, int iReqID) ;



		// ��ѯ������Ʒ
		int  QryCommodity(CommodityQryReqField^ qryCmdy, int iReqID) ;



		//��ʷί�в�ѯ
		int  QryHistOrder(HisOrderQryReqField^ req, int iReqID) ;


		//��ʷ�ɽ���ѯ
		int QryHistMatch(HisMatchQryReqField^ req, int iReqID) ;

		//��ѯ������Ϣ
		int QryCurrency(CurrencyQryReqField^ req, int iReqID);
				
#pragma endregion
	
//#pragma region Event
//event RspOpen^  OnRspOpen
//{
//	void add(RspOpen^ handler)
//	{
//		this->delegate_RspOpen += handler;
//	}
//	void remove(RspOpen^ handler)
//	{
//		this->delegate_RspOpen -= handler;
//	}
//	void raise()
//	{
//		if (this->delegate_RspOpen != nullptr)
//			this->delegate_RspOpen();
//	}
//}
//
//event RspClose^  OnRspClose
//{
//	void add(RspClose^ handler)
//	{
//		this->delegate_RspClose += handler;
//	}
//	void remove(RspClose^ handler)
//	{
//		this->delegate_RspClose -= handler;
//	}
//	void raise()
//	{
//		if (this->delegate_RspClose != nullptr)
//			this->delegate_RspClose();
//	}
//}
//
//event RspLogin^  OnRspLogin
//{
//	void add(RspLogin^ handler)
//	{
//		this->delegate_RspLogin += handler;
//	}
//	void remove(RspLogin^ handler)
//	{
//		this->delegate_RspLogin -= handler;
//	}
//	void raise(LoginRspField^ pLoginRspField, int errCode, int iReqID)
//	{
//		if (this->delegate_RspLogin != nullptr)
//			this->delegate_RspLogin(pLoginRspField,errCode,iReqID);
//	}
//}
//
//event RspInitFinished^  OnRspInitFinished
//{
//	void add(RspInitFinished^ handler)
//	{
//		this->delegate_RspInitFinished += handler;
//	}
//	void remove(RspInitFinished^ handler)
//	{
//		this->delegate_RspInitFinished -= handler;
//	}
//	void raise(int errCode)
//	{
//		if (this->delegate_RspInitFinished != nullptr)
//			this->delegate_RspInitFinished(errCode);
//	}
//}
//
//event RspLogOut^  OnRspLogOut
//{
//	void add(RspLogOut^ handler)
//	{
//		this->delegate_RspLogOut += handler;
//	}
//	void remove(RspLogOut^ handler)
//	{
//		this->delegate_RspLogOut -= handler;
//	}
//	void raise(int errCode, int iReqID)
//	{
//		if (this->delegate_RspLogOut != nullptr)
//			this->delegate_RspLogOut(errCode,iReqID);
//	}
//}
//
//event RspOrderInsert^  OnRspOrderInsert
//{
//	void add(RspOrderInsert^ handler)
//	{
//		this->delegate_RspOrderInsert += handler;
//	}
//	void remove(RspOrderInsert^ handler)
//	{
//		this->delegate_RspOrderInsert -= handler;
//	}
//	void raise(OrderInsertRspField^ pOrderInsertRspField, int errCode, int iReqID)
//	{
//		if (this->delegate_RspOrderInsert != nullptr)
//			this->delegate_RspOrderInsert(pOrderInsertRspField, errCode,iReqID);
//	}
//}
//#pragma endregion




	};

	//�������ݴ���Ļص������࣬�������ݵ��ﱾ��ʱ��API��ص������ж�Ӧ�Ľӿ�
	//�ص����������������Բ���
	//OnRsp��ͷ�ĺ���Ϊ����������Ӧ��Ӧ��OnRtn��ͷ�ĺ���Ϊ������������������

	class EsTradeSpi : public IEsunnyTradeSpi
	{

	private:
		gcroot<EsTradeApi^ > esTradeApi;
	public:
		EsTradeSpi(EsTradeApi^ esTradeApi) {
			this->esTradeApi = esTradeApi;
		}

	public:
		////////////////////////////////////////
		/// \fn    ~IEsunnyTradeSpi
		/// \brief �����࣬��Ҫ����
		/// \return   
		////////////////////////////////////////
		virtual ~EsTradeSpi() ;

		////////////////////////////////////////
		/// \fn    OnOpen
		/// \brief ���������������ʱ����
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnOpen() ;

		////////////////////////////////////////
		/// \fn    OnClose
		/// \brief ��������Ͽ�����ʱ����
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnClose();

		////////////////////////////////////////
		/// \fn    OnLogin
		/// \brief ����Login��½�ɹ�ʱ�յ���������½��Ӧ����
		/// \param const TEsLoginRspField & rsp
		/// \param int iReqID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnLogin(const TEsLoginRspField* rsp, int errCode, const int iReqID);

		////////////////////////////////////////
		/// \fn    OnInitFinished
		/// \brief ����Login�ɹ����յ�OnLoginӦ��ɹ����յ���ʼ���������
		///        ���е�ҵ�������Ҫ�ڱ���ӦerrCodeΪ0���ɹ�����ɽ���
		/// \param int errCode �����룬0-�ɹ�������ֵ-�����ԭ�����
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnInitFinished(int errCode) ;

		////////////////////////////////////////
		/// \fn    OnLogOut
		/// \brief �յ��ǳ�Ӧ�����
		/// \param int errCode
		/// \param const int iReqID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnLogOut(int errCode, const int iReqID) ;

		

		////////////////////////////////////////
		/// \fn    OnQryMoney
		/// \brief �ʽ��ѯӦ��
		/// \param TEsMoneyQryRspField * rsp ��ѯ���ʱ��ָ��Ϊ�գ�δ���ʱ������ѯ���
		/// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
		/// \param const int iReqID ��Ӧ���������ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnQryMoney(const TEsMoneyQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) ;

		

		
		////////////////////////////////////////
		/// \fn    OnRspOrderInsert
		/// \brief ���������Ӧ��
		/// \param TEsOrderInsertRspField & rsp �����������ϸ������᷵��ί�кż����غ�
		/// \param const int iReqID ��Ӧ���������ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspOrderInsert(const TEsOrderInsertRspField* rsp, int errCode, const int iReqID) ;

		////////////////////////////////////////
		/// \fn    OnRspOrderModify
		/// \brief �ĵ������Ӧ�𣬳���ʱ���յ���Ӧ��
		/// \param TEsOrderModifyRspField & rsp
		/// \param const int iReqID ��Ӧ���������ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspOrderModify(const TEsOrderModifyRspField* rsp, int errCode, const int iReqID);

		////////////////////////////////////////
		/// \fn    OnRspOrderDelete
		/// \brief ���������Ӧ�𣬳���ʱ���յ���Ӧ��
		/// \param TEsOrderDeleteRspField & rsp
		/// \param const int iReqID ��Ӧ���������ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspOrderDelete(const TEsOrderDeleteRspField* rsp, int errCode, const int iReqID) ;

		////////////////////////////////////////
		/// \fn    OnRspQryOrder
		/// \brief ί�в�ѯӦ��
		/// \param TEsOrderDataQryRspField * rsp ί�в�ѯ�������ѯ���ʱ��ָ��Ϊ��
		/// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
		/// \param const int iReqID ��Ӧ���������ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspQryOrder(const TEsOrderDataQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) ;

		////////////////////////////////////////
		/// \fn    OnRspHistOrderQry
		/// \brief ��ʷί�в�ѯӦ��
		/// \param TEsHisOrderQryRspField * rsp ��ʷί�в�ѯ�������ѯ���ʱ��ָ��Ϊ��
		/// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
		/// \param const int iReqID ��Ӧ���������ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspHistOrderQry(const TEsHisOrderQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) ;

		////////////////////////////////////////
		/// \fn    OnRtnOrderState
		/// \brief ί�б仯֪ͨ��ί��״̬�仯ʱ�ص�
		/// \param TEsOrderStateNoticeField & rsp ί����ϸ����
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRtnOrderState(const TEsOrderStateNoticeField& rsp) ;

		////////////////////////////////////////
		/// \fn    OnRtnOrderInfo
		/// \brief ί����Ϣ�仯֪ͨ��ί����Ϣ�仯ʱ�ص�
		/// \param TEsOrderInfoNoticeField & rsp ί����Ϣ��ϸ����
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRtnOrderInfo(const TEsOrderInfoNoticeField& rsp) ;

		////////////////////////////////////////
		/// \fn    OnRspMatchQry
		/// \brief  �ɽ���ѯӦ��
		/// \param TEsMatchDataQryRspField * rsp �ɽ���ѯ�������ѯ���ʱ��ָ��Ϊ��
		/// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
		/// \param const int iReqID ��Ӧ���������ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspMatchQry(const TEsMatchDataQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) ;

		////////////////////////////////////////
		/// \fn    OnRtnMatchState
		/// \brief �ɽ��仯����֪ͨ
		/// \param TEsMatchStateNoticeField & rsp �ɽ���ϸ����
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRtnMatchState(const TEsMatchStateNoticeField& rsp) ;

		////////////////////////////////////////
		/// \fn    OnRtnMatchInfo
		/// \brief �ɽ���Ϣ�仯����֪ͨ
		/// \param TEsMatchInfoNoticeField & rsp �ɽ���Ϣ��ϸ����
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRtnMatchInfo(const TEsMatchInfoNoticeField& rsp) ;

		////////////////////////////////////////
		/// \fn    OnRspHistMatchQry
		/// \brief ��ʷ�ɽ���ѯӦ��
		/// \param TEsHisMatchQryRspField * rsp ��ʷ�ɽ���ѯ�������ѯ���ʱ��ָ��Ϊ��
		/// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
		/// \param const int iReqID ��Ӧ���������ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspHistMatchQry(const TEsHisMatchQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) ;

		////////////////////////////////////////
		/// \fn    OnQryHold
		/// \brief �ֲֲ�ѯӦ��
		/// \param TEsHoldQryRspField * rsp �ֲֲ�ѯ�������ѯ���ʱ��ָ��Ϊ��
		/// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
		/// \param const int iReqID ��Ӧ���������ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnQryHold(const TEsHoldQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) ;

		////////////////////////////////////////
		/// \fn    OnRtnExchangeState
		/// \brief �г�״̬�������֪ͨ
		/// \param TEsExchangeQryRspField & rsp �г�״̬��ϸ��Ϣ
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRtnExchangeState(const TEsExchangeStateModifyNoticeField& rsp);

		
		
		////////////////////////////////////////
		/// \fn    OnQryCommodity
		/// \brief ��Ʒ��ѯӦ��
		/// \param TEsCommodityQryRspField * rsp ��Ʒ��ϸ��Ϣ����ѯ���ʱ��ָ��Ϊ��
		/// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
		/// \param const int iReqID ��Ӧ���������ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnQryCommodity(const TEsCommodityQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) ;


	

		////////////////////////////////////////
		/// \fn    OnRspQryCurrency
		/// \brief ��ѯ���ұ�����ϢӦ��
		/// \param const TEsCurrencyQryRspField * rsp
		/// \param int errCode
		/// \param const int iReqID
		/// \return void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspQryCurrency(const TEsCurrencyQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) ;


		////////////////////////////////////////
		/// \fn    OnRtnOrderRemove
		/// \brief ί��ɾ��֪ͨ
		/// \param const TEsOrderRemoveNoticeField & rsp
		/// \return void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRtnOrderRemove(const TEsOrderRemoveNoticeField& rsp) ;

		
	};
}


