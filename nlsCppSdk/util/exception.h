/*
 * Copyright 2015 Alibaba Group Holding Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef NLS_SDK_EXCEPTION_H
#define NLS_SDK_EXCEPTION_H

#include <string>
#include <stdexcept>

namespace util {

#if defined(_WIN32)
#ifndef  ASR_API
#define ASR_API _declspec(dllexport)
#endif
#else
#define ASR_API
#endif

class ExceptionWithString {
public:
    ExceptionWithString(std::string const &msg, int errorcode);
    ExceptionWithString(std::wstring const &msg, int errorcode, std::wstring miniDumpFileFullPath = L"");

    std::wstring GetMiniDumpFilePath();
    const char *what();
    int getErrorcode();

private:
    std::wstring wstr;
    std::string _errormsg;
    int _errcode;
};
}

#endif //NLS_SDK_EXCEPTION_H
