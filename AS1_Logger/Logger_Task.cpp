//============================================================================
// Name        : Logger_Task.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <thread>
#include <time.h>
#include "logger.hpp"
using namespace std;




void func_1()
{
CppLogger app1("Task1", lWarn, mFile,"out");
    app1.PrintInfo ("APP1");
    app1.SetLogLevel("Task1", lError);
    app1.PrintInfo ("Hello from app1");
}

void func_2()
{

CppLogger app2("Task2", lError, mFile,"out");
    app2.PrintInfo ("APP2");
    app2.SetLogLevel("Task2", lInfo);
    app2.PrintInfo ("Hello from app2");
}



int main() {


    std::thread th1(func_1);
    std::thread th2(func_2);
    th1.join();
    th2.join();

	return 0;
}
