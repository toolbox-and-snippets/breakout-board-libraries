#include <iostream>
#include "MCP9808.h"
#include <unistd.h>
#include <pthread.h>

using namespace std;
using namespace exploringBB;

int main() {
	MCP9808 sensor(1, 0x18);
	std::cout << "TESTING" << std::endl;
	float temp = sensor.readTempC();	
	std::cout << temp << std::endl;
	return 0;
}
