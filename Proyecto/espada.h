/*
Nombre de clase: Espada
Uso: Se decalra el objeto espada con atributos por default tal que:
    nombre = "Madera";
    damage = 5;
    resistance = 5;
    critico = 2;

    Asi mismo se puede crear un objeto por parametros ingresados.
    Esta clase regresa los parametros del objeto
*/

// Define el archivo como uan libreria
#ifndef ESPADA_H
#define ESPADA_H

// Incluimso paquetes
#include <iostream>

//Paquetes apra egnerar numeros random
#include<stdlib.h>
#include<time.h>

using namespace std;

//------------- CLASE ESPADA -------------//
class Espada{
    //Variables de clase
    protected:
        string nombre;
        int damage, resistance, critico;
    
    public:
        //Constructor por default
        Espada(){
            nombre = "Madera";
            damage = 5;
            critico = 2;
        }
        //Constructor por aprametros
        Espada(string name, int dam, int crit){
            nombre = name;
            damage = dam;
            critico = crit;
        }

        // Getters Espada
        //Getters
        string get_nombre_arma();
        int get_critico();
        //Getter para el daño 
        int get_damage();
};

// Gettes Espada
string Espada::get_nombre_arma(){
    return nombre;
}

int Espada::get_critico(){
    return critico;
}

//Get Attack
int Espada::get_damage(){
    return damage;
}

#endif