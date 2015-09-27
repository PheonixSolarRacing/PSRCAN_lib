#ifndef _PSRCAN
#define _PSRCAN

#include "../MCP_CAN_lib-master/mcp_can.h"

class PSRCAN
{
	private:
		MCP_CAN mcpCAN;
		INT8U buf[8];
		int bufLen;
	public:
		PSRCAN(INT8U _CS);
		void begin();
		void addData(int loc, bool data);			//add 1 byte
		void addData(int loc, char data);			//add 1 byte
		void addData(int loc, byte data);			//add 1 byte
		void addData(int loc, int data);			//add 2 bytes
		void addData(int loc, unsigned int data);	//add 2 bytes
		void addData(int loc, long data);			//add 4 bytes
		void addData(int loc, unsigned long data);	//add 4 bytes
		void addData(int loc, float data);			//add 4 bytes
		void sendMSG(INT32U ID, INT8U funcNum);
};

#endif