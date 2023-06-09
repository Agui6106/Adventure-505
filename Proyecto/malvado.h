/*
Nombre de clase: Malvado
Uso: 
*/

#ifndef MALVADO_H
#define MALVADO_H

#include "personaje.h"

//------------- CLASE MALVADO -------------//
class Malvado: public Personaje{
    public:
    Malvado():Personaje(){}

    Malvado(string wep, 
                string name, 
                int dam, 
                int crit,
                int vida,
                int level,
                int exp) : Personaje(wep, name, dam, crit, vida, level, exp){
                    user = name;
                }
    
    //Funciones de polimorfismo
        void curar();
        void set_xp(int x);
        void set_name();

};

// Funciones
void Malvado::curar(){
    vida += 5;
}

void Malvado::set_xp(int x){
    experiencia += x;
}

void Malvado::set_name(){}

#endif