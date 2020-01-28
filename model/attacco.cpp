#include <model/attacco.h>


Attacco::Attacco(QString n,
                 QString descr,
                 unsigned int d,
                 QString bp,
                 unsigned int c,
           unsigned int v,
           unsigned int t,
           QString td,
           QString b,
           unsigned int s,
           unsigned int vel,
                 QString tip):
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
                
            spazio(s),
velocita(vel),
tipo(tip){}

unsigned int Attacco::getSpazio() const {
    return spazio;
}
unsigned int Attacco::getVelocita() const{
    return velocita;
                        }
QString Attacco::getTipo() const{
    return tipo;
                        }
void Attacco::setSpazio(unsigned int s) {
    if(spazio != s) {
        spazio = s;
    }
}
void Attacco::setVelocita(unsigned int vel){
    if(velocita!=vel){
        velocita=vel;
    }
}
void Attacco::setTipo(QString t){
    if(tipo!=t){
       tipo=t;
     }
}
                        
void Attacco::setDanno(unsigned int d){
    if(danno!=d){
        danno=d*2;
    }
}

bool Attacco::operator==(const Personaggio& toCheck) const {
    const Attacco* app = dynamic_cast<const Attacco*>(&toCheck);
    if(app) {
        return  Personaggio::operator==(toCheck) &&
                spazio == app->getSpazio()&&
                velocita==app->getVelocita()&&
                tipo==app->getTipo();
    }
    return false;
}

bool Attacco::operator!=(const Personaggio& x) const {
    const Attacco* app = dynamic_cast<const Attacco*>(&x);
    if(app) {
        return  Personaggio::operator!=(x) &&
                spazio != app->getSpazio()&&
                velocita !=app->getVelocita()&&
                tipo!=app->getTipo();
    }
    return false;
}

Attacco* Attacco::clone() const {
    return new Attacco(*this);
}
