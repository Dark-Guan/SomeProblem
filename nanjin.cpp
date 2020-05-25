#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    int nPoint, mRoad, timeLimit, start, end;
    cin  >> nPoint >> mRoad >> timeLimit >> start >> end;
    vector<int> cost;
    vector<int> happy;
    map<pair<int,int>,int> path;
    int x, y, temp;
    for(int i = 0; i < nPoint; i++){
        cin >> temp;
        cost.push_back(temp);
    }
    for(int i = 0; i < nPoint; i++){
        cin >> temp;
        happy.push_back(temp);
    }
    for(int i = 0; i < mRoad; i++){
        cin >> x >> y >> temp;
        path.insert(make_pair(make_pair(x,y), temp));
        path.insert(make_pair(make_pair(y,x), temp));
    }
    // max happy 
    // use all the time and max happy
}
