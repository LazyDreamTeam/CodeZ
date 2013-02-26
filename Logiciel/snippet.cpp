#include "snippet.h"

Snippet::Snippet() {}

Snippet::Snippet(QString category, QString name) {
    this->category = category;
    this->name = name;
    this->code = this->extractCode();

}

QString Snippet::extractCode() {
    QString result = Functions::readFile(DB_PATH + this->category + DB_SNIPPET_FORMAT);
    jsonStructure = QtJson::Json::parse(result).toMap();
    return jsonStructure[this->name].toString();
}

QList<Snippet> Snippet::loadForCategory(QString category){
    QList<Snippet> snippets =  QList<Snippet>();
    QString result = Functions::readFile(DB_PATH + category + DB_SNIPPET_FORMAT);
    QVariantMap snippetsInfos = QtJson::Json::parse(result).toMap();
    QStringList snippetsInfosKeys = snippetsInfos.keys();
    foreach(QString snippetInfosKey,snippetsInfosKeys){
        Snippet snippet =  Snippet(category,snippetInfosKey);
        snippets.append(snippet);
    }
    return snippets;
}

void Snippet::remove(){
    jsonStructure.remove(this->name);
    QByteArray stream = QtJson::Json::serialize(jsonStructure);
    Functions::writeFile(DB_PATH +this->category+DB_SNIPPET_FORMAT,QString::fromAscii(stream));
}

void Snippet::save(){
    jsonStructure[this->name] = this->code;
    QByteArray stream = QtJson::Json::serialize(jsonStructure);
    Functions::writeFile(DB_PATH +this->category+DB_SNIPPET_FORMAT,QString::fromAscii(stream));
}

void Snippet::rename(QString oldName, QString newName){
    jsonStructure[newName] = jsonStructure[oldName];
    jsonStructure.remove(oldName);
    QByteArray stream = QtJson::Json::serialize(jsonStructure);
    Functions::writeFile(DB_PATH +this->category+DB_SNIPPET_FORMAT,QString::fromAscii(stream));
}

/**************/
/* ACCESSEURS */
/**************/

QString Snippet::getName() {
    return QString::fromUtf8(this->name.toStdString().c_str());
}

QString Snippet::getCategory() {
    return this->category;
}

QString Snippet::getCode() {
    return QString::fromUtf8(this->code.toStdString().c_str());
}

void Snippet::setName(QString name) {
    this->name = name;
}

void Snippet::setCategory(QString category) {
    this->category = category;
}

void Snippet::setCode(QString code) {
    this->code = code;
}

