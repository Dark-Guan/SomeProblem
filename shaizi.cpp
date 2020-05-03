#include <iostream>
#include <iomanip>
#include <cmath>


// i >=1 && i < M
using namespace std;

int main(int argc, char ** args){

    int M, N;
    cin >> M >> N; // N < M
    double exceptNum = 0.0;
    // 先计算值都是其他值时候的期望和
    for(int i = 1; i < M; i++){
        exceptNum += pow(static_cast<double>(i)/M, N);
    }
    exceptNum = static_cast<double>(M) - exceptNum;
    cout<< fixed << setprecision(4) << exceptNum << endl;
    return 0;
}
