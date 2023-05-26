// Incluimso paquetes
#include <iostream>

using namespace std;

// Clase Espada 
class Espada{
    protected:
        string nombre;
        int damage, resistance, critico;
    
    public:
        //Constructor por default
        Espada(){
            nombre = "Madera";
            damage = 5;
            resistance = 5;
            critico = 2;
        }

        Espada(string name, int dam, int resist, int crit){
            nombre = name;
            damage = dam;
            resistance = resist;
            critico = crit;
        }
    //Getters
    string get_nombre_arma();
    int get_resistencia();
    int get_critico();
    //Getter para el daño 
    int get_damage();
    
    
};

// Getters
string Espada::get_nombre_arma(){
    return nombre;
}

int Espada::get_resistencia(){
    return resistance;
}

int Espada::get_critico(){
    return critico;
}

//Get Attack
int Espada::get_damage(){
    return damage;
}

//------------- CLASE ESPADA -------------//

// Clase derivada persoanje
class Personaje : public Espada{
    private:
        string user, weapon;
        int vida, nivel, experiencia;
    
    public:
    //Creamnos un constructro x default
        Personaje():Espada(){
            user = "Hero";
            vida = 100;
            nivel = 1;
            experiencia = 0;
        }
    //Creamos 
        Personaje(string wep, string name, int dam, int resist, int crit, int vida, int level, int exp):Espada(wep, dam, resist, crit){
            vida = vida; 
            user = name;
            nivel = level;
            experiencia = exp;

        }
    // Getters
    string get_name();
    int get_vida();
    int get_nivel();
    int get_exp();

    // Settetrs
    void set_name();

    // FUnciones
    void curar();
};

//Getters 
string Personaje::get_name(){
    return user;
}

int Personaje::get_vida(){
    return vida;
}

// Niveles y exp
int Personaje::get_exp(){
    return experiencia;
}
int Personaje::get_nivel(){
    return nivel;
}

//Funciones
void Personaje::curar(){
    vida += 10;
}

void Personaje::set_name(){
    cout << "Estamos felices de conocnerte. Pero primero... Cual es tu nombre?: " << endl;
    cin >> user;
}



//------------- M A I N -------------//
int main (){
    //Variables
    int option = 0;
    //int n = 0;
    string user_name;

    //Declaracion de Objetos
    Personaje user;
    
    // Declaramos Objetos
    Personaje malo1("Piedra", "Goblin", 5, 5, 2, 10, 1, 15);

    cout << "#----Bienvenido a este mundo de fantasia----#" << endl;
    //Establecemos nombre del usuario
    user.set_name();
    cout << "Hola " << user.get_name() << " En el siguiente menu elije por donde comenzar tu aventura: " << endl;
    
    while(option != 10){
        cout << endl << "Opcion: ";
        cin >> option;

        switch (option) {

        case 1: //Estado del personaje
            cout << "Nombre: " << user.get_name() << endl;
            cout << "Nivel: " << user.get_nivel() << endl;
            cout << "Experiencia: " << user.get_exp() << endl;
            cout << "Arma: " << user.get_nombre_arma() << endl;
            cout << "Damage: " << user.get_damage() << endl ;
            cout << "Critico: " << user.get_critico() << endl;
            cout << "Resistencia de arma: " << user.get_resistencia() << endl;
            cout << "Vida: " << user.get_vida() << endl;
            break;
        
        case 2:
            cout << "Bienvenido a Zona 1" << endl;


            break;
        
        default:
        cout << "Ingresa una opcion Valida" << endl;
            break;
        }

    }

    
    


}
