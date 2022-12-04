// including user defined header files and standard header files
#include<stdio.h>
#include<string.h>
#include<time.h>
#include"Struct.h"
#include"menu.h"
#include"Add.h"
#include"Delete.h"
#include"Update.h"
#include"Search.h"
#include"DisplayAllRecords.h"

int main() //main
{
	switch (menu()) 
	{
	case 1:
		addPatientREcord(); //functionCall (defined in header file)
		break;
	case 2:
		deletePatientRecord(); //functionCall (defined in header file)
		break;
	case 3:
		updatePatientRecord(); //functionCall (defined in header file)
		break;
	case 4:
		searchPatientRecord(); //functionCall (defined in header file)
		break;
	case 5:
		displayAllRecords(); //functionCall (defined in header file)
		break;
	default:
		printf("Wrong!\n"); //display error in case of wrong input
		Sleep(2000); //Pausing the console for 2 seconds
		break;

	}
	main();
	return 0; //end os main
}