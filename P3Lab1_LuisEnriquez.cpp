
// Importar
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>

// Profundizar
using namespace std;

// Cabezaras
void printA(string*,int);
bool tri(int);


// Metodo main
int main() {
	srand((int)time(0));
	
	int op = 0;
	int m;
	int n;
	string pal;
	int fac = 0;
	
	while (op != 4) {
		
		cout<< "Menu" << endl;
		cout<< "1. Punto silla" << endl;
		cout<< "2. Numeros triangulares" << endl;
		cout<< "3. Arreglos de caracteres" << endl;
		cout<< "4. Salir" << endl;
		cout<< "Opcion: ";
		cin>>op;
		
		cout<< endl;
		
		if (op == 1) {
			int m[5][5];
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					m[i][j] = (rand()% 100)+ 1;
				}
			}
			int cont = 0;
			
			// Imprimir la matriz
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (m[i][j] < 10) {
						cout << "[0" << m[i][j] << "]";
					}else{
						cout<< "[" << m[i][j] << "]";
					}
				
				}
				cout<<endl;
			}
			
			cout<< "Puntos sillas en: " << endl;
			bool menor = true, mayor = true;
			
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					
					for (int h = 0; h < 5; h++) {
						if (m[h][j] > m[i][j]) {
							mayor = false;
						}
					}
					
					for (int k = 0; k < 5; k++) {
						if (m[i][k] < m[i][j]) {
							menor = false;
						}
					}
					
					if (mayor and menor) {
						cout << "(" << i << "," << j << ")" << " Magnitud: " << m[i][j] << endl;
						cont++;
					}
					
					mayor = true; 
					menor = true;
					
				}
			}
			
			cout << "Se encontraron " << cont << " puntos!";
			cout << endl;
			
		}
		
		if (op == 2) {
			cout<< "Numeros Triangulares" << endl;
			cout<< "Ingrese un numero: ";
			cin>>n;
			
			cout<< n;
				
			
			if (tri(n)) {
				cout << " es triangular!" << endl;
			}else{
				cout << " no es triangular! Pero ";
				for	(int t = 0; t < 100; t++) {
					if (tri(n+t)) {
						cout << (n+t);
						break;
					}
					if (tri(n-t)) {
						cout << (n-t);
						break;
					}
				}
				
				
				cout << " es el mas cercano!";
			}
			
			
		}
		
		if (op == 3) {
			cout<< "Permutaciones" << endl;
			cout<< "Ingrese una palabra: ";
			cin>>pal;
			fac = 1;
			
			for (int i = 1; i <= pal.length(); i++) {
				fac *= i;
			}
			
			cout<< "Se permuta " << fac << " veces!" << endl;


			
			string modi = pal;
			int vuelta = fac / pal.length();
			int pos = 0;

			
			string * arr = new string[fac];
			
			
			for (int a = 0; a < fac; a++) { // Llenar									
				arr [a] = pal;		
			}
			
			for (int b = 0; b < pal.length(); b++) {
				pos = b;			
				for (int a = 0; a < fac; a++) { // Recorrer arreglo	
					modi = arr[a];				
					modi[pos] = pal[b];	
					if (pos < pal.length() - 1) {	
						pos ++;						
					}else{
						pos = 0;	
					}
					arr [a] = modi;						
				
				}
			}
			
			
			printA(arr, 0);
			
			
		}
		
		cout<< endl;					
	}
	
	return 0;
		
}

void printA(string* A,int pos) {
	if (pos == sizeof(A)) {
		cout<< A[pos] << endl;
	}else{
		cout<< A[pos] << endl;
		return printA(A,pos + 1) ;
	}	
}

bool tri(int n) {
	bool p = false;
	
	for (int i = 1; i <= n; i++) {
		n -=i;
				
		if(n == 0) {
			p = true;
			break;
		}
	}
	
	return p;
	
}

