#include <stdio.h>
#include <wiringPi.h>

#define NUM 17 // 26pin
//#define NUM 18   //26pin
//#define NUM 20   //for Orange Pi Zero 2
//#define NUM 19   //for Orange Pi 4
//#define NUM 28     //40pin

void inter(void)
{
	printf("inter...\n");
}

int main(void)
{
	int ret = wiringPiSetup();
	printf("setup ret: %d\n",ret);

	pinMode(5, INPUT);

	pullUpDnControl(5, PUD_UP);
	wiringPiISR(5,INT_EDGE_FALLING, inter);
	return 0;
}
