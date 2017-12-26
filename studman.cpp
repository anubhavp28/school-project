class studentManager
{  int lastCode;
  struct student _obj;

	public :

	studentManager()
	{	ifstream fin;
		fin.open(studentTable,ios::in|ios::binary);
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
			lastCode = _obj.studId;
		}
		fin.close();
	}

	void insert()
	{  ofstream fout;
		fout.open(studentTable,ios::out|ios::app|ios::binary);
		if (!fout) { clrscr(); cout<<" SOMETHING WENT WRONG !!! TRY ADDING RECORDS FIRST "; exit(1); }
		cout<<"Enter the details of the new student --- \n\n";
		_obj.studId = ++lastCode;
		cout<<"Student ID -- "<<_obj.studId<<endl;
		cout<<"First Name -- ";
		gets(_obj.fName);
		cout<<"Last Name -- ";
		gets(_obj.lName);
		cout<<"Admission Date -- ";
		_obj.AdmDate = D.getDate();
		cout<<"Enter Date of Birth -- ";
		_obj.DOB = D.getDate();
		_obj.classCode = C.askForClass("Enter Student's Class - ");
		_obj.houseCode = H.askForHouse("Enter Student's House - ");
		clrscr();
		cout<<"Sex ( M or F ) -- ";
		cin>>_obj.sex;
		cout<<"Blood Group -- ";
		cin>>_obj.bloodGroup;
		cout<<"Father Name -- ";
		gets(_obj.father);
		cout<<"Mother Name -- ";
		gets(_obj.mother);
		cout<<"Address -- ";
		gets(_obj.add);
		cout<<"PIN -- ";
		cin>>_obj.pin;
		cout<<"Phone -- ";
		cin>>_obj.phone;
		fout.write((char*)&_obj,sizeof(student));
		cout<<"\nAdded Successfully !!!\n";
		fout.close();

	}

	void delete_()
	{  int code;
		display();
		cout<<"\nEnter the Student ID which you want to delete -- ";
		cin>>code;
		ifstream fin;
		fin.open(studentTable,ios::in);
		if (!fin) { clrscr(); cout<<" SOMETHING WENT WRONG !!! TRY ADDING RECORDS FIRST "; exit(1); }
		ofstream fout;
		fout.open("new",ios::out);
		while(1)
		{ 	fin.read((char*)&_obj,sizeof(_obj));
			if (fin.eof()) break;
			if (_obj.studId != code)
				fout.write((char*)&_obj,sizeof(_obj));
		}
		fin.close();
		fout.close();
		remove(studentTable);
		rename("new",studentTable);

	}

	void update()
	{  int code,found=0;;
		display();
		cout<<"\nEnter the Student ID which you want to update -- ";
		cin>>code;
		ifstream fin;
		fin.open(studentTable,ios::in);
      if (!fin) { clrscr(); cout<<" SOMETHING WENT WRONG !!! TRY ADDING RECORDS FIRST "; exit(1); }
		ofstream fout;
		fout.open("new",ios::out);
		while(1)
		{ 	fin.read((char*)&_obj,sizeof(_obj));
			if (fin.eof()) break;
			if (_obj.studId != code)
				fout.write((char*)&_obj,sizeof(_obj));
			else
				found=1;
		}

		if (found)
		{
		cout<<"Enter the updated details --- \n\n";
		cout<<"First Name -- ";
		cin>>_obj.fName;
		cout<<"Last Name -- ";
		cin>>_obj.lName;
		cout<<"Admission Date -- ";
		_obj.AdmDate = D.getDate();
		cout<<"Enter Date of Birth -- ";
		_obj.DOB = D.getDate();
		_obj.classCode = C.askForClass("Enter Student's Class - ");
		_obj.houseCode = H.askForHouse("Enter Student's House - ");
		clrscr();
		cout<<"Sex ( M or F ) -- ";
		cin>>_obj.sex;
		cout<<"Blood Group -- ";
		cin>>_obj.bloodGroup;
		cout<<"Father Name -- ";
		cin>>_obj.father;
		cout<<"Mother Name -- ";
		cin>>_obj.mother;
		cout<<"Address -- ";
		cin>>_obj.add;
		cout<<"PIN -- ";
		cin>>_obj.pin;
		cout<<"Phone -- ";
		cin>>_obj.phone;
		fout.write((char*)&_obj,sizeof(student));
		}
		else
		{
			cout<<"\nUnable to found !! ";
		}
		fin.close();
		fout.close();
		remove(studentTable);
		rename("new",studentTable);
	}

  void display()
	{
		cout<<"\nHere is the list of students in the school --- \n\n";
		ifstream fin;
		fin.open(studentTable,ios::in|ios::binary);
		if (!fin) { clrscr(); cout<<" SOMETHING WENT WRONG !!! TRY ADDING RECORDS FIRST "; exit(1); }
		fin.clear();
		fin.seekg(0);
		while (1)
		{
			fin.read((char*)&_obj,sizeof(_obj));
			if (fin.eof()){ cout<<"END OF RECORDS !!"; break;}
			cout<<"Student ID -- "<<_obj.studId<<endl;
			cout<<"First Name -- "<<_obj.fName<<endl;
			cout<<"Last Name -- "<<_obj.lName<<endl;
			cout<<"Admission Date -- "<<_obj.AdmDate.d<<"-"<<_obj.AdmDate.m<<"-"<<_obj.AdmDate.y<<endl;
			cout<<"Date of Birth -- "<<_obj.DOB.d<<"-"<<_obj.DOB.m<<"-"<<_obj.DOB.y<<endl;
			cout<<"Sex ( M or F ) -- "<<_obj.sex<<endl;
			cout<<"Blood Group -- "<<_obj.bloodGroup<<endl;
			cout<<"Father Name -- "<<_obj.father<<endl;
			cout<<"Mother Name -- "<<_obj.mother<<endl;
			cout<<"Address -- "<<_obj.add<<endl;
			cout<<"PIN -- "<<_obj.pin<<endl;
			cout<<"Phone -- "<<_obj.phone<<endl;
			cout<<"Class -- ";
			puts(C.getClassName(_obj.classCode));
			cout<<"House -- ";
			puts(H.getHouseName(_obj.houseCode));
		cout<<endl;
		cout<<"Press any key to continue or escape to exit........";
		if (getch()==27) break;
      clrscr();
		}
		fin.close();
	}


	void searchById(int i)
	{
	int found=0;
	ifstream fin;
		fin.open(studentTable,ios::in|ios::binary);
		if (!fin) { clrscr(); cout<<" SOMETHING WENT WRONG !!! TRY ADDING RECORDS FIRST "; exit(1); }
		while(1)
			{	fin.read((char*)&_obj,sizeof(_obj));
				if(fin.eof()) break;
				if (_obj.studId==i)
				{
					found=1;
					cout<<"Student ID -- "<<_obj.studId<<endl;
					cout<<"First Name -- "<<_obj.fName<<endl;
					cout<<"Last Name -- "<<_obj.lName<<endl;
					cout<<"Admission Date -- "<<_obj.AdmDate.d<<"-"<<_obj.AdmDate.m<<"-"<<_obj.AdmDate.y<<endl;
					cout<<"Date of Birth -- "<<_obj.DOB.d<<"-"<<_obj.DOB.m<<"-"<<_obj.DOB.y<<endl;
					cout<<"Sex ( M or F ) -- "<<_obj.sex<<endl;
					cout<<"Blood Group -- "<<_obj.bloodGroup<<endl;
					cout<<"Father Name -- "<<_obj.father<<endl;
					cout<<"Mother Name -- "<<_obj.mother<<endl;
					cout<<"Address -- "<<_obj.add<<endl;
					cout<<"PIN -- "<<_obj.pin<<endl;
					cout<<"Phone -- "<<_obj.phone<<endl;
					cout<<"Class -- ";
					puts(C.getClassName(_obj.classCode));
					cout<<"House -- ";
					puts(H.getHouseName(_obj.houseCode));
				break;
				}

			}
		if (!found)
			cout<<"NOTHING FOUND !!";
		fin.close();
	}

	void searchByName(char fname[20],char lname[20])
	{
	int found=0;
	ifstream fin;
		fin.open(studentTable,ios::in|ios::binary);
		if (!fin) { clrscr(); cout<<" SOMETHING WENT WRONG !!! TRY ADDING RECORDS FIRST "; exit(1); }
		while(1)
			{	fin.read((char*)&_obj,sizeof(_obj));
				if(fin.eof()) break;
				if (strcmp(_obj.fName,fname)==0 && strcmp(_obj.lName,lname)==0 )
				{
               found=1;
					cout<<"Student ID -- "<<_obj.studId<<endl;
					cout<<"First Name -- "<<_obj.fName<<endl;
					cout<<"Last Name -- "<<_obj.lName<<endl;
					cout<<"Admission Date -- "<<_obj.AdmDate.d<<"-"<<_obj.AdmDate.m<<"-"<<_obj.AdmDate.y<<endl;
					cout<<"Date of Birth -- "<<_obj.DOB.d<<"-"<<_obj.DOB.m<<"-"<<_obj.DOB.y<<endl;
					cout<<"Sex ( M or F ) -- "<<_obj.sex<<endl;
					cout<<"Blood Group -- "<<_obj.bloodGroup<<endl;
					cout<<"Father Name -- "<<_obj.father<<endl;
					cout<<"Mother Name -- "<<_obj.mother<<endl;
					cout<<"Address -- "<<_obj.add<<endl;
					cout<<"PIN -- "<<_obj.pin<<endl;
					cout<<"Phone -- "<<_obj.phone<<endl;
					cout<<"Class -- ";
					puts(C.getClassName(_obj.classCode));
					cout<<"House -- ";
					puts(H.getHouseName(_obj.houseCode));
				}

			}
		if (!found)
			cout<<"NOTHING FOUND !!";
		fin.close();
	}


};


