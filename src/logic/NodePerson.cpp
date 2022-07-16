#include "includes/NodePerson.h"
#include <algorithm>
#include <cmath>
#include <functional>
#include <iterator>
#include <limits>
#include <memory>
#include <vector>

NodePerson::NodePerson() = default;
NodePerson::NodePerson(Person &p){
    persona = p;
}

NodePerson::NodePerson(Person &p, const KDNodePtr &left_,
               const KDNodePtr &right_) {
                
    persona = p;            
    Izq = left_;
    Der = right_;
}


NodePerson::~NodePerson() = default;

double NodePerson::coord(const size_t &idx) { return this->persona.getCord().at(idx); }
NodePerson::operator bool() { return (!this->persona.getCord().empty()); }
NodePerson::operator point_t() { return this->persona.getCord(); }
NodePerson::operator size_t() { return index; }
NodePerson::operator pointIndex() { return pointIndex(this->persona.getCord(), index); }
KDNodePtr NodePerson::getIzq(){
    return this->Izq;
}
KDNodePtr NodePerson::getDer(){
    return this->Der;
}

KDNodePtr NewKDNodePtr() {
    KDNodePtr mynode = std::make_shared< NodePerson >();
    return mynode;
}


inline double dist2(const point_t &a, const point_t &b) {
    double distc = 0;
    for (size_t i = 0; i < a.size(); i++) {
        double di = a.at(i) - b.at(i);
        distc += di * di;
    }
    return distc;
}

inline double dist2(const KDNodePtr &a, const KDNodePtr &b) {
    return dist2(a->getPerson().getCord(), b->getPerson().getCord());
}

inline double dist(const point_t &a, const point_t &b) {
    return std::sqrt(dist2(a, b));
}

inline double dist(const KDNodePtr &a, const KDNodePtr &b) {
    return std::sqrt(dist2(a, b));
}