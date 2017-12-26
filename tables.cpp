
#define classTable   "CLASSDB"
#define houseTable 	"HOUSESDB"
#define studentTable "STUDDB"



struct date{
	int m;
	int d;
	int y;
};

struct class_{
	int classCode;
	char className[10];
};

struct student{
	int studId;
	date AdmDate;
	date DOB;
	char fName[20];
	char lName[20];
	char bloodGroup[3];
	char sex;
	char father[30];
	char mother[30];
	int classCode;
	int houseCode;
	char add[100];
	unsigned long int pin;
	char phone[15];
};

struct tc{
	int tcNo;
	date tcDate;
	int studId;
};

struct house{
	int houseCode;
	char houseName[15];
};

