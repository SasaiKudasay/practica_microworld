#include "mainwindow.h"
#include "ui_mainwindow.h"

MicroOrganize *MicOrg;
BoleznOrganize *BaktOrg, *GribOrg, *VirusOrg;
LecarstvoOrganize *TablOrg, *AntibOrg;
int TypeOfFunction = 0;
int TypeOfLecarstvo = 0;
int CountOfOrganize = 25;
int MassiveFight[5]={0,0,0,0,0};
bool FlagHelper;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    this->setFixedSize(1080,720);;
    ui->setupUi(this);
    ui->start->installEventFilter(this);
    ui->img_bakt->installEventFilter(this);
    ui->img_grib->installEventFilter(this);
    ui->img_virus->installEventFilter(this);
    ui->img_tabl->installEventFilter(this);
    ui->img_antib->installEventFilter(this);
    MicOrg = new class MicroOrganize[25];
    timer_org = new QTimer(this);
    connect(timer_org, SIGNAL(timeout()), this, SLOT(TimerSlot_org()));

    QPixmap imgFrontSite(":/resurs/img/front_site.jpg");
    int w_front = ui->front_site->width();
    int h_front = ui->front_site->height();
    ui->front_site->setPixmap(imgFrontSite.scaled(w_front, h_front, Qt::KeepAspectRatio));

    QPixmap imgStart(":/resurs/img/start.png");
    int w_start = ui->start->width();
    int h_start = ui->start->height();
    ui->start->setPixmap(imgStart.scaled(w_start, h_start, Qt::KeepAspectRatio));

    QPixmap bkgnd(":/resurs/img/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QPixmap imgFlora(":/resurs/img/микрофлора.png");
    int w_flora = ui->img_flora->width();
    int h_flora = ui->img_flora->height();
    ui->img_flora->setPixmap(imgFlora.scaled(w_flora, h_flora, Qt::KeepAspectRatio));

    QPixmap imgBakt(":/resurs/img/болезнь_бактерия_выкл.png");
    int w_bolez = ui->img_bakt->width();
    int h_bolez = ui->img_bakt->height();
    ui->img_bakt->setPixmap(imgBakt.scaled(w_bolez, h_bolez, Qt::KeepAspectRatio));

    QPixmap imgGrib(":/resurs/img/болезнь_грибок_выкл.png");
    ui->img_grib->setPixmap(imgGrib.scaled(w_bolez, h_bolez, Qt::KeepAspectRatio));

    QPixmap imgVirus(":/resurs/img/болезнь_вирус_выкл.png");
    ui->img_virus->setPixmap(imgVirus.scaled(w_bolez, h_bolez, Qt::KeepAspectRatio));

    QPixmap imgTabl(":/resurs/img/лекарство_таблетки_выкл.png");
    int w_lec = ui->img_tabl->width();
    int h_lec = ui->img_tabl->height();
    ui->img_tabl->setPixmap(imgTabl.scaled(w_lec, h_lec, Qt::KeepAspectRatio));

    QPixmap imgAntib(":/resurs/img/лекарство_антибиотики.png");
    ui->img_antib->setPixmap(imgAntib.scaled(w_lec, h_lec, Qt::KeepAspectRatio));

    QPixmap imgPerson(":/resurs/img/фаза_0.png");
    int w_person = ui->img_person->width();
    int h_person = ui->img_person->height();
    ui->img_person->setPixmap(imgPerson.scaled(w_person, h_person, Qt::KeepAspectRatio));

    QPixmap imgState(":/resurs/img/состояние.png");
    int w_state = ui->img_state->width();
    int h_state = ui->img_state->height();
    ui->img_state->setPixmap(imgState.scaled(w_state, h_state, Qt::KeepAspectRatio));

    QPixmap imgTag(":/resurs/img/иконка.png");
    int w_tag = ui->img_tag->width();
    int h_tag = ui->img_tag->height();
    ui->img_tag->setPixmap(imgTag.scaled(w_tag, h_tag, Qt::KeepAspectRatio));

    QPixmap imgStatus1(":/resurs/img/name_ots.png");
    int w_status = ui->bolez_status->width();
    int h_status = ui->bolez_status->height();
    ui->bolez_status->setPixmap(imgStatus1.scaled(w_status, h_status, Qt::KeepAspectRatio));

    srand(time(NULL));
    for (int i = 0; i < 25; i++)
        {
            switch (i)
            {
            case 0:
            {
                QPixmap imgOrg1 (":/resurs/img/микроорганизм_1");
                MicOrg[i].stepX = 1;
                MicOrg[i].stepY = 1;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_1->width();
                MicOrg[i].size_h = ui->img_mic_org_1->height();
                ui->img_mic_org_1->setPixmap(imgOrg1.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_1->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 1:
            {
                QPixmap imgOrg2 (":/resurs/img/микроорганизм_2.png");
                MicOrg[i].stepX = 2;
                MicOrg[i].stepY = -1;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_2->width();
                MicOrg[i].size_h = ui->img_mic_org_2->height();
                ui->img_mic_org_2->setPixmap(imgOrg2.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_2->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 2:
            {
                QPixmap imgOrg3 (":/resurs/img/микроорганизм_3.png");
                MicOrg[i].stepX = -1;
                MicOrg[i].stepY = -2;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_3->width();
                MicOrg[i].size_h = ui->img_mic_org_3->height();
                ui->img_mic_org_3->setPixmap(imgOrg3.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_3->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 3:
            {
                QPixmap imgOrg4 (":/resurs/img/микроорганизм_3.png");
                MicOrg[i].stepX = -1;
                MicOrg[i].stepY = 1;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_4->width();
                MicOrg[i].size_h = ui->img_mic_org_4->height();
                ui->img_mic_org_4->setPixmap(imgOrg4.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_4->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 4:
            {
                QPixmap imgOrg5 (":/resurs/img/микроорганизм_2.png");
                MicOrg[i].stepX = 1;
                MicOrg[i].stepY = 2;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_5->width();
                MicOrg[i].size_h = ui->img_mic_org_5->height();
                ui->img_mic_org_5->setPixmap(imgOrg5.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_5->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
             }
             case 5:
            {
                QPixmap imgOrg6 (":/resurs/img/микроорганизм_1.png");
                MicOrg[i].stepX = -2;
                MicOrg[i].stepY = -1;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_6->width();
                MicOrg[i].size_h = ui->img_mic_org_6->height();
                ui->img_mic_org_6->setPixmap(imgOrg6.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_6->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 6:
            {
                QPixmap imgOrg7 (":/resurs/img/микроорганизм_1.png");
                MicOrg[i].stepX = 1;
                MicOrg[i].stepY = -1;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_7->width();
                MicOrg[i].size_h = ui->img_mic_org_7->height();
                ui->img_mic_org_7->setPixmap(imgOrg7.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_7->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 7:
            {
                QPixmap imgOrg8 (":/resurs/img/микроорганизм_2.png");
                MicOrg[i].stepX = -1;
                MicOrg[i].stepY = 2;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_8->width();
                MicOrg[i].size_h = ui->img_mic_org_8->height();
                ui->img_mic_org_8->setPixmap(imgOrg8.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_8->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 8:
            {
                QPixmap imgOrg9 (":/resurs/img/микроорганизм_3.png");
                MicOrg[i].stepX = 2;
                MicOrg[i].stepY = 2;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_9->width();
                MicOrg[i].size_h = ui->img_mic_org_9->height();
                ui->img_mic_org_9->setPixmap(imgOrg9.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_9->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 9:
            {
                QPixmap imgOrg10 (":/resurs/img/микроорганизм_1.png");
                MicOrg[i].stepX = 1;
                MicOrg[i].stepY = -2;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_10->width();
                MicOrg[i].size_h = ui->img_mic_org_10->height();
                ui->img_mic_org_10->setPixmap(imgOrg10.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_10->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 10:
            {
                QPixmap imgOrg11 (":/resurs/img/микроорганизм_2.png");
                MicOrg[i].stepX = -2;
                MicOrg[i].stepY = -2;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_11->width();
                MicOrg[i].size_h = ui->img_mic_org_11->height();
                ui->img_mic_org_11->setPixmap(imgOrg11.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_11->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 11:
            {
                QPixmap imgOrg12 (":/resurs/img/микроорганизм_3.png");
                MicOrg[i].stepX = -1;
                MicOrg[i].stepY = 2;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_12->width();
                MicOrg[i].size_h = ui->img_mic_org_12->height();
                ui->img_mic_org_12->setPixmap(imgOrg12.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_12->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 12:
            {
                QPixmap imgOrg13 (":/resurs/img/микроорганизм_3.png");
                MicOrg[i].stepX = -2;
                MicOrg[i].stepY = 2;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_13->width();
                MicOrg[i].size_h = ui->img_mic_org_13->height();
                ui->img_mic_org_13->setPixmap(imgOrg13.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_13->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 13:
            {
                QPixmap imgOrg14 (":/resurs/img/микроорганизм_2.png");
                MicOrg[i].stepX = 1;
                MicOrg[i].stepY = -1;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_14->width();
                MicOrg[i].size_h = ui->img_mic_org_14->height();
                ui->img_mic_org_14->setPixmap(imgOrg14.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_14->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 14:
            {
                QPixmap imgOrg15 (":/resurs/img/микроорганизм_1.png");
                MicOrg[i].stepX = -1;
                MicOrg[i].stepY = 1;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_15->width();
                MicOrg[i].size_h = ui->img_mic_org_15->height();
                ui->img_mic_org_15->setPixmap(imgOrg15.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_15->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 15:
            {
                QPixmap imgOrg16 (":/resurs/img/микроорганизм_1.png");
                MicOrg[i].stepX = 2;
                MicOrg[i].stepY = -1;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_16->width();
                MicOrg[i].size_h = ui->img_mic_org_16->height();
                ui->img_mic_org_16->setPixmap(imgOrg16.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_16->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 16:
            {
                QPixmap imgOrg17 (":/resurs/img/микроорганизм_2.png");
                MicOrg[i].stepX = 1;
                MicOrg[i].stepY = 2;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_17->width();
                MicOrg[i].size_h = ui->img_mic_org_17->height();
                ui->img_mic_org_17->setPixmap(imgOrg17.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_17->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 17:
            {
                QPixmap imgOrg18 (":/resurs/img/микроорганизм_3.png");
                MicOrg[i].stepX = 1;
                MicOrg[i].stepY = -1;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_18->width();
                MicOrg[i].size_h = ui->img_mic_org_18->height();
                ui->img_mic_org_18->setPixmap(imgOrg18.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_18->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 18:
            {
                QPixmap imgOrg19 (":/resurs/img/микроорганизм_2.png");
                MicOrg[i].stepX = -1;
                MicOrg[i].stepY = 2;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_19->width();
                MicOrg[i].size_h = ui->img_mic_org_19->height();
                ui->img_mic_org_19->setPixmap(imgOrg19.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_19->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 19:
            {
                QPixmap imgOrg20 (":/resurs/img/микроорганизм_1.png");
                MicOrg[i].stepX = -2;
                MicOrg[i].stepY = -1;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_20->width();
                MicOrg[i].size_h = ui->img_mic_org_20->height();
                ui->img_mic_org_20->setPixmap(imgOrg20.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_20->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 20:
            {
                QPixmap imgOrg21 (":/resurs/img/микроорганизм_1.png");
                MicOrg[i].stepX = 1;
                MicOrg[i].stepY = 2;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_21->width();
                MicOrg[i].size_h = ui->img_mic_org_21->height();
                ui->img_mic_org_21->setPixmap(imgOrg21.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_21->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 21:
            {
                QPixmap imgOrg22 (":/resurs/img/микроорганизм_2.png");
                MicOrg[i].stepX = 2;
                MicOrg[i].stepY = -2;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_22->width();
                MicOrg[i].size_h = ui->img_mic_org_22->height();
                ui->img_mic_org_22->setPixmap(imgOrg22.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_22->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 22:
            {
                QPixmap imgOrg23 (":/resurs/img/микроорганизм_3.png");
                MicOrg[i].stepX = -1;
                MicOrg[i].stepY = 1;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_23->width();
                MicOrg[i].size_h = ui->img_mic_org_23->height();
                ui->img_mic_org_23->setPixmap(imgOrg23.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_23->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 23:
            {
                QPixmap imgOrg24 (":/resurs/img/микроорганизм_3.png");
                MicOrg[i].stepX = 2;
                MicOrg[i].stepY = -1;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_24->width();
                MicOrg[i].size_h = ui->img_mic_org_24->height();
                ui->img_mic_org_24->setPixmap(imgOrg24.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_24->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            case 24:
            {
                QPixmap imgOrg25 (":/resurs/img/микроорганизм_2.png");
                MicOrg[i].stepX = -2;
                MicOrg[i].stepY = 1;
                MicOrg[i].posX = (rand()%613 + 30);
                MicOrg[i].posY = (rand()%425 + 20);
                MicOrg[i].size_w = ui->img_mic_org_25->width();
                MicOrg[i].size_h = ui->img_mic_org_25->height();
                ui->img_mic_org_25->setPixmap(imgOrg25.scaled(MicOrg[i].size_w, MicOrg[i].size_h, Qt::KeepAspectRatio));
                ui->img_mic_org_25->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
              break;
            }
            }
        }
        timer_org->start(35);
}



bool MainWindow::eventFilter(QObject *obj, QEvent *event)

{
    if((event->type() == QEvent::MouseButtonPress) && (obj ==  ui->start))
    {
        ui->start->setEnabled(false);
        ui->front_site->setEnabled(false);
        ui->start->setVisible(false);
        ui->front_site->setVisible(false);
    }
    if((event->type() == QEvent::MouseButtonPress) && (obj ==  ui->img_bakt) && (TypeOfFunction != 2) && (TypeOfFunction != 3))
    {    
        ui->img_grib->setEnabled(false);
        ui->img_virus->setEnabled(false);
        TypeOfFunction = 1;
        QPixmap imgStatus1(":/resurs/img/name_bakt.png");
        int w_status = ui->bolez_status->width();
        int h_status = ui->bolez_status->height();
        ui->bolez_status->setPixmap(imgStatus1.scaled(w_status, h_status, Qt::KeepAspectRatio));
        QPixmap imgBakt(":/resurs/img/болезнь_бактерия_вкл.png");
        int w_bolez = ui->img_bakt->width();
        int h_bolez = ui->img_bakt->height();
        ui->img_bakt->setPixmap(imgBakt.scaled(w_bolez, h_bolez, Qt::KeepAspectRatio));
        BaktOrg = new class BoleznOrganize[12];
        for (int i = 0; i < 12; i++)
            {
                switch (i)
                {
                case 0:
                {
                    QPixmap imgBakt1 (":/resurs/img/бактерий_1.png");
                    BaktOrg[i].stepX = 1;
                    BaktOrg[i].stepY = 1;
                    BaktOrg[i].posX = (rand()%613 + 30);
                    BaktOrg[i].posY = (rand()%425 + 20);
                    BaktOrg[i].size_w = ui->bakt_1->width();
                    BaktOrg[i].size_h = ui->bakt_1->height();
                    BaktOrg[i].HP = 2;
                    ui->bakt_1->setPixmap(imgBakt1.scaled(BaktOrg[i].size_w, BaktOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->bakt_1->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    break;
                }
                case 1:
                {
                    QPixmap imgBakt2 (":/resurs/img/бактерия_2.png");
                    BaktOrg[i].stepX = -1;
                    BaktOrg[i].stepY = -1;
                    BaktOrg[i].posX = (rand()%613 + 30);
                    BaktOrg[i].posY = (rand()%425 + 20);
                    BaktOrg[i].size_w = ui->bakt_2->width();
                    BaktOrg[i].size_h = ui->bakt_2->height();
                    BaktOrg[i].HP = 2;
                    ui->bakt_2->setPixmap(imgBakt2.scaled(BaktOrg[i].size_w, BaktOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->bakt_2->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    break;
                }
                case 2:
                {
                    QPixmap imgBakt3 (":/resurs/img/бактерия_3.png");
                    BaktOrg[i].stepX = -1;
                    BaktOrg[i].stepY = 1;
                    BaktOrg[i].posX = (rand()%613 + 30);
                    BaktOrg[i].posY = (rand()%425 + 20);
                    BaktOrg[i].size_w = ui->bakt_3->width();
                    BaktOrg[i].size_h = ui->bakt_3->height();
                    BaktOrg[i].HP = 2;
                    ui->bakt_3->setPixmap(imgBakt3.scaled(BaktOrg[i].size_w, BaktOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->bakt_3->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    break;
                }
                case 3:
                {
                    QPixmap imgBakt4 (":/resurs/img/бактерий_1.png");
                    BaktOrg[i].stepX = 1;
                    BaktOrg[i].stepY = -1;
                    BaktOrg[i].posX = (rand()%613 + 30);
                    BaktOrg[i].posY = (rand()%425 + 20);
                    BaktOrg[i].size_w = ui->bakt_4->width();
                    BaktOrg[i].size_h = ui->bakt_4->height();
                    BaktOrg[i].HP = 2;
                    ui->bakt_4->setPixmap(imgBakt4.scaled(BaktOrg[i].size_w, BaktOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->bakt_4->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    break;
                }
                case 4:
                {
                    QPixmap imgBakt5 (":/resurs/img/бактерия_2.png");
                    BaktOrg[i].stepX = 2;
                    BaktOrg[i].stepY = 1;
                    BaktOrg[i].posX = (rand()%613 + 30);
                    BaktOrg[i].posY = (rand()%425 + 20);
                    BaktOrg[i].size_w = ui->bakt_5->width();
                    BaktOrg[i].size_h = ui->bakt_5->height();
                    BaktOrg[i].HP = 2;
                    ui->bakt_5->setPixmap(imgBakt5.scaled(BaktOrg[i].size_w, BaktOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->bakt_5->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    break;
                }
                case 5:
                {
                    QPixmap imgBakt6 (":/resurs/img/бактерия_3.png");
                    BaktOrg[i].stepX = 1;
                    BaktOrg[i].stepY = 2;
                    BaktOrg[i].posX = (rand()%613 + 30);
                    BaktOrg[i].posY = (rand()%425 + 20);
                    BaktOrg[i].size_w = ui->bakt_6->width();
                    BaktOrg[i].size_h = ui->bakt_6->height();
                    BaktOrg[i].HP = 2;
                    ui->bakt_6->setPixmap(imgBakt6.scaled(BaktOrg[i].size_w, BaktOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->bakt_6->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    break;
                }
                case 6:
                {
                    QPixmap imgBakt7 (":/resurs/img/бактерий_1.png");
                    BaktOrg[i].stepX = -2;
                    BaktOrg[i].stepY = 1;
                    BaktOrg[i].posX = (rand()%613 + 30);
                    BaktOrg[i].posY = (rand()%425 + 20);
                    BaktOrg[i].size_w = ui->bakt_7->width();
                    BaktOrg[i].size_h = ui->bakt_7->height();
                    BaktOrg[i].HP = 2;
                    ui->bakt_7->setPixmap(imgBakt7.scaled(BaktOrg[i].size_w, BaktOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->bakt_7->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                  break;
                }
                case 7:
                {
                    QPixmap imgBakt8 (":/resurs/img/бактерия_2.png");
                    BaktOrg[i].stepX = 1;
                    BaktOrg[i].stepY = -2;
                    BaktOrg[i].posX = (rand()%613 + 30);
                    BaktOrg[i].posY = (rand()%425 + 20);
                    BaktOrg[i].size_w = ui->bakt_8->width();
                    BaktOrg[i].size_h = ui->bakt_8->height();
                    BaktOrg[i].HP = 2;
                    ui->bakt_8->setPixmap(imgBakt8.scaled(BaktOrg[i].size_w, BaktOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->bakt_8->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    break;
                }
                case 8:
                {
                    QPixmap imgBakt9 (":/resurs/img/бактерия_3.png");
                    BaktOrg[i].stepX = 2;
                    BaktOrg[i].stepY = 2;
                    BaktOrg[i].posX = (rand()%613 + 30);
                    BaktOrg[i].posY = (rand()%425 + 20);
                    BaktOrg[i].size_w = ui->bakt_9->width();
                    BaktOrg[i].size_h = ui->bakt_9->height();
                    BaktOrg[i].HP = 2;
                    ui->bakt_9->setPixmap(imgBakt9.scaled(BaktOrg[i].size_w, BaktOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->bakt_9->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    break;
                }
                case 9:
                {
                    QPixmap imgBakt10 (":/resurs/img/бактерий_1.png");
                    BaktOrg[i].stepX = -2;
                    BaktOrg[i].stepY = -2;
                    BaktOrg[i].posX = (rand()%613 + 30);
                    BaktOrg[i].posY = (rand()%425 + 20);
                    BaktOrg[i].size_w = ui->bakt_10->width();
                    BaktOrg[i].size_h = ui->bakt_10->height();
                    BaktOrg[i].HP = 2;
                    ui->bakt_10->setPixmap(imgBakt10.scaled(BaktOrg[i].size_w, BaktOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->bakt_10->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    break;
                }
                case 10:
                {
                    QPixmap imgBakt11 (":/resurs/img/бактерия_2.png");
                    BaktOrg[i].stepX = 2;
                    BaktOrg[i].stepY = -1;
                    BaktOrg[i].posX = (rand()%613 + 30);
                    BaktOrg[i].posY = (rand()%425 + 20);
                    BaktOrg[i].size_w = ui->bakt_11->width();
                    BaktOrg[i].size_h = ui->bakt_11->height();
                    BaktOrg[i].HP = 2;
                    ui->bakt_11->setPixmap(imgBakt11.scaled(BaktOrg[i].size_w, BaktOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->bakt_11->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    break;
                }
                case 11:
                {
                    QPixmap imgBakt12 (":/resurs/img/бактерия_3.png");
                    BaktOrg[i].stepX = -1;
                    BaktOrg[i].stepY = 2;
                    BaktOrg[i].posX = (rand()%613 + 30);
                    BaktOrg[i].posY = (rand()%425 + 20);
                    BaktOrg[i].size_w = ui->bakt_12->width();
                    BaktOrg[i].size_h = ui->bakt_12->height();
                    BaktOrg[i].HP = 2;
                    ui->bakt_12->setPixmap(imgBakt12.scaled(BaktOrg[i].size_w, BaktOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->bakt_12->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    break;
                }
                }
            }

        return true;
    }
    if((event->type() == QEvent::MouseButtonPress) && (obj ==  ui->img_grib) && (TypeOfFunction != 1) && (TypeOfFunction != 3))
    {
        ui->img_bakt->setEnabled(false);
        ui->img_virus->setEnabled(false);
        TypeOfFunction = 2;
        QPixmap imgStatus2(":/resurs/img/name_grib.png");
        int w_status = ui->bolez_status->width();
        int h_status = ui->bolez_status->height();
        ui->bolez_status->setPixmap(imgStatus2.scaled(w_status, h_status, Qt::KeepAspectRatio));
        QPixmap imgGrib(":/resurs/img/болезнь_грибок_вкл.png");
        int w_bolez = ui->img_grib->width();
        int h_bolez = ui->img_grib->height();
        ui->img_grib->setPixmap(imgGrib.scaled(w_bolez, h_bolez, Qt::KeepAspectRatio));
        GribOrg = new class BoleznOrganize[9];
        for (int i = 0; i < 9; i++)
            {
                switch (i)
                {
                case 0:
                {
                    QPixmap imgGrib1 (":/resurs/img/грибок_1.png");
                    GribOrg[i].stepX = 1;
                    GribOrg[i].stepY = -1;
                    GribOrg[i].posX = (rand()%613 + 30);
                    GribOrg[i].posY = (rand()%425 + 20);
                    GribOrg[i].size_w = ui->grib_1->width();
                    GribOrg[i].size_h = ui->grib_1->height();
                    GribOrg[i].HP = 3;
                    ui->grib_1->setPixmap(imgGrib1.scaled(GribOrg[i].size_w, GribOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->grib_1->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                  break;
                }
                case 1:
                {
                    QPixmap imgGrib2 (":/resurs/img/грибок_2.png");
                    GribOrg[i].stepX = -1;
                    GribOrg[i].stepY = 1;
                    GribOrg[i].posX = (rand()%613 + 30);
                    GribOrg[i].posY = (rand()%425 + 20);
                    GribOrg[i].size_w = ui->grib_2->width();
                    GribOrg[i].size_h = ui->grib_2->height();
                    GribOrg[i].HP = 3;
                    ui->grib_2->setPixmap(imgGrib2.scaled(GribOrg[i].size_w, GribOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->grib_2->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                  break;
                }
                case 2:
                {
                    QPixmap imgGrib3 (":/resurs/img/грибок_3.png");
                    GribOrg[i].stepX = 1;
                    GribOrg[i].stepY = 2;
                    GribOrg[i].posX = (rand()%613 + 30);
                    GribOrg[i].posY = (rand()%425 + 20);
                    GribOrg[i].size_w = ui->grib_3->width();
                    GribOrg[i].size_h = ui->grib_3->height();
                    GribOrg[i].HP = 3;
                    ui->grib_3->setPixmap(imgGrib3.scaled(GribOrg[i].size_w, GribOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->grib_3->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                  break;
                }
                case 3:
                {
                    QPixmap imgGrib4 (":/resurs/img/грибок_1.png");
                    GribOrg[i].stepX = 2;
                    GribOrg[i].stepY = 1;
                    GribOrg[i].posX = (rand()%613 + 30);
                    GribOrg[i].posY = (rand()%425 + 20);
                    GribOrg[i].size_w = ui->grib_4->width();
                    GribOrg[i].size_h = ui->grib_4->height();
                    GribOrg[i].HP = 3;
                    ui->grib_4->setPixmap(imgGrib4.scaled(GribOrg[i].size_w, GribOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->grib_4->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                  break;
                }
                case 4:
                {
                    QPixmap imgGrib5 (":/resurs/img/грибок_2.png");
                    GribOrg[i].stepX = -2;
                    GribOrg[i].stepY = 1;
                    GribOrg[i].posX = (rand()%613 + 30);
                    GribOrg[i].posY = (rand()%425 + 20);
                    GribOrg[i].size_w = ui->grib_5->width();
                    GribOrg[i].size_h = ui->grib_5->height();
                    GribOrg[i].HP = 3;
                    ui->grib_5->setPixmap(imgGrib5.scaled(GribOrg[i].size_w, GribOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->grib_5->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                  break;
                }
                case 5:
                {
                    QPixmap imgGrib6 (":/resurs/img/грибок_3.png");
                    GribOrg[i].stepX = -1;
                    GribOrg[i].stepY = 2;
                    GribOrg[i].posX = (rand()%613 + 30);
                    GribOrg[i].posY = (rand()%425 + 20);
                    GribOrg[i].size_w = ui->grib_6->width();
                    GribOrg[i].size_h = ui->grib_6->height();
                    GribOrg[i].HP = 3;
                    ui->grib_6->setPixmap(imgGrib6.scaled(GribOrg[i].size_w, GribOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->grib_6->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                  break;
                }
                case 6:
                {
                    QPixmap imgGrib7 (":/resurs/img/грибок_1.png");
                    GribOrg[i].stepX = -1;
                    GribOrg[i].stepY = -1;
                    GribOrg[i].posX = (rand()%613 + 30);
                    GribOrg[i].posY = (rand()%425 + 20);
                    GribOrg[i].size_w = ui->grib_7->width();
                    GribOrg[i].size_h = ui->grib_7->height();
                    GribOrg[i].HP = 3;
                    ui->grib_7->setPixmap(imgGrib7.scaled(GribOrg[i].size_w, GribOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->grib_7->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                  break;
                }
                case 7:
                {
                    QPixmap imgGrib8 (":/resurs/img/грибок_2.png");
                    GribOrg[i].stepX = 1;
                    GribOrg[i].stepY = 1;
                    GribOrg[i].posX = (rand()%613 + 30);
                    GribOrg[i].posY = (rand()%425 + 20);
                    GribOrg[i].size_w = ui->grib_8->width();
                    GribOrg[i].size_h = ui->grib_8->height();
                    GribOrg[i].HP = 3;
                    ui->grib_8->setPixmap(imgGrib8.scaled(GribOrg[i].size_w, GribOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->grib_8->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                  break;
                }
                case 8:
                {
                    QPixmap imgGrib9 (":/resurs/img/грибок_3.png");
                    GribOrg[i].stepX = 1;
                    GribOrg[i].stepY = 1;
                    GribOrg[i].posX = (rand()%613 + 30);
                    GribOrg[i].posY = (rand()%425 + 20);
                    GribOrg[i].size_w = ui->grib_9->width();
                    GribOrg[i].size_h = ui->grib_9->height();
                    GribOrg[i].HP = 3;
                    ui->grib_9->setPixmap(imgGrib9.scaled(GribOrg[i].size_w, GribOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->grib_9->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                  break;
                }
                }
            }
        return true;
    }
    if((event->type() == QEvent::MouseButtonPress) && (obj ==  ui->img_virus) && (TypeOfFunction != 1) && (TypeOfFunction != 2))
    {
        ui->img_bakt->setEnabled(false);
        ui->img_grib->setEnabled(false);
        TypeOfFunction = 3;
        QPixmap imgStatus3(":/resurs/img/name_virus.png");
        int w_status = ui->bolez_status->width();
        int h_status = ui->bolez_status->height();
        ui->bolez_status->setPixmap(imgStatus3.scaled(w_status, h_status, Qt::KeepAspectRatio));
        QPixmap imgVirus(":/resurs/img/болезнь_вирус_вкл.png");
        int w_bolez = ui->img_virus->width();
        int h_bolez = ui->img_virus->height();
        ui->img_virus->setPixmap(imgVirus.scaled(w_bolez, h_bolez, Qt::KeepAspectRatio));
        VirusOrg = new class BoleznOrganize[6];
        for (int i = 0; i < 6; i++)
            {
                switch (i)
                {
                case 0:
                {
                    QPixmap imgVirus1 (":/resurs/img/вирус_1.png");
                    VirusOrg[i].stepX = 1;
                    VirusOrg[i].stepY = -1;
                    VirusOrg[i].posX = (rand()%613 + 30);
                    VirusOrg[i].posY = (rand()%425 + 20);
                    VirusOrg[i].size_w = ui->virus_1->width();
                    VirusOrg[i].size_h = ui->virus_1->height();
                    VirusOrg[i].HP = 5;
                    ui->virus_1->setPixmap(imgVirus1.scaled(VirusOrg[i].size_w, VirusOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->virus_1->setGeometry(VirusOrg[i].posX, VirusOrg[i].posY, VirusOrg[i].size_w, VirusOrg[i].size_h);
                  break;
                }
                case 1:
                {
                    QPixmap imgVirus2 (":/resurs/img/вирус_2.png");
                    VirusOrg[i].stepX = -1;
                    VirusOrg[i].stepY = 1;
                    VirusOrg[i].posX = (rand()%613 + 30);
                    VirusOrg[i].posY = (rand()%425 + 20);
                    VirusOrg[i].size_w = ui->virus_2->width();
                    VirusOrg[i].size_h = ui->virus_2->height();
                    VirusOrg[i].HP = 5;
                    ui->virus_2->setPixmap(imgVirus2.scaled(VirusOrg[i].size_w, VirusOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->virus_2->setGeometry(VirusOrg[i].posX, VirusOrg[i].posY, VirusOrg[i].size_w, VirusOrg[i].size_h);
                  break;
                }
                case 2:
                {
                    QPixmap imgVirus3 (":/resurs/img/вирус_1.png");
                    VirusOrg[i].stepX = -1;
                    VirusOrg[i].stepY = -1;
                    VirusOrg[i].posX = (rand()%613 + 30);
                    VirusOrg[i].posY = (rand()%425 + 20);
                    VirusOrg[i].size_w = ui->virus_3->width();
                    VirusOrg[i].size_h = ui->virus_3->height();
                    VirusOrg[i].HP = 5;
                    ui->virus_3->setPixmap(imgVirus3.scaled(VirusOrg[i].size_w, VirusOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->virus_3->setGeometry(VirusOrg[i].posX, VirusOrg[i].posY, VirusOrg[i].size_w, VirusOrg[i].size_h);
                  break;
                }
                case 3:
                {
                    QPixmap imgVirus4 (":/resurs/img/вирус_2.png");
                    VirusOrg[i].stepX = 1;
                    VirusOrg[i].stepY = 1;
                    VirusOrg[i].posX = (rand()%613 + 30);
                    VirusOrg[i].posY = (rand()%425 + 20);
                    VirusOrg[i].size_w = ui->virus_4->width();
                    VirusOrg[i].size_h = ui->virus_4->height();
                    VirusOrg[i].HP = 5;
                    ui->virus_4->setPixmap(imgVirus4.scaled(VirusOrg[i].size_w, VirusOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->virus_4->setGeometry(VirusOrg[i].posX, VirusOrg[i].posY, VirusOrg[i].size_w, VirusOrg[i].size_h);
                  break;
                }
                case 4:
                {
                    QPixmap imgVirus5 (":/resurs/img/вирус_1.png");
                    VirusOrg[i].stepX = 1;
                    VirusOrg[i].stepY = -2;
                    VirusOrg[i].posX = (rand()%613 + 30);
                    VirusOrg[i].posY = (rand()%425 + 20);
                    VirusOrg[i].size_w = ui->virus_5->width();
                    VirusOrg[i].size_h = ui->virus_5->height();
                    VirusOrg[i].HP = 5;
                    ui->virus_5->setPixmap(imgVirus5.scaled(VirusOrg[i].size_w, VirusOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->virus_5->setGeometry(VirusOrg[i].posX, VirusOrg[i].posY, VirusOrg[i].size_w, VirusOrg[i].size_h);
                  break;
                }
                case 5:
                {
                    QPixmap imgVirus6 (":/resurs/img/вирус_2.png");
                    VirusOrg[i].stepX = 2;
                    VirusOrg[i].stepY = 1;
                    VirusOrg[i].posX = (rand()%613 + 30);
                    VirusOrg[i].posY = (rand()%425 + 20);
                    VirusOrg[i].size_w = ui->virus_6->width();
                    VirusOrg[i].size_h = ui->virus_6->height();
                    VirusOrg[i].HP = 5;
                    ui->virus_6->setPixmap(imgVirus6.scaled(VirusOrg[i].size_w, VirusOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->virus_6->setGeometry(VirusOrg[i].posX, VirusOrg[i].posY, VirusOrg[i].size_w, VirusOrg[i].size_h);
                  break;
                }
                }
            }

        return true;
    }
    if((event->type() == QEvent::MouseButtonPress) && (obj ==  ui->img_tabl) && (TypeOfLecarstvo != 2))
    {
        ui->img_antib->setEnabled(false);
        TypeOfLecarstvo = 1;
        QPixmap imgTabl(":/resurs/img/лекарство_таблетки_вкл.png");
        int w_lec = ui->img_tabl->width();
        int h_lec = ui->img_tabl->height();
        ui->img_tabl->setPixmap(imgTabl.scaled(w_lec, h_lec, Qt::KeepAspectRatio));
        TablOrg = new class LecarstvoOrganize[5];
        for (int i = 0; i < 5; i++)
            {
                switch (i)
                {
                case 0:
                {
                    QPixmap imgTabl1 (":/resurs/img/Таблетки_орг.png");
                    TablOrg[i].stepX = -1;
                    TablOrg[i].stepY = 1;
                    TablOrg[i].posX = (rand()%613 + 30);
                    TablOrg[i].posY = (rand()%425 + 20);
                    TablOrg[i].size_w = ui->tabl_1->width();
                    TablOrg[i].size_h = ui->tabl_1->height();
                    ui->tabl_1->setPixmap(imgTabl1.scaled(TablOrg[i].size_w, TablOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->tabl_1->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                  break;
                }
                case 1:
                {
                    QPixmap imgTabl2 (":/resurs/img/Таблетки_орг.png");
                    TablOrg[i].stepX = 1;
                    TablOrg[i].stepY = -1;
                    TablOrg[i].posX = (rand()%613 + 30);
                    TablOrg[i].posY = (rand()%425 + 20);
                    TablOrg[i].size_w = ui->tabl_2->width();
                    TablOrg[i].size_h = ui->tabl_2->height();
                    ui->tabl_2->setPixmap(imgTabl2.scaled(TablOrg[i].size_w, TablOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->tabl_2->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                  break;
                }
                case 2:
                {
                    QPixmap imgTabl3 (":/resurs/img/Таблетки_орг.png");
                    TablOrg[i].stepX = -1;
                    TablOrg[i].stepY = -1;
                    TablOrg[i].posX = (rand()%613 + 30);
                    TablOrg[i].posY = (rand()%425 + 20);
                    TablOrg[i].size_w = ui->tabl_3->width();
                    TablOrg[i].size_h = ui->tabl_3->height();
                    ui->tabl_3->setPixmap(imgTabl3.scaled(TablOrg[i].size_w, TablOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->tabl_3->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                  break;
                }
                case 3:
                {
                    QPixmap imgTabl4 (":/resurs/img/Таблетки_орг.png");
                    TablOrg[i].stepX = 1;
                    TablOrg[i].stepY = 1;
                    TablOrg[i].posX = (rand()%613 + 30);
                    TablOrg[i].posY = (rand()%425 + 20);
                    TablOrg[i].size_w = ui->tabl_4->width();
                    TablOrg[i].size_h = ui->tabl_4->height();
                    ui->tabl_4->setPixmap(imgTabl4.scaled(TablOrg[i].size_w, TablOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->tabl_4->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                  break;
                }
                case 4:
                {
                    QPixmap imgTabl5 (":/resurs/img/Таблетки_орг.png");
                    TablOrg[i].stepX = 1;
                    TablOrg[i].stepY = 1;
                    TablOrg[i].posX = (rand()%613 + 30);
                    TablOrg[i].posY = (rand()%425 + 20);
                    TablOrg[i].size_w = ui->tabl_5->width();
                    TablOrg[i].size_h = ui->tabl_5->height();
                    ui->tabl_5->setPixmap(imgTabl5.scaled(TablOrg[i].size_w, TablOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->tabl_5->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                  break;
                }
                }
            }

        return true;
    }
    if((event->type() == QEvent::MouseButtonPress) && (obj ==  ui->img_antib) && (TypeOfLecarstvo != 1))
    {
        TypeOfLecarstvo = 2;
        ui->img_tabl->setEnabled(false);
        QPixmap imgAntib(":/resurs/img/лекарство_антибиотики_вкл.png");
        int w_lec = ui->img_antib->width();
        int h_lec = ui->img_antib->height();
        ui->img_antib->setPixmap(imgAntib.scaled(w_lec, h_lec, Qt::KeepAspectRatio));
        AntibOrg = new class LecarstvoOrganize[5];
        for (int i = 0; i < 6; i++)
            {
                switch (i)
                {
                case 0:
                {
                    QPixmap imgAntib1 (":/resurs/img/Антибиотики_орг.png");
                    AntibOrg[i].stepX = -1;
                    AntibOrg[i].stepY = 1;
                    AntibOrg[i].HP = 2;
                    AntibOrg[i].posX = (rand()%613 + 30);
                    AntibOrg[i].posY = (rand()%425 + 20);
                    AntibOrg[i].size_w = ui->antib_1->width();
                    AntibOrg[i].size_h = ui->antib_1->height();
                    ui->antib_1->setPixmap(imgAntib1.scaled(AntibOrg[i].size_w, AntibOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->antib_1->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                  break;
                }
                case 1:
                {
                    QPixmap imgAntib2 (":/resurs/img/Антибиотики_орг.png");
                    AntibOrg[i].stepX = 1;
                    AntibOrg[i].stepY = -1;
                    AntibOrg[i].HP = 2;
                    AntibOrg[i].posX = (rand()%613 + 30);
                    AntibOrg[i].posY = (rand()%425 + 20);
                    AntibOrg[i].size_w = ui->antib_2->width();
                    AntibOrg[i].size_h = ui->antib_2->height();
                    ui->antib_2->setPixmap(imgAntib2.scaled(AntibOrg[i].size_w, AntibOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->antib_2->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                  break;
                }
                case 2:
                {
                    QPixmap imgAntib3 (":/resurs/img/Антибиотики_орг.png");
                    AntibOrg[i].stepX = -1;
                    AntibOrg[i].stepY = -1;
                    AntibOrg[i].HP = 2;
                    AntibOrg[i].posX = (rand()%613 + 30);
                    AntibOrg[i].posY = (rand()%425 + 20);
                    AntibOrg[i].size_w = ui->antib_3->width();
                    AntibOrg[i].size_h = ui->antib_3->height();
                    ui->antib_3->setPixmap(imgAntib3.scaled(AntibOrg[i].size_w, AntibOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->antib_3->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                  break;
                }
                case 3:
                {
                    QPixmap imgAntib4 (":/resurs/img/Антибиотики_орг.png");
                    AntibOrg[i].stepX = 1;
                    AntibOrg[i].stepY = 1;
                    AntibOrg[i].HP = 2;
                    AntibOrg[i].posX = (rand()%613 + 30);
                    AntibOrg[i].posY = (rand()%425 + 20);
                    AntibOrg[i].size_w = ui->antib_4->width();
                    AntibOrg[i].size_h = ui->antib_4->height();
                    ui->antib_4->setPixmap(imgAntib4.scaled(AntibOrg[i].size_w, AntibOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->antib_4->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                  break;
                }
                case 4:
                {
                    QPixmap imgAntib5 (":/resurs/img/Антибиотики_орг.png");
                    AntibOrg[i].stepX = 1;
                    AntibOrg[i].stepY = 1;
                    AntibOrg[i].HP = 2;
                    AntibOrg[i].posX = (rand()%613 + 30);
                    AntibOrg[i].posY = (rand()%425 + 20);
                    AntibOrg[i].size_w = ui->antib_5->width();
                    AntibOrg[i].size_h = ui->antib_5->height();
                    ui->antib_5->setPixmap(imgAntib5.scaled(AntibOrg[i].size_w, AntibOrg[i].size_h, Qt::KeepAspectRatio));
                    ui->antib_5->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                  break;
                }
                }
            }

        return true;
    }
    else
    {
         return QObject::eventFilter(obj, event);
    }
}

void MainWindow::TimerSlot_org()
{
    if (CountOfOrganize >= 20)
    {
        QPixmap imgPerson(":/resurs/img/фаза_0.png");
        int w_person = ui->img_person->width();
        int h_person = ui->img_person->height();
        ui->img_person->setPixmap(imgPerson.scaled(w_person, h_person, Qt::KeepAspectRatio));
        QPixmap imgStatus(":/resurs/img/sost_otlich.png");
        int w_status2 = ui->stepen_status->width();
        int h_status2 = ui->stepen_status->height();
        ui->stepen_status->setPixmap(imgStatus.scaled(w_status2, h_status2, Qt::KeepAspectRatio));

    }
    else
        if ((CountOfOrganize < 20) && (CountOfOrganize >= 15) && (TypeOfFunction == 3))
        {
            QPixmap imgPerson(":/resurs/img/фаза_1_1.png");
            int w_person = ui->img_person->width();
            int h_person = ui->img_person->height();
            ui->img_person->setPixmap(imgPerson.scaled(w_person, h_person, Qt::KeepAspectRatio));
            QPixmap imgStatus(":/resurs/img/sost_norm.png");
            int w_status2 = ui->stepen_status->width();
            int h_status2 = ui->stepen_status->height();
            ui->stepen_status->setPixmap(imgStatus.scaled(w_status2, h_status2, Qt::KeepAspectRatio));

        }
        else
            if ((CountOfOrganize < 20) && (CountOfOrganize >= 15) && (TypeOfFunction == 2))
            {
                QPixmap imgPerson(":/resurs/img/фаза_2_1.png");
                int w_person = ui->img_person->width();
                int h_person = ui->img_person->height();
                ui->img_person->setPixmap(imgPerson.scaled(w_person, h_person, Qt::KeepAspectRatio));
                QPixmap imgStatus(":/resurs/img/sost_norm.png");
                int w_status2 = ui->stepen_status->width();
                int h_status2 = ui->stepen_status->height();
                ui->stepen_status->setPixmap(imgStatus.scaled(w_status2, h_status2, Qt::KeepAspectRatio));
            }
            else
                if ((CountOfOrganize < 20) && (CountOfOrganize >= 15) && (TypeOfFunction == 1))
                {
                    QPixmap imgPerson(":/resurs/img/фаза_3_1.png");
                    int w_person = ui->img_person->width();
                    int h_person = ui->img_person->height();
                    ui->img_person->setPixmap(imgPerson.scaled(w_person, h_person, Qt::KeepAspectRatio));
                    QPixmap imgStatus(":/resurs/img/sost_norm.png");
                    int w_status2 = ui->stepen_status->width();
                    int h_status2 = ui->stepen_status->height();
                    ui->stepen_status->setPixmap(imgStatus.scaled(w_status2, h_status2, Qt::KeepAspectRatio));
                }
                else
                    if ((CountOfOrganize < 15) && (CountOfOrganize >= 10) && (TypeOfFunction == 3))
                    {
                        QPixmap imgPerson(":/resurs/img/фаза_1_2.png");
                        int w_person = ui->img_person->width();
                        int h_person = ui->img_person->height();
                        ui->img_person->setPixmap(imgPerson.scaled(w_person, h_person, Qt::KeepAspectRatio));
                        QPixmap imgStatus(":/resurs/img/sost_bad.png");
                        int w_status2 = ui->stepen_status->width();
                        int h_status2 = ui->stepen_status->height();
                        ui->stepen_status->setPixmap(imgStatus.scaled(w_status2, h_status2, Qt::KeepAspectRatio));
                    }
                    else
                        if ((CountOfOrganize < 15) && (CountOfOrganize >= 10) && (TypeOfFunction == 2))
                        {
                            QPixmap imgPerson(":/resurs/img/фаза_2_2.png");
                            int w_person = ui->img_person->width();
                            int h_person = ui->img_person->height();
                            ui->img_person->setPixmap(imgPerson.scaled(w_person, h_person, Qt::KeepAspectRatio));
                            QPixmap imgStatus(":/resurs/img/sost_bad.png");
                            int w_status2 = ui->stepen_status->width();
                            int h_status2 = ui->stepen_status->height();
                            ui->stepen_status->setPixmap(imgStatus.scaled(w_status2, h_status2, Qt::KeepAspectRatio));
                        }
                        else
                            if ((CountOfOrganize < 15) && (CountOfOrganize >= 10) && (TypeOfFunction == 1))
                            {
                                QPixmap imgPerson(":/resurs/img/фаза_3_2.png");
                                int w_person = ui->img_person->width();
                                int h_person = ui->img_person->height();
                                ui->img_person->setPixmap(imgPerson.scaled(w_person, h_person, Qt::KeepAspectRatio));
                                QPixmap imgStatus(":/resurs/img/sost_bad.png");
                                int w_status2 = ui->stepen_status->width();
                                int h_status2 = ui->stepen_status->height();
                                ui->stepen_status->setPixmap(imgStatus.scaled(w_status2, h_status2, Qt::KeepAspectRatio));
                            }
                            else
                                if ((CountOfOrganize < 10) && (CountOfOrganize >= 5) && (TypeOfFunction == 3))
                                {
                                    QPixmap imgPerson(":/resurs/img/фаза_1_3.png");
                                    int w_person = ui->img_person->width();
                                    int h_person = ui->img_person->height();
                                    ui->img_person->setPixmap(imgPerson.scaled(w_person, h_person, Qt::KeepAspectRatio));
                                    QPixmap imgStatus(":/resurs/img/sost_ujas.png");
                                    int w_status2 = ui->stepen_status->width();
                                    int h_status2 = ui->stepen_status->height();
                                    ui->stepen_status->setPixmap(imgStatus.scaled(w_status2, h_status2, Qt::KeepAspectRatio));
                                }
                                else
                                    if ((CountOfOrganize < 10) && (CountOfOrganize >= 5) && (TypeOfFunction == 2))
                                    {
                                        QPixmap imgPerson(":/resurs/img/фаза_2_3.png");
                                        int w_person = ui->img_person->width();
                                        int h_person = ui->img_person->height();
                                        ui->img_person->setPixmap(imgPerson.scaled(w_person, h_person, Qt::KeepAspectRatio));
                                        QPixmap imgStatus(":/resurs/img/sost_ujas.png");
                                        int w_status2 = ui->stepen_status->width();
                                        int h_status2 = ui->stepen_status->height();
                                        ui->stepen_status->setPixmap(imgStatus.scaled(w_status2, h_status2, Qt::KeepAspectRatio));
                                    }
                                    else
                                        if ((CountOfOrganize < 10) && (CountOfOrganize >= 5) && (TypeOfFunction == 1))
                                        {
                                            QPixmap imgPerson(":/resurs/img/фаза_3_3.png");
                                            int w_person = ui->img_person->width();
                                            int h_person = ui->img_person->height();
                                            ui->img_person->setPixmap(imgPerson.scaled(w_person, h_person, Qt::KeepAspectRatio));
                                            QPixmap imgStatus(":/resurs/img/sost_ujas.png");
                                            int w_status2 = ui->stepen_status->width();
                                            int h_status2 = ui->stepen_status->height();
                                            ui->stepen_status->setPixmap(imgStatus.scaled(w_status2, h_status2, Qt::KeepAspectRatio));
                                        }
                                        else
                                            if ((CountOfOrganize < 5) && (TypeOfFunction == 3))
                                            {
                                                QPixmap imgPerson(":/resurs/img/фаза_1_4.png");
                                                int w_person = ui->img_person->width();
                                                int h_person = ui->img_person->height();
                                                ui->img_person->setPixmap(imgPerson.scaled(w_person, h_person, Qt::KeepAspectRatio));
                                                QPixmap imgStatus(":/resurs/img/sost_smert.png");
                                                int w_status2 = ui->stepen_status->width();
                                                int h_status2 = ui->stepen_status->height();
                                                ui->stepen_status->setPixmap(imgStatus.scaled(w_status2, h_status2, Qt::KeepAspectRatio));
                                            }
                                            else
                                                if ((CountOfOrganize < 5) && (TypeOfFunction == 2))
                                                {
                                                    QPixmap imgPerson(":/resurs/img/фаза_2_4.png");
                                                    int w_person = ui->img_person->width();
                                                    int h_person = ui->img_person->height();
                                                    ui->img_person->setPixmap(imgPerson.scaled(w_person, h_person, Qt::KeepAspectRatio));
                                                    QPixmap imgStatus(":/resurs/img/sost_smert.png");
                                                    int w_status2 = ui->stepen_status->width();
                                                    int h_status2 = ui->stepen_status->height();
                                                    ui->stepen_status->setPixmap(imgStatus.scaled(w_status2, h_status2, Qt::KeepAspectRatio));
                                                }
                                                else
                                                    if ((CountOfOrganize < 5) && (TypeOfFunction == 1))
                                                    {
                                                        QPixmap imgPerson(":/resurs/img/фаза_3_4.png");
                                                        int w_person = ui->img_person->width();
                                                        int h_person = ui->img_person->height();
                                                        ui->img_person->setPixmap(imgPerson.scaled(w_person, h_person, Qt::KeepAspectRatio));
                                                        QPixmap imgStatus(":/resurs/img/sost_smert.png");
                                                        int w_status2 = ui->stepen_status->width();
                                                        int h_status2 = ui->stepen_status->height();
                                                        ui->stepen_status->setPixmap(imgStatus.scaled(w_status2, h_status2, Qt::KeepAspectRatio));
                                                    }
    for (int i = 0; i < 25; i++)
    {
        switch (i)
        {
        case 0:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_1->width();
                MicOrg[i].size_h = ui->img_mic_org_1->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_1->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_1->setVisible(false);
                ui->img_mic_org_1->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_1->x();
            MicOrg[i].posY = ui->img_mic_org_1->y();
            MicOrg[i].size_w = ui->img_mic_org_1->width();
            MicOrg[i].size_h = ui->img_mic_org_1->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 22))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_1->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 1:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_2->width();
                MicOrg[i].size_h = ui->img_mic_org_2->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_2->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_2->setVisible(false);
                ui->img_mic_org_2->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_2->x();
            MicOrg[i].posY = ui->img_mic_org_2->y();
            MicOrg[i].size_w = ui->img_mic_org_2->width();
            MicOrg[i].size_h = ui->img_mic_org_2->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_2->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 2:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_3->width();
                MicOrg[i].size_h = ui->img_mic_org_3->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_3->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_3->setVisible(false);
                ui->img_mic_org_3->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_3->x();
            MicOrg[i].posY = ui->img_mic_org_3->y();
            MicOrg[i].size_w = ui->img_mic_org_3->width();
            MicOrg[i].size_h = ui->img_mic_org_3->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_3->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 3:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_4->width();
                MicOrg[i].size_h = ui->img_mic_org_4->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_4->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_4->setVisible(false);
                ui->img_mic_org_4->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_4->x();
            MicOrg[i].posY = ui->img_mic_org_4->y();
            MicOrg[i].size_w = ui->img_mic_org_4->width();
            MicOrg[i].size_h = ui->img_mic_org_4->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_4->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 4:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_5->width();
                MicOrg[i].size_h = ui->img_mic_org_5->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_5->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_5->setVisible(false);
                ui->img_mic_org_5->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_5->x();
            MicOrg[i].posY = ui->img_mic_org_5->y();
            MicOrg[i].size_w = ui->img_mic_org_5->width();
            MicOrg[i].size_h = ui->img_mic_org_5->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_5->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
         }
         case 5:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_6->width();
                MicOrg[i].size_h = ui->img_mic_org_6->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_6->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_6->setVisible(false);
                ui->img_mic_org_6->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_6->x();
            MicOrg[i].posY = ui->img_mic_org_6->y();
            MicOrg[i].size_w = ui->img_mic_org_6->width();
            MicOrg[i].size_h = ui->img_mic_org_6->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_6->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 6:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_7->width();
                MicOrg[i].size_h = ui->img_mic_org_7->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_7->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_7->setVisible(false);
                ui->img_mic_org_7->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_7->x();
            MicOrg[i].posY = ui->img_mic_org_7->y();
            MicOrg[i].size_w = ui->img_mic_org_7->width();
            MicOrg[i].size_h = ui->img_mic_org_7->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_7->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 7:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_8->width();
                MicOrg[i].size_h = ui->img_mic_org_8->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_8->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_8->setVisible(false);
                ui->img_mic_org_8->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_8->x();
            MicOrg[i].posY = ui->img_mic_org_8->y();
            MicOrg[i].size_w = ui->img_mic_org_8->width();
            MicOrg[i].size_h = ui->img_mic_org_8->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_8->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 8:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_9->width();
                MicOrg[i].size_h = ui->img_mic_org_9->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_9->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_9->setVisible(false);
                ui->img_mic_org_9->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_9->x();
            MicOrg[i].posY = ui->img_mic_org_9->y();
            MicOrg[i].size_w = ui->img_mic_org_9->width();
            MicOrg[i].size_h = ui->img_mic_org_9->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_9->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 9:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_10->width();
                MicOrg[i].size_h = ui->img_mic_org_10->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_10->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_10->setVisible(false);
                ui->img_mic_org_10->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_10->x();
            MicOrg[i].posY = ui->img_mic_org_10->y();
            MicOrg[i].size_w = ui->img_mic_org_10->width();
            MicOrg[i].size_h = ui->img_mic_org_10->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_10->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 10:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_11->width();
                MicOrg[i].size_h = ui->img_mic_org_11->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_11->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_11->setVisible(false);
                ui->img_mic_org_11->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_11->x();
            MicOrg[i].posY = ui->img_mic_org_11->y();
            MicOrg[i].size_w = ui->img_mic_org_11->width();
            MicOrg[i].size_h = ui->img_mic_org_11->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_11->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 11:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_12->width();
                MicOrg[i].size_h = ui->img_mic_org_12->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_12->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_12->setVisible(false);
                ui->img_mic_org_12->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_12->x();
            MicOrg[i].posY = ui->img_mic_org_12->y();
            MicOrg[i].size_w = ui->img_mic_org_12->width();
            MicOrg[i].size_h = ui->img_mic_org_12->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_12->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 12:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_13->width();
                MicOrg[i].size_h = ui->img_mic_org_13->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_13->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_13->setVisible(false);
                ui->img_mic_org_13->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_13->x();
            MicOrg[i].posY = ui->img_mic_org_13->y();
            MicOrg[i].size_w = ui->img_mic_org_13->width();
            MicOrg[i].size_h = ui->img_mic_org_13->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_13->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 13:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_14->width();
                MicOrg[i].size_h = ui->img_mic_org_14->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_14->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_14->setVisible(false);
                ui->img_mic_org_14->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_14->x();
            MicOrg[i].posY = ui->img_mic_org_14->y();
            MicOrg[i].size_w = ui->img_mic_org_14->width();
            MicOrg[i].size_h = ui->img_mic_org_14->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_14->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 14:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_15->width();
                MicOrg[i].size_h = ui->img_mic_org_15->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_15->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_15->setVisible(false);
                ui->img_mic_org_15->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_15->x();
            MicOrg[i].posY = ui->img_mic_org_15->y();
            MicOrg[i].size_w = ui->img_mic_org_15->width();
            MicOrg[i].size_h = ui->img_mic_org_15->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_15->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 15:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_16->width();
                MicOrg[i].size_h = ui->img_mic_org_16->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_16->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_16->setVisible(false);
                ui->img_mic_org_16->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_16->x();
            MicOrg[i].posY = ui->img_mic_org_16->y();
            MicOrg[i].size_w = ui->img_mic_org_16->width();
            MicOrg[i].size_h = ui->img_mic_org_16->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_16->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 16:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_17->width();
                MicOrg[i].size_h = ui->img_mic_org_17->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_17->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_17->setVisible(false);
                ui->img_mic_org_17->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_17->x();
            MicOrg[i].posY = ui->img_mic_org_17->y();
            MicOrg[i].size_w = ui->img_mic_org_17->width();
            MicOrg[i].size_h = ui->img_mic_org_17->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_17->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 17:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_18->width();
                MicOrg[i].size_h = ui->img_mic_org_18->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_18->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_18->setVisible(false);
                ui->img_mic_org_18->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_18->x();
            MicOrg[i].posY = ui->img_mic_org_18->y();
            MicOrg[i].size_w = ui->img_mic_org_18->width();
            MicOrg[i].size_h = ui->img_mic_org_18->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_18->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 18:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_19->width();
                MicOrg[i].size_h = ui->img_mic_org_19->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_19->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_19->setVisible(false);
                ui->img_mic_org_19->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_19->x();
            MicOrg[i].posY = ui->img_mic_org_19->y();
            MicOrg[i].size_w = ui->img_mic_org_19->width();
            MicOrg[i].size_h = ui->img_mic_org_19->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_19->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 19:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_20->width();
                MicOrg[i].size_h = ui->img_mic_org_20->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_20->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_20->setVisible(false);
                ui->img_mic_org_20->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_20->x();
            MicOrg[i].posY = ui->img_mic_org_20->y();
            MicOrg[i].size_w = ui->img_mic_org_20->width();
            MicOrg[i].size_h = ui->img_mic_org_20->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_20->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 20:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_21->width();
                MicOrg[i].size_h = ui->img_mic_org_21->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_21->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_21->setVisible(false);
                ui->img_mic_org_21->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_21->x();
            MicOrg[i].posY = ui->img_mic_org_21->y();
            MicOrg[i].size_w = ui->img_mic_org_21->width();
            MicOrg[i].size_h = ui->img_mic_org_21->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_21->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 21:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_22->width();
                MicOrg[i].size_h = ui->img_mic_org_22->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_22->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_22->setVisible(false);
                ui->img_mic_org_22->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_22->x();
            MicOrg[i].posY = ui->img_mic_org_22->y();
            MicOrg[i].size_w = ui->img_mic_org_22->width();
            MicOrg[i].size_h = ui->img_mic_org_22->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_22->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 22:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_23->width();
                MicOrg[i].size_h = ui->img_mic_org_23->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_23->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_23->setVisible(false);
                ui->img_mic_org_23->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_23->x();
            MicOrg[i].posY = ui->img_mic_org_23->y();
            MicOrg[i].size_w = ui->img_mic_org_23->width();
            MicOrg[i].size_h = ui->img_mic_org_23->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_23->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 23:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_24->width();
                MicOrg[i].size_h = ui->img_mic_org_24->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_24->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_24->setVisible(false);
                ui->img_mic_org_24->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_24->x();
            MicOrg[i].posY = ui->img_mic_org_24->y();
            MicOrg[i].size_w = ui->img_mic_org_24->width();
            MicOrg[i].size_h = ui->img_mic_org_24->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_24->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        case 24:
        {
            if (MicOrg[i].dead == true)
            {
                MicOrg[i].size_w = ui->img_mic_org_25->width();
                MicOrg[i].size_h = ui->img_mic_org_25->height();
                MicOrg[i].posX = 0;
                MicOrg[i].posY = 0;
                ui->img_mic_org_25->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
                ui->img_mic_org_25->setVisible(false);
                ui->img_mic_org_25->setEnabled(false);
            }
            else
            {
            MicOrg[i].posX = ui->img_mic_org_25->x();
            MicOrg[i].posY = ui->img_mic_org_25->y();
            MicOrg[i].size_w = ui->img_mic_org_25->width();
            MicOrg[i].size_h = ui->img_mic_org_25->height();
            MicOrg[i].posX += MicOrg[i].stepX;
            if ((MicOrg[i].posX > 642) || (MicOrg[i].posX < 30))
            {
                MicOrg[i].stepX = -MicOrg[i].stepX;
            }
            MicOrg[i].posY += MicOrg[i].stepY;
            if ((MicOrg[i].posY > 445) || (MicOrg[i].posY < 20))
            {
                MicOrg[i].stepY = -MicOrg[i].stepY;
            }
            ui->img_mic_org_25->setGeometry(MicOrg[i].posX, MicOrg[i].posY, MicOrg[i].size_w, MicOrg[i].size_h);
            }
          break;
        }
        }
    }
    switch (TypeOfFunction) {
        case 0:
    {
        break;
    }
        case 1:
    {
        for (int i = 0; i < 12; i++)
        {
            switch (i)
            {
            case 0:
            {
                if (BaktOrg[i].HP > 0)
                {
                BaktOrg[i].posX = ui->bakt_1->x();
                BaktOrg[i].posY = ui->bakt_1->y();
                BaktOrg[i].size_w = ui->bakt_1->width();
                BaktOrg[i].size_h = ui->bakt_1->height();
                BaktOrg[i].posX += BaktOrg[i].stepX;
                if ((BaktOrg[i].posX > 642) || (BaktOrg[i].posX < 30))
                {
                    BaktOrg[i].stepX = -BaktOrg[i].stepX;
                }
                BaktOrg[i].posY += BaktOrg[i].stepY;
                if ((BaktOrg[i].posY > 445) || (BaktOrg[i].posY < 22))
                {

                    BaktOrg[i].stepY = -BaktOrg[i].stepY;
                }
                ui->bakt_1->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= BaktOrg[i].posX) && ((MicOrg[j].posX + 15) >= BaktOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= BaktOrg[i].posY) && ((MicOrg[j].posY + 15) >= BaktOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        BaktOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    BaktOrg[i].size_w = ui->bakt_1->width();
                    BaktOrg[i].size_h = ui->bakt_1->height();
                    BaktOrg[i].posX = 1080;
                    BaktOrg[i].posY = 720;
                    ui->bakt_1->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    ui->bakt_1->setVisible(false);
                    ui->bakt_1->setEnabled(false);
                }
              break;
            }
            case 1:
            {
                if (BaktOrg[i].HP > 0)
                {
                BaktOrg[i].posX = ui->bakt_2->x();
                BaktOrg[i].posY = ui->bakt_2->y();
                BaktOrg[i].size_w = ui->bakt_2->width();
                BaktOrg[i].size_h = ui->bakt_2->height();
                BaktOrg[i].posX += BaktOrg[i].stepX;
                if ((BaktOrg[i].posX > 642) || (BaktOrg[i].posX < 30))
                {
                    BaktOrg[i].stepX = -BaktOrg[i].stepX;
                }
                BaktOrg[i].posY += BaktOrg[i].stepY;
                if ((BaktOrg[i].posY > 445) || (BaktOrg[i].posY < 20))
                {
                    BaktOrg[i].stepY = -BaktOrg[i].stepY;
                }
                ui->bakt_2->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= BaktOrg[i].posX) && ((MicOrg[j].posX + 15) >= BaktOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= BaktOrg[i].posY) && ((MicOrg[j].posY + 15) >= BaktOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        BaktOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    BaktOrg[i].size_w = ui->bakt_2->width();
                    BaktOrg[i].size_h = ui->bakt_2->height();
                    BaktOrg[i].posX = 1080;
                    BaktOrg[i].posY = 720;
                    ui->bakt_2->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    ui->bakt_2->setVisible(false);
                    ui->bakt_2->setEnabled(false);
                }
              break;
            }
            case 2:
            {
                if (BaktOrg[i].HP > 0)
                {
                BaktOrg[i].posX = ui->bakt_3->x();
                BaktOrg[i].posY = ui->bakt_3->y();
                BaktOrg[i].size_w = ui->bakt_3->width();
                BaktOrg[i].size_h = ui->bakt_3->height();
                BaktOrg[i].posX += BaktOrg[i].stepX;
                if ((BaktOrg[i].posX > 642) || (BaktOrg[i].posX < 30))
                {
                    BaktOrg[i].stepX = -BaktOrg[i].stepX;
                }
                BaktOrg[i].posY += BaktOrg[i].stepY;
                if ((BaktOrg[i].posY > 445) || (BaktOrg[i].posY < 20))
                {
                    BaktOrg[i].stepY = -BaktOrg[i].stepY;
                }
                ui->bakt_3->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= BaktOrg[i].posX) && ((MicOrg[j].posX + 15) >= BaktOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= BaktOrg[i].posY) && ((MicOrg[j].posY + 15) >= BaktOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        BaktOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    BaktOrg[i].size_w = ui->bakt_3->width();
                    BaktOrg[i].size_h = ui->bakt_3->height();
                    BaktOrg[i].posX = 1080;
                    BaktOrg[i].posY = 720;
                    ui->bakt_3->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    ui->bakt_3->setVisible(false);
                    ui->bakt_3->setEnabled(false);
                }
              break;
            }
            case 3:
            {
                if (BaktOrg[i].HP > 0)
                {
                BaktOrg[i].posX = ui->bakt_4->x();
                BaktOrg[i].posY = ui->bakt_4->y();
                BaktOrg[i].size_w = ui->bakt_4->width();
                BaktOrg[i].size_h = ui->bakt_4->height();
                BaktOrg[i].posX += BaktOrg[i].stepX;
                if ((BaktOrg[i].posX > 642) || (BaktOrg[i].posX < 30))
                {
                    BaktOrg[i].stepX = -BaktOrg[i].stepX;
                }
                BaktOrg[i].posY += BaktOrg[i].stepY;
                if ((BaktOrg[i].posY > 445) || (BaktOrg[i].posY < 20))
                {
                    BaktOrg[i].stepY = -BaktOrg[i].stepY;
                }
                ui->bakt_4->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= BaktOrg[i].posX) && ((MicOrg[j].posX + 15) >= BaktOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= BaktOrg[i].posY) && ((MicOrg[j].posY + 15) >= BaktOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        BaktOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    BaktOrg[i].size_w = ui->bakt_4->width();
                    BaktOrg[i].size_h = ui->bakt_4->height();
                    BaktOrg[i].posX = 1080;
                    BaktOrg[i].posY = 720;
                    ui->bakt_4->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    ui->bakt_4->setVisible(false);
                    ui->bakt_4->setEnabled(false);
                }
              break;
            }
            case 4:
            {
                if (BaktOrg[i].HP > 0)
                {
                BaktOrg[i].posX = ui->bakt_5->x();
                BaktOrg[i].posY = ui->bakt_5->y();
                BaktOrg[i].size_w = ui->bakt_5->width();
                BaktOrg[i].size_h = ui->bakt_5->height();
                BaktOrg[i].posX += BaktOrg[i].stepX;
                if ((BaktOrg[i].posX > 642) || (BaktOrg[i].posX < 30))
                {
                    BaktOrg[i].stepX = -BaktOrg[i].stepX;
                }
                BaktOrg[i].posY += BaktOrg[i].stepY;
                if ((BaktOrg[i].posY > 445) || (BaktOrg[i].posY < 20))
                {
                    BaktOrg[i].stepY = -BaktOrg[i].stepY;
                }
                ui->bakt_5->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= BaktOrg[i].posX) && ((MicOrg[j].posX + 15) >= BaktOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= BaktOrg[i].posY) && ((MicOrg[j].posY + 15) >= BaktOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        BaktOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    BaktOrg[i].size_w = ui->bakt_5->width();
                    BaktOrg[i].size_h = ui->bakt_5->height();
                    BaktOrg[i].posX = 1080;
                    BaktOrg[i].posY = 720;
                    ui->bakt_5->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    ui->bakt_5->setVisible(false);
                    ui->bakt_5->setEnabled(false);
                }
              break;
             }
             case 5:
            {
                if (BaktOrg[i].HP > 0)
                {
                BaktOrg[i].posX = ui->bakt_6->x();
                BaktOrg[i].posY = ui->bakt_6->y();
                BaktOrg[i].size_w = ui->bakt_6->width();
                BaktOrg[i].size_h = ui->bakt_6->height();
                BaktOrg[i].posX += BaktOrg[i].stepX;
                if ((BaktOrg[i].posX > 642) || (BaktOrg[i].posX < 30))
                {
                    BaktOrg[i].stepX = -BaktOrg[i].stepX;
                }
                BaktOrg[i].posY += BaktOrg[i].stepY;
                if ((BaktOrg[i].posY > 445) || (BaktOrg[i].posY < 20))
                {
                    BaktOrg[i].stepY = -BaktOrg[i].stepY;
                }
                ui->bakt_6->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= BaktOrg[i].posX) && ((MicOrg[j].posX + 15) >= BaktOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= BaktOrg[i].posY) && ((MicOrg[j].posY + 15) >= BaktOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        BaktOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    BaktOrg[i].size_w = ui->bakt_6->width();
                    BaktOrg[i].size_h = ui->bakt_6->height();
                    BaktOrg[i].posX = 1080;
                    BaktOrg[i].posY = 720;
                    ui->bakt_6->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    ui->bakt_6->setVisible(false);
                    ui->bakt_6->setEnabled(false);
                }
              break;
            }
            case 6:
            {
                if (BaktOrg[i].HP > 0)
                {
                BaktOrg[i].posX = ui->bakt_7->x();
                BaktOrg[i].posY = ui->bakt_7->y();
                BaktOrg[i].size_w = ui->bakt_7->width();
                BaktOrg[i].size_h = ui->bakt_7->height();
                BaktOrg[i].posX += BaktOrg[i].stepX;
                if ((BaktOrg[i].posX > 642) || (BaktOrg[i].posX < 30))
                {
                    BaktOrg[i].stepX = -BaktOrg[i].stepX;
                }
                BaktOrg[i].posY += BaktOrg[i].stepY;
                if ((BaktOrg[i].posY > 445) || (BaktOrg[i].posY < 20))
                {
                    BaktOrg[i].stepY = -BaktOrg[i].stepY;
                }
                ui->bakt_7->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= BaktOrg[i].posX) && ((MicOrg[j].posX + 15) >= BaktOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= BaktOrg[i].posY) && ((MicOrg[j].posY + 15) >= BaktOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        BaktOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    BaktOrg[i].size_w = ui->bakt_7->width();
                    BaktOrg[i].size_h = ui->bakt_7->height();
                    BaktOrg[i].posX = 1080;
                    BaktOrg[i].posY = 720;
                    ui->bakt_7->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    ui->bakt_7->setVisible(false);
                    ui->bakt_7->setEnabled(false);
                }
              break;
            }
            case 7:
            {
                if (BaktOrg[i].HP > 0)
                {
                BaktOrg[i].posX = ui->bakt_8->x();
                BaktOrg[i].posY = ui->bakt_8->y();
                BaktOrg[i].size_w = ui->bakt_8->width();
                BaktOrg[i].size_h = ui->bakt_8->height();
                BaktOrg[i].posX += BaktOrg[i].stepX;
                if ((BaktOrg[i].posX > 642) || (BaktOrg[i].posX < 30))
                {
                    BaktOrg[i].stepX = -BaktOrg[i].stepX;
                }
                BaktOrg[i].posY += BaktOrg[i].stepY;
                if ((BaktOrg[i].posY > 445) || (BaktOrg[i].posY < 20))
                {
                    BaktOrg[i].stepY = -BaktOrg[i].stepY;
                }
                ui->bakt_8->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= BaktOrg[i].posX) && ((MicOrg[j].posX + 15) >= BaktOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= BaktOrg[i].posY) && ((MicOrg[j].posY + 15) >= BaktOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        BaktOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    BaktOrg[i].size_w = ui->bakt_8->width();
                    BaktOrg[i].size_h = ui->bakt_8->height();
                    BaktOrg[i].posX = 1080;
                    BaktOrg[i].posY = 720;
                    ui->bakt_8->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    ui->bakt_8->setVisible(false);
                    ui->bakt_8->setEnabled(false);
                }
              break;
            }
            case 8:
            {
                if (BaktOrg[i].HP > 0)
                {
                BaktOrg[i].posX = ui->bakt_9->x();
                BaktOrg[i].posY = ui->bakt_9->y();
                BaktOrg[i].size_w = ui->bakt_9->width();
                BaktOrg[i].size_h = ui->bakt_9->height();
                BaktOrg[i].posX += BaktOrg[i].stepX;
                if ((BaktOrg[i].posX > 642) || (BaktOrg[i].posX < 30))
                {
                    BaktOrg[i].stepX = -BaktOrg[i].stepX;
                }
                BaktOrg[i].posY += MicOrg[i].stepY;
                if ((BaktOrg[i].posY > 445) || (BaktOrg[i].posY < 20))
                {
                    BaktOrg[i].stepY = -BaktOrg[i].stepY;
                }
                ui->bakt_9->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= BaktOrg[i].posX) && ((MicOrg[j].posX + 15) >= BaktOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= BaktOrg[i].posY) && ((MicOrg[j].posY + 15) >= BaktOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        BaktOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    BaktOrg[i].size_w = ui->bakt_9->width();
                    BaktOrg[i].size_h = ui->bakt_9->height();
                    BaktOrg[i].posX = 1080;
                    BaktOrg[i].posY = 720;
                    ui->bakt_9->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    ui->bakt_9->setVisible(false);
                    ui->bakt_9->setEnabled(false);
                }
              break;
            }
            case 9:
            {
                if (BaktOrg[i].HP > 0)
                {
                BaktOrg[i].posX = ui->bakt_10->x();
                BaktOrg[i].posY = ui->bakt_10->y();
                BaktOrg[i].size_w = ui->bakt_10->width();
                BaktOrg[i].size_h = ui->bakt_10->height();
                BaktOrg[i].posX += BaktOrg[i].stepX;
                if ((BaktOrg[i].posX > 642) || (BaktOrg[i].posX < 30))
                {
                    BaktOrg[i].stepX = -BaktOrg[i].stepX;
                }
                BaktOrg[i].posY += BaktOrg[i].stepY;
                if ((BaktOrg[i].posY > 445) || (BaktOrg[i].posY < 20))
                {
                    BaktOrg[i].stepY = -BaktOrg[i].stepY;
                }
                ui->bakt_10->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= BaktOrg[i].posX) && ((MicOrg[j].posX + 15) >= BaktOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= BaktOrg[i].posY) && ((MicOrg[j].posY + 15) >= BaktOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        BaktOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    BaktOrg[i].size_w = ui->bakt_10->width();
                    BaktOrg[i].size_h = ui->bakt_10->height();
                    BaktOrg[i].posX = 1080;
                    BaktOrg[i].posY = 720;
                    ui->bakt_10->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    ui->bakt_10->setVisible(false);
                    ui->bakt_10->setEnabled(false);
                }
              break;
            }
            case 10:
            {
                if (BaktOrg[i].HP > 0)
                {
                BaktOrg[i].posX = ui->bakt_11->x();
                BaktOrg[i].posY = ui->bakt_11->y();
                BaktOrg[i].size_w = ui->bakt_11->width();
                BaktOrg[i].size_h = ui->bakt_11->height();
                BaktOrg[i].posX += BaktOrg[i].stepX;
                if ((BaktOrg[i].posX > 642) || (BaktOrg[i].posX < 30))
                {
                    BaktOrg[i].stepX = -BaktOrg[i].stepX;
                }
                BaktOrg[i].posY += BaktOrg[i].stepY;
                if ((BaktOrg[i].posY > 445) || (BaktOrg[i].posY < 20))
                {
                    BaktOrg[i].stepY = -BaktOrg[i].stepY;
                }
                ui->bakt_11->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= BaktOrg[i].posX) && ((MicOrg[j].posX + 15) >= BaktOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= BaktOrg[i].posY) && ((MicOrg[j].posY + 15) >= BaktOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        BaktOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    BaktOrg[i].size_w = ui->bakt_11->width();
                    BaktOrg[i].size_h = ui->bakt_11->height();
                    BaktOrg[i].posX = 1080;
                    BaktOrg[i].posY = 720;
                    ui->bakt_11->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    ui->bakt_11->setVisible(false);
                    ui->bakt_11->setEnabled(false);
                }
              break;
            }
            case 11:
            {
                if (BaktOrg[i].HP > 0)
                {
                BaktOrg[i].posX = ui->bakt_12->x();
                BaktOrg[i].posY = ui->bakt_12->y();
                BaktOrg[i].size_w = ui->bakt_12->width();
                BaktOrg[i].size_h = ui->bakt_12->height();
                BaktOrg[i].posX += BaktOrg[i].stepX;
                if ((BaktOrg[i].posX > 642) || (BaktOrg[i].posX < 30))
                {
                    BaktOrg[i].stepX = -BaktOrg[i].stepX;
                }
                BaktOrg[i].posY += BaktOrg[i].stepY;
                if ((BaktOrg[i].posY > 445) || (BaktOrg[i].posY < 20))
                {
                    BaktOrg[i].stepY = -BaktOrg[i].stepY;
                }
                ui->bakt_12->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= BaktOrg[i].posX) && ((MicOrg[j].posX + 15) >= BaktOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= BaktOrg[i].posY) && ((MicOrg[j].posY + 15) >= BaktOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        BaktOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    BaktOrg[i].size_w = ui->bakt_12->width();
                    BaktOrg[i].size_h = ui->bakt_12->height();
                    BaktOrg[i].posX = 1080;
                    BaktOrg[i].posY = 720;
                    ui->bakt_12->setGeometry(BaktOrg[i].posX, BaktOrg[i].posY, BaktOrg[i].size_w, BaktOrg[i].size_h);
                    ui->bakt_12->setVisible(false);
                    ui->bakt_12->setEnabled(false);
                }
              break;
            }
            }
        }
        break;
    }
        case 2:
    {
        for (int i = 0; i < 9; i++)
        {
            switch (i)
            {
            case 0:
            {
                if (GribOrg[i].HP > 0)
                {
                GribOrg[i].posX = ui->grib_1->x();
                GribOrg[i].posY = ui->grib_1->y();
                GribOrg[i].size_w = ui->grib_1->width();
                GribOrg[i].size_h = ui->grib_1->height();
                GribOrg[i].posX += GribOrg[i].stepX;
                if ((GribOrg[i].posX > 642) || (GribOrg[i].posX < 30))
                {
                    GribOrg[i].stepX = -GribOrg[i].stepX;
                }
                GribOrg[i].posY += GribOrg[i].stepY;
                if ((GribOrg[i].posY > 445) || (GribOrg[i].posY < 22))
                {

                    GribOrg[i].stepY = -GribOrg[i].stepY;

                }
                ui->grib_1->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= GribOrg[i].posX) && ((MicOrg[j].posX + 15) >= GribOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= GribOrg[i].posY) && ((MicOrg[j].posY + 15) >= GribOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        GribOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    GribOrg[i].size_w = ui->grib_1->width();
                    GribOrg[i].size_h = ui->grib_1->height();
                    GribOrg[i].posX = 1080;
                    GribOrg[i].posY = 720;
                    ui->grib_1->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                    ui->grib_1->setVisible(false);
                    ui->grib_1->setEnabled(false);
                }
              break;
            }
            case 1:
            {
                if (GribOrg[i].HP > 0)
                {
                GribOrg[i].posX = ui->grib_2->x();
                GribOrg[i].posY = ui->grib_2->y();
                GribOrg[i].size_w = ui->grib_2->width();
                GribOrg[i].size_h = ui->grib_2->height();
                GribOrg[i].posX += GribOrg[i].stepX;
                if ((GribOrg[i].posX > 642) || (GribOrg[i].posX < 30))
                {
                    GribOrg[i].stepX = -GribOrg[i].stepX;
                }
                GribOrg[i].posY += GribOrg[i].stepY;
                if ((GribOrg[i].posY > 445) || (GribOrg[i].posY < 20))
                {
                    GribOrg[i].stepY = -GribOrg[i].stepY;
                }
                ui->grib_2->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= GribOrg[i].posX) && ((MicOrg[j].posX + 15) >= GribOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= GribOrg[i].posY) && ((MicOrg[j].posY + 15) >= GribOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        GribOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    GribOrg[i].size_w = ui->grib_2->width();
                    GribOrg[i].size_h = ui->grib_2->height();
                    GribOrg[i].posX = 1080;
                    GribOrg[i].posY = 720;
                    ui->grib_2->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                    ui->grib_2->setVisible(false);
                    ui->grib_2->setEnabled(false);
                }
              break;
            }
            case 2:
            {
                if (GribOrg[i].HP > 0)
                {
                GribOrg[i].posX = ui->grib_3->x();
                GribOrg[i].posY = ui->grib_3->y();
                GribOrg[i].size_w = ui->grib_3->width();
                GribOrg[i].size_h = ui->grib_3->height();
                GribOrg[i].posX += GribOrg[i].stepX;
                if ((GribOrg[i].posX > 642) || (GribOrg[i].posX < 30))
                {
                    GribOrg[i].stepX = -GribOrg[i].stepX;
                }
                GribOrg[i].posY += GribOrg[i].stepY;
                if ((GribOrg[i].posY > 445) || (GribOrg[i].posY < 20))
                {
                    GribOrg[i].stepY = -GribOrg[i].stepY;
                }
                ui->grib_3->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= GribOrg[i].posX) && ((MicOrg[j].posX + 15) >= GribOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= GribOrg[i].posY) && ((MicOrg[j].posY + 15) >= GribOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        GribOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    GribOrg[i].size_w = ui->grib_3->width();
                    GribOrg[i].size_h = ui->grib_3->height();
                    GribOrg[i].posX = 1080;
                    GribOrg[i].posY = 720;
                    ui->grib_3->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                    ui->grib_3->setVisible(false);
                    ui->grib_3->setEnabled(false);
                }
              break;
            }
            case 3:
            {
                if (GribOrg[i].HP > 0)
                {
                GribOrg[i].posX = ui->grib_4->x();
                GribOrg[i].posY = ui->grib_4->y();
                GribOrg[i].size_w = ui->grib_4->width();
                GribOrg[i].size_h = ui->grib_4->height();
                GribOrg[i].posX += GribOrg[i].stepX;
                if ((GribOrg[i].posX > 642) || (GribOrg[i].posX < 30))
                {
                    GribOrg[i].stepX = -GribOrg[i].stepX;
                }
                GribOrg[i].posY += GribOrg[i].stepY;
                if ((GribOrg[i].posY > 445) || (GribOrg[i].posY < 20))
                {
                    GribOrg[i].stepY = -GribOrg[i].stepY;
                }
                ui->grib_4->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= GribOrg[i].posX) && ((MicOrg[j].posX + 15) >= GribOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= GribOrg[i].posY) && ((MicOrg[j].posY + 15) >= GribOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        GribOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    GribOrg[i].size_w = ui->grib_4->width();
                    GribOrg[i].size_h = ui->grib_4->height();
                    GribOrg[i].posX = 1080;
                    GribOrg[i].posY = 720;
                    ui->grib_4->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                    ui->grib_4->setVisible(false);
                    ui->grib_4->setEnabled(false);
                }
              break;
            }
            case 4:
            {
                if (GribOrg[i].HP > 0)
                {
                GribOrg[i].posX = ui->grib_5->x();
                GribOrg[i].posY = ui->grib_5->y();
                GribOrg[i].size_w = ui->grib_5->width();
                GribOrg[i].size_h = ui->grib_5->height();
                GribOrg[i].posX += GribOrg[i].stepX;
                if ((GribOrg[i].posX > 642) || (GribOrg[i].posX < 30))
                {
                    GribOrg[i].stepX = -GribOrg[i].stepX;
                }
                GribOrg[i].posY += GribOrg[i].stepY;
                if ((GribOrg[i].posY > 445) || (GribOrg[i].posY < 20))
                {
                    GribOrg[i].stepY = -GribOrg[i].stepY;
                }
                ui->grib_5->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= GribOrg[i].posX) && ((MicOrg[j].posX + 15) >= GribOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= GribOrg[i].posY) && ((MicOrg[j].posY + 15) >= GribOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        GribOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    GribOrg[i].size_w = ui->grib_5->width();
                    GribOrg[i].size_h = ui->grib_5->height();
                    GribOrg[i].posX = 1080;
                    GribOrg[i].posY = 720;
                    ui->grib_5->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                    ui->grib_5->setVisible(false);
                    ui->grib_5->setEnabled(false);
                }
              break;
             }
             case 5:
            {
                if (GribOrg[i].HP > 0)
                {
                GribOrg[i].posX = ui->grib_6->x();
                GribOrg[i].posY = ui->grib_6->y();
                GribOrg[i].size_w = ui->grib_6->width();
                GribOrg[i].size_h = ui->grib_6->height();
                GribOrg[i].posX += GribOrg[i].stepX;
                if ((GribOrg[i].posX > 642) || (GribOrg[i].posX < 30))
                {
                    GribOrg[i].stepX = -GribOrg[i].stepX;
                }
                GribOrg[i].posY += GribOrg[i].stepY;
                if ((GribOrg[i].posY > 445) || (GribOrg[i].posY < 20))
                {
                    GribOrg[i].stepY = -GribOrg[i].stepY;
                }
                ui->grib_6->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= GribOrg[i].posX) && ((MicOrg[j].posX + 15) >= GribOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= GribOrg[i].posY) && ((MicOrg[j].posY + 15) >= GribOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        GribOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    GribOrg[i].size_w = ui->grib_6->width();
                    GribOrg[i].size_h = ui->grib_6->height();
                    GribOrg[i].posX = 1080;
                    GribOrg[i].posY = 720;
                    ui->grib_6->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                    ui->grib_6->setVisible(false);
                    ui->grib_6->setEnabled(false);
                }
              break;
            }
            case 6:
            {
                if (GribOrg[i].HP > 0)
                {
                GribOrg[i].posX = ui->grib_7->x();
                GribOrg[i].posY = ui->grib_7->y();
                GribOrg[i].size_w = ui->grib_7->width();
                GribOrg[i].size_h = ui->grib_7->height();
                GribOrg[i].posX += GribOrg[i].stepX;
                if ((GribOrg[i].posX > 642) || (GribOrg[i].posX < 30))
                {
                    GribOrg[i].stepX = -GribOrg[i].stepX;
                }
                GribOrg[i].posY += GribOrg[i].stepY;
                if ((GribOrg[i].posY > 445) || (GribOrg[i].posY < 20))
                {
                    GribOrg[i].stepY = -GribOrg[i].stepY;
                }
                ui->grib_7->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= GribOrg[i].posX) && ((MicOrg[j].posX + 15) >= GribOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= GribOrg[i].posY) && ((MicOrg[j].posY + 15) >= GribOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        GribOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    GribOrg[i].size_w = ui->grib_7->width();
                    GribOrg[i].size_h = ui->grib_7->height();
                    GribOrg[i].posX = 1080;
                    GribOrg[i].posY = 720;
                    ui->grib_7->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                    ui->grib_7->setVisible(false);
                    ui->grib_7->setEnabled(false);
                }
              break;
            }
            case 7:
            {
                if (GribOrg[i].HP > 0)
                {
                GribOrg[i].posX = ui->grib_8->x();
                GribOrg[i].posY = ui->grib_8->y();
                GribOrg[i].size_w = ui->grib_8->width();
                GribOrg[i].size_h = ui->grib_8->height();
                GribOrg[i].posX += GribOrg[i].stepX;
                if ((GribOrg[i].posX > 642) || (GribOrg[i].posX < 30))
                {
                    GribOrg[i].stepX = -GribOrg[i].stepX;
                }
                GribOrg[i].posY += GribOrg[i].stepY;
                if ((GribOrg[i].posY > 445) || (GribOrg[i].posY < 20))
                {
                    GribOrg[i].stepY = -GribOrg[i].stepY;
                }
                ui->grib_8->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= GribOrg[i].posX) && ((MicOrg[j].posX + 15) >= GribOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= GribOrg[i].posY) && ((MicOrg[j].posY + 15) >= GribOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        GribOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    GribOrg[i].size_w = ui->grib_8->width();
                    GribOrg[i].size_h = ui->grib_8->height();
                    GribOrg[i].posX = 1080;
                    GribOrg[i].posY = 720;
                    ui->grib_8->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                    ui->grib_8->setVisible(false);
                    ui->grib_8->setEnabled(false);
                }
              break;
            }
            case 8:
            {
                if (GribOrg[i].HP > 0)
                {
                GribOrg[i].posX = ui->grib_9->x();
                GribOrg[i].posY = ui->grib_9->y();
                GribOrg[i].size_w = ui->grib_9->width();
                GribOrg[i].size_h = ui->grib_9->height();
                GribOrg[i].posX += GribOrg[i].stepX;
                if ((GribOrg[i].posX > 642) || (GribOrg[i].posX < 30))
                {
                    GribOrg[i].stepX = -GribOrg[i].stepX;
                }
                GribOrg[i].posY += GribOrg[i].stepY;
                if ((GribOrg[i].posY > 445) || (GribOrg[i].posY < 20))
                {
                    GribOrg[i].stepY = -GribOrg[i].stepY;
                }
                ui->grib_9->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= GribOrg[i].posX) && ((MicOrg[j].posX + 15) >= GribOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= GribOrg[i].posY) && ((MicOrg[j].posY + 15) >= GribOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        GribOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    GribOrg[i].size_w = ui->grib_9->width();
                    GribOrg[i].size_h = ui->grib_9->height();
                    GribOrg[i].posX = 1080;
                    GribOrg[i].posY = 720;
                    ui->grib_9->setGeometry(GribOrg[i].posX, GribOrg[i].posY, GribOrg[i].size_w, GribOrg[i].size_h);
                    ui->grib_9->setVisible(false);
                    ui->grib_9->setEnabled(false);
                }
              break;
            }
            }
        }
        break;
    }
        case 3:
    {
        for (int i = 0; i < 6; i++)
        {
            switch (i)
            {
            case 0:
            {
                if (VirusOrg[i].HP > 0)
                {
                VirusOrg[i].posX = ui->virus_1->x();
                VirusOrg[i].posY = ui->virus_1->y();
                VirusOrg[i].size_w = ui->virus_1->width();
                VirusOrg[i].size_h = ui->virus_1->height();
                VirusOrg[i].posX += VirusOrg[i].stepX;
                if ((VirusOrg[i].posX > 642) || (VirusOrg[i].posX < 30))
                {
                    VirusOrg[i].stepX = -VirusOrg[i].stepX;
                }
                VirusOrg[i].posY += VirusOrg[i].stepY;
                if ((VirusOrg[i].posY > 445) || (VirusOrg[i].posY < 22))
                {

                    VirusOrg[i].stepY = -VirusOrg[i].stepY;

                }
                ui->virus_1->setGeometry(VirusOrg[i].posX, VirusOrg[i].posY, VirusOrg[i].size_w, VirusOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= VirusOrg[i].posX) && ((MicOrg[j].posX + 15) >= VirusOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= VirusOrg[i].posY) && ((MicOrg[j].posY + 15) >= VirusOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        VirusOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    VirusOrg[i].size_w = ui->virus_1->width();
                    VirusOrg[i].size_h = ui->virus_1->height();
                    VirusOrg[i].posX = 1080;
                    VirusOrg[i].posY = 720;
                    ui->virus_1->setGeometry(VirusOrg[i].posX, VirusOrg[i].posY, VirusOrg[i].size_w, VirusOrg[i].size_h);
                    ui->virus_1->setVisible(false);
                    ui->virus_1->setEnabled(false);
                }
              break;
            }
            case 1:
            {
                if (VirusOrg[i].HP > 0)
                {
                VirusOrg[i].posX = ui->virus_2->x();
                VirusOrg[i].posY = ui->virus_2->y();
                VirusOrg[i].size_w = ui->virus_2->width();
                VirusOrg[i].size_h = ui->virus_2->height();
                VirusOrg[i].posX += VirusOrg[i].stepX;
                if ((VirusOrg[i].posX > 642) || (VirusOrg[i].posX < 30))
                {
                    VirusOrg[i].stepX = -VirusOrg[i].stepX;
                }
                VirusOrg[i].posY += VirusOrg[i].stepY;
                if ((VirusOrg[i].posY > 445) || (VirusOrg[i].posY < 20))
                {
                    VirusOrg[i].stepY = -VirusOrg[i].stepY;
                }
                ui->virus_2->setGeometry(VirusOrg[i].posX, VirusOrg[i].posY, VirusOrg[i].size_w, VirusOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= VirusOrg[i].posX) && ((MicOrg[j].posX + 15) >= VirusOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= VirusOrg[i].posY) && ((MicOrg[j].posY + 15) >= VirusOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        VirusOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    VirusOrg[i].size_w = ui->virus_2->width();
                    VirusOrg[i].size_h = ui->virus_2->height();
                    VirusOrg[i].posX = 1080;
                    VirusOrg[i].posY = 720;
                    ui->virus_2->setGeometry(VirusOrg[i].posX, VirusOrg[i].posY, VirusOrg[i].size_w, VirusOrg[i].size_h);
                    ui->virus_2->setVisible(false);
                    ui->virus_2->setEnabled(false);
                }
              break;
            }
            case 2:
            {
                if (VirusOrg[i].HP > 0)
                {
                VirusOrg[i].posX = ui->virus_3->x();
                VirusOrg[i].posY = ui->virus_3->y();
                VirusOrg[i].size_w = ui->virus_3->width();
                VirusOrg[i].size_h = ui->virus_3->height();
                VirusOrg[i].posX += VirusOrg[i].stepX;
                if ((VirusOrg[i].posX > 642) || (VirusOrg[i].posX < 30))
                {
                    VirusOrg[i].stepX = -VirusOrg[i].stepX;
                }
                VirusOrg[i].posY += VirusOrg[i].stepY;
                if ((VirusOrg[i].posY > 445) || (VirusOrg[i].posY < 20))
                {
                    VirusOrg[i].stepY = -VirusOrg[i].stepY;
                }
                ui->virus_3->setGeometry(VirusOrg[i].posX, VirusOrg[i].posY, VirusOrg[i].size_w, VirusOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= VirusOrg[i].posX) && ((MicOrg[j].posX + 15) >= VirusOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= VirusOrg[i].posY) && ((MicOrg[j].posY + 15) >= VirusOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        VirusOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    VirusOrg[i].size_w = ui->virus_3->width();
                    VirusOrg[i].size_h = ui->virus_3->height();
                    VirusOrg[i].posX = 1080;
                    VirusOrg[i].posY = 720;
                    ui->virus_3->setGeometry(VirusOrg[i].posX, VirusOrg[i].posY, VirusOrg[i].size_w, VirusOrg[i].size_h);
                    ui->virus_3->setVisible(false);
                    ui->virus_3->setEnabled(false);
                }
              break;
            }
            case 3:
            {
                if (VirusOrg[i].HP > 0)
                {
                VirusOrg[i].posX = ui->virus_4->x();
                VirusOrg[i].posY = ui->virus_4->y();
                VirusOrg[i].size_w = ui->virus_4->width();
                VirusOrg[i].size_h = ui->virus_4->height();
                VirusOrg[i].posX += VirusOrg[i].stepX;
                if ((VirusOrg[i].posX > 642) || (VirusOrg[i].posX < 30))
                {
                    VirusOrg[i].stepX = -VirusOrg[i].stepX;
                }
                VirusOrg[i].posY += VirusOrg[i].stepY;
                if ((VirusOrg[i].posY > 445) || (VirusOrg[i].posY < 20))
                {
                    VirusOrg[i].stepY = -VirusOrg[i].stepY;
                }
                ui->virus_4->setGeometry(VirusOrg[i].posX, VirusOrg[i].posY, VirusOrg[i].size_w, VirusOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= VirusOrg[i].posX) && ((MicOrg[j].posX + 15) >= VirusOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= VirusOrg[i].posY) && ((MicOrg[j].posY + 15) >= VirusOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        VirusOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    VirusOrg[i].size_w = ui->virus_4->width();
                    VirusOrg[i].size_h = ui->virus_4->height();
                    VirusOrg[i].posX = 1080;
                    VirusOrg[i].posY = 720;
                    ui->virus_4->setGeometry(VirusOrg[i].posX, VirusOrg[i].posY, VirusOrg[i].size_w, VirusOrg[i].size_h);
                    ui->virus_4->setVisible(false);
                    ui->virus_4->setEnabled(false);
                }
              break;
            }
            case 4:
            {
                if (VirusOrg[i].HP > 0)
                {
                VirusOrg[i].posX = ui->virus_5->x();
                VirusOrg[i].posY = ui->virus_5->y();
                VirusOrg[i].size_w = ui->virus_5->width();
                VirusOrg[i].size_h = ui->virus_5->height();
                VirusOrg[i].posX += VirusOrg[i].stepX;
                if ((VirusOrg[i].posX > 642) || (VirusOrg[i].posX < 30))
                {
                    VirusOrg[i].stepX = -VirusOrg[i].stepX;
                }
                VirusOrg[i].posY += VirusOrg[i].stepY;
                if ((VirusOrg[i].posY > 445) || (VirusOrg[i].posY < 20))
                {
                    VirusOrg[i].stepY = -VirusOrg[i].stepY;
                }
                ui->virus_5->setGeometry(VirusOrg[i].posX, VirusOrg[i].posY, VirusOrg[i].size_w, VirusOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= VirusOrg[i].posX) && ((MicOrg[j].posX + 15) >= VirusOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= VirusOrg[i].posY) && ((MicOrg[j].posY + 15) >= VirusOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        VirusOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    VirusOrg[i].size_w = ui->virus_5->width();
                    VirusOrg[i].size_h = ui->virus_5->height();
                    VirusOrg[i].posX = 1080;
                    VirusOrg[i].posY = 720;
                    ui->virus_5->setGeometry(VirusOrg[i].posX, VirusOrg[i].posY, VirusOrg[i].size_w, VirusOrg[i].size_h);
                    ui->virus_5->setVisible(false);
                    ui->virus_5->setEnabled(false);
                }
              break;
             }
             case 5:
            {
                if (VirusOrg[i].HP > 0)
                {
                VirusOrg[i].posX = ui->virus_6->x();
                VirusOrg[i].posY = ui->virus_6->y();
                VirusOrg[i].size_w = ui->virus_6->width();
                VirusOrg[i].size_h = ui->virus_6->height();
                VirusOrg[i].posX += VirusOrg[i].stepX;
                if ((VirusOrg[i].posX > 642) || (VirusOrg[i].posX < 30))
                {
                    VirusOrg[i].stepX = -VirusOrg[i].stepX;
                }
                VirusOrg[i].posY += VirusOrg[i].stepY;
                if ((VirusOrg[i].posY > 445) || (VirusOrg[i].posY < 20))
                {
                    VirusOrg[i].stepY = -VirusOrg[i].stepY;
                }
                ui->virus_6->setGeometry(VirusOrg[i].posX, VirusOrg[i].posY, VirusOrg[i].size_w, VirusOrg[i].size_h);
                for (int j = 0; j < 25; j++)
                {
                    if (((MicOrg[j].posX - 5) <= VirusOrg[i].posX) && ((MicOrg[j].posX + 15) >= VirusOrg[i].posX))
                    {
                        if (((MicOrg[j].posY - 5) <= VirusOrg[i].posY) && ((MicOrg[j].posY + 15) >= VirusOrg[i].posY))
                        {
                        MicOrg[j].dead = true;
                        CountOfOrganize--;
                        VirusOrg[i].HP--;
                        }
                    }
                }
                }
                else
                {
                    VirusOrg[i].size_w = ui->virus_6->width();
                    VirusOrg[i].size_h = ui->virus_6->height();
                    VirusOrg[i].posX = 1080;
                    VirusOrg[i].posY = 720;
                    ui->virus_6->setGeometry(VirusOrg[i].posX, VirusOrg[i].posY, VirusOrg[i].size_w, VirusOrg[i].size_h);
                    ui->virus_6->setVisible(false);
                    ui->virus_6->setEnabled(false);
                }
              break;
            }
            }
        }
        break;
    }
    }


    switch (TypeOfLecarstvo)
    {
        case 0:
    {
        break;
    }
    case 1:
    {
        for (int i = 0; i < 5; i++)
        {
            switch (i)
            {
            case 0:
            {
                TablOrg[i].posX = ui->tabl_1->x();
                TablOrg[i].posY = ui->tabl_1->y();
                TablOrg[i].size_w = ui->tabl_1->width();
                TablOrg[i].size_h = ui->tabl_1->height();

                if (MassiveFight[i] == 0)
                {
                    TablOrg[i].posX += TablOrg[i].stepX;
                    if ((TablOrg[i].posX > 642) || (TablOrg[i].posX < 30))
                    {
                        TablOrg[i].stepX = -TablOrg[i].stepX;
                    }
                    TablOrg[i].posY += TablOrg[i].stepY;
                    if ((TablOrg[i].posY > 445) || (TablOrg[i].posY < 20))
                    {
                        TablOrg[i].stepY = -TablOrg[i].stepY;
                    }
                switch (TypeOfFunction)
                {
                case 1:
                {
                    for (int j = 0; j < 12; j++)
                    {
                        if (((TablOrg[i].posX + 150) >= BaktOrg[j].posX) && ((TablOrg[i].posX - 83) <= BaktOrg[j].posX))
                        {
                            if (((TablOrg[i].posY + 150) >= BaktOrg[j].posY) && ((TablOrg[i].posY - 83) <= BaktOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    TablOrg[i].stepX = 1;
                                    TablOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 2:
                {
                    for (int j = 0; j < 9; j++)
                    {
                        if (((TablOrg[i].posX + 150) >= GribOrg[j].posX) && ((TablOrg[i].posX - 83) <= GribOrg[j].posX))
                        {
                            if (((TablOrg[i].posY + 150) >= GribOrg[j].posY) && ((TablOrg[i].posY - 83) <= GribOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    TablOrg[i].stepX = 1;
                                    TablOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 3:
                {
                    for (int j = 0; j < 6; j++)
                    {
                        if (((TablOrg[i].posX + 150) >= VirusOrg[j].posX) && ((TablOrg[i].posX - 83) <= VirusOrg[j].posX))
                        {
                            if (((TablOrg[i].posY + 150) >= VirusOrg[j].posY) && ((TablOrg[i].posY - 83) <= VirusOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    TablOrg[i].stepX = 1;
                                    TablOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                }
                }
                else
                {
                    switch (TypeOfFunction)
                    {
                    case 1:
                    {
                        if (((BaktOrg[MassiveFight[i]].posX - 5) <= TablOrg[i].posX) && ((BaktOrg[MassiveFight[i]].posX + 15) >= TablOrg[i].posX))
                        {
                            if (((BaktOrg[MassiveFight[i]].posY - 5) <= TablOrg[i].posY) && ((BaktOrg[MassiveFight[i]].posY + 15) >= TablOrg[i].posY))
                            {
                            TablOrg[i].dead = true;
                            BaktOrg[MassiveFight[i]].HP = 0;
                            TablOrg[i].size_w = ui->tabl_1->width();
                            TablOrg[i].size_h = ui->tabl_1->height();
                            TablOrg[i].posX = 0;
                            TablOrg[i].posY = 0;
                            ui->tabl_1->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                            ui->tabl_1->setVisible(false);
                            ui->tabl_1->setEnabled(false);
                            }
                        }

                        if (BaktOrg[MassiveFight[i]].posX > TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX + TablOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posX < TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX - TablOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posY > TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY + TablOrg[i].stepY;
                        }

                        if (BaktOrg[MassiveFight[i]].posY < TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY - TablOrg[i].stepY;
                        }

                        if ((BaktOrg[MassiveFight[i]].HP == 0) && (TablOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 2:
                    {
                        if (((GribOrg[MassiveFight[i]].posX - 5) <= TablOrg[i].posX) && ((GribOrg[MassiveFight[i]].posX + 15) >= TablOrg[i].posX))
                        {
                            if (((GribOrg[MassiveFight[i]].posY - 5) <= TablOrg[i].posY) && ((GribOrg[MassiveFight[i]].posY + 15) >= TablOrg[i].posY))
                            {
                            TablOrg[i].dead = true;
                            GribOrg[MassiveFight[i]].HP = 0;
                            TablOrg[i].size_w = ui->tabl_1->width();
                            TablOrg[i].size_h = ui->tabl_1->height();
                            TablOrg[i].posX = 0;
                            TablOrg[i].posY = 0;
                            ui->tabl_1->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                            ui->tabl_1->setVisible(false);
                            ui->tabl_1->setEnabled(false);
                            }
                        }

                        if (GribOrg[MassiveFight[i]].posX > TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX + TablOrg[i].stepX;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posX < TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX - TablOrg[i].stepX;
                        }

                        if (GribOrg[MassiveFight[i]].posY > TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY + TablOrg[i].stepY;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posY < TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY - TablOrg[i].stepY;
                        }

                        if ((GribOrg[MassiveFight[i]].HP == 0) && (TablOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 3:
                    {
                        if (((VirusOrg[MassiveFight[i]].posX - 5) <= TablOrg[i].posX) && ((VirusOrg[MassiveFight[i]].posX + 15) >= TablOrg[i].posX))
                        {
                            if (((VirusOrg[MassiveFight[i]].posY - 5) <= TablOrg[i].posY) && ((VirusOrg[MassiveFight[i]].posY + 15) >= TablOrg[i].posY))
                            {
                            TablOrg[i].dead = true;
                            VirusOrg[MassiveFight[i]].HP = 0;
                            TablOrg[i].size_w = ui->tabl_1->width();
                            TablOrg[i].size_h = ui->tabl_1->height();
                            TablOrg[i].posX = 0;
                            TablOrg[i].posY = 0;
                            ui->tabl_1->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                            ui->tabl_1->setVisible(false);
                            ui->tabl_1->setEnabled(false);
                            }
                        }

                        if (VirusOrg[MassiveFight[i]].posX > TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX + TablOrg[i].stepX;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posX < TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX - TablOrg[i].stepX;
                        }

                        if (VirusOrg[MassiveFight[i]].posY > TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY + TablOrg[i].stepY;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posY < TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY - TablOrg[i].stepY;
                        }
                        if ((VirusOrg[MassiveFight[i]].HP == 0)  && (TablOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                }
                }
                ui->tabl_1->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);               
              break;
            }
            case 1:
            {
                TablOrg[i].posX = ui->tabl_2->x();
                TablOrg[i].posY = ui->tabl_2->y();
                TablOrg[i].size_w = ui->tabl_2->width();
                TablOrg[i].size_h = ui->tabl_2->height();

                if (MassiveFight[i] == 0)
                {
                    TablOrg[i].posX += TablOrg[i].stepX;
                    if ((TablOrg[i].posX > 642) || (TablOrg[i].posX < 30))
                    {
                        TablOrg[i].stepX = -TablOrg[i].stepX;
                    }
                    TablOrg[i].posY += TablOrg[i].stepY;
                    if ((TablOrg[i].posY > 445) || (TablOrg[i].posY < 20))
                    {
                        TablOrg[i].stepY = -TablOrg[i].stepY;
                    }
                switch (TypeOfFunction)
                {
                case 1:
                {
                    for (int j = 0; j < 12; j++)
                    {
                        if (((TablOrg[i].posX + 150) >= BaktOrg[j].posX) && ((TablOrg[i].posX - 83) <= BaktOrg[j].posX))
                        {
                            if (((TablOrg[i].posY + 150) >= BaktOrg[j].posY) && ((TablOrg[i].posY - 83) <= BaktOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    TablOrg[i].stepX = 1;
                                    TablOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 2:
                {
                    for (int j = 0; j < 9; j++)
                    {
                        if (((TablOrg[i].posX + 150) >= GribOrg[j].posX) && ((TablOrg[i].posX - 83) <= GribOrg[j].posX))
                        {
                            if (((TablOrg[i].posY + 150) >= GribOrg[j].posY) && ((TablOrg[i].posY - 83) <= GribOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    TablOrg[i].stepX = 1;
                                    TablOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 3:
                {
                    for (int j = 0; j < 6; j++)
                    {
                        if (((TablOrg[i].posX + 150) >= VirusOrg[j].posX) && ((TablOrg[i].posX - 83) <= VirusOrg[j].posX))
                        {
                            if (((TablOrg[i].posY + 150) >= VirusOrg[j].posY) && ((TablOrg[i].posY - 83) <= VirusOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    TablOrg[i].stepX = 1;
                                    TablOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                }
                }
                else
                {
                    switch (TypeOfFunction)
                    {
                    case 1:
                    {
                        if (((BaktOrg[MassiveFight[i]].posX - 5) <= TablOrg[i].posX) && ((BaktOrg[MassiveFight[i]].posX + 15) >= TablOrg[i].posX))
                        {
                            if (((BaktOrg[MassiveFight[i]].posY - 5) <= TablOrg[i].posY) && ((BaktOrg[MassiveFight[i]].posY + 15) >= TablOrg[i].posY))
                            {
                            TablOrg[i].dead = true;
                            BaktOrg[MassiveFight[i]].HP = 0;
                            TablOrg[i].size_w = ui->tabl_2->width();
                            TablOrg[i].size_h = ui->tabl_2->height();
                            TablOrg[i].posX = 0;
                            TablOrg[i].posY = 0;
                            ui->tabl_2->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                            ui->tabl_2->setVisible(false);
                            ui->tabl_2->setEnabled(false);
                            }
                        }

                        if (BaktOrg[MassiveFight[i]].posX > TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX + TablOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posX < TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX - TablOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posY > TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY + TablOrg[i].stepY;
                        }

                        if (BaktOrg[MassiveFight[i]].posY < TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY - TablOrg[i].stepY;
                        }

                        if ((BaktOrg[MassiveFight[i]].HP == 0) && (TablOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 2:
                    {
                        if (((GribOrg[MassiveFight[i]].posX - 5) <= TablOrg[i].posX) && ((GribOrg[MassiveFight[i]].posX + 15) >= TablOrg[i].posX))
                        {
                            if (((GribOrg[MassiveFight[i]].posY - 5) <= TablOrg[i].posY) && ((GribOrg[MassiveFight[i]].posY + 15) >= TablOrg[i].posY))
                            {
                            TablOrg[i].dead = true;
                            GribOrg[MassiveFight[i]].HP = 0;
                            TablOrg[i].size_w = ui->tabl_2->width();
                            TablOrg[i].size_h = ui->tabl_2->height();
                            TablOrg[i].posX = 0;
                            TablOrg[i].posY = 0;
                            ui->tabl_2->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                            ui->tabl_2->setVisible(false);
                            ui->tabl_2->setEnabled(false);
                            }
                        }

                        if (GribOrg[MassiveFight[i]].posX > TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX + TablOrg[i].stepX;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posX < TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX - TablOrg[i].stepX;
                        }

                        if (GribOrg[MassiveFight[i]].posY > TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY + TablOrg[i].stepY;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posY < TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY - TablOrg[i].stepY;
                        }

                        if ((GribOrg[MassiveFight[i]].HP == 0) && (TablOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 3:
                    {
                        if (((VirusOrg[MassiveFight[i]].posX - 5) <= TablOrg[i].posX) && ((VirusOrg[MassiveFight[i]].posX + 15) >= TablOrg[i].posX))
                        {
                            if (((VirusOrg[MassiveFight[i]].posY - 5) <= TablOrg[i].posY) && ((VirusOrg[MassiveFight[i]].posY + 15) >= TablOrg[i].posY))
                            {
                            TablOrg[i].dead = true;
                            VirusOrg[MassiveFight[i]].HP = 0;
                            TablOrg[i].size_w = ui->tabl_2->width();
                            TablOrg[i].size_h = ui->tabl_2->height();
                            TablOrg[i].posX = 0;
                            TablOrg[i].posY = 0;
                            ui->tabl_2->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                            ui->tabl_2->setVisible(false);
                            ui->tabl_2->setEnabled(false);
                            }
                        }

                        if (VirusOrg[MassiveFight[i]].posX > TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX + TablOrg[i].stepX;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posX < TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX - TablOrg[i].stepX;
                        }

                        if (VirusOrg[MassiveFight[i]].posY > TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY + TablOrg[i].stepY;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posY < TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY - TablOrg[i].stepY;
                        }
                        if ((VirusOrg[MassiveFight[i]].HP == 0)  && (TablOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    }
                }
              ui->tabl_2->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
              break;
            }
            case 2:
            {
                TablOrg[i].posX = ui->tabl_3->x();
                TablOrg[i].posY = ui->tabl_3->y();
                TablOrg[i].size_w = ui->tabl_3->width();
                TablOrg[i].size_h = ui->tabl_3->height();

                if (MassiveFight[i] == 0)
                {
                    TablOrg[i].posX += TablOrg[i].stepX;
                    if ((TablOrg[i].posX > 642) || (TablOrg[i].posX < 30))
                    {
                        TablOrg[i].stepX = -TablOrg[i].stepX;
                    }
                    TablOrg[i].posY += TablOrg[i].stepY;
                    if ((TablOrg[i].posY > 445) || (TablOrg[i].posY < 20))
                    {
                        TablOrg[i].stepY = -TablOrg[i].stepY;
                    }
                switch (TypeOfFunction)
                {
                case 1:
                {
                    for (int j = 0; j < 12; j++)
                    {
                        if (((TablOrg[i].posX + 150) >= BaktOrg[j].posX) && ((TablOrg[i].posX - 83) <= BaktOrg[j].posX))
                        {
                            if (((TablOrg[i].posY + 150) >= BaktOrg[j].posY) && ((TablOrg[i].posY - 83) <= BaktOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    TablOrg[i].stepX = 1;
                                    TablOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 2:
                {
                    for (int j = 0; j < 9; j++)
                    {
                        if (((TablOrg[i].posX + 150) >= GribOrg[j].posX) && ((TablOrg[i].posX - 83) <= GribOrg[j].posX))
                        {
                            if (((TablOrg[i].posY + 150) >= GribOrg[j].posY) && ((TablOrg[i].posY - 83) <= GribOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    TablOrg[i].stepX = 1;
                                    TablOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 3:
                {
                    for (int j = 0; j < 6; j++)
                    {
                        if (((TablOrg[i].posX + 150) >= VirusOrg[j].posX) && ((TablOrg[i].posX - 83) <= VirusOrg[j].posX))
                        {
                            if (((TablOrg[i].posY + 150) >= VirusOrg[j].posY) && ((TablOrg[i].posY - 83) <= VirusOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    TablOrg[i].stepX = 1;
                                    TablOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                }
                }
                else
                {
                    switch (TypeOfFunction)
                    {
                    case 1:
                    {
                        if (((BaktOrg[MassiveFight[i]].posX - 5) <= TablOrg[i].posX) && ((BaktOrg[MassiveFight[i]].posX + 15) >= TablOrg[i].posX))
                        {
                            if (((BaktOrg[MassiveFight[i]].posY - 5) <= TablOrg[i].posY) && ((BaktOrg[MassiveFight[i]].posY + 15) >= TablOrg[i].posY))
                            {
                            TablOrg[i].dead = true;
                            BaktOrg[MassiveFight[i]].HP = 0;
                            TablOrg[i].size_w = ui->tabl_3->width();
                            TablOrg[i].size_h = ui->tabl_3->height();
                            TablOrg[i].posX = 0;
                            TablOrg[i].posY = 0;
                            ui->tabl_3->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                            ui->tabl_3->setVisible(false);
                            ui->tabl_3->setEnabled(false);
                            }
                        }

                        if (BaktOrg[MassiveFight[i]].posX > TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX + TablOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posX < TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX - TablOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posY > TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY + TablOrg[i].stepY;
                        }

                        if (BaktOrg[MassiveFight[i]].posY < TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY - TablOrg[i].stepY;
                        }

                        if ((BaktOrg[MassiveFight[i]].HP == 0) && (TablOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 2:
                    {
                        if (((GribOrg[MassiveFight[i]].posX - 5) <= TablOrg[i].posX) && ((GribOrg[MassiveFight[i]].posX + 15) >= TablOrg[i].posX))
                        {
                            if (((GribOrg[MassiveFight[i]].posY - 5) <= TablOrg[i].posY) && ((GribOrg[MassiveFight[i]].posY + 15) >= TablOrg[i].posY))
                            {
                            TablOrg[i].dead = true;
                            GribOrg[MassiveFight[i]].HP = 0;
                            TablOrg[i].size_w = ui->tabl_3->width();
                            TablOrg[i].size_h = ui->tabl_3->height();
                            TablOrg[i].posX = 0;
                            TablOrg[i].posY = 0;
                            ui->tabl_3->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                            ui->tabl_3->setVisible(false);
                            ui->tabl_3->setEnabled(false);
                            }
                        }

                        if (GribOrg[MassiveFight[i]].posX > TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX + TablOrg[i].stepX;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posX < TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX - TablOrg[i].stepX;
                        }

                        if (GribOrg[MassiveFight[i]].posY > TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY + TablOrg[i].stepY;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posY < TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY - TablOrg[i].stepY;
                        }

                        if ((GribOrg[MassiveFight[i]].HP == 0) && (TablOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 3:
                    {
                        if (((VirusOrg[MassiveFight[i]].posX - 5) <= TablOrg[i].posX) && ((VirusOrg[MassiveFight[i]].posX + 15) >= TablOrg[i].posX))
                        {
                            if (((VirusOrg[MassiveFight[i]].posY - 5) <= TablOrg[i].posY) && ((VirusOrg[MassiveFight[i]].posY + 15) >= TablOrg[i].posY))
                            {
                            TablOrg[i].dead = true;
                            VirusOrg[MassiveFight[i]].HP = 0;
                            TablOrg[i].size_w = ui->tabl_3->width();
                            TablOrg[i].size_h = ui->tabl_3->height();
                            TablOrg[i].posX = 0;
                            TablOrg[i].posY = 0;
                            ui->tabl_3->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                            ui->tabl_3->setVisible(false);
                            ui->tabl_3->setEnabled(false);
                            }
                        }

                        if (VirusOrg[MassiveFight[i]].posX > TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX + TablOrg[i].stepX;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posX < TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX - TablOrg[i].stepX;
                        }

                        if (VirusOrg[MassiveFight[i]].posY > TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY + TablOrg[i].stepY;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posY < TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY - TablOrg[i].stepY;
                        }
                        if ((VirusOrg[MassiveFight[i]].HP == 0)  && (TablOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    }
                }
                ui->tabl_3->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
              break;
            }
            case 3:
            {
                TablOrg[i].posX = ui->tabl_4->x();
                TablOrg[i].posY = ui->tabl_4->y();
                TablOrg[i].size_w = ui->tabl_4->width();
                TablOrg[i].size_h = ui->tabl_4->height();

                if (MassiveFight[i] == 0)
                {
                    TablOrg[i].posX += TablOrg[i].stepX;
                    if ((TablOrg[i].posX > 642) || (TablOrg[i].posX < 30))
                    {
                        TablOrg[i].stepX = -TablOrg[i].stepX;
                    }
                    TablOrg[i].posY += TablOrg[i].stepY;
                    if ((TablOrg[i].posY > 445) || (TablOrg[i].posY < 20))
                    {
                        TablOrg[i].stepY = -TablOrg[i].stepY;
                    }
                switch (TypeOfFunction)
                {
                case 1:
                {
                    for (int j = 0; j < 12; j++)
                    {
                        if (((TablOrg[i].posX + 150) >= BaktOrg[j].posX) && ((TablOrg[i].posX - 83) <= BaktOrg[j].posX))
                        {
                            if (((TablOrg[i].posY + 150) >= BaktOrg[j].posY) && ((TablOrg[i].posY - 83) <= BaktOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    TablOrg[i].stepX = 1;
                                    TablOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 2:
                {
                    for (int j = 0; j < 9; j++)
                    {
                        if (((TablOrg[i].posX + 150) >= GribOrg[j].posX) && ((TablOrg[i].posX - 83) <= GribOrg[j].posX))
                        {
                            if (((TablOrg[i].posY + 150) >= GribOrg[j].posY) && ((TablOrg[i].posY - 83) <= GribOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    TablOrg[i].stepX = 1;
                                    TablOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 3:
                {
                    for (int j = 0; j < 6; j++)
                    {
                        if (((TablOrg[i].posX + 150) >= VirusOrg[j].posX) && ((TablOrg[i].posX - 83) <= VirusOrg[j].posX))
                        {
                            if (((TablOrg[i].posY + 150) >= VirusOrg[j].posY) && ((TablOrg[i].posY - 83) <= VirusOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    TablOrg[i].stepX = 1;
                                    TablOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                }
                }
                else
                {
                    switch (TypeOfFunction)
                    {
                    case 1:
                    {
                        if (((BaktOrg[MassiveFight[i]].posX - 5) <= TablOrg[i].posX) && ((BaktOrg[MassiveFight[i]].posX + 15) >= TablOrg[i].posX))
                        {
                            if (((BaktOrg[MassiveFight[i]].posY - 5) <= TablOrg[i].posY) && ((BaktOrg[MassiveFight[i]].posY + 15) >= TablOrg[i].posY))
                            {
                            TablOrg[i].dead = true;
                            BaktOrg[MassiveFight[i]].HP = 0;
                            TablOrg[i].size_w = ui->tabl_4->width();
                            TablOrg[i].size_h = ui->tabl_4->height();
                            TablOrg[i].posX = 0;
                            TablOrg[i].posY = 0;
                            ui->tabl_4->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                            ui->tabl_4->setVisible(false);
                            ui->tabl_4->setEnabled(false);
                            }
                        }

                        if (BaktOrg[MassiveFight[i]].posX > TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX + TablOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posX < TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX - TablOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posY > TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY + TablOrg[i].stepY;
                        }

                        if (BaktOrg[MassiveFight[i]].posY < TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY - TablOrg[i].stepY;
                        }

                        if ((BaktOrg[MassiveFight[i]].HP == 0) && (TablOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 2:
                    {
                        if (((GribOrg[MassiveFight[i]].posX - 5) <= TablOrg[i].posX) && ((GribOrg[MassiveFight[i]].posX + 15) >= TablOrg[i].posX))
                        {
                            if (((GribOrg[MassiveFight[i]].posY - 5) <= TablOrg[i].posY) && ((GribOrg[MassiveFight[i]].posY + 15) >= TablOrg[i].posY))
                            {
                            TablOrg[i].dead = true;
                            GribOrg[MassiveFight[i]].HP = 0;
                            TablOrg[i].size_w = ui->tabl_4->width();
                            TablOrg[i].size_h = ui->tabl_4->height();
                            TablOrg[i].posX = 0;
                            TablOrg[i].posY = 0;
                            ui->tabl_4->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                            ui->tabl_4->setVisible(false);
                            ui->tabl_4->setEnabled(false);
                            }
                        }

                        if (GribOrg[MassiveFight[i]].posX > TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX + TablOrg[i].stepX;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posX < TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX - TablOrg[i].stepX;
                        }

                        if (GribOrg[MassiveFight[i]].posY > TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY + TablOrg[i].stepY;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posY < TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY - TablOrg[i].stepY;
                        }

                        if ((GribOrg[MassiveFight[i]].HP == 0) && (TablOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 3:
                    {
                        if (((VirusOrg[MassiveFight[i]].posX - 5) <= TablOrg[i].posX) && ((VirusOrg[MassiveFight[i]].posX + 15) >= TablOrg[i].posX))
                        {
                            if (((VirusOrg[MassiveFight[i]].posY - 5) <= TablOrg[i].posY) && ((VirusOrg[MassiveFight[i]].posY + 15) >= TablOrg[i].posY))
                            {
                            TablOrg[i].dead = true;
                            VirusOrg[MassiveFight[i]].HP = 0;
                            TablOrg[i].size_w = ui->tabl_4->width();
                            TablOrg[i].size_h = ui->tabl_4->height();
                            TablOrg[i].posX = 0;
                            TablOrg[i].posY = 0;
                            ui->tabl_4->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                            ui->tabl_4->setVisible(false);
                            ui->tabl_4->setEnabled(false);
                            }
                        }

                        if (VirusOrg[MassiveFight[i]].posX > TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX + TablOrg[i].stepX;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posX < TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX - TablOrg[i].stepX;
                        }

                        if (VirusOrg[MassiveFight[i]].posY > TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY + TablOrg[i].stepY;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posY < TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY - TablOrg[i].stepY;
                        }
                        if ((VirusOrg[MassiveFight[i]].HP == 0)  && (TablOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    }
                }
                ui->tabl_4->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
              break;
            }
            case 4:
            {
                TablOrg[i].posX = ui->tabl_5->x();
                TablOrg[i].posY = ui->tabl_5->y();
                TablOrg[i].size_w = ui->tabl_5->width();
                TablOrg[i].size_h = ui->tabl_5->height();

                if (MassiveFight[i] == 0)
                {
                    TablOrg[i].posX += TablOrg[i].stepX;
                    if ((TablOrg[i].posX > 642) || (TablOrg[i].posX < 30))
                    {
                        TablOrg[i].stepX = -TablOrg[i].stepX;
                    }
                    TablOrg[i].posY += TablOrg[i].stepY;
                    if ((TablOrg[i].posY > 445) || (TablOrg[i].posY < 20))
                    {
                        TablOrg[i].stepY = -TablOrg[i].stepY;
                    }
                switch (TypeOfFunction)
                {
                case 1:
                {
                    for (int j = 0; j < 12; j++)
                    {
                        if (((TablOrg[i].posX + 150) >= BaktOrg[j].posX) && ((TablOrg[i].posX - 83) <= BaktOrg[j].posX))
                        {
                            if (((TablOrg[i].posY + 150) >= BaktOrg[j].posY) && ((TablOrg[i].posY - 83) <= BaktOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    TablOrg[i].stepX = 1;
                                    TablOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 2:
                {
                    for (int j = 0; j < 9; j++)
                    {
                        if (((TablOrg[i].posX + 150) >= GribOrg[j].posX) && ((TablOrg[i].posX - 83) <= GribOrg[j].posX))
                        {
                            if (((TablOrg[i].posY + 150) >= GribOrg[j].posY) && ((TablOrg[i].posY - 83) <= GribOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    TablOrg[i].stepX = 1;
                                    TablOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 3:
                {
                    for (int j = 0; j < 6; j++)
                    {
                        if (((TablOrg[i].posX + 150) >= VirusOrg[j].posX) && ((TablOrg[i].posX - 83) <= VirusOrg[j].posX))
                        {
                            if (((TablOrg[i].posY + 150) >= VirusOrg[j].posY) && ((TablOrg[i].posY - 83) <= VirusOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    TablOrg[i].stepX = 1;
                                    TablOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                }
                }
                else
                {
                    switch (TypeOfFunction)
                    {
                    case 1:
                    {
                        if (((BaktOrg[MassiveFight[i]].posX - 5) <= TablOrg[i].posX) && ((BaktOrg[MassiveFight[i]].posX + 15) >= TablOrg[i].posX))
                        {
                            if (((BaktOrg[MassiveFight[i]].posY - 5) <= TablOrg[i].posY) && ((BaktOrg[MassiveFight[i]].posY + 15) >= TablOrg[i].posY))
                            {
                            TablOrg[i].dead = true;
                            BaktOrg[MassiveFight[i]].HP = 0;
                            TablOrg[i].size_w = ui->tabl_5->width();
                            TablOrg[i].size_h = ui->tabl_5->height();
                            TablOrg[i].posX = 0;
                            TablOrg[i].posY = 0;
                            ui->tabl_5->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                            ui->tabl_5->setVisible(false);
                            ui->tabl_5->setEnabled(false);
                            }
                        }

                        if (BaktOrg[MassiveFight[i]].posX > TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX + TablOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posX < TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX - TablOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posY > TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY + TablOrg[i].stepY;
                        }

                        if (BaktOrg[MassiveFight[i]].posY < TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY - TablOrg[i].stepY;
                        }

                        if ((BaktOrg[MassiveFight[i]].HP == 0) && (TablOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 2:
                    {
                        if (((GribOrg[MassiveFight[i]].posX - 5) <= TablOrg[i].posX) && ((GribOrg[MassiveFight[i]].posX + 15) >= TablOrg[i].posX))
                        {
                            if (((GribOrg[MassiveFight[i]].posY - 5) <= TablOrg[i].posY) && ((GribOrg[MassiveFight[i]].posY + 15) >= TablOrg[i].posY))
                            {
                            TablOrg[i].dead = true;
                            GribOrg[MassiveFight[i]].HP = 0;
                            TablOrg[i].size_w = ui->tabl_5->width();
                            TablOrg[i].size_h = ui->tabl_5->height();
                            TablOrg[i].posX = 0;
                            TablOrg[i].posY = 0;
                            ui->tabl_5->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                            ui->tabl_5->setVisible(false);
                            ui->tabl_5->setEnabled(false);
                            }
                        }

                        if (GribOrg[MassiveFight[i]].posX > TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX + TablOrg[i].stepX;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posX < TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX - TablOrg[i].stepX;
                        }

                        if (GribOrg[MassiveFight[i]].posY > TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY + TablOrg[i].stepY;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posY < TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY - TablOrg[i].stepY;
                        }

                        if ((GribOrg[MassiveFight[i]].HP == 0) && (TablOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 3:
                    {
                        if (((VirusOrg[MassiveFight[i]].posX - 5) <= TablOrg[i].posX) && ((VirusOrg[MassiveFight[i]].posX + 15) >= TablOrg[i].posX))
                        {
                            if (((VirusOrg[MassiveFight[i]].posY - 5) <= TablOrg[i].posY) && ((VirusOrg[MassiveFight[i]].posY + 15) >= TablOrg[i].posY))
                            {
                            TablOrg[i].dead = true;
                            VirusOrg[MassiveFight[i]].HP = 0;
                            TablOrg[i].size_w = ui->tabl_5->width();
                            TablOrg[i].size_h = ui->tabl_5->height();
                            TablOrg[i].posX = 0;
                            TablOrg[i].posY = 0;
                            ui->tabl_5->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
                            ui->tabl_5->setVisible(false);
                            ui->tabl_5->setEnabled(false);
                            }
                        }

                        if (VirusOrg[MassiveFight[i]].posX > TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX + TablOrg[i].stepX;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posX < TablOrg[i].posX)
                        {
                            TablOrg[i].posX = TablOrg[i].posX - TablOrg[i].stepX;
                        }

                        if (VirusOrg[MassiveFight[i]].posY > TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY + TablOrg[i].stepY;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posY < TablOrg[i].posY)
                        {
                            TablOrg[i].posY = TablOrg[i].posY - TablOrg[i].stepY;
                        }
                        if ((VirusOrg[MassiveFight[i]].HP == 0)  && (TablOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    }
                }
                ui->tabl_5->setGeometry(TablOrg[i].posX, TablOrg[i].posY, TablOrg[i].size_w, TablOrg[i].size_h);
              break;
             }
             }
        }
        break;
    }
    case 2:
    {
        for (int i = 0; i < 5; i++)
        {
            switch (i)
            {
            case 0:
            {
                AntibOrg[i].posX = ui->antib_1->x();
                AntibOrg[i].posY = ui->antib_1->y();
                AntibOrg[i].size_w = ui->antib_1->width();
                AntibOrg[i].size_h = ui->antib_1->height();

                if (MassiveFight[i] == 0)
                {
                    AntibOrg[i].posX += AntibOrg[i].stepX;
                    if ((AntibOrg[i].posX > 642) || (AntibOrg[i].posX < 30))
                    {
                        AntibOrg[i].stepX = -AntibOrg[i].stepX;
                    }
                    AntibOrg[i].posY += AntibOrg[i].stepY;
                    if ((AntibOrg[i].posY > 445) || (AntibOrg[i].posY < 20))
                    {
                        AntibOrg[i].stepY = -AntibOrg[i].stepY;
                    }
                switch (TypeOfFunction)
                {
                case 1:
                {
                    for (int j = 0; j < 12; j++)
                    {
                        if (((AntibOrg[i].posX + 150) >= BaktOrg[j].posX) && ((AntibOrg[i].posX - 83) <= BaktOrg[j].posX))
                        {
                            if (((AntibOrg[i].posY + 150) >= BaktOrg[j].posY) && ((AntibOrg[i].posY - 83) <= BaktOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    AntibOrg[i].stepX = 1;
                                    AntibOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 2:
                {
                    for (int j = 0; j < 9; j++)
                    {
                        if (((AntibOrg[i].posX + 150) >= GribOrg[j].posX) && ((AntibOrg[i].posX - 83) <= GribOrg[j].posX))
                        {
                            if (((AntibOrg[i].posY + 150) >= GribOrg[j].posY) && ((AntibOrg[i].posY - 83) <= GribOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    AntibOrg[i].stepX = 1;
                                    AntibOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 3:
                {
                    for (int j = 0; j < 6; j++)
                    {
                        if (((AntibOrg[i].posX + 150) >= VirusOrg[j].posX) && ((AntibOrg[i].posX - 83) <= VirusOrg[j].posX))
                        {
                            if (((AntibOrg[i].posY + 150) >= VirusOrg[j].posY) && ((AntibOrg[i].posY - 83) <= VirusOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    AntibOrg[i].stepX = 1;
                                    AntibOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                }
                }
                else
                {
                    switch (TypeOfFunction)
                    {
                    case 1:
                    {
                        if (((BaktOrg[MassiveFight[i]].posX - 5) <= AntibOrg[i].posX) && ((BaktOrg[MassiveFight[i]].posX + 15) >= AntibOrg[i].posX))
                        {
                            if (((BaktOrg[MassiveFight[i]].posY - 5) <= AntibOrg[i].posY) && ((BaktOrg[MassiveFight[i]].posY + 15) >= AntibOrg[i].posY))
                            {
                            AntibOrg[i].HP--;
                            BaktOrg[MassiveFight[i]].HP = 0;
                            if (AntibOrg[i].HP == 0)
                            {
                                AntibOrg[i].size_w = ui->antib_1->width();
                                AntibOrg[i].size_h = ui->antib_1->height();
                                AntibOrg[i].posX = 0;
                                AntibOrg[i].posY = 0;
                                ui->antib_1->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                                ui->antib_1->setVisible(false);
                                ui->antib_1->setEnabled(false);
                            }
                            else
                                MassiveFight[i] = 0;
                            }
                        }

                        if (BaktOrg[MassiveFight[i]].posX > AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX + AntibOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posX < AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX - AntibOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posY > AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY + AntibOrg[i].stepY;
                        }

                        if (BaktOrg[MassiveFight[i]].posY < AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY - AntibOrg[i].stepY;
                        }

                        if ((BaktOrg[MassiveFight[i]].HP == 0) && (AntibOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 2:
                    {
                        if (((GribOrg[MassiveFight[i]].posX - 5) <= AntibOrg[i].posX) && ((GribOrg[MassiveFight[i]].posX + 15) >= AntibOrg[i].posX))
                        {
                            if (((GribOrg[MassiveFight[i]].posY - 5) <= AntibOrg[i].posY) && ((GribOrg[MassiveFight[i]].posY + 15) >= AntibOrg[i].posY))
                            {
                                AntibOrg[i].HP--;
                                GribOrg[MassiveFight[i]].HP = 0;
                                if (AntibOrg[i].HP == 0)
                                {
                                    AntibOrg[i].size_w = ui->antib_1->width();
                                    AntibOrg[i].size_h = ui->antib_1->height();
                                    AntibOrg[i].posX = 0;
                                    AntibOrg[i].posY = 0;
                                    ui->antib_1->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                                    ui->antib_1->setVisible(false);
                                    ui->antib_1->setEnabled(false);
                                }
                                else
                                    MassiveFight[i] = 0;
                            }
                        }

                        if (GribOrg[MassiveFight[i]].posX > AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX + AntibOrg[i].stepX;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posX < AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX - AntibOrg[i].stepX;
                        }

                        if (GribOrg[MassiveFight[i]].posY > AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY + AntibOrg[i].stepY;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posY < AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY - AntibOrg[i].stepY;
                        }

                        if ((GribOrg[MassiveFight[i]].HP == 0) && (AntibOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 3:
                    {
                        if (((VirusOrg[MassiveFight[i]].posX - 5) <= AntibOrg[i].posX) && ((VirusOrg[MassiveFight[i]].posX + 15) >= AntibOrg[i].posX))
                        {
                            if (((VirusOrg[MassiveFight[i]].posY - 5) <= AntibOrg[i].posY) && ((VirusOrg[MassiveFight[i]].posY + 15) >= AntibOrg[i].posY))
                            {
                                AntibOrg[i].HP--;
                                VirusOrg[MassiveFight[i]].HP = 0;
                                if (AntibOrg[i].HP == 0)
                                {
                                    AntibOrg[i].size_w = ui->antib_1->width();
                                    AntibOrg[i].size_h = ui->antib_1->height();
                                    AntibOrg[i].posX = 0;
                                    AntibOrg[i].posY = 0;
                                    ui->antib_1->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                                    ui->antib_1->setVisible(false);
                                    ui->antib_1->setEnabled(false);
                                }
                                else
                                    MassiveFight[i] = 0;
                            }
                        }

                        if (VirusOrg[MassiveFight[i]].posX > AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX + AntibOrg[i].stepX;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posX < AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX - AntibOrg[i].stepX;
                        }

                        if (VirusOrg[MassiveFight[i]].posY > AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY + AntibOrg[i].stepY;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posY < AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY - AntibOrg[i].stepY;
                        }
                        if ((VirusOrg[MassiveFight[i]].HP == 0)  && (AntibOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                }
                }
                ui->antib_1->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
              break;
            }
            case 1:
            {
                AntibOrg[i].posX = ui->antib_2->x();
                AntibOrg[i].posY = ui->antib_2->y();
                AntibOrg[i].size_w = ui->antib_2->width();
                AntibOrg[i].size_h = ui->antib_2->height();

                if (MassiveFight[i] == 0)
                {
                    AntibOrg[i].posX += AntibOrg[i].stepX;
                    if ((AntibOrg[i].posX > 642) || (AntibOrg[i].posX < 30))
                    {
                        AntibOrg[i].stepX = -AntibOrg[i].stepX;
                    }
                    AntibOrg[i].posY += AntibOrg[i].stepY;
                    if ((AntibOrg[i].posY > 445) || (AntibOrg[i].posY < 20))
                    {
                        AntibOrg[i].stepY = -AntibOrg[i].stepY;
                    }
                switch (TypeOfFunction)
                {
                case 1:
                {
                    for (int j = 0; j < 12; j++)
                    {
                        if (((AntibOrg[i].posX + 150) >= BaktOrg[j].posX) && ((AntibOrg[i].posX - 83) <= BaktOrg[j].posX))
                        {
                            if (((AntibOrg[i].posY + 150) >= BaktOrg[j].posY) && ((AntibOrg[i].posY - 83) <= BaktOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    AntibOrg[i].stepX = 1;
                                    AntibOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 2:
                {
                    for (int j = 0; j < 9; j++)
                    {
                        if (((AntibOrg[i].posX + 150) >= GribOrg[j].posX) && ((AntibOrg[i].posX - 83) <= GribOrg[j].posX))
                        {
                            if (((AntibOrg[i].posY + 150) >= GribOrg[j].posY) && ((AntibOrg[i].posY - 83) <= GribOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    AntibOrg[i].stepX = 1;
                                    AntibOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 3:
                {
                    for (int j = 0; j < 6; j++)
                    {
                        if (((AntibOrg[i].posX + 150) >= VirusOrg[j].posX) && ((AntibOrg[i].posX - 83) <= VirusOrg[j].posX))
                        {
                            if (((AntibOrg[i].posY + 150) >= VirusOrg[j].posY) && ((AntibOrg[i].posY - 83) <= VirusOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    AntibOrg[i].stepX = 1;
                                    AntibOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                }
                }
                else
                {
                    switch (TypeOfFunction)
                    {
                    case 1:
                    {
                        if (((BaktOrg[MassiveFight[i]].posX - 5) <= AntibOrg[i].posX) && ((BaktOrg[MassiveFight[i]].posX + 15) >= AntibOrg[i].posX))
                        {
                            if (((BaktOrg[MassiveFight[i]].posY - 5) <= AntibOrg[i].posY) && ((BaktOrg[MassiveFight[i]].posY + 15) >= AntibOrg[i].posY))
                            {
                                AntibOrg[i].HP--;
                                BaktOrg[MassiveFight[i]].HP = 0;
                                if (AntibOrg[i].HP == 0)
                                {
                                    AntibOrg[i].size_w = ui->antib_2->width();
                                    AntibOrg[i].size_h = ui->antib_2->height();
                                    AntibOrg[i].posX = 0;
                                    AntibOrg[i].posY = 0;
                                    ui->antib_2->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                                    ui->antib_2->setVisible(false);
                                    ui->antib_2->setEnabled(false);
                                }
                                else
                                    MassiveFight[i] = 0;
                            }
                        }

                        if (BaktOrg[MassiveFight[i]].posX > AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX + AntibOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posX < AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX - AntibOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posY > AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY + AntibOrg[i].stepY;
                        }

                        if (BaktOrg[MassiveFight[i]].posY < AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY - AntibOrg[i].stepY;
                        }

                        if ((BaktOrg[MassiveFight[i]].HP == 0) && (AntibOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 2:
                    {
                        if (((GribOrg[MassiveFight[i]].posX - 5) <= AntibOrg[i].posX) && ((GribOrg[MassiveFight[i]].posX + 15) >= AntibOrg[i].posX))
                        {
                            if (((GribOrg[MassiveFight[i]].posY - 5) <= AntibOrg[i].posY) && ((GribOrg[MassiveFight[i]].posY + 15) >= AntibOrg[i].posY))
                            {
                                AntibOrg[i].HP--;
                                GribOrg[MassiveFight[i]].HP = 0;
                                if (AntibOrg[i].HP == 0)
                                {
                                    AntibOrg[i].size_w = ui->antib_2->width();
                                    AntibOrg[i].size_h = ui->antib_2->height();
                                    AntibOrg[i].posX = 0;
                                    AntibOrg[i].posY = 0;
                                    ui->antib_2->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                                    ui->antib_2->setVisible(false);
                                    ui->antib_2->setEnabled(false);
                                }
                                else
                                    MassiveFight[i] = 0;
                            }
                        }

                        if (GribOrg[MassiveFight[i]].posX > AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX + AntibOrg[i].stepX;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posX < AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX - AntibOrg[i].stepX;
                        }

                        if (GribOrg[MassiveFight[i]].posY > AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY + AntibOrg[i].stepY;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posY < AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY - AntibOrg[i].stepY;
                        }

                        if ((GribOrg[MassiveFight[i]].HP == 0) && (AntibOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 3:
                    {
                        if (((VirusOrg[MassiveFight[i]].posX - 5) <= AntibOrg[i].posX) && ((VirusOrg[MassiveFight[i]].posX + 15) >= AntibOrg[i].posX))
                        {
                            if (((VirusOrg[MassiveFight[i]].posY - 5) <= AntibOrg[i].posY) && ((VirusOrg[MassiveFight[i]].posY + 15) >= AntibOrg[i].posY))
                            {
                                AntibOrg[i].HP--;
                                VirusOrg[MassiveFight[i]].HP = 0;
                                if (AntibOrg[i].HP == 0)
                                {
                                    AntibOrg[i].size_w = ui->antib_2->width();
                                    AntibOrg[i].size_h = ui->antib_2->height();
                                    AntibOrg[i].posX = 0;
                                    AntibOrg[i].posY = 0;
                                    ui->antib_2->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                                    ui->antib_2->setVisible(false);
                                    ui->antib_2->setEnabled(false);
                                }
                                else
                                    MassiveFight[i] = 0;
                            }
                        }

                        if (VirusOrg[MassiveFight[i]].posX > AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX + AntibOrg[i].stepX;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posX < AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX - AntibOrg[i].stepX;
                        }

                        if (VirusOrg[MassiveFight[i]].posY > AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY + AntibOrg[i].stepY;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posY < AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY - AntibOrg[i].stepY;
                        }
                        if ((VirusOrg[MassiveFight[i]].HP == 0)  && (AntibOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    }
                }
              ui->antib_2->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
              break;
            }
            case 2:
            {
                AntibOrg[i].posX = ui->antib_3->x();
                AntibOrg[i].posY = ui->antib_3->y();
                AntibOrg[i].size_w = ui->antib_3->width();
                AntibOrg[i].size_h = ui->antib_3->height();

                if (MassiveFight[i] == 0)
                {
                    AntibOrg[i].posX += AntibOrg[i].stepX;
                    if ((AntibOrg[i].posX > 642) || (AntibOrg[i].posX < 30))
                    {
                        AntibOrg[i].stepX = -AntibOrg[i].stepX;
                    }
                    AntibOrg[i].posY += AntibOrg[i].stepY;
                    if ((AntibOrg[i].posY > 445) || (AntibOrg[i].posY < 20))
                    {
                        AntibOrg[i].stepY = -AntibOrg[i].stepY;
                    }
                switch (TypeOfFunction)
                {
                case 1:
                {
                    for (int j = 0; j < 12; j++)
                    {
                        if (((AntibOrg[i].posX + 150) >= BaktOrg[j].posX) && ((AntibOrg[i].posX - 83) <= BaktOrg[j].posX))
                        {
                            if (((AntibOrg[i].posY + 150) >= BaktOrg[j].posY) && ((AntibOrg[i].posY - 83) <= BaktOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    AntibOrg[i].stepX = 1;
                                    AntibOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 2:
                {
                    for (int j = 0; j < 9; j++)
                    {
                        if (((AntibOrg[i].posX + 150) >= GribOrg[j].posX) && ((AntibOrg[i].posX - 83) <= GribOrg[j].posX))
                        {
                            if (((AntibOrg[i].posY + 150) >= GribOrg[j].posY) && ((AntibOrg[i].posY - 83) <= GribOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    AntibOrg[i].stepX = 1;
                                    AntibOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 3:
                {
                    for (int j = 0; j < 6; j++)
                    {
                        if (((AntibOrg[i].posX + 150) >= VirusOrg[j].posX) && ((AntibOrg[i].posX - 83) <= VirusOrg[j].posX))
                        {
                            if (((AntibOrg[i].posY + 150) >= VirusOrg[j].posY) && ((AntibOrg[i].posY - 83) <= VirusOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    AntibOrg[i].stepX = 1;
                                    AntibOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                }
                }
                else
                {
                    switch (TypeOfFunction)
                    {
                    case 1:
                    {
                        if (((BaktOrg[MassiveFight[i]].posX - 5) <= AntibOrg[i].posX) && ((BaktOrg[MassiveFight[i]].posX + 15) >= AntibOrg[i].posX))
                        {
                            if (((BaktOrg[MassiveFight[i]].posY - 5) <= AntibOrg[i].posY) && ((BaktOrg[MassiveFight[i]].posY + 15) >= AntibOrg[i].posY))
                            {
                                AntibOrg[i].HP--;
                                BaktOrg[MassiveFight[i]].HP = 0;
                                if (AntibOrg[i].HP == 0)
                                {
                                    AntibOrg[i].size_w = ui->antib_3->width();
                                    AntibOrg[i].size_h = ui->antib_3->height();
                                    AntibOrg[i].posX = 0;
                                    AntibOrg[i].posY = 0;
                                    ui->antib_3->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                                    ui->antib_3->setVisible(false);
                                    ui->antib_3->setEnabled(false);
                                }
                                else
                                    MassiveFight[i] = 0;
                            }
                        }

                        if (BaktOrg[MassiveFight[i]].posX > AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX + AntibOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posX < AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX - AntibOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posY > AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY + AntibOrg[i].stepY;
                        }

                        if (BaktOrg[MassiveFight[i]].posY < AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY - AntibOrg[i].stepY;
                        }

                        if ((BaktOrg[MassiveFight[i]].HP == 0) && (AntibOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 2:
                    {
                        if (((GribOrg[MassiveFight[i]].posX - 5) <= AntibOrg[i].posX) && ((GribOrg[MassiveFight[i]].posX + 15) >= AntibOrg[i].posX))
                        {
                            if (((GribOrg[MassiveFight[i]].posY - 5) <= AntibOrg[i].posY) && ((GribOrg[MassiveFight[i]].posY + 15) >= AntibOrg[i].posY))
                            {
                                AntibOrg[i].HP--;
                                GribOrg[MassiveFight[i]].HP = 0;
                                if (AntibOrg[i].HP == 0)
                                {
                                    AntibOrg[i].size_w = ui->antib_3->width();
                                    AntibOrg[i].size_h = ui->antib_3->height();
                                    AntibOrg[i].posX = 0;
                                    AntibOrg[i].posY = 0;
                                    ui->antib_3->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                                    ui->antib_3->setVisible(false);
                                    ui->antib_3->setEnabled(false);
                                }
                                else
                                    MassiveFight[i] = 0;
                            }
                        }

                        if (GribOrg[MassiveFight[i]].posX > AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX + AntibOrg[i].stepX;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posX < AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX - AntibOrg[i].stepX;
                        }

                        if (GribOrg[MassiveFight[i]].posY > AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY + AntibOrg[i].stepY;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posY < AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY - AntibOrg[i].stepY;
                        }

                        if ((GribOrg[MassiveFight[i]].HP == 0) && (AntibOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 3:
                    {
                        if (((VirusOrg[MassiveFight[i]].posX - 5) <= AntibOrg[i].posX) && ((VirusOrg[MassiveFight[i]].posX + 15) >= AntibOrg[i].posX))
                        {
                            if (((VirusOrg[MassiveFight[i]].posY - 5) <= AntibOrg[i].posY) && ((VirusOrg[MassiveFight[i]].posY + 15) >= AntibOrg[i].posY))
                            {
                                AntibOrg[i].HP--;
                                VirusOrg[MassiveFight[i]].HP = 0;
                                if (AntibOrg[i].HP == 0)
                                {
                                    AntibOrg[i].size_w = ui->antib_3->width();
                                    AntibOrg[i].size_h = ui->antib_3->height();
                                    AntibOrg[i].posX = 0;
                                    AntibOrg[i].posY = 0;
                                    ui->antib_3->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                                    ui->antib_3->setVisible(false);
                                    ui->antib_3->setEnabled(false);
                                }
                                else
                                    MassiveFight[i] = 0;
                            }
                        }

                        if (VirusOrg[MassiveFight[i]].posX > AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX + AntibOrg[i].stepX;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posX < AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX - AntibOrg[i].stepX;
                        }

                        if (VirusOrg[MassiveFight[i]].posY > AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY + AntibOrg[i].stepY;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posY < AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY - AntibOrg[i].stepY;
                        }
                        if ((VirusOrg[MassiveFight[i]].HP == 0)  && (AntibOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    }
                }
                ui->antib_3->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
              break;
            }
            case 3:
            {
                AntibOrg[i].posX = ui->antib_4->x();
                AntibOrg[i].posY = ui->antib_4->y();
                AntibOrg[i].size_w = ui->antib_4->width();
                AntibOrg[i].size_h = ui->antib_4->height();

                if (MassiveFight[i] == 0)
                {
                    AntibOrg[i].posX += AntibOrg[i].stepX;
                    if ((AntibOrg[i].posX > 642) || (AntibOrg[i].posX < 30))
                    {
                        AntibOrg[i].stepX = -AntibOrg[i].stepX;
                    }
                    AntibOrg[i].posY += AntibOrg[i].stepY;
                    if ((AntibOrg[i].posY > 445) || (AntibOrg[i].posY < 20))
                    {
                        AntibOrg[i].stepY = -AntibOrg[i].stepY;
                    }
                switch (TypeOfFunction)
                {
                case 1:
                {
                    for (int j = 0; j < 12; j++)
                    {
                        if (((AntibOrg[i].posX + 150) >= BaktOrg[j].posX) && ((AntibOrg[i].posX - 83) <= BaktOrg[j].posX))
                        {
                            if (((AntibOrg[i].posY + 150) >= BaktOrg[j].posY) && ((AntibOrg[i].posY - 83) <= BaktOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    AntibOrg[i].stepX = 1;
                                    AntibOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 2:
                {
                    for (int j = 0; j < 9; j++)
                    {
                        if (((AntibOrg[i].posX + 150) >= GribOrg[j].posX) && ((AntibOrg[i].posX - 83) <= GribOrg[j].posX))
                        {
                            if (((AntibOrg[i].posY + 150) >= GribOrg[j].posY) && ((AntibOrg[i].posY - 83) <= GribOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    AntibOrg[i].stepX = 1;
                                    AntibOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 3:
                {
                    for (int j = 0; j < 6; j++)
                    {
                        if (((AntibOrg[i].posX + 150) >= VirusOrg[j].posX) && ((AntibOrg[i].posX - 83) <= VirusOrg[j].posX))
                        {
                            if (((AntibOrg[i].posY + 150) >= VirusOrg[j].posY) && ((AntibOrg[i].posY - 83) <= VirusOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    AntibOrg[i].stepX = 1;
                                    AntibOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                }
                }
                else
                {
                    switch (TypeOfFunction)
                    {
                    case 1:
                    {
                        if (((BaktOrg[MassiveFight[i]].posX - 5) <= AntibOrg[i].posX) && ((BaktOrg[MassiveFight[i]].posX + 15) >= AntibOrg[i].posX))
                        {
                            if (((BaktOrg[MassiveFight[i]].posY - 5) <= AntibOrg[i].posY) && ((BaktOrg[MassiveFight[i]].posY + 15) >= AntibOrg[i].posY))
                            {
                                AntibOrg[i].HP--;
                                BaktOrg[MassiveFight[i]].HP = 0;
                                if (AntibOrg[i].HP == 0)
                                {
                                    AntibOrg[i].size_w = ui->antib_4->width();
                                    AntibOrg[i].size_h = ui->antib_4->height();
                                    AntibOrg[i].posX = 0;
                                    AntibOrg[i].posY = 0;
                                    ui->antib_4->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                                    ui->antib_4->setVisible(false);
                                    ui->antib_4->setEnabled(false);
                                }
                                else
                                    MassiveFight[i] = 0;
                            }
                        }

                        if (BaktOrg[MassiveFight[i]].posX > AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX + AntibOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posX < AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX - AntibOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posY > AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY + AntibOrg[i].stepY;
                        }

                        if (BaktOrg[MassiveFight[i]].posY < AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY - AntibOrg[i].stepY;
                        }

                        if ((BaktOrg[MassiveFight[i]].HP == 0) && (AntibOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 2:
                    {
                        if (((GribOrg[MassiveFight[i]].posX - 5) <= AntibOrg[i].posX) && ((GribOrg[MassiveFight[i]].posX + 15) >= AntibOrg[i].posX))
                        {
                            if (((GribOrg[MassiveFight[i]].posY - 5) <= AntibOrg[i].posY) && ((GribOrg[MassiveFight[i]].posY + 15) >= AntibOrg[i].posY))
                            {
                                AntibOrg[i].HP--;
                                GribOrg[MassiveFight[i]].HP = 0;
                                if (AntibOrg[i].HP == 0)
                                {
                                    AntibOrg[i].size_w = ui->antib_4->width();
                                    AntibOrg[i].size_h = ui->antib_4->height();
                                    AntibOrg[i].posX = 0;
                                    AntibOrg[i].posY = 0;
                                    ui->antib_4->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                                    ui->antib_4->setVisible(false);
                                    ui->antib_4->setEnabled(false);
                                }
                                else
                                    MassiveFight[i] = 0;
                            }
                        }

                        if (GribOrg[MassiveFight[i]].posX > AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX + AntibOrg[i].stepX;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posX < AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX - AntibOrg[i].stepX;
                        }

                        if (GribOrg[MassiveFight[i]].posY > AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY + AntibOrg[i].stepY;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posY < AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY - AntibOrg[i].stepY;
                        }

                        if ((GribOrg[MassiveFight[i]].HP == 0) && (AntibOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 3:
                    {
                        if (((VirusOrg[MassiveFight[i]].posX - 5) <= AntibOrg[i].posX) && ((VirusOrg[MassiveFight[i]].posX + 15) >= AntibOrg[i].posX))
                        {
                            if (((VirusOrg[MassiveFight[i]].posY - 5) <= AntibOrg[i].posY) && ((VirusOrg[MassiveFight[i]].posY + 15) >= AntibOrg[i].posY))
                            {
                                AntibOrg[i].HP--;
                                VirusOrg[MassiveFight[i]].HP = 0;
                                if (AntibOrg[i].HP == 0)
                                {
                                    AntibOrg[i].size_w = ui->antib_4->width();
                                    AntibOrg[i].size_h = ui->antib_4->height();
                                    AntibOrg[i].posX = 0;
                                    AntibOrg[i].posY = 0;
                                    ui->antib_4->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                                    ui->antib_4->setVisible(false);
                                    ui->antib_4->setEnabled(false);
                                }
                                else
                                    MassiveFight[i] = 0;
                            }
                        }

                        if (VirusOrg[MassiveFight[i]].posX > AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX + AntibOrg[i].stepX;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posX < AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX - AntibOrg[i].stepX;
                        }

                        if (VirusOrg[MassiveFight[i]].posY > AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY + AntibOrg[i].stepY;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posY < AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY - AntibOrg[i].stepY;
                        }
                        if ((VirusOrg[MassiveFight[i]].HP == 0)  && (AntibOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    }
                }
                ui->antib_4->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
              break;
            }
            case 4:
            {
                AntibOrg[i].posX = ui->antib_5->x();
                AntibOrg[i].posY = ui->antib_5->y();
                AntibOrg[i].size_w = ui->antib_5->width();
                AntibOrg[i].size_h = ui->antib_5->height();

                if (MassiveFight[i] == 0)
                {
                    AntibOrg[i].posX += AntibOrg[i].stepX;
                    if ((AntibOrg[i].posX > 642) || (AntibOrg[i].posX < 30))
                    {
                        AntibOrg[i].stepX = -AntibOrg[i].stepX;
                    }
                    AntibOrg[i].posY += AntibOrg[i].stepY;
                    if ((AntibOrg[i].posY > 445) || (AntibOrg[i].posY < 20))
                    {
                        AntibOrg[i].stepY = -AntibOrg[i].stepY;
                    }
                switch (TypeOfFunction)
                {
                case 1:
                {
                    for (int j = 0; j < 12; j++)
                    {
                        if (((AntibOrg[i].posX + 150) >= BaktOrg[j].posX) && ((AntibOrg[i].posX - 83) <= BaktOrg[j].posX))
                        {
                            if (((AntibOrg[i].posY + 150) >= BaktOrg[j].posY) && ((AntibOrg[i].posY - 83) <= BaktOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    AntibOrg[i].stepX = 1;
                                    AntibOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 2:
                {
                    for (int j = 0; j < 9; j++)
                    {
                        if (((AntibOrg[i].posX + 150) >= GribOrg[j].posX) && ((AntibOrg[i].posX - 83) <= GribOrg[j].posX))
                        {
                            if (((AntibOrg[i].posY + 150) >= GribOrg[j].posY) && ((AntibOrg[i].posY - 83) <= GribOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    AntibOrg[i].stepX = 1;
                                    AntibOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                case 3:
                {
                    for (int j = 0; j < 6; j++)
                    {
                        if (((AntibOrg[i].posX + 150) >= VirusOrg[j].posX) && ((AntibOrg[i].posX - 83) <= VirusOrg[j].posX))
                        {
                            if (((AntibOrg[i].posY + 150) >= VirusOrg[j].posY) && ((AntibOrg[i].posY - 83) <= VirusOrg[j].posY))
                            {
                                FlagHelper = false;
                                for (int k = 0; k < 5; k++)
                                {
                                    if ((MassiveFight[k] != j) && (FlagHelper != true))
                                    {
                                        FlagHelper = false;
                                    }
                                    else
                                    {
                                        FlagHelper = true;
                                    }
                                }

                                if (FlagHelper == false)
                                {
                                    MassiveFight[i]=j;
                                    AntibOrg[i].stepX = 1;
                                    AntibOrg[i].stepY = 1;
                                }
                            }
                        }
                    }
                    break;
                }
                }
                }
                else
                {
                    switch (TypeOfFunction)
                    {
                    case 1:
                    {
                        if (((BaktOrg[MassiveFight[i]].posX - 5) <= AntibOrg[i].posX) && ((BaktOrg[MassiveFight[i]].posX + 15) >= AntibOrg[i].posX))
                        {
                            if (((BaktOrg[MassiveFight[i]].posY - 5) <= AntibOrg[i].posY) && ((BaktOrg[MassiveFight[i]].posY + 15) >= AntibOrg[i].posY))
                            {
                                AntibOrg[i].HP--;
                                BaktOrg[MassiveFight[i]].HP = 0;
                                if (AntibOrg[i].HP == 0)
                                {
                                    AntibOrg[i].size_w = ui->antib_5->width();
                                    AntibOrg[i].size_h = ui->antib_5->height();
                                    AntibOrg[i].posX = 0;
                                    AntibOrg[i].posY = 0;
                                    ui->antib_5->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                                    ui->antib_5->setVisible(false);
                                    ui->antib_5->setEnabled(false);
                                }
                                else
                                    MassiveFight[i] = 0;
                            }
                        }

                        if (BaktOrg[MassiveFight[i]].posX > AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX + AntibOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posX < AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX - AntibOrg[i].stepX;
                        }

                        if (BaktOrg[MassiveFight[i]].posY > AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY + AntibOrg[i].stepY;
                        }

                        if (BaktOrg[MassiveFight[i]].posY < AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY - AntibOrg[i].stepY;
                        }

                        if ((BaktOrg[MassiveFight[i]].HP == 0) && (AntibOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 2:
                    {
                        if (((GribOrg[MassiveFight[i]].posX - 5) <= AntibOrg[i].posX) && ((GribOrg[MassiveFight[i]].posX + 15) >= AntibOrg[i].posX))
                        {
                            if (((GribOrg[MassiveFight[i]].posY - 5) <= AntibOrg[i].posY) && ((GribOrg[MassiveFight[i]].posY + 15) >= AntibOrg[i].posY))
                            {
                                AntibOrg[i].HP--;
                                GribOrg[MassiveFight[i]].HP = 0;
                                if (AntibOrg[i].HP == 0)
                                {
                                    AntibOrg[i].size_w = ui->antib_5->width();
                                    AntibOrg[i].size_h = ui->antib_5->height();
                                    AntibOrg[i].posX = 0;
                                    AntibOrg[i].posY = 0;
                                    ui->antib_5->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                                    ui->antib_5->setVisible(false);
                                    ui->antib_5->setEnabled(false);
                                }
                                else
                                    MassiveFight[i] = 0;
                            }
                        }

                        if (GribOrg[MassiveFight[i]].posX > AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX + AntibOrg[i].stepX;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posX < AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX - AntibOrg[i].stepX;
                        }

                        if (GribOrg[MassiveFight[i]].posY > AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY + AntibOrg[i].stepY;
                        }
                        else
                        if (GribOrg[MassiveFight[i]].posY < AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY - AntibOrg[i].stepY;
                        }

                        if ((GribOrg[MassiveFight[i]].HP == 0) && (AntibOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    case 3:
                    {
                        if (((VirusOrg[MassiveFight[i]].posX - 5) <= AntibOrg[i].posX) && ((VirusOrg[MassiveFight[i]].posX + 15) >= AntibOrg[i].posX))
                        {
                            if (((VirusOrg[MassiveFight[i]].posY - 5) <= AntibOrg[i].posY) && ((VirusOrg[MassiveFight[i]].posY + 15) >= AntibOrg[i].posY))
                            {
                                AntibOrg[i].HP--;
                                VirusOrg[MassiveFight[i]].HP = 0;
                                if (AntibOrg[i].HP == 0)
                                {
                                    AntibOrg[i].size_w = ui->antib_5->width();
                                    AntibOrg[i].size_h = ui->antib_5->height();
                                    AntibOrg[i].posX = 0;
                                    AntibOrg[i].posY = 0;
                                    ui->antib_5->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
                                    ui->antib_5->setVisible(false);
                                    ui->antib_5->setEnabled(false);
                                }
                                else
                                    MassiveFight[i] = 0;
                            }
                        }

                        if (VirusOrg[MassiveFight[i]].posX > AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX + AntibOrg[i].stepX;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posX < AntibOrg[i].posX)
                        {
                            AntibOrg[i].posX = AntibOrg[i].posX - AntibOrg[i].stepX;
                        }

                        if (VirusOrg[MassiveFight[i]].posY > AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY + AntibOrg[i].stepY;
                        }
                        else
                        if (VirusOrg[MassiveFight[i]].posY < AntibOrg[i].posY)
                        {
                            AntibOrg[i].posY = AntibOrg[i].posY - AntibOrg[i].stepY;
                        }
                        if ((VirusOrg[MassiveFight[i]].HP == 0)  && (AntibOrg[i].dead != true))
                        {
                            MassiveFight[i] = 0;
                        }
                        break;
                    }
                    }
                }
                ui->antib_5->setGeometry(AntibOrg[i].posX, AntibOrg[i].posY, AntibOrg[i].size_w, AntibOrg[i].size_h);
              break;
             }
             }
        }
        break;
    }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

