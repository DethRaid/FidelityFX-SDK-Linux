// This file is part of the FidelityFX SDK.
//
// Copyright (C) 2024 Advanced Micro Devices, Inc.
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "utils.h"
#include "utf8.h"

std::string WCharToUTF8(const std::wstring& wstr)
{
    if (wstr.empty())
        return std::string();

    // why are strings so cringe
    // i have wasted so much of my one human life dealing with this
    // i could be kissing girls but nooooooooo
    if constexpr (sizeof(wchar_t) == sizeof(char16_t)) {

        return utf8::utf16to8(std::u16string_view{reinterpret_cast<const char16_t*>(wstr.c_str()), wstr.size()});
    } else if constexpr (sizeof(wchar_t) == sizeof(char32_t)) {
        return utf8::utf32to8(std::u32string_view{reinterpret_cast<const char32_t*>(wstr.c_str()), wstr.size()});

    } else {
        throw std::runtime_error{"strings are cringe"};
    }
}

std::wstring UTF8ToWChar(const std::string& str)
{
    if (str.empty())
        return std::wstring();

    if constexpr (sizeof(wchar_t) == sizeof(char16_t)) {
        const auto u16str = utf8::utf8to16(str);
        return std::wstring{reinterpret_cast<const wchar_t*>(u16str.c_str()), u16str.size()};

    } else if constexpr (sizeof(wchar_t) == sizeof(char32_t)) {
        const auto u32str = utf8::utf8to32(str);
        return std::wstring{reinterpret_cast<const wchar_t*>(u32str.c_str()), u32str.size()};

    } else {
        throw std::runtime_error{"strings are cringe"};
    }
}
