#include "PSRCAN.h"

PSRCAN::PSRCAN(INT8U _CS) : mcpCAN(_CS) {

	for(int i = 0; i < 8; i++)
		buf[i] = 0;

	bufLen = 1;
}

void PSRCAN::begin(){
	mcpCAN.begin(CAN_125KBPS);
}

void PSRCAN::addData(int loc, bool data){
	if(loc != 0){
		byte byteBool;

		if(data)
			byteBool = 0xFF;
		else
			byteBool = 0x00;

		buf[loc] = byteBool;

		bufLen = (loc + 1);
	}
}

void PSRCAN::addData(int loc, char data){
	if(loc != 0){

		buf[loc] = data;

		bufLen = (loc + 1);
	}
}

void PSRCAN::addData(int loc, byte data){
	if(loc != 0){

		buf[loc] = data;

		bufLen = (loc + 1);
	}
};

void PSRCAN::addData(int loc, int data){
	if(loc != 0){

		for(int i = 0; i < 2; i++){
			buf[loc + i] = ((data >> (8 * (1 - i))) & 0xFF);
		}

		bufLen = (loc + 2);
	}
}

void PSRCAN::addData(int loc, unsigned int data){
	if(loc != 0){

		for(int i = 0; i < 2; i++){
			buf[loc + i] = ((data >> (8 * (1 - i))) & 0xFF);
		}

		bufLen = (loc + 2);
	}
}

void PSRCAN::addData(int loc, long data){
	if(loc != 0){

		for(int i = 0; i < 4; i++){
			buf[loc + i] = ((data >> (8 * (3 - i))) & 0xFF);
		}

		bufLen = (loc + 4);
	}
}

void PSRCAN::addData(int loc, unsigned long data){
	if(loc != 0){

		for(int i = 0; i < 4; i++){
			buf[loc + i] = ((data >> (8 * (3 - i))) & 0xFF);
		}

		bufLen = (loc + 4);
	}
}

void PSRCAN::addData(int loc, float data){
	if(loc != 0){

		for(int i = 0; i < 4; i++){
			buf[loc + i] = ((*reinterpret_cast<long*>(&data) >> (8 * (3 - i))) & 0xFF);
		}

		bufLen = (loc + 4);
	}
}

void PSRCAN::sendMSG(INT32U ID, INT8U funcNum){
	if(bufLen < 8)
		bufLen = 8;

	buf[0] = funcNum;

	mcpCAN.sendMsgBuf(ID, 0, bufLen, buf);

	for(int i = 0; i < 8; i++)
		buf[i] = 0;

	bufLen = 1;
}