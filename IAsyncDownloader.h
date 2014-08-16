#pragma once
# include "stdafx.h"


#include <cpprest\http_client.h>

using namespace web::http;
using namespace web::http::client;
using namespace Concurrency;


enum edataDLSerializeOption
{
	edataDLSLfilestream = 0
};

class ISerializer
{
public:

	ISerializer(wstring csName) :m_strname(csName)
	{

	}
	virtual ~ISerializer() = 0
	{
	}
	/* Bad assumption to get always as string , what about binaries?*/
	int Serialize( wstring input)
	{
		return write(input);
	}

	wstring getName()
	{
		return m_strname;
	}
protected:
	wstring m_strname;
private:
	virtual int write(wstring input) = 0;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CFileSerialize : public ISerializer
{
public:
	CFileSerialize(wstring name) : ISerializer(name)
	{

	}

	~CFileSerialize()
	{

	}

private:
	int write(wstring input)
	{
		//Define enums for all the errors
		int nRet = 0;
		try
		{
			wfstream fileserializer(m_strname);
			fileserializer << input;
			nRet = 1;
		}
		catch (wfstream::failure e)
		{
			/// Some failure while writing into the file. 
			nRet = -1;
		}

		return nRet;
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class IAsyncDownloader
{
public:
	IAsyncDownloader(ISerializer *ptrSerializer) :m_strConnectionURL(L""), m_strConnectionBaseURI(L""), 
		m_strQueryValue(L""), m_strReasonPhrase(L""),
		m_lResponseCode(0), m_uniqSerializePtr(ptrSerializer)
	{
	}
	virtual ~IAsyncDownloader() = 0
	{
	}
	void resetSerializer(ISerializer *ptr)
	{
		m_uniqSerializePtr.reset(ptr);
	}

	wstring getName()
	{
		return m_uniqSerializePtr->getName();
	}
	unsigned short download(wstring URL)
	{
		m_strConnectionURL = URL;
		status_code nRet = 0;
		if (false != breakURL())
		{
			nRet = downloadAsync().get();
			/*
			See if we can pass the status using another async function through a callback or an observer
			Based on the error code and the response code customize the message and return appropriate error
			code Please define an enum for all the possible error
			*/
		}
		else
		{
			nRet = -1; // retrived the reason phrase and set it 
		}
		return nRet;
	}

protected:
	wstring m_strConnectionURL;
	wstring m_strConnectionBaseURI;
	wstring m_strQueryValue;
	wstring m_strReasonPhrase;
	long m_lResponseCode;
	unique_ptr<ISerializer> m_uniqSerializePtr;
private:
	virtual bool breakURL() = 0;
	virtual pplx::task<status_code> downloadAsync( )
	{
			http_client httpClient(m_strConnectionBaseURI);
			wstring request(m_strQueryValue);
			return httpClient.request(web::http::methods::GET, request).then([&](http_response resp)
			{	m_lResponseCode = resp.error_code();				
				m_uniqSerializePtr->Serialize(resp.extract_string().get());
				return resp.status_code();
			});
	}

};