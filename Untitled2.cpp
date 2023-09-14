#include<iostream>
#include<fstream>
using namespace std;

class Student
{
	private:
		int rollno;
		char name[20];
		int marks;
		
	public:
		void Create();
		void Display();
			
};

int main()
{
	char c;
	int ch;
	Student s;
	do
	{
		system("cls");
		cout<<"\n\n\t Sequential File Menu";     
		cout<<"\n\n";     
		cout<<"\n\n\t 1. Create";     
		cout<<"\n\n\t 2. Display";     
		cout<<"\n\n\t 7. Exit";     
		cout<<"\n\n\t Enter your choice) : ";     
		cin>>ch;     
		switch(ch)     
		{       
		case 1:      
		s.Create();      
		break;       
		
		case 2:      
		s.Display();      
		break; 
		
		case 3:
			exit(0);
		}
	cout<<"\n\nDo you want to continue(y/n):";
	cin>>c;
	}while(c=='y'||c=='Y');
	return 0;
}

void Student::Create()
{
	fstream f;
	Student s;
	f.open("student.txt",ios::out|ios::app);
	f.seekp(0,ios::end);
	cout<<"Enter Student Roll No : ";
	cin>>s.rollno;
	cout<<"Enter Student Name : ";
	cin>>s.name;
	cout<<"Enter Student Marks : ";
	cin>>s.marks;
	f.write((char*)&s,sizeof(s));
	cout<<"\n\nData Entered into file successfully..!";
	
}

void Student::Display()
{
	fstream f;
	Student s;
	int cnt=0;
	f.open("student.txt",ios::in);
	f.seekg(0,ios::beg);
	while(f.read((char*)&s,sizeof(s)))
	{
		cout<<"\n\n";
		cout<<" "<<s.rollno;
		cout<<" "<<s.name;
		cout<<" "<<s.marks;
		cnt++;
	}
	if(cnt==0)
	cout<<"\nFile is Empty..! ";
	
	f.close();
}
