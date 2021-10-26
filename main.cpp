#include "FIFO/include/Scheduler.hpp"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <string>
using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoXY(int,int);
void clearSide();

int main(){
    string *names;
    int *test, s = 0;
	int menu_item = 0, run, x = 7;
	bool running = true;

    // Titulo
    system("cls");
    system("title Algoritmos de Scheduling");
	gotoXY(10, 5); cout << "Simulador de Algoritmos Scheduling.";
	gotoXY(10, 7); cout << "> ";
    // Imprimir una l�nea divisoria
	for(int i = 5; i <= 12; i++){
        gotoXY(50, i);
        cout << "|";
	}
	gotoXY(50, 5); cout << "|";
    // Mientras la constante running sea verdadera se ejecutar� el programa
	while(running){
        // Men� principal
        gotoXY(10, 7);  cout << "1) FIFO";
		gotoXY(10, 8);  cout << "2) SJF         ";
		gotoXY(10, 9);  cout << "3) Round Robin";
		gotoXY(10, 10); cout << "4) Priority";
		gotoXY(10, 11); cout << "Salir...";
		// Hacer pausa para que se puedan ejecutar los input
		system("pause>nul");
        // Flecha abajo
		if(GetAsyncKeyState(VK_DOWN) && x != 11){
            gotoXY(8,x); cout << "  ";
            x++;
            gotoXY(8,x); cout <<"\033[1;32m> \033[0m";
            menu_item++;
            continue;
        }
        // Flecha arriba
		if(GetAsyncKeyState(VK_UP) && x != 7){
            gotoXY(8,x); cout << "  ";
            x--;
            gotoXY(8,x); cout <<"\033[1;32m> \033[0m";
            menu_item--;
            continue;
        }
        // Enter
		if(GetAsyncKeyState(VK_RETURN)){
			switch(menu_item){
				case 0: {
				    // Borramos el sector derecho de la pantalla
				    clearSide();
				    int y = 10;
					gotoXY(60,6);
					cout << "Algoritmo FIFO";
					gotoXY(60,7);
					cout << "Tamanho de lista: "; cin >> s;
					test = new int[s];
					names = new string[s];
					for(int i = 0; i < s; i++){
                        gotoXY(60, y); cout <<"BT (" << i << ") > "; cin >> test[i];
                        gotoXY(75, y); cout <<"PID (" << i << ") > "; cin >> names[i];
                        y++;
					}
					break;
				}
				case 1: {
				    // Borramos el sector derecho de la pantalla
				    clearSide();
					gotoXY(60,7);
					cout << "Algoritmo SJF     ";
					break;
				}
				case 2: {
				    // Borramos el sector derecho de la pantalla
				    clearSide();
					gotoXY(60,7);
					cout << "Algoritmo Round Robin";
					break;
				}
				case 3: {
				    // Borramos el sector derecho de la pantalla
				    clearSide();
					gotoXY(60,7);
					cout << "Algoritmo Priority     ";
					break;
				}
				case 4: {
				    // Borramos el sector derecho de la pantalla
				    clearSide();
					gotoXY(60,7);
					cout << "Saliendo              ";
					running = false;
				}
			}
		}
	}
	gotoXY(20,100);
	return 0;
}
// Función para mover el cursor a una coordenada X,Y
void gotoXY(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
}
// Función para limpiar una sección de la pantalla
void clearSide(){
    for(int i = 5; i < 30; i++){
        gotoXY(60, i);
        cout << "                                                          ";
    }
}
