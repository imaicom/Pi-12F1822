// cc -o test01 test01.c -lwiringPi -lm
#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <math.h>

int main() {
	int fd , dat;
	char snd_data[8],rcv_data[8];

	fd = wiringPiI2CSetup(8); // I2Cのアドレス8番へ接続されているPIC 12F1822へアクセスする
	
	while(1) {
		snd_data[0] = 0xA0; write(fd,snd_data,1); // RA0ポートのAN0を指定する
		snd_data[0] = 0xAD; write(fd,snd_data,1); // AD変換を指定する
		read(fd,rcv_data,2);
		dat = (rcv_data[1] << 8) + rcv_data[0];
		printf("%04x ",dat);

		wiringPiI2CWrite(fd,0xA0); // RA0ポートのAN0を指定する
		dat = wiringPiI2CReadReg16(fd,0xAD); // AD変換されたデータを読む
		printf("%04x ",dat);
		
		snd_data[0] = 0xA4; write(fd,snd_data,1); // RA4ポートのAN3を指定する
		snd_data[0] = 0xAD; write(fd,snd_data,1); // AD変換を指定する
		read(fd,rcv_data,2);
		dat = (rcv_data[1] << 8) + rcv_data[0];
		printf("%04x ",dat);

		wiringPiI2CWrite(fd,0xA4); // RA4ポートのAN3を指定する
		dat = wiringPiI2CReadReg16(fd,0xAD); // AD変換されたデータを読む
		printf("%04x\n",dat);
		
		delay(100);
	};		
}
