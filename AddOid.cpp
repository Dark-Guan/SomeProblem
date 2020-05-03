#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char **args){
    int n;
    vector<int> stationDis;
    map<int,int> oilStation;// map distance : oil volume;
    vector<bool> stationUsed;
    int oilS, oilV;
    int L, P;
    cin >> n;
    for(int i= 0; i < n; i++){
        cin >> oilS >> oilV;

        oilStation[oilS] = oilV;

        stationDis.push_back(oilS);

        stationUsed.push_back(false);
    }
    sort(stationDis.begin(), stationDis.end());
    cin >> L >> P;
    int timeOfAddOil = 0;
    do{
        //耗尽油量
        L = L - P;
        if(L <=0){
            // 达到了
            cout << timeOfAddOil << endl; 
            break;
        }
        //看经过了几个加油站   
        priority_queue<int,vector<int>,less<int> > pastStation;
        map<int,int>  oilVsDis;
        for(auto it = stationDis.begin(); it < stationDis.end(); it++){
            if(*it >= L && !stationUsed[it-stationDis.begin()]){
                int vOfStation = oilStation.find(*it)->second;
                pastStation.push(vOfStation);
                oilVsDis[vOfStation] = *it;
            }
        }
        if(!pastStation.size()){
            // 没法达到
            cout << "-1" << endl;
            break;
        }
        //从油量最多的加油站开始加油
        int maxVolumeOfOil = pastStation.top();
        int disOfThisStation = oilVsDis.find(maxVolumeOfOil)->second;
        auto it = find(stationDis.begin(), stationDis.end(), disOfThisStation);

        P = maxVolumeOfOil;
        stationUsed[it - stationDis.begin()] = true;
        //加油次数加1
        timeOfAddOil++;
    }while(true);
    return 0;
}