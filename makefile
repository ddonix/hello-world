test:test.o
	gcc test.c -o test -lwiringPi  
jg:jg.o
	gcc jg.c -o jg -lwiringPi  
lb:lb.o
	gcc lb.c -o lb -lwiringPi  
pcm:pcm.o
	gcc pcm.c -g -o pcm -lwiringPi  
pcm_r:pcm_r.o
	gcc pcm_r.c -g -o pcm_r -lwiringPi  -lasound
pcm_w1:pcm_w1.o
	gcc pcm_w1.c -g -o pcm_w1 -lwiringPi  -lasound
pcm_w2:pcm_w2.o
	gcc pcm_w2.c -g -o pcm_w2 -lwiringPi  -lasound
shmwrite:shmwrite.o
	gcc shmwrite.c -g -o shmwrite -lwiringPi  -lasound
dc:dc.o
	gcc dc.c -g -o dc -lwiringPi  
wav:wav.o
	gcc wav.c -g -o wav -lasound
clean:  
	rm -f test jg lb pcm
