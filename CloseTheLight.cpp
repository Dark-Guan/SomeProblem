#include <iostream>

using namespace std;

// 典型的深度优先的搜索；
// 这个题目的节点数量巨大，如果全部构造出来，必然消耗大量时间和内存；
// 开始的 标号startIndex
// 开始额 层级startLevel
// 剩下的珠子个数
// 到达重点的层级
void findCount(int startIndex, int startLevel, int boltCount, int endDepth){
    if(startLevel == endDepth){
        cout << startIndex << endl;
        return;
    }
    if(boltCount == 0){
        boltCount = 1;
    }
    if(boltCount % 2){ //剩下的珠子一分为二 // 遍历
        //right
        findCount(startIndex*2, ++startLevel, (boltCount+1)/2, endDepth);
    }else{
        //left
        findCount(startIndex*2 + 1, ++startLevel, (boltCount)/2, endDepth);
    }
}

void findCount1(int startIdex, int startLevel, int boltCount, int endDepth){
    if(startLevel == endDepth){
        cout << startIdex << endl;
        return;
    }
    if(boltCount == 0){
        boltCount = 1;
    }
    if(boltCount % 2){
        //right
        findCount(startIdex*2, ++startLevel, (boltCount+1)/2, endDepth);
    }else{
        //left
        findCount(startIdex*2 + 1, ++startLevel, (boltCount)/2, endDepth);
    }
}

int main(int argc, char **args){
    int D, N;
    while(cin >> D >> N){
        findCount(1, 1, N, D);
    }
    return 0;
}