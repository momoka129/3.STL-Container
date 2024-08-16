#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define Planning 1
#define Art 2
#define Research 3
#include<ctime>

class Employee{
public:
    string m_name;
    int m_salary;
};

void printEmployee(vector<Employee> &v){
    for(vector<Employee>::iterator it = v.begin(); it != v.end(); it++){
        cout<<"Name: "<<it->m_name<<"\tsalary: "<<it->m_salary<<endl;
    }
    cout<<endl;
}

void createEmployee(vector<Employee> &v){
    string nameSeed = "ABCDEFGHIJ";
    for(int i = 0; i < 10; i++){
        Employee e;
        e.m_name = "Employee ";
        e.m_name += nameSeed[i];

        e.m_salary = rand()%10000 + 10000;    //10000 ~ 19999

        v.push_back(e);
    }
}

void setGroup(vector<Employee> &v, multimap<int,Employee> &m){
    for(vector<Employee>::iterator it = v.begin(); it != v.end(); it++){
        int ID = rand()%3 + 1;      // 1 2 3
        m.insert(make_pair(ID, *it));
    }
}

void showGroup(multimap<int,Employee> &m){
    cout<<"Planning department: "<<endl;
    cout<<"----------------------------------"<<endl;
    multimap<int, Employee>::iterator pos = m.find(Planning);
    int counter = m.count(Planning);
    int count = 0;
    for(; pos != m.end() && count < counter; pos++, count++){
        cout<<"Name: "<<pos->second.m_name<<"\tsalary: "<<pos->second.m_salary<<endl;
    }
    cout<<endl;

    cout<<"Art department: "<<endl;
    cout<<"----------------------------------"<<endl;
    pos = m.find(Art);
    counter = m.count(Art);
    count = 0;
    for(; pos != m.end() && count < counter; pos++, count++){
        cout<<"Name: "<<pos->second.m_name<<"\tsalary: "<<pos->second.m_salary<<endl;
    }
    cout<<endl;

    cout<<"Research&Development department: "<<endl;
    cout<<"----------------------------------"<<endl;
    pos = m.find(Research);
    counter = m.count(Research);
    count = 0;
    for(; pos != m.end() && count < counter; pos++, count++){
        cout<<"Name: "<<pos->second.m_name<<"\tsalary: "<<pos->second.m_salary<<endl;
    }
    cout<<endl;
}

int main(){

    srand((unsigned int)time(NULL));

    vector<Employee> v;

    //create employees and put into vector container
    createEmployee(v);

    printEmployee(v);

    //grouping
    multimap<int, Employee> m;
    setGroup(v,m);

    showGroup(m);

    return 0;
}