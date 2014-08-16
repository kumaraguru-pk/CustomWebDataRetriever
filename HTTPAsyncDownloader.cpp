#include "stdafx.h"
#include "HTTPAsyncDownloader.h"

CHTTPAsyncDownloader::CHTTPAsyncDownloader(ISerializer *ptrSerializer) :IAsyncDownloader(ptrSerializer)
{

}


CHTTPAsyncDownloader::~CHTTPAsyncDownloader()
{

}


/**
* This URL Break function just applies split on the first occuring ?/ character. It is not a generic function but serves the purpose for now to break the incoming URL
Can be improved.
?bn=1&bv=32.0.1700.102&clientv=48&cltzone=-480&csk=10051379387070890408-10171740824258180982&language=en,en&method=get_offers&mstime=0.157&os=WIN6.3-64&product_key=748ad6d80864338c9c03b664839d8161&v=1.0&signature=904f3bfbd9e8ce24e58203913828e195
*
This can also be part of the datapolicy and have the parser to do this job in the future */

bool CHTTPAsyncDownloader::breakURL()
{
	bool bRet = false;
	int nPos = m_strConnectionURL.find( L"?bn" );
	if (nPos > 0)
	{
		m_strQueryValue = m_strConnectionURL.substr(nPos);
		m_strConnectionBaseURI = m_strConnectionURL.substr(0, nPos);
		bRet = true;
	}
	return bRet;
}





