#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Student
{
    private:
        int roll_no;
        char name[35];
        char div;
        char address[15];
    public:
        Student(){
            roll_no = 999;
            strcpy(name, "");
            div = ' ';
            strcpy(address, "");
        }
        int get_rollcall() { return roll_no; }
        void get_info()
        {
            cout << "Enter Roll-No: ";
            cin >> roll_no;cin.ignore();
            cout << "Enter Name   : ";
            cin.getline(name, 35);
            cout << "Enter Div    : ";
            cin >> div;cin.ignore();
            cout << "Enter Address: ";
            cin.getline(address, 15);
        }
        void display()
        {
            cout << roll_no << " " << name << " " << div << " " << address << endl;
        }
}stud;

void write_data(Student emp1)
{
    ofstream data_writer;
    try{
        data_writer.open("studentDB.dat", ios::app|ios::binary);
        data_writer.write((char*)&emp1, sizeof(emp1));
    }catch(exception e){
        cout << "Error occured working with file." << endl;
    }
    data_writer.close();
}
void read_data()
{
    ifstream datareader;  
    try{
        datareader.open("studentDB.dat", ios::binary);
        while(datareader.read((char*)&stud, sizeof(stud)))
        {
            stud.display();
        }
    }catch(exception e){
        cout << "Error occured working with file." << endl;
    }
    datareader.close();
}
void delete_data(int roll_no)
{
    ifstream datafile;
    ofstream newFileWriter("newFile.dat", ios::binary);
    try{
        datafile.open("studentDB.dat", ios::binary);

        while(datafile.read((char*)&stud, sizeof(stud)))
        { 
            if(stud.get_rollcall() == roll_no) continue;
            newFileWriter.write((char*)&stud, sizeof(stud));
        }
    }catch(exception e){
        cout << "Error occured working with file." << endl;
    }
    newFileWriter.close();
    datafile.close();
    remove("studentDB.dat");
	rename("newFile.dat","studentDB.dat");
}
void search_student(int roll_no)
{ 
    ifstream datafile;    
    try{
        datafile.open("studentDB.dat", ios::binary);
        while(datafile.read((char*)&stud, sizeof(stud)))
        {
            if(stud.get_rollcall() == roll_no) break;
        }
        if(datafile.eof()) cout << "Student Not Found." << endl;
        else stud.display();
    }catch(exception e) {
        cout << "Error occured working with file." << endl;
    }
    datafile.close();
}
int main()
{  
    Student s1;
    int roll_num;
    int ch;
    while(true)
    {
        cout << "********Menu*******" << endl;
        cout << "1. Insert Data." << endl;
        cout << "2. Display Data." << endl;
        cout << "3. Search Student." << endl;
        cout << "4. Delete Data." << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Your Choice : ";
        cin >> ch;
        switch(ch)
        {
            case 1:
                    stud.get_info();
                    write_data(stud);
                    break;
            case 2:
                    read_data();
                    break;
            case 3:
                    cout << "Enter Student Roll-No: ";
                    cin >> roll_num;
                    search_student(roll_num);
                    break;
            case 4: 
                    cout << "Enter Student Roll-No: ";
                    cin >> roll_num;
                    delete_data(roll_num);
                    break;
            case 5:
                    exit(0);
                    break;
            default:
                    cout << "Blind." << endl;
                    break;
        }
    }
    return 0;
}