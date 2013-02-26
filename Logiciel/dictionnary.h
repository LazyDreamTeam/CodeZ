#ifndef DICTIONNARY_H
#define DICTIONNARY_H

#include <QList>
#include "category.h"

class Dictionnary
{
public:
    explicit Dictionnary();
    static Dictionnary* getInstance();


    QList<Category> getCategories();
    Category getCategory(QString name);

    QList<Snippet> getSnippets();
    Snippet getSnippet(QString name);

    QList<Langage> getLangages();
    Langage getLangage(QString name);


    QList<Coloration> getColorations();
    Coloration getColoration(QString color);
    void loadData();

private:
    static Dictionnary* _instance;

    QList<Category> categories;
    QList<Snippet> snippets;
    QList<Langage> langages;
    QList<Coloration> colorations;
};

#endif // DICTIONNARY_H
