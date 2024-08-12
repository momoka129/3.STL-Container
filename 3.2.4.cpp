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
    printVector(v1);

    if(v1.empty()){
        cout<<"The vector is empty."<<endl;
    }  //如果为真 代表容器为空
    else{
        cout<<"The vector is not empty."<<endl;
        cout<<"Vector v1's Capacity: "<<v1.capacity()<<endl;
        cout<<"v1's size: "<<v1.size()<<endl;
    }

    //重新指定大小
    //v1.resize(15);
    v1.resize(15,100);
    printVector(v1);        //如果重新指定大小大于原来size 默认用0填充

    v1.resize(5);
    printVector(v1);

}

int main(){

    test01();

    return 0;
}