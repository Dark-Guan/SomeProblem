#include <iostream>

using namespace std;

int shortestPath(int **metrix, int n){
    int *path = new int[n + 1];
    int newPath;
    int minPath;
    //frist
    for(int i = 0; i< n + 1; i++){
        path[i] = metrix[0][i];
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(metrix[i][j] !=INT_MAX ){
                newPath = path[i] + metrix[i][j];
                if(path[j] > newPath){
                    path[j] = newPath;
                }
            }
        }
    }
    return path[n];
}

void PrintMetrix(int **metrix, int n){
    for(int i = 0; i <= n ; i++){
        for(int j = 0; j <= n; j++){
            cout << metrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, temp;
    cin >> n;
    int **metrix = new int *[n+1];
    for (int i = 0; i <= n; i++){
        metrix[i] = new int[n+1];
    }for(int i = 0; i <= n ; i++){
        for(int j = 0; j <= n; j++){
            metrix[i][j] = INT_MAX;
        }
    }
    PrintMetrix(metrix, n);
    for(int i = 0; i <= n; i++){
        for(int j = i + 1; j <= n; j ++){
            cin >> temp;
            metrix[i][j] = temp; 
        }
    }
    PrintMetrix(metrix, n);
    cout << shortestPath(metrix, n) << endl;
    return 0;
}