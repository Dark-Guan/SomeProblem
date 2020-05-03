#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char ** args){
    vector<bool> wTree;
    int m, n;
    cin >> m >> n;
    for(int i = 0; i <= m ; i++){
        wTree.push_back(true);
    }
    for(int i = 0; i < n ; i++){
        int L, R, off;
        cin >> L >>R;
        off = L > R ? -1: 1;
        for(int j = L; j <= R * off; j+= off){
            if(j <= m && j >= 0){
                wTree[j] = false;
            }
        }
    }
    int count = 0;
    for(int i = 0; i <= m ; i++){
        if(wTree[i]){
            count ++;
        }
    }
    cout << count << endl;
    return 0;
}