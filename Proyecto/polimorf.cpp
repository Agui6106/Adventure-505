#include <iostream>
using namespace std;


class Estudiante{  //Base
    public:
        void come(){cout<< "Alimentos Baratos \n";}  //se llama en tiempo de compilacion
        // En memoria estatica no me la guardes, hasta que se corra
        virtual  void toma(){cout<< "Bebidas Baratas \n";} //se llama en tiempo de ejecucion
};

class Programador : public Estudiante{
    public:
        //Sobreescritura
        void come(){cout << "Pizza \n";}
        void toma(){cout << "cafe \n";}
};

/** Al usar apuntadores al obejto padre (Estudiante),
se define come() en tiempo de compilacion(Memoria Estatica) por lo que se manda a
llamar a la funcion de come de Estudiante.

Pero toma() es virtual lo que hace que se mande en tiempo de ejecucion (Memoria Dinamica)
como "new" es memoria dinamica que crea el objeto en tiempo de ejecucion
entonces es hasta que programador ya esta creado que se manda a llama toma()
**/

int main(){
   //Mem.Estatica   o  //Mem. Dinamica
   //Tiempo de comp    //tiempo de ejecucion

   //Llamo a un objeto programador y lo guardo en eun apuntador 
    Estudiante *est =  new Programador();

    est->come();   //imprime Alimentos Baratos  (sin virtual)
    est->toma();   //imprime Cafe               (con virtual)

}