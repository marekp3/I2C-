

#include <avr/io.h>
#define F_CPU 8000000UL
#include "header.h"
#include <util/delay.h>



int main(void)
{
	DDRC = DDRC | 0b00000001;
	PORTC = PORTC | 0b00000001;
	DDRD = 0xFF;
	PORTD=0xFF;
	I2C_Init();
	_delay_ms(1000);
    /* Replace with your application code */
    uint8_t minuty, dminut, godziny, dgodzin, cos, first;
	minuty = godziny = dgodzin = dminut = first = 0;
	uint8_t address = 0x68;
	static uint8_t DIGITS[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};
	while(1)
    {
		/*if(first==0)
		{
			I2C_Start();
			I2C_SendAddr((address<<1) | 0b00000000);
			I2C_SendByte(0x01);
			I2C_SendByte(0x38);
			I2C_SendByte(0x19);
			
			first=1;
			
		}*/
		I2C_Start();
		I2C_SendAddr((address<<1) | 0b00000000);
		I2C_SendByte(0x01);
		I2C_Start();
		I2C_SendAddr((address<<1) | 0b00000001);
		cos = I2C_ReceiveData_ACK();
		minuty = cos & 0b00001111;
		dminut = (cos & 0b11110000)>>4;
		cos = I2C_ReceiveData_ACK();
		godziny = cos & 0b00001111;
		dgodzin = (cos & 0b00110000)>>4;
		PORTD = DIGITS[minuty];
						
		_delay_ms(500);
			
		
    }
}



