#ifndef JUGADOR_H
#define JUGADOR_H

//Incluimos Personaje.h
#include "personaje.h"
//#include "espada.h"

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

#endif