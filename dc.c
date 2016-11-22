#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

#define OLED_PIN 2
#define OLB_PIN  3

int p(int x)
{
       	digitalWrite(OLB_PIN, x);
       	digitalWrite(OLED_PIN, x);
}

int pp(int x, int y, int z)
{
	int i,j,k;
	j = x*y/10;
	k = 1000000/y;
	printf("%d %d %d\n", j, y, j*(500000/y));
	for(i=0; i < j; i++)
	{
		digitalWrite(OLB_PIN, HIGH);
        	digitalWrite(OLED_PIN, HIGH);
                
		delayMicroseconds(k*z/10);
        	
		digitalWrite(OLB_PIN, LOW);
        	digitalWrite(OLED_PIN, LOW);
		delayMicroseconds(k*(10-z)/10);
	}
}

int main(int argc ,char *argv[])
{
	int dy[8] = {0,262,294,330,349,392,440,494};
	int zy[8] = {494,523,587,659,698,784,880,988};
	int gy[8] = {988,1046,1175,1318,1397,1568,1760,1967};
	wiringPiSetup();
    
	pinMode(OLED_PIN, OUTPUT);
	pinMode(OLB_PIN, OUTPUT);
       	
	digitalWrite(OLB_PIN, LOW);
       	digitalWrite(OLED_PIN,LOW);

	uint32_t i,j;
	i = 40;
	j = atoi(argv[1]);
	pp(10,dy[1],j);
	pp(10,dy[2],j);
	pp(10,dy[3],j);
	pp(10,dy[4],j);
	pp(10,dy[5],j);
	pp(10,dy[6],j);
	pp(10,dy[7],j);
	
	pp(10,zy[1],j);
	pp(10,zy[2],j);
	pp(10,zy[3],j);
	pp(10,zy[4],j);
	pp(10,zy[5],j);
	pp(10,zy[6],j);
	pp(10,zy[7],j);
	
/*	
	pp(10,gy[1],j);
	pp(10,gy[2],j);
	pp(10,gy[3],j);
	pp(10,gy[4],j);
	pp(10,gy[5],j);
	pp(10,gy[6],j);
	pp(10,gy[7],j);
*/	return 0;
}
