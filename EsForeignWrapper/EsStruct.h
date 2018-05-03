#pragma once
#include "Enums.h"
using namespace System;
using namespace System::Runtime::InteropServices;


namespace EsForeignWrapper
{
	//��ʱ���ݽṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	 public ref struct StkData
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 40)]
		String^ Market;        //�г�������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 66)]
		String^ Code;         //��Լ����

		float	YClose;			//������
		float	YSettle;		//�����
		float	Open;			//���̼�
		float	High;			//��߼�
		float	Low;			//��ͼ�
		float	New;			//���¼�
		float	NetChg;			//�ǵ�
		float	Markup;			//�ǵ���
		float	Swing;			//���
		float	Settle;			//�����
		float	Volume;			//�ɽ���
		float	Amount;			//�ֲ���

		[MarshalAs(UnmanagedType::ByValArray, SizeConst = 10, ArraySubType = UnmanagedType::R4)]
		array<float>^	Ask;			//������
		[MarshalAs(UnmanagedType::ByValArray, SizeConst = 10, ArraySubType = UnmanagedType::R4)]
		array<float>^	AskVol;		   //������
		[MarshalAs(UnmanagedType::ByValArray, SizeConst = 10, ArraySubType = UnmanagedType::R4)]
		array<float>^	Bid;		  //�����
		[MarshalAs(UnmanagedType::ByValArray, SizeConst = 10, ArraySubType = UnmanagedType::R4)]
		array<float>^	BidVol;		  //������			

		float	AvgPrice;		//ƽ����

		float   LimitUp;		//��ͣ��
		float   LimitDown;		//��ͣ��
		float   HistoryHigh;	//��Լ���
		float   HistoryLow;		//��Լ���

		float	YOPI;			//��ֲ�
		float   ZXSD;			//����ʵ��
		float   JXSD;			//����ʵ��
		float   CJJE;			//�ɽ����

		//��������
		float TClose;			//���̼�
		float Lastvol;			//���³ɽ���
		float status;			//��Լ����״̬ -1:δ֪ 0:���� 1:�޺��� 2:���� 3:���� 4:���� 5:����ǰ 6:����ǰ 7:����
		float updatetime;			//����ʱ��,���磺235959��ʾ23��59��59

		float		BestBPrice;					//�������
		float		BestBVol;					//��������
		float		BestSPrice;					//��������
		float		BestSVol;					//��������	
	};

	//��ʷ����
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct HistoryData 
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 20)]
		String^	time;	          //ʱ��,���磺2009-06-01 08:00:00
		float	fOpen;		      //����
		float	fHigh;		      //���
		float	fLow;			  //���
		float	fClose;		      //����
		float	fVolume;		  //�ɽ���(��)
		float	fAmount;		  //�ɽ���(Ԫ)
	};


	//Ʒ����ʷ����
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct StkHisData	  
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 40)]
		String^			Market;	     //�г�������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 66)]
		String^			Code;	    //Ʒ�ִ���
		short			nPeriod;	//����
		short			nCount;		//��ʷ������Ŀ
		[MarshalAs(UnmanagedType::ByValArray, SizeConst = 1)]
		array<HistoryData^>^	HisData;
	};


	//�ɽ���ϸ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	 public ref struct StockTraceData 
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 20)]
		String^	time;	       //ʱ��,���磺2009-06-01 08:00:00
		float	m_NewPrice;		//���¼�
		float	m_Volume;		//����
		float	m_Amount;		//�ֲ�
		float	m_BuyPrice;		//ί���
		float	m_SellPrice;	//ί����
		float	m_BuyVol;		//������
		float	m_SellVol;		//������
	};


	//Ʒ����ϸ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	 public ref struct StkTraceData 
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 40)]
		String^			Market;	//�г�������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 66)]
		String^			Code;	//Ʒ�ִ���
		unsigned short	nCount;		//��¼��Ŀ
		[MarshalAs(UnmanagedType::ByValArray, SizeConst = 1)]
		array<StockTraceData^>^	TraceData;
	};


	//��Լ��Ϣ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct WStockInfo
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 66)]
		String^    szCode;     //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 128)]
		String^	szName;  //��������
		unsigned char	Precision;    //���ȣ�С����λ��	
	};


	//�����г��ĺ�Լ��Ϣ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	 public ref struct WMarketInfo
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 40)]
		String^			Market;	//�г�������
		unsigned short stocknum;//��Լ��Ŀ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 1)]
		array<WStockInfo^>^	stockdata;//��Լ��Ϣ����
	};


	
	//����IP���ӵĵ�ַ��Ϣ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	 public ref struct AddressField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^					Ip;             //IP��ַ
		UInt16		    Port;           //�˿ں�
	};



	//��¼����ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	 public ref struct LoginReqField
	{
		Byte		IsCaLogin;              //�Ƿ�CA��֤
		Byte		Identity;               //��¼�������,Ŀǰֻ֧�ֵ��ͻ�
		Byte		IsForcePwd;             //�Ƿ�ǿ���޸�����
			
																	
		////union
		////{
		////	TClientNoType				ClientNo;			//�ͻ���,����ͻ���
		////	TOperatorNoType				OperatorNo;			//����Ա��,�������Ա��
		////};
		////�����йܲ�����Union,ʹ��һ�����ֽڴ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ ClientNo;

		/// ��Ӧ��ʹ�õĵ�¼�˺ŵ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^			LoginPwd;				//��¼����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]	/// ǿ���޸�����ʱ��������
		String^			NewPwd;					//ǿ���޸������¼ʱ,���޸�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				OtpPass;                //otp��֤����
		int                 CaLen;                  //CA��Ϣ���ȣ�IsCaLoginΪ'Y'ʱ�����ֶ���Ч
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 1)]
		String^					CaInfo;					//CA��¼ʱ��д,IsCaLoginΪ'Y'ʱ�����ֶ���Ч
	};



	//��¼Ӧ��ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct LoginRspField
	{
		EnumIsCaLoginType				IsCaLogin;              //�Ƿ�CA��֤
		EnumIsForcePasswordType		IsForcePwd;             //�Ƿ�ǿ���޸�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				LoginNo;				//��¼��    
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				LoginName;				//��¼���ʺż��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^			ReservedInfo;			//�ͻ�Ԥ����Ϣ,�ͻ��Լ�ʶ���̨ϵͳ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				LastLoginDateTime;		//�ϴε�¼ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				LastLogoutDateTime;		//�ϴεǳ�ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^						LastLoginIp;			//�ϴε�¼ip
		short					LastLoginPort;			//�ϴε�¼port
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 201)]
		String^			LastLoginMachineInfo;	//�ϴε�¼������Ϣ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ServerDateTime;			//ϵͳ��ǰʱ��(�ͻ���Уʱ)
	};

	//��������ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct OrderInsertReqField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^			    CommodityNo;            //��Ʒ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				ContractNo;             //��Լ����
		Byte				OrderType;				//ί������
		Byte				OrderWay;				//ί�з�ʽ,���ͻ����ù�ע���ֶ�
		Byte				OrderMode;				//ί��ģʽ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ValidDateTime;			//��Ч����(GTD�����ʹ��)
		Byte			    IsRiskOrder;			//���ձ���
		Byte				Direct;					//��������
		Byte				Offset;					//����ƽ��
		Byte				Hedge;					//Ͷ����ֵ
		double				OrderPrice;				//ί�м۸�
		double				TriggerPrice;			//�����۸�
		int				    OrderVol;				//ί������
		int				    MinMatchVol;			//��С�ɽ���

		Byte					Randomise;						//��ɽ���Ƿ���������� 2012-11-2
		int				MinClipSize;					//��ɽ����С�����
		int				MaxClipSize;					//��ɽ����������

		int			        SaveInt;                //�ͻ������ֶ�1
		double		        SaveDouble;             //�ͻ������ֶ�2
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^		        SaveString;             //�ͻ������ֶ�3
	};

	//����Ӧ��ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct OrderInsertRspField
	{
		UInt16				OrderStreamId;					//ί������
		int				OrderId;						//ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 22)]
		String^				LocalNo;						//���غ�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				TradeNo;						//�ͻ������ʺ�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				InsertNo;						//�µ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				InsertDateTime;					//�µ�ʱ��
		Byte				OrderState;						//ί��״̬
		OrderInsertReqField^      ReqData;                        //������������
	};

	//ί��״̬���֪ͨ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct OrderStateNoticeField
	{
		Byte				    OrderType;						//ί������
		Byte					Offset;							//��ƽ����
		Byte					Hedge;							//Ͷ����ֵ����

		double				    OrderPrice;				        //ί�м�
		double				    TriggerPrice;                   //������
		int				        OrderVol;						//ί������

		unsigned int			OrderStreamId;                  //ί������,ÿ��״̬֪ͨΨһ
		int				        OrderId;                        //ί��ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 22)]
		String^				    LocalNo;                        //���غ�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				    SystemNo;                       //ϵͳ��

		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				    UpdateNo;		                //����Ա���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				    UpdateDateTime;					//����ʱ��
		Byte				    OrderState;                     //ί��״̬
		double				    MatchPrice;                     //�ɽ�����
		int				        MatchVol;                       //�ɽ�����
		int				        ErrorCode;                      //��������ʱ��Ӧ������

		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 22)]
		String^				    ActionLocalNo;                  //���������ı��غ�

		OrderInsertReqField^    ReqData;                        //������������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				    ExchangeSystemNo;				//������ϵͳ��

		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^				    ErrorText;						//ԭʼ������Ϣ.2015-09-15����
	};

	//ί����Ϣ���֪ͨ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct OrderInfoNoticeField
	{
		OrderInsertReqField^	ReqData;                            //��������������

		unsigned int					OrderStreamId;                  //ί������
		int				OrderId;                        //ί��ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 22)]
		String^				LocalNo;                        //���غ�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				SystemNo;                       //ϵͳ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				ExchangeSystemNo;				//������ϵͳ��   
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				TradeNo;                        //�����˺�

		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				InsertNo;                       //¼�����Ա��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				InsertDateTime;                 //¼��ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				UpdateNo;						//���һ�α����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				UpdateDateTime;					//���һ�α��ʱ��
		Byte				OrderState;                     //ί��״̬
		double				MatchPrice;                     //�ɽ��۸�
		int				MatchVol;                       //�ɽ�����
		int				ErrorCode;						//���һ�β���������Ϣ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^				ErrorText;						//ԭʼ������Ϣ.2015-09-15����

		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 22)]
		String^				ActionLocalNo;                  //���������ı��غ�
		Byte				OrderInput;						//�Ƿ�¼��
		Byte				Deleted;                        //�Ƿ�ɾ��
		Byte					AddOne;							//T+1��־
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				ParentSystemNo;
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				UpperNo;//���ֺš�
	};

	//��������ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct OrderDeleteReqField
	{
		int				OrderId;                        //ί��ID
	};


	//����Ӧ��ṹ
	//typedef TEsOrderStateNoticeField TEsOrderDeleteRspField;
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct  OrderDeleteRspField
	{
		OrderStateNoticeField^    OrderStateField;
		OrderInsertReqField^      ReqData;                        //������������
	};



	////�ĵ�����ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsOrderModifyReqField
	//{
	//	TOrderIdType				OrderId;                        //ί��ID
	//	TTradePriceType				OrderPrice;				        //ί�м۸�
	//	TTradePriceType				TriggerPrice;                   //�����۸�
	//	TTradeVolType				OrderVol;	                    //ί������
	//};

	//�ĵ�Ӧ��ṹ
	//typedef TEsOrderStateNoticeField TEsOrderModifyRspField;
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct OrderModifyRspField
	{
		OrderStateNoticeField^    OrderStateField;
		OrderInsertReqField^      ReqData;                        //������������
	};

	//�ɽ�״̬֪ͨ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct MatchStateNoticeField
	{
		unsigned int				MatchStreamId;              //�ɽ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;                   //�ͻ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				SystemNo;                   //ϵͳ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				MatchNo;                    //�ɽ���
		Byte				MatchMode;                  //�ɽ�ģʽ
		Byte				MatchWay;                   //�ɽ���ʽʽ
		double				MatchPrice;                 //�ɽ���
		int				MatchVol;                   //�ɽ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				MatchDateTime;              //�ɽ�ʱ��
		double				MatchFee;                   //�ɽ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				CurrencyNo;					//�����ѱ���
		Byte					AddOne;						//T+1���
		Byte				ManualFee;					//�ֹ�������
		Byte				Deleted;                    //ɾ����־
		int				OrderId;                    //ί��ID
		int				MatchId;                    //�ɽ�ID
		double				CoverPrice;                 //ƽ�ּ۸�
	};

	//�ɽ���Ϣ֪ͨ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct MatchInfoNoticeField
	{
		
		MatchStateNoticeField^    StateData;                  //�ɽ�״̬
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^			CommodityNo;				//��Ʒ��������Ҫ

		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				ContractNo;					//����������Ҫ
		Byte					Direct;						//����������Ҫ
		Byte					Offset;						//����������Ҫ
	};

	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct OrderQryReqField
	{
		int				OrderStreamId;					//��ѯ�������ش��ڴ����ŵ�ί������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;                       //�ͻ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				ExchangeNo;                     //������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^			CommodityNo;                    //��Ʒ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				ContractNo;                     //��Լ
		Byte				OrderType;						//ί������
		Byte				OrderMode;						//ί��ģʽ
		Byte			IsRiskOrder;					//���ձ���
		Byte					Hedge;							//Ͷ����ֵ
		int				OrderId;                        //ί��ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 22)]
		String^				LocalNo;                        //���غ�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				SystemNo;                       //ϵͳ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				OperNo;							//�µ��˻�����˺�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				BeginInsertDateTime;            //��ʼʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				EndInsertDateTime;              //����ʱ��
		Byte				OrderState;                     //ί��״̬
	};
	
	
	//ί������Ӧ������
	typedef OrderInfoNoticeField OrderDataQryRspField;

	//�ɽ���ѯ��������
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct MatchQryReqField
	{
		int				MatchStreamId;              //�ɽ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;                   //�ͻ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				SystemNo;                   //ϵͳ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^				MatchNo;                    //�ɽ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				BeginMatchDateTime;         //��ʼʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				EndMatchDateTime;           //����ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				ExchangeNo;                 //������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^			CommodityNo;				//��Ʒ��������Ҫ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				ContractNo;					//����������Ҫ
	};

	//�ɽ�����Ӧ������
	typedef MatchInfoNoticeField MatchDataQryRspField;

	//�ʽ��ѯ����ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct MoneyQryReqField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;                   //�ͻ���
	};

	//�ʽ��ѯӦ��ṹ(ע��νṹ���ʽ�仯֪ͨ�ṹ�Ĺ�ϵ)
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct MoneyQryRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;                   //�ͻ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				CurrencyNo;                 //���ұ��
		double				YAvailable;					//�����
		double				YCanCashOut;				//�����
		double				YMoney;						//������
		double				YBalance;					//��Ȩ��
		double				YUnExpiredProfit;			//��δ��ƽӯ
		double				Adjust;						//�ʽ����0
		double				CashIn;						//���1
		double				CashOut;					//����2
		double				Fee;						//������3
		double				Frozen;						//�����ʽ�4
		double				CoverProfit;				//���ƽӯ5
		double				DayCoverProfit;				//����ƽӯ6
		double				FloatProfit;				//��ʸ�ӯ7
		double				DayFloatProfit;				//���и�ӯ8
		double				UnExpiredProfit;			//δ��ƽӯ9
		double				Premium;					//Ȩ����10
		double				Deposit;					//��֤��11
		double				KeepDeposit;				//ά�ֱ�֤��12
		double				Pledge;						//��Ѻ�ʽ�13
		double				TAvailable;					//�����ʽ�14
		double				Discount;					//���ֽ��15
		double				TradeFee;					//����������16
		double				DeliveryFee;				//����������17
		double				ExchangeFee;				//���������18
		double				FrozenDeposit;				//���ᱣ֤��19
		double				FrozenFee;					//����������20
		double				NewFloatProfit;				//��ӯ(��LME)21
		double				LmeFloatProfit;				//LME��ӯ22
		double				OptionMarketValue;			//��Ȩ��ֵ23
		double				OriCash;					//����ԭʼ�����24(���Զ�����ʽ�)
		double              TMoney;                     //���ʽ�
		double		        TBalance;					//��Ȩ��
		double		        TCanCashOut;				//�����
		double		        RiskRate;					//������
		double		        AccountMarketValue;			//�˻���ֵ
	};
	////�ʽ�仯֪ͨ�ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TMoneyChgItem
	//{
	//	TMoneyChgType				MoneyChg;
	//	TMoneyValueType				MoneyValue;
	//};

	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsMoneyChgNoticeField
	//{
	//	TClientNoType				ClientNo;                   //�ͻ���
	//	TCurrencyNoType				CurrencyNo;                 //���ұ��
	//	u_short						MoneyChgNum;                //�ʽ�仯��ĸ���
	//	TMoneyChgItem				MoneyItem[1];				//�ʽ�仯����
	//};

	//�ֲֲ�ѯ����ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct HoldQryReqField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;                   //�ͻ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				ExchangeNo;                 //������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				CommodityNo;                //��Ʒ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				ContractNo;                 //��Լ
	};
	//�ֲֲ�ѯӦ��ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct HoldQryRspField
	{
		int				HoldKeyId;                  //�ֲֹؼ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;                   //�ͻ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^			CommodityNo;                //��Ʒ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				ContractNo;                 //��Լ
		Byte					Direct;                     //��������
		Byte					Hedge;                      //Ͷ����ֵ
		double				TradePrice;                 //�ֲ־���
		int				TradeVol;                   //�ֲ���
		double				YSettlePrice;               //������
		double				TNewPrice;                  //���¼�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				MatchDateTime;              //�ɽ�ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				MatchNo;                    //�ɽ���
		double				Deposit;                    //��֤��
		double				KeepDeposit;                //ά�ֱ�֤��
	};

	//��Ʒ��ѯ����ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct CommodityQryReqField
	{
	};
	//��Ʒ��ѯӦ��ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct CommodityQryRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				ExchangeNo;				//������
		Byte				CommodityType;			//��Ʒ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				CommodityNo;			//��Ʒ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				RelateCommodityNo;		//������Լ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				CommodityName;          //��Ʒ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				CommodityAttribute;     //��Ʒ����
		Byte				CommodityState;         //��Ʒ״̬
		double				ProductDot;             //ÿ�ֳ���
		double				UpperTick;              //��С�䶯�۷���
		int					LowerTick;              //��С�䶯�۷�ĸ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				CurrencyNo;				//��Ʒʹ�ñ���
		Byte				DeliveryMode;			//���ʽ
		int					DeliveryDays;           //������ƫ��
		Byte				DepositCalculateMode;	//��֤����㷽ʽ
		int					MaxSingleOrderVol;		//��������µ���
		int					MaxHoldVol;				//���ֲ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				AddOneTime;				//T+1ʱ��,���ڴ�ʱ��ΪT+1����
		Byte				CmbDirect;				//�����������(��һ��)
		Byte				CoverMode;              //ƽ�ַ�ʽ
	};

	////��Ʒ״̬�仯֪ͨ�ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsCommodityStateModNoticeField
	//{
	//	TCommodityNoType			CommodityNo;					//�ϱ������ֶ�Ϊ��Ʒ�ؼ���
	//	TCommodityStateType			CommodityState;
	//	TTradeVolType				MaxSingleOrderVol;				//��������µ���
	//	TTradeVolType				MaxHoldVol;						//���ֲ���
	//};

	////��Լ��ѯ����ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsContractQryReqField
	//{
	//	TCommodityNoType			CommodityNo;            //��Ʒ
	//	TContractLastDays			LastDays;		        //�ٽ�������

	//};

	//��Լ��ѯӦ��ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct ContractQryRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^			CommodityNo;			//��Ʒ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				ContractNo;				//��Լ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^			ContractName;			//��Լ����
		Byte			ContractType;			//��Լ����
		Byte			ContractState;			//��Լ״̬
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^					ExpiryDate;				//������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^						LastTradeDate;			//�������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^						FirstNoticeDate;		//�״�֪ͨ��
	};

	////��Լ����֪ͨ�ṹ
	//typedef TEsContractQryRspField	TEsContractAddNoticeField;

	////�ͻ������޸�����ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsClientPasswordModifyReqField
	//{
	//	TClientNoType				ClientNo;               //�ͻ���
	//	TPasswordTypeType			PasswordType;           //��������
	//	TLoginPasswordType			OldPassword;			//����Ա�޸Ŀͻ�����ʱ,��Ȩ�޲���Ա���Բ���д������					
	//	TLoginPasswordType			NewPassword;            //������
	//};

	//�ͻ������޸�Ӧ��ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct ClientPasswordModifyRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;               //�ͻ���
		Byte			    PasswordType;           //��������
	};

	////����Ա�����޸�����ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsOperatorPasswordModifyReqField
	//{
	//	TOperatorNoType				OperatorNo;				//����Ա��
	//	TLoginPasswordType			OldPassword;		    //������
	//	TLoginPasswordType			NewPassword;			//������
	//};
	////����Ա�����޸�Ӧ��ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsOperatorPasswordModifyRspField
	//{
	//	TOperatorNoType				OperatorNo;			    //����Ա��
	//};

	//�г���ѯ����ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct ExchangeQryReqField
	{
	};
	////�г���ѯӦ��ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsExchangeQryRspField
	//{
	//	TExchangeNoType				ExchangeNo;		        //������
	//	TExchangeNameType			ExchangeName;		    //����������
	//	TExchangeStateType			ExchangeState;		    //������״̬
	//};

	//�г�״̬�޸�֪ͨ�ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct ExchangeStateModifyNoticeField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				ExchangeNo;
		Byte			ExchangeState;
	};

	////����Ա�����ͻ���ѯ����ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsOperatorClientQryReqField
	//{
	//	TOperatorNoType				OperatorNo;			    //����Ա��
	//};
	////����Ա�����ͻ���ѯӦ��ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsOperatorClientQryRspField
	//{
	//	TClientNoType				ClientNo;			    //�ͻ���
	//};

	//��ʷί�в�ѯ����ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct HisOrderQryReqField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;				//�ͻ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^						BeginDate;				//��ʼ���ڣ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^						EndDate;				//�������ڣ�����
	};

	//��ʷί�в�ѯӦ��ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct HisOrderQryRspField
	{
		OrderInfoNoticeField^     Data;				    //ί������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^					Date;                   //ί������
	};

	//��ʷ�ɽ���ѯ����ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct HisMatchQryReqField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;				//�ͻ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^						BeginDate;				//��ʼ���ڣ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^						EndDate;				//�������ڣ�����
		Byte			IsContainTotle;			//�Ƿ�����ϼ�ֵ
	};

	//��ʷ�ɽ���ѯӦ��ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct HisMatchQryRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^					Date;				    //��������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;				//�ͻ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				SettleNo;				//�����óɽ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^			CommodityNo;			//��Ʒ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				ContractNo;				//��Լ
		Byte				MatchWay;				//�ɽ���ʽ
		Byte					Direct;                 //��������
		Byte					Offset;                 //��ƽ����
		int				MatchVol;               //�ɽ�����
		double				MatchPrice;             //�ɽ��۸�
		double				Premium;                //Ȩ����
		double              Turnover;        //�ɽ����
		double				ClientFee;				//�ͻ�������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				GroupNo;				//�������
		double				ManualFee;				//�˹�������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				CurrencyNo;             //����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				CommodityCurrencyNo;    //Ʒ�ֱ���
		Byte			IsRiskOrder;            //�Ƿ���ձ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				SystemNo;               //ϵͳ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				MatchNo;                //�ɽ���
		int				MatchStreamID;          //�ɽ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				MatchDateTime;          //�ɽ�ʱ��
		Byte				MatchMode;              //�Ƿ���ձ���
		Byte				OrderType;              //ί������
		double				CoverPrice;             //ƽ�ּ۸�
		double				CoverProfit;			//ƽ��ӯ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				UpperNo;				//��ʷ�ɽ����ֺ�
	};

	////ί�б�����̲�ѯ��������
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsOrderProcessQryReqField
	//{
	//	TOrderIdType				OrderId;                //ί��ID
	//};

	////ί�б�����̲�ѯӦ������
	//typedef TEsOrderStateNoticeField TEsOrderProcessQryRspField;

	////��ʷί�����̲�ѯ����ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsHisOrderProcessQryReqField
	//{
	//	TOrderIdType				OrderId;                //ί��ID
	//	TDateType					Date;                   //��ѯ����
	//};

	////��ʷί�����̲�ѯӦ��ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsHisOrderProcessQryRspField
	//{
	//	TEsOrderProcessQryRspField  Data;                   //ί����������
	//	TDateType			        Date;                   //����
	//};

	//��������ѯ����ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct CashOperQryReqField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;               //�ͻ���
	};
	//��������ѯӦ��ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct CashOperQryRspField
	{
		CashOperQryReqField      ReqData;                //��ѯ��������
		int			SerialId;               //�������ˮ��
		Byte				CashState;              //�����״̬
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				OperDateTime;           //����ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				OperatorNo;             //������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				CheckDateTime;          //���ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				CheckOperatorNo;        //�����

		Byte				CashType;               //���������
		Byte				CashMode;               //�����ʽ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				CurrencyNo;             //���ұ��
		double				CashValue;              //�������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
		String^				CashRemark;             //��ע
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^				ClientBank;				//�ͻ����б�ʶ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^				ClientAccount;			//�ͻ������˻�
		Byte				ClientLWFlag;			//�ͻ�������˻���ʶ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		Byte				CompanyBank;			//��˾���б�ʶ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^				CompanyAccount;			//��˾�����˻�
		Byte				CompanyLWFlag;			//��˾������˻���ʶ
	};

	////��������������ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsCashOperReqField
	//{
	//	TClientNoType				ClientNo;				//�ͻ���
	//	TCashTypeType				CashType;				//���������
	//	TCashModeType				CashMode;				//�����ʽ
	//	TCurrencyNoType				CurrencyNo;				//���ұ��
	//	TMoneyValueType				CashValue;				//�������
	//	TCashRemarkType				CashRemark;				//��ע
	//	TBankType					ClientBank;				//�ͻ����б�ʶ
	//	TAccountType				ClientAccount;			//�ͻ������˻�
	//	TLWFlagType					ClientLWFlag;			//�ͻ�������˻���ʶ
	//	TBankType					CompanyBank;			//��˾���б�ʶ
	//	TAccountType				CompanyAccount;			//��˾�����˻�
	//	TLWFlagType					CompanyLWFlag;			//��˾������˻���ʶ
	//};

	////����������Ӧ��ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsCashOperRspField
	//{
	//	TEsCashOperReqField			ReqData;				//����������������
	//	TCashSerialIdType			SerialId;				//�������ˮ��
	//	TCashStateType				CashState;				//�����״̬
	//	TDateTimeType				OperDateTime;			//����ʱ��
	//	TOperatorNoType				OperatorNo;				//������
	//	TDateTimeType				CheckDateTime;			//���ʱ��
	//	TOperatorNoType				CheckOperatorNo;		//�����
	//};

	////����������֪ͨ�ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//typedef TEsCashOperRspField TEsCashOperNoticeField;

	////��������������ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsCashCheckReqField
	//{
	//	TCashSerialIdType			SerialId;				//�������ˮ��
	//	TCashStateType				CashState;				//�����״̬
	//	TForceCashOutFlagType		ForceCashOutFlag;		//�Ƿ�ǿ�Ƴ�����
	//};

	////����������Ӧ��ṹ
	//typedef TEsCashOperRspField TEsCashCheckRspField;

	////����������֪ͨ�ṹ
	//typedef TEsCashOperRspField TEsCashCheckNoticeField;

	////�ʽ������ѯ����ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsAdjustQryReqField
	//{
	//	TClientNoType				ClientNo;               //�ͻ���
	//};

	////�ʽ������ѯӦ��ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsAdjustQryRspField
	//{
	//	TEsAdjustQryReqField        ReqData;                //��ѯ��������
	//	TAdjustSerialIdType			SerialId;               //�������ˮ��
	//	TAdjustStateType			AdjustState;            //�ʽ����״̬   
	//	TDateTimeType				OperDateTime;           //����ʱ��
	//	TOperatorNoType				OperatorNo;             //������
	//	TDateTimeType				CheckDateTime;          //���ʱ��
	//	TOperatorNoType				CheckOperatorNo;        //�����

	//	TAdjustTypeType				AdjustType;             //�ʽ��������
	//	TCurrencyNoType				CurrencyNo;             //���ұ��
	//	TMoneyValueType				AdjustValue;            //�������
	//	TAdjustRemarkType			AdjustRemark;           //��ע
	//														//20120616����
	//	TBankType					ClientBank;				//���б�ʶ
	//	TAccountType				ClientAccount;			//�����˻�
	//	TLWFlagType					ClientLWFlag;			//������˻���ʶ
	//	TBankType					CompanyBank;			//���б�ʶ
	//	TAccountType				CompanyAccount;			//�����˻�
	//	TLWFlagType					CompanyLWFlag;			//������˻���ʶ
	//};

	////��ʷ������ѯ����ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsHisCashOperQryReqField
	//{
	//	TClientNoType				ClientNo;				//�ͻ���
	//	TDateType					BeginDate;				//��ʼ����
	//	TDateType					EndDate;				//��ֹ����
	//};

	////��ʷ������ѯӦ��ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsHisCashOperQryRspField
	//{
	//	TEsCashOperQryRspField		Data;
	//	TDateType					Date;
	//};

	////��ʷ�ʽ������ѯ����ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsHisAdjustQryReqField
	//{
	//	TClientNoType				ClientNo;				//�ͻ���
	//	TDateType					BeginDate;				//��ʼ����
	//	TDateType					EndDate;				//��ֹ����
	//};
	////��ʷ�ʽ������ѯӦ��ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsHisAdjustQryRspField
	//{
	//	TEsAdjustQryRspField		Data;
	//	TDateType					Date;
	//};

	////�ͻ���֤������֤����ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsClientPasswordAuthReqField
	//{
	//	TClientNoType				ClientNo;
	//	TLoginPasswordType			Password;
	//};
	////�ͻ���֤������֤Ӧ��ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsClientPasswordAuthRspField
	//{
	//	TClientNoType				ClientNo;
	//};

	//���ֲ�ѯ����ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct CurrencyQryReqField
	{
	};
	//���ֲ�ѯӦ��ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct CurrencyQryRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				CurrencyNo;
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				CurrencyName;
		Byte				IsPrimary;
		Byte				CurrencyGroup;
		double				ExchangeRate;
	};

	//ɾ��ί��֪ͨ�ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct OrderRemoveNoticeField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^               ClientNo;
		int				OrderId;
	};

	//ɾ���ɽ�֪ͨ�ṹ
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct MatchRemoveNoticeField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^             ClientNo;
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				SystemNo;
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				MatchNo;
		int				    MatchId;
	};

	////���ʱ��֪ͨ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsExchangeRateModifyNoticeField
	//{
	//	TCurrencyNoType				CurrencyNo;
	//	TExchangeRateType			ExchangeRate;
	//};

	////����¼���ѯ����ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsMonitorEventQryReqField
	//{
	//};

	////����¼���ѯӦ��ṹ
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsMonitorEventQryRspField
	//{
	//	TEventTypeType				EventType;
	//	TEventLevelType				EventLevel;
	//	TEventSourceType			EventSource;
	//	TEventContentType			EventContent;
	//	TEventSerialIdType			SerialId;
	//	TDateTimeType				EventDateTime;
	//};

	////����¼�֪ͨ�ṹ
	//typedef TEsMonitorEventQryRspField	TEsMonitorEventNoticeField;

	////�۽��������̱�������---�ͻ�����
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsHKMarketOrderReq
	//{
	//	TClientNoType					ClientNo;
	//	TCommodityNoType				CommodityNo;
	//	TContractNoType					ContractNo;

	//	TOrderTypeType					OrderType;						//ί������
	//	TOrderModeType					OrderMode;						//ί��ģʽ
	//	TDateTimeType					ValidDateTime;

	//	TTradePriceType					BuyPrice;
	//	TTradePriceType					SellPrice;

	//	TTradeVolType					BuyVol;
	//	TTradeVolType					SellVol;

	//	THKMarketOperType				BuyOper;
	//	THKMarketOperType				SellOper;

	//	TOrderIdType					BuyOrderID;
	//	TOrderIdType					SellOrderID;

	//	TOrderSaveStringType			SaveString;
	//};
	//typedef TEsHKMarketOrderReq TEsHKMarketOrderRsp;

	////�ͻ����������ѯ����ṹ

	//public ref public ref struct TClientCountRentQryReq
	//{
	//	TClientNoType				ClientNo;
	//	TCommodityNoType			CommodityNo;
	//	TContractNoType				ContractNo;			//�����
	//	TMatchWayType				MatchWay;
	//};
	////�ͻ����������ѯӦ��ṹ
	//public ref public ref struct TClientCountRentQryRsp
	//{
	//	TClientCountRentQryReq		ReqData;

	//	TMoneyValueType				BFee;
	//	TMoneyValueType				DFee;
	//	TCurrencyNoType				CurrencyNo;

	//	TDepositModeType			DepositMode;		//�������Ͷ���
	//	TMoneyValueType				Deposit;			//������֤��
	//	TMoneyValueType				LockDeposit;		//���ֱ�֤��
	//	TMoneyValueType				KeepDeposit;		//ά�ֱ�֤��
	//};

}
