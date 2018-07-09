// dllmain.h : 模块类的声明。

class Cext_t2sdkModule : public ATL::CAtlDllModuleT< Cext_t2sdkModule >
{
public :
	DECLARE_LIBID(LIBID_ext_t2sdkLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_EXT_T2SDK, "{2DBEC8C7-A54C-4909-8F91-7FE37E4F6113}")
};

extern class Cext_t2sdkModule _AtlModule;
