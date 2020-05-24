#include <iostream>
#include <string>
#include <cmath>
/*
0
1  2
34 56
7
*/
using namespace std;

int aHeap[1024];
void init(){
    for(int i= 0; i < 1024; i++){
        aHeap[i] = INT_MAX; // means no data
    }
}

void add(int x)
{   int index = 0;
    while(aHeap[index] != INT_MAX){
        index ++;
    }
    aHeap[index] = x;
    do{
        int fatherIndex;
        if((index % 2)){
            fatherIndex = index / 2;
        }else{
            fatherIndex = (index - 1 ) /2;
        }
        if(fatherIndex < 0){
            break;
        }
        if(aHeap[fatherIndex] > aHeap[index]){
            int temp = aHeap[index];
            aHeap[index] = aHeap[fatherIndex];
            aHeap[fatherIndex] = temp;
            index = fatherIndex;
        }else{
            break;
        }
    }while(true);
}

void del(int x){
    int index = 0;
    int tail = 0;
    while(aHeap[index] != x){
        index ++;
        if(index > 1024){
            return;
        }
    }
    while(aHeap[tail] != INT_MAX){
        tail ++;
    }
    tail -- ;
    aHeap[index] = aHeap[tail];
    aHeap[tail] = INT_MAX;
    // move up
    do{
        int fatherIndex;
        if((index % 2)){
            fatherIndex = index / 2;
        }else{
            fatherIndex = (index - 1 ) /2;
        }
        if(fatherIndex < 0){
            break;
        }
        if(aHeap[fatherIndex] > aHeap[index]){
            int temp = aHeap[index];
            aHeap[index] = aHeap[fatherIndex];
            aHeap[fatherIndex] = temp;
            index = fatherIndex;
        }else{
            break;
        }
    }while(true);
    // move down
    do{
        int lSon = index * 2 + 1;
        int rSon = index * 2 + 2;
        if(aHeap[index] > aHeap[lSon]){
            int temp = aHeap[index];
            aHeap[index] = aHeap[lSon];
            aHeap[lSon] = temp;
            index = lSon;
        }else if(aHeap[index] > aHeap[rSon]){
            int temp = aHeap[index];
            aHeap[index] = aHeap[rSon];
            aHeap[rSon] = temp;
            index = rSon;
        }else{
            break;
        }
    }while(true);
}

void print(){
    int index = 0;
    int startI = pow(2, index)-1;
    while(aHeap[startI] != INT_MAX){
        int num = pow(2, index);
        for(int i = 0; i< num ; i++ ){
            if(aHeap[i + startI] != INT_MAX){
                cout << aHeap[i + startI];
            }
        }
        cout << endl;
        index ++;
        startI = pow(2, index)-1;
    }
}

int main(){
    init();
    int n, m;
    cin >> n >> m;
    int temp;
    string cmd;
    for(int i  =0;i < n; i++){
        cin >> temp;
        add(temp);
    }
    print();
    for(int i = 0; i < m; i++){
        cin >> cmd >> temp;
        if(cmd == "add"){
            add(temp);
            print();
        }else if(cmd == "delete"){
            del(temp);
            print();
        }
    }
}