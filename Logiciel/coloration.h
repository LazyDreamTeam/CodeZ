#ifndef COLORATION_H
#define COLORATION_H

#include <QStringList>
#include "log.h"

/**
	Represente une coloration liée a un langage (ex la coloration des structures conditionnelles (if, else, switch...))
	@author Idleman
	@since 13/07/2012
**/
class Coloration
{
public:
    Coloration();

    void setColor(QString color);
    void setUnderline(bool underline);
    void setBold(bool bold);
    void setStrike(bool strike);
    void setItalic(bool italic);
    void setValues(QStringList values);

    QString getColor();
    bool isUnderline();
    bool isBold();
    bool isStrike();
    bool isItalic();
    QStringList getValues();
    QString toString();

private:
	QString color;
	bool underline;
    bool bold;
    bool strike;
    bool italic;
    QStringList values;
};

#endif // COLORATION_H
