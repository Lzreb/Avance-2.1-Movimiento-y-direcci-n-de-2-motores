![header](https://64.media.tumblr.com/8491a07418ae9607282abd3ba759480e/56878bd0aea7b65b-ed/s2048x3072/4e9012fcecc7501349400dd7d2c4185f068b3a96.pnj)

# Movimiento y dirección de 2 motores


![divider](https://64.media.tumblr.com/8a4c4aa7d59a9902cf7af99d25c30741/6358e14772faff9b-da/s2048x3072/5a757bd89f4480d7f4f293be5c31ec807e411db4.pnj)


## Introducción
- En este sistema trabajamos con el controlador L293D y un Arduino para aprender cómo controlar dos motores de corriente directa, y así modificar tanto su velocidad como su sentido de giro.

- A continuación, se explicarán tanto el circuito como la programación de un sistema que sea capaz de moverse y que tenga varias opciones de movimiento. Con esto también buscamos que sirva como referencia para futuros proyectos como robots tipo automóviles, entre otros.

![divider](https://64.media.tumblr.com/8a4c4aa7d59a9902cf7af99d25c30741/6358e14772faff9b-da/s2048x3072/5a757bd89f4480d7f4f293be5c31ec807e411db4.pnj)

## Materiales

- Se necesitan los siguientes materiales para llevar acabo este proyecto:

    - 1 Arduino  

    - 1 Protoboard  

    - 1 L293D (Puente H) 

    - 4 Botones o Pulsadores  

    - 2 DC Motor 

    - 1 Fuente de poder de 24 V 

![divider](https://64.media.tumblr.com/8a4c4aa7d59a9902cf7af99d25c30741/6358e14772faff9b-da/s2048x3072/5a757bd89f4480d7f4f293be5c31ec807e411db4.pnj)
## Circuito y Conexiones

Figura 1.1

Diagrama del circuito y conexiones.


![TinkerCAD](https://media.discordapp.net/attachments/1224728869706403864/1554006021884608552/image.png?ex=6abb5063&is=6ab9fee3&hm=8400a70174e6de4740892658b6bc9a537cf173ba5d43665b4ce01c6605eba68c&=&format=webp&quality=lossless&width=1024&height=636)

- Para comenzar a armar este circuito es necesario comprender el funcionamiento del controlador L293D y el papel de cada uno de sus pines. El controlador L293D nos permite controlar las revoluciones de cada motor teniendo valores analógicos, o sea que se pueda cambiar la velocidad y no solo tener encendido o apagado (como en los pines digitales). En la Figura 2 se pueden apreciar los números de los pines (en la parte gris), la función de cada uno de ellos y los motores (representados como M1 y M2). 

Figura 1.2

Pines del controlador L293D

![Diagrama](https://media.discordapp.net/attachments/1224728869706403864/1554005897112588298/image.png?ex=6abb5045&is=6ab9fec5&hm=ba7af78d22c042e51d87d7dd0c4c392ea983ec22bcd0534d7113bff6a51adac2&=&format=webp&quality=lossless&width=640&height=507)


- Los pines Enable motor 1 y 2 están conectados a la placa Arduino en 5V para proporcionarle energía al controlador. Los pines control motor 1, 2, 3 y 4 están conectados a los pines digitales 10, 9, 5 y 6, respectivamente, del Arduino. Esto debido a que son pines que reciben información (input) de los pines digitales para poder programar y controlar la velocidad de los motores. También están conectados los motores a los pines 3 y 14 (positivos) y 6 y 11(negativos), para alimentarlos ocupamos una fuente de alimentación externa de 24V, esta está conectada a los pines 8 y 16 de nuestro controlador por medio de los valles del protoboard. 

- La manera en la que cambiaremos el movimiento y velocidades de los motores es mediante cuatro botones, conectados a los pines digitales 7, 4, 3 y 2 del Arduino. Estos son circuitos sencillos, cada uno tiene su fuente de alimentación por medio de los pines en uno de sus lados y en la esquina contraria están conectados a ground para cerrar el circuito. 


![divider](https://64.media.tumblr.com/8a4c4aa7d59a9902cf7af99d25c30741/6358e14772faff9b-da/s2048x3072/5a757bd89f4480d7f4f293be5c31ec807e411db4.pnj)
## Código

Figura 2.1

Configuración inicial

![Código](https://media.discordapp.net/attachments/1224728869706403864/1553955384358731796/image.png?ex=6abb213a&is=6ab9cfba&hm=2fa30f94ef56050ccdaaf3c6364911d5e9bc6692f927e7c85f0da5d9f4df5c4e&=&format=webp&quality=lossless&width=673&height=768)

- Primero empezamos definiendo la conexión de los pines correspondientes a cada motor o botón, según sea el caso; después definimos las variables que vamos a necesitar. En este caso tenemos variables para cambiar el sentido de los motores y que pueda ir en reversa, otros para leer el último estado de los botones y, por último, uno para saber si el sistema está activo o no.  
 
- Para el setup de nuestro programa, solamente configuraremos nuestros motores como "output" y los botones como "input_pullup" para aprovechar la resistencia interna. Como pequeño extra, le indicaremos que los motores estén apagados al inicio para que estos se prendan solamente cuando el sistema esté activo. 

Figura 2.2

Estructura pt.1 

![Código2](https://media.discordapp.net/attachments/1224728869706403864/1553955298828492810/image.png?ex=6abb2126&is=6ab9cfa6&hm=9b431a2c9820179e80d9cef19cc6c58dbe41b894e384ad825b036e799b34473c&=&format=webp&quality=lossless&width=640&height=444)

- Estaremos trabajando a base de condicionales para poder mover los motores en el sentido que queramos acorde a los estados de los botones. El primer condicional lo utilizamos para poder prender el sistema con el segundo botón de izquierda a derecha del circuito, si el sistema ya está activo y se presiona nuevamente la dirección de los motores cambia el cuál sería nuestro sistema de reversa. Además, agregamos un pequeño delay para evitar errores de lectura. 

- Después agregamos una nueva variable la cual estará en constante cambio pues registrará el estado anterior del botón (por esta razón no se agrega en el setup) y empezamos con nuestra segunda condicional es para cuando el sistema no este activo el loop se reinicie y apaga los motores completamente.

Figura 2.3

Estructura pt.2

![Código3](https://media.discordapp.net/attachments/1224728869706403864/1553955151985774692/image.png?ex=6abb2103&is=6ab9cf83&hm=7b9da7630fb3277cc6ead50d84e9b0d490f9dc318381af7dd9336968dafd8220&=&format=webp&quality=lossless&width=640&height=446)

- Ahora pasemos a la configuración para girar cuando este va hacia adelante. Similar a la variable del estado del botón, agregamos 2 variables para definir tanto a qué velocidad avanza el motor izquierdo como el derecho, lo que nos permitirá girar si esto fuera la programación de un carrito. (!marchatras); el "!" es equivalente a lo que se conoce comúnmente en programación como "si no"; en este caso sería "si no marchatras, entonces:", lo cual nos dice que si la función de marchatras no está activa, va a realizar la acción que nosotros le indiquemos.   

- Ahora, dentro de esta condicional, tenemos otra anidada (o sea, condicional dentro de condicional), la cual depende del estado de los botones. Si ambos no están presionados, entonces ambos motores avanzan a una velocidad constante, pero si alguno de los botones se presiona, entonces el motor correspondiente disminuirá su velocidad "girando" en ese sentido.

Figura 2.4

Estructura pt.3

![Código4](https://media.discordapp.net/attachments/1224728869706403864/1553964657922801745/image.png?ex=6abb29dd&is=6ab9d85d&hm=48bb8296e157f3c8453e379d40440c543d489c8f6f65927a3b3459c7cff9b924&=&format=webp&quality=lossless&width=640&height=546)

- Lo mismo ocurriría para el estado invertido; sin embargo, la mayor diferencia que podemos observar es a qué "motor" nos estamos refiriendo, o sea, mientras este iba hacia adelante, la velocidad estaba configurada en motor Izq y Der 1, mientras que en reversa ocurre en el motor Izq y Der 2. Esto es equivalente a si la velocidad en los primeros fuera negativa, pero aquí los configuramos como otra "variable" para evitar posibles errores y que exista un mayor entendimiento de a qué sentido hacemos referencia.  

- Para terminar, solamente agregamos la condicional del estado del botón para apagar el sistema y reiniciar el loop. 

![divider](https://64.media.tumblr.com/8a4c4aa7d59a9902cf7af99d25c30741/6358e14772faff9b-da/s2048x3072/5a757bd89f4480d7f4f293be5c31ec807e411db4.pnj)
## Demo

- El siguiente link te redirige a un video demostrativo del circuito.

- [Demo](https://drive.google.com/file/d/1GJtDJ23x9fAGzh6zP1MqRTQtyXkZMuVV/view?usp=sharing )

![divider](https://64.media.tumblr.com/8a4c4aa7d59a9902cf7af99d25c30741/6358e14772faff9b-da/s2048x3072/5a757bd89f4480d7f4f293be5c31ec807e411db4.pnj)
## Conclusión

- Gracias a esto podemos concluir que se puede ajustar el movimiento de los motores mediante controladores como el L293D, pues nos permite configurar dos motores de manera individual, modificando su velocidad y sentido de giro a partir de las señales enviadas desde Arduino. Esto agregado a la combinación de conocimientos previos de electrónica y programación.  

- Algo importante a destacar es que, para que un mecanismo pueda desplazarse correctamente, no basta con hacer que ambos motores giren, sino que es necesario controlar la velocidad de cada uno dependiendo del movimiento que queramos lograr como resultado.   

- Todo esto nos permitió entender una parte importante del sistema de movimiento, el cual nos sirve como base para después implementar un sistema más completo. 

![divider](https://64.media.tumblr.com/8a4c4aa7d59a9902cf7af99d25c30741/6358e14772faff9b-da/s2048x3072/5a757bd89f4480d7f4f293be5c31ec807e411db4.pnj) 
## Colaboradores

- [@AtlasDaKiwi](https://github.com/AtlasDaKiwi) (Atlas)
- [@val130613](https://github.com/val130613) (Valeria)
- [@arianacastt](https://github.com/arianacastt)  (Ariana)
- [@Lzreb](https://github.com/Lzreb) (Rebeca)
