/*
 * LED sequence V1.0.c
 *
 * Created: 8/22/2023 10:49:21 PM
 * Author : Bolis Karam
 */ 

//#include <avr/io.h>
#include "APP/APP.h"

//void DIO_test_Init(void);
//void DIO_Test_Update(void);

//void LED_Test_Init(void);
//void LED_Test_Update(void);

int main(void)
{
	//DIO_test_Init();
	//LED_Test_Init();
	APP_Init();
	
	
    /* Replace with your application code */
    while (1) 
    {
		//DIO_Test_Update();
		//LED_Test_Update();
		APP_Update();
		
	}
}



//------------------------------------- Test INIT DIO peripheral -----------------------------------
/*void DIO_test_Init(void){
	ST_DIO_Config_t DIO_Init_Config;
	EN_DIO_STATUS_t DIO_ERROR = DIO_OK ;
	
	DIO_Init_Config.portName = PORT_A;
	DIO_Init_Config.pinNumber = PIN2 ;
	DIO_Init_Config.direction = OUTPUT;
	DIO_ERROR = MCAL_DIO_Init_Pin(&DIO_Init_Config);
	
	DIO_Init_Config.portName = PORT_B;
	DIO_Init_Config.pinNumber = PIN4 ;
	DIO_Init_Config.direction = OUTPUT;
	DIO_ERROR = MCAL_DIO_Init_Pin(&DIO_Init_Config);
}*/
//-------------------------------------------------------------------------------------------------

//------------------------------------- Test DIO peripheral ---------------------------------------
/*void DIO_Test_Update(void){
	ST_DIO_Data_Config_t DIO_Write_Config;
	EN_DIO_STATUS_t DIO_ERROR = DIO_OK ;
	DIO_Write_Config.portName = PORT_A;
	DIO_Write_Config.pinNumber = PIN2;
	DIO_ERROR = MCAL_DIO_Write_Pin(&DIO_Write_Config,High);
		
	DIO_Write_Config.portName = PORT_B;
	DIO_Write_Config.pinNumber = PIN4;
	DIO_ERROR = MCAL_DIO_Write_Pin(&DIO_Write_Config,LOW);
}*/
//--------------------------------------------------------------------------------------------------

//------------------------------------- Test INIT LED peripheral -----------------------------------
/*void LED_Test_Init(void){
	ST_LED_Config_t LED_Config;
	EN_LED_STATUS_t LED_ERROR = LED_OK ;
	
	LED_Config.LED_Port = PORT_A ;
	LED_Config.LED_Pin = PIN0 ;
	LED_ERROR = ECUAL_LED_Init(&LED_Config);
	
	LED_Config.LED_Port = PORT_A ;
	LED_Config.LED_Pin = PIN1 ;
	LED_ERROR = ECUAL_LED_Init(&LED_Config);
}*/
//---------------------------------------------------------------------------------------------

//------------------------------------- Test LED peripheral -----------------------------------
/*void LED_Test_Update(void){
	ST_LED_Config_t LED_Config;
	EN_LED_STATUS_t LED_ERROR = LED_OK ;
	
	LED_Config.LED_Port = PORT_A ;
	LED_Config.LED_Pin = PIN0 ;
	LED_ERROR = ECUAL_LED_ON(&LED_Config);
	
	LED_Config.LED_Port = PORT_A ;
	LED_Config.LED_Pin = PIN1 ;
	LED_ERROR = ECUAL_LED_ON(&LED_Config);
}*/
//---------------------------------------------------------------------------------------------
