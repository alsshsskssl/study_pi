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

	pinMode(LED1,OUTPUT);

	while(1){
		if(getDistance()<50.0){
			double distance = getDistance();
			digitalWrite(LED1,0);
			delay(distance*5);
			digitalWrite(LED1,1);
			delay(distance*5);
		}
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
	delay(50);
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
