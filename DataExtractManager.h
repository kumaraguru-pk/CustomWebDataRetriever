#pragma once
# include "stdafx.h"
# include "DataExtracter.h"
# include "CDataContainer.h"

typedef shared_ptr<CCDataContainer> sharedDataContainer;
typedef shared_ptr<IParser> sharedParser;
typedef shared_ptr<IAsyncDownloader> sharedDownloader;
typedef shared_ptr<IDataPolicy> sharedDataPolicy;
typedef shared_ptr<ISerializer> sharedSerializer;

class CDataExtractManager
{
public:
	CDataExtractManager();
	~CDataExtractManager();
	/*
	 This can be converted into a factory  or use some other technique to inject the dependencies
	*/
	void BuildDataExtracter(wstring filename, int /*eType*/, int /*eFormat*/);	
	int ExecuteDataExtracter(wstring strURL);

	wstring GetData( );
private:
	CDataExtracter m_dataExtracter;
	sharedDataContainer m_ptrdataStore;
	sharedParser m_ptrparserObj;
	sharedDownloader m_ptrdownloader;
	sharedDataPolicy m_ptrDataPolicy;
	sharedSerializer m_ptrDataSerializer;
};

