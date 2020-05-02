#include <stdio.h>
#include <stdbool.h>
static int count = 0;

// dvide and conquer
int f(int n , int m){
    count ++ ;
    if(n < 0 || m < 0){
        return 0;
    }
    if( n == 0 || m == 0){
        return 1;
    }
    return f(n -1, m) + f(n , m -1);
}

// dynamic program
static int dp[100][100] = {0};
int dpRes(int n, int  m){
    for(int i = 0; i<= n; i ++){
        dp[i][0] = 1;
    }
    for(int i = 0; i <= m; i++){
        dp[0][i] = 1;
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i -1][j] + dp[i][j - 1];
        }
    }
    return dp[n][m];
}

// dvide and conquer
static int cache[100][100] = {0};
static int count1 = 0;
int f_with_cache(int n , int m){
    count1 ++ ;
    if(n < 0 || m < 0){
        return 0;
    }
    if( n == 0 && m == 0){
        return 1;
    }
    if(cache[n][m] != 0){
        return cache[n][m];
    }

    cache[n][m] =  f_with_cache(n -1, m) + f_with_cache(n , m -1);
    return cache[n][m];
}

// DFS ???? BFS ???? ?????????????????
// ? ? ? ? ?????
#define COL 5
#define ROW 4

bool visited[COL+1][ROW+1] = {false};
int step(int x, int y, int n, int m){

    if(x < 0 || y < 0 || x > n || y > m){
        return 0; // dead end
    }

    if( x == n && y == m){
        return 1;// find it
    }

    if(visited[x][y]){
        return 0; // has been there
    }

    visited[x][y] = true;
    int sum = 0;

    sum += step(x - 1, y, n, m);// go left
    sum += step(x + 1, y, n, m);// go right
    sum += step(x, y - 1, n, m);// go up 
    sum += step(x, y + 1, n, m);// go down

    visited[x][y] = false;
    return sum;
}

int main(int argc, char ** ags){
    int res1 = f(15,15);
    int res2 = dpRes(15,15);
    int res3 = f_with_cache(15, 15);
    printf("routes dc %d cout %d VS dp %d\n", res1, count, res2);
    printf("routes f_with_cache %d cout %d\n", res3, count1);
    // 不允许经过某个点
    visited[2][2] = true;
    printf("step sum %d\n",step(4, 4, COL, ROW));
    // 不允许重复的边
    
    // 正好通过所有的定点需要的次数

    // 正好通过所有点边

    return 0;
}

// 国际象棋皇后问题
// DFS 深度上 STEP 构造每一步
// BFS 广度上 option 构造判定条件

// 24点问题

// 数独问题，构造而外的存储空间

//推荐使用迭代家cache的手段；
