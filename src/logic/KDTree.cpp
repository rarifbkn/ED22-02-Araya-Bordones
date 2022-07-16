#include "includes/KDTree.h"

comparer::comparer(size_t idx_):idx{idx_}{};

inline bool comparer::compareIdx(const pointIndex &a, const pointIndex &b){
    return (a.first.at(idx) < b.first.at(idx));    
}

inline void sort_on_index(const pointIndexArr::iterator &begin, 
                        const pointIndexArr::iterator &end,
                        size_t idx){
    comparer comp(idx);
    comp.idx = idx;

    using std::placeholders::_1;
    using std::placeholders::_2;

    std::nth_element(begin, begin + std::distance(begin,end)/2,
                    end,std::bind(&comparer::compareIdx,comp,_1,_2));

}
using pointVec = std::vector<point_t>;

KDNodePtr KDTree::makeTree(const pointIndexArr::iterator &begin,
                            const pointIndexArr::iterator &end,
                            const size_t &length,
                            const size_t &level){


        if(begin == end){
            return NewKDNodePtr();
        }

        size_t dim = begin->first.size();

        if(length > 1){
            sort_on_idx(begin,end,level);
        }

        auto middle = begin + (length/2);// mediana

        auto lBegin = begin;
        auto lEnd = middle;
        auto rBegin = middle +1;
        auto rEnd = end;

        size_t lLen = length/2;
        size_t rLen = length -lLen -1;

        KDNodePtr left;
        if(lLen > 0 && dim >0){
            left  =makeTree(rBegin,rEnd,rLen,(level +1)% dim);
        }else{
            left  = this->hojas;
        }
         KDNodePtr right;
        if (rLen > 0 && dim > 0) {
            right = makeTree(rBegin, rEnd, rLen, (level + 1) % dim);
        } else {
            right = this->hojas;
        }
    return std::make_shared<NodePerson>(*middle,left,right);

}


KDTree::KDTree(pointVec poitnArray){   
    hojas = std::make_shared<NodePerson>();
    //iterador
    pointIndexArr arr;
    for(size_t i=0; i < poitnArray.size();i++){
        arr.push_back(pointIndex(poitnArray.at(i),i));
    }
    auto begin = arr.begin();
    auto end = arr.end();

    size_t length = arr.size();
    size_t level = 0; // Nivel Raiz

    raiz = KDTree::makeTree(begin,end,length,level);
}

KDNodePtr KDTree::cercano(const KDNodePtr &branch,
                        const point_t &pt, 
                        const size_t &level,
                        const KDNodePtr &best,
                        const double &bestDist){
     
     double d ,dx,dx2;

    if(!bool(*branch)){
        return NewKDNodePtr();
    }
    point_t branchPt(*branch);
    size_t dim = branchPt.size();

    d = dist2(branchPt,pt);
    dx = branchPt.at(level) -pt.at(level);
    dx2 = dx*dx;

    KDNodePtr bestL = best;
    double bestDist1 = bestDist;

    if(d < bestDist){
        bestDist1 = d;
        bestL = branch;
    }   

    size_t nextLvl = (level + 1)%dim;
    KDNodePtr seccion;
    KDNodePtr otra;


    // selecciona cual rama es mas coherente comprobar

    if(dx > 0){
        seccion = branch->getIzq();
        otra = branch->getDer();
    }else{
        seccion = branch->getDer();
        otra = branch->getIzq();
    }

    //mantiene vecinos mas cercanos debajo del arbol

    KDNodePtr lejano = cercano(seccion,pt,nextLvl,bestL,bestDist1);
    if(!lejano->getPerson().getCord().empty()){
        double dL = dist2(lejano->getPerson().getCord(),pt);
        if(dL < bestDist1){
            bestDist1 = dL;
            bestL = lejano;
        }
    }
    //solamente revisa la otra rama si esta no tiene sentido hacerlo
    if(dx2 < bestDist1){
        lejano = cercano(otra,pt,nextLvl,bestL,bestDist1);
        if(!lejano->getPerson().getCord().empty()){
            double dL = dist2(lejano->getPerson().getCord(),pt);
            if(dL < bestDist1){
                bestDist1 = dL;
                bestL = lejano;
            }
        }
    }
    return bestL;
}
 

point_t KDTree::PuntoCercano(const point_t &pt) {
    return point_t(*cercano(pt));
};
size_t KDTree::IndexCercano(const point_t &pt) {
    return size_t(*cercano(pt));
};

pointIndex KDTree::PointIndexCercano(const point_t &pt) {
    KDNodePtr Nearest = cercano(pt);
    return pointIndex(point_t(*Nearest), size_t(*Nearest));
}

pointIndexArr KDTree::vecino(  //
    const KDNodePtr &branch,          //
    const point_t &pt,                //
    const double &rad,                //
    const size_t &level               //
) {
    double d, dx, dx2;

    if (!bool(*branch)) {
        // branch has no point, means it is a leaf,
        // no points to add
        return pointIndexArr();
    }

    size_t dim = pt.size();

    double r2 = rad * rad;

    d = dist2(point_t(*branch), pt);
    dx = point_t(*branch).at(level) - pt.at(level);
    dx2 = dx * dx;

    pointIndexArr nbh, nbh_s, nbh_o;
    if (d <= r2) {
        nbh.push_back(pointIndex(*branch));
    }

    //
    KDNodePtr section;
    KDNodePtr other;
    if (dx > 0) {
        section = branch->getIzq();
        other = branch->getDer();
    } else {
        section = branch->getDer();
        other = branch->getIzq();
    }

    nbh_s = vecino(section, pt, rad, (level + 1) % dim);
    nbh.insert(nbh.end(), nbh_s.begin(), nbh_s.end());
    if (dx2 < r2) {
        nbh_o = vecino(other, pt, rad, (level + 1) % dim);
        nbh.insert(nbh.end(), nbh_o.begin(), nbh_o.end());
    }

    return nbh;
};

pointIndexArr KDTree::vecino(  //
    const point_t &pt,               //
    const double &rad) {
    size_t level = 0;
    return vecino(raiz, pt, rad, level);
}

pointVec KDTree::puntosVecinos(  //
    const point_t &pt,                 //
    const double &rad) {
    size_t level = 0;
    pointIndexArr nbh = vecino(raiz, pt, rad, level);
    pointVec nbhp;
    nbhp.resize(nbh.size());
    std::transform(nbh.begin(), nbh.end(), nbhp.begin(),
                   [](pointIndex x) { return x.first; });
    return nbhp;
}

indexArr KDTree::IndexVecinos(  //
    const point_t &pt,                  //
    const double &rad) {
    size_t level = 0;
    pointIndexArr nbh = vecino(raiz, pt, rad, level);
    indexArr nbhi;
    nbhi.resize(nbh.size());
    std::transform(nbh.begin(), nbh.end(), nbhi.begin(),
                   [](pointIndex x) { return x.second; });
    return nbhi;
}
   // default caller
     KDNodePtr KDTree::cercano(const point_t &pt) {
    size_t level = 0;
    // KDNodePtr best = branch;
    double branchDist = dist2(point_t(*raiz), pt);
    return cercano(raiz,          // beginning of tree
                    pt,            // point we are querying
                    level,         // start from level 0
                    raiz,          // best is the root
                    branchDist);  // best_dist = branch_dist
}



