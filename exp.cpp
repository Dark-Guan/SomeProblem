#include <iostream>
#include <string>

using namespace std;

string add(string f1, string f2){

}

string movePoint(string f1, int b){

}

string deletZeroFirst(string f1){
    while(f1.length() > 0 && f1[0] == '0'){
        f1 = f1.substr(1);
    }
    return f1;
}

string multi(string f1, string f2){
	int pointIndex1 = f1.find(".");
	int pointLen = 0;
	if(pointIndex1 != -1){
		pointLen = f1.length() -1 - pointIndex1;
	}
    string f3 = movePoint(f2, pointLen);

	// while(f3)
}

string expf(string f, int b){
	string result = "1.0";
	for(int i = 0; i < b; i++){
		cout << result << endl;
		result = multi(f, result);
	}
	return result;
}

int main(){
	string f;
	int b;
	while(cin >> f, b){
		cout << expf(f, b);
	}
	return 0;
}