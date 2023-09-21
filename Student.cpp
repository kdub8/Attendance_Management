#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <limits>
#include <bits/stdc++.h>
#include <ctime>

using namespace std;

class Student {
    public:
    int attendanceCount = 0;
    string name, username, password, rollno, address, father, mother;

    Student() {
        attendanceCount = 0;
    }

    string getUsername () {
        return username;
    }

    int checkAttendCount() {
        return attendanceCount;
        };

        #if 0
    void displayDate () {
        time_t now = time(0); // get current dat/time with respect to system  
  
        char* dt = ctime(&now); // convert it into string  
    
        cout << dt << endl; // print local date and time  
    
        //tm* gmtm = gmtime(&now); // for getting time to UTC convert to struct  
        //dt = asctime(gmtm);  
        //cout << "The UTC date and time is:" << dt << endl; // print UTC date and time  
    }
    #endif
//todo
//work on deleting the old attendance count and adding a new updated attendance count
    void markAttendToday() {
        string username;

        time_t now = time(0); // get current dat/time with respect to system  
  
        char* dt = ctime(&now); // convert it into string

        cout << "Enter your username: ";
        cin >> username;
        string filename = username.append(".dat");
        fstream userfile;
        userfile.open(filename);
        GotoLine(userfile, 8);
        string sa;
        string count = "";
        while (getline(userfile, sa)) {
            userfile >> sa;
        }
        cout << "Old ";
        for (int i = 0; i < sa.length(); i++) {
            cout << sa[i];
        }
        count.append(sa, 18, -1);
        int intCount = stoi(count);
        ++intCount;
        cout << endl << "Current Attendance Count is " << intCount << " as of " << dt << endl;
        count = to_string(intCount);
        userfile.close();
        delete_line(filename.c_str(), 8);
        
        #if 1
        ofstream myfile;
        myfile.open(filename, fstream::app);

        myfile << endl << "Attendance Count: " << count;
        myfile.close();
        #endif

        
    };

    void deleteStudentInfo () {
        int status;
        string fileName;
        cout<<"Enter the name of the file you wish to delete (FORMAT: username.dat): ";
        cin>>fileName;
        status = remove(fileName.c_str());
        if(status==0)
            cout<<"\nFile Deleted Successfully!";
        else
            cout<<"\nError Occurred!";
        cout<<endl;

        ifstream userfile;
        userfile.open("db.dat");
        ofstream temp;
        temp.open("temp.dat");

        string line;        
        while (getline(userfile,line) && !EOF) {
            line.replace(line.find(fileName),fileName.length(),"");
            temp << line << endl;

        }
        userfile.close();
        temp.close();
        remove("db.dat");
        rename("temp.dat","db.dat");
    };

    std::fstream& GotoLine(std::fstream& file, unsigned int num) {
        file.seekg(std::ios::beg);
        for(int i=0; i < num - 1; ++i){
            file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        return file;
    }

#if 1
    void delete_line(const char * file_name, int n)
    {
        // open file in read mode or in mode
        ifstream is(file_name);
        string s(file_name);
        //cout << "File name is: " << s << endl;
        // open file in write mode or out mode
        ofstream ofs;
        ofs.open("temp.txt", ofstream::out);
        //cout << "Output file opened successfully" << endl;
        // loop getting single characters
        char c;
        int line_no = 1;
        while (is.get(c))
        {
            // if a newline character
            if (c == '\n')
            line_no++;
    
            // file content not to be deleted
            if (line_no != n)
                ofs << c;
        }
    
        // closing output file
        ofs.close();
    
        // closing input file
        is.close();
    
        // remove the original file
        int status;
        status = remove(file_name);
        if(status!=0)
            cout<<"\nError Occurred!";
    
        // rename the file
        if (rename("temp.txt", file_name) != 0)
            perror("Error renaming file...");

    }
    #endif

};