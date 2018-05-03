#pragma once
using namespace System;
namespace EsForeignWrapper
{

	/// <summary>
	/// �Ƿ�CA��֤����
	/// </summary>
	public enum struct EnumIsCaLoginType
	{
		//CA��֤��ʽ
		CA_LOGIN = 'Y',
		//��CA��֤��ʽ
		NOT_CA_LOGIN = 'N'
	};

	/// <summary>
	/// �Ƿ�ǿ���޸���������
	/// </summary>
	public enum struct EnumIsForcePasswordType
	{
		//ǿ���޸�����
		FORCE_PWD = 'Y',
		//��ǿ���޸�����
		NOT_FORCE_PWD = 'N'
	};

	/// <summary>
	/// ��¼�������
	/// </summary>
	public enum struct EnumEsLoginIdentityType
	{
		//�µ��ͻ���
		IDENTITY_CLIENT = 'c',
		//�µ��˶�
		IDENTITY_TCLIENT = 'd',
		//�����˶�
		IDENTITY_BROKER = 'b',
		//����Ա��
		IDENTITY_TRADER = 't',
		//��̨�����
		IDENTITY_MANAGER = 'm'
	};

	/// <summary>
	/// �Ƿ��������
	/// </summary>
	public enum struct EnumIsPrimaryCurrencyType
	{
		//�ǻ���
		CURRENCY_PRIMARY_YES = 'Y',
		//���ǻ���
		CURRENCY_PRIMARY_NO = 'N'
	};

	/// <summary>
	/// �������־(ͬһ�����飬�ʽ���)
	/// </summary>
	public enum struct EnumCurrencyGroupFlagType
	{
		//������A
		CURRENCY_GROUP_A = 'A',
		//������B
		CURRENCY_GROUP_B = 'B',
		//������C
		CURRENCY_GROUP_C = 'C',
		//������D
		CURRENCY_GROUP_D = 'D',
		//������E
		CURRENCY_GROUP_E = 'E'
	};

	/// <summary>
	/// �г�״̬����
	/// </summary>
	public enum struct EnumExchangeStateType
	{
		//�г�������
		EXCHANGE_STATE_YES = 'Y',
		//�г���ֹ����
		EXCHANGE_STATE_NO = 'N',
		//�г�ֻ��ƽ��
		EXCHANGE_STATE_COVER = 'C'
	};

	/// <summary>
	/// ƽ�ַ�ʽ����
	/// </summary>
	public enum struct EnumCoverModeType
	{
		//�����ֿ�ƽ
		COVER_MODE_NONE = 'N',
		//ƽ��δ�˽�
		COVER_MODE_UNFINISHED = 'U',
		//���ֺ�ƽ��
		COVER_MODE_OPENCOVER = 'C',
		//���֡�ƽ�ֺ�ƽ��
		COVER_MODE_COVERTODAY = 'T'
	};

	/// <summary>
	/// ��Ʒ��������
	/// </summary>
	public enum struct EnumCommodityTypeType
	{
		//�ֻ�
		COMMODITY_TYPE_GOODS = 'G',
		//�ڻ�
		COMMODITY_TYPE_FUTURE = 'F',
		//��Ȩ
		COMMODITY_TYPE_OPTION = 'O',
		//��������
		COMMODITY_TYPE_SPREAD_MONTH = 'M',
		//��Ʒ������
		COMMODITY_TYPE_SPREAD_COMMODITY = 'C'
	};

	/// <summary>
	/// ��Ʒ״̬����
	/// </summary>
	public enum struct EnumCommodityStateType
	{
		//��Ʒ������
		COMMODITY_STATE_YES = 'Y',
		//��Ʒ��ֹ����
		COMMODITY_STATE_NO = 'N',
		//��Ʒֻ��ƽ��
		COMMODITY_STATE_COVER = 'C'
	};

	/// <summary>
	/// ���ʽ����
	/// </summary>
	public enum struct EnumDeliveryModeType
	{
		//ʵ�ｻ��
		DELIVERY_MODE_GOODS = 'G',
		//�ֽ𽻸�
		DELIVERY_MODE_CASH = 'C',
		//��Ȩ��Ȩ
		DELIVERY_MODE_EXECUTE = 'E'
	};

	/// <summary>
	/// �ֲּ��㷽ʽ
	/// </summary>
	public enum struct EnumDepositCalculateModeType
	{
		//����
		DEPOSIT_CALCULATE_MODE_NORMAL = 'N',
		//��Լ���ֲ�
		DEPOSIT_CALCULATE_MODE_CLEAN = 'C',
		//Ʒ������
		DEPOSIT_CALCULATE_MODE_LOCK = 'L'
	};

	/// <summary>
	/// ��Լ��������
	/// </summary>
	public enum struct EnumContractTypeType
	{
		//���Ⱥ�Լ
		CONTRACT_TYPE_SINGLE = '0',
		//��������
		CONTRACT_TYPE_SPREAD = '1',
		//��������
		CONTRACT_TYPE_SWAP = '2',
		//��Ʒ������
		CONTRACT_TYPE_COMMODITY = '3'
	};
	/// <summary>
	/// ��Լ״̬����
	/// </summary>
	public enum struct EnumContractStateType
	{
		//��Լ������
		CONTRACT_STATE_YES = 'Y',
		//��Լ��ֹ����
		CONTRACT_STATE_NO = 'N',
		//��Լֻ��ƽ��
		CONTRACT_STATE_COVER = 'C'
	};
	/// <summary>
	/// �ͻ�״̬
	/// </summary>
	public enum struct EnumClientStateType
	{
		//����
		CLIENT_STATE_NORMAL = 'N',
		//����
		CLIENT_STATE_CANCEL = 'C'
	};
	/// <summary>
	/// �ͻ���������
	/// </summary>
	public enum struct EnumClientTypeType
	{
		//���˿ͻ�
		CLIENT_TYPE_PERSON = 'P',
		//�����ͻ�
		CLIENT_TYPE_ORGANIZATION = 'O'
	};
	/// <summary>
	/// �ͻ�����״̬����
	/// </summary>
	public enum struct EnumClientTradeStateType
	{
		//��������
		CLIENT_TRADE_YES = 'Y',
		//��ֹ��¼
		CLIENT_TRADE_NO = 'N',
		//ֻ�ɲ�ѯ
		CLIENT_TRADE_QUERY = 'Q',
		//ֻ��ƽ��
		CLIENT_TRADE_COVER = 'C',
		//����
		CLIENT_TRADE_FROZEN = 'F'
	};
	/// <summary>
	/// �ͻ�����״̬����
	/// </summary>
	public enum struct EnumClientQuoteStateType
	{
		//������¼
		CLIENT_QUOTE_YES = 'Y',
		//��ֹ��¼
		CLIENT_QUOTE_NO = 'N'
	};
	/// <summary>
	/// ����Ա״̬����
	/// </summary>
	public enum struct EnumOperatorStateType
	{
		//��������
		OPERATOR_TRADE_YES = 'Y',
		//��ֹ��¼
		OPERATOR_TRADE_NO = 'N',
		//ֻ�ɵ�¼��ѯ
		OPERATOR_TRADE_QUERY = 'Q',
		//ֻ��ƽ��
		OPERATOR_TRADE_COVER = 'C'
	};

	/// <summary>
	/// ����Ա��¼��ʽ
	/// </summary>
	public enum struct EnumOperatorLoginType
	{
		//�ܹ���¼�ͻ�ǰ��
		OPERATOR_LOGIN_EVERY_FRONT = 'Y',
		//���ܵ�¼�ͻ�ǰ��
		OPERATOR_LOGIN_NOT_EVERY_FRONT = 'N'
	};

	/// <summary>
	/// �ͻ�����������
	/// </summary>
	public enum struct EnumGroupTypeType
	{
		//���׷���(һ���ͻ����Է��䵽�������)
		GROUP_TYPE_TRADE = 'T',
		//�������(һ���ͻ�ֻ���Է��䵽һ���������)
		GROUP_TYPE_SETTLE = 'S',
		//�����Ѳ�����(һ���ͻ�ֻ���Է��䵽һ����������)
		GROUP_TYPE_FEERENT = 'F',
		//��֤�������(һ���ͻ�ֻ���Է��䵽һ����֤����)
		GROUP_TYPE_DEPOSITRENT = 'D',
		//�ʽ�����(һ���ͻ�ֻ���Է��䵽һ���ʽ�����,ͬһ�ʽ�����Ŀͻ������ܹ�����ռ���ʽ�)
		GROUP_TYPE_MONEY = 'M'
	};

	/// <summary>
	/// ��������
	/// </summary>
	public enum struct EnumPasswordTypeType
	{
		//��������
		PASSWORD_TYPE_TRADE = 'T',
		//��������
		PASSWORD_TYPE_QUOTE = 'Q',
		//��֤����
		PASSWORD_TYPE_AUTH = 'A'
	};

	/// <summary>
	/// ί������
	/// </summary>
	public enum struct EnumOrderType
	{
		//�޼�
		ORDER_TYPE_LIMIT = '1',
		//�м�
		ORDER_TYPE_MARKET = '2',
		//�޼�ֹ��
		ORDER_TYPE_STOP_LIMIT = '3',
		//�м�ֹ��
		ORDER_TYPE_STOP_MARKET = '4'
	};
	/// <summary>
	/// ί�з�ʽ
	/// </summary>
	public enum struct EnumOrderWayType
	{
		//�������ӵ�
		ORDER_WAY_SELF_ETRADER = 'E',
		//������ӵ�
		ORDER_WAY_PROXY_ETRADER = 'P',
		//�ⲿ���ӵ�(�ⲿ����ϵͳ�µ�����ϵͳ¼��)
		ORDER_WAY_JTRADER = 'J',
		//�˹�¼�뵥(�ⲿ������ʽ�µ�����ϵͳ¼��)
		ORDER_WAY_MANUAL = 'M',
		//carry��
		ORDER_WAY_CARRY = 'C',
		//��ʽ������
		ORDER_WAY_PROGRAM = 'S'
	};

	/// <summary>
	/// ί��ģʽ����
	/// </summary>
	public enum struct EnumOrderModeType
	{
		//FOK
		ORDER_MODE_FOK = '1',
		//FAK��IOC
		ORDER_MODE_FAK = '2',
		//������Ч
		ORDER_MODE_GFD = '3',
		//ȡ��ǰ��Ч
		ORDER_MODE_GTC = '4',
		//ָ������ǰ��Ч
		ORDER_MODE_GTD = '5'
	};
	/// <summary>
	/// �ɽ���ʽ
	/// </summary>
	public enum struct EnumMatchWayType
	{
		//����
		MATCH_WAY_ALL = 'A',
		//�������ӵ�
		MATCH_WAY_SELF_ETRADER = 'E',
		//������ӵ�
		MATCH_WAY_PROXY_ETRADER = 'P',
		//�ⲿ���ӵ�(�ⲿ����ϵͳ�µ�����ϵͳ¼��)
		MATCH_WAY_JTRADER = 'J',
		//�˹�¼�뵥(�ⲿ������ʽ�µ�����ϵͳ¼��)
		MATCH_WAY_MANUAL = 'M',
		//carry��
		MATCH_WAY_CARRY = 'C',
		//���
		MATCH_WAY_DELIVERY = 'D',
		//��ʽ����
		MATCH_WAY_PROGRAM = 'S'
	};
	/// <summary>
	/// �Ƿ���ձ���
	/// </summary>
	public enum struct EnumIsRiskOrderType
	{
		//�Ƿ��ձ���
		RISK_ORDER_YES = 'Y',
		//���Ƿ��ձ���
		RISK_ORDER_NO = 'N'
	};
	/// <summary>
	/// ��������
	/// </summary>
	public enum struct EnumDirectType
	{
		//����
		DIRECT_BUY = 'B',
		//����
		DIRECT_SELL = 'S'
	};
	/// <summary>
	/// ��ƽ����
	/// </summary>
	public enum struct EnumOffsetType
	{
		//��
		OFFSET_NONE = 'N',
		//����
		OFFSET_OPEN = 'O',
		//ƽ��
		OFFSET_COVER = 'C',
		//ƽ��
		OFFSET_COVER_TODAY = 'T'
	};
	/// <summary>
	/// Ͷ����ֵ����
	/// </summary>
	public enum struct EnumHedgeType
	{
		//��
		HEDGE_NONE = 'N',
		//Ͷ��
		HEDGE_T = 'T',
		//��ֵ
		HEDGE_B = 'B'

	};
	/// <summary>
	/// ί��¼������
	/// </summary>
	public enum struct EnumOrderInputType
	{
		//��
		ORDER_INPUT_YES = 'Y',
		//��
		ORDER_INPUT_NO = 'N'
	};
	/// <summary>
	/// T+1�ɽ�
	/// </summary>
	public enum struct EnumAddOneType
	{
		//T+1�ɽ�
		ADD_ONE_YES = 'Y',
		//��T+1�ɽ�
		ADD_ONE_NO = 'N'

	};
	/// <summary>
	/// �˹���д������
	/// </summary>
	public enum struct EnumManualFeeType
	{    //�˹�
		MANUALFEE_YES = 'Y',
		//�Զ�
		MANUALFEE_NO = 'N'

	};
	/// <summary>
	/// ί��״̬����
	/// </summary>
	public enum struct EnumOrderStateType
	{//ָ��ʧ��
		ORDER_STATE_FAIL = '0',
		//������
		ORDER_STATE_ACCEPT = '1',
		//�ѹ���
		ORDER_STATE_SUPPENDED = '2',
		//���Ŷ�
		ORDER_STATE_QUEUED = '3',
		//������(�Ŷ���ʱ״̬)
		ORDER_STATE_DELETEING = '4',
		//���޸�(�Ŷ���ʱ״̬)
		ORDER_STATE_MODIFYING = '5',
		//���ֳ���
		ORDER_STATE_PARTDELETED = '6',
		//��ȫ����
		ORDER_STATE_DELETED = '7',
		//���ֳɽ�
		ORDER_STATE_PARTFINISHED = '8',
		//��ȫ�ɽ�
		ORDER_STATE_FINISHED = '9'
	};
	/// <summary>
	/// �ɽ���ʽ����
	/// </summary>
	public enum struct EnumMatchModeType
	{    //����
		MATCH_MODE_NORMAL = 'N',
		//����ί��
		MATCH_MODE_UPDATE = 'U',
		//����
		MATCH_MODE_OTHER = 'O'
	};
	/// <summary>
	/// �����ʺ���������
	/// </summary>
	public enum struct EnumTradeNoTypeType
	{
		//��������
		TRADENO_NORMAL = 'N',
		//Ͷ��
		TRADENO_TOUJI = 'T',
		//��ֵ
		TRADENO_BAOZHI = 'B',
		//����
		TRADENO_SPREAD = 'S'
	};
	/// <summary>
	/// ���������
	/// </summary>
	public enum struct EnumCashTypeType
	{    //����
		CASH_TYPE_OUT = 'O',
		//���
		CASH_TYPE_IN = 'I'
	};

	/// <summary>
	/// �����״̬
	/// </summary>
	public enum struct EnumCashStateType
	{ //δ���
		CASH_STATE_NOT_CHECK = 'N',
		//�����
		CASH_STATE_CHECK = 'Y',
		//���δͨ��
		CASH_STATE_FAIL = 'F'
	};


	/// <summary>
	/// �����ʽ
	/// </summary>
	public enum struct EnumCashModeType
	{    //ת��
		CASH_MODE_A = 'A',
		//֧Ʊ
		CASH_MODE_B = 'B',
		//�ֽ�
		CASH_MODE_C = 'C',
		//����
		CASH_MODE_E = 'E'
	};


	/// <summary>
	/// �Ƿ�ǿ�Ƴ�����
	/// </summary>
	public enum struct EnumForceCashOutFlagType
	{	//ǿ�Ƴ����ʽ���ʱ���������
		FORCE_CASH_OUT_YES = 'Y',
		//��ǿ�Ƴ���,�ʽ���ʱ�����������
		FORCE_CASH_OUT_NO = 'N'

	};


	/// <summary>
	/// �ʽ����״̬
	/// </summary>
	public enum struct EnumAdjustStateType
	{    //δ���
		ADJUST_STATE_NOT_CHECK = 'N',
		//�����
		ADJUST_STATE_CHECK = 'Y',
		//���δͨ��
		ADJUST_STATE_FAIL = 'F'
	};


	/// <summary>
	/// �ʽ�仯�ֶ�����(�ӵ�λ����λ,ÿλ��Ӧһ���仯�ֶ�)
	/// </summary>
	public enum struct EnumTMoneyChgType
	{
		//�ʽ����                                                                 
		MONEY_CHG_ADJUST = 0x00000001,
		//���                                                                     
		MONEY_CHG_CASHIN = 0x00000002,
		//����                                                                     
		MONEY_CHG_CASHOUT = 0x00000004,
		//������                                                                   
		MONEY_CHG_FEE = 0x00000008,
		//�����ʽ�                                                                 
		MONEY_CHG_FROZEN = 0x00000010,
		//���ƽӯ                                                                 
		MONEY_CHG_COVERPROFIT = 0x00000020,
		//����ƽӯ                                                                 
		MONEY_CHG_DAYCVERPROFIT = 0x00000040,
		//��ʸ�ӯ                                                                 
		MONEY_CHG_FLOATPROFIT = 0x00000080,
		//���и�ӯ                                                                 
		MONEY_CHG_DAYFLOATPROFIT = 0x00000100,
		//δ��ƽӯ                                                                 
		MONEY_CHG_UNEXPIREDPROFIT = 0x00000200,
		//Ȩ����                                                                   
		MONEY_CHG_PREMIUM = 0x00000400,
		//��֤��                                                                   
		MONEY_CHG_DEPOSIT = 0x00000800,
		//ά�ֱ�֤��                                                               
		MONEY_CHG_KEEPDEPOSIT = 0x00001000,
		//��Ѻ�ʽ�                                                                 
		MONEY_CHG_PLEDGE = 0x00002000,
		//�����ʽ�                                                                 
		MONEY_CHG_TAVAILABLE = 0x00004000,
		//���ֽ��
		MONEY_CHG_Discount = 0x00008000,
		//����������
		MONEY_CHG_TradeFee = 0x00010000,
		//����������
		MONEY_CHG_DeliveryFee = 0x00020000,
		//���������
		MONEY_CHG_ExchangeFee = 0x00040000,
		//���ᱣ֤��
		MONEY_CHG_FrozenDeposit = 0x00080000,
		//����������
		MONEY_CHG_FrozenFee = 0x00100000,
		//��ӯ(��LME)
		MONEY_CHG_NewFloatProfit = 0x00200000,
		//LME��ӯ
		MONEY_CHG_LmeFloatProfit = 0x00400000,
		//��Ȩ��ֵ
		MONEY_CHG_OptionMarketValue = 0x00800000,
		//����ԭʼ�����
		MONEY_CHG_OriCash = 0x01000000,
		//���ʽ�        
		MONEY_CHG_TMoney = 0x02000000,
		//��Ȩ��
		MONEY_CHG_TBalance = 0x04000000,
		//�����
		MONEY_CHG_TCanCashOut = 0x08000000,
		//������
		MONEY_CHG_RiskRate = 0x10000000,
		//�˻���ֵ
		MONEY_CHG_AccountMarketValue = 0x20000000
	};


	/// <summary>
	/// ��Ϣ����������
	/// </summary>
	public enum struct EnumMessageReceiverType
	{    //ָ���ͻ�
		MESSAGE_RECEIVER_CLIENT = 'C',
		//ָ���ͻ���
		MESSAGE_RECEIVER_GROUP = 'G',
		//���пͻ�
		MESSAGE_RECEIVER_ALL = 'A'
	};


	/// <summary>
	/// ��֤����㷽ʽ
	/// </summary>
	public enum struct EnumDepositModeType
	{    //����
		DEPOSIT_MODE_B = '1',
		//����
		DEPOSIT_MODE_D = '2',
		//��ֵ����
		DEPOSIT_MODE_CB = '3',
		//��ֵ����
		DEPOSIT_MODE_CD = '4',
		//�ۿ�
		DEPOSIT_MODE_Z = '5'

	};



	/// <summary>
	/// ��־��������
	/// </summary>
	public enum struct EnumLogTypeType
	{
		//��¼��־
		LOGTYPE_LOGIN = '1'
	};


	/// <summary>
	/// ί�гɽ�ɾ�����
	/// </summary>
	public enum struct EnumDeletedType
	{
		//��
		DEL_YES = 'Y',
		//��
		DEL_NO = 'N',
		//����
		DEL_DISAPPEAR = 'D'
	};

	/// <summary>
	/// �Ƿ�����ϼ�ֵ
	/// </summary>
	public enum struct EnumContainTotleType
	{
		//����
		ContainTotle_Yes = 'Y',
		//������
		ContainTotle_No = 'N'
	};

	/// <summary>
	/// ����ұ�ʶ
	/// </summary>
	public enum struct EnumLWFlagType
	{    //����������˻�
		LWFlag_L = 'L',
		//�ͻ���������˻�
		LWFlag_W = 'W',
		//��˾��������˻�
		LJFFlag_J = 'J',
		//��˾��������˻�
		LJFFlag_F = 'F'
	};

	/// <summary>
	/// ����¼���������
	/// </summary>
	public enum struct EnumEventTypeType
	{	//�����¼�
		EVENT_TYPE_Y = 'Y',
		//�ǳ����¼�
		EVENT_TYPE_N = 'N'

	};

	/// <summary>
	/// ����¼��ȼ�����
	/// </summary>
	public enum struct EnumEventLevelType
	{	//����
		EVENT_TYPE_NORMAL = 'N',
		//����
		EVENT_TYPE_WARNNING = 'W',
		//����
		EVENT_TYPE_ERROR = 'E'
	};

	/// <summary>
	/// �۽���������������
	/// </summary>
	public enum struct EnumHKMarketOperType
	{
		MarketOper_None = '\0',
		//�µ�
		MarketOper_Insert = 'I',
		//�ĵ�
		MarketOper_Modify = 'M',
		//����
		MarketOper_Delete = 'D'
	};
}
