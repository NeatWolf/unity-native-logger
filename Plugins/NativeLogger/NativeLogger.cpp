#include "NativeLogger.h"

LoggerFuncPtr NativeLogger::Logger = nullptr;

void NativeLogger::SetLogger(LoggerFuncPtr logger)
{
	Logger = logger;
}

void NativeLogger::Log(NativeLogger::Level level, const char* msg)
{
	if (level == Level::Info)
		LogInfo(msg);
	else if (level == Level::Warning)
		LogWarn(msg);
	else if (level == Level::Error)
		LogError(msg);
}

void NativeLogger::LogInfo(const char* msg)
{
	Logger((int)Level::Info, msg);
}

void NativeLogger::LogWarn(const char* msg)
{
	Logger((int)Level::Warning, msg);
}

void NativeLogger::LogError(const char* msg)
{
	Logger((int)Level::Error, msg);
}
