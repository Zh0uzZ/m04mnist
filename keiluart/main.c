#include "system.h"

 unsigned char i = 0;
 unsigned char  en = 0; 
 unsigned int count = 0;
 unsigned int uart_data;
 unsigned int data[10];
 void Btn_ISR()
{
	  i=0;
}

 void Timer_ISR()
{
	 int j = 0;
	 int sum = 0;
	 en=1;
	if(count == 9)
	{
		for(j = 0;j<10;j++)
		{
			sum += data[j];
		}
		*(unsigned int*) AHB_UART_BASE = sum;
	}
	
	}
void Uart_ISR()
{
	if(count<=9)
	{
	data[count] = *(unsigned int*) AHB_UART_BASE;
	count = count + 1;
	}
}
//////////////////////////////////////////////////////////////////
// Main Function
//////////////////////////////////////////////////////////////////

int main(void) 
 {
	
	*(unsigned int*) AHB_TIMER_BASE= 0x0000FFFF;		     //Timer load register: =<clock frequency>   1555
	*(unsigned int*) AHB_TIMER_CONT = 0x07;				         //Timer 4-bits control register: [0]: timer enable, [1] mode (free-run or reload) [2]: prescaler
// *(unsigned int*) NVIC_INT_PRIORITY0 = 0x00004000;	   //Priority: IRQ0(Timer): 0x00, IRQ1(UART): 0x40
//	 *(unsigned int*) AHB_LED_BASE = 0xA5; 
	*(unsigned int*) NVIC_INT_ENABLE = 0x00000007;		     //Enable interrupts for UART and timer
	 *(unsigned int*) NVIC_INT_PRIORITY0 = 0x00C08000;
	while(1)
	{
//	  if(en==1)
//		{
//			en=0;
////		*(unsigned char*) AHB_LED_BASE = i; 
//			i=i+1;
////	   if (i==100)
////				*(unsigned int*) AHB_TIMER_CONT= 0;	//Stop timer if counter reaches 9
//	 }
		 *(unsigned int*) AHB_LED_BASE = count; 
		
 }
return 0;	
}


