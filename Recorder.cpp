/***
* ==++==
*
* Copyright (c) Microsoft Corporation. All rights reserved. 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* ==--==
* =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
*
* Dealer.cpp : Contains the main logic of the black jack dealer
*
* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
****/

#include "stdafx.h"

using namespace std;
using namespace web; 
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;


class WMIRecorder
{
public:
    WMIRecorder() { }
    WMIRecorder(utility::string_t url);

    pplx::task<void> open() { return m_listener.open(); }
    pplx::task<void> close() { return m_listener.close(); }

private:

    void handle_get(http_request message);
    void handle_put(http_request message);
    void handle_post(http_request message);
    void handle_delete(http_request message);
    
    http_listener m_listener;   
};

WMIRecorder::WMIRecorder(utility::string_t url) : m_listener(url)
{
    m_listener.support(methods::GET, std::bind(&WMIRecorder::handle_get, this, std::placeholders::_1));
    m_listener.support(methods::PUT, std::bind(&WMIRecorder::handle_put, this, std::placeholders::_1));
    m_listener.support(methods::POST, std::bind(&WMIRecorder::handle_post, this, std::placeholders::_1));
    m_listener.support(methods::DEL, std::bind(&WMIRecorder::handle_delete, this, std::placeholders::_1));
    
}

//
// A GET of the dealer resource produces a list of existing tables.
// 
void WMIRecorder::handle_get(http_request message)
{
    
};

//
// A POST of the dealer resource creates a new table and returns a resource for
// that table.
// 
void WMIRecorder::handle_post(http_request message)
{
    
};

//
// A DELETE of the player resource leaves the table.
// 
void WMIRecorder::handle_delete(http_request message)
{
  
};


//
// A PUT to a table resource makes a card request (hit / stay).
// 
void WMIRecorder::handle_put(http_request message)
{
  
};
