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

 	wiringPiI2CWrite(fd,0x1);

	delay(500);

	dat=wiringPiI2CRead(fd);
	printf("%x\n",dat);
	wiringPiI2CWrite(fd,0x2);
	  
	delay(500);

	dat=wiringPiI2CRead(fd);
    printf("%x\n",dat);
	wiringPiI2CWrite(fd,0x1);


	delay(500);

	dat=wiringPiI2CRead(fd);
	printf("%x\n",dat);

	delay(500);
	
	dat=wiringPiI2CRead(fd);
    printf("%x\n",dat);
	delay(500);

	dat=wiringPiI2CRead(fd);
	printf("%x\n",dat);

	delay(500);
	
	dat=wiringPiI2CRead(fd);
    printf("%x\n",dat);

	return(0);	
}

