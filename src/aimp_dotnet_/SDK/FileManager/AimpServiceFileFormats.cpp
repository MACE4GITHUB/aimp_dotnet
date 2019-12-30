// ----------------------------------------------------
// 
// AIMP DotNet SDK
// 
// Copyright (c) 2014 - 2019 Evgeniy Bogdan
// https://github.com/martin211/aimp_dotnet
// 
// Mail: mail4evgeniy@gmail.com
// 
// ----------------------------------------------------

#include "Stdafx.h"
#include "AimpServiceFileFormats.h"

using namespace AIMP::SDK;

AimpServiceFileFormats::AimpServiceFileFormats(ManagedAimpCore^ core) : BaseAimpService<IAIMPServiceFileFormats>(core)
{
}

AimpActionResult AimpServiceFileFormats::GetFormats(FileFormats flags, String^% formats)
{
    IAIMPServiceFileFormats* service = GetAimpService();
    AimpActionResult result = AimpActionResult::Fail;
    IAIMPString* str = nullptr;
    formats = nullptr;

    try
    {
        if (service != nullptr)
        {
            result = CheckResult(service->GetFormats(DWORD(flags), &str));

            if (result == AimpActionResult::OK)
            {
                formats = AimpConverter::ToManagedString(str);
            }
        }
    }
    finally
    {
        ReleaseObject(service);
        ReleaseObject(str);
    }

    return result;
}

AimpActionResult AimpServiceFileFormats::IsSupported(String^ fileName, FileFormats flags)
{
    IAIMPServiceFileFormats* service = GetAimpService();
    AimpActionResult result = AimpActionResult::Fail;
    IAIMPString* str = nullptr;

    try
    {
        if (service != nullptr)
        {
            str = AimpConverter::ToAimpString(fileName);
            result = CheckResult(service->IsSupported(str, DWORD(flags)));
        }
    }
    finally
    {
        ReleaseObject(service);
        ReleaseObject(str);
    }

    return result;
}

IAIMPServiceFileFormats* AimpServiceFileFormats::GetAimpService()
{
    IAIMPServiceFileFormats* service = nullptr;
    GetService(IID_IAIMPServiceFileFormats, &service);
    return service;
}