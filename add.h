void addPatientREcord(); //function prototype

void addPatientREcord() //function definition
{

	FILE* fPtr = NULL; //declaring and initializing  file pointers
	FILE* readPtr = NULL;
	PATIENT newPatient, patient; //declaring variables of type struct
	system("cls"); //clearing screen
	if ((fPtr = fopen("Patient_Record.txt", "a+")) == NULL) //display error in case file could not be opened
	{
		puts("File could not be opened");
	}
	else //opening a file
	{
		if ((readPtr = fopen("Patient_Record.txt", "r")) == NULL) //display error in case file could not be opened
		{
			puts("File could not be opened");
		}
		else //opening file
		{
			printf("\n\n\n-------------------------------------------------------\n\n");
			printf("\tEnter ID of a Patient: "); //asking for input of ID
			scanf_s("  %14[^\n]s", &newPatient.patientID, 14); //taking input from user
			strupr(newPatient.patientID); 

			for (int i = 0; !feof(readPtr); i++)
			{
				fseek(readPtr, i * sizeof(PATIENT), SEEK_SET);
				fread(&patient, sizeof(PATIENT), 1, readPtr);
				while (strcmp(newPatient.patientID, patient.patientID) == 0)
				{
					printf("\tWrong!\n\tThis ID matched with another patient's ID:");
					printf("\n\tEnter ID of a Patient: ");
					scanf_s("  %14[^\n]s", &newPatient.patientID, 14);
					strupr(newPatient.patientID);
					rewind(readPtr);
				}
			}

			printf("\tEnter name of a Patient: ");
			scanf_s("  %24[^\n]s", &newPatient.name, 24);
			strupr(newPatient.name);
			rewind(readPtr);
			printf("\tEnter CNIC number of a Patient: ");
			scanf_s("  %llu", &newPatient.CNIC);
			for (int i = 0; !feof(readPtr); i++)
			{
				fseek(readPtr, i * sizeof(PATIENT), SEEK_SET);
				fread(&patient, sizeof(PATIENT), 1, readPtr);
				while (newPatient.CNIC == patient.CNIC)
				{
					printf("\tWrong!\n\tThis CNIC number matched with another patient's CNIC number: ");
					printf("\n\tEnter CNIC number of a Patient: ");
					scanf_s("  %llu", &newPatient.CNIC);
					rewind(readPtr);
				}
			}
			rewind(readPtr);
			printf("\tEnter Phone Number of a Patient: ");
			scanf_s("  %llu", &newPatient.phoneNumber);
			for (int i = 0; !feof(readPtr); i++)
			{
				fseek(readPtr, i * sizeof(PATIENT), SEEK_SET);
				fread(&patient, sizeof(PATIENT), 1, readPtr);
				while (newPatient.phoneNumber == patient.phoneNumber)
				{
					printf("\tWrong!\n\tThis Phone Number matched with another patient's Phone Number.");
					printf("\n\tEnter Phone Number of a Patient: ");
					scanf_s("  %llu", &newPatient.phoneNumber);
					rewind(readPtr);
				}
			}
			printf("\tEnter name of Disease: ");
			scanf_s("  %199[^\n]s", &newPatient.disease, 199);
			strupr(newPatient.disease);
			printf("\tIs patient is admitted? (YES/NO): ");
			scanf_s("  %4[^\n]s", &newPatient.isAdmitted, 4);
			strupr(newPatient.isAdmitted);
			printf("%s", newPatient.isAdmitted);
			while (strcmp(newPatient.isAdmitted, "YES") != 0
				&& strcmp(newPatient.isAdmitted, "NO") != 0)
			{
				printf("\tWrong!\n ");
				printf("\tIs patient is admitted? (YES/NO): ");
				scanf_s("  %4[^\n]s", &newPatient.isAdmitted, 4);
				strupr(newPatient.isAdmitted);
			}

			fclose(readPtr);
		}

		fwrite(&newPatient, sizeof(PATIENT), 1, fPtr);
	}
	fclose(fPtr);
}