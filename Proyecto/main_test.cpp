#include "espada.h"
#include "personaje.h"
#include "jugador.h"
#include "malvado.h"

int main(){
    //Test calse espada
    Espada sowrd("Piedra", 1, 1, 1);
    cout << sowrd.get_critico() << endl;

    //Test clase Perosnaje
    Personaje yo;
    cout << yo.get_exp() << endl;

    //Test clase jugador
    Jugador gay("piedra", "sexo", 5, 0, 10, 10, 50, 100);
    cout << gay.get_Espada().get_nombre_arma() << endl;

    //Test clase malvado
    Personaje *malo = new Malvado();

    cout << "Vida antes de curar: " << malo -> get_vida() << endl;
    malo -> curar();
    cout << "Vida despeus de curar: " << malo -> get_vida() << endl;

}

