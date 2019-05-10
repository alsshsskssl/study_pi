#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#define TRIG 23
#define ECHO 24
#define LED1 1

int main(){
	float distance;
	int s,e;
	
	if(wiringPiSetup() == -1)
		return 1;

	pinMode(TRIG,OUTPUT);
	pinMode(ECHO,INPUT);

	printf("before while\n");

	while(1){
		digitalWrite(TRIG,LOW);
		delay(500);
		digitalWrite(TRIG,HIGH);
		delayMicroseconds(10);
		digitalWrite(TRIG,LOW);
		while(digitalRead(ECHO)==0);
		s = micros();
		while(digitalRead(ECHO)==1);
		e = micros();
		distance = (e-s)/29./2.;
		printf("distance : %.2f\n",distance);
	}

	return 0;
}
