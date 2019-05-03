#include <stdio.h>
#include <wiringPi.h>

#define LED1 4
#define LED2 1

int main(){
  int led, hz, bright, range;
  int i;	
  if(wiringPiSetup() == -1)
 	  return 1;
  pinMode (LED1, PWM_OUTPUT);
  pinMode (LED2, PWM_OUTPUT);

  scanf("%d %d %d",&led,&hz,&bright);
  digitalWrite(LED1, 1);

  if(led == 1){
    for(i=0; i<bright; i++){
      delay(hz*50);
      digitalWrite(LED1, 0);
      delay(hz*50);
      digitalWrite(LED1, 1);
    }
  }else if(led == 2){
    range = 10*hz;

    printf("%d", range);
    pwmSetClock(1920);
    pwmSetMode(PWM_MODE_MS);

    pwmSetRange(range);
    pwmWrite(1,range-range*bright/10.0);
  }
  while(1) {}
  return 0;

}
