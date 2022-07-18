
#include <algorithm>
#include <functional>
#include <vector>
#include "Person.h"


using personas = std::vector<Person>;
using indexArr = std::vector<size_t>;
using pointIndex = typename std::pair< std::vector< double >, size_t >;


class NodePerson{
public: 
    using KDNodePtr = std::shared_ptr< NodePerson >; 
    const size_t index = 2;
    Person persona;
    KDNodePtr Izq;
    KDNodePtr Der;
   
    NodePerson();
    NodePerson(Person p);

    ~NodePerson();
    
    // getter
    double coord(const size_t &);
    Person getPerson();
    KDNodePtr getIzq();
    KDNodePtr getDer();
    // conversions
    explicit operator bool();
    explicit operator point_t();
    explicit operator size_t();
    explicit operator pointIndex();    
};

using KDNodePtr = std::shared_ptr< NodePerson >;
KDNodePtr NewKDNodePtr();

inline double dist2(const KDNodePtr &, const KDNodePtr &); //distancia en el area cuadrada
inline double dist2(const point_t &, const point_t &);

inline double dist(const KDNodePtr &, const KDNodePtr &);// distancia respecto a un punto
inline double dist(const point_t &, const point_t &);
