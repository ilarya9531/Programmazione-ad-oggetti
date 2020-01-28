#ifndef DIFESA
#define DIFESA
#include <model/personaggio.h>
class Difesa: public Personaggio{
private:
    unsigned int distanza;
public:
    Difesa(QString = QString("Default"),
           QString =QString("Default"),
            unsigned int = 0,
            QString = QString("Default"),
            unsigned int = 0,
            unsigned int = 0,
            unsigned int=0,
            QString = QString("Default"),
            QString = QString("Default"),
            unsigned int =0
            );
    unsigned int getDistanza()const;
    void setDistanza(unsigned int=0);
void setDanno(unsigned int=0);
    bool operator==(const Personaggio&) const;
    bool operator!=(const Personaggio&) const;

    Difesa* clone() const;

};

#endif // DIFESA

