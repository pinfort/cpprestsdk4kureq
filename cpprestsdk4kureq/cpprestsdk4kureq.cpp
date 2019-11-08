// cpprestsdk4kureq.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

wchar_t* HttpGet(const wchar_t* host_name, const wchar_t* path)
{
	http_client client(host_name);

	uri_builder builder(path);

	Concurrency::task<web::http::http_response> fetchTask = client.request(methods::GET, builder.to_string());

	web::http::http_response response = fetchTask.get();
	
	std::wstring result = response.to_string();
	const wchar_t* returnVal = result.c_str();

	return (wchar_t*)returnVal;
}
