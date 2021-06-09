#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define data_size    10*sizeof(int32_t)
#define IIS_CLK     1
#define IIS_WS      4
#define IIS_DATA0   5

void myDelay(unsigned int time);

int main(){
    int32_t num = 0;
    int32_t *p,*p2;
    int num_ws = 0;
    int j = 0;

    if(wiringPiSetup() == -1){
        printf("Init error\n");
        exit(1);
    };

    p = (void *) malloc(data_size);
    if (p == NULL)
	{
		printf("malloc failed!\n");
		return -1;
	}

    pinMode (IIS_CLK, OUTPUT) ;
    pinMode (IIS_WS,OUTPUT);
    unsigned char iis_clk_s = 1;
    unsigned char iis_ws_s = 1;

    digitalWrite (IIS_CLK, iis_clk_s) ;
    digitalWrite (IIS_WS, iis_ws_s) ;

    p2 = p;
    printf("init\r\n");
    for(int n = 0;n<data_size/sizeof(int32_t);n++){
        printf("%d\t",p[n]);
    }
    printf("\r\n");

    for(int n=0;n<320;n++){
        if(iis_clk_s){
            num_ws ++;
            if(num_ws == 32){
                iis_ws_s = ~iis_ws_s;
                num_ws = 0;
            }
        }
        else{
            if(num_ws == 1){
                num = digitalRead(IIS_DATA0);
            }
            else if(num_ws<=24 && num_ws>1){
                num = (num << 1) + digitalRead(IIS_DATA0);
            }
            else if(num_ws == 25){
                if(num & 0x800000){
                    num|=0xff000000;
                }
                *p2 = num;
                p2++;
            }
        }
        myDelay(25);
    }
    for(int i = 0; i<data_size/sizeof(int32_t);i++){
        printf("%d\t",p[i]);
    }
    printf("\r\n");
    free(p);
    return 0;
}

void myDelay(unsigned int time)
{
    while(time--);
}
