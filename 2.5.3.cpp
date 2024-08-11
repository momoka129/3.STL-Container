#include<iostream>
using namespace std;
#include<vector>

//容器嵌套容器
void test01(){
    //创建大容器
    vector<vector<int>> v;

    //创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    //向小容器中添加数据
    for(int i = 0; i < 3; i++){
        v1.push_back(i+1);
        v2.push_back(i*1);
        v3.push_back(i-1);
    }

    //将小容器插入到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    //通过大容器遍历所有数据
    for(vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++){
        //(*it)--容器
        for(vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++){
            cout<<*it2<<" ";
        }
        cout<<endl;
    }
}

int main(){
    test01();
    return 0;
}