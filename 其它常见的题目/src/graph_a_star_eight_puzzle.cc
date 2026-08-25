#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


struct Node {
    string state;
    int g;
    int h;
    Node(const string& _state, int _g,int _h) : state(_state), g(_g), h(_h) {}
    bool operator<(const Node& rhs) const {
        return g + h > rhs.g + rhs.h;
    }
};


int getH(const string& state, const string& goal_state,int level) {
    int h = 0;
    int n = state.length();
    for (int i = 0; i < n; ++i) {
        if (state[i] != 0 && state[i] != goal_state[i]) {
            int cur_x = i % level, cur_y = i / level;
            int goal_i = goal_state[i] - 1, goal_x = goal_i % 3, goal_y = goal_i / 3;
            h += abs(cur_x - goal_x) + abs(cur_y - goal_y);
        }
    }
    return h;
}


class Solution {
public:
    const int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int eightPuzzle(string start,string goal,int level){
        if(start == goal) return 0;

        priority_queue<Node> q;
        q.push({start,0,0});

        unordered_set<string> visited;
        int ans = -1;
        while(!q.empty()){
            auto cur = q.top();
            q.pop();
            int idx = 0;
            for(int i=0;i<cur.state.length();i++){
                if(cur.state[i] == '0'){
                    idx = i;
                    break;
                }
            }
            if(cur.state == goal){
                ans = cur.g;
                break;
            }
            int curx = idx / level;
            int cury = idx % level;
            visited.insert(cur.state);
            for(auto dir : dirs){
                int nx = curx + dir[0];
                int ny = cury + dir[1];
                if(nx < 0 || nx >= level) continue;
                if(ny < 0 || ny >= level) continue;
                string nextState = cur.state;
                swap(nextState[idx],nextState[nx * level + ny]);
                if(visited.count(nextState)) continue;

                int h = getH(nextState,goal,level);
                q.push({nextState,cur.g+1,h});
            }
        }
        return ans;
    }
};

int main() {
    std::cout << Solution().eightPuzzle("123456780","352610784",3) << std::endl;
    return 0;
}
