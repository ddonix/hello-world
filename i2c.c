#include <stdio.h>

#include <wiringPiI2C.h>

int main(void)

{
        int buf[10] = {0};
        const int devId = 0b1010000;
        int fd = wiringPiI2CSetup(devId);

        if (fd < 0) {
                printf("Error setup I2C device %b\n", devId);
        	return 1;
	}

        buf[0] = wiringPiI2CRead(fd);
        printf("buf = %c\n", buf[0]);


        return 0;
}
