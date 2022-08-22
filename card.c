#include <string.h>
#include <stdio.h>
#include "card.h"
#include "terminal.h"



getCardHolderName(ST_cardData_t* cardData)
{
	uint8_t name_length;
	printf("Please Enter your name \n");
	gets(cardData->cardHolderName);
	name_length=strlen(cardData->cardHolderName);
	if ((cardData->cardHolderName == NULL) || (name_length < 20) || (name_length > 24))
	{
		
		return WRONG_NAME;

	}
	else
	{
	
		
		return OK;
	 
	}


}

getCardExpiryDate(ST_cardData_t* cardData) 
{
	uint8_t expiry_date_length;
	printf("Please Enter your card's expiry date (MM/YY) \n");
	gets(cardData->cardExpirationDate); 
	expiry_date_length = strlen(cardData->cardExpirationDate);
		
	if ((cardData->cardExpirationDate == NULL) || (expiry_date_length!=5) || (cardData->cardExpirationDate[2]!='/'))
	{
		
		return WRONG_EXP_DATE;
	}
	else 
	{
		
		return OK;
	 
	}

}

getCardPAN(ST_cardData_t* cardData) 
{
	uint8_t PAN_length=0;
	
	printf("Please Enter your card's Primary Account Number \n");
	
	gets(cardData->primaryAccountNumber);
	
	PAN_length = strlen(cardData->primaryAccountNumber);
	
	if (16 < PAN_length && PAN_length<19)//16-19
	{
		printf("valid\n");
		return OK;

	
	}
	else 
	{
		printf("invalid\n");
		return WRONG_PAN;
	
	}
}

