// Function to modify a customer record
void modifyRecord(char phoneNumber[])
{
    for (int i = 0; i < customerCount; i++)
    {
        if (strcmp(customer[i].phoneNumber, phoneNumber) == 0)
    {
        printf("\nEnter new usage (in minutes) for %s:", custemers[i].name);
        scanf("%f", &customers[i].usage);
        customers[i].totalBill = customers[i].usage * 0.1;
        printf("\nRecord modified successfully!\n");
        return;
    }
    }
    printf("\nRecord not found!\n");
}
