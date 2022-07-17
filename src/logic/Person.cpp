#include "includes/Person.h"

Person::Person(){

}

Person::Person(Rect& r){

    xInitial = r.x;
    yInitial = r.y;
    xFinal = r.x + r.width;
    yFinal = r.y + r.height;
    xCentro = r.x + ((float)r.width/2.0);
    yCentro = r.y + ((float)r.height/2.0);
}

Mat Person::getImg(){
    return this->img;
}
string Person::getEntity(){
    return this->entity;
}
int Person::getxInitial(){
    return this->xInitial;
}
int Person::getyInitial(){
    return this->yInitial;
}
int Person::getxCentro(){
    return this->xCentro;
}
int Person::getyCentro(){
    return this->yCentro;
}
int Person::getxFinal(){
    return this->xFinal;
}
int Person::getyFinal(){
    return this->yFinal;
}

void Person::setImg(Mat newImage){
    this->img = newImage;
}
void Person ::setEntity(string entity){
    this->entity= entity;

}
void Person::setxInitial(int x){
    this->xInitial = x;
}
void Person::setyInitial(int y){
    this->yInitial = y;

}
void Person::setxCentro(int x){
    this->xCentro = x;
}
void Person::setyCentro(int y){
    this->yCentro;
}
void Person::setxFinal(int x){
    this->xFinal = x;
}
void Person::setyFinal(int y){
    this->yFinal = y;
}