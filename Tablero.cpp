#include <iostream>
using namespace std;

int main(){
int i,j;
int tablero[3][3];
cout<<"Rellene el tablero\n";
/*for(i=0;i<3;i++){
	for(j=0;j<3;j++){
		cin>>tablero[i][j];
	}
}*/

for(i=0;i<3;i++){
	for(j=0;j<3;j++){
		int borde = (i==0 || i==2 && j==0 || j==2) ? 2 : 0;
		tablero [i][j] ;
		//cout<<tablero [i][j];
	}
}

for(i=0;i<3;i++){
	for(j=0;j<3;j++){
		cout<<tablero[i][j];
	}
}

	
	return 0;
}
