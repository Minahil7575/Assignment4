void deletePatientRecord(); //function prototype

void deletePatientRecord() //function definition
{
	PATIENT searchPatient, patient; // declaring a variable of type struct
	FILE* fPtr = NULL; //declaring a file pointer
	FILE* writeTempPtr = NULL; //declaring a file pointer
	FILE* readFPtr = NULL; //declaring a file pointer
	FILE* readTempPtr = NULL; //declaring a file pointer
	FILE* writeFPtr = NULL;//declaring a file pointer
	int check = 0;
	system("cls"); //clearing screen

	if ((fPtr = fopen("Patient_Record.txt", "r")) == NULL) //display error in case file could not be opened
	{
		puts("File could not be opened");
	}
	else //opening a file
	{
		printf("\n\n\n-------------------------------------------------------\n\n");
		printf("\tEnter ID of a Patient: "); //asking for ID
		scanf_s("  %14[^\n]s", &searchPatient.patientID, 14);
		strupr(searchPatient.patientID);
		for (int i = 0; !feof(fPtr); i++) //until the end of file
		{
			fseek(fPtr, i * sizeof(PATIENT), SEEK_SET); //fptr is moved to a specific place
			fread(&patient, sizeof(PATIENT), 1, fPtr);
			if (strcmp(searchPatient.patientID, patient.patientID) == 0)
			{
				check = 1;
				//opening the file or else displaying the error
				if ((writeTempPtr = fopen("Temporary_Patient_Record.txt", "w")) == NULL)
				{
					puts("File could not be opened");
				}
				else
				{
					if ((readFPtr = fopen("Patient_Record.txt", "r")) == NULL) //read file is opened
					{
						puts("File could not be opened");
					}
					else
					{
						
						for (int i = 0, j = 0; !feof(readFPtr); i++)
						{
							fseek(readFPtr, i * sizeof(PATIENT), SEEK_SET);
							fread(&patient, sizeof(PATIENT), 1, readFPtr);
							if (!(strcmp(searchPatient.patientID, patient.patientID) == 0)
								&& !feof(readFPtr))
							{
								fseek(writeTempPtr, j++ * sizeof(PATIENT), SEEK_SET);
								fwrite(&patient, sizeof(PATIENT), 1, writeTempPtr);
							}
						}
					}

					fclose(readFPtr); //closing the file
					fclose(writeTempPtr);
					fflush(writeTempPtr);

				}
			}
		}

		if ((writeFPtr = fopen("Patient_Record.txt", "w")) == NULL)
		{
			puts("File could not be opened");
		}
		else
		{
			if ((readTempPtr = fopen("Temporary_Patient_Record.txt", "r")) == NULL)
			{
				puts("File could not be opened");
			}
			else
			{
				for (int i = 0; !feof(readTempPtr); i++)
				{
					fseek(readTempPtr, i * sizeof(PATIENT), SEEK_SET);
					fread(&patient, sizeof(PATIENT), 1, readTempPtr);
					if (!feof(readTempPtr))
					{
						fseek(writeFPtr, i * sizeof(PATIENT), SEEK_SET);
						fwrite(&patient, sizeof(PATIENT), 1, writeFPtr);
					}
				}
			}
		}
		fclose(readTempPtr);
		fclose(writeFPtr);

	}

	fclose(fPtr);

	if (check == 0)
	{
		printf("\n-------------------------------------------------------\n");
		printf("\tNO record found.");
		printf("\n-------------------------------------------------------\n\n");
	}
	else
	{
		printf("\n-------------------------------------------------------\n");
		printf("\tRecord of this patient has been deleted.");
		printf("\n-------------------------------------------------------\n\n");
	}

	int choice;
label4:
	printf("\tEnter 1 to back: ");
	scanf_s("  %d", &choice);
	switch (choice)
	{
	case 1:
		return;
		break;
	default:
		printf("\tWrong!\n");
		goto label4;
	}
}