#include <view/window.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <iostream>

Window::Window(QWidget *parent):
   QWidget (parent){

this->setMaximumWidth(700);
    this->setMaximumHeight(1700);
this->setMinimumHeight(1700);
this->setWindowTitle("I personaggi di Clash of Clans");


//prima riga
//pulsanti layout orizzontale di bottoni
    cerca=new QPushButton("Cerca");
    cerca->setStyleSheet("background-color:#ffc1e3; color:#000;border: 2px solid #bf5f82;");

    aggiungi = new QPushButton("Aggiungi");
    aggiungi->setStyleSheet("background-color:#ffc1e3; color:#000; border: 2px solid #bf5f82;");
    aggiungi->setMinimumSize(75,35);
    aggiungi->setMaximumSize(75,35);

    rimuovi = new QPushButton("Rimuovi");
    rimuovi->setStyleSheet("background-color:#ff7961; color:#000; border: 2px solid #ba000d;");
    rimuovi->setVisible(false);

    modifica = new QPushButton("Modifica");
    modifica->setStyleSheet("background-color:#ffc1e3; color:#000; border: 2px solid #bf5f82;");
    modifica->setVisible(false);

    conferma = new QPushButton("Conferma");
    conferma->setStyleSheet("background-color:#ffc1e3; color:#000; border: 2px solid #bf5f82;");

    conferma->setVisible(false);
    salva= new QPushButton("Salva su file");
    salva->setStyleSheet("background-color:#ffc1e3; color:#000; border: 2px solid #bf5f82;");
    salva->setMinimumSize(85,35);
    salva->setMaximumSize(85,35),

    salva->setVisible(false);

QVBoxLayout *agg= new QVBoxLayout();
agg->addWidget(aggiungi);
agg->addWidget(salva);
QHBoxLayout *modrim= new QHBoxLayout();
modrim->addWidget(modifica);
modrim->addWidget(rimuovi);
QVBoxLayout *modrimconf= new QVBoxLayout();
modrimconf->addLayout(modrim);
modrimconf->addWidget(conferma);
    QHBoxLayout *pulsanti=new QHBoxLayout();

    pulsanti->addLayout(agg);

 pulsanti->addLayout(modrimconf);


//seconda riga
//prima colonna
//label dati
    nome=new QLabel("Nome");
    nome->setMaximumSize(150,35);
    descr= new QLabel("Descrizione");
    descr->setMaximumSize(150,35);
    danno= new QLabel("Danno");
    danno->setMaximumSize(150,35);
    bf = new QLabel("Bersaglio Preferito");
    bf->setMaximumSize(150,35);
    costo= new QLabel("Costo");
    costo->setMaximumSize(150,35);
    vita= new QLabel("Vita");
    vita->setMaximumSize(150,35);
    tempo= new QLabel("Tempo");
    tempo->setMaximumSize(150,35);
    tipodanno= new QLabel("Tipo di danno");
    tipodanno->setMaximumSize(150,35);
    bersagli= new QLabel("Bersagli");
    bersagli->setMaximumSize(150,35);
    type= new QLabel("Tipo");
    type->setMaximumSize(150,35);
    //attacco
    spazio= new QLabel("Spazio");
    spazio->setMaximumSize(150,35);
    spazio->setVisible(false);
    velocita= new QLabel("Velocita");
    velocita->setMaximumSize(150,35);
    velocita->setVisible(false);
    tipo = new QLabel("incantesimo/truppa");
    tipo->setMaximumSize(150,35);
    tipo->setVisible(false);

    //difesa
    distanza= new QLabel("distanza");
    distanza->setMaximumSize(150,35);
    distanza->setVisible(false);
    //eroe
    temporig= new QLabel("temporig");
    temporig->setMaximumSize(150,35);
    temporig->setVisible(false);
    livello= new QLabel("livello");
    livello->setMaximumSize(150,35);
    livello->setVisible(false);


    //pv= primo verticale
    QVBoxLayout *pv= new QVBoxLayout();

    pv->addWidget(nome);
    pv->addWidget(descr);
    pv->addWidget(danno);
    pv->addWidget(bf);
    pv->addWidget(costo);
    pv->addWidget(vita);
    pv->addWidget(tempo);
    pv->addWidget(tipodanno);
    pv->addWidget(bersagli);
    pv->addWidget(type);

    pv->addWidget(spazio);
    pv->addWidget(velocita);
    pv->addWidget(tipo);


    pv->addWidget(distanza);


    pv->addWidget(temporig);
    pv->addWidget(livello);


//componenti per dati
    nomeText= new QLineEdit();
    nomeText->setMaximumSize(150,35);
    descrText=new QLineEdit();
    descrText->setMinimumSize(150,35);
    dannoSpin= new QSpinBox();
    dannoSpin->setMaximumSize(150,35);

    bfCombo= new QComboBox();
    bfCombo->setMaximumSize(150,35);
    bfCombo->insertItem(1,"Difese");
    bfCombo->insertItem(2,"Risorse");
    bfCombo->insertItem(3,"Difese aeree");
    bfCombo->insertItem(4,"Muri");
    bfCombo->insertItem(5,"Indifferente");

    costoSpin= new QSpinBox();
    costoSpin->setMaximumSize(150,35);
    vitaSpin= new QSpinBox();
    vitaSpin->setMaximumSize(150,35);
    tempoSpin= new QSpinBox();
    tempoSpin->setMaximumSize(150,35);
    tipodannoCombo= new QComboBox();
    tipodannoCombo->setMaximumSize(150,35);
    tipodannoCombo->insertItem(1,"Bersaglio singolo");
    tipodannoCombo->insertItem(2,"Ad area");

    bersagliCombo=new QComboBox();
    bersagliCombo->setMaximumSize(150,35);
    bersagliCombo->insertItem(1,"Terra e aria");
    bersagliCombo->insertItem(2,"Terra");
    bersagliCombo->insertItem(3,"Aria");


    typeCombo=new QComboBox();
    typeCombo->setMaximumSize(150,35);
    typeCombo->insertItem(1,"");
    typeCombo->insertItem(2,"Attacco");
    typeCombo->insertItem(3,"Difesa");
    typeCombo->insertItem(4,"Eroe");
    //attacco
    spazioSpin=new QSpinBox();
    spazioSpin->setMaximumSize(150,35);
    spazioSpin->setVisible(false);
    velocitaSpin= new QSpinBox();
    velocitaSpin->setMaximumSize(150,35);
    velocitaSpin->setVisible(false);
    tipoText= new QLineEdit();
    tipoText->setMaximumSize(150,35);
    tipoText->setVisible(false);
    //difesa
    distanzaSpin=new QSpinBox();
    distanzaSpin->setMaximumSize(150,35);
    distanzaSpin->setVisible(false);
    //eroe
    temporigSpin=new QSpinBox();
    temporigSpin->setMaximumSize(150,35);
    temporigSpin->setVisible(false);
    livelloSpin=new QSpinBox();
    livelloSpin->setMaximumSize(150,35);
    livelloSpin->setVisible(false);

//sv= secondo verticale
    QVBoxLayout *sv=new QVBoxLayout();

    sv->addWidget(nomeText);
    sv->addWidget(descrText);
    sv->addWidget(dannoSpin);
    sv->addWidget(bfCombo);
    sv->addWidget(costoSpin);
    sv->addWidget(vitaSpin);
    sv->addWidget(tempoSpin);
    sv->addWidget(tipodannoCombo);
    sv->addWidget(bersagliCombo);
    sv->addWidget(typeCombo);
//attacco
    sv->addWidget(spazioSpin);
    sv->addWidget(velocitaSpin);
    sv->addWidget(tipoText);

//difesa
    sv->addWidget(distanzaSpin);

//eroe
    sv->addWidget(temporigSpin);
    sv->addWidget(livelloSpin);



pv->setSpacing(30);
sv->setSpacing(30);

//layout sinistra con tutti i dettagli
    QHBoxLayout *uno = new QHBoxLayout();
    uno->addLayout(pv);
    uno->addLayout(sv);

//seconda colonna
//filtri di ricerca
    cercaNomeLabel= new QLabel("Cerca per nome");
    cercaNome= new QLineEdit();

    typeFLabel= new QLabel("Tipo");
    bfFLabel= new QLabel("Bersaglio preferito");
    tipodannoFLabel= new QLabel("Tipo di danno");
    bersagliFLabel= new QLabel("Bersagli");

    typeF= new QComboBox();
    typeF->setMaximumSize(150,35);
    typeF->insertItem(1,"Qualsiasi");
    typeF->insertItem(2,"Attacco");
    typeF->insertItem(3,"Difesa");
    typeF->insertItem(4,"Eroe");

    bfF= new QComboBox();
    bfF->setMaximumSize(150,35);
    bfF->insertItem(1,"Qualsiasi");
    bfF->insertItem(2,"Difese");
    bfF->insertItem(3,"Muri");
    bfF->insertItem(4,"Risorse");
    bfF->insertItem(5,"Difese aeree");
    bfF->insertItem(6,"Indifferente");



    tipodannoF= new QComboBox();
    tipodannoF->setMaximumSize(150,35);
    tipodannoF->insertItem(1,"Qualsiasi");
    tipodannoF->insertItem(2,"Bersaglio singolo");
    tipodannoF->insertItem(3,"Ad area");





    bersagliF= new QComboBox();
    bersagliF->setMaximumSize(150,35);
    bersagliF->insertItem(1,"Qualsiasi");
    bersagliF->insertItem(2,"Terra e aria");
    bersagliF->insertItem(3,"Terra");
    bersagliF->insertItem(4,"Aria");

//layout centrale per i filtri di ricerca
    QVBoxLayout *due=new QVBoxLayout();

    due->addWidget(cercaNomeLabel);
    due->addWidget(cercaNome);
    due->addWidget(typeFLabel);
    due->addWidget(typeF);
    due->addWidget(bfFLabel);
    due->addWidget(bfF);
    due->addWidget(tipodannoFLabel);
    due->addWidget(tipodannoF);
    due->addWidget(bersagliFLabel);
    due->addWidget(bersagliF);
    due->addWidget(cerca);

//Lista di risultati
    lista= new QListWidget();
    listaLabel= new QLabel("Risultati");
    leggi= new QPushButton("Leggi da file");
    QVBoxLayout *tre=new QVBoxLayout();
    tre->addWidget(listaLabel);
    tre->addWidget(lista);

    tre->addWidget(leggi);

//layout orizzontale con le colonne
    QHBoxLayout *colonne=new QHBoxLayout();
    colonne->setSpacing(10);

    colonne->addLayout(uno);
    colonne->addLayout(due);
    colonne->addLayout(tre);

    //layout finale
    QVBoxLayout *finale= new QVBoxLayout();
            finale->addLayout(pulsanti);
            finale->addLayout(colonne);
            setLayout(finale);

/*quando il pulsante cerca viene cliccato viene invocata la funzione filtraPers che restituisce una lista con
 * i personaggi che rispondono a tale indicazione*/
            connect(cerca, &QPushButton::clicked, [this]{
                    filtraPers(lista);
                    resettaFiltri();
});

//quando il pulsante salva viene cliccato viene chiamata la funzione salvaClicked che ha il compito di fornire un QString
//contenente il nome del file, alla funzione salva che avrà il compito di salvare i dati su file
           connect(salva, &QPushButton::clicked, [this]{
               salvaClicked();

            });

//quando viene scelta una variante della ComboBox "tipo" viene chiamata la funzione setEditText che ha il compito
//di far apparire le editext relative al tipo scelto
            connect(typeCombo, static_cast<void (QComboBox::*)(int index)>(&QComboBox::currentIndexChanged),
                    [this]{
                setEditText(typeCombo->currentText());
            });
//quando viene cliccato il pulsante "leggi da file" viene chiamata una funzione a cui viene passato come parametro il path
//del file e ne tira fuori gli elementi inserendoli nel contenitore
            connect(leggi, &QPushButton::clicked, [this]{
                leggiClicked();

             });

            connect(lista, &QListWidget::currentRowChanged, [this]{
                mostraDettagli();
                rimuovi->setVisible(true);
                modifica->setVisible(true);
                conferma->setVisible(true);
            });
/*quando viene cliccato il pulsante aggiungi vengono ripuliti i campi dai e resi vuoti per permettere l'inserimento*/
            connect(aggiungi, &QPushButton::clicked, [this]{
                resettaCampi();
                salva->setVisible(true);
                rimuovi->setVisible(false);
                modifica->setVisible(false);
                conferma->setVisible(false);

            });

            /* quando viene cliccato il pulsante modifica il nome viene reso non modificabile,
             * se si vuole modificare un personaggio dal nome bisogna eliminarlo e crearne un altro*/
            connect(modifica, &QPushButton::clicked, [this]{
                nomeText->setEnabled(false);
            });

/* quando viene cliccato il pulsante modifica i campi dell'oggetto selezionato vengono aggiornati*/
            connect(conferma, &QPushButton::clicked, [this]{


                if(modificaCampi())
                    QMessageBox::information(this, "OK", "Modificato correttamente");
                else {
                    QMessageBox::information(this, "Errore", "Modifica non avvenuta");
                }
            });
/* quando viene cliccato il pulsante rimuovi il personaggio selezionato viene rimosso dal file*/
            connect(rimuovi, &QPushButton::clicked, [this]{
                elimina();
            });
}

/* metodo utilizzato per resettare i campi a vuoti*/
void Window::resettaCampi(){
    nomeText->setText("");
    descrText->setText("");
    dannoSpin->setValue(0);
    bfCombo->setCurrentIndex(0);
    costoSpin->setValue(0);
    tempoSpin->setValue(0);
    vitaSpin->setValue(0);
    tipodannoCombo->setCurrentIndex(0);
    bersagliCombo->setCurrentIndex(0);
    spazioSpin->setValue(0);
    velocitaSpin->setValue(0);
    temporigSpin->setValue(0);
    livelloSpin->setValue(0);
    distanzaSpin->setValue(0);
    typeCombo->setCurrentIndex(0);
    spazioSpin->setVisible(false);
    spazio->setVisible(false);
    velocita->setVisible(false);
    velocitaSpin->setVisible(false);
    tipo->setVisible(false);
    tipoText->setVisible(false);
    distanza->setVisible(false);
    distanzaSpin->setVisible(false);
    temporig->setVisible(false);
    temporigSpin->setVisible(false);
    livello->setVisible(false);
    livelloSpin->setVisible(false);

}
/* metodo utilizzato per resettare i filtri di ricerca*/
void Window::resettaFiltri(){
    cercaNome->setText("");
    typeF->setCurrentIndex(0);
    bersagliF->setCurrentIndex(0);
    bfF->setCurrentIndex(0);
tipodannoF->setCurrentIndex(0);

}
//ritorna un QString contenente il tipo di personaggio risultante dal cast
QString Window::getType(DeepPtr<Personaggio> pers) {
    if(dynamic_cast<Attacco*>(pers.pointer)) {
        return "Attacco";
    }
    if(dynamic_cast<Difesa*>(pers.pointer)) {
        return "Difesa";
    }
    if(dynamic_cast<Eroe*>(pers.pointer)) {
        return "Eroe";
    }
    throw typeError("Card type not found");
}

//funzione che fa apparire le label e EditText in base al tipo selezionato
void Window::setEditText(QString tipop){
    if(tipop=="Attacco"){
        spazio->setVisible(true);
        spazioSpin->setVisible(true);
        velocita->setVisible(true);
        velocitaSpin->setVisible(true);
        tipo->setVisible(true);
        tipoText->setVisible(true);
        distanza->setVisible(false);
        distanzaSpin->setVisible(false);
        temporig->setVisible(false);
        temporigSpin->setVisible(false);
        livello->setVisible(false);
        livelloSpin->setVisible(false);
        }
    if(tipop=="Difesa") {
        spazio->setVisible(false);
        spazioSpin->setVisible(false);
        velocita->setVisible(false);
        velocitaSpin->setVisible(false);
        tipo->setVisible(false);
        tipoText->setVisible(false);
        distanza->setVisible(true);
        distanzaSpin->setVisible(true);
        temporig->setVisible(false);
        temporigSpin->setVisible(false);
        livello->setVisible(false);
        livelloSpin->setVisible(false);
    }
    if(tipop=="Eroe"){
        spazio->setVisible(false);
        spazioSpin->setVisible(false);
        velocita->setVisible(false);
        velocitaSpin->setVisible(false);
        tipo->setVisible(false);
        tipoText->setVisible(false);
        distanza->setVisible(false);
        distanzaSpin->setVisible(false);
        temporig->setVisible(true);
        temporigSpin->setVisible(true);
        livello->setVisible(true);
        livelloSpin->setVisible(true);
    }

}
/*questo metodo controlla che non ci sia già quell'elemento presente nel file, in caso restituisce un false per impedire
inserimento o modifica*/
bool Window::controlloDoppioni(QString n){

    for(auto it = cont.begin(); it!= cont.end(); it++){
        if((*it).pointer->getNome()==n){
            //QMessageBox::information(this, "no", "no");
            return false;

        }
    }return true;
}
//creo e aggiungo il nuovo personaggio nel contenitore


bool Window::aggiungiPersonaggio(){

    if(typeCombo->currentText()=="Attacco"){
        Attacco* a= new Attacco(nomeText->text(), 0,
                                0, bfCombo->currentText(),
                                costoSpin->value(),vitaSpin->value(),
                                tempoSpin->value(), tipodannoCombo->currentText(),
                                bersagliCombo->currentText(),
                                spazioSpin->value(), velocitaSpin->value(),
                                tipoText->text());
        a->setDanno(dannoSpin->value());
        a->setDescrizione(descrText->text());
        if((controlloDoppioni(a->getNome()))==true){
            cont.add(a);
        return true;}
        else {
            QMessageBox::information(this, "errore", "Questo personaggio è già presente");
            return false;
        }

    }


    if(typeCombo->currentText()=="Difesa"){
        Difesa* d= new Difesa(nomeText->text(), descrText->text(),
                                dannoSpin->value(), bfCombo->currentText(),
                                costoSpin->value(),vitaSpin->value(),
                                tempoSpin->value(), tipodannoCombo->currentText(),
                                bersagliCombo->currentText(),
                                distanzaSpin->value());
        if((controlloDoppioni(d->getNome()))==true){
            cont.add(d);
        return true;}
        else {
            QMessageBox::information(this, "errore", "Questo personaggio è già presente");
            return false;
        }


    }
    if(typeCombo->currentText()=="Eroe"){
        Eroe* e= new Eroe(nomeText->text(), descrText->text(),
                                dannoSpin->value(), bfCombo->currentText(),
                                costoSpin->value(),vitaSpin->value(),
                                tempoSpin->value(), tipodannoCombo->currentText(),
                                bersagliCombo->currentText(),
                                temporigSpin->value(), livelloSpin->value());
        if((controlloDoppioni(e->getNome()))==true){
        cont.add(e);
        return true;}
        else {
            QMessageBox::information(this, "errore", "Questo personaggio è già presente");
            return false;
        }

    }

}

/* funzione che viene invocata dal metodo del click del pulsante salva, controlla che i campi "obbligatori" siano compilati
 * legge il file e mette i personaggi nel contenitore, aggiunge in coda il nuovo personaggio, infine chiama savaSuFile
 * per memorizzare nel file Json */
void Window::salvaClicked(){
    //controllo che i campi ritenuti più importanti non siano vuoti
    if(typeCombo->currentText()==""||nomeText->text().isEmpty()){
        QMessageBox::information(this, "Errore", "Obbligatorio selezionare il tipo di personaggio e inserire il nome");
    }else{
    QString file=QFileDialog::getOpenFileName(this, "Save on","","Json (*.json)" );
    //leggere prima da file serve per tirare fuori gli elementi già presenti e aggiungere quello nuovo
    leggiDaFile(file);
    bool ver=aggiungiPersonaggio();
    if(ver){
        resettaCampi();

        bool stato=salvaSuFile(file);
        if(stato) QMessageBox::information(this, "OK","Salvataggio completato");
        else QMessageBox::information(this, "Errore", "Salvataggio fallito");
        leggiDaFile(file);
        filtraPers(lista);
        }

    }
}
bool Window::salvaSuFile(const QString file)  {

    QFile jsonFile(file);
    if(!jsonFile.open(QFile::WriteOnly)){return false;}
    QJsonArray jsonAr;
    for(auto it = cont.begin(); it != cont.end(); ++it) {
        QJsonObject jsonObj;
        jsonObj.insert("nome", QJsonValue::fromVariant((*it)->getNome()));
        jsonObj.insert("descr", QJsonValue::fromVariant((*it)->getDescrizione()));
        jsonObj.insert("danno", QJsonValue::fromVariant((*it)->getDanno()));
        jsonObj.insert("bf", QJsonValue::fromVariant((*it)->getBersaglioPrefe()));
        jsonObj.insert("costo", QJsonValue::fromVariant((*it)->getCosto()));
        jsonObj.insert("vita", QJsonValue::fromVariant((*it)->getVita()));
        jsonObj.insert("tempo", QJsonValue::fromVariant((*it)->getTempo()));
        jsonObj.insert("tipodanno", QJsonValue::fromVariant((*it)->getTipoDanno()));
        jsonObj.insert("bersagli", QJsonValue::fromVariant((*it)->getBersagli()));
        if(getType(*it)=="Attacco"){
            jsonObj.insert("type", QJsonValue::fromVariant("Attacco"));
            jsonObj.insert("spazio", QJsonValue::fromVariant(static_cast<Attacco*>((*it).pointer)->getSpazio()));
            jsonObj.insert("velocita", QJsonValue::fromVariant(static_cast<Attacco*>((*it).pointer)->getVelocita()));
            jsonObj.insert("tipo", QJsonValue::fromVariant(static_cast<Attacco*>((*it).pointer)->getTipo()));

        }
        if(getType(*it)=="Difesa"){
            jsonObj.insert("type", QJsonValue::fromVariant("Difesa"));
            jsonObj.insert("distanza", QJsonValue::fromVariant(static_cast<Difesa*>((*it).pointer)->getDistanza()));

        }
        if(getType(*it)=="Eroe"){
            jsonObj.insert("type", QJsonValue::fromVariant("Eroe"));
            jsonObj.insert("temporig", QJsonValue::fromVariant(static_cast<Attacco*>((*it).pointer)->getSpazio()));
            jsonObj.insert("livello", QJsonValue::fromVariant(static_cast<Attacco*>((*it).pointer)->getSpazio()));
        }



       jsonAr.append(jsonObj);

    }
    QJsonObject oggettoFinale;
    oggettoFinale.insert(QString("Personaggi"), QJsonValue(jsonAr));
    jsonFile.write(QJsonDocument(oggettoFinale).toJson());
    jsonFile.close();
    return true;

}

/*funzione invocata dal metodo del click del pulsante leggi, ha il solo compito di fornire il file json,
 * chiamare la funzione leggidDaFile che ne estrapola il contenuto ed infine
 * la funzione filtra che fornisce la lista di personaggi */
void Window::leggiClicked(){

    file=QFileDialog::getOpenFileName(this, "Load on", "", "Json (*json)");
    bool stato = leggiDaFile(file);
    filtraPers(lista);
    resettaCampi();
    if(stato) QMessageBox::information(this, "ok", "Letto correttamente");
    else QMessageBox::information(this, "errore", "impossibile leggere il file");
    //reset filtri da chiamare
}


/*Dopo aver eliminato tutto il contenuto del contenitore inserisco tutti i personaggi presi dal file json*/
bool Window::leggiDaFile(QString path){


    QFile file(path);

    if(!file.open(QIODevice::ReadOnly)){QMessageBox::information(this, "errore", "impossibile leggere il file");}

    QJsonDocument documento = QJsonDocument::fromJson(file.readAll());
    QJsonObject arrayobj=documento.object();

    QJsonArray array =arrayobj["Personaggi"].toArray();

if(!cont.isEmpty()){
    cont.clear();}

        for(int i=0; i<array.size();++i){
            QJsonObject obj = array[i].toObject();
            QString persType= obj["type"].toString();

            if(persType=="Attacco"){
                cont.add(new Attacco(array[i].toObject().value("nome").toString(),
                                     array[i].toObject().value("descr").toString(),
                                     array[i].toObject().value("danno").toInt(),
                                     array[i].toObject().value("bf").toString(),
                                     array[i].toObject().value("costo").toInt(),
                                     array[i].toObject().value("vita").toInt(),
                                     array[i].toObject().value("tempo").toInt(),
                                     array[i].toObject().value("tipodanno").toString(),
                                     array[i].toObject().value("bersagli").toString(),
                                     array[i].toObject().value("spazio").toInt(),
                                     array[i].toObject().value("velocita").toInt(),
                                     array[i].toObject().value("tipo").toString()));

            }
            if(persType=="Difesa"){
                cont.add(new Difesa(array[i].toObject().value("nome").toString(),
                                    array[i].toObject().value("descr").toString(),
                                    array[i].toObject().value("danno").toInt(),
                                    array[i].toObject().value("bf").toString(),
                                    array[i].toObject().value("costo").toInt(),
                                    array[i].toObject().value("vita").toInt(),
                                    array[i].toObject().value("tempo").toInt(),
                                    array[i].toObject().value("tipodanno").toString(),
                                    array[i].toObject().value("bersagli").toString(),
                                    array[i].toObject().value("distanza").toInt()));
            }
            if(persType=="Eroe"){
                cont.add(new Eroe(array[i].toObject().value("nome").toString(),
                                  array[i].toObject().value("descr").toString(),
                                  array[i].toObject().value("danno").toInt(),
                                  array[i].toObject().value("bf").toString(),
                                  array[i].toObject().value("costo").toInt(),
                                  array[i].toObject().value("vita").toInt(),
                                  array[i].toObject().value("tempo").toInt(),
                                  array[i].toObject().value("tipodanno").toString(),
                                  array[i].toObject().value("bersagli").toString(),
                                  array[i].toObject().value("temporig").toInt(),
                                  array[i].toObject().value("livello").toInt()));
            }
}
        file.close();
        return true;


}

/* in base ai filtri selezionati restituisco una lista di personaggi che corrispondono alla richiesta*/
void Window::filtraPers(QListWidget* lista){
    lista->reset();
    lista->clear();
    QString q="Qualsiasi";
    for(auto it = cont.begin(); it != cont.end(); ++it) {
       if((cercaNome->text()==""||cercaNome->text()==(*it)->getNome()&&
                   bfF->currentText()==q||bfF->currentText()==(*it)->getBersaglioPrefe()) &&
          (tipodannoF->currentText()==q||tipodannoF->currentText()==(*it)->getTipoDanno()) &&
          (bersagliF->currentText()==q||bersagliF->currentText()==(*it)->getBersagli())&&
          ((typeF->currentText()==q||typeF->currentText()==getType(*it)))
                ){

            QListWidgetItem* nuova= new QListWidgetItem();
            nuova->setText((*it)->getNome());
            lista->addItem(nuova);

           }
    }
    lista->sortItems();
    if(lista->count()==0){
        QMessageBox::information(this, "Errore", "Nessun personaggio corrisponde alla tua ricerca");
    }
}

void Window::mostraDettagli(){
modifica->setVisible(true);
    QString nome=lista->currentItem()->text();
    for(auto it = cont.begin(); it != cont.end(); ++it){

        if((*it)->getNome()==nome){
            nomeText->setText((*it)->getNome());
            descrText->setText((*it)->getDescrizione());
            dannoSpin->setValue((*it)->getDanno());
            bfCombo->setCurrentText((static_cast<Attacco*>((*it).pointer)->getBersaglioPrefe()));

            costoSpin->setValue((*it)->getCosto());
            vitaSpin->setValue((*it)->getVita());
            tempoSpin->setValue((*it)->getTempo());
            tipodannoCombo->setCurrentText((static_cast<Attacco*>((*it).pointer)->getTipoDanno()));
            bersagliCombo->setCurrentText((static_cast<Attacco*>((*it).pointer)->getBersagli()));

            typeCombo->setCurrentText(getType(*it));
            if(getType(*it)=="Attacco"){


                spazioSpin->setValue((static_cast<Attacco*>((*it).pointer)->getSpazio()));
                velocitaSpin->setValue((static_cast<Attacco*>((*it).pointer)->getVelocita()));
                tipoText->setText(static_cast<Attacco*>((*it).pointer)->getTipo());

            }
            if(getType(*it)=="Difesa"){

                distanzaSpin->setValue((static_cast<Difesa*>((*it).pointer)->getDistanza()));

            }
            else

                temporigSpin->setValue((static_cast<Eroe*>((*it).pointer)->getTempoRig()));
                livelloSpin->setValue((static_cast<Eroe*>((*it).pointer)->getLivelloMax()));




        }

    }
}
/* metodo che selezionato un elemento ne modifica i campi e salva su file*/
bool Window::modificaCampi(){
    QString nome=lista->currentItem()->text();
    for(auto it = cont.begin(); it != cont.end(); ++it){

        if((*it)->getNome()==nome){
            (*it)->setNome(nomeText->text());
            (*it)->setDescrizione(descrText->text());
            (*it)->setDanno(dannoSpin->value());
            (*it)->setBersaglioPrefe(bfCombo->currentText());
            (*it)->setVita(vitaSpin->value());
            (*it)->setCosto(costoSpin->value());
            (*it)->setTempo(tempoSpin->value());
            (*it)->setTipoDanno(tipodannoCombo->currentText());
            (*it)->setBersagli(bersagliCombo->currentText());
            if(getType(*it)=="Attacco"){
                static_cast<Attacco*>((*it).pointer)->setSpazio(spazioSpin->value());
                static_cast<Attacco*>((*it).pointer)->setVelocita(velocitaSpin->value());
                static_cast<Attacco*>((*it).pointer)->setTipo(tipoText->text());

            }
            if(getType(*it)=="Difesa"){
                static_cast<Difesa*>((*it).pointer)->setDistanza(distanzaSpin->value());

            }
            else {
                static_cast<Eroe*>((*it).pointer)->setTempoRig(temporigSpin->value());
                static_cast<Eroe*>((*it).pointer)->setLivelloMax(livelloSpin->value());
            }

                salvaSuFile(file);
                filtraPers(lista);
                return true;


        }



    }
}
/*metodo che selezionato un elemento lo elimina dal file*/
void Window::elimina(){
    leggiDaFile(file);
    QString nome=lista->currentItem()->text();

   for(auto it = cont.begin(); it!=cont.end(); ++it){
        if((*it).pointer->getNome()==nome)    {
           cont.erase(cont.search(*it));
           break;


}
    }

    salvaSuFile(file);
    filtraPers(lista);
}









