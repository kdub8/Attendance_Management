#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include "Student.cpp"

//Admin username is : "admin" , password is "admin@2"

using namespace std;

int adminView();
int studentView();
int studentLogin();
int checkCredentials(string username, string password);
int getAllStudentsbyRollNum();
int deleteAllStudents();
int deleteStudentbyFileName();
int checkListOfStudentsRegistered();
int checkPresenceCountbyRollNum();
int getListOfStudentsPresenceCount();
int registerStudent();
int adminLogin();
int registerStudent();
int markMyAttendance(string username);
int countMyAttendance(string username);
int delay();

int delay()
{
for(int i = 0; i < 3; i ++)
{
	cout<<"\n Saving Records ...";
    for(int ii = 0; ii < 20000; ii++)
    {
    	for(int j = 0; j < 20000; j++)
       	{ }
    }
}
   
cout<<"\n Exiting Now ...";
for(int i = 0; i < 3; i++){
   for(int j = 0; j < 20000; j++) { 
     for(int k = 0; k < 20000; k++){
	 }
    } 
}

return 0;
}

/////////////////////////////////////////////
	int adminView() {	
		int goBack = 0;
		while(1) {
			system("cls");
			cout<<"\n1. Register a student";
			cout<<"\n2. Delete all students' names that are registered";
			cout<<"\n3. Delete student by file name";
			cout<<"\n4. Check list of students registered by username";
			cout<<"\n5. Check presence count of any student by roll number";
			cout<<"\n6. Get list of students with their attendance count";
			cout<<"\n0. Go Back <- \n";
			int choice;
			cout<<"\nEnter your choice: ";
			cin>>choice;
				switch(choice)
				{
					case 1: registerStudent();
							break;  
					case 2: deleteAllStudents(); 
							break;
					case 3: deleteStudentbyFileName(); 
							break;
					case 4: checkListOfStudentsRegistered(); 
							break;
					case 5: checkPresenceCountbyRollNum(); 
							break;
					case 6: getListOfStudentsPresenceCount(); 
							break;
					case 0: goBack = 1;
							break;
					default: cout<<"\n Invalid choice. Enter again: ";
					getchar();           	
				}   
				if(goBack == 1) {
					break; //break the loop
				}     
			}

		return 0;
		}
/////////////////////////////////////////////
	int studentLogin() {
		system("cls");
		cout<<"\n -------- Student Login ---------";	
		studentView();
		delay();
		return 0; 
	}
/////////////////////////////////////////////
	int adminLogin() {
		system("cls");
		cout << "\n --------- Admin Login --------";	

		string username;
		string password;

		cout << "\nEnter username: ";
		cin >> username;
		cout << "\nEnter password: ";
		cin >> password;

		if (username == "admin" && password == "admin@2") {
			adminView();
			getchar();	
			delay();
		}   
		else {
		cout<<"\nError! Invalid Credentials...";	
		cout<<"\nPlease press any key for main menu ";
		getchar();
		getchar();
		}

		return 0;
	}
/////////////////////////////////////////////
	int checkStudentCredentials(string username, string password) {
		// read file line by line & check if username-password.dat exist?
		// if it exists return 1, else 0
		ifstream read;
		read.open("db.dat");

		if (read) {
		// The file exists, and is open for input
		int recordFound = 0;
		string line;
		//string temp = username + password + ".dat";
		string temp = username + ".dat";
		cout << "\n file name is : "<<temp;
		while (getline(read, line)) {
			if(line == temp)
			{
				recordFound = 1;
				break;
			}
		}

		if (recordFound == 0)
			return 0;
		else
			return 1;
		}
		else
		{
			return 0;
		}
					
	}
/////////////////////////////////////////////
	int getAllStudentsbyName() {
		cout << "\nList of all students by their name \n";	

		cout << "\nPlease press any key to continue..";
		getchar();
		getchar();

		return 0;
	}
/////////////////////////////////////////////
	int getAllStudentsbyRollNum() {
		cout << "\nList of all students by their roll number\n";

		cout << "\nPlease press any key to continue..";
		getchar();
		getchar();

		return 0;		
		
	}
/////////////////////////////////////////////
	int deleteStudentbyFileName() {
		cout << "\nDelete any student by their name on file\n";	
		Student student;
		student.deleteStudentInfo();	

		cout << "\nPlease press any key to continue..";
		getchar();
		getchar();

		return 0;
	}
/////////////////////////////////////////////
	int checkPresenceCountbyRollNum() {
		cout << "\nCheck presence count of any Student by roll number\n";	

		cout << "\nPlease press any key to continue..";
		getchar();
		getchar();

		return 0;	
	}
/////////////////////////////////////////////
	int checkAllPresenceCountbyRollNum() {
		cout << "\nCheck presence count of all students by roll number & Name \n";		
		cout << "\nPlease press any key to continue..";
		getchar();
		getchar();

		return 0;
	}
/////////////////////////////////////////////
	int studentView() {
		cout<<"\n ------- Student Login-------- \n";		

		string username, password;

		cout<<"\nEnter username : ";
		cin>>username;

		cout<<"\nEnter password : ";
		cin>>password;

		int res = checkStudentCredentials(username, password);

		if (res  == 0) {
			cout<<"\nInvalid Credentials !!";
			cout<<"\nPlease press any key for the main menu..";
			getchar(); 
			getchar();	
			return 0;
		} 

		int goBack = 0;

		while(1) {
			system("cls");
			cout<<"\n1. Mark my attendance for today ";
			cout<<"\n2. Count my attendance";
			cout<<"\n0. Go Back <- \n";
			int choice;

			cout << "\nEnter your choice: ";
			cin >> choice;

			switch(choice)
			{
				case 1: markMyAttendance(username); 
						break;
				case 2: countMyAttendance(username); 
						break;
				case 0: goBack = 1;
						break;
				default: cout<<"\nInvalid choice. Please enter again: ";
				getchar();           	
			}   

			if(goBack == 1) {
			break; //break the loop
			}     
				
			}
	
	}
/////////////////////////////////////////////
	int markMyAttendance(string username) {
		Student student;
		student.markAttendToday();
		cout<<"\nMarking attendance for today!";
		cout<<"\nPlease press any key to continue..";

		getchar();
		getchar();

		return 0;	
	} 
/////////////////////////////////////////////
	int countMyAttendance(string username) {
		Student student;
		cout << "Current attendance as of today is " << student.checkAttendCount() << "days." << endl;
		cout << "\nCounting attendance as of today!";	
		cout << "\nPlease press any key to continue..";


		getchar();
		getchar();

		return 0;	
	} 
/////////////////////////////////////////////
	int deleteAllStudents() {
		cout << "\nAll students' information has been deleted!";
		cout << "\nPlease press any key to continue..";
		getchar(); 
		getchar();
		return 0;
	}
/////////////////////////////////////////////
	int checkListOfStudentRegistered() {
		cout<<"\nList of all students that are registered!";
		cout<<"\nPlease press any key to continue..";

		getchar(); 
		getchar();
		return 0;
	}
/////////////////////////////////////////////
	int getListOfStudentsPresenceCount() {
		cout<<"\nAll students with their presence count !!";
		cout<<"\nPlease press any key to continue..";
		getchar(); 
		getchar();
		return 0;
	}
/////////////////////////////////////////////
	int checkListOfStudentsRegistered() {
		cout<<"\n --Check List of Student Registered by Username-- ";	

		//check if record already exists..
		ifstream read;
		read.open("db.dat");

		if (read) {
			int recordFound = 0; 
			string line;
			while(getline(read, line)) {
				char name[100];
				strcpy(name, line.c_str());//kevinlwong.dat
				//char onlyname[100]; //we want only kevinlwong
				//strncpy(onlyname, name, (strlen(name) - 4));
				char ch;
				cout << endl;
				char* onlyname = strtok(name,".");
				for (int i = 0; i < strlen(onlyname); i++) {

					ch = toupper((char)onlyname[i]);

					cout << ch;
				}	
				//cout << endl << onlyname;
			}
			read.close();        
		}
		else {
		cout << "\nNo record found!";
		}
			
			
		cout << "\nPlease press any key to continue..";

		getchar(); 
		getchar();
		return 0;
	}
/////////////////////////////////////////////
	int registerStudent() {
		cout<<"\n ----- Form to Register Student ---- \n";	
		Student student;
		string name, username, password, rollno, address, father, mother;
		
		cout<<"\nEnter Name : ";     
		cin>>name;
		student.name = name;
		cout<<"\nEnter Username : ";     
		cin>>username;
		student.username = username;
		cout<<"\nEnter Password : ";     
		cin>>password;
		student.password = password;
		cout<<"\nEnter Roll no. : ";     
		cin>>rollno;
		student.rollno = rollno;
		getchar();
		
		char add[100];
		cout<<"\nEnter Address : ";     
		cin.getline(add, 100);
		student.address = add;
		cout<<"\nEnter Father's name : ";     
		cin>>father;
		student.father = father;
		cout<<"\nEnter Mother's name : ";     
		cin>>mother;
		student.mother = mother;
		cout<<"\nCurrent attendance is set to " << student.checkAttendCount() << endl;
		
		//check if record already exists..
		ifstream read;
		read.open("db.dat");
		
		if(read) {   
			int recordFound =0; 
			string line;

			while(getline(read, line)) {
			if(line == username + ".dat" )
				{

				recordFound = 1 ;
				break;

				}
			}
			if (recordFound == 1) {
				cout<<"\nUsername has already been registered. Please choose another username... ";
				getchar(); 
				getchar();
				delay();
				read.close();
				return 0;
			}
		}
		read.close();

		ofstream out;
		out.open("db.dat", ios::app);
		out << username + ".dat" << "\n";
		out.close();

		ofstream out1;
		string temp = username + ".dat";
		out1.open(temp.c_str());
		out1 << name << "\n"; 	
		out1 << username << "\n"; 	
		out1 << password << "\n";
		out1 << rollno << "\n"; 	
		out1 << add << "\n"; 	
		out1 << father << "\n";
		out1 << mother << "\n";
		out1 << "Attendance Count: " + to_string(student.checkAttendCount()) << endl;
		out1.close();

		cout<<"\nStudent has been registered successfully!";
		
		cout<<"\nPlease press any key to continue..";

		getchar(); 
		getchar();
		return 0;		
	}
/////////////////////////////////////////////
	int main(int argc, char** argv) {
		
	while(1) {
		system("cls");
		cout << "\n Attendance Management System \n";
		cout << "-------------------------------------\n\n";
		
		cout << "1. Student Login\n";
		cout << "2. Admin Login\n";
		
		cout << "0. Exit\n";
		int choice;
		
		cout << "\nEnter your choice: ";
		cin >> choice;
		
		switch(choice) {
		case 1: studentLogin(); 
				break;
		case 2: adminLogin(); 
				break;
		case 0: 
				while (1) {
				system("cls");

				cout << "\nAre you sure you want to exit? Enter y | n \n";
				char ex;
				cin >> ex;
				if(ex == 'y' || ex == 'Y')
				exit(0);
				else if(ex == 'n' || ex == 'N') {
					break;
				}
				else {
					cout << "\n Invalid choice!";
					getchar();
				}
			}
				break;		
		default: cout<<"\nInvalid choice. Please enter again.. ";
		getchar();
		}   		        
	}	
	return 0;
	}  