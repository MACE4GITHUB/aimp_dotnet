﻿// ----------------------------------------------------
// 
// AIMP DotNet SDK
// 
// Copyright (c) 2014 - 2019 Evgeniy Bogdan
// https://github.com/martin211/aimp_dotnet
// 
// Mail: mail4evgeniy@gmail.com
// 
// ----------------------------------------------------
using System.Collections.Generic;

namespace AIMP.SDK.MusicLibrary.Extension.Command
{
    public interface IAimpDataStorageCommandReloadTags
    {
        AimpActionResult ReloadTags(IAimpFileList files);
    }
}