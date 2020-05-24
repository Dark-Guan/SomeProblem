#include <iostream>
#include <map>

using namespace std;

int FindMaxPair(map<int,pair<int,bool> > all){
    map<int,int>  balance;
    int result = 0;
    for(auto it=all.begin(); it != all.end(); it++){
        if(it->second.second){ // encounter black
            balance[it->second.first,it->first];
        }else{// white
            for(auto itB = balance.begin(); itB != balance.end(); itB++){
                if(it->second.first <= itB->first){
                    itB = balance.erase(itB);
                    result ++;
                }
            }
        }
    }
    return result;
}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i <t ; i ++){
        int n, m;
        cin >> n >> m;
        map<int,pair<int,bool> > all;
        int x, y;
        for(int i =0; i < n ; i++){
            cin >> x >> y;
            all[x] = make_pair(y, true); // true for balck
        }
        for(int i = 0; i< m; i++){
            cin >> x >> y;
            all[x] = make_pair(y, false);
        }
        cout << FindMaxPair(all) << endl;
    }
    return 0;
}