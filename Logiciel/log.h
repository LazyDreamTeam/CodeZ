#ifndef LOG_H
#define LOG_H
#include <QString>
#include <QDate>
#include <QDebug>

#include "constant.h"
/**
	Classe de centralisation et de gestion des logs (console, fichier texte et panneau special)
	@author Idleman
	@since 13/07/2012
**/
class Log
{
public:
    Log();
    static void put(QString message,int level = 1, int priority = 2);
};

#endif // LOG_H
