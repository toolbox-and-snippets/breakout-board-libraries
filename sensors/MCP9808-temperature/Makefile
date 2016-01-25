CXXFLAGS = -g -Wall -Werror -std=c++0x
CXX = g++

all: I2CDevice.o MCP9808.o application

I2CDevice.o: I2CDevice.cpp I2CDevice.h
	$(CXX) -c $(CXXFLAGS) I2CDevice.cpp

MCP9808.o: MCP9808.cpp MCP9808.h
	$(CXX) -c $(CXXFLAGS) MCP9808.cpp

application: I2CDevice.o MCP9808.o application.cpp
	$(CXX) $(CXXFLAGS) application.cpp I2CDevice.o MCP9808.o -o application
	
clean:
	rm -f *.o application
