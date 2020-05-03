#include <iostream>
#include <vector>
#include <string>

using namespace std;


int FindTheWay(int x, int y, vector<string> &pattern, string route, int endx, int endy){
    if(x == endx && y == endy){
        int acState = 0;
        for(int i = 0; i < pattern.size(); i ++){
            int ret = route.find(pattern[i], 0);
            if(ret >= 0){
                acState ++;
            }
        }
        if(acState >= 2){
            return 1;
        }else{
            return 0;
        }
    }
    if(x < 0 || y < 0 || x > endx || y > endy){
        return 0;
    }

    route.push_back('R');
    int R = FindTheWay(x + 1, y, pattern, route, endx, endy);
    route.pop_back();
    
    route.push_back('D');
    int D = FindTheWay(x, y + 1, pattern, route, endx, endy);
    route.pop_back();
    return  (R + D);
}

int main(int argc, char ** args){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, m;
        string temp, route;
        vector<string> pattern;
        cin >> n >> m;
        cin >> temp;
        pattern.push_back(temp);
        cin >> temp;
        pattern.push_back(temp);
        int sum = FindTheWay(0, 0, pattern, route, n, m);
        cout << sum << endl;
    }
    return 0;
}