#include <string.h>
#include <stdio.h>
#include "terminal.h"



EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{

	uint8_t Transaction_Date_length;
	printf("Please Enter Transaction Date (DD/MM/YYYY) \n");
	gets(termData->transactionDate);
	Transaction_Date_length = strlen(termData->transactionDate);

	if ((termData->transactionDate == NULL) || (Transaction_Date_length !=10) || (termData->transactionDate[2] != '/') || (termData->transactionDate[5] != '/'))
	{
		
		return WRONG_DATE;
	}
	else
	{
		
		return OK;

	}
}

   /*                               MM/YY                      DD/MM/YYYY        */
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
	uint8_t expiration_date_year=0, transaction_date_year=0, expiration_date_month=0, transaction_date_month=0;

	transaction_date_year = (((termData.transactionDate[8]) - STRING_TO_INT) * INT_TO_TENS) + (termData.transactionDate[9]) - STRING_TO_INT;
	expiration_date_year  = (((cardData.cardExpirationDate[3]) - STRING_TO_INT) * INT_TO_TENS) + (cardData.cardExpirationDate[4]) - STRING_TO_INT;

	transaction_date_month = (((termData.transactionDate[3]) - STRING_TO_INT) * INT_TO_TENS) + (termData.transactionDate[4]) - STRING_TO_INT;
	expiration_date_month = (((cardData.cardExpirationDate[0]) - STRING_TO_INT) * INT_TO_TENS) + (cardData.cardExpirationDate[1]) - STRING_TO_INT;


	if (expiration_date_year < transaction_date_year)
	{
		printf("EXPIRED_CARD");
		exit();
			return EXPIRED_CARD;
	}
	else if(expiration_date_year==transaction_date_year)
	{
		if (expiration_date_month < transaction_date_month)
		{
			printf("EXPIRED_CARD");
			exit();
			return EXPIRED_CARD;
		}
		else
		{
			return OKAY;
		}
	}
	else 
	{
		return OKAY;
	}
}

EN_terminalError_t  getTransactionAmount(ST_terminalData_t* termData)
{

	printf("Please Enter transaction amount \n");
	scanf_s("%f", & termData->transAmount);
	if ((termData->transAmount) <= 0)
	{
		return INVALID_AMOUNT;
	}
	else 
	{
		return OKAY;
	}
}


EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) 
{
	if ((termData->maxTransAmount) < (termData->transAmount))
	{
		printf("EXCEED_MAX_AMOUNT");
		exit();
		return EXCEED_MAX_AMOUNT;
	}
	else
	{
		return OKAY;
	}
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
	printf("Enter max amount\n");
	scanf_s("%f", &(termData->maxTransAmount));
	if ((termData->maxTransAmount) <= 0)
	{
		return OKAY;
	}
	else
	{
		return INVALID_MAX_AMOUNT;
	}

}

