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
		
		wiringPiI2CWrite(fd,0xA0); // RA0ポートのAN0を指定する
		dat = wiringPiI2CReadReg16(fd,0xAD); // AD変換されたデータを読む
		printf("%x ",dat);
		
		wiringPiI2CWrite(fd,0xA4); // RA4ポートのAN3を指定する
		dat = wiringPiI2CReadReg16(fd,0xAD);
		printf("%x\n",dat);
		
		delay(10);

	};		
}

