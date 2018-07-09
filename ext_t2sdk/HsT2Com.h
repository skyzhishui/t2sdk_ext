// HsT2Com.h : CHsT2Com 的声明

#pragma once
#include "resource.h"       // 主符号



#include "ext_t2sdk_i.h"
#include "t2sdk_interface.h"

#include <comutil.h>
#pragma comment(lib,"comsuppw.lib")

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
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

