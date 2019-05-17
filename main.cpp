#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;

string** llenadoMat();

void imprimirMat(string**, int);

void liberarMemoria(string**, int);

void juego(string**, int);

int filaJuego(char);

string** turnoSegundoJugador(string**);

int main(){
	cout<<"		--Bienvenido a Hnefatafl--"<<endl;
	int tam = 11;
	string** matriz = NULL;
	matriz = llenadoMat();
	imprimirMat(matriz, tam);
	cout<<endl;
	juego(matriz, tam);
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

void juego(string** matriz, int tam){
	tam = 11;
	bool condicion = false, movimiento;
	string coordenadap = "", coordenadaMov;
	//while(condicion){
		cout<<"		Turno del jugador 1"<<endl<< "Ingrese la coordenada de la pieza: ";
		cin>> coordenadap;
		char fila,letra1,letra2;
		string letra = "";
		int columna;
		fila = coordenadap[0];
		letra1 = coordenadap[2];
		if(3<=coordenadap.length()){
			letra2 = coordenadap[3];
		}
		letra = letra1;
		letra += letra2;
		columna = stoi(letra, nullptr, 11);
		if(columna >= 10){
			columna--;
		}
		while(columna>11 || columna<0){
			cout<<"La coordenada que ha ingresado no es válida."<<endl;
			cout<<"Ingrese la columna de la pieza: ";
			cin>> columna;
		}
		int fil = filaJuego(fila);
		bool validacion = true;
		while(validacion){
			if(matriz[fil][columna] != "[N]"){
				cout<<"No hay ninguna pieza negra en la coordenada que ha ingresado"<<endl;
				cout<<"Ingrese la fila: ";
				cin>> fila;
                        	fil = filaJuego(fila);
				cout<<"Ingrese la columna: ";
				cin>>columna;
			}else{
				validacion = false;	
			}
		}
		cout<<"Ingrese la coordenada a donde desea mover la pieza: ";
		cin>> coordenadaMov;
		char filam, letram, letra2m;
		string letraM = "";
                int columnam;
                filam = coordenadaMov[0];
                letram = coordenadap[2];
                if(3<=coordenadaMov.length()){
                        letra2m = coordenadaMov[3];
                }
                letraM = letram;
                letraM += letra2m;
                columnam = stoi(letraM, nullptr, 11);
                if(columnam >= 10){
                        columnam--;
                }
		int filMov = filaJuego(filam);
		bool condicion2 = true;
		while(condicion2){
			if(fil == filMov || columna == columnam){
				if(matriz[filMov][columnam] == "[B]" || matriz[filMov][columnam] == "[N]" || matriz[filMov][columnam] == "[W]"){
					cout<<"Ya existe una pieza en la coordenada que ha ingresado"<<endl;
					cout<<"Ingrese la fila: ";
					cin>> fila;
                        		fil = filaJuego(fila);
					cout<<"Ingrese la columna: ";
					cin>>columnam;
				}else{
					matriz[filMov][columnam] = "[N]";
					matriz[fil][columna] = "[ ]";
					condicion2 = false;
					break;
				}
			}else{
				cout<<"El movimiento que ha intendo hacer no es válido."<<endl;
				cout<<"Ingrese la fila: ";
				cin>> fila;
                        	fil = filaJuego(fila);
				cout<<"Ingrese la columna: ";
				cin>> columnam;
			}
		}
		imprimirMat(matriz,tam);
		cout<<endl<<"	Turno del segundo jugador"<<endl;
		matriz = turnoSegundoJugador(matriz);
		imprimirMat(matriz, tam);
	//}
}

string** turnoSegundoJugador(string** matriz){
	string coordenadap = "", coordenadaMov;
	cout<<"Ingrese la coordenada de la pieza: ";
        cin>> coordenadap;
        char fila,letra1,letra2;
        string letra = "";
        int columna;
        fila = coordenadap[0];
        letra1 = coordenadap[2];
        if(3<=coordenadap.length()){
                 letra2 = coordenadap[3];
        }
        letra = letra1;
        letra += letra2;
        columna = stoi(letra, nullptr, 11);
        if(columna >= 10){
                 columna--;
        }
        while(columna>11 || columna<0){
                 cout<<"La coordenada que ha ingresado no es válida."<<endl;
                 cout<<"Ingrese la columna de la pieza: ";
                 cin>> columna;
        }
        int fil = filaJuego(fila);
        bool validacion = true;
	while(validacion){
        	if(matriz[fil][columna] != "[B]"){
                	cout<<"No hay ninguna pieza blanca en la coordenada que ha ingresado"<<endl;
	                cout<<"Ingrese la fila: ";
        	        cin>> fila;
			fil = filaJuego(fila);
                	cout<<"Ingrese la columna: ";
	                cin>>columna;
        	}else{
                	validacion = false;
         	}
        }
        cout<<"Ingrese la coordenada a donde desea mover la pieza: ";
        cin>> coordenadaMov;
        char filam, letram, letra2m;
        string letraM = "";
        int columnam;
        filam = coordenadaMov[0];
        letram = coordenadap[2];
        if(3<=coordenadaMov.length()){
                letra2m = coordenadaMov[3];
        }
        letraM = letram;
        letraM += letra2m;
        columnam = stoi(letraM, nullptr, 11);
        if(columnam >= 10){
                columnam--;
        }
        int filMov = filaJuego(filam);
        bool condicion2 = true;
        while(condicion2){
                if(fil == filMov || columna == columnam){
                        if(matriz[filMov][columnam] == "[B]" || matriz[filMov][columnam] == "[N]" || matriz[filMov][columnam] == "[W]"){
                                cout<<"Ya existe una pieza en la coordenada que ha ingresado"<<endl;
                                cout<<"Ingrese la fila: ";
				cin>> fila;
                        	fil = filaJuego(fila);
                                cout<<"Ingrese la columna: ";
                                cin>>columnam;
                         }else{
                                matriz[filMov][columnam] = "[B]";
                                matriz[fil][columna] = "[ ]";
                                condicion2 = false;
                                break;
                                }
                        }else{
                                cout<<"El movimiento que ha intendo hacer no es válido."<<endl;
                                cout<<"Ingrese la fila: ";
                               	cin>> fila;
                        	fil = filaJuego(fila);
                                cout<<"Ingrese la columna: ";
                                cin>> columnam;
                        }
                }
	return matriz;
}

int filaJuego(char letra){
	int col;
	if(letra == 'a' || letra == 'A'){
		col = 0;
	}
	if(letra == 'b' || letra == 'B'){
		col = 1;
	}
	if(letra == 'c' || letra == 'C'){
                col = 2;
        }
	if(letra == 'd' || letra =='D'){
                col = 3;
        }
	if(letra == 'e' || letra == 'E'){
                col = 4;
        }
	if(letra == 'f' || letra == 'F'){
                col = 5;
        }
	if(letra == 'g' || letra == 'G'){
                col = 6;
        }
	if(letra == 'h' || letra == 'H'){
                col = 7;
        }
	if(letra == 'i' || letra == 'I'){
                col = 8;
        }
	if(letra == 'j' || letra == 'J'){
                col = 9;
        }
	if(letra == 'k' || letra == 'K'){
                col = 10;
        }
	return col;
}
