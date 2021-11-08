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
	std::cout << sizeof(float) << std::endl;
	F1TS_packetSizes();
	F1Ts_startF1TelemetryThread();

	while (!F1TS_isReady())
	{
		std::cout << "Waiting for the socket to open" << std::endl;
	}


	
	while (true)
	{
		//std::cout << "-------------------------------------" << std::endl;
		for(int i=0;i<22;i++)
		{
			std::cout << F1TS_speed(i) << "  ";
		}
		std::cout << std::endl;
	}
	
	F1TS_closeF1Telemetry();
	
	
	//char d[] = "aaaabbbbcccc";
	//char* data =  &d[0];


	//metodo1(data);
	//metodo2(data);
	//metodo3(data);
}
