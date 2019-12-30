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

#include "SDK\ManagedAimpCore.h"

namespace AIMP
{
    namespace SDK
    {
        using namespace AIMP::SDK;

        template <typename TAimpService>
        [System::Serializable]
        public ref class BaseAimpService abstract : IAimpService
        {
        private:
            bool _isExist;
        public:
            BaseAimpService(ManagedAimpCore^ core)
            {
                _core = core;
                _isExist = false;
            }

        protected:
            AimpActionResult CheckResult(HRESULT result)
            {
                const AimpActionResult res = Utils::CheckResult(result);
                if (res != AimpActionResult::OK)
                {
                    //AIMP::SDK::InternalLogger::Instance->Write("Invalid operation: result " + result);
                }

                return res;
            }

            AimpActionResult GetService(const IID id, TAimpService** service)
            {
                TAimpService* s = nullptr;
                const AimpActionResult result = CheckResult(_core->GetService(id, reinterpret_cast<void**>(&s)));

                if (result == AimpActionResult::OK && s != nullptr)
                {
                    *service = s;
                    _isExist = true;
                }

                return result;
            }

            void ReleaseObject(IUnknown* object)
            {
                if (object != nullptr)
                {
                    object->Release();
                    object = nullptr;
                }
            }

            virtual TAimpService* GetAimpService() = 0;

        public:
            property bool IsExists
            {
                virtual bool get()
                {
                    return _isExist;
                }
            }
        protected:
            ManagedAimpCore^ _core;
        };
    }
}