// cc -o test01 test01.c -lwiringPi -lm
#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <math.h>

int main() {
	int fd;
	short dat,x,y,z;

	fd = wiringPiI2CSetup(8);

	delay(500);	

//	delay(500);
//
//	dat=wiringPiI2CReadReg8(fd,0);
//	printf("%x\n",dat);
	
//	wiringPiI2CWriteReg8(fd,1,0x00);
 	wiringPiI2CWriteReg8(fd,0,0x1);

	delay(500);

	dat=wiringPiI2CReadReg8(fd,0);
	printf("%x\n",dat);
	wiringPiI2CWriteReg8(fd,1,0x10);
	
	delay(500);

	dat=wiringPiI2CReadReg8(fd,0);
    printf("%x\n",dat);

	delay(500);

	dat=wiringPiI2CReadReg8(fd,0);
	printf("%x\n",dat);

	delay(500);
	
	dat=wiringPiI2CReadReg8(fd,0);
    printf("%x\n",dat);
	delay(500);

	dat=wiringPiI2CReadReg8(fd,0);
	printf("%x\n",dat);

	delay(500);
	
	dat=wiringPiI2CReadReg8(fd,0);
    printf("%x\n",dat);

	return(0);	
}

