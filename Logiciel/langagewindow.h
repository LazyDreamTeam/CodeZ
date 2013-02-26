#ifndef LANGAGEWINDOW_H
#define LANGAGEWINDOW_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QIcon>
#include <QHBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QWidget>
#include "constant.h"
#include "dictionnary.h"
#include "langage.h"
#include "log.h"
class LangageWindow : public QDialog
{
    Q_OBJECT
public:
    explicit LangageWindow(QWidget *parent = 0);
    
signals:
    
public slots:
    void addLanguage();
    void updateLanguage();
    void deleteLanguage();
    void selectLangage(QListWidgetItem *item);

private:
    QLabel *lblLangagesList;
    QHBoxLayout *layout;
    QListWidget *listLangagesList;
    QWidget *buttonZone;
    QVBoxLayout *buttonZoneLayout;
    QPushButton *btnAddLangage;
    QPushButton *btnUpdateLangage;
    QPushButton *btnDeleteLangage;
    Dictionnary *dictionnary;
};

#endif // LANGAGEWINDOW_H
