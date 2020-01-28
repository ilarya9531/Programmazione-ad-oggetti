#ifndef ATTACCO
#define ATTACCO
#include <model/personaggio.h>
class Attacco: public Personaggio{
private:
    unsigned int spazio;
    unsigned int velocita;
    QString tipo;

public:
    Attacco(QString = QString("Default"),
            QString =QString ("Default"),
            unsigned int = 0,
            QString = QString("Default"),
            unsigned int = 0,
            unsigned int = 0,
            unsigned int=0,
            QString = QString("Default"),
            QString = QString("Default"),
            unsigned int =0,
            unsigned int=0,
            QString = QString("Default"));

    void setDanno(unsigned int);
    unsigned int getSpazio()const;
    unsigned int getVelocita()const;
    QString getTipo()const;
    void setSpazio(unsigned int=0);
    void setVelocita(unsigned int=0);
    void setTipo(QString = QString());
    bool operator==(const Personaggio&) const;
    bool operator!=(const Personaggio&) const;

    Attacco* clone() const;
};

#endif // ATTACCO

