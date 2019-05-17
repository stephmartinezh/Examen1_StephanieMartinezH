#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;

string** llenadoMat();

void imprimirMat(string**, int);

void liberarMemoria(string**, int);

int main(){
	int tam = 11;
	string** matriz = NULL;
	matriz = llenadoMat();
	imprimirMat(matriz, tam);
	liberarMemoria(matriz,tam);
	return 0;
}

string** llenadoMat(){
	string** matriz;
	int tam = 11;
	matriz = new string*[tam];
	for(int i = 0; i<tam; i++){
		matriz[i] = new string[tam];
	}
	for(int i = 0; i<tam;i++){
		for(int j = 0; j<tam; j++){
			if((i>3 && i<=6 && j== 0) || (j>3 && j<=6 && i ==0) || (j==tam-1 && i>3 && i<=6) || (i == tam-1 && j<=6 && j>3)){
				matriz[i][j] = "[N]";
			}else{
				matriz[i][j] = "[ ]"; 
			}
		}
	}
	matriz[1][4] = "[N]";
	matriz[1][6] = "[N]";
	matriz[4][1] = "[N]";
	matriz[6][1] = "[N]";
	matriz[4][9] = "[N]";
	matriz[6][9] = "[N]";
	matriz[9][4] = "[N]";
	matriz[9][6] = "[N]";
	matriz[5][2] = "[N]";
	matriz[2][5] = "[N]";
	matriz[5][8] = "[N]";
	matriz[8][5] = "[N]";

	matriz[3][5] = "[B]";
	matriz[4][4] = "[B]";
	matriz[4][5] = "[B]";
	matriz[4][6] = "[B]";
	matriz[5][3] = "[B]";
	matriz[5][4] = "[B]";
	matriz[5][5] = "[W]";
	matriz[5][6] = "[B]";
	matriz[5][7] = "[B]";
	matriz[6][4] = "[B]";
	matriz[6][5] = "[B]";
	matriz[6][6] = "[B]";
	matriz[7][5] = "[B]";

	matriz[0][0] = "[X]";
        matriz[0][tam-1] = "[X]";
        matriz[tam-1][0] = "[X]";
        matriz[tam-1][tam-1] = "[X]";
	return matriz;
}

void imprimirMat(string** matriz, int tam){
	for(int i = 0; i<tam; i++){
		for(int j = 0; j<tam; j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
}

void liberarMemoria(string** matriz, int tam){
	for(int i = 0; i<tam; i++){
		delete[] matriz[i];
	}
	delete[] matriz;
}
