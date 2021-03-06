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

#pragma once
#include "SDK\BaseManager.h"

namespace AIMP
{
    namespace SDK
    {
        using namespace Windows::Input;
        using namespace SDK;
        using namespace ActionManager;

        [System::Serializable]
        public ref class AimpActionManager :
            public AimpBaseManager<IAIMPServiceActionManager>,
            public IAimpServiceActionManager
        {
        public:
            explicit AimpActionManager(ManagedAimpCore^ core);

            virtual AimpActionResult GetById(String^ id, IAimpAction^% action);

            virtual int MakeHotkey(ModifierKeys modifiers, unsigned int key);

            virtual AimpActionResult Register(IAimpAction^ action);

            virtual AimpActionResult Register(Generic::ICollection<IAimpAction^>^ actions);

            virtual IAimpAction^ CreateAction();
        };
    }
}
