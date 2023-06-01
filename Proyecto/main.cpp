// Incluimos clases
#include "espada.h"
#include "personaje.h"



// Incluimso paquetes
#include <iostream>
//Paquetes apra egnerar numeros random
#include<stdlib.h>
#include<time.h>

using namespace std;


//------------- CLASE ZONA -------------//
class Zona{
    private:
        string name_zone;
        int num_enemis, lvl_enemis;
    public:
        //Constructor por parametros de zona
        Zona(string name, int num, int lvl){
            name_zone = name;
            num_enemis = num;
            lvl_enemis = lvl;
        };

    //Getters
    int get_num_enemis();
    int get_lvl_enemis();

    //Funciones
    void regresemos();

};

//Funciones
int Zona::get_lvl_enemis(){
    return lvl_enemis;
}
int Zona::get_num_enemis(){
    return num_enemis;
}
//FUncion
void Zona::regresemos(){
    cout << "Bien regresemso a casa..." << endl;
}


//------------- CLASE JUGADOR -------------//
class Jugador: public Personaje{
    public: 
        //Constructor por default
        Jugador():Personaje(){}

        //Constructor por parametros
        Jugador(string wep, 
                string name, 
                int dam, 
                int resist,
                int crit,
                int vida,
                int level,
                int exp) : Personaje(wep, name, dam, resist, crit, vida, level, exp){}
        

        //FUncion apra establecer el nombre del juador
        void set_name();

        //Funciones de polimorfismo
        void curar();
        void set_level();
        void new_exp();
};

// FUNCIONES
//Establecemso el nombre
void Jugador::set_name(){
    cout << "Estamos felices de conocnerte. Pero primero... Cual es tu nombre?: " << endl;
    cin >> user;
}

//Nos curamos en descanso
void Jugador::curar(){
    vida += 10;
}

//Subimos de nivel
void Jugador::set_level(){
    if (experiencia >= 50){
        nivel++;
    }
    cout << "Has subido de nivel" << endl;
}

//Ganamos xp
void Jugador::new_exp(){
    experiencia -= 50;
}

//------------- CLASE MALVADO -------------//
class Malvado: public Personaje{
    public:
    Malvado():Personaje(){}

    Malvado(string wep, 
                string name, 
                int dam, 
                int resist,
                int crit,
                int vida,
                int level,
                int exp) : Personaje(wep, name, dam, resist, crit, vida, level, exp){
                    user = name;
                }
    
    //Funciones de polimorfismo
        void curar();

};

// Funciones
void Malvado::curar(){
    vida += 5;
}




//------------- M A I N -------------//
int main (){
    //Variables
    int option = 0;
    // Inicialiazamos un numeor random
    srand(time(NULL));
    //Declaracion de Objetos
    Jugador user;

    //------------- Personaje creado por usuario -------------//
    cout << "#----Bienvenido a este mundo de fantasia----#" << endl;
    //Establecemos nombre del usuario
    user.set_name();

    //------------- Introduccion -------------//
    cout << "Hola " << user.get_name() << " A partir de ahora tu aventura comienza, para avanzar necesitaras subir de niveles: " << endl;
    cout << "Ahora eres libre de escoger entre estas opciones. Disfrutalo :D" << endl;

    //------------- M E N U-------------//
    cout << "Opcion 1. Ver estado del personaje: " << endl;

    // Eleccion por input de usuario. Usamos un while para que se repita la seleccion menu
    while(option != 10){
        // Creamso variable opcion para el loop
        cout << endl << "Opcion: ";
        cin >> option;

        // Creamos variables de eleccion
        //ELeccion descansar
        string descansar;
        // Eleccion de zona
        int zone;

        switch (option) {

        case 1: //Estado del personaje
            cout << "Nombre: " << user.get_name() << endl;
            cout << "Nivel: " << user.get_nivel() << endl;
            cout << "Experiencia: " << user.get_exp() << endl;
            cout << "Arma: " << user.get_Espada().get_nombre_arma() << endl;
            cout << "Damage: " << user.get_Espada().get_damage() << endl ;
            cout << "Critico: " << user.get_Espada().get_critico() << endl;
            cout << "Resistencia de arma: " << user.get_Espada().get_resistencia() << endl;
            cout << "Vida: " << user.get_vida() << endl;
            break;
        
        case 2: // Descansar (Aumenta la vida en 10%)
            cout << "Quieres Descansar?. Y/N" << endl; cin >> descansar;
            // Elegir Si a descnsar 
            if (descansar == "y"){
                //Condicion si la vida ya esta al maximo
                if (user.get_vida() == 100){
                    cout << "No puedes descansar, tu vida esta al maximo" << endl;
                } else { //Sino curar
                    user.curar();
                }

            } else if (descansar == "n"){
                cout << "Ok" << endl;
            }
            break;
        
        case 3: //Viajar a una zona

            cout << "A donde te gustaria viajar?" << endl;
            cout << "1) Zona Oscura" << endl; cout << "2) Bosque" << endl;
            cin >> zone;

            if (zone == 1){
                // Viajamos y creamos la Zona Oscura
                cout << "Viajando a zona oscura..." << endl;
                Zona Zona_oscura("Zona Oscura", 10, 10);
                // Mostramos informacion de la zona
                cout << "Nivel de enemigos: "  << Zona_oscura.get_lvl_enemis() << endl;
                cout << "Numero de enemigos: " << Zona_oscura.get_num_enemis() << endl;
                Malvado *mal = new Malvado[Zona_oscura.get_num_enemis()];
                
                cout << mal->get_nivel() << endl;

            } else if (zone == 2){
                // VIahamos y creamos el bosque
                cout << "Viajando a Bosque..." << endl;
                Zona bosque("Bosque", 10, 5);
                // Mostramos informacion de la zona
                cout << "Nivel de enemigos: "  << bosque.get_lvl_enemis() << endl;
                cout << "Numero de enemigos: " << bosque.get_num_enemis() << endl;
            }
            break;


        default:
        cout << "Ingresa una opcion Valida" << endl;
            break;
        }

    }

}
