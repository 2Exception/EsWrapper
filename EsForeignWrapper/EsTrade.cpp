#include "stdafx.h"
#include "EsTrade.h"
#include <exception>   

namespace EsForeignWrapper
{
#pragma region API����ʵ��
	EsTradeApi::EsTradeApi(String^ cer, String^ logPath, String^ appId)
	{
		//char *frontAddress = (char*)(void*)Marshal::StringToHGlobalAnsi(pszFrontAddress);
		char *pcer = (char*)(void*)Marshal::StringToHGlobalAnsi(cer);
		char *pAppId = (char*)(void*)Marshal::StringToHGlobalAnsi(appId);
		char *plogPath = (char*)(void*)Marshal::StringToHGlobalAnsi(logPath);
		int pRetCode = -1;
		//����API
		this->pIEsunnyTradeApi = CreateEsunnyForeignTradeApi(pcer, &pRetCode, plogPath, pAppId);
		if (pIEsunnyTradeApi == NULL) {
			throw gcnew Exception("CreateEsunnyForeignTradeApi ERROR,Code:" + pRetCode);
		}

		//����SPI
		this->pIEsunnyTradeSpi = new EsTradeSpi(this);
		//����SPI
		this->pIEsunnyTradeApi->SetSpi(this->pIEsunnyTradeSpi);


	}
	EsTradeApi::~EsTradeApi() {
	}

	void EsTradeApi::Free()
	{
		//�Ͽ�����
		this->pIEsunnyTradeApi->Close();
		//����ʵ��
		this->pIEsunnyTradeApi->Free();
	}

	String^  EsTradeApi::GetErrcodeDesc(int iErrcode)
	{
		return gcnew String(this->pIEsunnyTradeApi->GetErrcodeDesc(iErrcode));

	}

	bool EsTradeApi::Open(AddressField^ addr)
	{
		bool isOpen = this->pIEsunnyTradeApi->IsOpen();
		if (isOpen == false) {
			Console::WriteLine("EsTradeApiδ���ӣ���ʼ����...");
			TEsAddressField addrField;
			Marshal::StructureToPtr(addr, IntPtr(&addrField), true);
			isOpen=this->pIEsunnyTradeApi->Open(addrField);
		}
		return isOpen;
	}



	bool EsTradeApi::IsOpen()
	{
		return this->pIEsunnyTradeApi->IsOpen();
	}

	int EsTradeApi::Login(LoginReqField^ loginReqField, int iReqID)
	{

		TEsLoginReqField  req;
		Marshal::StructureToPtr(loginReqField, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->Login(req, iReqID);
	}

	int EsTradeApi::LogOut(int iReqID)
	{
		return this->pIEsunnyTradeApi->LogOut(iReqID);
	}

	int  EsTradeApi::SetVertificateCode(String^ certificateCode, int iReqID)
	{
		char *pcer = (char*)(void*)Marshal::StringToHGlobalAnsi(certificateCode);
		return this->pIEsunnyTradeApi->SetVertificateCode(pcer,iReqID);
	}

	String^  EsTradeApi::GetCertCodeExpireDate()
	{
		char pexpireDate[11];		
		this->pIEsunnyTradeApi->GetCertCodeExpireDate(pexpireDate);
		String^ ret = Marshal::PtrToStringAnsi(IntPtr(&pexpireDate));
		return ret;

	}



	int  EsTradeApi::OrderInsert(OrderInsertReqField^ orderInsertReqField, int iReqID)
	{
		TEsOrderInsertReqField req;
		Marshal::StructureToPtr(orderInsertReqField, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->OrderInsert(req, iReqID);

	}

	int  EsTradeApi::OrderDelete(int orderId, int iReqID)
	{
		TEsOrderDeleteReqField req;
		req.OrderId = orderId;
		return this->pIEsunnyTradeApi->OrderDelete(req,iReqID);
	}

	int EsTradeApi::QryMoney(MoneyQryReqField^ qryMoney, int iReqID)
	{
		TEsMoneyQryReqField req;
		Marshal::StructureToPtr(qryMoney, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->QryMoney(req,iReqID);
	}

	int  EsTradeApi::QryOrder(OrderQryReqField^ qryOrder, int iReqID)
	{
		TEsOrderQryReqField req;
		Marshal::StructureToPtr(qryOrder, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->QryOrder(req, iReqID);
	}
	int  EsTradeApi::QryMatch(MatchQryReqField^ qryMatch, int iReqID)
	{
		TMatchQryReqField req;
		Marshal::StructureToPtr(qryMatch, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->QryMatch(req, iReqID);
	}
	int   EsTradeApi::QryHold(HoldQryReqField^ qryHold, int iReqID)
	{
		TEsHoldQryReqField req;
		Marshal::StructureToPtr(qryHold, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->QryHold(req, iReqID);
	}

	int  EsTradeApi::QryCommodity(CommodityQryReqField^ qryCmdy, int iReqID)
	{
		TEsCommodityQryReqField req;
		Marshal::StructureToPtr(qryCmdy, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->QryCommodity(req, iReqID);
	}

	int   EsTradeApi::QryHistOrder(HisOrderQryReqField^ qryOrder, int iReqID)
	{
		TEsHisOrderQryReqField req;
		Marshal::StructureToPtr(qryOrder, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->QryHistOrder(req, iReqID);
	}

	int  EsTradeApi::QryHistMatch(HisMatchQryReqField^ qryMatch, int iReqID)
	{
		TEsHisMatchQryReqField req;
		Marshal::StructureToPtr(qryMatch, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->QryHistMatch(req, iReqID);
	}

	int EsTradeApi::QryCurrency(CurrencyQryReqField^ qryCurrency, int iReqID)
	{
		TEsCurrencyQryReqField req;
		Marshal::StructureToPtr(qryCurrency, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->QryCurrency(req, iReqID);
	}



#pragma endregion


#pragma region SPI����ʵ��
	//�����࣬��Ҫ����
	EsTradeSpi::~EsTradeSpi()
	{
		Console::WriteLine("EsTradeSpi����");
	}


	//���������������ʱ����
	void EsTradeSpi::OnOpen()
	{
		Console::WriteLine("EsTradeSpi���ӻص�");
		this->esTradeApi->OnRspOpen();
	}


	//��������Ͽ�����ʱ����
	void EsTradeSpi::OnClose()
	{
		this->esTradeApi->OnRspClose();
	}


	//����Login��½�ɹ�ʱ�յ���������½��Ӧ����
	void EsTradeSpi::OnLogin(const TEsLoginRspField* rsp, int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspLogin(TypeConverter<LoginRspField^,  TEsLoginRspField>::ToManagedType((TEsLoginRspField *)rsp),errCode,iReqID);
	}


	/// \brief ����Login�ɹ����յ�OnLoginӦ��ɹ����յ���ʼ���������
	///        ���е�ҵ�������Ҫ�ڱ���ӦerrCodeΪ0���ɹ�����ɽ���
	/// \param int errCode �����룬0-�ɹ�������ֵ-�����ԭ�����
	void EsTradeSpi::OnInitFinished(int errCode)
	{
		this->esTradeApi->OnRspInitFinished(errCode);
	}


	/// \brief �յ��ǳ�Ӧ�����
	void EsTradeSpi::OnLogOut(int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspLogOut(errCode,iReqID);
	}



	/// \brief �ʽ��ѯӦ��
	void EsTradeSpi::OnQryMoney(const TEsMoneyQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID)
	{
		this->esTradeApi->OnQryMoney(TypeConverter<MoneyQryRspField^, TEsMoneyQryRspField>::ToManagedType((TEsMoneyQryRspField *)rsp),islast,errCode,iReqID);
	}




	////////////////////////////////////////
	/// \fn    OnRspOrderInsert
	/// \brief ���������Ӧ��
	/// \param TEsOrderInsertRspField & rsp �����������ϸ������᷵��ί�кż����غ�
	/// \param const int iReqID ��Ӧ���������ID
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRspOrderInsert(const TEsOrderInsertRspField* rsp, int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspOrderInsert(TypeConverter<OrderInsertRspField^, TEsOrderInsertRspField>::ToManagedType((TEsOrderInsertRspField *)rsp),errCode,iReqID);
	}

	////////////////////////////////////////
	/// \fn    OnRspOrderModify
	/// \brief �ĵ������Ӧ�𣬳���ʱ���յ���Ӧ��
	/// \param TEsOrderModifyRspField & rsp
	/// \param const int iReqID ��Ӧ���������ID
	/// \return   void __cdecl
	////////////////////////////////////////
	void  EsTradeSpi::OnRspOrderModify(const TEsOrderModifyRspField* rsp, int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspOrderModify(TypeConverter<OrderModifyRspField^, TEsOrderModifyRspField>::ToManagedType((TEsOrderModifyRspField *)rsp), errCode, iReqID);
	}

	////////////////////////////////////////
	/// \fn    OnRspOrderDelete
	/// \brief ���������Ӧ�𣬳���ʱ���յ���Ӧ��
	/// \param TEsOrderDeleteRspField & rsp
	/// \param const int iReqID ��Ӧ���������ID
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRspOrderDelete(const TEsOrderDeleteRspField* rsp, int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspOrderDeleteError( errCode, iReqID);

	}

	////////////////////////////////////////
	/// \fn    OnRspQryOrder
	/// \brief ί�в�ѯӦ��
	/// \param TEsOrderDataQryRspField * rsp ί�в�ѯ�������ѯ���ʱ��ָ��Ϊ��
	/// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
	/// \param const int iReqID ��Ӧ���������ID
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRspQryOrder(const TEsOrderDataQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspQryOrder(TypeConverter<OrderDataQryRspField^, TEsOrderDataQryRspField>::ToManagedType((TEsOrderDataQryRspField *)rsp),islast, errCode, iReqID);

	}

	////////////////////////////////////////
	/// \fn    OnRspHistOrderQry
	/// \brief ��ʷί�в�ѯӦ��
	/// \param TEsHisOrderQryRspField * rsp ��ʷί�в�ѯ�������ѯ���ʱ��ָ��Ϊ��
	/// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
	/// \param const int iReqID ��Ӧ���������ID
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRspHistOrderQry(const TEsHisOrderQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspHistOrderQry(TypeConverter<HisOrderQryRspField^, TEsHisOrderQryRspField>::ToManagedType((TEsHisOrderQryRspField *)rsp), islast, errCode, iReqID);

	}

	////////////////////////////////////////
	/// \fn    OnRtnOrderState
	/// \brief ί�б仯֪ͨ��ί��״̬�仯ʱ�ص�
	/// \param TEsOrderStateNoticeField & rsp ί����ϸ����
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRtnOrderState(const TEsOrderStateNoticeField& rsp)
	{
		this->esTradeApi->OnRtnOrderState(TypeConverter<OrderStateNoticeField^, TEsOrderStateNoticeField>::ToManagedType((TEsOrderStateNoticeField *)&rsp));

	}

	////////////////////////////////////////
	/// \fn    OnRtnOrderInfo
	/// \brief ί����Ϣ�仯֪ͨ��ί����Ϣ�仯ʱ�ص�
	/// \param TEsOrderInfoNoticeField & rsp ί����Ϣ��ϸ����
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRtnOrderInfo(const TEsOrderInfoNoticeField& rsp)
	{
		this->esTradeApi->OnRtnOrderInfo(TypeConverter<OrderInfoNoticeField^, TEsOrderInfoNoticeField>::ToManagedType((TEsOrderInfoNoticeField *)&rsp));
	}

	////////////////////////////////////////
	/// \fn    OnRspMatchQry
	/// \brief  �ɽ���ѯӦ��
	/// \param TEsMatchDataQryRspField * rsp �ɽ���ѯ�������ѯ���ʱ��ָ��Ϊ��
	/// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
	/// \param const int iReqID ��Ӧ���������ID
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRspMatchQry(const TEsMatchDataQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspMatchQry(TypeConverter<MatchDataQryRspField^, TEsMatchDataQryRspField>::ToManagedType((TEsMatchDataQryRspField *)rsp), islast, errCode, iReqID);
	}

	////////////////////////////////////////
	/// \fn    OnRtnMatchState
	/// \brief �ɽ��仯����֪ͨ
	/// \param TEsMatchStateNoticeField & rsp �ɽ���ϸ����
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRtnMatchState(const TEsMatchStateNoticeField& rsp)
	{
		this->esTradeApi->OnRtnMatchState(TypeConverter<MatchStateNoticeField^, TEsMatchStateNoticeField>::ToManagedType((TEsMatchStateNoticeField *)&rsp));

	}

	////////////////////////////////////////
	/// \fn    OnRtnMatchInfo
	/// \brief �ɽ���Ϣ�仯����֪ͨ
	/// \param TEsMatchInfoNoticeField & rsp �ɽ���Ϣ��ϸ����
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRtnMatchInfo(const TEsMatchInfoNoticeField& rsp)
	{
		this->esTradeApi->OnRtnMatchInfo(TypeConverter<MatchInfoNoticeField^, TEsMatchInfoNoticeField>::ToManagedType((TEsMatchInfoNoticeField *)&rsp));

	}

	////////////////////////////////////////
	/// \fn    OnRspHistMatchQry
	/// \brief ��ʷ�ɽ���ѯӦ��
	/// \param TEsHisMatchQryRspField * rsp ��ʷ�ɽ���ѯ�������ѯ���ʱ��ָ��Ϊ��
	/// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
	/// \param const int iReqID ��Ӧ���������ID
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRspHistMatchQry(const TEsHisMatchQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspHistMatchQry(TypeConverter<HisMatchQryRspField^, TEsHisMatchQryRspField>::ToManagedType((TEsHisMatchQryRspField *)rsp), islast, errCode, iReqID);

	}

	////////////////////////////////////////
	/// \fn    OnQryHold
	/// \brief �ֲֲ�ѯӦ��
	/// \param TEsHoldQryRspField * rsp �ֲֲ�ѯ�������ѯ���ʱ��ָ��Ϊ��
	/// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
	/// \param const int iReqID ��Ӧ���������ID
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnQryHold(const TEsHoldQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID)
	{
		this->esTradeApi->OnQryHold(TypeConverter<HoldQryRspField^, TEsHoldQryRspField>::ToManagedType((TEsHoldQryRspField *)rsp), islast, errCode, iReqID);
	}


	////////////////////////////////////////
	/// \fn    OnRtnExchangeState
	/// \brief �г�״̬�������֪ͨ
	/// \param TEsExchangeQryRspField & rsp �г�״̬��ϸ��Ϣ
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRtnExchangeState(const TEsExchangeStateModifyNoticeField& rsp)
	{
		this->esTradeApi->OnRtnExchangeState(TypeConverter<ExchangeStateModifyNoticeField^, TEsExchangeStateModifyNoticeField>::ToManagedType((TEsExchangeStateModifyNoticeField *)&rsp));
	
	}


	////////////////////////////////////////
	/// \fn    OnQryCommodity
	/// \brief ��Ʒ��ѯӦ��
	/// \param TEsCommodityQryRspField * rsp ��Ʒ��ϸ��Ϣ����ѯ���ʱ��ָ��Ϊ��
	/// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
	/// \param const int iReqID ��Ӧ���������ID
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnQryCommodity(const TEsCommodityQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID)
	{
		this->esTradeApi->OnQryCommodity(TypeConverter<CommodityQryRspField^, TEsCommodityQryRspField>::ToManagedType((TEsCommodityQryRspField *)rsp), islast, errCode, iReqID);
	}



	////////////////////////////////////////
	/// \fn    OnRspQryCurrency
	/// \brief ��ѯ���ұ�����ϢӦ��
	/// \param const TEsCurrencyQryRspField * rsp
	/// \param int errCode
	/// \param const int iReqID
	/// \return void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRspQryCurrency(const TEsCurrencyQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspQryCurrency(TypeConverter<CurrencyQryRspField^, TEsCurrencyQryRspField>::ToManagedType((TEsCurrencyQryRspField *)rsp), islast, errCode, iReqID);
	}



	////////////////////////////////////////
	/// \fn    OnRtnOrderRemove
	/// \brief ί��ɾ��֪ͨ
	/// \param const TEsOrderRemoveNoticeField & rsp
	/// \return void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRtnOrderRemove(const TEsOrderRemoveNoticeField& rsp)
	{
		this->esTradeApi->OnRtnOrderRemove(TypeConverter<OrderRemoveNoticeField^, TEsOrderRemoveNoticeField>::ToManagedType((TEsOrderRemoveNoticeField *)&rsp));
	}





#pragma endregion
}
