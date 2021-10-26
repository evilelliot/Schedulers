#include "FIFO/include/Scheduler.hpp"
#include "SJF/include/SJF.hpp"
#include "RR/include/Robin.hpp"
#include "Priority/QS.hpp"
#include "Priority/nodos.hpp"
#include "Priority/Priority.hpp"
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
	for(int i = 5; i <= 20; i++){
        gotoXY(50, i);
        cout << "|";
	}
	gotoXY(50, 5); cout << "|";
    // Mientras la constante running sea verdadera se ejecutará el programa
	while(running){
        // Menú principal
        gotoXY(10, 7);  cout << "1) FIFO";
		gotoXY(10, 8);  cout << "2) SJF         ";
		gotoXY(10, 9);  cout << "3) Round Robin";
		gotoXY(10, 10); cout << "4) Priority";
		gotoXY(10, 11); cout << "Salir...";
		gotoXY(10, 12); cout << "Limpiar pantalla";
		// Hacer pausa para que se puedan ejecutar los input
		system("pause>nul");
        // Flecha abajo
		if(GetAsyncKeyState(VK_DOWN) && x != 12){
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
			// Listo
			switch(menu_item){
				case 0: {
				    // Borramos el sector derecho de la pantalla
				    clearSide();
                    int y = 4;
				    int n = 0;
                    int tmp_bt = 0;
                    string tmp_pid;
                    gotoXY(60, 2);
                    cout << "Tamaño de la lista: "; cin >> n;
                    Scheduler sch(n);
                    // Ingresar datos
                    for(int i = 0; i < n; i++){
                        y = y + 2;
                        gotoXY(60, y);
                        cout << "[" << i+1 << "] Set PID: "; cin >> tmp_pid;
                        gotoXY(90, y);
                        cout << "[" << i+1 << "] Set BT:  "; cin >> tmp_bt;
                        sch.enqueue(tmp_bt, tmp_pid); 
                    }
                    sch.scheduleProcess();
					break;
				}
				// Listo
				case 1: {
				    // Borramos el sector derecho de la pantalla
				    clearSide();
					gotoXY(60,7);
					cout << "Algoritmo SJF     ";
                    int size = 0;
                    gotoXY(60, 9);
                    cout << "Tamaño de lista: "; cin >> size;
                    // Inicializando la lista
                    SJF sch(size);
                    sch.scheduler();

					break;
				}
				// Listo
				case 2: {
					int p = 0;
					int q = 0;
				    // Borramos el sector derecho de la pantalla
				    clearSide();
					gotoXY(60,7);
					cout << "Ingresa la cantidad de procesos: "; cin >> p;
					gotoXY(60, 8);
					cout << "Ingresa el quantum: "; cin >> q;
					Robin robin(p, q);
					break;
				}
				case 3: {
				    // Borramos el sector derecho de la pantalla
				    clearSide();
					gotoXY(60,7);
					Priority p(3);
  					p.scheduler();
					break;
				}
				case 4: {
				    // Borramos el sector derecho de la pantalla
				    clearSide();
					gotoXY(60,7);
					cout << "Saliendo              ";
					running = false;
				}
				case 5: {
					system("cls");
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
