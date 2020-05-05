#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	int temp;
	vector<int> a, b, o;
	cin >> n;
	for(int i=0; i<n*n; i++){
		cin >> temp;
		a.push_back(temp);
		o.push_back(0);
	}
	for(int i=0; i<n*n; i++){
		cin >> temp;
		b.push_back(temp);
	}
	for(int i=0; i<n; i++){
	    for(int j=0; j<n; j++){
		    o[j+i*n] = a[i*n]*b[j] +
		         a[i*n+1]*b[j+n] +
		          a[i*n + 2]*b[j+2*n];	
	    }
	}
    for(int i=0; i<n; i++){
    	cout << o[i*n] << " ";
    	cout << o[i*n+1] << " ";
    	cout << o[i*n + 2];
    	cout << endl;
    }
	return 0;
}