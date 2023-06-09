#ifndef ZONA_H
#define ZONA_H

//#include "personaje.h"

//------------- CLASE ZONA -------------//
class Zona{
    private:
    // Declaramos Varaibles de la clases 
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

};

//Funciones
int Zona::get_lvl_enemis(){
    return lvl_enemis;
}
int Zona::get_num_enemis(){
    return num_enemis;
}

#endif