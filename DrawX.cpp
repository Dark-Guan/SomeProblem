
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<char> drawXwidth(int n){
    vector<char> X;
    if(n == 1)
    {
        X.push_back('X');
        return X;
    }
    vector<char> retVec = drawXwidth(n-1);
    int size = retVec.size();
    int width = sqrt(size);
    for(int i = 0; i < 3 * width ; i ++){
        for(int j = 0; j < 3 * width ; j ++){
            if(i < width){
                if(j < width ){
                    X.push_back(retVec[j + i * width]);
                }else if(j < 2 * width){
                    X.push_back(' ');
                }else if(j < 3 * width){
                    X.push_back(retVec[j-2*width + i * width]);
                }
            }else if(i < 2 * width){
                if(j < width ){
                    X.push_back(' ');
                }else if(j < 2 * width){
                    X.push_back(retVec[j - width + (i-width)*width]);
                }else if(j < 3 * width){
                    X.push_back(' ');
                }
            }else if( i < 3 * width){
                if(j < width ){
                    X.push_back(retVec[j + (i-2*width)*width]);
                }else if(j < 2 * width){
                    X.push_back(' ');
                }else if(j < 3 * width){
                    X.push_back(retVec[j-2*width + (i-2*width)*width]);
                }
            }
        }
    }
    return X;
}

int main(int argc, char** args){
    int n;
    cin >> n;
    vector<char> drawX = drawXwidth(n);
    int len = drawX.size();
    int width = sqrt(len);
    for(int i = 0; i < width; i++){
        for(int j = 0; j < width; j++){
            cout << drawX[i * width + j];
        }
        cout << endl;
    }
    return 0;
}