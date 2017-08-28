﻿// ----------------------------------------------------
// 
// AIMP DotNet SDK
//  
// Copyright (c) 2014 - 2017 Evgeniy Bogdan
// https://github.com/martin211/aimp_dotnet
// 
// Mail: mail4evgeniy@gmail.com
// 
// ----------------------------------------------------

using AIMP.SDK.ActionManager;

namespace AIMP.SDK.MusicLibrary
{
    /// <summary>
    /// Uses for notify library about changes at data storage.
    /// </summary>
    public interface IAimpDataStorageManager
    {
        /// <summary>
        /// Notifies about the background task that has been started.
        /// </summary>
        /// <param name="id">The identifier.</param>
        /// <param name="caption">The caption.</param>
        /// <param name="cancelEvent">The cancel event.</param>
        AimpActionResult BackgroundTaskStarted(int id, string caption, IAimpActionEvent cancelEvent);

        /// <summary>
        /// Notifies about the background task that has been finished.
        /// </summary>
        /// <param name="id">The identifier.</param>
        AimpActionResult BackgroundTaskFinished(int id);

        /// <summary>
        /// Changeds this instance.
        /// </summary>
        void Changed();
    }
}