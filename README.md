# Adventure-P505

# Jose Alberto Aguilar Sanchez - A01735612

Este proyecto tiene la finalidad de ser un prototipo para un videojuego tipo RPG de aventrua basado en texto, plantenado las operaciones basicas de un juego de este estilo. Las funciones principales para este programa son.

1. Consultar el estado del personaje. Nos permite conocer el estado de nuestro jugador junto con sus stast y propiedades
2. Descansar. Permite al jugador "descansar" para recuperar algo de vida
3. Viaje. Permite emrpender el viaje a alguan de las zonas pre programadas para entamblar combate con algun enemigo de esa zona.
4. Cerrar el programa.

Asi mismo podemos editar el nombre del jugador y al entamblar combate sus stats pueden ser modificadas como vida y resistencia.

# Clases y objetos
El proyecto consta de varias clases compuestas y por herencia, tales que.

### Clase Espada
La clase "Espada" representa un objeto de espada con atributos como el nombre, el daño, la resistencia y la capacidad crítica.

### Clase Personaje
La clase "Personaje" representa un personaje en un juego y proporciona funcionalidades relacionadas con su creación, atributos y acciones. Esta clase esta compuesta por "Espada".

### Clase Jugador
La clase "Jugador" es una subclase de la clase "Personaje" y representa al jugador principal en el juego. Esta clase agrega funcionalidades específicas del jugador y tiene la capacidad de interactuar en el juego como el usuario principal.

### Clase Malvado
La clase "Malvado" es una subclase de la clase "Personaje" y representa a un personaje malvado en el juego. Esta clase hereda los atributos y métodos de la clase "Personaje" y agrega funcionalidades específicas para el personaje malvado.

# Main
Dentro de nuestra funcion pricnipal (main) utilziamso las librerias stdlib y time para generar numeros aleatorios que utilizaremos en funciones mas adelante.

Asi mismo tenemos una funcion para entamblar combate, esta funcion representa una secuencia de combate entre el jugador y un enemigo en un juego. Toma como argumentos un entero x que indica el rango de números aleatorios para determinar el encuentro con enemigos, un puntero a un objeto Personaje representando al primer enemigo, un puntero a un objeto Personaje representando al segundo enemigo, y un objeto Jugador que representa al usuario. Utilzia ifs anidados para tomar decisiones utilizando las inputs del usuario y numeros generados aleatoriamente para simular las probaabildiades de fallar un ataque.

Para la generacion de la intefaz de interaccion del programa con el suario se utilzian un switch dependiendo de lo que el usuario ingrese a la consola de acuerdo a las opciones, en caso de que ingresa una opcion no valida no entrara denbtro del switch y vovler a pedir una opcion.

# Bugs conocidos y consideraciones
Para correr el codigo en un PC, basta con descargar el archivo "main.exe", sin embargo aqui hay una lsita de bugs conocidos hasta el momento

1. Al ingresa la opcion "y/n" utilizar unicamnte minusculas.
2. Problema al guardar la nueva salud despues de entamblar combate.

