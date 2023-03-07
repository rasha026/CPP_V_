#include "logger.hpp"


std::mutex log_mutex;

CppLogger::~CppLogger()
{

}


 CppLogger::CppLogger(std::string appId, LogLevel logLevel, LogMode logMode,std::string file_name=""){
	this->Application_ID=appId;
	this->log_level=logLevel;
	this->Log_mode=logMode;


	if(logMode ==mFile && file_name!=""){
		fileStream.open(file_name + ".txt", std::ios::app);
	}



}



void CppLogger::SetLogLevel(std::string appId, LogLevel logLevel){
	this->Application_ID=appId;
	this->log_level=logLevel;




}
void CppLogger::SetLogMode(std::string appId, LogMode logMode ){
	this->Application_ID=appId;
	this->Log_mode=logMode;



}

tm *CppLogger::GetTime(){
	// current date/time based on current system
	   time_t TimeNow = time(0);
	   tm *ltm = localtime(&TimeNow);

	   return ltm;
}









void CppLogger::PrintInfo(std::string MSG){
	std::lock_guard<std::mutex> guard(log_mutex);
	this->LogMsg=MSG;
	LogNum++;

	tm *st_Time=GetTime();
	if (this->Log_mode == mFile)
	{
		this->fileStream<<"| "<< st_Time->tm_hour << ":"<< st_Time->tm_min <<":"<<st_Time->tm_sec<<" " <<"| " << this->Application_ID << " | " << this->LogNum<<" | "<< logLevel_ARR[this->log_level]<<" | "<<this->LogMsg<<" |"<< std::endl;

	}
	else if (this->Log_mode == mConsole)
	{
		std::cout <<"| "<< st_Time->tm_hour << ":"<< st_Time->tm_min <<":"<<st_Time->tm_sec<<" " ;
		std::cout <<"| " << this->Application_ID << " | " << this->LogNum<<" | "<< logLevel_ARR[this->log_level]<<" | "<<this->LogMsg<<" |"<< std::endl;
	}




}






