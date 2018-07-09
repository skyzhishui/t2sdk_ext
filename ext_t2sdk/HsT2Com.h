// HsT2Com.h : CHsT2Com ������

#pragma once
#include "resource.h"       // ������



#include "ext_t2sdk_i.h"
#include "t2sdk_interface.h"

#include <comutil.h>
#pragma comment(lib,"comsuppw.lib")

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;


// CHsT2Com

class ATL_NO_VTABLE CHsT2Com :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CHsT2Com, &CLSID_HsT2Com>,
	public IDispatchImpl<IHsT2Com, &IID_IHsT2Com, &LIBID_ext_t2sdkLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CHsT2Com()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_HST2COM)


BEGIN_COM_MAP(CHsT2Com)
	COM_INTERFACE_ENTRY(IHsT2Com)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



	STDMETHOD(SetConnString)(BSTR szSection, BSTR szEntry, BSTR szValue);
	STDMETHOD(SetServerConfig)(BSTR servers, BSTR licensefile, BSTR lang, BSTR send_queue_size, BSTR safe_level);
	STDMETHOD(ConnectionCreate)(LONG* result);
	STDMETHOD(Connect)(LONG timeout, BSTR* ErrorMsg);
	STDMETHOD(AddValueInt)(LONG iValue);
	STDMETHOD(AddValueStr)(BSTR szValue);
	STDMETHOD(AddValueDouble)(DOUBLE fValue);
	STDMETHOD(AddValueChar)(BSTR cValue);

	STDMETHOD(initNewConfig)(void);
	STDMETHOD(addNewPacker)(LONG iVer);
	STDMETHOD(addBeginPack)(void);
	STDMETHOD(addEndPack)(void);

	STDMETHOD(runSendBiz)(LONG iFunID,LONG iSystemNo, LONG* result, BSTR* ErrorMsg, VARIANT* pNameArr, VARIANT* pValueArr);
	STDMETHOD(runRelease)(void);
	STDMETHOD(AddFieldName)(BSTR szFieldName,BSTR szFieldType);
	STDMETHOD(AddFieldDef)(BSTR szFieldName);
};



OBJECT_ENTRY_AUTO(__uuidof(HsT2Com), CHsT2Com)

