#include "includes/Person.h"

using namespace std;

Person::Person(Rect& r){

    xInitials = r.x;
    yInitials = r.y;
    xFinal = r.x + r.width;
    yFinal = r.y + r.height;
    centroX = r.x + ((float)r.width/2.0);
    centroY = r.y + ((float)r.height/2.0);
}

Mat Person::getImg(){
    return this->img;
}
int Person::getEntries(){
    return this->contEntries;
}
string Person::getEntity(){
    return this->entity;
}
int Person::getExit(){
    return this->contExit;
}
int Person::getxInitials(){
    return this->xInitials;
}
int Person::getyInitials(){
    return this->yInitials;
}
int Person::getCentroX(){
    return this->centroX;
}
int Person::getCentroY(){
    return this->centroY;
}
int Person::getxFinal(){
    return this->xFinal;
}
int Person::getyFinal(){
    return this->yFinal;
}

void Person::setImg(Mat img){
    this->img = img;
}
void Person ::setEntity(string entity){
    this->entity= entity;

}
void Person::setEntries(int contE){
    this->contEntries = contE;
}

void Person::setExit(int contE){
    this->contExit = contE;
}
void Person::setxInitials(int x){
    this->xInitials = x;
}
void Person::setyInitials(int y){
    this->yInitials = y;

}
void Person::setCentroX(int x){
    this->centroX = x;
}
void Person::setCentroY(int y){
    this->centroY;
}
void Person::setxFinal(int x){
    this->xFinal = x;
}
void Person::setyFinal(int y){
    this->yFinal = y;
}

Person :: ~Person(){

}