int menu(); //function prototype

int menu() //function defintion
{
	system("cls"); //clear screen
	printf("\n\n\n-------------------------------------------------------\n");
	printf("\t\t\t \"WELCOME\"\n");
	printf("\t\t  HOW CAN WE HELP YOU?\n");
	printf("\t\t\tHOSPTAL MENU\n"); //printing the menu
	printf("-------------------------------------------------------\n\n");
	printf("%s%40s\n\n", "1. Add Patient", "2. Delete Patient");
	printf("%s%37s\n\n", "3. Update Patient", "4. Search Patient");
	printf("%s\n\n", "5. Display All Patients");
	printf("-------------------------------------------------------\n\n");
	int choice; //declaring a variable for choice

	printf("\nEnter your choice: "); //asking for input
	scanf_s("%d", &choice); //taking input

	return choice; //returning choice 
}