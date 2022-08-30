#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <ctime>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QEvent>
#include <QPixmap>
#include <QTimer>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void TimerSlot_org();

private:
    Ui::MainWindow *ui;
    QTimer *timer_org;
};

class MicroOrganize
{
public:
    int posX, posY, size_h, size_w;
    int stepX, stepY;
    bool dead = false;
private:
};

class BoleznOrganize : public MicroOrganize
{
public:
    int HP;
private:
};

class LecarstvoOrganize : public BoleznOrganize
{
public:
private:
};



#endif


