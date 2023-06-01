#include "espada.h"
#include "personaje.h"
#include "jugador.h"

int main(){
    Espada sowrd("Piedra", 1, 1, 1);
    cout << sowrd.get_critico();

    Personaje yo;
    cout << yo.get_exp();

    Jugador gay("piedra", "sexo", 5, 0, 10, 10, 50, 100);
    cout << gay.get_Espada();
}
