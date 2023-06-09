// Incluimos clases
#include "espada.h"
#include "personaje.h"
#include "jugador.h"
#include "malvado.h"
#include "zona.h"

// Incluimso paquetes
#include <iostream>
//Paquetes apra generar numeros random
#include<stdlib.h>
#include<time.h>

using namespace std;

//------------- FUNCION DE COMBATE -------------//
void combat(int x, Personaje *a, Personaje *b, Personaje *c){
    // Declaramos un numero random para encuentro con enemigos
    int num; num = rand()%x; 

    // Numero random que nos dira si falla o no
    int prob; prob = rand()%2;

    // Variable que nos dice que tanto daño recibe cada objeto
    int dam, enem_xp;

    //Creamos una variables para elegir
    int input;

    // Damos una intro
    cout << "Hace frio y casi no ves nada... Hasta que de pronto..." << endl;

    //------------- Malo 1 -------------//
    if (num == 1){
        // Interfaz de menu de interaaccion
        cout << "Te has encontrxado con un " << a ->get_name() << "!!!!" << endl;
        cout << "Que deseas hacer?" << endl << "Elige la opcion que desees" << endl;
        cout << "1. Atacar" << endl;
        cout << "2. Huir" << endl;
        cin >> input;

        //Eleecion del usuario para atacar
        if (input == 1){

            while(a ->get_vida() >= 0){
                // Usuario ataca y resta vida al enemgio
                dam = a ->get_Espada().get_damage();
                enem_xp = a->get_exp();
                cout << "Atacas con "<< c->get_Espada().get_nombre_arma() << endl;
                a -> taken_damage(c->get_Espada().get_damage());
                cout << "La vida del " << a->get_name() <<" es de: " << a->get_vida() << endl;

                // Si un numero aleatorio es igual 1, enemigo ataca
                if (prob == 1){
                    c->taken_damage(dam);
                    cout << a->get_name() << " Ataca con: " << a->get_Espada().get_nombre_arma() << endl;
                    cout << "Recibes " << a ->get_Espada().get_damage() << " De damage" << endl;
                    cout << "Tu vida ahora es: " << c->get_vida() << endl;

                    //Por cada golpe se gana la experiencia del oponente
                    c->set_xp(enem_xp);

                    // Subimos de nivel cada 50 xp points
                    if (c->get_exp() == 50){
                        c->set_level();
                    }
            
                // Si un numero aleotrio es igual a 2, falla
                } else if (prob == 2){
                    cout << a ->get_name() << " Falla su ataque" << endl;
                }

            } // WHile end
            
            
        // Eleccion de usuario apra huir 
        } else if (input == 2){
            cout << "Huyes" << endl;
        }

    //------------- Malo 2 -------------//

    } else if (num == 2) {
        // Interfaz de menu de interaaccion
        cout << "Te has encontrado con un " << b ->get_name() << endl;
        cout << "Que deseas hacer?" << endl << "Elige la opcion que desees" << endl;
        cout << "1. Atacar" << endl;
        cout << "2. Huir" << endl;
        cin >> input;

        //Eleecion del usuario para atacar
        if (input == 1){
            while(b ->get_vida() >= 0){
                // Usuario ataca y resta vida al enemgio
                dam = b ->get_Espada().get_damage();
                enem_xp = b->get_exp();
                cout << "Atacas con "<< c->get_Espada().get_nombre_arma() << endl;
                b -> taken_damage(c->get_Espada().get_damage());
                cout << "La vida del " << b->get_name() <<" es de: " << a->get_vida() << endl;

                // Si un numero aleatorio es igual 1, enemigo ataca
                if (prob == 1){
                    c->taken_damage(dam);
                    cout << b->get_name() << " Ataca con: " << b->get_Espada().get_nombre_arma() << endl;
                    cout << "Recibes " << b->get_Espada().get_damage() << " De damage" << endl;
                    cout << "Tu vida ahora es: " << c->get_vida() << endl;

                    

                    //Por cada golpe se gana la experiencia del oponente
                    c->set_xp(enem_xp);

                    // Subimos de nivel cada 50 xp points
                    if (c->get_exp() == 50){
                        c->set_level();
                    }
            
                // Si un numero aleotrio es igual a 2, falla
                } else if (prob == 2){
                    cout << b ->get_name() << " Falla su ataque" << endl;
                }
            }

        // Huir
        } else if (input == 2){
            cout << "Huyes" << endl;
        }

    //No encuentras nada
    } else {
        cout << "No encuentras nada y sigues tu camino..." << endl;
    } 

}

//------------- M A I N -------------//
int main (){
    //Variables
    int option = 0;
    
    // Funcion creacacion de numeros random
    srand(time(NULL));
    
    //Declaracion de Objetos
    Personaje *user = new Jugador();

    //------------- Personaje creado por usuario -------------//
    cout << "#----Bienvenido a este mundo de fantasia----#" << endl;
    //Establecemos nombre del usuario
    ((Jugador*)user)->set_name();

    //------------- Introduccion -------------//
    cout << "Hola " << user->get_name() << " A partir de ahora tu aventura comienza, para avanzar necesitaras subir de niveles: " << endl;
    cout << "Ahora eres libre de escoger entre estas opciones. Disfrutalo :D" << endl;
    cout << "Ingresa en la consola el numero de la opcion que desees " << endl;
    cout << " " << endl;

    //------------- M E N U-------------//
    cout << "Opcion 1. Ver estado del personaje: " << endl;
    cout << "Opcion 2. Descansar " << endl;
    cout << "Opcion 3. Viajar a una zona: " << endl;

    // Eleccion por input de usuario. Usamos un while para que se repita la seleccion menu
    while(option != 10){
        // Creamso variable opcion para el loop
        cout << endl << "Opcion: ";
        cin >> option;

        //------------- Creamos variables de eleccion -------------//
        //ELeccion descansar
        string descansar;
        // Eleccion de zona
        int zone;
        string vamos;

        //------------- M E N U -------------//
        switch (option) {

        case 1: //Estado del personaje
            cout << "Nombre: " << user->get_name() << endl;
            cout << "Nivel: " << user->get_nivel() << endl;
            cout << "Experiencia: " << user->get_exp() << endl;
            cout << "Arma: " << user->get_Espada().get_nombre_arma() << endl;
            cout << "Damage: " << user->get_Espada().get_damage() << endl ;
            cout << "Critico: " << user->get_Espada().get_critico() << endl;
            cout << "Vida: " << user->get_vida() << endl;
            break;
        
        case 2: // Descansar (Aumenta la vida del personaje)
            cout << "Quieres Descansar?. Y/N" << endl; cin >> descansar;
            // Elegir Si a descnsar 
            if (descansar == "y"){
                //Condicion si la vida ya esta al maximo
                if (user->get_vida() == 100){
                    cout << "No puedes descansar, tu vida esta al maximo" << endl;
                } else { //Sino curar
                    user->curar();
                }

            } else if (descansar == "n"){
                cout << "Ok" << endl;
            }
            break;
        
        case 3: //Viajar a una zona
            cout << "A donde te gustaria viajar?" << endl;
            cout << "1) Zona Oscura" << endl; cout << "2) Bosque" << endl;
            cin >> zone;

            // Eleccion Zona oscura
            if (zone == 1){
                // Viajamos y creamos la Zona Oscura
                cout << "Viajando a zona oscura..." << endl;
                Zona Zona_oscura("Zona Oscura", 2, 5);
                // Mostramos informacion de la zona
                cout << "Nivel de enemigos: "  << Zona_oscura.get_lvl_enemis() << endl;
                cout << "Numero de enemigos: " << Zona_oscura.get_num_enemis() << endl;
                
                // Creamos objetos correspondientes
                Personaje *malo_1 = new Malvado("Espada de madre", "Goblin", 5, 3, 50, Zona_oscura.get_lvl_enemis(), 1);
                Personaje *malo_2 = new Malvado("Espada de pieda", "Esqueleto", 6, 3, 45, Zona_oscura.get_lvl_enemis(), 1);

                // Preguntamso si queremso seguir adelante
                cout << "Deseas continuar?.  y/n" << endl; cin >> vamos;

                // Tomamos la Decision
                if (vamos == "y"){ //Elegir si
                    cout << "Te adentras a lo profundo de la zona obscura... " << endl;
                    combat(Zona_oscura.get_num_enemis(), malo_1, malo_2, ((Jugador*)user));

                } else if (vamos == "n"){ //Elegir no
                    cout << "Ok... Regresemos..." << endl;
                }
                
            // Eleccion Bosque
            } else if (zone == 2){
                // VIahamos y creamos el bosque
                cout << "Viajando a Bosque..." << endl;
                Zona bosque("Bosque", 2, 10);
                // Mostramos informacion de la zona
                cout << "Nivel de enemigos: "  << bosque.get_lvl_enemis() << endl;
                cout << "Numero de enemigos: " << bosque.get_num_enemis() << endl;

                //Creamos objetos correspondientes
                Personaje *malo_1B = new Malvado("Espada de madera", "Tilin", 1, 2, 10, bosque.get_lvl_enemis(), 1);
                Personaje *malo_2B = new Malvado("Espada de piedra", "Tilin Insano", 5, 2, 10, bosque.get_lvl_enemis(), 1);

                // Preguntamso si queremso seguir adelante
                cout << "Deseas continuar?.  y/n" << endl; cin >> vamos;

                // Tomamos la decision
                if (vamos == "y"){ //Elegir si
                    cout << "Te adentras a lo profundo de la zona obscura... " << endl;
                    combat(bosque.get_num_enemis(), malo_1B, malo_2B, ((Jugador*)user));

                } else if (vamos == "n"){ //Elegir no
                    cout << "Ok... Regresemos..." << endl;
                }
            }
            break;


        // Switch Default
        default:
        cout << "Ingresa una opcion Valida" << endl;
            break;
        }

    }

}

