#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QIcon>
#include <QHBoxLayout>
#include "constant.h"
#include "log.h"
class AboutWindow : public QDialog
{
    Q_OBJECT
public:
    explicit AboutWindow(QWidget *parent = 0);

signals:
    
public slots:

private :
    QLabel *lblHowAboutUs;
    QHBoxLayout *layout;
};

#endif // ABOUTWINDOW_H
