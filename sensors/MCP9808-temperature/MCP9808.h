#ifndef MCP9808_H_
#define MCP9808_H_
#include"I2CDevice.h"

namespace exploringBB {

class MCP9808:protected I2CDevice{

public:



private:
	unsigned int I2CBus, I2CAddress;
	unsigned char *registers;

public:
	MCP9808(unsigned int I2CBus, unsigned int I2CAddress=0x18);
	virtual float readTempC(void);
	virtual ~MCP9808();
	//std::string exec(const char* cmd);
};

} /* namespace exploringBB */

#endif /* MCP9808_H_ */
