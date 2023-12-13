#ifndef card
#define card

typedef unsigned char uint8_t;

typedef enum EN_cardError_t
{
	OK,
	WRONG_NAME,
	WRONG_EXP_DATE,
	WRONG_PAN,
}EN_cardError_t;

typedef struct ST_cardData_t
{
	uint8_t cardHolderName;
	uint8_t primaryAccountNumber[20];
	uint8_t cardExpirationDate[7];
}ST_cardData_t;



EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
EN_cardError_t getCardPAN(ST_cardData_t* cardData);
#endif