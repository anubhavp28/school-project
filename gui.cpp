class gui
{
  public:
  static void createOptionForm(char op[][50],int n)
	{
		int maxlength=0;
		for (int i=0;i<n;i++)
		{ 	if (strlen(op[i])>maxlength)
				maxlength = (strlen(op[i])%2!=0)?strlen(op[i]):strlen(op[i])+1;
		}
		int startx = (80-maxlength-5)/2;
		int endx = (80-maxlength-5)/2 + maxlength + 10;
		gotoxy(startx,5);
		for (i=0;i<maxlength/2+3;i++)
			cout<<"=";
		cout<<"SELECT";
		for (i=0;i<maxlength/2+3;i++)
		cout<<"=";
		for (i=0;i<n;i++){
		gotoxy(startx,6+i);
		cout<<"+ ";
		cout<<i+1<<" - "<<op[i];
		for (int j=0;j<=endx-startx-strlen(op[i])-7;j++)
			cout<<" ";
		gotoxy(endx,6+i);
		cout<<"+";
		}
		gotoxy(startx,6+n);
		for (i=0;i<=endx-startx;i++)
			cout<<"=";
	}

  static void createErrorMsgBox(char msg[])
  {  	int maxlength=0;
		maxlength = (strlen(msg)%2!=0)?strlen(msg):strlen(msg)+1;
		int startx = (80-maxlength-5)/2;
		int endx = (80-maxlength-5)/2 + maxlength + 10;
		gotoxy(startx,8);
		for (int i=0;i<maxlength/2+3;i++)
			cout<<"=";
		cout<<"ERROR";
		for (i=0;i<maxlength/2+4;i++)
		cout<<"=";
		gotoxy(startx,9);
		cout<<"# ";
		cout<<msg;
		for (int j=0;j<=endx-startx-strlen(msg)-7;j++)
			cout<<" ";
		gotoxy(endx,9);
		cout<<"#";
		gotoxy(startx,10);
		for (i=0;i<=endx-startx;i++)
			cout<<"=";
		while (!kbhit())
			if (getch()==13)
				{	clrscr();
				return;
				}
  }
} ;
/*
void main()
{  char p[][50] = {"asdasdasd","asdaadasdsadsdssdasda", "asdasd"};
	gui::createErrorMsgBox("Wrong Date Entered (Press Enter To Exit)");
} */
