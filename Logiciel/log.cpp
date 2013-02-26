#include "log.h"

Log::Log()
{

}


/**
  Methode statique affichant le message "message" dans les logs.
  Cette méthode est vouée a diffuser les logs dans la consoles de debug,
  dans une GUI du projet vouée au débug ou dans un fichier texte de logs en fonction
  des parametres fournis lors du lancement du programme
  @param <QString> message : message a envoyer
  @param <int> niveau du log (referent a la profondeur de couche dont il est issu). Défaut : 1
  @param <int> priorité du log (n'affiche que les logs <= LOG_MAX_PRIORITY). Défaut : 2
**/
void Log::put(QString message, int level, int priority){
    if(priority <= LOG_MAX_PRIORITY) {
        QString str("  ");
        QDateTime date =  QDateTime::currentDateTime();
        qDebug(qPrintable(date.toString("hh:mm:ss")+str.repeated(level)+message));
        //@TODO  gerer la partie enregistrement dans un fichier texte et l'affichage en GUI
    }
}
