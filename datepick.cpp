#include "gui.cpp"

class datePicker
{

int _validate(int day,int month,int year)
{
		if (year <0) return 0;
		if (month >12 || month <1) return 0;
		if (day >31 || day <1) return 0;
		if ((day ==31 && ( month ==2 || month ==4 || month ==6 || month ==9 || month ==11) ) ) return 0;
		if ( day ==30 && month ==2) return 0;
		if ( year <2000)
		{
			if ((day ==29 && month ==2) && !((year -1900)%4==0)) return 0;
		}
		if ( year >2000)
		{
				if ((day ==29 && month ==2) && !((year -2000)%4==0)) return 0;
		}
		return 1;
}

public :

date getDate()
{
 date d;
	while(1)
	{
	cout<<"\nEnter Day (0-31) : ";
	cin>>d.d;
	cout<<"\nEnter Month (1-12) : ";
	cin>>d.m;
	cout<<"\nEnter Year (1990-20XX) : ";
	cin>>d.y;
	if (!_validate(d.d,d.m,d.y))
		gui::createErrorMsgBox("Wrong Date Entered (Press Enter To Exit)");
	else
		return d;
	}
}

};

datePicker D;
     /*
void main()
{
 datePicker d;
 d.getDate();
}         */
