#include <iostream>
using namespace std;


void RellenarMapa();
void ImprimirPantalla();
void Inputs();
void Logica();



#define CONSOLE_HEIGHT 20
#define CONSOLE_WIDHT 20

//Enumerador de tipos de carácteres que conforman el mapa
enum MAP_TILES { EMPTY = ' ', WALL = '#', POINT = '.' };

//Enumerador con los tipos de inputs que puede hacer el usuario
enum USER_INPUTS { NONE, UP, DOWN, RIGHT, LEFT, QUIT };

//Array multidimensional que delimitará el mapa en consola
MAP_TILES ConsoleScreen[CONSOLE_HEIGHT][CONSOLE_WIDHT];

//Posición inicial del jugador en la consola
int personaje_x = CONSOLE_WIDHT / 2;
int personaje_y = CONSOLE_HEIGHT / 2;
//Carácter que representa al jugador
char personaje = 'O';
//Booleano de ejecución
bool run = true;
//Inicialización de la variable inputs
USER_INPUTS input = USER_INPUTS::NONE;

//Puntos activos en el mapa
int map_points = 0;
//Puntos recogidos por el personaje
int puntos_personaje = 0;


int main()
{
    //Primero generamos el mapa y los puntos
    RellenarMapa();
    ImprimirPantalla();
    while (run) {
        Inputs();
        Logica();
        ImprimirPantalla();
    }
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

/*Para detectar los inputs del usuario, los obtenemos mediante un "cin" y los ponemos en diferentes casos.
Mediante el enumerador creado anteriormente, decidiremos hacia donde se mueve en función de la tecla pulsada.*/
void Inputs() { //Input del jugador
    char input_raw;
    cin >> input_raw;
    switch (input_raw) {
    case 'W':
    case 'w':
        input = USER_INPUTS::UP;
        break;
    case 'A':
    case 'a':
        input = USER_INPUTS::LEFT;
        break;
    case 'S':
    case 's':
        input = USER_INPUTS::DOWN;
        break;
    case 'D':
    case 'd':
        input = USER_INPUTS::RIGHT;
        break;
    case 'Q':
    case 'q':
        input = USER_INPUTS::QUIT;
        break;
    default:
        input = USER_INPUTS::NONE;
    }
}

/*En este método vamos a mover a nuestro jugador segun la dirección escogida por el usuario.*/
void Logica() { //Logica del movimiento del jugador
    int personaje_y_new = personaje_y;
    int personaje_x_new = personaje_x;
    switch (input)
    {
    case UP:
        personaje_y_new--;
        break;
    case DOWN:
        personaje_y_new++;
        break;
    case RIGHT:
        personaje_x_new++;
        break;
    case LEFT:
        personaje_x_new--;
        break;
    case QUIT:
        run = false;
        break;
    }

    if (personaje_x_new < 0) {              //Si nos salimos por la izquierda
        personaje_x_new = CONSOLE_WIDHT - 1;//Aparecemos a la derecha
    }
    personaje_x_new %= CONSOLE_WIDHT;       //Con el modulo podemos reestablecer la posicion facilmente
                                            //ya que si nuestro limite fuera 9 y yo me voy a 10 entonces: 10 % 10 = 0

    if (personaje_y_new < 0) {                 //Lo mismo para y
        personaje_y_new = CONSOLE_HEIGHT - 1;
    }
    personaje_y_new %= CONSOLE_HEIGHT;

    if (ConsoleScreen[personaje_y_new][personaje_x_new] == MAP_TILES::WALL) { //Las paredes no las podemos passar
        personaje_y_new = personaje_y;
        personaje_x_new = personaje_x;
    }
    else if (ConsoleScreen[personaje_y_new][personaje_x_new] == MAP_TILES::POINT) { //Si hay un punto me lo como
        ConsoleScreen[personaje_y_new][personaje_x_new] = MAP_TILES::EMPTY;
        map_points--;
        puntos_personaje++;
    }
    //Nueva posición
    personaje_y = personaje_y_new;
    personaje_x = personaje_x_new;
}
