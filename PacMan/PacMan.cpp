#include <iostream>
using namespace std;


void RellenarMapa();
void ImprimirPantalla();



#define CONSOLE_HEIGHT 20
#define CONSOLE_WIDHT 20

//Enumerador de tipos de carácteres que conforman el mapa
enum MAP_TILES { EMPTY = ' ', WALL = '#', POINT = '.' };

//Array multidimensional que delimitará el mapa en consola
MAP_TILES ConsoleScreen[CONSOLE_HEIGHT][CONSOLE_WIDHT];

//Posición inicial del jugador en la consola
int personaje_x = CONSOLE_WIDHT / 2;
int personaje_y = CONSOLE_HEIGHT / 2;
//Carácter que representa al jugador
char personaje = 'O';

int main()
{
    //Primero generamos el mapa y los puntos
    RellenarMapa();
    ImprimirPantalla();
}

/*Para rellenar el mapa utilizaremos un dobre bucle "for" que nos recorra toda la consola. En este bucle
comprovaremos si estamos en una posición x = 0, y = 0, x = ancho - 1 o y = alto - 1. En caso de estar en
una de estas 4 posiciones colocaremos un # (o pared), sino lo dejaremos vacío.*/
void RellenarMapa() {
    for (int i = 0; i < CONSOLE_HEIGHT; i++) {
        for (int j = 0; j < CONSOLE_WIDHT; j++) {
            if (i == 0 || i == CONSOLE_HEIGHT - 1 || j == 0 || j == CONSOLE_WIDHT - 1) {
                ConsoleScreen[i][j] = MAP_TILES::WALL;
            }
            else {
                ConsoleScreen[i][j] = MAP_TILES::EMPTY;
            }
        }
    }
}

/*Una vez rellenada la array del mapa, la imprimiremos recorriendola posción a posición con la modificación
de que tambien se imprimirá al personaje en la posición de la array del mapa perteneciente.*/
void ImprimirPantalla() {
    system("CLS");
    for (int i = 0; i < CONSOLE_HEIGHT; i++) {
        for (int j = 0; j < CONSOLE_WIDHT; j++) {
            if (personaje_x == j && personaje_y == i) {
                cout << personaje;
            }
            else {
                cout << (char)ConsoleScreen[i][j];
            }
        }
        cout << endl;
    }
}
