#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;


struct Node{
    int x,y;
    string s;
    bool operator < (const Node& other) const { // 重载运算符需要加上const
        return x < other.x;
    }
};

struct LessNode {
    bool operator()(const Node& n1,const Node& n2) const { 
        return n1.x < n2.x;
    }
};

struct GreaterNode {
    bool operator()(const Node& n1,const Node& n2) const { 
        return n1.x > n2.x;
    }
};


// 比较少用
bool compareNode(const Node& n1,const Node& n2){
    return n1.x < n2.x;
}

// sort 
void sortSomething(){
    // 单个元素
    vector<int> nums;
    sort(nums.begin(),nums.end()); // 默认使用less 排序，从小到大
    sort(nums.begin(),nums.end(),greater<int>());

    // 键值对
    vector<pair<int,int>> pairs;
    sort(pairs.begin(),pairs.end());
    sort(pairs.begin(),pairs.end(),greater<pair<int,int>>());

    // vector<vector<int>> 
    vector<vector<int>> vecs = {{1,3,2},{1,2,3}};
    sort(vecs.begin(),vecs.end());
    sort(vecs.begin(),vecs.end(),greater<vector<int>>());

    vector<Node> nodes;
    sort(nodes.begin(),nodes.end());// 使用<运算符重载
    sort(nodes.begin(),nodes.end(),compareNode);// 比较函数
    sort(nodes.begin(),nodes.end(),LessNode());// 比较函数对象
    sort(nodes.begin(),nodes.end(),[](const Node& n1,const Node& n2) {  // lambda function.
        return n1.x < n2.x;
    });
}


void CustomPriorityQueue(){
    priority_queue<int> pq1;  // 最大堆,less
    pq1.push(1);
    pq1.push(1);
    pq1.push(2);
    std::cout << pq1.size() << '\t' << pq1.top() << std::endl;
    pq1.pop();
    std::cout << pq1.size() << '\t' << pq1.top() << std::endl;
    pq1.pop();
    std::cout << pq1.size() << '\t' << pq1.top() << std::endl;
    
    priority_queue<int,vector<int>,greater<int>> pq2; // 最小堆
    pq2.push(1);
    pq2.push(2);

    priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pq3;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq4;

    priority_queue<Node> pq5;
    priority_queue<Node,vector<Node>,LessNode> pq6;
    // 错误使用
    // priority_queue<Node,vector<Node>,[](const Node& n1,const Node& n2){
    //     return n1.x < n2.x;
    // }> pq5;
}


void CustomSet(){
    set<int,less<int>> st1;
    set<int,greater<int>> st2;

    set<pair<int,int>> st3;
    set<pair<int,int>,greater<pair<int,int>>> st4;

    set<Node> st5;   // 注意唯一key，比较函数需要包含所有元素，否则插入数据可能失败
    set<Node,LessNode> st6;
    set<Node,GreaterNode> st7;
}


int main(int argc, char const *argv[])
{
    sortSomething();
    CustomPriorityQueue();
    CustomSet();
    return 0;
}


