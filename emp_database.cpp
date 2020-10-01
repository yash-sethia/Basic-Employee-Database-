#include <fstream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char ANS;
struct emp
 {int  code;

  char name[50];
  int job, dep;
  float sallary;
  int rank, delay,deadline,complete,experience;
  int ddj,mmj,yyyyj;
 }s;


int year=365;


int date_2_num(int dd1,int mm1)
{  int ctr=0;
	if(mm1==1)
		ctr+=dd1;
	if(mm1==2)
		ctr+=31+dd1;
	if(mm1==3)
		ctr+=31+28+dd1;
	if(mm1==4)
		ctr+=31+28+31+dd1;
	if(mm1==5)
		ctr=31+28+31+30+dd1;
	if(mm1==6)
		ctr=31+28+31+30+dd1+31;
	if(mm1==7)
		ctr=31+28+31+30+dd1+31+30;
	if(mm1==8)
		ctr= 31+28+31+30+dd1+31+30+31;
	if(mm1==9)
		ctr=31+28+31+30+dd1+31+30+31+31;
	if(mm1==10)
		ctr=31+28+31+30+dd1+31+30+31+31+30;
	if(mm1==11)
		ctr= 31+28+31+30+dd1+31+30+31+31+30+31;
	if(mm1==12)
		ctr=31+28+31+30+dd1+31+30+31+31+30+31+30;

	return(ctr);
}




int time_cal(int dd1,int mm1,int yyyy1,int dd2,int mm2,int yyyy2)
{
	int a=date_2_num(dd1,mm1);int time;
	int b=date_2_num(dd2,mm2);
		if(yyyy2-yyyy1<=1)
		{	time=b-a;
			if(time<=0)
				time+=year;
		 }
		 else
		    {	if((yyyy2-yyyy1)>1)
			{       if(mm2>=mm1)
				{
					 time=b-a-1+((yyyy2-yyyy1)*year);
				}
				if(mm1>mm2)
				{ 	 int x=yyyy2-yyyy1;
					 time=b-a+(x*year);
				}
			}}
		for(int i=yyyy1;i<yyyy2;i++)
			{
				if(i%4==0&&i%100==0&&i%400==0)
					time++;
			 }
		if(mm2>2)
				if(yyyy2%4==0&&yyyy2%100==0&&yyyy2%400==0)
				      time++;
		 return(time);
}





void input_date(int &dd1,int &mm1, int &yyyy1)
{
	cout<<"ENTER DATE DD/MM/YYYY";
	cin>>dd1>>mm1>>yyyy1;
}




int exp_cal(int ddJ,int mmJ,int yyyyJ)
{
	int ddt,mmt,yyyyt;
	cout<<"Input Todays Date";
	input_date(ddt,mmt,yyyyt);
	int m=time_cal(ddJ,mmJ,yyyyJ,ddt,mmt,yyyyt);
	return(m);
}



void input()
{

 int dd1,mm1,yyyy1,dd2,mm2,yyyy2,dd3,mm3,yyyy3;
  fstream f1;
 f1.open("data.dat",ios::out|ios::binary);
 char ans;
 do
 {
	 cout<<"Enter Code"<<endl;
 	cin>>s.code;
 	cout<<"ENTER NAME"<<endl;
 	gets(s.name);
 	cout<<"ENTER SALARY"<<endl;
 	cin>>s.sallary;
 	cout<<"ENTER DEPARTMENT"<<endl;
 	cin>>s.dep;
 	cout<<"ENTER RANK"<<endl;
 	cin>>s.rank;
 	cout<<"ENTER JOB "<<endl;
 	cin>>s.job;
 	cout<<"ENTER DATE OF JOINING (DD/MM/YYYY) "<<endl;
 	cin>>s.ddj>>s.mmj>>s.yyyyj;
 	s.experience=s.experience=exp_cal(s.ddj,s.mmj,s.yyyyj);;
 	s.delay=0;
  	
	f1.write((char*)&s,sizeof(s));
  	cout<<"DO YOU WANT TO ADD MORE DATA ? (Y/N)";
  	cin>>ans;
  }while(ans=='Y'|| ans=='y');
  f1.close();
}



void input_eff()
{       fstream f;
	f.open("Data.dat", ios::binary|ios::in|ios::out);
	cout<<"Enter the employee code";
	int code;
	int dd1,dd2,dd3,mm1,mm2,mm3,yyyy1,yyyy2,yyyy3;
	cin>>code;
	while(!f.eof())
	{
		f.read((char*)&s, sizeof(s));
		if(s.code==code)
		{
			cout<<"WORK WAS GIVRN ON"<<endl;
			 input_date(dd1,mm1,yyyy1);
			cout<<"JOB DEADLINE";
			input_date(dd2,mm2,yyyy2);
			 cout<<"JOB COMLETED ON"<<endl;
			 input_date(dd3,mm3,yyyy3);
			 s.deadline=time_cal(dd1,mm1,yyyy1,dd2,mm2,yyyy2);
			 s.complete+=time_cal(dd1,mm1,yyyy1,dd3,mm3,yyyy3);
			 if(s.complete<=0)
				s.delay+=0;
			 else
				s.delay+=s.complete-s.deadline;

		    }
	}
f.close();
}





void rank_acc_delay(int rank7[100])
{
    int delay[100] ;
    ifstream f1;
    int temp;
    f1.open("Data.bin",ios::binary);
    for(int z=0;z<100;z++)
    {       if(z!=0)
	{    f1.read((char*)&s, sizeof(s));
	    delay[z]=s.delay;
	    rank7[z]=s.code;
	    int j=z;
	    while((delay[j-1]>delay[j])&&(j!=0))
	    {       temp=rank7[j];
		rank7[j]=rank7[j-1];
		rank7[j-1]=temp;
		j--;
	    }
	}
	if(z==0)
	{         f1.read((char*)&s,sizeof(s));
	    delay[z]=s.delay;
	    rank7[z]=s.code;
	}
    }
    f1.close();
}




void case3m()
{         char ch;
cout<<"ENTER PASSWORD"; char pass[100];
		 gets(pass);
		if(strcmp(pass,"PASSWORD"))
		cout<<"SELECT ANY ONE \n ";
		cout<<"1. CHECK FOR INDIVIDUAL \n";
		cout<<"2. SORT (RANK) \n";
		cout<<"3. SORT(EFFICENY) \n";
		cout<<"4. SORT(EXPERICE) \n";
		cout<<"5. SORT(DEPARTMENT) \n";
		cout<<"6. EMPLOYEE OF THE MONTH \n";
		cout<<"  ENTER YOUR CHOICE  ";
	cin>>ch;
  switch(ch)
  {
	 case'1':{
			 cout<<"SEARCH FOR INDIVIDUAL \n";
			int a;
		  cout<<"To search the employee's data, Enter the employee's code";
		  cin>>a;
		  int ctr =0;
		  ifstream f1;
		  f1.open("data.dat");
	      while(!f1.eof())
	      {
		   f1.read((char*)&s,sizeof(s));
		   if(s.code==a)
		  {        ctr++;
			   cout<<"NAME : ";
			   puts(s.name);
			   cout<<"\n JOB : ";
			   cout<<s.job;
			   cout<<"\n DEPARTMENT : "<<s.dep;
			   cout<<" \n SALLARY : "<<s.sallary  ;
			   cout<<" \n POSITION : "<<s.rank;
			   cout<<"\n EXPERIENCE : "<<s.experience;
			   cout<<"\n DATE OF JOINING (DD/MM/YYYY) : "<<s.ddj<<cout<<"/"<<s.mmj<<cout<<"/"<<s.yyyyj;
		   }
	     }
		  if(!ctr)
			  cout<<"Data of the given user is not available!";
		 f1.close();
		 break;

		}
  	case'2':{
		int i,j;
		ifstream f;
		f.open("Data.dat",ios::binary);
		for(i=1;i<10;i++)
		{    f.seekg(0,ios::cur);
		     while(!f.eof())
		     {	 f.read((char*)&s, sizeof(s));
			if(i==s.rank)
			{
			 cout<<"RANK \t";
			 cout<<i<<"   ";
			 puts(s.name);
			 break;
			}
		 }
	      }   break;
	}
  	case'3': {
		int i=0,rank1[100];
		rank_acc_delay(rank1);
		ifstream f;
		f.open("Data.dat",ios::binary);
	       for(;i<100;i++)
	       {   f.seekg(0,ios::cur);
	       while(!f.eof())
		{
			f.read((char*)&s,sizeof(s));
			if(rank1[i]==s.code)
			{
				 cout<<"NAME : ";
				 puts(s.name);
				 cout<<endl;

			}
		} }
	      break;
	     }

  	case'4':
	{
		int ddt,mmt,yyyyt;
		 ifstream f1;int temp;
		 f1.open("Data.bin",ios::binary);
		int rank2[100],experience[100] ;
		for(int v=0;v<100;v++,!f1.eof())
		   {   f1.read((char*)&s,sizeof(s));
		      if(v!=0)
			{
				rank2[v]=s.code;
				experience[v]=s.experience;
				 int j=v;
				while((experience[j-1]>experience[j])&&(j>=0))
				{       temp=rank2[j];
					rank2[j]=rank2[j-1];
					 rank2[j-1]=temp;
					 temp=experience[j];
					 experience[j]=experience[j-1];
					 experience[j-1]=experience[j];
					 j--;
				   }
			}
		if(v==0)
		{
				rank2[v]=s.code;
				experience[v]=s.experience;
		}
		    }
		for(int i=0;i<10;i++)
		{    f1.seekg(0,ios::cur);
		     while(!f1.eof())
		     {	 f1.read((char*)&s, sizeof(s));
			if(rank2[i]==s.code)
			{
			 cout<<"RANK \t";
			 cout<<i+1<<"   ";
			 puts(s.name);
			}
		     }
		}
		    f1.close();

	   break;
	  }
	  case'5':{
	      fstream f1;
		int check[50];
		int n=0,k=0;
		f1.open("data.dat",ios::binary|ios::in|ios::out);
		while(!f1.eof())
		{
		     f1.read((char*)&s,sizeof(s));
		     check[k]=s.dep;
		     k++;
		}
		int dept;
		for(int i=0;i<n;i++)
			if(check[i]!=s.dep)

				while(!f1.eof())
				{
					f1.read((char*)&s,sizeof(s));
					if(dept==s.dep)
					while(!f1.eof())
					{
						f1.read((char*)&s,sizeof(s));
						if(s.dep==dept)
						cout<<s.name<<"\t"<<s.code;
					}
				}
	      }
  	case '6':
	  {
		 int rank3[100];
		rank_acc_delay(rank3);
		ifstream f;
		f.open("Data.dat",ios::binary);
		f.read((char*)&s,sizeof(s));
		while(!f.eof())
		{
		 if(rank3[0]==s.code)
		 {	cout<<" BEST EMPLOYEE IS : "<<s.name;
			break;
		 }
		}
		break;
	  }
	  default:cout<<"ILLEGAL INPUT";
	  }
		
}




void case4m()
{        cout<<"ENTER PASSWORD"; char pass[100];
		 gets(pass);
	if(strcmp(pass,"PASSWORD"))
	cout<<"Enter the emplyoee code whose data is to modified;";
	 int a;
	 cin>>a;
	 char ch;
	 cout<<"What would you like to edit ?";
	 cout<<endl<<"1.Name \n" ;
	 cout<<"2.Job  \n";
	 cout<<"3.Department \n";
	 cout<<"4.Sallary \n";
	 cout<<"5.Date of joining \n";
	 cout<<"6.Rank \n";
	 cout<<"7.Go to previous menu \n";
	 cout<<" ENTER YOUR CHOICE : ";
	 cin>>ch;
	 fstream f1,f2;
	 char rep;
	 int ctr=0;
	  f1.open("data.dat",ios::binary|ios::in);
	   f2.open("temp.dat",ios::binary|ios::out);



	    do
	    {     while(!f1.eof())
		{     f1.read((char*)&s,sizeof(s));
		switch(ch)
		 {
			case '1': {


						if(a==s.code)
						{
							cout<<"Enter new name ";
							gets(s.name);

						}

				   break;
				}
			case '2' : {

						if(a==s.code)
						{
							cout<<"Enter new job ";
							cin>>s.job;
						}

				   break;
				}
			case '3': {
						if(a==s.code)
						{
							cout<<"Enter new Department ";
							cin>>s.dep;
						}

				   break;
				}
			case '4': {
						if(a==s.code)
						{
							cout<<"Enter new Sallary ";
							cin>>s.sallary;
						}

				   break;
				}
			case '5': {
						if(a==s.code)
						{
							cout<<"Enter new Date of joining ";
							input_date(s.ddj,s.mmj,s.yyyyj);
						}

				   break;
				}
			case '7': {
					rep='N';
					continue;
				}
			case '6' : {
					cout<<"Enter new rank";
					cin>>s.rank;
					break;
				}
			default : {
					cout<<"INCORRECT CHOICE ENTERED \n TRY AGAIN \n";
					rep='Y';
					continue;
				}
			}

		 f2.write((char*)&s,sizeof(s));

		 }
			remove("data.dat");
			rename("temp.dat","data.dat");
			cout<<"NAME : ";
			   puts(s.name);
			   cout<<"\n JOB : ";
			   cout<<s.job;
			   cout<<"\n DEPARTMENT : "<<s.dep;
			   cout<<" \n SALLARY : "<<s.sallary  ;
			   cout<<" \n POSITION : "<<s.rank;
			   cout<<"\n EXPERIENCE : "<<s.experience;
			   cout<<"\n DATE OF JOINING (DD/MM/YYYY) : "<<s.ddj<<cout<<"/"<<s.mmj<<cout<<"/"<<s.yyyyj;

		   cout<<"\n DO YOU WANT TO CONTINUE  ? (Y/N)";
		   cin>>rep;
	 }while(rep=='Y'||rep=='y');
	 f1.close();
	 f2.close();
  }




void main()
{
cout<<"*********************************************************";
cout<<" .              WELCOME  TO EMPLOYEE  DATABASE          .";
cout<<"*********************************************************";
clrscr();
cout<<" WELCOME TO THE NEXT GEN PRIVATE EMPLOYEE DATABASE (NGPED ";
cout<<endl<<endl<<endl<<endl<<endl;
int comp;
char CHOICE;
cout<<" ENTER COMPANY CODE ";
cin>>comp;
do
{
cout<<"**************************************MENU************************************** \n";
cout<<"CHOOSE ANY  1 TO CONTINUE";
cout<<"\n";
cout<<" 1.ADD ANOTHER EMPLOYEE \n ";
cout<<" 2.UPLOAD NEW EFFICIENCY DATA \n";
cout<<" 3.VIEW DATA(password requred)  \n";
cout<<" 4.MODIFY DATA(password required) \n";
cout<<" 5.LOG OUT \n";
cout<<" 6.LOG OUT AND EXIT \n";
cin>>CHOICE;

switch(CHOICE)
{
	case '1':
	 {
		input();
		break;
	 }
 case '2':
 	{
       		cout<<"*********** EFFICIENCY DATA *********** \n"<<endl;
       		input_eff();
       		break;
 	}
 case '3':
		{
			cout<<"*********** VIEW DATA *********** \n ";
			case3m();
			break;
		}
case '4' :
  	{
		cout<<"***********  MODIFICATION OF DATA *********** \n"<<endl;
		case4m();
		break;
  	}
  case '5' :
  	{

		  ANS='Y';
		continue;
  	}
	case '6':
  	{
	 exit(0);
  	}
  default:
  	{
  		cout<<"WRONG CHOICE ENTERED \n TRY AGAIN  \n";
  		ANS='Y';
  		continue;
  	}
  }
  cout<<"DO YOU WISH TO CONTINUE ?(Y/N)";
  cin>>ANS;
  }while(ANS=='Y'||ANS=='y');
  getch();
  }
  
