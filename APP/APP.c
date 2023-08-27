/*
 * APP.c
 *
 * Created: 8/26/2023 3:57:24 AM
 *  Author: Bolis
 */ 


#include "APP.h"

void APP_Init(void){
		
	//------------------------------------- Test INIT LED peripheral -----------------------------------
	
	ST_LED_Config_t LED_Config;
	EN_LED_STATUS_t LED_ERROR = LED_OK ;
	
	LED_Config.LED_Port = PORT_A ;
	LED_Config.LED_Pin = PIN0 ;
	LED_ERROR = ECUAL_LED_Init(&LED_Config);
	
	LED_Config.LED_Port = PORT_A ;
	LED_Config.LED_Pin = PIN1 ;
	LED_ERROR = ECUAL_LED_Init(&LED_Config);
	
	LED_Config.LED_Port = PORT_A ;
	LED_Config.LED_Pin = PIN2 ;
	LED_ERROR = ECUAL_LED_Init(&LED_Config);
	
	LED_Config.LED_Port = PORT_A ;
	LED_Config.LED_Pin = PIN3 ;
	LED_ERROR = ECUAL_LED_Init(&LED_Config);
	
	//--------------------------------------------------------------------------------------------- 
	
	//------------------------------------- Test INIT Button peripheral --------------------------------
	
	ST_BUTTON_Config_t Button_Config ;
	EN_BUTTON_STATUS_t BUTTON_ERROR = BUTTON_OK ;
	
	Button_Config.buttonPort = PORT_D ;
	Button_Config.buttonPin = PIN5;
	BUTTON_ERROR = ECUAL_BUTTON_Init(&Button_Config);
	
	//---------------------------------------------------------------------------------------------	
	
}
	
	
void APP_Update(void){

	static uint8_t Count = 0 ;
		
	ST_LED_Config_t LED_Config;
	EN_LED_STATUS_t LED_ERROR = LED_OK ;
		
	ST_BUTTON_Config_t Button_Config ;
	EN_BUTTON_STATUS_t BUTTON_ERROR = BUTTON_OK ;
		
	EN_pinValue_t buttonValue = LOW ;
				
	Button_Config.buttonPort = PORT_C ;
	Button_Config.buttonPin = PIN1 ;
		
	BUTTON_ERROR = ECUAL_BUTTON_Read(&Button_Config,&buttonValue);
		
	if(BUTTON_ERROR == BUTTON_OK){
		
		if (buttonValue){
			if(Count >= 0 && Count < 4){
				LED_Config.LED_Port = PORT_A ;
				LED_Config.LED_Pin = PIN0 + Count ;
				LED_ERROR = ECUAL_LED_ON(&LED_Config);
				if (LED_ERROR== LED_OK)
				{
					Count++;
				}
			}
			else if(Count >= 4 && Count < 8 ){
				LED_Config.LED_Port = PORT_A ;
				LED_Config.LED_Pin = PIN0 + (Count-4);
				LED_ERROR = ECUAL_LED_OFF(&LED_Config);
				if (LED_ERROR== LED_OK)
				{
					if(Count == 7){
						Count = 0 ;
						}else{
						Count++;
					}
				}
			}
			while(buttonValue==High){
				BUTTON_ERROR = ECUAL_BUTTON_Read(&Button_Config,&buttonValue);
			}
		}
		// other solution	
		/*	
		if (buttonValue==High)
		{	
			switch(Count){
				case 0:
					LED_Config.LED_Port = PORT_A ;
					LED_Config.LED_Pin = PIN0 ;
					LED_ERROR = ECUAL_LED_ON(&LED_Config);
					Count++;
					break;
				case 1:
					LED_Config.LED_Port = PORT_A ;
					LED_Config.LED_Pin = PIN1 ;
					LED_ERROR = ECUAL_LED_ON(&LED_Config);
					Count++;
					break;
				case 2:
					LED_Config.LED_Port = PORT_A ;
					LED_Config.LED_Pin = PIN2 ;
					LED_ERROR = ECUAL_LED_ON(&LED_Config);
					Count++;
					break;
				case 3:
					LED_Config.LED_Port = PORT_A ;
					LED_Config.LED_Pin = PIN3 ;
					LED_ERROR = ECUAL_LED_ON(&LED_Config);
					Count++;
					break;
				case 4:
					LED_Config.LED_Port = PORT_A ;
					LED_Config.LED_Pin = PIN0 ;
					LED_ERROR = ECUAL_LED_OFF(&LED_Config);
					Count++;
					break;
				case 5:
					LED_Config.LED_Port = PORT_A ;
					LED_Config.LED_Pin = PIN1 ;
					LED_ERROR = ECUAL_LED_OFF(&LED_Config);
					Count++;
					break;
				case 6:
					LED_Config.LED_Port = PORT_A ;
					LED_Config.LED_Pin = PIN2 ;
					LED_ERROR = ECUAL_LED_OFF(&LED_Config);
					break;
				case 7:
					LED_Config.LED_Port = PORT_A ;
					LED_Config.LED_Pin = PIN3 ;
					LED_ERROR = ECUAL_LED_OFF(&LED_Config);
					Count=0;
					break;
			}
			while(buttonValue==High){
				BUTTON_ERROR = ECUAL_BUTTON_Read(&Button_Config,&buttonValue);
			}
		}*/
	}
}