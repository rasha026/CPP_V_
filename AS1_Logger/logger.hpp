
#ifndef LOGGER_HPP_
#define LOGGER_HPP_
#include <iostream>
#include <array>
#include <mutex>
#include <experimental/optional>
#include <cstddef>
#include <fstream>


typedef enum {
	lError,
	lWarn,
	lInfo,
	lDebug,
}LogLevel;

typedef enum {
	mFile,
	mConsole,
	mRemote,
}LogMode;



//template<typename T, size_t TElemCount>
class CppLogger
{
  public:

	~CppLogger();
	CppLogger(std::string appId, LogLevel logLevel, LogMode logMode ,std::string file_name);
	void SetLogLevel(std::string appId, LogLevel logLevel);
	void SetLogMode(std::string appId, LogMode logMode);

	tm *GetTime();
	void PrintInfo(std::string);


  private:
	std::string Application_ID;
	int LogNum{};
	std::string LogMsg;
	LogLevel log_level;
	LogMode  Log_mode;
	std::ofstream fileStream;
	std::string logLevel_ARR[4]{"lError","lWarn","lInfo","lDebug"};
};

#endif
