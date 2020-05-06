#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int FindMinPrint(int index,string array, int end){
	
	int num;
	for(int i = 0; i < array.size(); i++){
	   if(i<= index && array[i] == 'G'){
	   	num++;
	   }else if(i> index && array[i] == 'R'){
	   	num++;
	   }
	}
	num = max(num, FindMinPrint(index + 1, array, end));
	return num;
}

int main()
{
	string input;
	cin >> input;
    cout << FindMinPrint(0, input, input.size());
	return 0;
}
