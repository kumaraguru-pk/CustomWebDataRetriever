#include "stdafx.h"
#include "DataExtracter.h"


CDataExtracter::CDataExtracter()
{
}

CDataExtracter::~CDataExtracter()
{
}

void CDataExtracter::SetParser(shared_ptr<IParser> ParserObj)
{
	m_ParserObj = ParserObj;
}
void CDataExtracter::SetDownloader(shared_ptr<IAsyncDownloader> downloader)
{
	m_downloaderObj = downloader;
}
void CDataExtracter::SetURL( wstring strInputURL)
{
	m_strInputURL = strInputURL;
}

void CDataExtracter::SetFileName(wstring strFileName)
{
	m_strFileName = strFileName;
}

int CDataExtracter::DownloadAndExtractData()
{
	int nRet = -1;
	if (!m_downloaderObj && !m_ParserObj )
	{
		if (-1 != (nRet = m_downloaderObj->download(m_strInputURL)))
		{
			nRet = m_ParserObj->ExtractData(m_downloaderObj->getName());
		}
	}
	return nRet;
}