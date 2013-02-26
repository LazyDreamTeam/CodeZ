#ifndef CONSTANT_H
#define CONSTANT_H

#include <QString>
const QString DB_SNIPPET_FORMAT = ".snip";
const QString DB_PATH           = "./database/";
const QString DB_LANGAGE_PATH   =  "./langages/";
const QString DB_LANGAGE_FORMAT = ".lang";

#ifdef CATEGORY_H
const unsigned int DB_FILE_MAXLEN = 26;
#endif

#ifdef LANGAGE_H
const unsigned int DB_FILE_LANGAGE_MAXLEN = 26;
#endif

const QString PROGRAM_NAME         = "CodeZ";
const unsigned int PROGRAM_VERSION = 1;
const QString PROGRAM_VERSION_NAME = "Lot 2 Alpha";
const QString PROGRAM_TITLE        = PROGRAM_NAME + " v" + QString::number(PROGRAM_VERSION) \
                                        + " ("+PROGRAM_VERSION_NAME+")";
const int LOG_MAX_PRIORITY         = 1;

const QString SITE_URL             = "http://snippet.idleman.fr";
const QString SVN_URL = "http://hades.idleman.fr/svn/codez";
const QString RSS_URL = "http://dizplay.idleman.fr/action/svn2Rss?project=codez";
const QString FORUM_URL = SITE_URL+"/forum";
const QString CATEGORY_LANGAGE_SEPARATOR = "-&-";

const QString LABEL_NEW_SNIPPET    = "Nouveau snippet";
const QString LABEL_NO_SNIPPET     = QString::fromUtf8("Aucun snippet trouvé.");
const QString LABEL_NO_LANGUAGE    = QString::fromUtf8("Aucun langage trouvé.");
const QString LABEL_CODE_COMMENT   = "/**\n\tFonction squelette.\n\t@author: Moi\n**/\n";
const QString LABEL_CHOOSE_SNIP    = "Choisissez un snippet dans la liste.";
const QString LABEL_NAME_REQUIRED    = "Nom obligatoire...";

const QString LABEL_HOW_ABOUT_US    = QString("<h1>Informations sur le programme</h1> <br/>") +
                                      QString("<ul>") +
                                      QString("<li><strong>Nom :</strong> "+PROGRAM_NAME+"</li>") +
                                      QString("<li><strong>Version : </strong>"+QString::number(PROGRAM_VERSION)+" ("+PROGRAM_VERSION_NAME+")</li>") +
                                      QString("<li><strong>Site web :</strong> <a style='color:#eb2c2c;' href='"+SITE_URL+"'>"+SITE_URL+"</a></li>") +
                                      QString("<li><strong>Forum :</strong> <a style='color:#eb2c2c;' href='"+FORUM_URL+"'>"+FORUM_URL+"</a></li>") +
                                      QString("<li><strong>SVN :</strong> <a style='color:#eb2c2c;' href='"+SVN_URL+"'>"+SVN_URL+"</a></li>") +
                                      QString("<li><strong>Flux RSS :</strong> <a style='color:#eb2c2c;' href='"+RSS_URL+"'>"+RSS_URL+"</a></li>") +
                                      QString("</ul>") +
                                      QString("<h1>Auteurs</h1> <br/>") +
                                      QString("<ul>") +
                                      QString("<li><strong>Valentin CARRUESCO</strong> aka <a style='color:#eb2c2c;' href='http://blog.idleman.fr'>Idleman</a> <i>Fondateur/Dev C++/Graphiste</i></li>") +
                                      QString("<li><strong>Yosko</strong> <i>Dev C++/Int&eacute;grateur UI</i></li>") +
                                      QString("<li><strong>AkaiKen</strong> <i>Dev PHP/Int&eacute;grateur CSS&JS/Graphiste</i></li>") +
                                      QString("</ul>") ;



#endif // CONSTANT_H
