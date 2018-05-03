// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#pragma once

#include "include/EsunnyQuot.h"
#include "include/EsunnyForeignApi.h"

#include "EsStruct.h"
#include "Delegates.h"
#include <vcclr.h>

using namespace System;

namespace EsForeignWrapper 
{
	/// ���й���, �Զ�ת�� Managed <==> Native 
	template<typename ManagedType, typename NativeType>
	class TypeConverter
	{
	public:
		/// Native to Managed
		static ManagedType ToManagedType(NativeType* pNative)
		{
			return safe_cast<ManagedType>(Marshal::PtrToStructure(IntPtr(pNative), ManagedType::typeid));
		}

		static void ToNativeType(ManagedType managed, NativeType* pNative)
		{
			Marshal::StructureToPtr(managed, IntPtr(pNative), true);
		}
	};
}

