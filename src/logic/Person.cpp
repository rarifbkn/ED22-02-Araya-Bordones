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
void setEntity(string newEntity){
   this->entity = newEntity;
}


Person :: ~Person(){

}