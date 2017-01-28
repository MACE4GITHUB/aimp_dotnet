/*
 * AIMP DotNet SDK
 * 
 * (C) 2017
 * Mail: mail4evgeniy@gmail.com
 * https://github.com/martin211/aimp_dotnet
 * 
 */
#include "Stdafx.h"
#include "AimpObjectList.h"

using namespace AIMP::SDK;

generic<typename T>
AimpObjectList<T>::AimpObjectList(IAIMPObjectList* nativeObject)
{
    _nativeObject = nativeObject;
}

generic<typename T>
AimpActionResult AimpObjectList<T>::Add(T entry)
{
    return Utils::CheckResult(_nativeObject->Add(AimpConverter::ToAimpString((String^)entry)));
}

generic<typename T>
AimpActionResult AimpObjectList<T>::Clear()
{
    return Utils::CheckResult(_nativeObject->Clear());
}

generic<typename T>
AimpActionResult AimpObjectList<T>::Delete(int index)
{
    return Utils::CheckResult(_nativeObject->Delete(index));
}

generic<typename T>
AimpActionResult AimpObjectList<T>::Insert(int index, T entry)
{
    return Utils::CheckResult(_nativeObject->Insert(index, AimpConverter::ToAimpString((String^)entry)));
}

generic<typename T>
int AimpObjectList<T>::Count::get()
{
    return _nativeObject->GetCount();
}

generic<typename T>
AimpActionResult AimpObjectList<T>::GetObject(int index, T% item)
{
    IAIMPString* str;
    AimpActionResult result = Utils::CheckResult(_nativeObject->GetObject(index, IID_IAIMPString, (void**)&str));

    if (result == AimpActionResult::Ok && str != NULL)
    {
        item = (T)AimpConverter::ToManagedString(str);
        str->Release();
        str = NULL;
    }

    return result;
}

generic<typename T>
AimpActionResult AimpObjectList<T>::SetObject(int index, T item)
{
    return Utils::CheckResult(_nativeObject->SetObject(index, AimpConverter::ToAimpString((String^)item)));
}

