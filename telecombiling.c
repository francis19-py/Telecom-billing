#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CUSTOMERS 100

//struct holding customer information

struct customer {
    char name[50];
    char phoneNumber[15];
    float usage;
    float totalBill;
};
//array to store customer data.
struct customer customers[MAX_CUSTOMERS];
//global variable for customers
int customerCount = 0;
//clear  input buffer 
void clearInputBuffer () {
    int c;
    while ((c = getchar ()) != '\n' && c != EOF);
}
//validate phonenumber (digits only)
int isValidPhoneNumber(const char *phone){
    for(int i = 0; phone[i]; i++){
        if(!isdigit(phone[i])) return 0;
    }
    return 1;
}

// Function to add a new customer record 
void addRecord() 
{ 
	if (customerCount >= MAX_CUSTOMERS) {
		printf("\nMaximum number of records reached!\n");
		return;
	}
	printf("\nEnter name: ");
        if (fgets(customers[customerCount].name, sizeof(customers[customerCount].name),stdin)== NULL){
			printf("Error reading name.\n");
			return;
		}
	customers[customerCount].name[strcspn(customers[customerCount].name,"\n")]='\0';
	
	printf("Enter phone number: "); 
	scanf("%14s", customers[customerCount].phoneNumber); 
	clearInputBuffer();
	if(!isValidPhoneNumber(customers[customerCount].phoneNumber)) {
		printf("Invalid phone number .Must be numeric.\n");
		return;
	}
	printf("Enter usage (in minutes): "); 
		if(scanf("%f", &customers[customerCount].usage) !=1 || customers[customerCount].usage < 0){
			printf("Invalid usage amount . MUst be a positive number.\n");
			clearInputBuffer();
			return;
		}
	clearInputBuffer();
	customers[customerCount].totalBill = customers[customerCount].usage * 0.1; 
		customerCount++; 
		printf("\nRecord added successfully!\n"); 
	} 

// Fucntion to modify a customer record
void modifyRecord(const char *phoneNumber)
{
    for (int i = 0; i < customerCount; i++)
    {
        if (strcmp(customers[i].phoneNumber, phoneNumber) == 0)
        {       
        printf("\nEnter new usage (in minutes) for %s:", customers[i].name);
        if (scanf("%f", &customers[i].usage)!= 1 ||customers[i].usage<0){
            printf("Invalid usage amount.\n");
            clearInputBuffer();
            return;
        }
        clearInputBuffer();
        customers[i].totalBill = customers[i].usage * 0.1;
        printf("\nRecord modified successfully!\n");
        return;
    }
    }
    printf("\nRecord not found!\n");
}

//function to view records
void viewRecords () {
    if (customerCount == 0){
        printf("\n No records to display.\n");
        return;
    }
    printf("\n Name\tPhone Number\tUsage(min)\tTotal Bill($)\n");
    for (int i = 0; i < customerCount; i++){
        printf("%s\t%s\t%.2f\t\t%.2f\n", customers[i].name, customers[i].phoneNumber, customers[i].usage, customers[i].totalBill);
    }
}

//function to delete records
void deleteRecord(const char *phoneNumber) { 
	for (int i = 0; i < customerCount; i++) { 
		if (strcmp(customers[i].phoneNumber, phoneNumber) == 0) { 
			for (int j = i; j < customerCount - 1; j++) { 
				customers[j] = customers[j + 1]; 
			} 
			customerCount--; 
			printf("\nRecord deleted successfully!\n"); 
			return; 
		} 
	} 
	printf("\nRecord not found!\n"); 
}

//function to search records
void searchRecord(char phoneNumber[]) { 
	printf("\nName\tPhone Number\tUsage(min)\tTotal Bill($)\n"); 
	for (int i = 0; i < customerCount; i++) { 
		if (strcmp(customers[i].phoneNumber, phoneNumber) == 0) { 
			printf("%s\t%s\t%.2f\t\t%.2f\n", customers[i].name, customers[i].phoneNumber, customers[i].usage, customers[i].totalBill); 
			return; 
		} 
	} 
	printf("\nRecord not found!\n"); 
}
 
//Function to viewpayment for a customer
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

void displayMenu ()
{
    printf("\n1.Add New Records\n");
    printf("2.View List of Records\n");
    printf("3.Modify Records\n");
    printf("4.View Payment\n");
    printf("5.Delete Record\n");
    printf("6.Exit\n");
}   

int main (){
    int choice;
    char phoneNumber[15];

    while(1){
        displayMenu();
        printf("Enter your choice: ");
        if(scanf("%d",&choice) != 1){
            printf("Invalid input . Please enter a number .\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        

        switch(choice){
        case 1:
               addRecord();
               break;
        case 2:
                viewRecords();
                break;       
        case 3:
                printf("\nEnter phone number to modify record: ");
                scanf(" %14s", phoneNumber);
                clearInputBuffer();
                modifyRecord(phoneNumber);
                break;
        case 4:
                printf("\nEnter phone number to view payment: ");
                scanf("%14s", phoneNumber);
                clearInputBuffer();
                viewpayment(phoneNumber);
                break;
        case 5:
                printf("\nEnter phone number to delete record:  ");
                scanf("%14s", phoneNumber);
                clearInputBuffer();
                deleteRecord(phoneNumber); 
                break;
        case 6:
                printf("exiting the program . bye!");
        default:
            printf("\n Invalid choice! PLease try again.\n");

        }
    }
    return 0;
}
