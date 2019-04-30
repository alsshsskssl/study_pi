#include<stdio.h>
#include<wiringPi.h>

#define LED1 4
#define LED2 5

int main(){
	if(wiringPiSetup()== -1)
		return 1;
;
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);

	while(1){
		int i;
		int a,b,c;
		printf("\nEnter a character.");
		scanf("%d %d %d",&a,&b,&c);

		//printf("The character you entered is %c", userinput);
		//while(getchar() != '\n');
		for(i=0; i<a; i++){
			delay(b*50);
			digitalWrite(LED1+c-1, 0);
			delay(b*50);
			digitalWrite(LED1+c-1, 1);
		}

		/*
		if(userinput == '1'){
			digitalWrite(LED1, 0);
		}else if(userinput == '0'){
			digitalWrite(LED1,1);
		}
			digitalWrite(LED2,1);
		*/
	}
	return 0;
}
