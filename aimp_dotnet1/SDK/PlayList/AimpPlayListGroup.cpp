#include "Stdafx.h"
#include "AimpPlayListGroup.h"
#include "AimpPlayListItem.h"
#include "..\..\ObjectHelper.h"

namespace AIMP
{
	namespace SDK
	{
		using namespace AIMP::SDK::Services::PlayList;

		AimpPlayListGroup::AimpPlayListGroup()
		{
			IAIMPPlaylistGroup *group = (IAIMPPlaylistGroup*)ManagedAimpCore::QueryInterface(IID_IAIMPPlaylistGroup);
		}

		AimpPlayListGroup::AimpPlayListGroup(IAIMPPlaylistGroup *item) : AimpObject(item)
		{
		}

		System::String^ AimpPlayListGroup::Name::get()
		{
			return ObjectHelper::GetString(InternalAimpObject, AIMP_PLAYLISTGROUP_PROPID_NAME);
		}

		bool AimpPlayListGroup::Expanded::get()
		{
			return ObjectHelper::GetBool(InternalAimpObject, AIMP_PLAYLISTGROUP_PROPID_EXPANDED);
		}

		void AimpPlayListGroup::Expanded::set(bool value)
		{
			ObjectHelper::SetBool(InternalAimpObject, AIMP_PLAYLISTGROUP_PROPID_EXPANDED, value);
		}

		double AimpPlayListGroup::Duration::get()
		{
			return ObjectHelper::GetFloat(InternalAimpObject, AIMP_PLAYLISTGROUP_PROPID_DURATION);
		}

		void AimpPlayListGroup::Duration::set(double value)
		{
			ObjectHelper::SetFloat(InternalAimpObject, AIMP_PLAYLISTGROUP_PROPID_DURATION, value);
		}

		int AimpPlayListGroup::Index::get()
		{
			return ObjectHelper::GetInt32(InternalAimpObject, AIMP_PLAYLISTGROUP_PROPID_INDEX);
		}

		bool AimpPlayListGroup::Selected::get()
		{
			return ObjectHelper::GetBool(InternalAimpObject, AIMP_PLAYLISTGROUP_PROPID_SELECTED);
		}

		void AimpPlayListGroup::Selected::set(bool value)
		{
			ObjectHelper::SetBool(InternalAimpObject, AIMP_PLAYLISTGROUP_PROPID_SELECTED, value);
		}

		int AimpPlayListGroup::Count::get()
		{
			return InternalAimpObject->GetItemCount();
		}

		IAimpPlayListItem ^AimpPlayListGroup::GetItem(int index)
		{
			if (_item == nullptr)
			{
				IAIMPPlaylistItem *item;
				InternalAimpObject->GetItem(index, IID_IAIMPPlaylistItem, (void**)&item);
				_item = gcnew AimpPlayListItem(item);
			}

			return _item;
		}
	}
}