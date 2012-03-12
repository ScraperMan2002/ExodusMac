#include "SettingsViewModel.h"
#include "SettingsView.h"

//----------------------------------------------------------------------------------------
//Constructors
//----------------------------------------------------------------------------------------
VDP::SettingsViewModel::SettingsViewModel(const std::wstring& amenuHandlerName, int aviewModelID, VDP* adevice)
:ViewModelBase(amenuHandlerName, aviewModelID, false, true, adevice->GetDeviceInstanceName(), adevice->GetDeviceModuleID()), device(adevice)
{}

//----------------------------------------------------------------------------------------
//View creation and deletion
//----------------------------------------------------------------------------------------
IView* VDP::SettingsViewModel::CreateView()
{
	return new SettingsView(device);
}

//----------------------------------------------------------------------------------------
void VDP::SettingsViewModel::DeleteView(IView* aview)
{
	delete aview;
}
