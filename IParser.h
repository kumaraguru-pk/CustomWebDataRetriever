#pragma once
# include "stdafx.h"
# include "CDataContainer.h"
# include "IDataPolicy.h"

class IParser
{
public:
	IParser(shared_ptr<CCDataContainer> ptrStor, shared_ptr<IDataPolicy> ptrPolicy) : m_IOCDataStoreObj(ptrStor), m_IOCDataPolicy(ptrPolicy)
	{
	}
	virtual ~IParser() = 0
	{
	}
	bool ExtractData(wstring filename)
	{
		return extractData(filename);
	}

	void ResetDataPolicy(CCDataContainer *ptr)
	{
		m_IOCDataStoreObj.reset(ptr);
	}

	void ResetContainer(IDataPolicy *ptr)
	{
		m_IOCDataPolicy.reset(ptr);
	}

protected:
	shared_ptr<CCDataContainer> GetDataContainer(){ return m_IOCDataStoreObj; }
	shared_ptr<IDataPolicy> GetDataPolicy() { return m_IOCDataPolicy; }

private:
   virtual bool extractData(wstring filename) = 0;
   shared_ptr<CCDataContainer> m_IOCDataStoreObj;
   shared_ptr<IDataPolicy> m_IOCDataPolicy;
};