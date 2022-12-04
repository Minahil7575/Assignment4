void searchPatientRecord(void); //function prototype

void searchPatientRecord(void) //function definition
{
	FILE* fPtr = NULL; //declaring a file pointer
	PATIENT searchPatient, patient; // declaring variables of type struct
	int check = 0;

	if ((fPtr = fopen("Patient_Record.txt", "r")) == NULL) // display error in case file could not be opened
	{
		puts("File could not be opened");
	}
	else //opening a file
	{
		system("cls"); //clearing screen
		printf("\n\n\n-------------------------------------------------------\n");
		printf("\t\t\tSEARCH MENU\n"); //displaying search menu
		printf("\t\t\tWhat do you want to search?\n");
		printf("-------------------------------------------------------\n\n");
		printf("\t%s\t\t%s\n", "1. Patient ID", "2. Name");
		printf("\t%s\t\t\t%s\n", "3. CNIC", "4. Phone Number");
		printf("\t%s\t\t%s\n", "5. Disease", "6. Status");
		printf("\t%s", "7. Return to main MENU");
		printf("\n-------------------------------------------------------\n\n");


		int choice; //declaring an integer type variable
	label6:
		printf("\tMake a slection from above: "); //asking what user want to do
		scanf_s("  %d", &choice); //taking input of choice
		switch (choice) //considering choice
		{
		case 1: //if user enter 1 then search by ID
			system("cls"); //clearing screen
			printf("\n\n\n-------------------------------------------------------\n");
			printf("\tEnter ID of a Patient: "); //asking for input
			scanf_s("  %14[^\n]s", &searchPatient.patientID, 14);//searching for ID
			strupr(searchPatient.patientID); //converting string to uppercae
			fseek(fPtr, 0 * sizeof(PATIENT), SEEK_SET); //moving pointer to  specific place
			for (int i = 0; !feof(fPtr); i++) //until the end of file
			{
				fseek(fPtr, i * sizeof(PATIENT), SEEK_SET); //moving fptr to a specific point
				fread(&patient, sizeof(PATIENT), 1, fPtr); //read from a file
				if (strcmp(searchPatient.patientID, patient.patientID) == 0
					&& !feof(fPtr)) 
				{
					check = 1; //loop is executed only once
					//display complete info
					printf("\n\n\n-------------------------------------------------------\n\n");
					printf("\tPatient ID: %s\n", patient.patientID);
					printf("\tName: %s\n", patient.name);
					printf("\tCNIC: %llu\n", patient.CNIC);
					printf("\tPhone Number: %llu\n", patient.phoneNumber);
					printf("\tDisease: %s\n", patient.disease);
					printf("\tIs Admitted: %s\n", patient.isAdmitted);
					printf("-------------------------------------------------------\n\n");
				}
			}
			break; //end the loop
		case 2: // if user enter 2 then search by name
			system("cls"); //clear screen
			printf("\n\n\n-------------------------------------------------------\n");
			printf("\tEnter name of a Patient: "); //asking for input of name
			scanf_s("  %24[^\n]s", &searchPatient.name, 24); //taking name of user
			strupr(searchPatient.name);
			for (int i = 0; !feof(fPtr); i++) //until the end of file
			{
				fseek(fPtr, i * sizeof(PATIENT), SEEK_SET); //moving fptr to a specific postion
				fread(&patient, sizeof(PATIENT), 1, fPtr);
				if (strcmp(searchPatient.name, patient.name) == 0
					&& !feof(fPtr))
				{
					check = 1;// printing the complete info
					printf("\n\n\n-------------------------------------------------------\n\n");
					printf("\tPatient ID: %s\n", patient.patientID);
					printf("\tName: %s\n", patient.name);
					printf("\tCNIC: %llu\n", patient.CNIC);
					printf("\tPhone Number: %llu\n", patient.phoneNumber);
					printf("\tDisease: %s\n", patient.disease);
					printf("\tIs Admitted: %s\n", patient.isAdmitted);
					printf("-------------------------------------------------------\n\n");

				}
			}
			break; //end of loop
		case 3: //if user enter 3 then print the info on the basis of CNIC
			system("cls"); //clear screen
			//asking for input and moving the fptr to a specific position 
			printf("\n\n\n-------------------------------------------------------\n");
			printf("\tEnter CNIC number of a Patient: ");
			scanf_s("  %16[^\n]s", &searchPatient.CNIC, 16);
			strupr(searchPatient.CNIC);
			for (int i = 0; !feof(fPtr); i++)
			{
				fseek(fPtr, i * sizeof(PATIENT), SEEK_SET);
				fread(&patient, sizeof(PATIENT), 1, fPtr);
				if (strcmp(searchPatient.CNIC, patient.CNIC) == 0)
					//printing the whole info
				{
					check = 1;
					printf("\n\n\n-------------------------------------------------------\n\n");
					printf("\tPatient ID: %s\n", patient.patientID);
					printf("\tName: %s\n", patient.name);
					printf("\tCNIC: %llu\n", patient.CNIC);
					printf("\tPhone Number: %llu\n", patient.phoneNumber);
					printf("\tDisease: %s\n", patient.disease);
					printf("\tIs Admitted: %s\n", patient.isAdmitted);
					printf("-------------------------------------------------------\n\n");
				}
			}
			break;
		case 4: //if 4 is entered then diplay info on the basis of phone num
			system("cls"); //clearing screen and asking for input and displaying the complete info
			printf("\n\n\n-------------------------------------------------------\n");
			printf("\tEnter Phone Number of a Patient: ");
			scanf_s("  %14[^\n]s", &searchPatient.phoneNumber, 14);
			strupr(searchPatient.phoneNumber);
			for (int i = 0; !feof(fPtr); i++)
			{
				fseek(fPtr, i * sizeof(PATIENT), SEEK_SET);
				fread(&patient, sizeof(PATIENT), 1, fPtr);
				if (strcmp(searchPatient.phoneNumber, patient.phoneNumber) == 0
					&& !feof(fPtr))
				{
					check = 1;
					printf("\n\n\n-------------------------------------------------------\n\n");
					printf("\tPatient ID: %s\n", patient.patientID);
					printf("\tName: %s\n", patient.name);
					printf("\tCNIC: %llu\n", patient.CNIC);
					printf("\tPhone Number: %llu\n", patient.phoneNumber);
					printf("\tDisease: %s\n", patient.disease);
					printf("\tIs Admitted: %s\n", patient.isAdmitted);
					printf("-------------------------------------------------------\n\n");

				}
			}
			break;
		case 5://if 5 is entered then diplay info on the basis of disease
			system("cls"); //clearing screen and asking for input and displaying the complete info
			
			printf("\n\n\n-------------------------------------------------------\n");
			printf("\tEnter name of Disease: ");
			scanf_s("  %199[^\n]s", &searchPatient.disease, 199);
			strupr(searchPatient.disease);
			for (int i = 0; !feof(fPtr); i++)
			{
				fseek(fPtr, i * sizeof(PATIENT), SEEK_SET);
				fread(&patient, sizeof(PATIENT), 1, fPtr);
				if (strcmp(searchPatient.disease, patient.disease) == 0
					&& !feof(fPtr))
				{
					check = 1;
					printf("\n\n\n-------------------------------------------------------\n\n");
					printf("\tPatient ID: %s\n", patient.patientID);
					printf("\tName: %s\n", patient.name);
					printf("\tCNIC: %llu\n", patient.CNIC);
					printf("\tPhone Number: %llu\n", patient.phoneNumber);
					printf("\tDisease: %s\n", patient.disease);
					printf("\tIs Admitted: %s\n", patient.isAdmitted);
					printf("-------------------------------------------------------\n\n");

				}
			}
			break;
		case 6: //if 4 is entered then diplay info on the basis of status
			system("cls"); //clearing screen and asking for input and displaying the complete info
			
			printf("\n\n\n-------------------------------------------------------\n");
			printf("\tIs patient admitted? (YES/NO)): ");
			scanf_s("  %4[^\n]s", &searchPatient.isAdmitted, 4);
			strupr(searchPatient.isAdmitted);
			while (strcmp(searchPatient.isAdmitted, "YES") != 0
				&& strcmp(searchPatient.isAdmitted, "NO") != 0)
			{
				printf("\tWrong!\n): ");
				printf("\tIs patient is admitted? (YES/NO): ");
				scanf_s("  %4[^\n]s", &searchPatient.isAdmitted, 4);
				strupr(searchPatient.isAdmitted);
			}
			for (int i = 0; !feof(fPtr); i++)
			{
				fseek(fPtr, i * sizeof(PATIENT), SEEK_SET);
				fread(&patient, sizeof(PATIENT), 1, fPtr);
				if (strcmp(searchPatient.isAdmitted, patient.isAdmitted) == 0
					&& !feof(fPtr))
				{
					check = 1;
					printf("\n\n\n-------------------------------------------------------\n\n");
					printf("\tPatient ID: %s\n", patient.patientID);
					printf("\tName: %s\n", patient.name);
					printf("\tCNIC: %llu\n", patient.CNIC);
					printf("\tPhone Number: %llu\n", patient.phoneNumber);
					printf("\tDisease: %s\n", patient.disease);
					printf("\tIs Admitted: %s\n", patient.isAdmitted);
					printf("-------------------------------------------------------\n\n");

				}
			}
			break;
		case 7: //go back to menu
			return;
			break;
		default: //move to label 6
			goto label6;
		}
	}

	if (check == 0)
	{
		printf("\n-------------------------------------------------------\n");
		printf("\tNO record found.");
		printf("\n-------------------------------------------------------\n\n");
		Sleep(3000);
	}
	Sleep(3000);
	searchPatientRecord();
}