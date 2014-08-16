#include "stdafx.h"
#include "DataExtractManager.h"
# include "HTTPAsyncDownloader.h"
# include "XMLParser.h"
# include "DataExtracter.h"

CDataExtractManager::CDataExtractManager():m_ptrdataStore(nullptr),m_ptrdownloader(nullptr),m_ptrparserObj(nullptr)
{

}

CDataExtractManager::~CDataExtractManager()
{
}

void CDataExtractManager::BuildDataExtracter(wstring filename,int /*eDataPolicyType*/, int /*eDataInputFormat*/)
{
	int nRet = -1; //unknown case define a enum type for errors; 
	/*based on the policy type and format create the policy and the parser Reset the pointers before assigning*/
	m_ptrdataStore = make_shared<CCDataContainer>();
	m_ptrDataPolicy = make_shared<CSplDataPolicy>();
	m_ptrparserObj = make_shared< CXMLParser>(m_ptrdataStore, m_ptrDataPolicy);
	m_ptrdownloader = make_shared<CHTTPAsyncDownloader>( new CFileSerialize(filename));
}

int CDataExtractManager::ExecuteDataExtracter(wstring strURL)
{
	m_dataExtracter.SetURL(strURL);
	m_dataExtracter.SetParser(m_ptrparserObj);
	m_dataExtracter.SetDownloader(m_ptrdownloader);
	if (false == m_dataExtracter.DownloadAndExtractData())
	{
		//Error case see if we can throw a better error to user by query the error
	}
	return m_ptrdataStore->getDataSize();
}

wstring CDataExtractManager::GetData()
{
   /*
   Run through the policy get the key and retrive the values and format : for now its done this way
   We can have a information expert to handle the action... 

   Instantiate the policy with the information expert and get the job done for the retrieve information. 
   */
   return L"";
}