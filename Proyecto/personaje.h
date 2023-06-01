//Definimos como libreria el archivo H
#ifndef PERSONAJE_H
#define PERSONAJE_H

//Incluimos Espada.h
#include "espada.h"

//------------- CLASE PERSONAJE -------------//
class Personaje{
    //Variables agregadas a la clase
    protected:
        string user;
        int vida, nivel, experiencia;
        //Composicion
        Espada weapon;
        
    public:
    //Creamnos un constructro x default (nos sera util para el personaje del usuario)
        Personaje(){
            weapon = Espada();
            user = "";
            vida = 100;
            nivel = 1;
            experiencia = 0;
        }
    //Creamos un constructor por valores
        Personaje(string wep, string name, int dam, int resist, int crit, int vida, int level, int exp){
            vida = vida; 
            user = name;
            nivel = level;
            experiencia = exp;
            weapon = Espada(wep, dam, resist, crit);
        }

    // Getters Personaje
    string get_name();
    int get_vida();
    int get_nivel();
    int get_exp();

    // Llamamos el arma
    Espada get_Espada();

    // Funciones
    virtual void curar();
    virtual void set_level();
     
};

//Getters estado
string Personaje::get_name(){
    return user;
}
int Personaje::get_vida(){
    return vida;
}

// Getter Arma
Espada Personaje::get_Espada(){
    return weapon;
}

// Gettrs Niveles y exp
int Personaje::get_exp(){
    return experiencia;
}
int Personaje::get_nivel(){
    return nivel;
}

//Funciones para polimorifsmo
void Personaje::set_level(){
    experiencia ++;
}

void Personaje::curar(){
    vida += 1;
}

#endif