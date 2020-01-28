#include <model/personaggio.h>

Personaggio::Personaggio(QString n,
                         QString descr,
                            unsigned int d,
                            QString bf,

                           unsigned int c,
                           unsigned int v,
                           unsigned int t,
                           QString td,
                           QString b) {
    nome = n;
    descrizione=descr;
    danno= d;
    descrizione= descr;
    bersaglioprefe= bf;
    costo=c;
    vita=v;
    tempo=t;
    tipodanno=td;
    bersagli=b;
}

QString Personaggio::getNome() const {
    return nome;
}
QString Personaggio::getDescrizione() const {
    return descrizione;

}
unsigned int Personaggio::getDanno() const {
    return danno;
}

QString Personaggio::getBersaglioPrefe() const {
    return bersaglioprefe;
}

unsigned int Personaggio::getCosto() const {
    return costo;
}

unsigned int Personaggio::getVita() const {
    return vita;
}

unsigned int Personaggio::getTempo() const {
    return tempo;
}

QString Personaggio::getTipoDanno() const {
    return tipodanno;
}

QString Personaggio::getBersagli() const {
    return bersagli;
}



void Personaggio::setNome(QString n) {
    if(nome != n) {
        nome = n;
    }
}


void Personaggio::setDescrizione(QString descr){
    if(descrizione!=descr){
        descrizione=descr;
    }
}
void Personaggio::setCosto(unsigned int c) {
    if(danno != c) {
        danno = c;
    }
}
void Personaggio::setBersaglioPrefe(QString bp) {
    if(bersaglioprefe != bp) {
        bersaglioprefe = bp;
    }
}
void Personaggio::setVita(unsigned int v) {
    if(vita != v) {
        vita = v;
   }
}
void Personaggio::setTempo(unsigned int t) {
    if(tempo != t) {
        tempo = t;
    }
}
void Personaggio::setTipoDanno(QString td) {
    if(tipodanno != td) {
        tipodanno = td;
    }
}


void Personaggio::setBersagli(QString b) {
    if(bersagli != b) {
        bersagli = b;
    }
}





bool Personaggio::operator==(const Personaggio& x) const {
    return  nome      == x.getNome() &&
            descrizione   == x.getDescrizione() &&
            danno == x.getDanno() &&
            bersaglioprefe        == x.getBersaglioPrefe() &&
            costo       == x.getCosto() &&
            vita      == x.getVita() &&
            tempo          == x.getTempo() &&
            tipodanno        == x.getTipoDanno() &&
            bersagli      == x.getBersagli() ;

}

bool Personaggio::operator!=(const Personaggio& x) const {
    return  nome      != x.getNome() &&
            descrizione  != x.getDescrizione() &&
            danno != x.getDanno() &&
            bersaglioprefe != x.getBersaglioPrefe() &&
            costo       != x.getCosto() &&
            vita      != x.getVita() &&
            tempo          != x.getTempo() &&
            tipodanno        != x.getTipoDanno() &&
            bersagli      != x.getBersagli() ;
}
