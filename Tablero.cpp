#include <iostream>
#define N 6
using namespace std;

int main(){

int borde[6][6];

for(int i=0;i<N;i++){
	for(int j=0;j<N;j++){
		borde[i][j] = (i==0 || j==0 || i==(N-1) || j==(N-1)) ? 3 : 0;
	}
}

for(int i=0;i<N;i++){
	for(int j=0;j<N;j++){
		cout<<borde[i][j];
	}
	cout<<"\n";
}

	
	return 0;
}
