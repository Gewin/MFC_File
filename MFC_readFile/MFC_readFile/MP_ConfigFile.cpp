#include "stdafx.h"
#include "MP_ConfigFile.h"

char *pszFileName="MP_Config_File.ini";

static int GetConfigValue(char *name, char *value)
{
	int location;
	CStdioFile myFile;
	CFileException fileException;
	if(!myFile.Open(pszFileName, CFile::typeText|CFile::modeRead, &fileException))
	{
		printf("Read file error!");
		return -1;
	}

	myFile.SeekToBegin();
	CString str, str1;
	while(myFile.ReadString(str))
	{
        printf("Get string = %s\n", str);
		if((location = str.Find(_T(32))) != -1)  //find the space
		{
			str1 = str.Left(location);
			if (0 == str1.CompareNoCase(name))  //The name is ok
			{
				str.Delete(0, location + 1);
				str.TrimLeft();   //Move the all left space
				break;
			}
			else
			{
				continue;
			}
		}
		else
		{
			printf("The string is not confirm the rule\n");
			continue;
		}
	}
	memcpy(value, (LPSTR)(LPCTSTR)str, 20);
	//value = (LPSTR)(LPCTSTR)str;
	myFile.Close();
	return 0;
}

static int SetConfigValue(char *name, char *value)
{
	int location, totalLength = 0;
	CStdioFile myFile;
	CFileException fileException;
	if(!myFile.Open(pszFileName, CFile::typeText|CFile::modeReadWrite, &fileException))
	{
		return -1;
	}

	myFile.SeekToBegin();
	CString str, str1, str2;
	while(myFile.ReadString(str))
	{
		totalLength += str.GetLength();
		if((location = str.Find(_T(32))) != -1)  //find the space
		{
			str1 = str.Left(location);
			if (0 == str1.CompareNoCase(name))  //The name is ok
			{
				str2.Format(_T("%s %s"), str1, value);  
				myFile.Seek(totalLength - str.GetLength(), CFile::begin);
				myFile.WriteString(_T("\n"));
				myFile.WriteString(str2);
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
	return 0;
}

int MPReadSTBProvider(char *value)
{
	int ret = 0;

	ret = GetConfigValue("stb_provider", value);
	if(ret)
	{
		printf("Get value error\n");
		return -1;
	}
	
	return 0;
}

int  MPWriteSTBProvider(char *stbProvider)
{
	int ret = 0;

	ret = SetConfigValue("stb_provider", stbProvider);

	return 0;

}