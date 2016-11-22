#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

#define OLED_PIN 2
#define OJG_PIN  3

int main(int argc ,char *argv[])
{
	wiringPiSetup();
    
	pinMode(OLED_PIN, OUTPUT);
	pinMode(OJG_PIN, OUTPUT);

	char data[100],k;
	uint32_t i,j,l;

	i = 0;	
	while(1)
	{
    		scanf("%s", data);
		for(i = 0; 0 != data[i] ; i++)
		{
			k = 1;
			for (j = 0;j < 8; j++)
			{
				digitalWrite(OLED_PIN, data[i] & k);
				digitalWrite(OJG_PIN, data[i] & k);
                		delayMicroseconds(100000);
				k = k<<1;
			}
		}
        	digitalWrite(OLED_PIN, LOW);
	}
        digitalWrite(OLED_PIN, LOW);
	return 0;
}
