void updatePatientRecord(void)//function definition

{
	FILE* fPtr = NULL; //declaring a file pointer
	PATIENT searchPatient, patient; // declaring a variable of type struct
	int check = 0;
	system("cls"); //clearing screen

	if ((fPtr = fopen("Patient_Record.txt", "r+")) == NULL) // display error in case file could not be opened
	{
		puts("File could not be opened");
	}
	else //opening a file
	{
		printf("\n\n\n-------------------------------------------------------\n\n");
		printf("\tEnter ID of a Patient: "); //asking fp/or what user want to update
		scanf_s("  %14[^\n]s", &searchPatient.patientID, 14); //takig input
		strupr(searchPatient.patientID); //converting to uppercase
		system("cls"); //clearing screen
		for (int i = 0; !feof(fPtr); i++) //until the end of file
		{
			fseek(fPtr, i * sizeof(PATIENT), SEEK_SET); //move the pointer to a specific position
			fread(&patient, sizeof(PATIENT), 1, fPtr); //read from file

			if (strcmp(searchPatient.patientID, patient.patientID) == 0) //comparing strings
			{
			label1:
				check = 1;
				system("cls"); //clearing screen and displaying complete info of patient
				printf("\n\n\n-------------------------------------------------------\n\n");
				printf("\tPatient ID: %s\n", patient.patientID);
				printf("\tName: %s\n", patient.name);
				printf("\tCNIC: %llu\n", patient.CNIC);
				printf("\tPhone Number: %llu\n", patient.phoneNumber);
				printf("\tDisease: %s\n", patient.disease);
				printf("\tIs Admitted: %s\n\n\n", patient.isAdmitted);
				//asking for update and printing update menu
				printf("-------------------------------------------------------\n");
				printf("\t\t\tUpdate MENU\n");
				printf("-------------------------------------------------------\n\n");
				printf("\t%s\t\t\t%s\n", "1. Patient ID", "2. Name");
				printf("\t%s\t\t\t\t%s\n", "3. CNIC", "4. Phone Number");
				printf("\t%s\t\t\t%s\n", "5. Disease", "6. Status");
				printf("\t%s\n", "7. Return to MENU");
				printf("-------------------------------------------------------\n\n");

				int choice; //declaring integer
			label2:
				printf("\tMake selection from above: ");
				scanf_s("  %d", &choice);
				system("cls");
				printf("\n\n\n-------------------------------------------------------\n\n\t");
				switch (choice)
				{
				case 1: //if user enter 1 change ID
					scanf_s("  %14[^\n]s", &patient.patientID, 14);
					strupr(patient.patientID);
					break;
				case 2: //if user enter 2 change NAME
					scanf_s("  %24[^\n]s", &patient.name, 24);
					strupr(patient.name);
					break;
				case 3://if user enter 3 change CNIC
					scanf_s("  %llu", &patient.CNIC, 16);
					break;
				case 4://if user enter 4 change PHOME NO
					scanf_s("  %llu", &patient.phoneNumber, 14);
					break;
				case 5://if user enter 5 change DISEASE 
					scanf_s("  %199[^\n]s", &patient.disease, 199);
					strupr(patient.disease);
					break;
				case 6://if user enter 6 change STATUS
					scanf_s("  %4[^\n]s", &patient.isAdmitted, 4);
					strupr(patient.isAdmitted);
					while (strcmp(patient.isAdmitted, "YES") != 0 //if status already exist display error and ask again
						&& strcmp(patient.isAdmitted, "NO") != 0)
					{
						printf("\tPatient's status is same, Enter again:!\n ");
						printf("\tIs patient admitted? (YES/NO): ");
						scanf_s("  %4[^\n]s", &patient.isAdmitted, 4);
						strupr(patient.isAdmitted);
					}
					break;
				case 7: //move to menu
					return;
					break;
				default: //if any other number entered display error and ask again
					printf("ERROR!\n");
					goto label2;
					break;
				}

				fseek(fPtr, i * sizeof(PATIENT), SEEK_SET);
				fwrite(&patient, sizeof(PATIENT), 1, fPtr); 
				goto label1;
			}
		}
	}

	if (check == 0) //if check is equal t zero then display eror
	{
		printf("\n-------------------------------------------------------\n");
		printf("\tNO record found.");
		printf("\n-------------------------------------------------------\n\n");
		Sleep(3000);
	}
}