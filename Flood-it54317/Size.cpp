#include "Size.h"
#include "ui_Size.h"


Size::Size(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Size)
{
    ui->setupUi(this);
    button5x5 = new QPushButton(this);
    button5x5->setText("5x5");
    button5x5->setObjectName(QString::fromUtf8("button5x5"));
    button5x5->setGeometry(QRect(190, 270, 141, 51));
    button24x24 = new QPushButton(this);
    button24x24->setText("24x24");
    button24x24->setObjectName(QString::fromUtf8("button24x24"));
    button24x24->setGeometry(QRect(630, 270, 141, 51));
    button12x12 = new QPushButton(this);
    button12x12->setText("12x12");
    button12x12->setObjectName(QString::fromUtf8("button12x12"));
    button12x12->setGeometry(QRect(420, 270, 141, 51));
    buttonperso = new QPushButton(this);
    buttonperso->setText("lancement perso");
    buttonperso->setGeometry(810,510,121,29);
    row = new QSpinBox(this);
    row->setMaximum(30);
    row->setMinimum(2);
    row->setGeometry(QRect(490,510,48,29));
    col = new QSpinBox(this);
    col->setMaximum(30);
    col->setMinimum(2);
    col->setGeometry(QRect(660,510,48,29));


}

Size::~Size()
{
    delete ui;
}

void Size::close_windows(){ // fermer la page la après ouverture
    this->close();
}
