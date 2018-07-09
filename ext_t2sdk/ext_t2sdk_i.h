

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Mon Jul 09 15:01:08 2018
 */
/* Compiler settings for ext_t2sdk.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ext_t2sdk_i_h__
#define __ext_t2sdk_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IComponentRegistrar_FWD_DEFINED__
#define __IComponentRegistrar_FWD_DEFINED__
typedef interface IComponentRegistrar IComponentRegistrar;
#endif 	/* __IComponentRegistrar_FWD_DEFINED__ */


#ifndef __IHsT2Com_FWD_DEFINED__
#define __IHsT2Com_FWD_DEFINED__
typedef interface IHsT2Com IHsT2Com;
#endif 	/* __IHsT2Com_FWD_DEFINED__ */


#ifndef __CompReg_FWD_DEFINED__
#define __CompReg_FWD_DEFINED__

#ifdef __cplusplus
typedef class CompReg CompReg;
#else
typedef struct CompReg CompReg;
#endif /* __cplusplus */

#endif 	/* __CompReg_FWD_DEFINED__ */


#ifndef __HsT2Com_FWD_DEFINED__
#define __HsT2Com_FWD_DEFINED__

#ifdef __cplusplus
typedef class HsT2Com HsT2Com;
#else
typedef struct HsT2Com HsT2Com;
#endif /* __cplusplus */

#endif 	/* __HsT2Com_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IComponentRegistrar_INTERFACE_DEFINED__
#define __IComponentRegistrar_INTERFACE_DEFINED__

/* interface IComponentRegistrar */
/* [unique][dual][uuid][object] */ 


EXTERN_C const IID IID_IComponentRegistrar;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a817e7a2-43fa-11d0-9e44-00aa00b6770a")
    IComponentRegistrar : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Attach( 
            /* [in] */ BSTR bstrPath) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RegisterAll( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UnregisterAll( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetComponents( 
            /* [out] */ SAFEARRAY * *pbstrCLSIDs,
            /* [out] */ SAFEARRAY * *pbstrDescriptions) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RegisterComponent( 
            /* [in] */ BSTR bstrCLSID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UnregisterComponent( 
            /* [in] */ BSTR bstrCLSID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IComponentRegistrarVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IComponentRegistrar * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IComponentRegistrar * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IComponentRegistrar * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IComponentRegistrar * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IComponentRegistrar * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IComponentRegistrar * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IComponentRegistrar * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IComponentRegistrar * This,
            /* [in] */ BSTR bstrPath);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RegisterAll )( 
            IComponentRegistrar * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UnregisterAll )( 
            IComponentRegistrar * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetComponents )( 
            IComponentRegistrar * This,
            /* [out] */ SAFEARRAY * *pbstrCLSIDs,
            /* [out] */ SAFEARRAY * *pbstrDescriptions);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RegisterComponent )( 
            IComponentRegistrar * This,
            /* [in] */ BSTR bstrCLSID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UnregisterComponent )( 
            IComponentRegistrar * This,
            /* [in] */ BSTR bstrCLSID);
        
        END_INTERFACE
    } IComponentRegistrarVtbl;

    interface IComponentRegistrar
    {
        CONST_VTBL struct IComponentRegistrarVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IComponentRegistrar_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IComponentRegistrar_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IComponentRegistrar_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IComponentRegistrar_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IComponentRegistrar_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IComponentRegistrar_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IComponentRegistrar_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IComponentRegistrar_Attach(This,bstrPath)	\
    ( (This)->lpVtbl -> Attach(This,bstrPath) ) 

#define IComponentRegistrar_RegisterAll(This)	\
    ( (This)->lpVtbl -> RegisterAll(This) ) 

#define IComponentRegistrar_UnregisterAll(This)	\
    ( (This)->lpVtbl -> UnregisterAll(This) ) 

#define IComponentRegistrar_GetComponents(This,pbstrCLSIDs,pbstrDescriptions)	\
    ( (This)->lpVtbl -> GetComponents(This,pbstrCLSIDs,pbstrDescriptions) ) 

#define IComponentRegistrar_RegisterComponent(This,bstrCLSID)	\
    ( (This)->lpVtbl -> RegisterComponent(This,bstrCLSID) ) 

#define IComponentRegistrar_UnregisterComponent(This,bstrCLSID)	\
    ( (This)->lpVtbl -> UnregisterComponent(This,bstrCLSID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IComponentRegistrar_INTERFACE_DEFINED__ */


#ifndef __IHsT2Com_INTERFACE_DEFINED__
#define __IHsT2Com_INTERFACE_DEFINED__

/* interface IHsT2Com */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IHsT2Com;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("165B9942-98BD-4CAF-ABBF-72735B4B1794")
    IHsT2Com : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetConnString( 
            /* [in] */ BSTR szSection,
            /* [in] */ BSTR szEntry,
            /* [in] */ BSTR szValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetServerConfig( 
            /* [in] */ BSTR servers,
            /* [in] */ BSTR licensefile,
            /* [in] */ BSTR lang,
            /* [in] */ BSTR send_queue_size,
            /* [in] */ BSTR safe_level) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ConnectionCreate( 
            /* [out] */ LONG *result) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [in] */ LONG timeout,
            /* [out] */ BSTR *ErrorMsg) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddValueInt( 
            /* [in] */ LONG iValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddValueStr( 
            /* [in] */ BSTR szValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddValueDouble( 
            /* [in] */ DOUBLE fValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddValueChar( 
            /* [in] */ BSTR cValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE initNewConfig( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE addNewPacker( 
            /* [in] */ LONG iVer) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE addBeginPack( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE addEndPack( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE runSendBiz( 
            /* [in] */ LONG iFunID,
            /* [in] */ LONG iSystemNo,
            /* [out] */ LONG *result,
            /* [out] */ BSTR *ErrorMsg,
            /* [out] */ VARIANT *pNameArr,
            /* [out] */ VARIANT *pValueArr) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE runRelease( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddFieldName( 
            /* [in] */ BSTR szFieldName,
            /* [in] */ BSTR szFieldType) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddFieldDef( 
            /* [in] */ BSTR szFieldName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsT2ComVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsT2Com * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsT2Com * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsT2Com * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHsT2Com * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHsT2Com * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHsT2Com * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHsT2Com * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetConnString )( 
            IHsT2Com * This,
            /* [in] */ BSTR szSection,
            /* [in] */ BSTR szEntry,
            /* [in] */ BSTR szValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetServerConfig )( 
            IHsT2Com * This,
            /* [in] */ BSTR servers,
            /* [in] */ BSTR licensefile,
            /* [in] */ BSTR lang,
            /* [in] */ BSTR send_queue_size,
            /* [in] */ BSTR safe_level);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ConnectionCreate )( 
            IHsT2Com * This,
            /* [out] */ LONG *result);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IHsT2Com * This,
            /* [in] */ LONG timeout,
            /* [out] */ BSTR *ErrorMsg);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddValueInt )( 
            IHsT2Com * This,
            /* [in] */ LONG iValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddValueStr )( 
            IHsT2Com * This,
            /* [in] */ BSTR szValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddValueDouble )( 
            IHsT2Com * This,
            /* [in] */ DOUBLE fValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddValueChar )( 
            IHsT2Com * This,
            /* [in] */ BSTR cValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *initNewConfig )( 
            IHsT2Com * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *addNewPacker )( 
            IHsT2Com * This,
            /* [in] */ LONG iVer);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *addBeginPack )( 
            IHsT2Com * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *addEndPack )( 
            IHsT2Com * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *runSendBiz )( 
            IHsT2Com * This,
            /* [in] */ LONG iFunID,
            /* [in] */ LONG iSystemNo,
            /* [out] */ LONG *result,
            /* [out] */ BSTR *ErrorMsg,
            /* [out] */ VARIANT *pNameArr,
            /* [out] */ VARIANT *pValueArr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *runRelease )( 
            IHsT2Com * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddFieldName )( 
            IHsT2Com * This,
            /* [in] */ BSTR szFieldName,
            /* [in] */ BSTR szFieldType);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddFieldDef )( 
            IHsT2Com * This,
            /* [in] */ BSTR szFieldName);
        
        END_INTERFACE
    } IHsT2ComVtbl;

    interface IHsT2Com
    {
        CONST_VTBL struct IHsT2ComVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsT2Com_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHsT2Com_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHsT2Com_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHsT2Com_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHsT2Com_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHsT2Com_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHsT2Com_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IHsT2Com_SetConnString(This,szSection,szEntry,szValue)	\
    ( (This)->lpVtbl -> SetConnString(This,szSection,szEntry,szValue) ) 

#define IHsT2Com_SetServerConfig(This,servers,licensefile,lang,send_queue_size,safe_level)	\
    ( (This)->lpVtbl -> SetServerConfig(This,servers,licensefile,lang,send_queue_size,safe_level) ) 

#define IHsT2Com_ConnectionCreate(This,result)	\
    ( (This)->lpVtbl -> ConnectionCreate(This,result) ) 

#define IHsT2Com_Connect(This,timeout,ErrorMsg)	\
    ( (This)->lpVtbl -> Connect(This,timeout,ErrorMsg) ) 

#define IHsT2Com_AddValueInt(This,iValue)	\
    ( (This)->lpVtbl -> AddValueInt(This,iValue) ) 

#define IHsT2Com_AddValueStr(This,szValue)	\
    ( (This)->lpVtbl -> AddValueStr(This,szValue) ) 

#define IHsT2Com_AddValueDouble(This,fValue)	\
    ( (This)->lpVtbl -> AddValueDouble(This,fValue) ) 

#define IHsT2Com_AddValueChar(This,cValue)	\
    ( (This)->lpVtbl -> AddValueChar(This,cValue) ) 

#define IHsT2Com_initNewConfig(This)	\
    ( (This)->lpVtbl -> initNewConfig(This) ) 

#define IHsT2Com_addNewPacker(This,iVer)	\
    ( (This)->lpVtbl -> addNewPacker(This,iVer) ) 

#define IHsT2Com_addBeginPack(This)	\
    ( (This)->lpVtbl -> addBeginPack(This) ) 

#define IHsT2Com_addEndPack(This)	\
    ( (This)->lpVtbl -> addEndPack(This) ) 

#define IHsT2Com_runSendBiz(This,iFunID,iSystemNo,result,ErrorMsg,pNameArr,pValueArr)	\
    ( (This)->lpVtbl -> runSendBiz(This,iFunID,iSystemNo,result,ErrorMsg,pNameArr,pValueArr) ) 

#define IHsT2Com_runRelease(This)	\
    ( (This)->lpVtbl -> runRelease(This) ) 

#define IHsT2Com_AddFieldName(This,szFieldName,szFieldType)	\
    ( (This)->lpVtbl -> AddFieldName(This,szFieldName,szFieldType) ) 

#define IHsT2Com_AddFieldDef(This,szFieldName)	\
    ( (This)->lpVtbl -> AddFieldDef(This,szFieldName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHsT2Com_INTERFACE_DEFINED__ */



#ifndef __ext_t2sdkLib_LIBRARY_DEFINED__
#define __ext_t2sdkLib_LIBRARY_DEFINED__

/* library ext_t2sdkLib */
/* [custom][version][uuid] */ 


EXTERN_C const IID LIBID_ext_t2sdkLib;

EXTERN_C const CLSID CLSID_CompReg;

#ifdef __cplusplus

class DECLSPEC_UUID("4BD326E4-600E-4974-99F3-E7531FDAF8C5")
CompReg;
#endif

EXTERN_C const CLSID CLSID_HsT2Com;

#ifdef __cplusplus

class DECLSPEC_UUID("60F08CA9-F0E0-4A05-81C9-C92799C8B711")
HsT2Com;
#endif
#endif /* __ext_t2sdkLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


