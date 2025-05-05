#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct index_pair
{
    int id, pos;
    index_pair() { pos = -1; }
    void display()
    {
        cout << "id = " << id << " pos = " << pos << endl;
    }
}pairr, pairr2;

class Employee
{
    private:
        int id;
        char name[35];
        float salary;
        char designation[15];
    public:
        Employee(){
            id = 1000;
            strcpy(name, "");
            salary = 0;
            strcpy(designation, "");
        }
        int get_id() { return id; }
        void get_data()
        {
            cout << "Enter Employee Id    : ";
            cin >> id;cin.ignore();
            cout << "Enter Employee Name  : ";
            cin.getline(name, 35);
            cout << "Enter Employee Salary: ";
            cin >> salary;cin.ignore();
            cout << "Enter Employee Post  : ";
            cin.getline(designation, 15);
        }
        void display()
        {
            cout << id << " " << name << " " << salary << " " << designation << endl;
        }
        void set_salary(float new_salary){ salary = new_salary; }
}emp;

void write_data(Employee emp1)
{
    ofstream data_writer;
    ofstream index_writer;    
    try{
        index_writer.open("index.dat", ios::app|ios::binary);
        data_writer.open("empDB.dat", ios::app|ios::binary);
        pairr.id = emp1.get_id();
        pairr.pos += 1;
        index_writer.write((char*)&pairr, sizeof(pairr));
        data_writer.write((char*)&emp1, sizeof(emp1));
        cout << "Data Inserted." << pairr.pos << endl;
    }catch(exception e){
        cout << "Error occured working with file." << endl;
    }
    index_writer.close();
    data_writer.close();
}
void read_data()
{
    ifstream datareader;  
    try{
        datareader.open("empDB.dat", ios::binary);
        while(datareader.read((char*)&emp, sizeof(emp)))
        {
            emp.display();
        }
    }catch(exception e){
        cout << "Error occured working with file." << endl;
    }
    datareader.close();
}
void modify_data(int emp_id, float new_salary)
{
    fstream datafile;    
    fstream indexfile;
    try{
        indexfile.open("index.dat",ios::in|ios::binary);
        while(indexfile.read((char*)&pairr2, sizeof(pairr2)))
        { 
            if(pairr2.id == emp_id) break;
        }
        if(indexfile.eof()) cout << "Employee Not Found." << endl;
        else{
            datafile.open("empDB.dat", ios::in|ios::out|ios::binary);
            datafile.seekp(sizeof(Employee)*pairr2.pos);
            datafile.read((char*)&emp, sizeof(emp));
            emp.set_salary(new_salary);
            datafile.seekp(sizeof(Employee)*pairr2.pos);
            datafile.write((char*)&emp, sizeof(emp));
            cout << "Employee Salary Updated." << endl;
        }
    }catch(exception e){
        cout << "Error occured working with file." << endl;
    }
    indexfile.close();
    datafile.close();
}
void search_employee(int emp_id)
{ 
    ifstream datafile;    
    ifstream indexfile;
    try{
        indexfile.open("index.dat", ios::binary);
        datafile.open("empDB.dat", ios::binary);
        while(indexfile.read((char*)&pairr2, sizeof(pairr2)))
        {
            if(pairr2.id == emp_id) break;
        }
        if(indexfile.eof()) cout << "Employee Not Found." << endl;
        else{
            datafile.seekg((sizeof(emp)*pairr2.pos), ios::beg);
            datafile.read((char*)&emp, sizeof(emp));
            emp.display();
        }
    }catch(exception e) {
        cout << "Error occured working with file." << endl;
    }
    datafile.close();
    indexfile.close();
}
int main()
{
    
    Employee e1;
    int e_id;
    float new_sal;
    int ch;
    while(true)
    {

        cout << "********Menu*******" << endl;
        cout << "1. Insert Data." << endl;
        cout << "2. Modify Salary." << endl;
        cout << "3. Search Employee." << endl;
        cout << "4. Display Data." << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Your Choice : ";
        cin >> ch;
        switch(ch)
        {
            case 1:
                    e1.get_data();
                    write_data(e1);
                    break;
            case 2:
                    cout << "Enter Employee Id  : ";
                    cin >> e_id;
                    cout << "Enter New Salary   : ";
                    cin >> new_sal;
                    modify_data(e_id, new_sal);
                    break;
            case 3:
                    cout << "Enter Employee Id  : ";
                    cin >> e_id;
                    search_employee(e_id);
                    break;
            case 4: 
                    read_data();
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