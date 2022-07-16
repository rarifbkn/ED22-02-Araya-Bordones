#include "NodePerson.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
using pointIndexArr = typename std::vector< pointIndex >;


// clase de ayuda para comparar
class comparer{
    public: 
    size_t idx;   
    explicit comparer(size_t idx); 
    inline bool compareIdx(const pointIndex&, const pointIndex&);
};
    using pointIndexArr = typename std::vector< pointIndex >;
    
    inline void sort_on_idx(const pointIndexArr::iterator &,const pointIndexArr::iterator &, size_t idx);

    using pointVec = std::vector<point_t>;

class KDTree{
    private:
        KDNodePtr raiz;
        KDNodePtr hojas;

        KDNodePtr makeTree(const pointIndexArr::iterator &begin,
                            const pointIndexArr::iterator &end, 
                            const size_t &length,const size_t &level);

        KDNodePtr cercano(const KDNodePtr &rama,
                            const point_t &pt, 
                            const size_t &level, 
                            const KDNodePtr &best, 
                            const double &best_dist );

        
        pointIndexArr vecino(const KDNodePtr &branch, 
                            const point_t &pt, 
                            const double &rad, 
                            const size_t &level );

    public:
        KDTree() = default;
        explicit KDTree(pointVec point_array);

        //Funcion cercano
        point_t PuntoCercano(const point_t &pt);
        size_t IndexCercano(const point_t &pt);
        pointIndex PointIndexCercano(const point_t &pt);

        //funcion vecino
        pointIndexArr vecino(const point_t &pt, const double &rad);
        pointVec puntosVecinos(const point_t &pt, const double &rad);
        indexArr IndexVecinos(const point_t &pt, const double &rad);

};

//constructor por defecto
KDNodePtr cercano(const point_t &pt);