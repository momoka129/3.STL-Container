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

    //[]
    for(int i = 0; i < v1.size(); i++){
        cout<<v1[i]<<" ";
    }cout<<endl;

    //at
    for(int i = 0; i < v1.size(); i++){
        cout<<v1.at(i)<<" ";
    }cout<<endl;

    //获取第一个元素
    cout<<"first element: "<<v1.front()<<endl;

    //获取最后一个元素
    cout<<"last element: "<<v1.back()<<endl;
}

int main(){

    test01();

    return 0;
}