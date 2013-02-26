#include "dictionnary.h"

Dictionnary* Dictionnary::_instance = 0;

Dictionnary::Dictionnary()
{
    this->loadData();
}

Dictionnary* Dictionnary::getInstance()
{
    if(_instance == 0)
        _instance = new Dictionnary();
    return _instance;
}

void Dictionnary::loadData(){

    this->langages = Langage::loadAll();
    this->categories = Category::loadAll();

    QList<Snippet> snippetsList = QList<Snippet>();
    foreach(Category category,categories){
        snippetsList.append(category.getSnippets());
    }

    QList<Coloration> colorationsList = QList<Coloration>();
    foreach(Langage langage,langages){
        colorationsList.append(langage.getColorations());
    }

    this->snippets = snippetsList;
    this->colorations = colorationsList;
}

QList<Category> Dictionnary::getCategories(){
	return this->categories;
}

Category Dictionnary::getCategory(QString name){
    Category returnedCategory;
    foreach(Category cat,this->categories){
        QStringList catList = cat.getName().split(CATEGORY_LANGAGE_SEPARATOR);
        if(catList.at(0)==name){
            returnedCategory = cat;
        }
    }

    return returnedCategory;
}


QList<Snippet> Dictionnary::getSnippets(){
    return this->snippets;
}

Snippet Dictionnary::getSnippet(QString name){
    Snippet returnedSnippet;
    foreach(Snippet snip,this->snippets){
        if(snip.getName()==name) returnedSnippet = snip;
    }
    return returnedSnippet;
}

QList<Langage> Dictionnary::getLangages(){
    return this->langages;
}

Langage Dictionnary::getLangage(QString name){
    Langage returnedLangage;
    foreach(Langage lang,this->langages){
        if(lang.getName()==name) returnedLangage = lang;
    }
    return returnedLangage;
}


QList<Coloration> Dictionnary::getColorations(){
    return this->colorations;
}

Coloration Dictionnary::getColoration(QString color){
    Coloration returnedColoration;
    foreach(Coloration col,this->colorations){
        if(col.getColor()==color) returnedColoration = col;
    }
    return returnedColoration;
}



