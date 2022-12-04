void displayAllRecords(void); //function prototype


void displayAllRecords(void) //function definition
{
	FILE* fPtr = NULL; //declaring a file pointer
	PATIENT patient; // declaring a variable of type struct
	int check = 0; //declaring an integer
	system("cls"); //clearing screen

	if ((fPtr = fopen("Patient_Record.txt", "r")) == NULL) //display error in case file could not be opened
	{
		puts("File could not be opened");
	}
	else //opening a file
	{
		for (int i = 0; !feof(fPtr); i++) //until the file ends
		{
			fseek(fPtr, i * sizeof(PATIENT), SEEK_SET); //moving fptr to a specific location
			fread(&patient, sizeof(PATIENT), 1, fPtr); //read from file
			if (!feof(fPtr))
			{
				check = 1; 
				if (i == 0) //loop will be executed only once(first loop)
				{
					//printing all the records of all the patients
					printf("\n\n\n-------------------------------------------------------\n");
					printf("\t\tRecord of all Patients\n");
					printf("-------------------------------------------------------\n\n");
				}
				printf("-------------------------------------------------------\n\n");
				printf("\tPatient ID: %s\n", patient.patientID); //printing ID
				printf("\tName: %s\n", patient.name); //printing NAME
				printf("\tCNIC: %llu\n", patient.CNIC); //printing CNIC
				printf("\tPhone Number: %llu\n", patient.phoneNumber); //printing PHONE NO
				printf("\tDisease: %s\n", patient.disease); //printing DISEASE
				printf("\tIs Admitted: %s\n", patient.isAdmitted); //printing STATUS
				printf("-------------------------------------------------------\n\n");
			}
		}
		fclose(fPtr); //closing the file
	}
	if (check == 0) //if check point is equal to zero display that no such record found
	{
		printf("\n-------------------------------------------------------\n\n");
		printf("\t\t\tNO such record found.");
		printf("\n-------------------------------------------------------\n\n");
	}
	int choice; //declaring an integer type variable
label3:
	printf("\tEnter 1 to go back to the main menu: "); //going to main menu
	scanf_s("  %d", &choice); //taking input of choice
	switch (choice)
	{
	case 1: //if choice is 1 go back to main menu
		return;
		break;
	default:
		printf("\tYou didn't press the right key, Enter again:\n"); //displaying error and asking again
		goto label3; // moving back to ask for exit
	}
}