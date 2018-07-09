// HsT2Com.cpp : CHsT2Com ��ʵ��

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
	// TODO: �ڴ����ʵ�ִ���
	lpConfig = NewConfig();
	lpConfig->AddRef();
	return S_OK;
}


// CHsT2Com


STDMETHODIMP CHsT2Com::SetConnString(BSTR szSection, BSTR szEntry, BSTR szValue)
{
	// TODO: �ڴ����ʵ�ִ���
	//char* str = _com_util::ConvertBSTRToString(szSection);
	lpConfig->SetString(_com_util::ConvertBSTRToString(szSection), _com_util::ConvertBSTRToString(szEntry), _com_util::ConvertBSTRToString(szValue));
	return S_OK;
}


STDMETHODIMP CHsT2Com::SetServerConfig(BSTR servers, BSTR licensefile, BSTR lang, BSTR send_queue_size, BSTR safe_level)
{
	// TODO: �ڴ����ʵ�ִ���
	lpConfig->SetString("t2sdk", "servers", _com_util::ConvertBSTRToString(servers));

    //[t2sdk] license_fileָ�����֤�ļ�·��
    lpConfig->SetString("t2sdk", "license_file", _com_util::ConvertBSTRToString(licensefile));

    //[t2sdk] langָ��������Ϣ�����Ժţ�ȱʡΪ��������2052����1033ΪӢ��
    lpConfig->SetString("t2sdk", "lang", _com_util::ConvertBSTRToString(lang));

    //[t2sdk] send_queue_sizeָ��T2_SDK�ķ��Ͷ��д�С
    lpConfig->SetString("t2sdk", "send_queue_size", _com_util::ConvertBSTRToString(send_queue_size));

    //[safe] safe_levelָ�����ӵİ�ȫģʽ����Ҫ��T2ͨ���İ�ȫģʽһ�£���������ʧ��
    lpConfig->SetString("safe", "safe_level", _com_util::ConvertBSTRToString(safe_level));
	return S_OK;
}


STDMETHODIMP CHsT2Com::ConnectionCreate(LONG* result)
{
	// TODO: �ڴ����ʵ�ִ���
	//ͨ��T2SDK����������������ȡһ���µ�CConnection����ָ��
    lpConnection = NewConnection(lpConfig);

    lpConnection->AddRef();

	* result = lpConnection->Create(NULL);
	//long longret = (long)ret;
	
	return S_OK;
}


STDMETHODIMP CHsT2Com::Connect(LONG timeout, BSTR* ErrorMsg)
{
	// TODO: �ڴ����ʵ�ִ���
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
	// TODO: �ڴ����ʵ�ִ���
	CHAR* schar =  _com_util::ConvertBSTRToString(szFieldType);
	pack->AddField(_com_util::ConvertBSTRToString(szFieldName),schar[0]);
	return S_OK;
}

STDMETHODIMP CHsT2Com::AddValueInt(LONG iValue)
{
	// TODO: �ڴ����ʵ�ִ���
	//pack->AddField(_com_util::ConvertBSTRToString(szFieldName),'I');
	pack->AddInt(iValue);
	return S_OK;
}


STDMETHODIMP CHsT2Com::AddValueStr(BSTR szValue)
{
	// TODO: �ڴ����ʵ�ִ���
	//pack->AddField(_com_util::ConvertBSTRToString(szFieldName),'S');
	pack->AddStr(_com_util::ConvertBSTRToString(szValue));
	return S_OK;
}


STDMETHODIMP CHsT2Com::AddValueDouble(DOUBLE fValue)
{
	// TODO: �ڴ����ʵ�ִ���
	//pack->AddField(_com_util::ConvertBSTRToString(szFieldName),'D');
	pack->AddDouble(fValue);
	return S_OK;
}


STDMETHODIMP CHsT2Com::AddValueChar(BSTR cValue)
{
	// TODO: �ڴ����ʵ�ִ���
	CHAR* schar =  _com_util::ConvertBSTRToString(cValue);
	//pack->AddField(_com_util::ConvertBSTRToString(szFieldName),'C');
	pack->AddChar(schar[0]);
	return S_OK;
}







STDMETHODIMP CHsT2Com::addNewPacker(LONG iVer)
{
	// TODO: �ڴ����ʵ�ִ���
	pack = NewPacker(2);

    pack->AddRef();
	return S_OK;
}


STDMETHODIMP CHsT2Com::addBeginPack(void)
{
	// TODO: �ڴ����ʵ�ִ���
	pack->BeginPack();
	return S_OK;
}


STDMETHODIMP CHsT2Com::addEndPack(void)
{
	// TODO: �ڴ����ʵ�ִ���
	pack->EndPack();
	return S_OK;
}



STDMETHODIMP CHsT2Com::runSendBiz(LONG iFunID,LONG iSystemNo, LONG* result, BSTR* ErrorMsg, VARIANT* pNameArr, VARIANT* pValueArr)
{
	// TODO: �ڴ����ʵ�ִ���
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
		/*MessageBoxA(0, lpConnection->GetErrorMsg(ret), "����", 0);*/
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
				//MessageBoxA(0, "ҵ������ɹ�!", "��Ϣ", 0);
				//* ErrorMsg = ShowPacket((IF2UnPacker *)Pointer);
				IF2UnPacker * lpUnPacker = (IF2UnPacker *)Pointer;
				int i = 0, t = 0, j = 0, k = 0;
				for (i = 0; i < lpUnPacker->GetDatasetCount(); ++i)
				{
					// ���õ�ǰ�����
					lpUnPacker->SetCurrentDatasetByIndex(i);
					//// ��ӡ�ֶ�
					//for (t = 0; t < lpUnPacker->GetColCount(); ++t)
					//{
					//	printf("%20s", lpUnPacker->GetColName(t));
					//	nameBstr[t]
					//	//sprintf(str,"%s%s",str,lpUnPacker->GetColName(t));
					//	//retstr = retstr + _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(t));
					//}
					//putchar('\n');
					// ��ӡ���м�¼
					for (j = 0; j < (int)lpUnPacker->GetRowCount(); ++j)
					{
						// ��ӡÿ����¼
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
								//MessageBoxA(NULL,lpUnPacker->GetCharByIndex(k),"����",MB_OK);
								break;

							case 'S':
								//printf("%20s", lpUnPacker->GetStrByIndex(k));
								//MessageBoxA(NULL,lpUnPacker->GetStrByIndex(k),"����",MB_OK);
								nameBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(k));
								valueBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetStrByIndex(k)); 
								break;

							case 'F':
								char fstr[64];
								//printf("%20f", lpUnPacker->GetDoubleByIndex(k));
								//MessageBoxA(NULL,lpUnPacker->GetDoubleByIndex(k),"����",MB_OK);
								nameBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(k));
								sprintf(fstr,"%f",lpUnPacker->GetDoubleByIndex(k));
								valueBstr[t] = _com_util::ConvertStringToBSTR(fstr);
								break;

							case 'R':
								{
									int nLength = 0;
									void *lpData = lpUnPacker->GetRawByIndex(k, &nLength);

									// ��2�������ݽ��д���
									break;
								}

							default:
								// δ֪��������
								//printf("δ֪�������͡�\n");
								nameBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(k));
								valueBstr[t] = _com_util::ConvertStringToBSTR("δ֪��������");
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
				//MessageBoxA(0, "ҵ�����ʧ��!", "��Ϣ", 0);
				// * ErrorMsg = ShowPacket((IF2UnPacker *)Pointer);
				IF2UnPacker * lpUnPacker = (IF2UnPacker *)Pointer;
				int i = 0, t = 0, j = 0, k = 0;
				for (i = 0; i < lpUnPacker->GetDatasetCount(); ++i)
				{
					// ���õ�ǰ�����
					lpUnPacker->SetCurrentDatasetByIndex(i);
					//// ��ӡ�ֶ�
					//for (t = 0; t < lpUnPacker->GetColCount(); ++t)
					//{
					//	printf("%20s", lpUnPacker->GetColName(t));
					//	nameBstr[t]
					//	//sprintf(str,"%s%s",str,lpUnPacker->GetColName(t));
					//	//retstr = retstr + _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(t));
					//}
					//putchar('\n');
					// ��ӡ���м�¼
					for (j = 0; j < (int)lpUnPacker->GetRowCount(); ++j)
					{
						// ��ӡÿ����¼
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
								//MessageBoxA(NULL,lpUnPacker->GetCharByIndex(k),"����",MB_OK);
								break;

							case 'S':
								printf("%20s", lpUnPacker->GetStrByIndex(k));
								//MessageBoxA(NULL,lpUnPacker->GetStrByIndex(k),"����",MB_OK);
								nameBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(k));
								valueBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetStrByIndex(k)); 
								break;

							case 'F':
								//printf("%20f", lpUnPacker->GetDoubleByIndex(k));
								//MessageBoxA(NULL,lpUnPacker->GetDoubleByIndex(k),"����",MB_OK);
								nameBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(k));
								sprintf(str,"%f",lpUnPacker->GetDoubleByIndex(k));
								valueBstr[t] = _com_util::ConvertStringToBSTR(str);
								break;

							case 'R':
								{
									int nLength = 0;
									void *lpData = lpUnPacker->GetRawByIndex(k, &nLength);

									// ��2�������ݽ��д���
									break;
								}

							default:
								// δ֪��������
								//printf("δ֪�������͡�\n");
								nameBstr[t] = _com_util::ConvertStringToBSTR(lpUnPacker->GetColName(k));
								valueBstr[t] = _com_util::ConvertStringToBSTR("δ֪��������");
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
				//MessageBoxA(0, (char *)Pointer, "����", 0);
				* ErrorMsg = _com_util::ConvertStringToBSTR((char *)Pointer);
				//nameBstr[0] = _com_util::ConvertStringToBSTR("ErrorMsg");
				//valueBstr[0] = _com_util::ConvertStringToBSTR((char *)Pointer);
				break;
			}

			case 3:
			{
				//MessageBoxA(0,"ҵ������ʧ��!", "����", 0);
				* ErrorMsg = _com_util::ConvertStringToBSTR("ҵ������ʧ��!");
				//nameBstr[0] = _com_util::ConvertStringToBSTR("ErrorMsg");
				//valueBstr[0] = _com_util::ConvertStringToBSTR("ҵ������ʧ��!");
				break;
			}
			default:
			{
				//MessageBoxA(0,lpConnection->GetErrorMsg(ret), "����", 0);
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
	// TODO: �ڴ����ʵ�ִ���
	
    lpConnection->Release();
    lpConfig->Release();
	return S_OK;
}




STDMETHODIMP CHsT2Com::AddFieldDef(BSTR szFieldName)
{
	// TODO: �ڴ����ʵ�ִ���
	pack->AddField(_com_util::ConvertBSTRToString(szFieldName));
	return S_OK;
}
