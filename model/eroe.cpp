#include <model/eroe.h>


Eroe::Eroe(QString n,
           QString descr,
           unsigned int d,
          QString bp,
           unsigned int c,
           unsigned int v,
           unsigned int t,
           QString td,
           QString b,
           unsigned int tRig,
           unsigned int lMax):
            Personaggio(n,
                 descr,
                        d,
                 bp,
                 c,
                 v,
                 t,
                 td,
                 b
                 ),
            temporig(tRig),
            livellomax(lMax){}

unsigned int Eroe::getTempoRig() const {
    return temporig;
}
unsigned int Eroe::getLivelloMax()const{
    return livellomax;
}

void Eroe::setTempoRig(unsigned int tRig) {
    if(temporig != tRig) {
        temporig = tRig;
    }
}
void Eroe::setLivelloMax(unsigned int lMax){
    if(livellomax!=lMax){
        livellomax=lMax;
    }
}
void Eroe::setDanno(unsigned int d){
    if(danno!=d){
        danno=d*10;
    }
}

bool Eroe::operator==(const Personaggio& x) const {
    const Eroe* app = dynamic_cast<const Eroe*>(&x);
    if(app) {
        return  Eroe::operator==(x) &&
                temporig == app->getTempoRig()&&
                livellomax == app->getLivelloMax();
    }
    return false;
}

bool Eroe::operator!=(const Personaggio& x) const {
    const Eroe* app = dynamic_cast<const Eroe*>(&x);
    if(app) {
        return  Personaggio::operator!=(x) &&
                temporig != app->getTempoRig()&&
                livellomax !=app->getLivelloMax();
    }
    return false;
}

Eroe* Eroe::clone() const {
    return new Eroe(*this);
}
