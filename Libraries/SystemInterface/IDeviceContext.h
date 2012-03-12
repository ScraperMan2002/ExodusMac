#ifndef __IDEVICECONTEXT_H__
#define __IDEVICECONTEXT_H__
class ILogEntry;
class IDevice;

class IDeviceContext
{
public:
	//Enumerations
	enum KeyCode;

	//Constructors
	virtual ~IDeviceContext() = 0 {}

	//Timing functions
	virtual double GetCurrentTimesliceProgress() const = 0;

	//Control functions
	virtual bool DeviceEnabled() const = 0;
	virtual void SetDeviceEnabled(bool state) = 0;

	//Device/System interface
	virtual IDevice* GetTargetDevice() const = 0;

	//System message functions
	virtual void SetSystemRollback(IDeviceContext* atriggerDevice, IDeviceContext* arollbackDevice, double timeslice, void (*callbackFunction)(void*) = 0, void* callbackParams = 0) = 0;
	virtual void WriteLogEvent(const ILogEntry& entry) = 0;
	virtual void FlagStopSystem() = 0;
	virtual void StopSystem() = 0;
	virtual void RunSystem() = 0;
	virtual void ExecuteDeviceStep() = 0;
	inline std::wstring GetCapturePath() const;
	inline std::wstring GetModuleDisplayName() const;

	//Input functions
	virtual bool TranslateKeyCode(unsigned int platformKeyCode, KeyCode& inputKeyCode) = 0;
	virtual void HandleInputKeyDown(KeyCode keyCode) const = 0;
	virtual void HandleInputKeyUp(KeyCode keyCode) const = 0;

protected:
	//System message functions
	virtual const wchar_t* GetCapturePathInternal() const = 0;
	virtual const wchar_t* GetModuleDisplayNameInternal() const = 0;
};

#include "IDeviceContext.inl"
#endif
