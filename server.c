#include <stdio.h>
#include "server.h"
#include "card.h" 

#include <string.h>

int counter=0,accountSearch=0;

ST_accountsDB_t accounts[255] = {
    { 500.5,"12345678901234567"},
    {558.3,"12345678901445677" }
};
ST_transaction_t transaction[255] = {0};

EN_transState_t receiveTransactionData(ST_transaction_t* transData)
{
    
    for (counter = 0; counter < 254; counter++)
    {
        if (strcmp(transData->cardHolderData.primaryAccountNumber, transaction[counter].cardHolderData.primaryAccountNumber) == 0)
        {
            for (counter = 0; counter < 254; counter++)
            {
                if (strcmp(transData->cardHolderData.primaryAccountNumber, accounts[counter].primaryAccountNumber) == 0)
                {
                    if (accounts[counter].balance >= transData->terminalData.transAmount)


                    {
                        
                        accounts[counter].balance -= transData->terminalData.transAmount;
                        printf("New Balance= %f EGP \n", accounts[counter].balance);
                        return APPROVED;


                    }
                    else
                    {
                        printf("DECLINED_INSUFFECIENT_FUND\n");
                        return DECLINED_INSUFFECIENT_FUND;


                    }
                }
            }
        }
    }



    printf("DECLINED_STOLEN_CARD\n");

    return DECLINED_STOLEN_CARD;
    }




EN_serverError_t isValidAccount(ST_cardData_t* cardData)
{
    uint8_t choice=0 ;
    printf("Do you want to block your card from the system?(Y/N)\n");
    clear();
    scanf("%c",&choice);

    for (counter = 0; counter < 254; counter++) 
    {
        
            if (strcmp(cardData->primaryAccountNumber, accounts[counter].primaryAccountNumber) == 0)
            {
                switch (choice) {
                case 'y':
                case 'Y':



                    memcpy(&accounts[counter].primaryAccountNumber, NULL, sizeof(ST_cardData_t));
                    return DONE;
                    break;


                case 'N':
                case 'n':
                {

                    return ACCOUNT_NOT_FOUND;
                    break;



                }
                default:
                    printf( "Invalid");



                }
                

            }
        
       
        
     
    
    }
    
    return DECLINED_STOLEN_CARD;
    





}




EN_serverError_t isAmountAvailable(ST_terminalData_t* termData) 
{
    if ((termData->transAmount) <= (accounts[counter].balance))
{

        return OK;


}
    else 
    {
        
        return LOW_BALANCE;
    
    }


}

EN_serverError_t saveTransaction(ST_transaction_t* transData) 
{
    static uint8_t Seq_counter=0;
   

    memcpy(&transaction[Seq_counter], transData, sizeof(ST_transaction_t));
    transaction[counter].transactionSequenceNumber=Seq_counter;
    
    accountSearch = Seq_counter;
    
    Seq_counter++;
}



        




        
    



