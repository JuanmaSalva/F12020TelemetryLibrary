#include <iostream>

#include "F1TS_Externs.h"



void metodo1(char*& dato)
{
	std::cout << dato << std::endl;
}

void metodo3(char*& dato)
{
	dato += 1;
	std::cout << dato << std::endl;

}

void metodo2(char*& dato)
{
	dato += 1;
	std::cout << dato << std::endl;

}

int main()
{
	F1TS_startF1TelemetryThread();

	while (!F1TS_isReady())
	{
		std::cout << "Waiting for the socket to open" << std::endl;
	}


	std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	
	
	F1TS_closeF1Telemetry();
}
