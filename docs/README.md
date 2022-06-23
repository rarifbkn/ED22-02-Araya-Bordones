![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de caras en secuencias de imágenes o video

**Alumnos:**

* Arif Bordones. (Coordinador)
* Scarlette Araya. (Encargada de bitácora)

## Resumen 
>El trabajo a realizar consiste en desarrollar una aplicación que cumpla con reconocer, enlistar y contabilizar el flujo de personas que circulan por las entradas principales de la empresa ACME. Esto se llevara a cabo por medio del uso de orientación a objeto y listas enlazadas simples. 

## 1. Introducción
La problemática propuesta consiste en crear un sistema de vigilancia para una empresa, la cual tiene como objetivo llevar la información de las personas que transitan en una una zona en específico. Para esto el equipo ideara un programa que registrara la entrada y salida de los clientes al recinto, el cual se llevara a cabo en visual studio code con c++, haciedo uso de libreria de visión artificial OpenCV.

### 1.1 Descripción del problema

El desafío de este taller consiste en la creación de un programa que sea capaz de llevar la información que nos proporcionara la camara de seguridad de la empresa con esta información se requiere contabilizar la entrada y salida de las personas a la zona específica.  

### 1.2 Objetivos 

**Objetivo General**

Desarrollar e implementar un programa que sea capaz de contabilizar y reconocer a las personas que transitan por principales entradas.

**Objetivos específicos**

1. -Estructurar el problema y la creacion de las clases principales.
2. -Desarrollo del codigo para reconocer a las personas.
3. -Mejorar el codigo con la inclusion de arboles como estructura principal.

### 1.3 Solución propuesta

Se trabajo con histogramas de gradientes, los cuales por medio de graficos de colores logran identificar las personas, esto a su vez con ayuda de la libreria OpenCV. 

## 2. Materiales y métodos

Para el desarrollo de este taller se requiere: 
-video de seguridad
-IDE visual studio code
-Libreria OpenCV

### 2.1 Instalación
Librerias
-OpenCV

IDES
-Visual studio code

### 2.2 Diseño 
El diseño utilizado en este taller fue la por default del Cmake, con el modulo de logic el cual contiene las clases cpp con sus propios métodos, el módulo include contiene los headers de las clases, las cules son:
-Person
-NodePerson
-linkedList
-Detector

### 2.3 Implementación*********************************************************************

Explicar brevemente algunos aspectos de implementación: Por ejemplo, detector de caras utilizado. Se pueden realizar pequeñas reseñas al código para indicar elementos importantes en el trabajo.

Por ejemplo, 

#### Detector de caras*****************************************************

El detector de caras utilizado fue xxx. Para utilizarlo se debe.... El código para detectar una cara en una imagen se muestra a continuación:

```c++
 1. faceCascadePath = "./haarcascade_frontalface_default.xml";
 2. faceCascade.load( faceCascadePath )
 3. std::vector<Rect> faces;
 4. faceCascade.detectMultiScale(frameGray, faces);

 5. for ( size_t i = 0; i < faces.size(); i++ )
 6. {
 7.  int x1 = faces[i].x;
 8.  int y1 = faces[i].y;
 9.  int x2 = faces[i].x + faces[i].width;
10.  int y2 = faces[i].y + faces[i].height;
11. }
```
La primera linea carga el archivo de entrenamiento... etc

## 3. Resultados obtenidos******************************************************************

## 4. Conclusiones*********************************************************************************

# Anexos

## Anexo A: Instalación librerías OpenCV

## Anexo B: Instalación de IDE y configuración librerías OpenCV

# Referecia

Indicar los libros, páginas web, documentos, etc. Utilizados en el trabajo. Por ejemplo:

1. MONTERO, J.,Metodos matemáticos aplicados a la ganadería.3aed. Sevilla: Ediciones de la pradera,2007.
2. LVARADO,   J.   P.,¿Qué   debe   contener   un   artículo   científico?.http://www.ie.tec.ac.cr/palvarado/pmwiki/index.php/MSc/Art\%c3\%adculoCient\%c3\%adfico. Fe-cha de acceso:13/Nov/2018


