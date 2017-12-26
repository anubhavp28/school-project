#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <process.h>
#include <iomanip.h>
#include <stdio.h>
#include <string.h>
#include "tables.cpp"
#include "datepicker.cpp"
#include "classman.cpp"
#include "houseman.cpp"
#include "studman.cpp"

void main()
{  int x;
	studentManager z;
	cout<<endl<<"\t\t\tSTUDENT RECORD MANAGEMENT SYSTEM";
	char m0[][50] = {"Student Record Maintance","Class Record Maintance", "House Record Maintance","Exit"};
	char m1[][50] = {"Insert Student","Search By ID", "Search By Name" ,"Display Records", "Delete Record", "Update Record", "Go Back"};
	char m2[][50] = {"Insert Class","Display Records","Delete Record", "Go Back"};
	char m3[][50] = {"Insert House","Display Records","Delete Record", "Go Back"};
	start:
	gui::createOptionForm(m0,4);
	cout<<endl<<"Enter your choice : ";
	cin>>x;
	switch(x)
	{
		case 1:
			clrscr();
			gui::createOptionForm(m1,6);
			cout<<endl<<"Enter your choice : ";
			cin>>x;
			switch (x)
			{
				case 1: z.insert();
					getch();
					clrscr();
					goto start;
					break;
				case 2:
					clrscr();
					int id;
					cout<<endl<<"Enter Id to Search : ";
					cin>>id;
					z.searchById(id);
					cout<<"\nPress any key to go back....";
					getch();
					clrscr();
					goto start;
					break;
				case  3:
					clrscr();
					char fname[20],lname[20];
					cout<<endl<<"Enter First Name to Search : ";
					cin>>fname;
					cout<<"Enter Last Name to Search : ";
					cin>>lname;
					z.searchByName(fname,lname);
					cout<<"\nPress any key to go back....";
					getch();
					clrscr();
					goto start;
					break;
				case 4:
					clrscr();
					z.display();
					cout<<"\nPress any key to go back....";
					getch();
					clrscr();
					goto start;
					break;
				case 5:
					clrscr();
					z.delete_();
					cout<<"\nPress any key to go back....";
					getch();
					clrscr();
					goto start;
					break;
				case 6:
               clrscr();
					z.update();
					cout<<"\nPress any key to go back....";
					getch();
					clrscr();
					goto start;
					break;

			}
			break;
		case 2:
			clrscr();
			gui::createOptionForm(m2,4);
			cout<<endl<<"Enter your choice : ";
			cin>>x;
			switch (x)
			{
				case 1:
					clrscr();
					C.insert();
					cout<<"\nPress any key to go back....";
					getch();
					clrscr();
					goto start;
					break;
				case 2:
					clrscr();
					C.display();
					cout<<"\nPress any key to go back....";
					getch();
					clrscr();
					goto start;
					break;
				case 3:
					clrscr();
					C.delete_();
					cout<<"\nPress any key to go back....";
					getch();
					clrscr();
					goto start;
					break;
				case 4:
					clrscr();
					goto start;
					break;
			 }
			 break;
		case 3:
			clrscr();
			gui::createOptionForm(m3,4);
			cout<<endl<<"Enter your choice : ";
			cin>>x;
			switch (x)
			{
				case 1:
					clrscr();
					H.insert();
					cout<<"\nPress any key to go back....";
					getch();
					clrscr();
					goto start;
					break;
				case 2:
					clrscr();
					H.display();
					cout<<"\nPress any key to go back....";
					getch();
					clrscr();
					goto start;
					break;
				case 3:
					clrscr();
					H.delete_();
					cout<<"\nPress any key to go back....";
					getch();
					clrscr();
					goto start;
					break;
				case 4:
               clrscr();
					goto start;
					break;
			 }
			 break;

		case 4:
			exit(0);
	}

exit(0);
}

 
