#include "Stdafx.h"
#include "AimpPlaybackQueueItem.h"

using namespace AIMP::SDK;

AimpPlaybackQueueItem::AimpPlaybackQueueItem(IAIMPPlaybackQueueItem *aimpItem) : AimpObject(aimpItem)
{
}

Object^ AimpPlaybackQueueItem::UserData::get()
{
    IUnknown *item = NULL;
    InternalAimpObject->GetValueAsObject(AIMP_PLAYBACKQUEUEITEM_PROPID_CUSTOM, IID_IUnknown, (void**)&item);
    return System::Runtime::InteropServices::Marshal::GetObjectForIUnknown(IntPtr(item));
}

void AimpPlaybackQueueItem::UserData::set(Object^ value)
{
    throw gcnew System::NotImplementedException("Not implemented");
}

IAimpPlayListItem^ AimpPlaybackQueueItem::PlayListItem::get()
{
    IAIMPPlaylistItem *item;
    InternalAimpObject->GetValueAsObject(AIMP_PLAYBACKQUEUEITEM_PROPID_PLAYLISTITEM, IID_IAIMPPlaylistItem, (void**)&item);
    return gcnew AimpPlayListItem(item);
}

void AimpPlaybackQueueItem::PlayListItem::set(IAimpPlayListItem^ value)
{
    InternalAimpObject->SetValueAsObject(AIMP_PLAYBACKQUEUEITEM_PROPID_PLAYLISTITEM, ((AimpPlayListItem^)value)->InternalAimpObject);
}