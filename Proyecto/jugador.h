/*
Nombre de clase: Jugador
Uso: Se decalra el objeto jugador por herencia de personaje,
    esta clase tiene el objetivo de ser el principal objete que interactue en el 
    juego siendo este el usuario.

    Tiene un construcotr por default y otro por parametros, asi mismo
    posee los getters para operarlos mas tarde, sin embargo se agregan las
    funciones correspondiente a ingresar nombre, curar, subir de nivel y
    ganar xp
*/


// Declaramso el arcihvo como libreria
#ifndef JUGADOR_H
#define JUGADOR_H

// Incluimso la clase personaje
#include "personaje.h"

//------------- CLASE JUGADOR -------------//
class Jugador: public Personaje{
    public: 
        //Constructor por default
        Jugador():Personaje(){}

        //Constructor por parametros
        Jugador(string wep, 
                string name, 
                int dam, 
                int crit,
                int vida,
                int level,
                int exp) : Personaje(wep, name, dam, crit, vida, level, exp){}
        

        //FUncion apra establecer el nombre del juador
        void set_name();

        //Funciones de polimorfismo
        void curar();
        void set_xp(int x);
        
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
void Jugador::set_xp(int x){
    experiencia += x;
    cout << "Has ganado: " << x << " de experiencia!!!" << endl;
}

#endif