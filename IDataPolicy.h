#pragma once
#pragma once
# include "stdafx.h"


class IDataPolicy
{
public:
   IDataPolicy( )
   {
   }

  virtual ~IDataPolicy()= 0
   {
   }
protected:
	wstring m_csSectionName;
	vector<wstring> m_csKeyArray;
	int m_nKeysLength;
	wstring m_dataExtractPolicy;

public:
	wstring GetSectionName()
	{
	   return m_csSectionName;
	}

	int GetKeyLen()
	{
	   return m_nKeysLength;
	}
	wstring GetKey(int nKey) 
	{ 
	   return ( nKey < 0 || nKey > m_nKeysLength)? emptyStr : m_csKeyArray[nKey];	 
	}    
};

/*

This can be built at run time if we apply xml serialization for rule types so that rules can change over the time. 
*/
class CSplDataPolicy:public IDataPolicy
{
public:
   CSplDataPolicy( )
   {
	  m_csSectionName= L"offer";
	  m_csKeyArray.push_back( L"name" );
	  m_csKeyArray.push_back( L"package_md5" );	
	  m_dataExtractPolicy = L"Product Update Data Policy";
	  m_nKeysLength = 2;
   }
};