#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_WIDTH = 100;

int dp[MAX_WIDTH][MAX_WIDTH];

struct Point{
    int x;
    int y;
    bool isMatch;
};

// refresh dp;
long FindTheWayDP(Point startP, Point endP){ 
    if(startP.x == endP.x && startP.y == endP.y){
        return 1;
    }

    if(startP.x < 0 || startP.y < 0 || startP.x > endP.x || startP.y > endP.y){
        return 0;
    }

    if(dp[startP.x][startP.y] != 0){
        return  dp[startP.x][startP.y];
    }

    startP.x += 1;
    long R = FindTheWayDP(startP, endP);
    startP.x -= 1;
    
    startP.y += 1;
    long D = FindTheWayDP(startP, endP);
    startP.y -= 1;

    dp[startP.x][startP.y] = R + D;
    return  dp[startP.x][startP.y];
}


long FindTheWay(Point startP, vector<string> &pattern, string route, Point endP){
    int acState = 0;
    if(!startP.isMatch){
        for(int i = 0; i < pattern.size(); i ++){
            int ret = route.find(pattern[i], 0);
            if(ret >= 0){
                acState ++;
            }
        }
        if(acState >= pattern.size()){
            startP.isMatch = true;
        }
    }
    
    if(startP.x == endP.x && startP.y == endP.y){
        if(startP.isMatch){
            return 1;
        }else{
            return 0;
        }
    }
    
    if(startP.x < 0 || startP.y < 0 || startP.x > endP.x || startP.y > endP.y){
        return 0;
    }

    if(dp[startP.x][startP.y] != 0 && startP.isMatch){
        return  dp[startP.x][startP.y];
    }

    route.push_back('R');
    startP.x += 1;
    long R = FindTheWay(startP, pattern, route, endP);
    startP.x -= 1;
    route.pop_back();
    
    route.push_back('D');
    startP.y += 1;
    long D = FindTheWay(startP, pattern, route, endP);
    startP.y -= 1;
    route.pop_back();
    return  R + D;
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


        for(int i = 0; i < MAX_WIDTH; i ++ ){
            for(int j = 0; j < MAX_WIDTH; j ++){
                dp[i][j] = 0;
            }
        }
        Point startP;
        Point endP;

        startP.x = 0;
        startP.y = 0;
        startP.isMatch = false;

        endP.x = n;
        endP.y = m;
        endP.isMatch = false;
        FindTheWayDP(startP,endP);
        long sum = FindTheWay(startP, pattern, route, endP);
        cout << sum << endl;
        sum %= 1000000007;
        cout << sum << endl;
    }
    return 0;
}