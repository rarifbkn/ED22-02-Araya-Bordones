![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de personas en secuencias de imágenes o video

**Alumnos:**

* Arif Bordones Sierra. (Coordinador)
* Scarlette Araya Lobos. (Encargada de bitácora)

## Resumen 

>El trabajo a realizar consiste en desarrollar una aplicación que cumpla con reconocer, enlistar y contabilizar el flujo de personas que circulan por las entradas principales de la empresa ACME. Esto se llevara a cabo por medio del uso de orientación a objeto y arboles binarios. 

## 1. Introducción

La problemática propuesta consiste en crear un sistema de vigilancia para una empresa, la cual tiene como objetivo llevar la información de las personas que transitan en una una zona en específico. Para esto el equipo ideara un programa que registrara la entrada y salida de los clientes al recinto, el cual se llevara a cabo en visual studio code con c++, haciedo uso de libreria de visión artificial OpenCV.

### 1.1 Descripción del problema

El desafío de este taller consiste en la creación de un programa que sea capaz de llevar la información que nos proporcionara la camara de seguridad de la empresa, con esta información se requiere contabilizar la entrada y salida de las personas a la zona en específico.  

### 1.2 Objetivos 

**Objetivo General**

Desarrollar e implementar un programa que sea capaz de contabilizar y reconocer a las personas que transitan por las principales entradas.

**Objetivos específicos**

1. Estructurar el problema y la creación de las clases principales.
2. Desarrollo del código para reconocer a las personas.
3. Mejorar el código con la inclusión de árboles como estructura principal.

### 1.3 Solución propuesta

La solución propuesta consiste en la detección de las personas ubicando el centro de esta, que en conjunto de una linea referencial(mitad de la imagen) describira la entrada o salida de las personas que transitan en el video.

*Desarrollo de la solución*

->Detección de personas
Implementar histogramas de gradientes orientados por medio del método HOGDescriptor, el cual por medio de diversos filtros de colores identifica el objeto que resalta dentro de la imagen.  

->Información personas
Por medio de lista enlazadas //arboles binarios// se almacenara a las personas reconocidas por el detector.

->Cálculo
Luego de estructurar la información se calculará tráfico, cantidad y velocidad de entrada y salida de personas.  

## 2. Materiales y métodos

Para el desarrollo de este taller se requiere: 

-Video de seguridad o secuencia de imágenes.
-IDE visual studio code
-Libreria OpenCV

### 2.1 Instalación

*Librerias*
-OpenCV

*IDES*
-Visual studio code

### 2.2 Diseño 

El diseño utilizado en este taller fue la por default del Cmake, con el módulo de logic el cual contiene las clases cpp con sus propios métodos, el módulo include contiene los headers de las clases, las cules son:

->Person
->NodePerson
->KDTree
->Detector

![DIAGRAMA DE CLASES](images/Diagrama_de_clases_EDD.png)

### 2.3 Implementación //Editar//

    En el talller se implementaron muchos métodos que ayudan a detectar y reconocer a las personas que aparecen en la secuencia de imágenes y para almacenar esta información se uso la estructura de datos árboles binarios.
    
    -> el histograma de gradientes orientados por medio del codigo:

    > Crea el detector para luego guardarlo en un vector
    > HOGDescriptor hog;
    > hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
    > vector<Rect> detections;  

    ->La deteccion de personas se hace una vez creado el detector, por medio de un iterador
    >hog.detectMultiScale(img,detections,0,Size(3,4),Size(4,4),1.05,2);   
    >   //itero por cada deteccion que reconoce el hog   
    >   for(auto& detection :detections){
    >      //ajusta el rectangulo de la imagen
    >        AdjustBox(detection);
    >        p = detection;
    >        //crea la identidad de la persona
    >       string aux = to_string(numberPerson);
    >        p = detection;
    >        p.setEntity(identidad + aux);
    >        //creo el nodo y lo inserto en la lista
    >        NodePerson nodo = NodePerson(p);
    >        Personas.insert(&nodo);
    >       //Dibuja las figuras en la imagen
    >
    >        putText(img,p.getEntity(),Point(p.getxCentro(),p.getyCentro()+5),FONT_HERSHEY_COMPLEX,0.60,Scalar(0,255,0));
    >        rectangle(img,Point(p.getxInitial(),p.getyInitial()),Point(p.getxFinal(),p.getyFinal()),Scalar(0,0,255),2);
    >        circle(img,Point(p.getxCentro(),p.getyCentro()),2,Scalar(0,255,0),2);
    >        numberPerson++; 
    >    } 

    ->La Lista Enlazada Simple:
    >//Lista Enlazada creada en el main
    > LinkedList Personas;

    ->La lectura de la secuencia de imágenes
    >//iterador
    >vector<string> paths;
    >paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/secuencia de imagenes/imagen01.png");
    >paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/secuencia de imagenes/imagen02.png");
    >paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/secuencia de imagenes/imagen03.png");
    >for(auto& path:paths){
    >    //LECTURA IMAGEN
    >    Mat img = imread(path);
    >   // por si no encuentra la imagen
    >   if(!img.data) return -1;}

    ->Seguimiento de deteccion:
    Por temas de tiempo y diversas dificultades explicadas dentro del informe en un anexo , no se logro realizar la diferenciacion de las personas entre las imagenes, es por esta razón que no se pudo continuar las historias 2,3,4,5,6,7 ya que era necesaria la diferenciacion entre estas para lograr el requirimiento

    Sin embargo la lógica a implementar, fue que por cada imagen que pasara hiciera una lista de centroides nuevos para comparar por cada persona iterando en el vector de centroides, para asi obtener las personas que tienen una menor distancias entre los centroides de la persona y el centroide nuevo identificado y que por ende corresponden a la misma identidad, ó a los centroides que no se relacionan en distancia con ninguna persona anterior y que en conclusión serían personas nuevas. 

## 3. Resultados obtenidos

    Por cada imagen leída en el programa se obtuvo la detección de personas correspondientes de forma correcta e identificada por una identidad, sin embargo dependiendo de la calidad de la imagen en cuanto a luz o colores puede variar el margen de error de detección, asi como con muchas personas juntas , puesto que confunden al área de detección del programa.

## 4. Conclusiones//Editar

Tras este tiempo de trabajo y todo lo mencionado anteriormente, se logró el 90% de las historias requeridas para esta segunda entrega, el objetivo principal de reconocer a las personas  por secuencia de imágenes se logró en su totalidad junto a la implementación de arboles binarios.

# Anexos

## Anexo A: Instalación librerías OpenCV

https://opencv.org/releases/

## Anexo B: Instalación de IDE y configuración librerías OpenCV

https://visualstudio.microsoft.com/es/downloads/
https://cmake.org/download/

## Anexo C: Dificultades y problemáticas durante el desarrollo del taller //editar

Durante el desarrollo se lograron muchos avances, pero en conjunto de diversos problemas se dificultó el trabajar en la IDE visual Studio code puesto que requeria de muchas herramientas externas para trabajar con el lenguaje c++, a pesar de tener mucha ayuda por parte del profesor y ayudante del ramo Estructura de Datos, no fue suficiente para aclarar todas las dudas que fueron surgiendo, por último el correr en el programa un video hacia que los recursos del pc llegaran a niveles altos de consumo que realentizaban el proceso y no se logro dibujar sobre el video los rectangulos de detección por falta de conocimiento.

# Referecia

##Videos:

Los videos se usaron como referencia para la realizacion del proyecto.

- tochiVision (2019, mayo 14). [OpenCV/C++ tutorial] people detection using Histogram of Oriented Gradients (HOG). Youtube. https://www.youtube.com/watch?v=cvGEWBO0Vho

-CasualGamer (2020, noviembre 15). Capture Window with OpenCV in C++. Youtube. https://www.youtube.com/watch?v=mwfHopNiA3I


- tochiVision (2018, julio 1). [OpenCV/C++ tutorial] Read, Display and write video. Youtube. https://www.youtube.com/watch?v=VIg_xQ5ud8s

- tochiVision (2019b, junio 1). [OpenCV/C++ tutorial] combined people detection and tracking. Youtube. https://www.youtube.com/watch?v=BCJYorKIlN8


 ##Páginas
 
Se busco información en OpenCV Library. (2021, febrero 9). Home. OpenCV. https://opencv.org/

Se busco y resolvieron dudas de errores desde corob-msft. (s/f). Compiler error C2512. Microsoft.Com. Recuperado el 25 de junio de 2022, de https://docs.microsoft.com/en-us/cpp/error-messages/compiler-errors-2/compiler-error-c2512?view=msvc-170


 


