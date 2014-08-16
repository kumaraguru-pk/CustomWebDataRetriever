# pragma once
# include "stdafx.h"
# include "HTTPAsyncDownloader.h"
# include "IParser.h"

class CDataExtracter
{	
public:
	CDataExtracter();
	~CDataExtracter();

private:
	shared_ptr<IAsyncDownloader> m_downloaderObj;
	shared_ptr<IParser>  m_ParserObj;
	wstring m_strInputURL;
	wstring m_strFileName;

public:
	void SetParser(shared_ptr<IParser> ParserObj);
	void SetDownloader(shared_ptr<IAsyncDownloader> downloader);
	void SetURL( wstring strInputURL);	
	void SetFileName(wstring strFileName);
	int DownloadAndExtractData();
};


