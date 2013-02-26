#include "langage.h"

Langage::Langage() {}

Langage::Langage(QString fileName) {
    this->fileName = fileName;
    this->path = DB_LANGAGE_PATH + fileName + DB_LANGAGE_FORMAT;
    this->extractJsonData();
}

/**
  Récupère les données du JSON .lang, les parses et remplis les attributs de la classe avec 
  (necessite que l'attribut "path" soit déja renseigné pour trouver le bon fichier)
**/
void Langage::extractJsonData() {
    Log::put("Extraction du langage "+this->path,2);
    QString result = Functions::readFile(this->path);
    QVariantMap allData = QtJson::Json::parse(result).toMap();
    
    Log::put("Recuperation des attributs...",3);
    this->name = QVariant(allData["name"]).toString();
    Log::put("name  : "+this->name,3);
    this->author = QVariant(allData["author"]).toString();
    Log::put("author  : "+this->author,3);
    this->pubdate = QVariant(allData["pubdate"]).toString();
    Log::put("pubdate  : "+this->pubdate,3);
    this->comment = QVariant(allData["comment"]).toString();
    Log::put("comment  : "+this->comment,3);
    this->linkSheet = QVariant(allData["linkSheet"]).toString();
    Log::put("linkSheet  : "+this->linkSheet,3);
    this->version = QVariant(allData["version"]).toString();
    Log::put("version  : "+this->version,3);

    Log::put("Récuperation des colorations du langage  : "+this->path,2);
    QList<Coloration> colorationList = QList<Coloration>();

    QVariantList colorations = QVariant(allData["colorations"]).toList();

    Log::put("Nombre de colorations : "+QString::number(colorations.size()),3);

    foreach(QVariant coloration,colorations){
        Coloration currentColoration = Coloration();
        QVariantMap jsonColoration = coloration.toMap();
        currentColoration.setBold(QVariant(jsonColoration["bold"]).toBool());
        currentColoration.setItalic(QVariant(jsonColoration["italic"]).toBool());
        currentColoration.setUnderline(QVariant(jsonColoration["underline"]).toBool());
        currentColoration.setStrike(QVariant(jsonColoration["strike"]).toBool());
        currentColoration.setColor(QVariant(jsonColoration["color"]).toString());
        currentColoration.setValues(QVariant(jsonColoration["values"]).toStringList());
        Log::put(currentColoration.toString(),4);
        colorationList.append(currentColoration);
    }
    this->colorations = colorationList;
    Log::put("Recuperation des attributs terminée.",3);
}


QStringList Langage::getAll() {
     QStringList result =  QStringList();
     QStringList listFilter;
     listFilter << "*" << DB_LANGAGE_FORMAT;
     QDirIterator dirIterator(DB_LANGAGE_PATH, listFilter, QDir::Files | QDir::NoSymLinks);

     while ( dirIterator.hasNext() ) {
         QString name = QFileInfo(dirIterator.next()).baseName();
         if ( name.toStdString().length() < DB_FILE_LANGAGE_MAXLEN ) {
             result << name;
         }
     }
     return result;
}


QList<Langage> Langage::loadAll(){
    QList<Langage> langages  = QList<Langage>();
    QStringList langagesName = Langage::getAll();
    foreach(QString langageName,langagesName){
        Langage langage = Langage(langageName);
        //langage.setName(langageName);
        langages.append(langage);
    }
    return langages;
}



QString Langage::getName(){
    return this->name;
}

QString Langage::getAuthor(){
    return this->author;
}
QString Langage::getPubdate(){
    return this->pubdate;
}
QString Langage::getLinkSheet(){
    return this->linkSheet;
}
QString Langage::getComment(){
    return this->comment;
}
QString Langage::getVersion(){
    return this->version;
}
QList<Coloration> Langage::getColorations() {
    return this->colorations;
}
QString Langage::getFileName(){
    return this->fileName;
}


void Langage::setName(QString name){
    this->name = name;
}
void Langage::setAuthor(QString author){
    this->author = author;
}
void Langage::setPubdate(QString pubdate){
    this->pubdate = pubdate;
}
void Langage::setLinkSheet(QString linkSheet){
    this->linkSheet = linkSheet;
}
void Langage::setComment(QString comment){
    this->comment = comment;
}
void Langage::setVersion(QString version){
    this->version = version;
}
void Langage::setColorations(QList<Coloration> colorations) {
    this->colorations = colorations;
}



