# Adventure-P505
# Jose Alberto Aguilar Sanchez - A01735612

Este proyecto tiene la finalidad de ser un prototipo para un videojuego tipo RPG de aventura basado en texto, planteando las operaciones básicas de un juego de este estilo. Las funciones principales para este programa son:

1. Consultar el estado del personaje: nos permite conocer el estado de nuestro jugador junto con sus stats y propiedades.
2. Descansar: permite al jugador "descansar" para recuperar algo de vida.
3. Viaje: permite emprender el viaje a alguna de las zonas preprogramadas para entablar combate con algún enemigo de esa zona.
4. Cerrar el programa.

Asimismo, podemos editar el nombre del jugador y al entablar combate, sus stats pueden ser modificadas, como vida y resistencia.

# Clases y objetos
El proyecto consta de varias clases compuestas y por herencia, tales como:

### Clase Espada
La clase "Espada" representa un objeto de espada con atributos como el nombre, el daño, la resistencia y la capacidad crítica.

### Clase Personaje
La clase "Personaje" representa un personaje en un juego y proporciona funcionalidades relacionadas con su creación, atributos y acciones. Esta clase está compuesta por "Espada".

### Clase Jugador
La clase "Jugador" es una subclase de la clase "Personaje" y representa al jugador principal en el juego. Esta clase agrega funcionalidades específicas del jugador y tiene la capacidad de interactuar en el juego como el usuario principal.

### Clase Malvado
La clase "Malvado" es una subclase de la clase "Personaje" y representa a un personaje malvado en el juego. Esta clase hereda los atributos y métodos de la clase "Personaje" y agrega funcionalidades específicas para el personaje malvado.

# Main
Dentro de nuestra función principal utilizamos las librerías stdlib y time para generar números aleatorios que utilizaremos en funciones más adelante.

Asimismo, tenemos una función para entablar combate, la cual representa una secuencia de combate entre el jugador y un enemigo en un juego. Toma como argumentos un entero x que indica el rango de números aleatorios para determinar el encuentro con enemigos, un puntero a un objeto Personaje representando al primer enemigo, un puntero a un objeto Personaje representando al segundo enemigo, y un objeto Jugador que representa al usuario. Utiliza ifs anidados para tomar decisiones utilizando las inputs del usuario y números generados aleatoriamente para simular las probabilidades de fallar un ataque.

Para la generación de la interfaz de interacción del programa con el usuario, se utiliza un switch dependiendo de lo que el usuario ingrese en la consola, de acuerdo a las opciones. En caso de que ingrese una opción no válida, no entrará dentro del switch y volverá a pedir una opción.

# Bugs conocidos y consideraciones
Para correr el código en una PC, basta con descargar el archivo "main.exe". Sin embargo, aquí hay una lista de bugs conocidos hasta el momento:

1. Al ingresar la opción "y/n", utilizar únicamente minúsculas.
2. Problema al guardar la nueva salud después de entablar combate.
