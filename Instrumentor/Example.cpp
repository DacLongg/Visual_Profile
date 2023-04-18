#include "Instrumentor.h"

void Function1()
{
	PROFILE_FUNCTION();

	for (int i = 0; i < 1000; i++)
	{
		std::cout << "Hello World #" << i << std::endl;
	}
}

void Function2()
{
	PROFILE_FUNCTION();

	for (int i = 1000; i < 5000; i++)
	{
		std::cout << "Hello World #" << i << std::endl;
	}
}

void RunProfiling()
{
	PROFILE_FUNCTION();

	InstrumentationTimer Timer("RunProfiling");

	std::cout << "Running BenchMarks... \n";
	Function1();
	Function2();
}

int main()
{
	Instrumentor::Get().BeginSession("Profile");
	RunProfiling();
	Instrumentor::Get().EndSession();

	std::cin.get();
}