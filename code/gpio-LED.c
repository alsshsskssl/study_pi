#include <stdio.h>
#include <wiringPi.h>

#define LED1 4 // BCM_GPIO 24
#define BUTTON 1
int main (void)
{
  if (wiringPiSetup () == -1)
  return 1 ;

// GPIO 24번 핀을 출력 핀으로 설정
  pinMode (LED1, OUTPUT) ;
  pinMode (BUTTON, INPUT);

  while(1){
   int sw_in_val = digitalRead(BUTTON);
    if(!sw_in_val){
      digitalWrite(LED1, 0);
      delay(300);
      digitalWrite(LED1, 1);
      delay(300);
    }else{
      digitalWrite(LED1, 1);
    }
    printf("%d\n", sw_in_val);
    delay(100);
  }

  return 0 ;
}
