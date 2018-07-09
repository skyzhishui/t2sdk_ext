// HsT2Com.cpp : CHsT2Com 的实现

#include "stdafx.h"
#include "HsT2Com.h"
#include "t2sdk_interface.h"
#include <stdlib.h>
#include <comutil.h>
#pragma comment(lib,"comsuppw.lib")


CConfigInterface * lpConfig = NULL;
CConnectionInterface *lpConnection = NULL;
IF2Packer* pack = NULL;
STDMETHODIMP CHsT2Com::initNewConfig(void)
{
	// TODO: 在此添加实现代码
	lpConfig = NewConfig();
	lpConfig->AddRef();
	return S_OK;
}


// CHsT2Com


STDMETHODIMP CHsT2Com::SetConnString(BSTR szSection, BSTR szEntry, BSTR szValue)
{
	// TODO: 在此添加实现代码
	//char* str = _com_util::ConvertBSTRToString(szSection);
	lpConfig->SetString(_com_util::ConvertBSTRToString(szSection), _com_util::ConvertBSTRToString(szEntry), _com_util::ConvertBSTRToString(szValue));
	return S_OK;
}


STDMETHODIMP CHsT2Com::SetServerConfig(BSTR servers, BSTR licensefile, BSTR lang, BSTR send_queue_size, BSTR safe_level)
{
	// TODO: 在此添加实现代码
	lpConfig->SetString("t2sdk", "servers", _com_util::ConvertBSTRToString(servers));

    //[t2sdk] license_file指定许可证文件路径
    lpConfig->SetString("t2sdk", "license_file", _com_util::ConvertBSTRToString(licensefile));

    //[t2sdk] lang指定错误信息的语言号（缺省为简体中文2052），1033为英文
    lpConfig->SetString("t2sdk", "lang", _com_util::ConvertBSTRToString(lang));

    //[t2sdk] send_queue_size指定T2_SDK的发送队列大小
    lpConfig->SetString("t2sdk", "send_queue_size", _com_util::ConvertBSTRToString(send_queue_size));

    //[safe] safe_level指定连接的安全模式，需要和T2通道的安全模式一致，否则连接失败
    lpConfig->SetString("safe", "safe_level", _com_util::ConvertBSTRToString(safe_level));
	return S_OK;
}


STDMETHODIMP CHsT2Com::ConnectionCreate(LONG* result)
{
	// TODO: 在此添加实现代码
	//通过T2SDK的引出函数，来获取一个新的CConnection对象指针
    lpConnection = NewConnection(lpConfig);

    lpConnection->AddRef();

	* result = lpConnection->Create(NULL);
	//long longret = (long)ret;
	
	return S_OK;
}


STDMETHODIMP CHsT2Com::Connect(LONG timeout, BSTR* ErrorMsg)
{
	// TODO: 在此添加实现代码
	int ret = 0;
	BSTR str;
	if (ret = lpConnection->Connect(1000))
    {
		str = _com_util::ConvertStringToBSTR(lpConnection->GetErrorMsg(ret));
	}
	else
	{
		str = _com_util::ConvertStringToBSTR("OK");
	}
	* ErrorMsg = str;
	return S_OK;
}


STDMETHODIMP CHsT2Com::AddFieldName(BSTR szFieldName,BSTR szFieldType)
{
	// TODO: 在此添加实现代码
	CHAR* schar =  _com_util::ConvertBSTRToString(szFieldType);
	pack->AddField(_com_util::ConvertBSTRToString(szFieldName),schar[0]);
	return S_OK;
}

STDMETHODIMP CHsT2Com::AddValueInt(LONG iValue)
{
	// TODO: 在此添加实现代码
	//pack->AddField(_com_util::ConvertBSTRToString(szFieldName),'I');
	pack->AddInt(iValue);
	return S_OK;
}


STDMETHODIMP CHsT2Com::AddValueStr(BSTR szValue)
{
	// TODO: 在此添加实现代码
	//pack->AddField(_com_util::ConvertBSTRToString(szFieldName),'S');
	pack->AddStr(_com_util::ConvertBSTRToString(szValue));
	return S_OK;
}


STDMETHODIMP CHsT2Com::AddValueDouble(DOUBLE fValue)
{
	// TODO: 在此添加实现代码
	//pack->AddField(_com_util::ConvertBSTRToString(szFieldName),'D');
	pack->AddDouble(fValue);
	return S_OK;
}


STDMETHODIMP CHsT2Com::AddValueChar(BSTR cValue)
{
	// TODO: 在此添加实现代码
	CHAR* schar =  _com_util::ConvertBSTRToString(cValue);
	//pack->AddField(_com_util::ConvertBSTRToString(szFieldName),'C');
	pack->AddChar(schar[0]);
	return S_OK;
}







STDMETHODIMP CHsT2Com::addNewPacker(LONG iVer)
{
	// TODO: 在此添加实现代码
	pack = NewPacker(2);

    pack->AddRef();
	return S_OK;
}


STDMETHODIMP CHsT2Com::addBeginPack(void)
{
	// TODO: 在此添加实现代码
	pack->BeginPack();
	return S_OK;
}


STDMETHODIMP CHsT2Com::addEndPack(void)
{
	// TODO: 在此添加实现代码
	pack->EndPack();
	return S_OK;
}



STDMETHODIMP CHsT2Com::runSendBiz(LONG iFunID,LONG iSystemNo, LONG* result, BSTR* ErrorMsg, VARIANT* pNameArr, VARIANT* pValueArr)
{
	// TODO: 在此添加实现代码
	void *Pointer = NULL;
	int ret = 0;
	VARIANT nameWarp;
	VARIANT valueWarp;
	VariantInit(&nameWarp);
	VariantInit(&valueWarp);
    nameWarp.vt = VT_ARRAY | VT_BSTR; 
    valueWarp.vt = VT_ARRAY | VT_BSTR; 
	SAFEARRAY *namepsa;
	SAFEARRAY *valuepsa;
	SAFEARRAYBOUND nameArry = { 200, 0 };
	SAFEARRAYBOUND valueArry = { 200, 0 }; 
	namepsa = SafeArrayCreate(VT_BSTR,1,&nameArry);
	valuepsa = SafeArrayCreate(VT_BSTR,1,&valueArry);
	BSTR* nameBstr;
	BSTR* valueBstr;
	SafeArrayAccessData(namepsa, (void **)&nameBstr); 
	SafeArrayAccessData(valuepsa, (void **)&valueBstr);
	if(iSystemNo == 0)
	{
		ret = lpConnection->SendBiz(iFunID, pack);
	}
	else
	{
		ret = lpConnection->SendBiz(iFunID, pack, 0, iSystemNo);
	}
	if (ret < 0)
    {
		/*MessageBoxA(0, lpConnection->GetErrorMsg(ret), "错误", 0);*/
		* result = ret;
		* ErrorMsg = _com_util::ConvertStringToBSTR(lpConnection->GetErrorMsg(ret));
    }
	else
	{
		ret = lpConnection->RecvBiz(ret, &Pointer);
		//int i = lpConnection->GetStatus();
		* result = ret;
		switch (ret)
		{
			case 0:
			{
				//MessageBoxA(0, "业务操作成功!", "信息", 0);
				//* ErrorMsg = ShowPacket((IF2UnPacker *)Pointer);
				IF2UnPacker * lpUnPacker = (IF2UnPacker *)Pointer;
				int i = 0, t = 0, j = 0, k = 0;
				for (i = 0; i < lpUnPacker->GetDatasetCount(); ++i)
				{
					// 设置当前结果集
					lpUnPacker->SetCurrentDatasetByIndex(i);
					//// 打印字段
					//for (t = 0; t < lpUnPacker->GetColCount(); ++t)
					//{
					//	printf("%20s", lpUnPacker->GetColName(t));
					//	nameBstr[t]
					//	//sprintf(str,"%s%s",str,lpUnPacker->GetColName(t));
					//	//retstr = retstr + _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(t));
					//}
					//putchar('\n');
					// 打印所有记录
					for (j = 0; j < (int)lpUnPacker->GetRowCount(); ++j)
					{
						// 打印每条记录
						for (k = 0; k < lpUnPacker->GetColCount(); ++k)
						{
							//int u = 0;
							switch (lpUnPacker->GetColType(k))
							{
							case 'I':
								//u = lpUnPacker->GetIntByIndex(k);
								//printf("%20d", lpUnPacker->GetIntByIndex(k));
								char istr[32];
								nameBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(k));
								sprintf(istr,"%d",lpUnPacker->GetIntByIndex(k));
								valueBstr[t] = _com_util::ConvertStringToBSTR(istr);
								break;

							case 'C':
								char cstr[4];
								//printf("%20c", lpUnPacker->GetCharByIndex(k));
								nameBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(k));
								sprintf(cstr,"%c",lpUnPacker->GetCharByIndex(k));
								valueBstr[t] = _com_util::ConvertStringToBSTR(cstr);
								//MessageBoxA(NULL,lpUnPacker->GetCharByIndex(k),"错误",MB_OK);
								break;

							case 'S':
								//printf("%20s", lpUnPacker->GetStrByIndex(k));
								//MessageBoxA(NULL,lpUnPacker->GetStrByIndex(k),"错误",MB_OK);
								nameBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(k));
								valueBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetStrByIndex(k)); 
								break;

							case 'F':
								char fstr[64];
								//printf("%20f", lpUnPacker->GetDoubleByIndex(k));
								//MessageBoxA(NULL,lpUnPacker->GetDoubleByIndex(k),"错误",MB_OK);
								nameBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(k));
								sprintf(fstr,"%f",lpUnPacker->GetDoubleByIndex(k));
								valueBstr[t] = _com_util::ConvertStringToBSTR(fstr);
								break;

							case 'R':
								{
									int nLength = 0;
									void *lpData = lpUnPacker->GetRawByIndex(k, &nLength);

									// 对2进制数据进行处理
									break;
								}

							default:
								// 未知数据类型
								//printf("未知数据类型。\n");
								nameBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(k));
								valueBstr[t] = _com_util::ConvertStringToBSTR("未知数据类型");
								break;
							}
							
						    t++;
						}
						lpUnPacker->Next();
					}

				}
				break;
			}

			case 1:
			{
				//MessageBoxA(0, "业务操作失败!", "信息", 0);
				// * ErrorMsg = ShowPacket((IF2UnPacker *)Pointer);
				IF2UnPacker * lpUnPacker = (IF2UnPacker *)Pointer;
				int i = 0, t = 0, j = 0, k = 0;
				for (i = 0; i < lpUnPacker->GetDatasetCount(); ++i)
				{
					// 设置当前结果集
					lpUnPacker->SetCurrentDatasetByIndex(i);
					//// 打印字段
					//for (t = 0; t < lpUnPacker->GetColCount(); ++t)
					//{
					//	printf("%20s", lpUnPacker->GetColName(t));
					//	nameBstr[t]
					//	//sprintf(str,"%s%s",str,lpUnPacker->GetColName(t));
					//	//retstr = retstr + _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(t));
					//}
					//putchar('\n');
					// 打印所有记录
					for (j = 0; j < (int)lpUnPacker->GetRowCount(); ++j)
					{
						// 打印每条记录
						for (k = 0; k < lpUnPacker->GetColCount(); ++k)
						{
							//int u = 0;
							char str[32];
							switch (lpUnPacker->GetColType(k))
							{
							case 'I':
								//u = lpUnPacker->GetIntByIndex(k);
								//printf("%20d", lpUnPacker->GetIntByIndex(k));
								nameBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(k));
								sprintf(str,"%d",lpUnPacker->GetIntByIndex(k));
								valueBstr[t] = _com_util::ConvertStringToBSTR(str);
								break;

							case 'C':
								//printf("%20c", lpUnPacker->GetCharByIndex(k));
								nameBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(k));
								sprintf(str,"%c",lpUnPacker->GetCharByIndex(k));
								valueBstr[t] = _com_util::ConvertStringToBSTR(str);
								//MessageBoxA(NULL,lpUnPacker->GetCharByIndex(k),"错误",MB_OK);
								break;

							case 'S':
								printf("%20s", lpUnPacker->GetStrByIndex(k));
								//MessageBoxA(NULL,lpUnPacker->GetStrByIndex(k),"错误",MB_OK);
								nameBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(k));
								valueBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetStrByIndex(k)); 
								break;

							case 'F':
								//printf("%20f", lpUnPacker->GetDoubleByIndex(k));
								//MessageBoxA(NULL,lpUnPacker->GetDoubleByIndex(k),"错误",MB_OK);
								nameBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(k));
								sprintf(str,"%f",lpUnPacker->GetDoubleByIndex(k));
								valueBstr[t] = _com_util::ConvertStringToBSTR(str);
								break;

							case 'R':
								{
									int nLength = 0;
									void *lpData = lpUnPacker->GetRawByIndex(k, &nLength);

									// 对2进制数据进行处理
									break;
								}

							default:
								// 未知数据类型
								//printf("未知数据类型。\n");
								nameBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(k));
								valueBstr[t] = _com_util::ConvertStringToBSTR("未知数据类型");
								break;
							}
							
						    t++;
						}
						lpUnPacker->Next();
					}

				}
				break;
			}

			case 2:
			{
				//MessageBoxA(0, (char *)Pointer, "错误", 0);
				* ErrorMsg = _com_util::ConvertStringToBSTR((char *)Pointer);
				//nameBstr[0] = _com_util::ConvertStringToBSTR("ErrorMsg");
				//valueBstr[0] = _com_util::ConvertStringToBSTR((char *)Pointer);
				break;
			}

			case 3:
			{
				//MessageBoxA(0,"业务包解包失败!", "错误", 0);
				* ErrorMsg = _com_util::ConvertStringToBSTR("业务包解包失败!");
				//nameBstr[0] = _com_util::ConvertStringToBSTR("ErrorMsg");
				//valueBstr[0] = _com_util::ConvertStringToBSTR("业务包解包失败!");
				break;
			}
			default:
			{
				//MessageBoxA(0,lpConnection->GetErrorMsg(ret), "错误", 0);
				* ErrorMsg = _com_util::ConvertStringToBSTR(lpConnection->GetErrorMsg(ret));
				
				//nameBstr[0] = _com_util::ConvertStringToBSTR("ErrorMsg");
				//valueBstr[0] = _com_util::ConvertStringToBSTR(lpConnection->GetErrorMsg(ret));
				break;
			}
		}
	}

	pack->Release();
	SafeArrayUnaccessData(namepsa);
	SafeArrayUnaccessData(valuepsa);
	nameWarp.parray = namepsa;
	valueWarp.parray = valuepsa;
	* pNameArr = nameWarp;
	* pValueArr = valueWarp;
	return S_OK;
}


STDMETHODIMP CHsT2Com::runRelease(void)
{
	// TODO: 在此添加实现代码
	
    lpConnection->Release();
    lpConfig->Release();
	return S_OK;
}




STDMETHODIMP CHsT2Com::AddFieldDef(BSTR szFieldName)
{
	// TODO: 在此添加实现代码
	pack->AddField(_com_util::ConvertBSTRToString(szFieldName));
	return S_OK;
}
