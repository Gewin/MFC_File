#include "stdafx.h"
#include "MP_ConfigFile.h"

LPCTSTR pszFileName= _T("MP_Config_File.ini");

CString strDefault[] = {_T("stb_provider      0x1008"),
						_T("operator_id       0x22"),
						_T("hw_id             0x8888"),
						_T("product_id        0x12345678"),
						_T("sw_id             0x010203"),
						_T("hw_model          0x12345678"),
						_T("sw_model          0x12345678"),
						_T("hw_config         0x123"),
						_T("year_week         0x1234"),
						_T("manufacturer_id   0x00000A"),
						_T("hw_version        QS05-701-00419_2.0"),
						_T("stb_sn            AVL41914120001"),
						_T("commond           1111")};

static int GetConfigValue(LPCTSTR name, LPTSTR value)
{
	int i;
	CString str, str1;
	int location = 0;
	bool findResult = false;
	CStdioFile myFile;
	CFileException fileException;
	if(!myFile.Open(pszFileName, CFile::typeText|CFile::modeRead, &fileException))
	{
		if(!myFile.Open(pszFileName, CFile::modeCreate|CFile::modeReadWrite, &fileException))   //Create new one and set default value
		{
			return -1;
		}
		for(i = 0; i < sizeof(strDefault) / sizeof(strDefault[0]) - 1; i++)
		{
			str = strDefault[i] + _T("\n");
			myFile.WriteString(str);
		}
		myFile.WriteString(strDefault[i]);  //The last line don't have "\n"
	}

	myFile.SeekToBegin();
	while(myFile.ReadString(str))
	{
		if((location = str.Find(SPACE_ASCII_CODE)) != -1)  //find the space
		{
			str1 = str.Left(location);
			if (0 == str1.CompareNoCase(name))  //The name is ok
			{
				str.Delete(0, location + 1);
				str.TrimLeft();   //Move all the left space
				findResult = true;
				break;
			}
			else
			{
				continue;
			}
		}
		else
		{
			continue;
		}
	}
	myFile.Close();
	if(findResult)
	{
		_tcscpy(value, str);
		return 0;
	}
	else
	{	
		return -1;
	}
}

static int SetConfigValue(LPCTSTR name, LPCTSTR value)
{
	int i;
	int location;
	CStringArray strArray;
	CString str, str1, str2;
	bool findResult = false;
	CStdioFile myFile;
	CFileException fileException;
	if(!myFile.Open(pszFileName, CFile::typeText | CFile::modeReadWrite, &fileException))
	{
		if(!myFile.Open(pszFileName, CFile::modeCreate | CFile::modeReadWrite, &fileException))   //Create new one and set default value
		{
			return -1;
		}
		for(i = 0; i < sizeof(strDefault) / sizeof(strDefault[0]) - 1; i++)
		{
			str = strDefault[i] + _T("\n");
			myFile.WriteString(str);
		}
		myFile.WriteString(strDefault[i]);  //The last line don't have "\n"
	}

	myFile.SeekToBegin();
	while(myFile.ReadString(str))
	{
		strArray.Add(str);
		if((location = str.Find(SPACE_ASCII_CODE)) != -1)  //find the space
		{
			str1 = str.Left(location);
			if (0 == str1.CompareNoCase(name))  //The name is ok
			{
				str2 = str;
				str2.Delete(0, location + 1);
				str2.TrimLeft();                //Get the value
				str.Replace(str2, value);       //Replace old value use new
				strArray.RemoveAt(strArray.GetSize() - 1);
				strArray.Add(str);
				findResult = true;
			}
			else
			{
				continue;
			}
		}
		else
		{
			strArray.RemoveAt(strArray.GetSize() - 1);   //Remove the line which don't conform to the format
			continue;
		}
	}
	myFile.Close();

	/* if not find the item, add new one */
	if(!findResult)
	{
		str.Format(_T("%s%s%s"), name, _T(" "), value);
		strArray.Add(str);
	}

	/* Write back to the file */
	if(!myFile.Open(pszFileName, CFile::modeCreate | CFile::modeReadWrite, &fileException))
	{
		return -1;
	}
	for(i = 0; i < strArray.GetSize() - 1; i++)
	{
		str = strArray[i] + _T("\n");
		myFile.WriteString(str);
	}
	myFile.WriteString(strArray[i]);  //The last line don't have "\n"

	myFile.Close();
	return 0;
}

int MPReadSTBProvider(LPTSTR value)
{
	int ret = 0;

	ret = GetConfigValue(_T("stb_provider"), value);
	if(ret)
	{
		return -1;
	}
	
	return 0;
}

int  MPWriteSTBProvider(LPCTSTR stbProvider)
{
	int ret = 0;

	ret = SetConfigValue(_T("stb_provider"), stbProvider);
	if(ret)
	{
		return -1;
	}

	return 0;
}

int MPReadOperatorId(LPTSTR value)
{
	int ret = 0;

	ret = GetConfigValue(_T("operator_id"), value);
	if(ret)
	{
		return -1;
	}
	
	return 0;
}

int MPWriteOperatorId(LPCTSTR operatorId)
{
	int ret = 0;

	ret = SetConfigValue(_T("operator_id"), operatorId);
	if(ret)
	{
		return -1;
	}

	return 0;
}

int MPReadHWId(LPTSTR value)
{
	int ret = 0;

	ret = GetConfigValue(_T("hw_id"), value);
	if(ret)
	{
		return -1;
	}
	
	return 0;
}

int  MPWriteHWId(LPCTSTR hwId)
{
	int ret = 0;

	ret = SetConfigValue(_T("hw_id"), hwId);
	if(ret)
	{
		return -1;
	}

	return 0;
}

int MPReadProductId(LPTSTR value)
{
	int ret = 0;

	ret = GetConfigValue(_T("product_id"), value);
	if(ret)
	{
		return -1;
	}
	
	return 0;
}

int  MPWriteProductId(LPCTSTR productId)
{
	int ret = 0;

	ret = SetConfigValue(_T("product_id"), productId);
	if(ret)
	{
		return -1;
	}

	return 0;
}

int MPReadSWId(LPTSTR value)
{
	int ret = 0;

	ret = GetConfigValue(_T("sw_id"), value);
	if(ret)
	{
		return -1;
	}
	
	return 0;
}

int  MPWriteSWId(LPCTSTR swId)
{
	int ret = 0;

	ret = SetConfigValue(_T("sw_id"), swId);
	if(ret)
	{
		return -1;
	}

	return 0;
}

int MPReadHWModel(LPTSTR value)
{
	int ret = 0;

	ret = GetConfigValue(_T("hw_model"), value);
	if(ret)
	{
		return -1;
	}
	
	return 0;
}

int MPWriteHWModel(LPCTSTR hwModel)
{
	int ret = 0;

	ret = SetConfigValue(_T("hw_model"), hwModel);
	if(ret)
	{
		return -1;
	}

	return 0;
}

int MPReadSWModel(LPTSTR value)
{
	int ret = 0;

	ret = GetConfigValue(_T("sw_model"), value);
	if(ret)
	{
		return -1;
	}
	
	return 0;
}

int  MPWriteSWModel(LPCTSTR swModel)
{
	int ret = 0;

	ret = SetConfigValue(_T("sw_model"), swModel);
	if(ret)
	{
		return -1;
	}

	return 0;
}

int MPReadHWConfig(LPTSTR value)
{
	int ret = 0;

	ret = GetConfigValue(_T("hw_config"), value);
	if(ret)
	{
		return -1;
	}
	
	return 0;
}

int  MPWriteHWConfig(LPCTSTR hwConfig)
{
	int ret = 0;

	ret = SetConfigValue(_T("hw_config"), hwConfig);
	if(ret)
	{
		return -1;
	}

	return 0;
}

int MPReadYearWeek(LPTSTR value)
{
	int ret = 0;

	ret = GetConfigValue(_T("year_week"), value);
	if(ret)
	{
		return -1;
	}
	
	return 0;
}

int  MPWriteYearWeek(LPCTSTR yearWeek)
{
	int ret = 0;

	ret = SetConfigValue(_T("year_week"), yearWeek);
	if(ret)
	{
		return -1;
	}

	return 0;
}

int MPReadManufacturerId(LPTSTR value)
{
	int ret = 0;

	ret = GetConfigValue(_T("manufacturer_id"), value);
	if(ret)
	{
		return -1;
	}
	
	return 0;
}

int  MPWriteManufacturerId(LPCTSTR manufacturerId)
{
	int ret = 0;

	ret = SetConfigValue(_T("manufacturer_id"), manufacturerId);
	if(ret)
	{
		return -1;
	}

	return 0;
}

int MPReadHWVersion(LPTSTR value)
{
	int ret = 0;

	ret = GetConfigValue(_T("hw_version"), value);
	if(ret)
	{
		return -1;
	}
	
	return 0;
}

int  MPWriteHWVersion(LPCTSTR hwVersion)
{
	int ret = 0;

	ret = SetConfigValue(_T("hw_version"), hwVersion);
	if(ret)
	{
		return -1;
	}

	return 0;
}

int MPReadSTBSN(LPTSTR value)
{
	int ret = 0;

	ret = GetConfigValue(_T("stb_sn"), value);
	if(ret)
	{
		return -1;
	}
	
	return 0;
}

int  MPWriteSTBSN(LPCTSTR stbSN)
{
	int ret = 0;

	ret = SetConfigValue(_T("stb_sn"), stbSN);
	if(ret)
	{
		return -1;
	}

	return 0;
}

int MPReadCommond(LPTSTR value)
{
	int ret = 0;

	ret = GetConfigValue(_T("commond"), value);
	if(ret)
	{
		return -1;
	}
	
	return 0;
}