#include <view/window.h>

using std::sort;

QSize Window::dimButton = QSize(50, 50);
unsigned int Window::defaultWidth = 300;
unsigned int Window::persGroupWidth = 500;


//method to filter the displayed cards based on the filters values
void Window::filtraPers(QListWidget* currentList, QLabel* persTrovati) {
    currentList->reset();
    currentList->clear();
    /*for(auto it = pers.begin(); it != pers.end(); ++it) {
        if( (!nomeComboBox->currentIndex()      || (*it)->getNome() == nomeComboBox->currentText()) &&
            (!attackComboBox->currentIndex()      || (getType(*it) == "Minion" && QString::number(static_cast<Minion*>((*it).pointer)->getAttack()) == attackComboBox->currentText())
                                                  || (getType(*it) == "Weapon" && QString::number(static_cast<Weapon*>((*it).pointer)->getAttack()) == attackComboBox->currentText())) &&
            (!collectibleComboBox->currentIndex() || (*it)->getCollectible() == collectibleComboBox->currentText()) &&
            (!classComboBox->currentIndex()       || (*it)->getClassName() == classComboBox->currentText()) &&
            (!costComboBox->currentIndex()        || QString::number((*it)->getCost()) == costComboBox->currentText()) &&
            (!healthComboBox->currentIndex()      || (getType(*it) == "Hero" && QString::number(static_cast<Hero*>((*it).pointer)->getArmor()) == healthComboBox->currentText())
                                                  || (getType(*it) == "Minion" && QString::number(static_cast<Minion*>((*it).pointer)->getHealth()) == healthComboBox->currentText())
                                                  || (getType(*it) == "Weapon" && QString::number(static_cast<Weapon*>((*it).pointer)->getDurability()) == healthComboBox->currentText())) &&
            (!rarityComboBox->currentIndex()      || (*it)->getRarity() == rarityComboBox->currentText()) &&
            (!setComboBox->currentIndex()         || (*it)->getSet() == setComboBox->currentText()) &&
            (textBox->text().isEmpty()            || (*it)->getName().toUpper().contains(textBox->text().toUpper())) &&
            (!tribeComboBox->currentIndex()       || (getType(*it) == "Minion" && static_cast<Minion*>((*it).pointer)->getTribe() == tribeComboBox->currentText())) &&
            (!typeComboBox->currentIndex()        || ((typeComboBox->currentText() == getType(*it))))) {
            QListWidgetItem* toAdd = new QListWidgetItem();
            toAdd->setData(Qt::UserRole, (*it)->getId());
            toAdd->setText((*it)->getName());
            currentList->addItem(toAdd);
        }
    }*/
    for(auto it = pers.begin(); it != pers.end(); ++it) {
            if( (!nomeComboBox->currentIndex()      || (*it)->getNome() == nomeComboBox->currentText()) &&
                    (!descrComboBox->currentIndex()      || (*it)->getDescrizione() == descrComboBox->currentText()) &&
                    (!dannoComboBox->currentIndex()      || QString::number((*it)->getDanno()) == dannoComboBox->currentText()) &&
                    (!bersaglioPrefeComboBox->currentIndex()      || (*it)->getBersaglioPrefe() == bersaglioPrefeComboBox->currentText()) &&
                    (!costoComboBox->currentIndex()      || QString::number((*it)->getCosto()) == costoComboBox->currentText()) &&
                    (!vitaComboBox->currentIndex()      || QString::number((*it)->getVita()) == vitaComboBox->currentText()) &&
                    (!tempoComboBox->currentIndex()      || QString::number((*it)->getTempo()) == tempoComboBox->currentText()) &&
                    (!tipoDannoComboBox->currentIndex()      || (*it)->getTipoDanno() == tipoDannoComboBox->currentText()) &&
                    (!bersagliComboBox->currentIndex()      || (*it)->getBersagli() == bersagliComboBox->currentText()) &&
                    (!idComboBox->currentIndex()      || (*it)->getId() == idComboBox->currentText())){

                QListWidgetItem* toAdd = new QListWidgetItem();
                toAdd->setData(Qt::UserRole, (*it)->getId());
                toAdd->setText((*it)->getNome());
                currentList->addItem(toAdd);
            }

    }

    currentList->sortItems();
    //persTrovati->setText(QString::number(currentList->count())+" card(s) found!");
}
//ritorna un QString che contiene il tipo del personaggio, trovato tramita cast sull'oggetto passato

QString Window::getType(DeepPtr<Personaggio> pers) {
    if(dynamic_cast<Attacco*>(pers.pointer)) {
        return "Attacco";
    }
    if(dynamic_cast<Difesa*>(pers.pointer)) {
        return "Minion";
    }
    if(dynamic_cast<Eroe*>(pers.pointer)) {
        return "Eroe";
    }

    throw typeError("Tipo personaggio non trovato");
}


//legge i dati dal file la cui posizione si trova nella variabile locale "filePath"

bool Window::leggiDaFile(QString filePath, QListWidget* currentList, QLabel* persTrovati) {
    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    QByteArray jsonData = file.readAll();
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonArray array = document.object().value("pers").toArray();

    if(!array.isEmpty()) {
        if(!pers.isEmpty()) {
            pers.clear();
        }

        foreach(const QJsonValue& v, array) {
            QString tipoPers = QString(v.toObject().value("type").toString());
            if(tipoPers == "Attacco") {
                pers.add(new Attacco(v.toObject().value("nome").toString(),
                                   v.toObject().value("descrizione").toString(),
                                   v.toObject().value("danno").toInt(),
                                   v.toObject().value("bersaglioprefe").toString(),
                                   v.toObject().value("costo").toInt(),
                                   v.toObject().value("vita").toInt(),
                                   v.toObject().value("tempo").toInt(),
                                   v.toObject().value("tipodanno").toString(),
                                   v.toObject().value("bersagli").toString(),
                                   v.toObject().value("id").toString(),
                                   v.toObject().value("spazio").toInt(),
                                   v.toObject().value("velocita").toInt(),
                                   v.toObject().value("tipo").toString()
                                  ));
            }
            else if(tipoPers == "Difesa") {
                pers.add(new Difesa(v.toObject().value("nome").toString(),
                                     v.toObject().value("descrizione").toString(),
                                     v.toObject().value("danno").toInt(),
                                     v.toObject().value("bersaglioprefe").toString(),
                                     v.toObject().value("costo").toInt(),
                                     v.toObject().value("vita").toInt(),
                                     v.toObject().value("tempo").toInt(),
                                     v.toObject().value("tipodanno").toString(),
                                     v.toObject().value("bersagli").toString(),
                                     v.toObject().value("id").toString(),
                                     v.toObject().value("distanza").toInt()


                                    ));
          }
            else if(tipoPers == "Eroe") {
                pers.add(new Eroe(v.toObject().value("nome").toString(),
                                    v.toObject().value("descrizione").toString(),
                                    v.toObject().value("danno").toInt(),
                                    v.toObject().value("bersaglioprefe").toString(),
                                    v.toObject().value("costo").toInt(),
                                    v.toObject().value("vita").toInt(),
                                    v.toObject().value("tempo").toInt(),
                                    v.toObject().value("tipodanno").toString(),
                                    v.toObject().value("bersagli").toString(),
                                    v.toObject().value("id").toString(),
                                    v.toObject().value("livellomax").toInt(),
                                    v.toObject().value("temporig").toInt()
                                   ));
            }

        }
        updateComboBox();
        filtraPers(currentList, persTrovati);
        return true;
    }
    return false;
}
//metodo che setta tutte le ComboBox di default come "all"

void Window::resetFilters() const {
    nomeComboBox->setCurrentIndex(0);
    dannoComboBox->setCurrentIndex(0);
    bersaglioPrefeComboBox->setCurrentIndex(0);
    vitaComboBox->setCurrentIndex(0);
    tempoComboBox->setCurrentIndex(0);
    costoComboBox->setCurrentIndex(0);
    bersagliComboBox->setCurrentIndex(0);
    tipoDannoComboBox->setCurrentIndex(0);

    textBox->clear();
}
// metodo per settare i 3 pulsanti
void Window::setButton(bool nuovoB, bool cancB, bool modB) const {
    if(nuovoPersButton->isEnabled() != nuovoB) {
        nuovoPersButton->setEnabled(nuovoB);
    }
    if(cancPersButton->isEnabled() != cancB) {
        cancPersButton->setEnabled(cancB);
    }
    if(modificaPersButton->isEnabled() != modB) {
        modificaPersButton->setEnabled(modB);
    }
}
//metodo che serve per impostare i campi facoltativi (appartenenti solo ad alcuni personaggi) visibili o meno

void Window::setStackedVisible(bool primo, bool secondo, bool terzo) const {
    if(primaSpecialLabel->isVisible() != primo) {
        primaSpecialLabel->setVisible(primo);
        primaSpecialLabel->setVisible(primo);
    }
    if(secondaSpecialLabel->isVisible() != secondo) {
        secondaSpecialLabel->setVisible(secondo);
        secondaSpecialLabel->setVisible(secondo);
    }
    if(terzaSpecialLabel->isVisible() != terzo) {
        terzaSpecialLabel->setVisible(terzo);
        terzaSpecialLabel->setVisible(terzo);
    }
}
//metodo utilizzato per modificare i dati di un personaggio già inserito
void Window::updatePers(QString ogg) {
    for(auto it = pers.begin(); it != pers.end(); ++it) {
        if( (*it)->getId() == ogg) {

            (*it)->setNome(static_cast<QLineEdit*>(nomeStacked->widget(1))->text());
            (*it)->setDescrizione(static_cast<QLineEdit*>(descrStacked->widget(1))->text());
            (*it)->setCosto(static_cast<QSpinBox*>(dannoStacked->widget(1))->value());
            (*it)->setBersaglioPrefe(static_cast<QComboBox*>(bersaglioPrefeStacked->widget(1))->currentText());
            (*it)->setCosto(static_cast<QSpinBox*>(costoStacked->widget(1))->value());
            (*it)->setVita(static_cast<QSpinBox*>(vitaStacked->widget(1))->value());
            (*it)->setTempo(static_cast<QSpinBox*>(tempoStacked->widget(1))->value());
            (*it)->setTipoDanno(static_cast<QComboBox*>(tipoDannoStacked->widget(1))->currentText());
            (*it)->setBersagli(static_cast<QComboBox*>(bersagliStacked->widget(1))->currentText());

            if(getType(*it) == "Difesa") {
                Difesa* dif=static_cast<Difesa*>((*it).pointer);
                dif->setDistanza(static_cast<QSpinBox*>(primaSpecialStacked->widget(1))->value());

            }
            else if(getType(*it) == "Attacco") {
                Attacco* att = static_cast<Attacco*>((*it).pointer);
                att->setSpazio(static_cast<QSpinBox*>(primaSpecialStacked->widget(1))->value());
                att->setVelocita(static_cast<QSpinBox*>(secondaSpecialStacked->widget(1))->value());
                att->setTipo(static_cast<QSpinBox*>(terzaSpecialStacked->widget(1))->text());

            }
            else if(getType(*it) == "Eroe") {
                Eroe* er = static_cast<Eroe*>((*it).pointer);
                er->setLivelloMax(static_cast<QSpinBox*>(primaSpecialStacked->widget(1))->value());
                er->setTempoRig(static_cast<QSpinBox*>(secondaSpecialStacked->widget(1))->value());
            }
            return;
        }
    }
}
//metodo per visualizzare i dati realtivi al personaggio scelto
void Window::updateComboBox() {
    //tutti i personaggi
    Container<QString> valNome;
    Container<QString> valDescr;
    Container<int> valDanno;
    Container<QString> valBersaglioPrefe;
    Container<int> valCosto;
    Container<int> valVita;
    Container<int> valTempo;
    Container<QString> valTipoDanno;
    Container<QString> valBersagli;
    Container<QString> typeValues;

    //difesa
    Container<int> valDistanza;

    //attacco
    Container<int> valVelocita;
    Container<int> valSpazio;

    //eroe
    Container<int> valTempoRig;
    Container<int> valLivelloMax;


    for(auto it = pers.begin(); it != pers.end(); ++it) {
        if(valNome.search((*it)->getNome()) == -1) {
            valNome.add((*it)->getNome());
        }
        if(valDescr.search((*it)->getDescrizione()) == -1) {
            valDescr.add((*it)->getDescrizione());
        }
        if(valDanno.search((*it)->getDanno()) == -1) {
            valDanno.add((*it)->getDanno());
        }
        if(valBersaglioPrefe.search((*it)->getBersaglioPrefe()) == -1) {
            valBersaglioPrefe.add((*it)->getBersaglioPrefe());
        }
        if(valCosto.search((*it)->getCosto()) == -1) {
            valCosto.add((*it)->getCosto());
        }
        if(valVita.search((*it)->getVita()) == -1) {
            valVita.add((*it)->getVita());
        }
        if(valTempo.search((*it)->getTempo()) == -1) {
            valTempo.add((*it)->getTempo());
        }
        if(valTipoDanno.search((*it)->getTipoDanno()) == -1) {
            valTipoDanno.add((*it)->getTipoDanno());
        }
        if(valBersagli.search((*it)->getBersagli()) == -1) {
            valBersagli.add((*it)->getBersagli());
        }
        if(getType(*it) == "Difesa") {
            if(valDistanza.search(static_cast<Difesa*>((*it).pointer)->getDistanza()) == -1) {
                valDistanza.add(static_cast<Difesa*>((*it).pointer)->getDistanza());
            }
        }
        if(getType(*it) == "Attacco") {
            Attacco* att = static_cast<Attacco*>((*it).pointer);
            if(valSpazio.search(att->getSpazio()) == -1) {
                valSpazio.add(att->getSpazio());
            }
            if(valVelocita.search(att->getVelocita()) == -1) {
                valVelocita.add(att->getVelocita());
            }

        }
        if(getType(*it) == "Eroe") {
            Eroe* er = static_cast<Eroe*>((*it).pointer);
            if(valTempoRig.search(er->getTempoRig()) == -1) {
                valTempoRig.add(er->getTempoRig());
            }
            if(valLivelloMax.search(er->getLivelloMax()) == -1) {
                valLivelloMax.add(er->getLivelloMax());
            }
        }
        if(typeValues.search(getType(*it)) == -1) {
            typeValues.add(getType(*it));
        }
    }
    sort(valNome.begin(), valNome.end());
    nomeComboBox->clear();
    nomeComboBox->addItem("All");
    for(auto it = valNome.begin(); it != valNome.end(); ++it) {
        if(!(*it).isEmpty()) {
            nomeComboBox->addItem(*it);
        }
    }

    sort(valDescr.begin(), valDescr.end());
    descrComboBox->clear();
    descrComboBox->addItem("All");
    for(auto it = valDescr.begin(); it != valDescr.end(); ++it) {
        descrComboBox->addItem(*it);
    }

    sort(valDanno.begin(), valDanno.end());
    dannoComboBox->clear();
    dannoComboBox->addItem("All");
    for(auto it = valDanno.begin(); it != valDanno.end(); ++it) {

            dannoComboBox->addItem(QString::number(*it));

    }

    sort(valBersaglioPrefe.begin(), valBersaglioPrefe.end());
    bersaglioPrefeComboBox->clear();
    bersaglioPrefeComboBox->addItem("All");
    for(auto it = valBersaglioPrefe.begin(); it != valBersaglioPrefe.end(); ++it) {
        if(!(*it).isEmpty()) {
            bersaglioPrefeComboBox->addItem(*it);
        }
    }

    sort(valCosto.begin(), valCosto.end());
    costoComboBox->clear();
    costoComboBox->addItem("All");
    for(auto it = valCosto.begin(); it != valCosto.end(); ++it) {
        costoComboBox->addItem(QString::number(*it));
    }

    sort(valVita.begin(), valVita.end());
    vitaComboBox->clear();
    vitaComboBox->addItem("All");
    for(auto it = valVita.begin(); it != valVita.end(); ++it) {
        vitaComboBox->addItem(QString::number(*it));
    }

    sort(valTempo.begin(), valTempo.end());
    tempoComboBox->clear();
    tempoComboBox->addItem("All");
    for(auto it = valTempo.begin(); it != valTempo.end(); ++it) {

            tempoComboBox->addItem(QString::number(*it));

    }

    sort(valTipoDanno.begin(), valTipoDanno.end());
    tipoDannoComboBox->clear();
    tipoDannoComboBox->addItem("All");
    for(auto it = valTipoDanno.begin(); it != valTipoDanno.end(); ++it) {
        if(!(*it).isEmpty()) {
            tipoDannoComboBox->addItem(*it);
        }
    }

    sort(valBersagli.begin(), valBersagli.end());
    bersagliComboBox->clear();
    bersagliComboBox->addItem("All");
    for(auto it = valBersagli.begin(); it != valBersagli.end(); ++it) {
        if(!(*it).isEmpty()) {
            bersagliComboBox->addItem(*it);
        }
    }


}

//change the stacked index to the opposite of the current state
void Window::updateStacked() const {
    nomeStacked->setCurrentIndex(!nomeStacked->currentIndex());
    descrStacked->setCurrentIndex(!descrStacked->currentIndex());
    dannoStacked->setCurrentIndex(!dannoStacked->currentIndex());
    bersaglioPrefeStacked->setCurrentIndex(!bersaglioPrefeStacked->currentIndex());
    costoStacked->setCurrentIndex(!costoStacked->currentIndex());
    vitaStacked->setCurrentIndex(!vitaStacked->currentIndex());
    tempoStacked->setCurrentIndex(!tempoStacked->currentIndex());
    tipoDannoStacked->setCurrentIndex(!tipoDannoStacked->currentIndex());
    bersagliStacked->setCurrentIndex(!bersagliStacked->currentIndex());
    primaSpecialStacked->setCurrentIndex(!primaSpecialStacked->currentIndex());
    secondaSpecialStacked->setCurrentIndex(!secondaSpecialStacked->currentIndex());
    terzaSpecialStacked->setCurrentIndex(!terzaSpecialStacked->currentIndex());

}

//method to update the card viewer "zone" by using the passed parameter as cardID value or to check the action type
void Window::updateViewer(QString currentItem) {
    if(currentItem == "deleted") {
        static_cast<QLabel*>(nomeStacked->widget(0))->clear();
        static_cast<QLineEdit*>(nomeStacked->widget(1))->clear();

        static_cast<QLabel*>(descrStacked->widget(0))->clear();
        static_cast<QLineEdit*>(descrStacked->widget(1))->clear();

        static_cast<QLabel*>(dannoStacked->widget(0))->clear();
        static_cast<QSpinBox*>(dannoStacked->widget(0))->setValue(0);

        static_cast<QLabel*>(costoStacked->widget(0))->clear();
        static_cast<QSpinBox*>(costoStacked->widget(1))->setValue(0);


        static_cast<QLabel*>(bersaglioPrefeStacked->widget(0))->clear();
        static_cast<QLineEdit*>(bersaglioPrefeStacked->widget(1))->clear();

        static_cast<QLabel*>(vitaStacked->widget(0))->clear();
        static_cast<QSpinBox*>(vitaStacked->widget(1))->setValue(0);

        static_cast<QLabel*>(tempoStacked->widget(0))->clear();
        static_cast<QSpinBox*>(tempoStacked->widget(1))->setValue(0);

        static_cast<QLabel*>(bersagliStacked->widget(0))->clear();
        static_cast<QLineEdit*>(bersagliStacked->widget(1))->clear();

        //static_cast<QLabel*>(textStacked->widget(0))->clear();
       // static_cast<QLineEdit*>(textStacked->widget(1))->clear();
        static_cast<QLabel*>(primaSpecialStacked->widget(0))->clear();
        static_cast<QLineEdit*>(primaSpecialStacked->widget(1))->clear();
        static_cast<QLabel*>(secondaSpecialStacked->widget(0))->clear();
        static_cast<QLineEdit*>(secondaSpecialStacked->widget(1))->clear();
        static_cast<QLabel*>(terzaSpecialStacked->widget(0))->clear();
        static_cast<QLineEdit*>(terzaSpecialStacked->widget(1))->clear();
        persID->clear();
        persType->clear();
    }
    else {
        for(auto it = pers.begin(); it != pers.end(); ++it) {
            if((*it)->getId() == currentItem) {
                static_cast<QLabel*>(nomeStacked->widget(0))->setText((*it)->getNome());
                static_cast<QLineEdit*>(nomeStacked->widget(1))->setText((*it)->getNome());
                static_cast<QLabel*>(descrStacked->widget(0))->setText((*it)->getDescrizione());
                static_cast<QLineEdit*>(descrStacked->widget(1))->setText((*it)->getDescrizione());
                static_cast<QLabel*>(dannoStacked->widget(0))->setText(QString::number((*it)->getDanno()));
                static_cast<QSpinBox*>(dannoStacked->widget(1))->setValue((*it)->getDanno());

                static_cast<QLabel*>(bersaglioPrefeStacked->widget(0))->setText((*it)->getBersaglioPrefe());
                static_cast<QLineEdit*>(bersaglioPrefeStacked->widget(1))->setText((*it)->getBersaglioPrefe());
                static_cast<QLabel*>(costoStacked->widget(0))->setText(QString::number((*it)->getCosto()));
                static_cast<QSpinBox*>(costoStacked->widget(1))->setValue((*it)->getCosto());
                static_cast<QLabel*>(vitaStacked->widget(0))->setText(QString::number((*it)->getVita()));
                static_cast<QSpinBox*>(vitaStacked->widget(1))->setValue((*it)->getVita());
                static_cast<QLabel*>(tempoStacked->widget(0))->setText(QString::number((*it)->getTempo()));
                static_cast<QSpinBox*>(tempoStacked->widget(1))->setValue((*it)->getTempo());
                static_cast<QLabel*>(bersagliStacked->widget(0))->setText((*it)->getBersagli());
                static_cast<QLineEdit*>(bersagliStacked->widget(1))->setText((*it)->getBersagli());

                //static_cast<QLabel*>(textStacked->widget(0))->setText((*it)->getText());
                //static_cast<QLineEdit*>(textStacked->widget(1))->setText((*it)->getText());
                persType->setText(getType(*it));
                if(persType->text() == "Difesa") {
                    Difesa* dif= static_cast<Difesa*>((*it).pointer);
                    primaSpecialLabel->setText("<b>Distanza:<b/>");
                    static_cast<QLabel*>(primaSpecialStacked->widget(0))->setText(QString::number(dif->getDistanza()));
                    static_cast<QSpinBox*>(primaSpecialStacked->widget(1))->setValue(dif->getDistanza());
                    setStackedVisible(true, false, false);
                }
                else if(persType->text() == "Attacco") {
                    Attacco* att = static_cast<Attacco*>((*it).pointer);
                    primaSpecialLabel->setText("<b>Spazio occupato:<b/>");
                    secondaSpecialLabel->setText("<b>Velocita di movimento:<b/>");
                    terzaSpecialLabel->setText("<b>Tipo:<b/>");
                    static_cast<QLabel*>(primaSpecialStacked->widget(0))->setText(QString::number(att->getSpazio()));
                    static_cast<QSpinBox*>(primaSpecialStacked->widget(1))->setValue(att->getSpazio());
                    static_cast<QLabel*>(secondaSpecialStacked->widget(0))->setText(QString::number(att->getVelocita()));
                    static_cast<QSpinBox*>(secondaSpecialStacked->widget(1))->setValue(att->getVelocita());
                    static_cast<QLabel*>(terzaSpecialStacked->widget(0))->setText(att->getTipo());
                    static_cast<QLineEdit*>(terzaSpecialStacked->widget(1))->setText(att->getTipo());
                    setStackedVisible(true, true, true);
                }

                else {
                    Eroe* er = static_cast<Eroe*>((*it).pointer);
                    primaSpecialLabel->setText("<b>Livello massimo:<b/>");
                    secondaSpecialLabel->setText("<b>Tempo rigenerazione:<b/>");
                    static_cast<QLabel*>(primaSpecialStacked->widget(0))->setText(QString::number(er->getLivelloMax()));
                    static_cast<QSpinBox*>(primaSpecialStacked->widget(1))->setValue(er->getLivelloMax());
                    static_cast<QLabel*>(secondaSpecialStacked->widget(0))->setText(QString::number(er->getTempoRig()));
                    static_cast<QSpinBox*>(secondaSpecialStacked->widget(1))->setValue(er->getTempoRig());
                    setStackedVisible(true, true, false);
                }
                return;
            }
        }
    }
}

//constructor
Window::Window(QWidget *parent):
    QWidget(parent),

    nomeComboBox(new QComboBox()),
    descrComboBox(new QComboBox()),
    dannoComboBox(new QComboBox()),
    bersaglioPrefeComboBox(new QComboBox()),
    costoComboBox(new QComboBox()),
    vitaComboBox(new QComboBox()),
    tempoComboBox(new QComboBox()),
    tipoDannoComboBox(new QComboBox()),
    bersagliComboBox(new QComboBox()),
    typeComboBox(new QComboBox()),
    persID(new QLabel()),
    persType(new QLabel()),
    primaSpecialLabel(new QLabel()),
    secondaSpecialLabel(new QLabel()),
    terzaSpecialLabel(new QLabel()),


    textBox(new QLineEdit()),


    nuovoPersButton(new QPushButton("Nuovo\na Personaggio")),
    cancPersButton(new QPushButton("Cancella\na Personaggio")),
    modificaPersButton(new QPushButton("Modifica\na Personaggio")),


    nomeStacked(new QStackedWidget()),
    descrStacked(new QStackedWidget()),
    dannoStacked(new QStackedWidget()),
    bersaglioPrefeStacked(new QStackedWidget()),
    costoStacked(new QStackedWidget()),
    vitaStacked(new QStackedWidget()),
    tempoStacked(new QStackedWidget()),
    tipoDannoStacked(new QStackedWidget()),
    bersagliStacked(new QStackedWidget()),
    primaSpecialStacked(new QStackedWidget()),
    secondaSpecialStacked(new QStackedWidget()),
    terzaSpecialStacked(new QStackedWidget()),
    typeStacked(new QStackedWidget())
     {

    QListWidget* persList = new QListWidget();
    QLabel* persTrovati = new QLabel();
    //loadFromFile("../qontainer/default.json", cardsList, persTrovati); //uncomment the line to load a default file

    QGroupBox* persGroup = new QGroupBox("Cerca Personaggio");
    persGroup->setMinimumWidth(persGroupWidth);

    QHBoxLayout* ricercaPersLayout = new QHBoxLayout();
    ricercaPersLayout->setSizeConstraint(QLayout::SetMinimumSize);

    textBox->setMinimumWidth(defaultWidth);
    QScrollArea* listScroll = new QScrollArea();
    listScroll->setWidgetResizable(true);
    listScroll->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    listScroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    listScroll->setMinimumWidth(defaultWidth);
    QVBoxLayout* listVBox = new QVBoxLayout();
    listVBox->addWidget(textBox);
    listVBox->addWidget(listScroll);

    QPushButton* clearButton = new QPushButton("Clear\nSelect");
    clearButton->setMinimumSize(dimButton);
    clearButton->setMaximumSize(dimButton);
    clearButton->setEnabled(false);
    persTrovati->setAlignment(Qt::AlignCenter);
    QPushButton* resetButton = new QPushButton("Reset\nFilters");
    resetButton->setMinimumSize(dimButton);
    resetButton->setMaximumSize(dimButton);

    QHBoxLayout* extraRow = new QHBoxLayout();
    extraRow->addWidget(clearButton);
    extraRow->addWidget(persTrovati);
    extraRow->addWidget(resetButton);

    nomeComboBox->setMinimumWidth(defaultWidth);
    descrComboBox->setMinimumWidth(defaultWidth);
    dannoComboBox->setMinimumWidth(defaultWidth);
    bersaglioPrefeComboBox->setMinimumWidth(defaultWidth);
    costoComboBox->setMinimumWidth(defaultWidth);
    vitaComboBox->setMinimumWidth(defaultWidth);
    tempoComboBox->setMinimumWidth(defaultWidth);
    bersagliComboBox->setMinimumWidth(defaultWidth);
    typeComboBox->setMinimumWidth(defaultWidth);

    QFormLayout* filtersLayout = new QFormLayout();

    filtersLayout->addRow("Nome", nomeComboBox);
    filtersLayout->addRow("Descrizione", descrComboBox);
    filtersLayout->addRow("Type", typeComboBox);
    filtersLayout->addRow("Danno", dannoComboBox);
    filtersLayout->addRow("Bersaglio preferito", bersaglioPrefeComboBox);
    filtersLayout->addRow("Costo", costoComboBox);
    filtersLayout->addRow("Vita", vitaComboBox);
    filtersLayout->addRow("Tempo", tempoComboBox);
    filtersLayout->addRow("Tipo di danno", tipoDannoComboBox);
    filtersLayout->addRow("Bersagli", bersagliComboBox);

    filtersLayout->addItem(extraRow);

    ricercaPersLayout->addLayout(listVBox);
    ricercaPersLayout->addLayout(filtersLayout);
    persGroup->setLayout(ricercaPersLayout);

    filtraPers(persList, persTrovati);
    listScroll->setWidget(persList);

    QGroupBox* operationsGroup = new QGroupBox("Operations");

    QFormLayout* operationsForm = new QFormLayout();
    operationsForm->setSizeConstraint(QLayout::SetMinimumSize);

    nuovoPersButton->setMinimumSize(dimButton);
    nuovoPersButton->setMaximumSize(dimButton);

    cancPersButton->setMinimumSize(dimButton);
    cancPersButton->setMaximumSize(dimButton);
    cancPersButton->setEnabled(false);

    modificaPersButton->setMinimumSize(dimButton);
    modificaPersButton->setMaximumSize(dimButton);
    modificaPersButton->setEnabled(false);

    QPushButton* helpButton = new QPushButton("Help");
    helpButton->setMinimumSize(dimButton);
    helpButton->setMaximumSize(dimButton);

    QPushButton* saveButton = new QPushButton("Save");
    saveButton->setMinimumSize(dimButton);
    saveButton->setMaximumSize(dimButton);
    saveButton->setToolTip("Save the current cards in a file");

    QPushButton* loadButton = new QPushButton("Load");
    loadButton->setMinimumSize(dimButton);
    loadButton->setMaximumSize(dimButton);
    loadButton->setToolTip("Replace the current cards with\nthe ones from another file");

    QLabel* fileLabel = new QLabel();
    fileLabel->setAlignment(Qt::AlignHCenter);
    fileLabel->setWordWrap(true);

    QFrame* horizontalSplit = new QFrame();
    horizontalSplit->setFrameShape(QFrame::HLine);
    horizontalSplit->setFrameShadow(QFrame::Raised);
    horizontalSplit->setLineWidth(0);
    horizontalSplit->setMidLineWidth(0);

    operationsForm->addRow(nuovoPersButton, modificaPersButton);
    operationsForm->addRow(cancPersButton);
    operationsForm->addRow(horizontalSplit);
    operationsForm->addRow(horizontalSplit);
    operationsForm->addRow(saveButton, loadButton);
    operationsForm->addRow(fileLabel);
    operationsGroup->setLayout(operationsForm);

    QGroupBox* cardViewerGroup = new QGroupBox("Card viewer");
    cardViewerGroup->setMinimumWidth(defaultWidth);

    QLabel* nomeLabel = new QLabel();
    nomeLabel->setAlignment(Qt::AlignVCenter);
    nomeLabel->setWordWrap(true);
    QLineEdit* nomeLineEdit = new QLineEdit();
    nomeStacked->addWidget(nomeLabel);
    nomeStacked->addWidget(nomeLineEdit);

    persType->setAlignment(Qt::AlignVCenter);
    persType->setWordWrap(true);

    QLabel* descrLabel = new QLabel();
    descrLabel->setAlignment(Qt::AlignVCenter);
    descrLabel->setWordWrap(true);
    QLineEdit* descrLineEdit = new QLineEdit();
    descrStacked->addWidget(descrLabel);
    descrStacked->addWidget(descrLineEdit);

    QLabel* dannoLabel = new QLabel();
    dannoLabel->setAlignment(Qt::AlignVCenter);
    dannoLabel->setWordWrap(true);
    QSpinBox* dannoSpinBox = new QSpinBox();
    dannoSpinBox->setMaximum(999);
    dannoSpinBox->setSingleStep(1);
    dannoStacked->addWidget(dannoLabel);
    dannoStacked->addWidget(dannoSpinBox);

    QLabel* bersaglioPrefeLabel = new QLabel();
    bersaglioPrefeLabel->setAlignment(Qt::AlignVCenter);
    bersaglioPrefeLabel->setWordWrap(true);
    QLineEdit* bersaglioPrefeLineEdit = new QLineEdit();
    bersaglioPrefeStacked->addWidget(bersaglioPrefeLabel);
    bersaglioPrefeStacked->addWidget(bersaglioPrefeLineEdit);

    QLabel* costoLabel = new QLabel();
    costoLabel->setAlignment(Qt::AlignVCenter);
    costoLabel->setWordWrap(true);
    QSpinBox* costoSpinBox = new QSpinBox();
    costoSpinBox->setMaximum(999);
    costoSpinBox->setSingleStep(1);
    costoStacked->addWidget(costoLabel);
    costoStacked->addWidget(costoSpinBox);

    QLabel* vitaLabel = new QLabel();
     vitaLabel->setAlignment(Qt::AlignVCenter);
     vitaLabel->setWordWrap(true);
    QSpinBox*  vitaSpinBox = new QSpinBox();
     vitaSpinBox->setMaximum(999);
     vitaSpinBox->setSingleStep(1);
     vitaStacked->addWidget( vitaLabel);
     vitaStacked->addWidget( vitaSpinBox);

     QLabel* tempoLabel = new QLabel();
      tempoLabel->setAlignment(Qt::AlignVCenter);
      tempoLabel->setWordWrap(true);
     QSpinBox*  tempoSpinBox = new QSpinBox();
      tempoSpinBox->setMaximum(999);
      tempoSpinBox->setSingleStep(1);
      tempoStacked->addWidget(tempoLabel);
      tempoStacked->addWidget(tempoSpinBox);

       QLabel* bersagliLabel = new QLabel();
      bersagliLabel->setAlignment(Qt::AlignVCenter);
      bersagliLabel->setWordWrap(true);
      QLineEdit* bersagliLineEdit = new QLineEdit();
      bersagliStacked->addWidget(bersagliLabel);
      bersagliStacked->addWidget(bersagliLineEdit);

      QLabel* tipoDannoLabel = new QLabel();
     tipoDannoLabel->setAlignment(Qt::AlignVCenter);
     tipoDannoLabel->setWordWrap(true);
     QLineEdit* tipoDannoLineEdit = new QLineEdit();
     tipoDannoStacked->addWidget(tipoDannoLabel);
     tipoDannoStacked->addWidget(tipoDannoLineEdit);
    /*
    QLabel* firstLabel = new QLabel();
    firstLabel->setAlignment(Qt::AlignVCenter);
    firstLabel->setWordWrap(true);
    QSpinBox* primaSpecialSpinBox = new QSpinBox();
    primaSpecialSpinBox->setMaximum(999);
    primaSpecialSpinBox->setSingleStep(1);
    primaSpecialStacked->addWidget(firstLabel);
    primaSpecialStacked->addWidget(primaSpecialSpinBox);

    QLabel* flavorLabel = new QLabel();
    flavorLabel->setAlignment(Qt::AlignVCenter);
    flavorLabel->setWordWrap(true);
    QLineEdit* flavorLineEdit = new QLineEdit();
    flavorStacked->addWidget(flavorLabel);
    flavorStacked->addWidget(flavorLineEdit);

    QLabel* nameLabel = new QLabel();
    nameLabel->setAlignment(Qt::AlignVCenter);
    nameLabel->setWordWrap(true);
    QLineEdit* nameLineEdit = new QLineEdit();
    nameStacked->addWidget(nameLabel);
    nameStacked->addWidget(nameLineEdit);

    QLabel* rarityLabel = new QLabel();
    rarityLabel->setAlignment(Qt::AlignVCenter);
    rarityLabel->setWordWrap(true);
    QLineEdit* rarityLineEdit = new QLineEdit();
    rarityStacked->addWidget(rarityLabel);
    rarityStacked->addWidget(rarityLineEdit);

    QLabel* secondLabel = new QLabel();
    secondLabel->setAlignment(Qt::AlignVCenter);
    secondLabel->setWordWrap(true);
    QSpinBox* secondaSpecialSpinBox = new QSpinBox();
    secondaSpecialSpinBox->setMaximum(999);
    secondaSpecialSpinBox->setSingleStep(1);
    secondaSpecialStacked->addWidget(secondLabel);
    secondaSpecialStacked->addWidget(secondaSpecialSpinBox);

    QLabel* setLabel = new QLabel();
    setLabel->setAlignment(Qt::AlignVCenter);
    setLabel->setWordWrap(true);
    QLineEdit* setLineEdit = new QLineEdit();
    setStacked->addWidget(setLabel);
    setStacked->addWidget(setLineEdit);

    QLabel* textLabel = new QLabel();
    textLabel->setAlignment(Qt::AlignVCenter);
    textLabel->setWordWrap(true);
    QLineEdit* textLineEdit = new QLineEdit();
    textStacked->addWidget(textLabel);
    textStacked->addWidget(textLineEdit);

    QLabel* thirdLabel = new QLabel();
    thirdLabel->setAlignment(Qt::AlignVCenter);
    thirdLabel->setWordWrap(true);
    QLineEdit* terzaSpecialLineEdit = new QLineEdit();
    terzaSpecialStacked->addWidget(thirdLabel);
    terzaSpecialStacked->addWidget(terzaSpecialLineEdit);
*/
    QComboBox* typeEditComboBox = new QComboBox();
    typeEditComboBox->addItem(QString());
    typeEditComboBox->addItem("Attacco");
    typeEditComboBox->addItem("Difesa");
    typeEditComboBox->addItem("Eroe");

    typeStacked->addWidget(persType);
    typeStacked->addWidget(typeEditComboBox);

    QPushButton* confirmAddButton = new QPushButton("Conferma\n Aggiunta");
    confirmAddButton->setMinimumSize(dimButton);
    confirmAddButton->setMaximumSize(dimButton);

    QPushButton* confirmEditButton = new QPushButton("Conferma\n Modficia");
    confirmEditButton->setMinimumSize(dimButton);
    confirmEditButton->setMaximumSize(dimButton);

    confirmStacked->addWidget(confirmAddButton);
    confirmStacked->addWidget(confirmEditButton);
    confirmStacked->setVisible(false);

    QPushButton* cancelButton = new QPushButton("Cancella");
    cancelButton->setMinimumSize(dimButton);
    cancelButton->setMaximumSize(dimButton);
    cancelButton->setVisible(false);

    QFormLayout* cardViewLayout = new QFormLayout();
    cardViewLayout->setSizeConstraint(QLayout::SetMinimumSize);
    cardViewLayout->addRow("<b>Nome:</b>", nomeStacked);
    cardViewLayout->addRow("<b>Descrizione:</b", descrStacked);
    cardViewLayout->addRow("<b>Danno:</b>", dannoStacked);
    cardViewLayout->addRow("<b>Bersaglio Preferito:</b>", bersaglioPrefeStacked);
    cardViewLayout->addRow("<b>Costo:</b>", costoStacked);
    cardViewLayout->addRow("<b>Vita:</b>", vitaStacked);
    cardViewLayout->addRow("<b>Tempo:</b>", tempoStacked);
    cardViewLayout->addRow("<b>Bersagli:</b>", bersagliStacked);
    cardViewLayout->addRow("<b>Tipo danno:</b>", tipoDannoStacked);
    cardViewLayout->addRow("<b>Tipo:</b>", typeStacked);
    cardViewLayout->addRow(primaSpecialLabel, primaSpecialStacked);
    cardViewLayout->addRow(secondaSpecialLabel, secondaSpecialStacked);
    cardViewLayout->addRow(terzaSpecialLabel, terzaSpecialStacked);
    cardViewLayout->addRow(persID);
    cardViewLayout->addRow(confirmStacked, cancelButton);
    cardViewerGroup->setLayout(cardViewLayout);

    setStackedVisible(false, false, false);

    Container<QComboBox*> comboBoxContainer;
    comboBoxContainer.add(nomeComboBox);
    comboBoxContainer.add(descrComboBox);
    comboBoxContainer.add(dannoComboBox);
    comboBoxContainer.add(bersaglioPrefeComboBox);
    comboBoxContainer.add(costoComboBox);
    comboBoxContainer.add(vitaComboBox);
    comboBoxContainer.add(tempoComboBox);
    comboBoxContainer.add(bersagliComboBox);
    comboBoxContainer.add(tipoDannoComboBox),
    comboBoxContainer.add(typeComboBox);

    //whenever a value changes on any QComboBox, it triggers a refresh on the cards list
    for(auto it = comboBoxContainer.begin(); it != comboBoxContainer.end(); ++it) {
        connect(*it, static_cast<void (QComboBox::*)(int index)>(&QComboBox::currentIndexChanged),
            [this, persList, persTrovati]{
            setButton(true, false, false);
            filtraPers(persList, persTrovati);
        });
    }

    //whenever the "Add a Card" button is pressed, the add a card panel appears under the Card Viewer zone

    connect(nuovoPersButton, &QPushButton::clicked, [this, cancelButton, persList, clearButton, confirmAddButton]{
       cancelButton->setVisible(true);
       persList->reset();
       persList->setEnabled(false);
       clearButton->setEnabled(false);
       updateViewer("deleted");
       setButton(false, false, false);
       confirmStacked->setCurrentIndex(0);
       typeStacked->setCurrentIndex(1);
       static_cast<QComboBox*>(typeStacked->widget(1))->setVisible(true);
       setStackedVisible(false, false, false);
       confirmAddButton->setEnabled(false);
       updateStacked();
    });

    //whenever the "Cancel" button is pressed, undo the current action
    connect(cancelButton, &QPushButton::clicked, [this, cancelButton, persList, clearButton, confirmAddButton]{
        updateViewer("deleted");
        updateStacked();
        persList->setEnabled(true);
        persList->reset();
        clearButton->setEnabled(false);
        cancelButton->setVisible(false);
        typeStacked->setCurrentIndex(0);
        setStackedVisible(false, false, false);
        setButton(true, false, false);
    });

    //whenever an element is clicked on the cards list, it triggers a visual refresh on the card view panel
    connect(persList, &QListWidget::currentRowChanged, [this, persList, clearButton]{
        setButton(false, true, true);
        clearButton->setEnabled(true);
        persID->setText(persList->currentItem()->data(Qt::UserRole).toString());
        updateViewer(persList->currentItem()->data(Qt::UserRole).toString());
    });

    //whenever the Clear Select button is pressed, the current selection is cancelled
    connect(clearButton, &QPushButton::clicked, [this, persList, clearButton]{
        setButton(true, false, false);
        persList->reset();
        clearButton->setEnabled(false);
        updateViewer("deleted");
    });

    //whenever the "Confirm Add" button is pressed, the new item is created, insert into the cards Container and the whole GUI is updated
    connect(confirmAddButton, &QPushButton::clicked, [this, cancelButton, persList, persTrovati, clearButton, typeEditComboBox]{
        QString toUse = QString("NEW_000");
        for(auto it = pers.begin(); it != pers.end(); ++it) {
            if((*it)->getId().startsWith("NEW_") && toUse.right(3).toInt() <= (*it)->getId().right(3).toInt()) {
                QString pos = QString::number((*it)->getId().right(3).toInt()+1);
                unsigned int toSize = toUse.size()-pos.size();
                toUse = toUse.left(toSize).append(pos);
            }
        }
        persID->setText(toUse);
        if(typeEditComboBox->currentText() == "Difesa") {
            pers.add(new Difesa(static_cast<QLineEdit*>(nomeStacked->widget(1))->text(),
                               static_cast<QLineEdit*>(descrStacked->widget(1))->text(),
                               static_cast<QSpinBox*>(dannoStacked->widget(1))->value(),
                               static_cast<QLineEdit*>(bersaglioPrefeStacked->widget(1))->text(),

                               static_cast<QSpinBox*>(costoStacked->widget(1))->value(),

                               static_cast<QSpinBox*>(vitaStacked->widget(1))->value(),
                               static_cast<QSpinBox*>(tempoStacked->widget(1))->value(),
                               static_cast<QLineEdit*>(bersagliStacked->widget(1))->text(),
                                static_cast<QLineEdit*>(tipoDannoStacked->widget(1))->text(),
                               toUse,
                               static_cast<QSpinBox*>(primaSpecialStacked->widget(1))->value()
                          ));
        }
        else if(typeEditComboBox->currentText() == "Attacco") {
            pers.add(new Attacco(static_cast<QLineEdit*>(nomeStacked->widget(1))->text(),
                                 static_cast<QLineEdit*>(descrStacked->widget(1))->text(),
                                 static_cast<QSpinBox*>(dannoStacked->widget(1))->value(),
                                 static_cast<QLineEdit*>(bersaglioPrefeStacked->widget(1))->text(),

                                 static_cast<QSpinBox*>(costoStacked->widget(1))->value(),

                                 static_cast<QSpinBox*>(vitaStacked->widget(1))->value(),
                                 static_cast<QSpinBox*>(tempoStacked->widget(1))->value(),
                                 static_cast<QLineEdit*>(bersagliStacked->widget(1))->text(),
                                  static_cast<QLineEdit*>(tipoDannoStacked->widget(1))->text(),
                                   toUse,
                                static_cast<QSpinBox*>(primaSpecialStacked->widget(1))->value(),
                                 static_cast<QSpinBox*>(secondaSpecialStacked->widget(1))->value(),
                                 static_cast<QLineEdit*>(terzaSpecialStacked->widget(1))->text()
                          ));
        }


        else if(typeEditComboBox->currentText() == "Eroe") {
            pers.add(new Eroe(static_cast<QLineEdit*>(nomeStacked->widget(1))->text(),
                              static_cast<QLineEdit*>(descrStacked->widget(1))->text(),
                              static_cast<QSpinBox*>(dannoStacked->widget(1))->value(),
                              static_cast<QLineEdit*>(bersaglioPrefeStacked->widget(1))->text(),

                              static_cast<QSpinBox*>(costoStacked->widget(1))->value(),

                              static_cast<QSpinBox*>(vitaStacked->widget(1))->value(),
                              static_cast<QSpinBox*>(tempoStacked->widget(1))->value(),
                              static_cast<QLineEdit*>(bersagliStacked->widget(1))->text(),
                              static_cast<QLineEdit*>(tipoDannoStacked->widget(1))->text(),
                              toUse,
                              static_cast<QSpinBox*>(primaSpecialStacked->widget(1))->value(),
                              static_cast<QSpinBox*>(secondaSpecialStacked->widget(1))->value()

                          ));
        }
        cancelButton->setVisible(false);
        setButton(true, false, false);
        clearButton->setEnabled(false);
        updateComboBox();
        updateStacked();
        updateViewer(persID->text());
        static_cast<QComboBox*>(typeStacked->widget(1))->setCurrentIndex(0);
        typeStacked->setCurrentIndex(0);
        persList->setEnabled(true);
        filtraPers(persList, persTrovati);
        resetFilters();
    });


    //whenever the edit confirmation is sent, add the card to the card list and refresh both the left list and the filters
    connect(confirmEditButton, &QPushButton::clicked, [this, cancelButton, persList, persTrovati, clearButton]{
        updatePers(persList->currentItem()->data(Qt::UserRole).toString());
        updateViewer(persList->currentItem()->data(Qt::UserRole).toString());
        cancelButton->setVisible(false);
        setButton(true, false, false);
        clearButton->setEnabled(false);
        persList->setEnabled(true);
        updateComboBox();
        updateStacked();
        filtraPers(persList, persTrovati);
        resetFilters();
    });

    //whenever the Delete a Card button is pressed, the selected Card is removed and the QListWidget updated
    connect(cancPersButton, &QPushButton::clicked, [this, persList, persTrovati, clearButton]{
        for(auto it = pers.begin(); it != pers.end(); ++it) {
            if((*it)->getId() == persList->currentItem()->data(Qt::UserRole).toString()) {
                pers.erase(pers.search(*it));
                break;
            }
        }
        updateViewer("deleted");
        updateComboBox();
        setButton(true, false, false);
        clearButton->setEnabled(false);
        filtraPers(persList, persTrovati);
        resetFilters();
    });

    //whenever the Edit a Card button is pressed, the state of every QStackedWidget is changed
    connect(modificaPersButton, &QPushButton::clicked, [this, cancelButton, persList]{
        cancelButton->setVisible(true);
        setButton(false, false, false);
        persList->setEnabled(false);
        confirmStacked->setCurrentIndex(1);
        updateStacked();
    });

    //whenever the Save button is pressed, a dialog opens, letting the user to choose a file where to save the current cards to
    connect(loadButton, &QPushButton::clicked, [this, persList, persTrovati, fileLabel]{
        QFileDialog dialog(this);
        dialog.setNameFilter("*.json");
        QString fileName = dialog.getOpenFileName(this, "Get cards from a file", "", "Json File (*.json)");
        if(leggiDaFile(fileName, persList, persTrovati)) {
            fileLabel->setText("Loaded successfully");
        }
        else {
            fileLabel->setText("Can't open the file");
        }
        updateViewer("deleted");
        resetFilters();
        filtraPers(persList, persTrovati);
    });

    //whenever the reset button is pressed, all the filters are set to "All", resetting the view
    connect(resetButton, &QPushButton::clicked, [this]{
        resetFilters();
    });

    //whenever the Load button is pressed, a dialog opens, letting the user to choose a file where to load the cards from
    connect(saveButton, &QPushButton::clicked, [this, fileLabel]{
        QFileDialog dialog(this);
        dialog.setNameFilter("*.json");
        QString fileName = dialog.getSaveFileName(this, "Save current cards", "", "Json File (*.json)");
        if(!fileName.endsWith(".json")) {
            fileName += ".json";
        }
        QFile saveLocation(fileName);

        QJsonArray cardsArray;
        for(auto it = pers.begin(); it != pers.end(); ++it) {
            QJsonObject cardSingle;
            cardSingle.insert("nome", QJsonValue::fromVariant((*it)->getNome()));
            cardSingle.insert("descr", QJsonValue::fromVariant((*it)->getDescrizione()));
            cardSingle.insert("danno", QJsonValue::fromVariant((*it)->getDanno()));
            cardSingle.insert("bersaglioPrefe", QJsonValue::fromVariant((*it)->getBersaglioPrefe()));
            cardSingle.insert("costo", QJsonValue::fromVariant((*it)->getCosto()));
            cardSingle.insert("vita", QJsonValue::fromVariant((*it)->getVita()));
            cardSingle.insert("tempo", QJsonValue::fromVariant((*it)->getTempo()));
            cardSingle.insert("tipoDanno", QJsonValue::fromVariant((*it)->getTipoDanno()));
            cardSingle.insert("bersagli", QJsonValue::fromVariant((*it)->getBersagli()));
            cardSingle.insert("id", QJsonValue::fromVariant((*it)->getId()));

            if(getType(*it) == "Difesa") {
                cardSingle.insert("type", QJsonValue::fromVariant("Difesa"));
                cardSingle.insert("distanza", QJsonValue::fromVariant(static_cast<Difesa*>((*it).pointer)->getDistanza()));
            }
            else if(getType(*it) == "Attacco") {
                Attacco* att = static_cast<Attacco*>((*it).pointer);
                cardSingle.insert("type", QJsonValue::fromVariant("Attacco"));
                cardSingle.insert("spazio", QJsonValue::fromVariant(att->getSpazio()));
                cardSingle.insert("velocita", QJsonValue::fromVariant(att->getVelocita()));
                cardSingle.insert("tipo", QJsonValue::fromVariant(att->getTipo()));
            }

            else {
                Eroe* er = static_cast<Eroe*>((*it).pointer);
                cardSingle.insert("type", QJsonValue::fromVariant("Eroe"));
                cardSingle.insert("livelloMax", QJsonValue::fromVariant(er->getLivelloMax()));
                cardSingle.insert("tempoRig", QJsonValue::fromVariant(er->getTempoRig()));
            }
            cardsArray.append(cardSingle);
        }

        QJsonObject toInsert;
        toInsert.insert("pers", cardsArray);
        QJsonDocument doc(toInsert);
        if(!saveLocation.open(QIODevice::WriteOnly)) {
            fileLabel->setText("File non letto");
            return;
        }
        saveLocation.write(doc.toJson());
        fileLabel->setText("Salvato");
    });

    //whenever the value on the text field changes, it triggers a refresh on the cards list
    connect(textBox, &QLineEdit::textChanged, [this, persList, persTrovati]{
        setButton(true, false, false);
        filtraPers(persList, persTrovati);
    });

    //whenever the type combobox value on Add a Card changes, show different input fields based on the type
    connect(typeEditComboBox, static_cast<void (QComboBox::*)(int index)>(&QComboBox::currentIndexChanged),
        [this, confirmAddButton, typeEditComboBox] {
            if(typeEditComboBox->currentText() == "Hero") {
                primaSpecialLabel->setText("<b>Armor:</b>");
                setStackedVisible(true, false, false);
                confirmAddButton->setEnabled(true);
            }
            else if(typeEditComboBox->currentText() == "Minion") {
                primaSpecialLabel->setText("<b>Attack:</b>");
                secondaSpecialLabel->setText("<b>Health:</b>");
                terzaSpecialLabel->setText("<b>Tribe:</b>");
                setStackedVisible(true, true, true);
                confirmAddButton->setEnabled(true);
            }
            else if(typeEditComboBox->currentText() == "Spell") {
                setStackedVisible(false, false, false);
                confirmAddButton->setEnabled(true);
            }
            else if(typeEditComboBox->currentText() == "Weapon") {
                primaSpecialLabel->setText("<b>Attack:</b>");
                secondaSpecialLabel->setText("<b>Durability:</b>");
                setStackedVisible(true, true, false);
                confirmAddButton->setEnabled(true);
            }
            else {
                confirmAddButton->setEnabled(false);
                setStackedVisible(false, false, false);
            }
    });

    QGridLayout* grid = new QGridLayout();
    grid->addWidget(persGroup, 0, 0);
    grid->addWidget(operationsGroup, 0, 1);
    grid->addWidget(cardViewerGroup, 0, 2);
    setLayout(grid);
    setWindowTitle("Qontainer");
}
