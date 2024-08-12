#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>
using namespace std;
const int NUM = 5;

//选手类
class Player{
public:
    Player(string name, double score){
        this->m_Name = name;
        this->m_Score = score;
    }

    void setScore(double score){
        this->m_Score = score;
    }

    string getName(){
        return m_Name;
    }

    double getScore(){
        return m_Score;
    }

private:
    string m_Name;
    double m_Score;
};

void createPlayer(vector<Player> &v){
    string playerSeed = "ABCDE";
    for(int i = 0; i < NUM; i++){
        string name = "Player ";
        name += playerSeed[i];

        int score = 0;

        Player p(name, score);

        v.push_back(p);
    }
}

void makeScore(vector<Player> &v){
    for(vector<Player>::iterator it = v.begin(); it != v.end(); it++){
        //将评委的打分放入到deque容器中
        deque<double> d;
        for(int i = 0; i < 10; i++){
            int score = rand()%41 + 60;     //40~100
            d.push_back(score);
        }

        cout<<it->getName()<<"'s each score: "<<endl;
        for(deque<double>::iterator ait = d.begin(); ait != d.end(); ait++){
            cout<<*ait<<" ";
        }
        cout<<endl;
        cout<<"============================="<<endl;

        //排序
        sort(d.begin(), d.end());

        //remove highest and lowest
        d.pop_back();
        d.pop_front();

        //average out
        int sum = 0;
        for(deque<double>::iterator ait = d.begin(); ait != d.end(); ait++){
            sum += *ait;    //累加每个评委的打分
        }
        int average = sum / d.size();

        //将平均分赋值给选手
        it->setScore(average);
    }
}

void showPlayerInfo(vector<Player> &v){
    for(vector<Player>::iterator it = v.begin(); it != v.end(); it++){
        cout<<"Name: "<<(*it).getName()<<"\t"<<"Final score: "<<(*it).getScore()<<endl;
    }
}

int main(){

    //随机数种子
    srand((unsigned int)time(NULL));

    //创建存放选手的容器
    vector<Player> v;

    //创造并储存五名选手到vector容器
    createPlayer(v);

    makeScore(v);

    showPlayerInfo(v);

    //find the winner
    sort(v.begin(), v.end());
    cout<<"The winner is "<<v.back().getName()<<" with a score of "<<v.back().getScore()<<endl;
    
    return 0;
}