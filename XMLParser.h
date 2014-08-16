#pragma once

# include "stdafx.h"
# include "IParser.h"
#include "XMLParser.h"
# include <xmllite.h>
# include <Shlwapi.h>
# include <sstream>
#include <fstream>

class CXMLParser :public IParser
{
public:
	CXMLParser(shared_ptr<CCDataContainer> dataFormat, shared_ptr<IDataPolicy> policy);
	~CXMLParser();	
 private:
	bool isNodeInKeys( wstring strNodeName);
	bool extractData( wstring filename);
};


