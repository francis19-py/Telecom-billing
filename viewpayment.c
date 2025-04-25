//Function to viewpayment for a customer
#include "viewpayment.h"
#include <stdio.h>
void viewpayment (const char *phoneNumber)
{
    for (int i =0; i < customerCount; i++){
        if (strcmp(customers[i].phoneNumber, phoneNumber)==0){
            printf("\nTotal Bill for %s: $%.2f\n", customers[i].name, customers[i].totalBill);
            return;
        }
    }
     printf("\nRecord not found!\n");
}
