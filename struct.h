struct patientRecord //defining a user defined variable containing further variables
{
	char patientID[15]; //user ID
	char name[25]; //user name
	unsigned long long CNIC; //user ID card number
	unsigned long long phoneNumber; //user's phone no
	char disease[200]; //name of disease
	char isAdmitted[5]; //user's status
};

typedef struct patientRecord PATIENT; //"patient" is the name of struct
#pragma warning (disable : 4996)