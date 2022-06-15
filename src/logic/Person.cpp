#include "includes/Person.h"
#include <iostream>

using namespace std;

Person::Person(){

}
Person::Person(string entity, Mat img){
    this->entity = entity;
    this->img = img;
    this->contEntries = 0;
    this->contExit = 0;
    
}

Mat Person::getImg(){
    return this->img;
}

void Person::setImg(Mat img){
    this->img = img;
}

string Person::getEntity(){
    return this->entity;
}
void Person ::setEntity(string entity){
    this->entity= entity;

}
int Person::getEntries(){
    return this->contEntries;
}
void Person::setEntries(int contE){
    this->contEntries = contE;
}
int Person::getExit(){
    return this->contExit;
}
void Person::setExit(int contE){
    this->contExit = contE;
}
Person :: ~Person(){

}