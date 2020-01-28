#include <model/difesa.h>


Difesa::Difesa(QString n,
               QString descr,
           unsigned int d,
          QString bf,
           unsigned int c,
           unsigned int v,
           unsigned int t,
           QString td,
           QString tb,

           unsigned int dist):
            Personaggio(n,
                        descr,
                 d,
                 bf,
                 c,
                 v,
                 t,
                 td,
                 tb
                 ),
            distanza(dist) {}

unsigned int Difesa::getDistanza() const {
    return distanza;
}

void Difesa::setDistanza(unsigned int dist) {
    if(distanza != dist) {
        distanza = dist;
    }
}
void Difesa::setDanno(unsigned int d){
    if(danno!=d){
        danno=d*5;
    }
}
bool Difesa::operator==(const Personaggio& x) const {
    const Difesa* app = dynamic_cast<const Difesa*>(&x);
    if(app) {
        return  Personaggio::operator==(x) &&
                distanza == app->getDistanza();
    }
    return false;
}

bool Difesa::operator!=(const Personaggio& x) const {
    const Difesa* app = dynamic_cast<const Difesa*>(&x);
    if(app) {
        return  Personaggio::operator!=(x) &&
                distanza != app->getDistanza();
    }
    return false;
}

Difesa* Difesa::clone() const {
    return new Difesa(*this);
}
