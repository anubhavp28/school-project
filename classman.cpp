
class classManager
{	int lastCode;
	struct class_ _obj;

	public:

	classManager()
	{	ifstream fin;
		fin.open(classTable,ios::in);
		if (fin.eof() || !fin)
		{
			lastCode = 0;
		}
		else
		{
			while(1)
			{	fin.read((char*)&_obj,sizeof(_obj));
				if(fin.eof()) break;
			}
			lastCode = _obj.classCode;
		}
		fin.close();
	}

	void insert()
	{  ofstream fout;
		fout.open(classTable,ios::out|ios::app);
		if (!fout) { clrscr(); cout<<" SOMETHING WENT WRONG !!! TRY ADDING RECORDS FIRST "; exit(1); }
		cout<<"Enter the details of the new class --- \n\n";
		cout<<"Class Name -- ";
		gets(_obj.className);
		lastCode = lastCode + 1;
		_obj.classCode = lastCode;
		fout.write((char*)&_obj,sizeof(_obj));
		cout<<"Written successfully!!";
		fout.close();

	}

	void display()
	{
		cout<<"\nHere is the list of classes in the school --- \n\n";
		ifstream fin;
		fin.open(classTable,ios::in);
      if (!fin) { clrscr(); cout<<" SOMETHING WENT WRONG !!! TRY ADDING RECORDS FIRST "; exit(1); }
		cout<<setw(10)<<"Class Code"<<setw(12)<<"Class Name"<<endl;
		while (1)
		{
			fin.read((char*)&_obj,sizeof(_obj));
			if (fin.eof()) break;
			cout<<setw(10)<<_obj.classCode<<setw(12)<<_obj.className<<endl;
		}
		fin.close();
	}

	void delete_()
	{  int code;
		display();
		cout<<"Enter the Class Code which you want to delete -- ";
		cin>>code;
		ifstream fin;
		fin.open(classTable,ios::in);
		if (!fin) { clrscr(); cout<<" SOMETHING WENT WRONG !!! TRY ADDING RECORDS FIRST "; exit(1); }
		ofstream fout;
		fout.open("new",ios::out);
		while(1)
		{ 	fin.read((char*)&_obj,sizeof(_obj));
			if (fin.eof()) break;
			if (_obj.classCode != code)
				fout.write((char*)&_obj,sizeof(_obj));
		}
		fin.close();
		fout.close();
		remove(classTable);
		rename("new",classTable);

	}

	int askForClass(char *msg)
	{  int recCount=0;
		int x=1;
		int ch=0;
		int numRec;
		clrscr();
		cout<<endl<<" "<<msg<<endl;
		ifstream fin;
		fin.open(classTable,ios::in);
		if (!fin) { clrscr(); cout<<" SOMETHING WENT WRONG !!! TRY ADDING RECORDS FIRST "; exit(1); }
		cout<<"\n Here is the list of classes in the school - \n\n Use arrow keys on the numpad to navigate.\n Make sure that numlock is ON.\n Use Enter or num key 5 to select.\n\n";
		while (1)
				{
					recCount++;
					fin.read((char*)&_obj,sizeof(_obj));
					if (fin.eof()) break;
					if (recCount==x)
						cout<<"\t->"<<setw(10)<<_obj.className;
					else
						cout<<"\t  "<<setw(10)<<_obj.className;
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
				cout<<"\n Here is the list of classes in the school - \n\n Use arrow keys on the numpad to navigate.\n Make sure that numlock is ON.\n Use Enter or num key 5 to select.\n\n";
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
						cout<<"\t->"<<setw(10)<<_obj.className;
					else
						cout<<"\t  "<<setw(10)<<_obj.className;
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
				return _obj.classCode;
			}
  fin.close();
  }

  char* getClassName(int i)
  {   static char className[10] = "";
  		ifstream fin;
		fin.open(classTable,ios::in);
		if (!fin) { clrscr(); cout<<" SOMETHING WENT WRONG !!! TRY ADDING RECORDS FIRST "; exit(1); }
		while(1)
			{	fin.read((char*)&_obj,sizeof(_obj));
				if(fin.eof()) break;
				if (_obj.classCode==i)
					strcpy(className,_obj.className);

			}
		fin.close();
      return className;
  }

};

classManager C;

