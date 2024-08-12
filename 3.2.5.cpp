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

    //尾删
    v1.pop_back();
    printVector(v1);

    //插入  参数是迭代器
    v1.insert(v1.begin(), 100);
    printVector(v1);

    v1.insert(v1.begin(), 2, 1000);
    printVector(v1);

    //删除 参数也是迭代器
    v1.erase(v1.begin());
    printVector(v1);

    //v1.erase(v1.begin(), v1.end());
    v1.clear();
    printVector(v1);
}

int main(){

    test01();

    return 0;
}