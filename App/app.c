#include "../Server/server.h"
#include"app.h"
#include <stdio.h>


void appStart(void) {
	while (1) {

		ST_transaction_t client = { 0 };

		getCardHolderName(client.cardHolderData.cardHolderName);
		getCardExpiryDate(&client.cardHolderData);
		getCardPAN(&client.cardHolderData);




		getTransactionDate(&client.terminalData);
		isCardExpired(client.cardHolderData, client.terminalData);

		setMaxAmount(&client.terminalData);
		getTransactionAmount(&client.terminalData);
		isBelowMaxAmount(&client.terminalData);

		isValidAccount(&client.cardHolderData);
		isAmountAvailable(&client.terminalData);

		saveTransaction(&client);
		receiveTransactionData(&client);

	  clear();
	  
	}
}

void main()
{
	appStart();
}