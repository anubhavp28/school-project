class houseManager
{	int lastCode;
	struct house _obj;
	public:

	houseManager()
	{	ifstream fin;
		fin.open(houseTable,ios::in);
		if (!fin || fin.eof())
		{
			lastCode = 0;
		}
		else
		{
			while(1)
			{	fin.read((char*)&_obj,sizeof(_obj));
				if(fin.eof()) break;
			}
			lastCode = _obj.houseCode;
		}
		fin.close();
	}

	void insert()
	{  ofstream fout;
		fout.open(houseTable,ios::out|ios::app);
		if (!fout) { clrscr(); cout<<" SOMETHING WENT WRONG !!! TRY ADDING RECORDS FIRST "; exit(1); }
		cout<<"Enter the details of the new house --- \n\n";
		cout<<"House Name -- ";
		gets(_obj.houseName);
		lastCode = lastCode + 1;
		_obj.houseCode = lastCode;
		fout.write((char*)&_obj,sizeof(_obj));
		cout<<"Written successfully!!";
		fout.close();

	}

	void display()
	{
		cout<<"\nHere is the list of houses in the school --- \n\n";
		ifstream fin;
		fin.open(houseTable,ios::in);
		if (!fin) { clrscr(); cout<<" SOMETHING WENT WRONG !!! TRY ADDING RECORDS FIRST "; exit(1); }\
		cout<<setw(10)<<"House Code"<<setw(18)<<"House Name"<<endl;
		while (1)
		{
			fin.read((char*)&_obj,sizeof(_obj));
			if (fin.eof()) break;
			cout<<setw(10)<<_obj.houseCode<<setw(18)<<_obj.houseName<<endl;
		}
		fin.close();
	}

	void delete_()
	{  int code;
		display();
		cout<<"Enter the House Code which you want to delete -- ";
		cin>>code;
		ifstream fin;

		fin.open(houseTable,ios::in);
		if (!fin) { clrscr(); cout<<" SOMETHING WENT WRONG !!! TRY ADDING RECORDS FIRST "; exit(1); }
		ofstream fout;
		fout.open("new",ios::out);
		while(1)
		{ 	fin.read((char*)&_obj,sizeof(_obj));
			if (fin.eof()) break;
			if (_obj.houseCode != code)
				fout.write((char*)&_obj,sizeof(_obj));
		}
		fin.close();
		fout.close();
		remove(houseTable);
		rename("new",houseTable);

	}

	int askForHouse(char *msg)
	{  int recCount=0;
		int x=1;
		int ch=0;
		int numRec;
		clrscr();
		cout<<endl<<" "<<msg<<endl;
		ifstream fin;
		fin.open(houseTable,ios::in);
		if (!fin) { clrscr(); cout<<" SOMETHING WENT WRONG !!! TRY ADDING RECORDS FIRST "; exit(1); }
		cout<<"\n Here is the list of houses in the school - \n\n Use arrow keys on the numpad to navigate.\n Make sure that numlock is ON.\n Use Enter or num key 5 to select.\n\n";
		while (1)
				{
					recCount++;
					fin.read((char*)&_obj,sizeof(_obj));
					if (fin.eof()) break;
					if (recCount==x)
						cout<<"\t->"<<setw(10)<<_obj.houseName;
					else
						cout<<"\t  "<<setw(10)<<_obj.houseName;
					if (recCount%3==0)
						cout<<endl;
				}
		numRec=recCount-1;
		while (ch!=13 && ch!=53)
		{
			if (kbhit())
			{
				clrscr();
				cout<<endl<<" "<<msg<<endl;
				cout<<"\n Here is the list of houses in the school - \n\n Use arrow keys on the numpad to navigate.\n Make sure that numlock is ON.\n Use Enter or num key 5 to select.\n\n";
				ch = getch();
				switch (ch)
				{
					case 54 :
						x = (x<numRec)?x+1:x;
						break;
					case 52 :
						x = (x>1)?x-1:x;
						break;
					case 50:
						x = (x+3<=numRec)?x+3:x;
						break;
					case 56:
						x = (x-3>=1)?x-3:x;
						break;
				}
				recCount=0;
				fin.clear();
				fin.seekg(0,ios::beg);
				while (1)
				{
					recCount++;
					fin.read((char*)&_obj,sizeof(_obj));
					if (fin.eof()) break;
					if (recCount==x)
						cout<<"\t->"<<setw(10)<<_obj.houseName;
					else
						cout<<"\t  "<<setw(10)<<_obj.houseName;
					if (recCount%3==0)
						cout<<endl;
				}

			}

		}
	recCount=0;
	fin.clear();
	fin.seekg(0,ios::beg);
	while (1)
			{
			recCount++;
			fin.read((char*)&_obj,sizeof(_obj));
			if (fin.eof()) break;
			if (recCount==x)
				return _obj.houseCode;
			}
  fin.close();
  }

  char* getHouseName(int i)
  {   static char houseName[10] = "";
		ifstream fin;
		fin.open(houseTable,ios::in);
      if (!fin) { clrscr(); cout<<" SOMETHING WENT WRONG !!! TRY ADDING RECORDS FIRST "; exit(1); }
		while(1)
			{	fin.read((char*)&_obj,sizeof(_obj));
				if(fin.eof()) break;
				if (_obj.houseCode==i)
					strcpy(houseName,_obj.houseName);

			}
		fin.close();
      return houseName;
  }

};

houseManager H;

/*
void main()
{
houseManager m;
m.askForHouse();

}  */
