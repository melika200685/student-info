#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////
struct student
{
	int code;
	char name[100];
	int tedad;
	char lesson[10][20];
	float grade[20];
	int part[20];
	float avg;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
int ragham(int x)
{
	int i=0;
	while(x>0)
	{
		x/=10;
		i++;
	}
	
	return i;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
student info()										//تابع گرفتن اطلاعات دانشجو
{
	student s;
	
	float sum=0,sumpart=0;
	
	cout<<"please enter name : ";
	cin.getline(s.name,100);
	
	
	cout<<endl<<"please enter code : ";

	do
	{
		cin>>s.code;
		cin.ignore();
	}while(ragham(s.code)!=9);
	
	
	cout<<endl<<"please enter count of lesson : ";
	cin>>s.tedad;
	cin.ignore();
	
	for(int i=0;i<s.tedad;i++)
	{
		cout<<endl<<"please enter name of lesson"<<i+1<<" : ";
		cin.getline(s.lesson[i],20);
		
		cout<<"please enter grade of lesson"<<i+1<<" : ";
		cin>>s.grade[i];
		cin.ignore();
		
		cout<<"please enter part of lesson"<<i+1<<" : ";
		cin>>s.part[i];
		cin.ignore();
		
		sumpart+=s.part[i];
		sum+=s.grade[i]*s.part[i];
		
		
	}
	
	if(sumpart!=0)
		s.avg=sum/sumpart;
		
	else
		cout<<"Error...count of parts can not be 0!";
	
	cout<<"-------------------------------------"<<endl;
	
	
	
	ofstream f1("student.txt", ios::app);
	
	f1<<s.name<<endl;
	f1<<s.code<<endl;
	f1<<s.tedad<<endl;
	
	for(int i=0;i<s.tedad;i++)
	{
		f1<<s.lesson[i]<<endl;
		f1<<s.grade[i]<<endl;
		f1<<s.part[i]<<endl;	
	}
	
	f1<<s.avg<<endl;
	f1.close();
	
	return s;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void all()					//تابع برای نمایش اطلاعات همه دانشجویان
{
	student s;
	
	ifstream f2("student.txt");
	
	while(f2.getline(s.name,100))
	{
		f2>>s.code;
		f2.ignore();
		f2>>s.tedad;
		f2.ignore();
		
		cout<<endl<<endl<<"name : "<<s.name<<endl;
		cout<<"code : "<<s.code<<endl;
		cout<<"count of lesson : "<<s.tedad<<endl;
		
		
		for(int i=0;i<s.tedad;i++)
		{
			f2.getline(s.lesson[i],20);
			
			f2>>s.grade[i];
			f2.ignore();
			
			f2>>s.part[i];
			f2.ignore();
			
			
			cout<<"name of lesson"<<i+1<<" : "<<s.lesson[i]<<endl;
			cout<<"grade of lesson"<<i+1<<" : "<<s.grade[i]<<endl;
			cout<<"part of lesson"<<i+1<<" : "<<s.part[i]<<endl<<endl;
			
			
		}
		
		f2>>s.avg;
		f2.ignore();
		
		cout<<endl<<"your avg : "<<s.avg<<endl;
		cout<<"-------------------------------------"<<endl;
		
	}
	
	f2.close();	
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void search()
{
	student s;
	char x[100];
	int a,b;
	
	bool found=false;
	
	
	
	cout<<"According to which option do you want to search?"<<endl;
	cout<<"1)name"<<endl<<"2)code"<<endl;
	
	do
	{
		cin>>a;
		cin.ignore();
	}while((a!=1)  &&  (a!=2));
	
	
	if(a==1)
	{
		cout<<"please enter name : ";
		cin.getline(x,100);
		
		ifstream f3("student.txt");
		
		while(f3.getline(s.name,100))
		{
			if(strcmp(x , s.name)==0)
			{
				found=true;
				cout<<"found"<<endl;
				
				f3>>s.code;
				f3.ignore();
				
				f3>>s.tedad;
				f3.ignore();
				
				cout<<"name : "<<s.name<<endl;
				cout<<"code : "<<s.code<<endl;
				cout<<"count of lesson : "<<s.tedad<<endl;
				
				for(int i=0;i<s.tedad;i++)
				{
					f3.getline(s.lesson[i],20);
					
					f3>>s.grade[i];
					f3.ignore();
					
					f3>>s.part[i];
					f3.ignore();
					
					cout<<"name of lesson"<<i+1<<" : "<<s.lesson[i]<<endl;	
					cout<<"grade of lesson"<<i+1<<" : "<<s.grade[i]<<endl;	
					cout<<"part of lesson"<<i+1<<" : "<<s.part[i]<<endl;	
						
				}
				
				f3>>s.avg;
				f3.ignore();
				
				cout<<"your avg : "<<s.avg<<endl;
				
				if(found==false)
					cout<<"not found";
					
			}
			
			
		}	
		
			f3.close();	
		
	} 			//جست و جو با اسم				
	

	
	else if(a==2)
	{
		ifstream f4("student.txt");
		
		cout<<"pleas enter code : ";
		
		do
		{
			cin>>b;	
			cin.ignore();
		}while(ragham(b)!=9);
		
		
		
		
		while(f4.getline(s.name,100))
		{
			f4>>s.code;
			f4.ignore();
			
			f4>>s.tedad;
			f4.ignore();
			
			for(int i=0;i<s.tedad;i++)
			{
				f4.getline(s.lesson[i],20);
				
				f4>>s.grade[i];
				f4.ignore();
				
				f4>>s.part[i];
				f4.ignore();
			}
			
			f4>>s.avg;
			f4.ignore();
			
			if(b==s.code)
			{
				cout<<"found"<<endl;
				
				cout<<"name : "<<s.name<<endl;
				cout<<"code : "<<s.code<<endl;
				cout<<"count of lesson : "<<s.tedad<<endl;
				
				for(int i=0;i<s.tedad;i++)
				{
					cout<<"name of lesson"<<i+1<<" : "<<s.lesson[i]<<endl;	
					cout<<"grade of lesson"<<i+1<<" : "<<s.grade[i]<<endl;	
					cout<<"part of lesson"<<i+1<<" : "<<s.part[i]<<endl;
				}
				
				cout<<"your avg : "<<s.avg<<endl;
				
			}
			
			else
				cout<<"not found"<<endl;	
		}
		
		f4.close();	
	}
	
	
	
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	
	int n=0,x=0,i=0;
	student s[100];
	cout<<"please enter a number?"<<endl<<"1)add student"<<endl<<"2)show information"<<endl<<"3)search"<<endl;
	
	do
	{
		cin>>x;
		
	}while(x<1  ||  x>3);
	
	
	switch(x)
	{
		case 1:	
				cout<<"How many students do you want to add? ";
				cin>>n;
				cin.ignore();
				
				for(int j=0;j<n;j++)
				{
					cout<<"student"<<j+1<<"="<<endl;
					s[i]=info();
					
					cout<<"avg : "<<s[i].avg<<endl;
					cout<<"---------------"<<endl;
				
				}
				break;	
		
		case 2:
				all();
				break;
				
		case 3:
				search();
				break;
	}
	
	return 0;
	
}
