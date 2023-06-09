/*
Nombre de clase: Personaje
Uso: Se decalra el objeto personaje por composicion de la clases "espada.h"
    Esta clase es el padre apra las clases jugador y malvado, la clase 
    tiene un construcotr por default y otro por parametros, asi mismo
    posee los getters para operarlos mas tarde
*/


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
        Personaje(string wep, string name, int dam, int crit, int life, int level, int exp){
            vida = life; 
            user = name;
            nivel = level;
            experiencia = exp;
            weapon = Espada(wep, dam, crit);
        }

    // Declaramos la clase como abstracta
    //virtual void xd() = 0;

    // Getters Personaje
    string get_name();
    int get_vida();
    int get_nivel();
    int get_exp();

    //Setters
    virtual void set_level();

    // Llamamos el arma
    Espada get_Espada();

    // Funciones para  clase abstracta
    virtual void curar() = 0;
    virtual void set_xp(int x) = 0;
    virtual void set_name() = 0;

    // Funciones de polimorfismo
    virtual void taken_damage(int x);
     
};


//----------------- GETTERS -----------------//
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

//----------------------------------//

// Setters
void Personaje::set_level(){
    nivel +=1;
}

// Funcion de daño recibido
void Personaje::taken_damage(int x){
    vida -= x;
}

#endif