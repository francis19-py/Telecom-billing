//function to view payments
void viewRecords () {
    printf("\n Name\tPhone Number\tUsage(min)\tTotal Bill($)\n");
    for (int i = 0; i < customerCount; i++){
        printf("%s\t%s\t%.2f\t\t%.2f\n", customers[i].name, customers[i].phoneNumber, customers[i].usage, customers[i].TotalBill);
    }
}