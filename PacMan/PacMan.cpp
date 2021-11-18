#include <iostream>
using namespace std;

#define CONSOLE_HEIGHT 20
#define CONSOLE_WIDHT 20

//Enumerador de tipos de carácteres que conforman el mapa
enum MAP_TILES { EMPTY = ' ', WALL = '#', POINT = '.' };

//Array multidimensional que delimitará el mapa en consola
MAP_TILES ConsoleScreen[CONSOLE_HEIGHT][CONSOLE_WIDHT];

int main()
{
    //Primero generamos el mapa y los puntos
    RellenarMapa();
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
