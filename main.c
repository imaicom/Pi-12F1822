// cc -o main main.c -lwiringPi -lm
#include <stdio.h>
#include <unistd.h>	// write,readを使う宣言
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <math.h>

int main() {
	int fd , dat;
	unsigned char snd_data[8],rcv_data[8];

	fd = wiringPiI2CSetup(8); // I2Cのアドレス8番へ接続されているPIC 12F1822へアクセスする
	
	while(1) {
		// Write,Read文にて書いてみた		
		snd_data[0] = 0xA0; write(fd,snd_data,1); // RA0ポートのAN0を指定する
		snd_data[0] = 0xAD; write(fd,snd_data,1); // AD変換を指定する
		read(fd,rcv_data,2);
		dat = (rcv_data[1] << 8) + rcv_data[0];
		printf("%04x ",dat);

		// wiringPiライブラリで書いてみた		
		wiringPiI2CWrite(fd,0xA0); // RA0ポートのAN0を指定する
		dat = wiringPiI2CReadReg16(fd,0xAD); // AD変換されたデータを読む
		printf("%04x ",dat);
		
		// Write,Read文にて書いてみた		
		snd_data[0] = 0xA4; write(fd,snd_data,1); // RA4ポートのAN3を指定する
		snd_data[0] = 0xAD; write(fd,snd_data,1); // AD変換を指定する
		read(fd,rcv_data,2);
		dat = (rcv_data[1] << 8) + rcv_data[0];
		printf("%04x ",dat);

		// wiringPiライブラリで書いてみた		
		wiringPiI2CWrite(fd,0xA4); // RA4ポートのAN3を指定する
		dat = wiringPiI2CReadReg16(fd,0xAD); // AD変換されたデータを読む
		printf("%04x ",dat);
		
		snd_data[0] = 0xAA; write(fd,snd_data,1); // 4バイト送信を指定する
		read(fd,rcv_data,4); // 4バイト受信をする
		dat = (rcv_data[1] << 8) + rcv_data[0];
		printf("%04x ",dat);
		dat = (rcv_data[3] << 8) + rcv_data[2];
		printf("%04x\n",dat);
		
		delay(100);
	};		
}
