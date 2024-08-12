#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> &v){
    for(vector<int>::iterator it = v.begin(); it < v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){
    vector<int> v1;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }

    cout<<"Before swaping: "<<endl;
    printVector(v1);

    vector<int> v2;
    for(int i = 10; i > 0; i--){
        v2.push_back(i);
    }
    printVector(v2);

    v1.swap(v2);
    cout<<"after swaping: "<<endl;
    printVector(v1);
    printVector(v2);
}

//实际用途
//巧用swap可以收缩内存空间
void test02(){
    vector<int> v;
    for(int i = 0; i < 100000; i++){
        v.push_back(i);
    }

    cout<<"v capacity: "<<v.capacity()<<endl;
    cout<<"v size: "<<v.size()<<endl;

    v.resize(3);
    cout<<"v capacity: "<<v.capacity()<<endl;
    cout<<"v size: "<<v.size()<<endl;

    //收缩内存
    vector<int>(v).swap(v);     //vector<int>(v)  匿名对象
    cout<<"v capacity: "<<v.capacity()<<endl;
    cout<<"v size: "<<v.size()<<endl;
}

int main(){

    test01();

    test02();

    return 0;
}