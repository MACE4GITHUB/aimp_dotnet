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
#include "AimpServiceMusicLibrary.h"
#include "AimpDataStorage.h"
#include "AimpGroupingPresets.h"

using namespace AIMP::SDK;

AimpActionResult AimpServiceMusicLibrary::GetActiveStorage(IAimpDataStorage^% storage)
{
    IAIMPServiceMusicLibrary* service = GetAimpService();
    AimpActionResult result = AimpActionResult::Fail;
    storage = nullptr;

    try
    {
        if (service != nullptr)
        {
            IAIMPMLDataStorage* aimpStorage = nullptr;
            result = CheckResult(
                service->GetActiveStorage(IID_IAIMPMLDataStorage, reinterpret_cast<void**>(&aimpStorage)));
            if (result == AimpActionResult::OK && aimpStorage != nullptr)
            {
                storage = gcnew AimpDataStorage(aimpStorage);
            }
        }
    }
    finally
    {
        ReleaseObject(service);
    }

    return result;
}

AimpActionResult AimpServiceMusicLibrary::GetActiveStorage(IAimpGroupingPresets^% presets)
{
    IAIMPServiceMusicLibrary* service = GetAimpService();
    AimpActionResult result = AimpActionResult::Fail;
    presets = nullptr;

    try
    {
        if (service != nullptr)
        {
            IAIMPMLGroupingPresets* aimpPresets = nullptr;
            result = CheckResult(
                service->GetActiveStorage(IID_IAIMPMLGroupingPresets, reinterpret_cast<void**>(&aimpPresets)));
            if (result == AimpActionResult::OK && aimpPresets != nullptr)
            {
                presets = gcnew AimpGroupingPresets(aimpPresets);
            }
        }
    }
    finally
    {
        ReleaseObject(service);
    }

    return result;
}

AimpActionResult AimpServiceMusicLibrary::SetActiveStorage(IAimpDataStorage^ storage)
{
    IAIMPServiceMusicLibrary* service = GetAimpService();
    const AimpActionResult result = AimpActionResult::Fail;

    try
    {
        // TODO complete it
        if (service != nullptr)
        {
            IAIMPMLGroupingPresets* storage;
            //result = CheckResult(service->SetActiveStorage(IID_IAIMPMLGroupingPresets));
        }
    }
    finally
    {
        ReleaseObject(service);
    }

    return result;
}

AimpActionResult AimpServiceMusicLibrary::SetActiveStorage(IAimpGroupingPresets^ preset)
{
    IAIMPServiceMusicLibrary* service = GetAimpService();
    const AimpActionResult result = AimpActionResult::Fail;

    try
    {
        // TODO complete it
        if (service != nullptr)
        {
            IAIMPMLGroupingPresets* storage;
            //result = CheckResult(service->SetActiveStorage(IID_IAIMPMLGroupingPresets));
        }
    }
    finally
    {
        ReleaseObject(service);
    }

    return result;
}

AimpActionResult AimpServiceMusicLibrary::GetStorage(int index, IAimpDataStorage^% storage)
{
    IAIMPServiceMusicLibrary* service = GetAimpService();
    AimpActionResult result = AimpActionResult::Fail;
    storage = nullptr;

    try
    {
        if (service != nullptr)
        {
            IAIMPMLDataStorage* aimpStorage = nullptr;
            result = CheckResult(service->GetStorage(index, IID_IAIMPMLDataStorage,
                                                     reinterpret_cast<void**>(&aimpStorage)));
            if (result == AimpActionResult::OK && aimpStorage != nullptr)
            {
                storage = gcnew AimpDataStorage(aimpStorage);
            }
        }
    }
    finally
    {
        ReleaseObject(service);
    }

    return result;
}

AimpActionResult AimpServiceMusicLibrary::GetStorage(int index, IAimpGroupingPresets^% storage)
{
    IAIMPServiceMusicLibrary* service = GetAimpService();
    AimpActionResult result = AimpActionResult::Fail;

    try
    {
        if (service != nullptr)
        {
            IAIMPMLGroupingPresets* aimpPresets = nullptr;
            result = CheckResult(service->GetStorage(index, IID_IAIMPMLGroupingPresets,
                                                     reinterpret_cast<void**>(&aimpPresets)));

            if (result == AimpActionResult::OK && aimpPresets != nullptr)
            {
                storage = gcnew AimpGroupingPresets(aimpPresets);
            }
        }
    }
    finally
    {
        ReleaseObject(service);
    }

    return result;
}

AimpActionResult AimpServiceMusicLibrary::GetStorageById(String^ id, IAimpDataStorage^% storage)
{
    IAIMPServiceMusicLibrary* service = GetAimpService();
    AimpActionResult result = AimpActionResult::Fail;
    IAIMPString* aimpId = nullptr;
    storage = nullptr;

    try
    {
        if (service != nullptr)
        {
            IAIMPMLDataStorage* aimpStorage = nullptr;
            aimpId = AimpConverter::ToAimpString(id);
            result = CheckResult(
                service->GetStorageByID(aimpId, IID_IAIMPMLDataStorage, reinterpret_cast<void**>(&aimpStorage)));

            if (result == AimpActionResult::OK && aimpStorage != nullptr)
            {
                storage = gcnew AimpDataStorage(aimpStorage);
            }
        }
    }
    finally
    {
        ReleaseObject(service);
    }

    return result;
}

AimpActionResult AimpServiceMusicLibrary::GetStorageById(String^ id, IAimpGroupingPresets^% storage)
{
    IAIMPServiceMusicLibrary* service = GetAimpService();
    AimpActionResult result = AimpActionResult::Fail;
    IAIMPString* aimpId = nullptr;
    storage = nullptr;

    try
    {
        if (service != nullptr)
        {
            IAIMPMLGroupingPresets* aimpStorage = nullptr;
            aimpId = AimpConverter::ToAimpString(id);
            result = CheckResult(service->GetStorageByID(aimpId, IID_IAIMPMLGroupingPresets,
                                                         reinterpret_cast<void**>(&aimpStorage)));

            if (result == AimpActionResult::OK && aimpStorage != nullptr)
            {
                storage = gcnew AimpGroupingPresets(aimpStorage);
            }
        }
    }
    finally
    {
        ReleaseObject(service);
    }

    return result;
}

int AimpServiceMusicLibrary::GetStorageCount()
{
    IAIMPServiceMusicLibrary* service = GetAimpService();

    try
    {
        if (service != nullptr)
        {
            return service->GetStorageCount();
        }
    }
    finally
    {
        ReleaseObject(service);
    }

    return 0;
}

IAIMPServiceMusicLibrary* AimpServiceMusicLibrary::GetAimpService()
{
    IAIMPServiceMusicLibrary* service = nullptr;
    GetService(IID_IAIMPServiceMusicLibrary, &service);
    return service;
}