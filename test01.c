// cc -o test01 test01.c -lwiringPi -lm
#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <math.h>

int main() {
	int fd;
	short dat,x,y,z;

	fd = wiringPiI2CSetup(8);

	while(1) {
		/*
		delay(200);wiringPiI2CWrite(fd,0);
		delay(200);wiringPiI2CWrite(fd,2);
		delay(200);wiringPiI2CWrite(fd,1);
		delay(200);wiringPiI2CWrite(fd,4);
		delay(200);wiringPiI2CWrite(fd,3);
		delay(200);wiringPiI2CWrite(fd,6);
		delay(200);wiringPiI2CWrite(fd,5);
		delay(200);wiringPiI2CWrite(fd,7);
		
		if(wiringPiI2CReadReg8(fd,1)== 0xAA) return(0);
		*/
		dat=wiringPiI2CRead(fd);
		printf("%x ",dat);
		dat=wiringPiI2CRead(fd);
		printf("%x ",dat);
		dat=wiringPiI2CRead(fd);
		printf("%x ",dat);
		dat=wiringPiI2CRead(fd);
		printf("%x ",dat);
		dat=wiringPiI2CReadReg8(fd,0);
		printf("%x ",dat);
		dat=wiringPiI2CReadReg8(fd,1);
		printf("%x ",dat);
		dat=wiringPiI2CReadReg8(fd,20);
		printf("%x ",dat);
		dat=wiringPiI2CReadReg16(fd,2);
		printf("%x\n",dat);
		delay(100);
	};

//	delay(500);
//	dat=wiringPiI2CRead(fd);
//	printf("%x\n",dat);
//	wiringPiI2CWrite(fd,0x2);

		
}

