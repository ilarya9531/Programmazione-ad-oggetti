#ifndef PERSONAGGIO
#define PERSONAGGIO




#include <model/exception.h>

class Personaggio {
protected:
    unsigned int danno;
    private:
        QString nome;
        QString descrizione;

        QString bersaglioprefe;
        unsigned int costo;
        unsigned int vita;
        unsigned int tempo;
        QString tipodanno;

        QString bersagli;
    public:
        Personaggio(QString = QString("Default"),
                    QString = QString("Default"),
                     unsigned int = 0,
                     QString = QString("Default"),
                     unsigned int = 0,
                     unsigned int = 0,
                     unsigned int=0,
                     QString = QString("Default"),
                     QString = QString("Default")


            );
        QString getNome() const;
        QString getDescrizione() const;
        unsigned int getDanno() const;
        QString getBersaglioPrefe() const;
        unsigned int getCosto() const;
        unsigned int getVita() const;
        unsigned int getTempo() const;
        QString getTipoDanno() const;
        QString getBersagli() const;



        void setNome(QString = QString());
        void setBersaglioPrefe(QString = QString("False"));
        void setCosto(unsigned int = 0);
        void setVita(unsigned int = 0);
        void setTempo(unsigned int = 0);
        void setTipoDanno(QString = QString());
        void setBersagli(QString = QString());


        void setDescrizione(QString = QString());
        virtual void setDanno(unsigned int = 0)=0;
        virtual Personaggio* clone() const = 0;
        virtual bool operator==(const Personaggio&) const;
        virtual bool operator!=(const Personaggio&) const;
        virtual ~Personaggio() = default;
};
#endif // PERSONAGGIO
