#include "PSRCAN.h"

PSRCAN::PSRCAN(INT8U _CS) : mcpCAN(_CS) {
	mcpCAN.begin(CAN_125KBPS);

	for(int i = 0; i < 8; i++)
		buf[i] = 0;

	bufLen = 0;
}

void PSRCAN::addData(int loc, bool data){
	byte byteBool;

	if(data)
		byteBool = 0xFF;
	else
		byteBool = 0x00;

	buf[loc] = byteBool;

	bufLen += 1;

}

void PSRCAN::addData(int loc, char data){
	buf[loc] = data;

	bufLen += 1;
}

void PSRCAN::addData(int loc, byte data){
	buf[loc] = data;

	bufLen += 1;
};

void PSRCAN::addData(int loc, int data){
	for(int i = 0; i < 1; i++){
		buf[loc + i] = ((data >> (8 * (1 - i))) & 0xFF);
	}

	bufLen += 2;
}

void PSRCAN::addData(int loc, unsigned int data){
	for(int i = 0; i < 1; i++){
		buf[loc + i] = ((data >> (8 * (1 - i))) & 0xFF);
	}

	bufLen += 2;
}

void PSRCAN::addData(int loc, long data){
	for(int i = 0; i < 4; i++){
		buf[loc + i] = ((data >> (8 * (3 - i))) & 0xFF);
	}

	bufLen += 4;
}

void PSRCAN::addData(int loc, unsigned long data){
	for(int i = 0; i < 4; i++){
		buf[loc + i] = ((data >> (8 * (3 - i))) & 0xFF);
	}

	bufLen += 4;
}

void PSRCAN::addData(int loc, float data){
	for(int i = 0; i < 1; i++){
		buf[loc + i] = ((*reinterpret_cast<int*>(&data) >> (8 * (3 - i))) & 0xFF);
	}

	bufLen += 4;
}

void PSRCAN::sendMSG(unsigned long ID, byte funcNum){
	mcpCAN.sendMsgBuf(ID, funcNum, bufLen, buf);

	for(int i = 0; i < 8; i++)
		buf[i] = 0;

	bufLen = 0;
}