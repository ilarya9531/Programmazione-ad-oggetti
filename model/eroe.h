#ifndef EROE
#define EROE
#include <model/personaggio.h>
class Eroe: public Personaggio{
private:
    unsigned int temporig;
    unsigned int livellomax;
public:
    Eroe(QString = QString("Default"),
         QString=QString("Default"),
            unsigned int = 0,
            QString = QString("Default"),
            unsigned int = 0,
            unsigned int = 0,
            unsigned int=0,
            QString = QString("Default"),
            QString = QString("Default"),
            unsigned int =0,
            unsigned int=0);
    QString getDescrizione()const;
    unsigned int getTempoRig()const;
    unsigned int getLivelloMax()const;
    void setDanno(unsigned int=0);

    void setTempoRig(unsigned int=0);
    void setLivelloMax(unsigned int=0);
    bool operator==(const Personaggio&) const;
    bool operator!=(const Personaggio&) const;

    Eroe* clone() const;
};

#endif // EROE

