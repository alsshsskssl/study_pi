#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#define TRIG 23
#define ECHO 24
#define LED1 1
double getDistance();
int main(){
	/*
	while(1){
		printf("%f\n",getDistance());
		delay(500);
	}
	*/

	if(wiringPiSetup() == -1)
		return 1;

	pinMode(LED1,PWM_OUTPUT);

	while(1){
		int range = 10*3;
		double distance = getDistance();
		pwmSetClock(1920);
		pwmSetMode(PWM_MODE_MS);
		pwmSetRange(range);
		pwmWrite(LED1,distance);
	}
	

	return 0;
}
double getDistance(){
	double distance;
	double s,e;
	
	if(wiringPiSetup() == -1)
		return 1;

	pinMode(TRIG,OUTPUT);
	pinMode(ECHO,INPUT);

	digitalWrite(TRIG,LOW);
	delay(200);
	digitalWrite(TRIG,HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG,LOW);
	while(digitalRead(ECHO)==0);
	s = micros();
	while(digitalRead(ECHO)==1);
	e = micros();
	distance = (e-s)/29./2.;

	return distance;
}
