#ifndef Window_H
#define Window_H
#include<model/attacco.h>
#include<model/difesa.h>
#include<model/eroe.h>
#include<model/personaggio.h>
#include<model/container.h>
#include<model/deepptr.h>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>
#include <QFileDialog>

#include <QMessageBox>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include<QString>
#include<QGroupBox>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QListWidget>
#include<QListWidgetItem>
#include<QSpinBox>

class Window: public QWidget {
    Q_OBJECT
private:
    //lista di oggetti Personaggio
    Container<DeepPtr<Personaggio> > cont;
    QLabel *cercaNomeLabel;
    QLineEdit *cercaNome;
    //bottoni superiori
    QPushButton *aggiungi;
    QPushButton *cerca;
    QPushButton *rimuovi;
    QPushButton *modifica;
    QPushButton *conferma;
    QPushButton *salva;
     //layout a sinistra
    //label
    QLabel *nome;
    QLabel *descr;
    QLabel *danno;
    //bf=bersaglio preferito
    QLabel *bf;
    QLabel *costo;
    QLabel *vita;
    QLabel *tempo;
    QLabel *tipodanno;
    QLabel *bersagli;
    QLabel *type;
    QLabel *spazio;
    QLabel *velocita;
    QLabel *tipo;
    QLabel *distanza;
    QLabel *temporig;
    QLabel *livello;

    QLineEdit *nomeText;
    QLineEdit *descrText;
    QSpinBox *dannoSpin;
    QComboBox *bfCombo;
    QSpinBox *costoSpin;
    QSpinBox *vitaSpin;
    QSpinBox *tempoSpin;
    QComboBox *tipodannoCombo;
    QComboBox *bersagliCombo;
    QComboBox *typeCombo;

    QSpinBox *spazioSpin;
    QSpinBox *velocitaSpin;
    QLineEdit *tipoText;
    QSpinBox *distanzaSpin;
    QSpinBox *temporigSpin;
    QSpinBox *livelloSpin;

//F=filtro
    QLabel *typeFLabel;
    QLabel *bfFLabel;
    QLabel *tipodannoFLabel;
    QLabel *bersagliFLabel;
    QComboBox *typeF;
    QComboBox *bfF;
    QComboBox *tipodannoF;
    QComboBox *bersagliF;

//lista risultati
    QListWidget *lista;

    QPushButton *leggi;
    QLabel  *listaLabel;

    QString file;

    private slots:

        void resettaCampi();
        void resettaFiltri();
        void filtraPers(QListWidget*);
        void setEditText(QString);
        bool aggiungiPersonaggio();
        bool salvaSuFile(const QString);
        void salvaClicked();
        QString getType(DeepPtr<Personaggio>);
        void leggiClicked();
        bool leggiDaFile(QString);
        void mostraDettagli();
        bool modificaCampi();
        bool controlloDoppioni(QString);
        void elimina();

public:
    Window(QWidget *parent = 0);

};
#endif // Window_H
