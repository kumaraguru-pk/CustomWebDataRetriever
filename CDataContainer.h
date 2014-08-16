#pragma once
# include "stdafx.h"

class CCDataContainer
{
public:
	CCDataContainer() { }
	~CCDataContainer(){ }
private:
   map< wstring, wstring> m_csKeyValueMap;

public:
	void setkeyValue( wstring key, wstring value)
	{
		m_csKeyValueMap[key] = value;
	}	
	wstring getData(wstring csKey)
	{
	   return m_csKeyValueMap[csKey];
	}

	int getDataSize()
	{
	   return m_csKeyValueMap.size();
	}
};