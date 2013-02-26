#ifndef CATEGORYWINDOW_H
#define CATEGORYWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QIcon>
#include <QHBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QMessageBox>

#include "constant.h"
#include "dictionnary.h"
#include "category.h"
#include "langage.h"
#include "log.h"





class CategoryWindow : public QDialog
{
    Q_OBJECT
public:
    explicit CategoryWindow(QWidget *parent = 0);
    void show();
signals:
    void CategoryAdded();
    
public slots:
    void addCategory();
private:

    QHBoxLayout *layout;
    QWidget *buttonZone;
    QVBoxLayout *buttonZoneLayout;
    QLabel *labelCategoryName;
    QLabel *labelLangageName;

    QLineEdit *textCategoryName;
    QComboBox *comboLangageList;
    QPushButton *btnAddCategory;
    Dictionnary *dictionnary;
    
};

#endif // CATEGORYWINDOW_H
