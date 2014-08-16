#pragma once

# include "stdafx.h"
# include "IAsyncDownloader.h"

class CHTTPAsyncDownloader :public IAsyncDownloader
{
public:
	CHTTPAsyncDownloader(ISerializer *ptrSerializer);
	virtual ~CHTTPAsyncDownloader();

public:
	unsigned short download(wstring URL, wstring responseStr);

private:
	bool breakURL();
	
};

