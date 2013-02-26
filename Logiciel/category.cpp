#include <QDebug>
#include "category.h"


Category::Category() {}

Category::Category(QString name) {
    this->name = name;
}


/**
Récupèrer tous les fichiers de catgeories.
Conditions : fichiers avec l'extension DB_SNIPPET_FORMAT
             et pas plus de DB_FILE_MAXLEN caractères de long.
**/
QStringList Category::getAll() {
     Log::put("Recuperation des noms de catégories",2);
     QStringList result =  QStringList();
     QStringList listFilter;
     listFilter << "*" << DB_SNIPPET_FORMAT;
     QDirIterator dirIterator(DB_PATH, listFilter, QDir::Files | QDir::NoSymLinks);

     while ( dirIterator.hasNext() ) {
         QString name = QFileInfo(dirIterator.next()).baseName();
         if ( name.toStdString().length() < DB_FILE_MAXLEN ) {
             result << name;
         }
     }
     return result;
}

/**
Récupère tous les "objets" catégorie et retourne une QList, ces objets category
chargent a leurs instanciation les snippet et le langage qu'elles contiennent
**/
QList<Category> Category::loadAll(){
    Log::put("Recuperation des objets de catégories",2);
    QList<Category> categories  = QList<Category>();
    QStringList categoriesName = Category::getAll();
    foreach(QString categoryName,categoriesName){
        QStringList catInfos = categoryName.split(CATEGORY_LANGAGE_SEPARATOR);
        Category category = Category();
        category.setName(catInfos.at(0));
        category.setLangage((catInfos.size()>1?catInfos.at(1):"Default"));
        Log::put("Catégorie "+categoryName,3);
        category.loadLangage();
        category.loadSnippet();
        categories.append(category);
    }
    return categories;
}

/**
 * Récuperation de la liste des noms de snippet pour la catégorie courante
 **/
QStringList Category::getSnippetsList() {
     QString result = Functions::readFile(DB_PATH + this->getRealName() + DB_SNIPPET_FORMAT);
     QVariantMap test;

     if ( ! result.isEmpty() ) {
         test = QtJson::Json::parse(result).toMap();
     }
     return test.keys();
}

Snippet Category::getSnippet(QString name){
    Snippet returnedSnippet;
    foreach(Snippet snip,getSnippets()){
        if(snip.getName()==name)returnedSnippet = snip;
    }
    return returnedSnippet;
}


void Category::add(QString name, QString langage){
    QString catFileName = DB_PATH+name+CATEGORY_LANGAGE_SEPARATOR+langage+DB_SNIPPET_FORMAT;
    Functions::touch(catFileName);
}

void Category::rename(QString oldName, QString newName){
    QStringList categoriesName = Category::getAll();
    foreach(QString categoryName,categoriesName){
        if(categoryName.startsWith(oldName + CATEGORY_LANGAGE_SEPARATOR)) {
            QFile file(DB_PATH + categoryName + DB_SNIPPET_FORMAT);
            QStringList catInfos = categoryName.split(CATEGORY_LANGAGE_SEPARATOR);
            file.rename(DB_PATH + newName + CATEGORY_LANGAGE_SEPARATOR + catInfos.at(1) + DB_SNIPPET_FORMAT);
        }
    }
}

void Category::remove(){
    QString catFileName = DB_PATH+this->name+CATEGORY_LANGAGE_SEPARATOR+this->langage+DB_SNIPPET_FORMAT;

    Functions::deleteFile(catFileName);
}

/**
 * Ajouter un snippet au fichier categorie.DB_SNIPPET_FORMAT
 **/




/**************/
/* ACCESSEURS */
/**************/

void Category::setName(QString category) {
    this->name = category;
}

void Category::loadSnippet() {
    this->snippets = Snippet::loadForCategory(this->getRealName());
}

QString Category::getName() {
    return this->name;
}

QString Category::getRealName() {
    return this->name+CATEGORY_LANGAGE_SEPARATOR+this->langage;
}


QString Category::getLangage() {
    return this->langage;
}
void Category::setLangage(QString langage) {
    this->langage = langage;
}

void Category::loadLangage() {
    this->langageObject = Langage(this->langage);
}

Langage Category::getLangageObject(){
    return this->langageObject;
}

QList<Snippet> Category::getSnippets(){
    return this->snippets;
}
