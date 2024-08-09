#include<iostream>
using namespace std;
#include<vector>

//vector容器存放自定义数据类型
class Person{
public:
    Person(string name, int age){
        this->M_name = name;
        this->M_age = age;
    }

    string getName() const{
        return M_name;
    }
    
    int getAge() const{
        return M_age;
    }
    
private:
    string M_name;
    int M_age;
};

void test01(){
    vector<Person> v;

    Person p1("Bell", 17);
    Person p2("Chalie", 15);
    Person p3("Bery", 999);

    //向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);

    //遍历容器中的数据    *it 解出来是Person数据类型--看vector< >
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        cout<<"Name: "<<(*it).getName()<<" Age: "<<it->getAge()<<endl;
    }
}

int main(){

    test01();

    return 0;
}