#include "Play.h"
#include "ui_Play.h"

Play::Play(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Play)
{
    ui->setupUi(this);
    buttonRed = new QPushButton(this);
    buttonRed->setText("Red");
    buttonRed->setObjectName(QString::fromUtf8("buttonRed"));
    buttonRed->setStyleSheet("background : red");
    buttonRed->setGeometry(QRect(10, 230, 83, 29));
    buttonBlue = new QPushButton(this);
    buttonBlue->setText("Blue");
    buttonBlue->setObjectName(QString::fromUtf8("buttonBlue"));
    buttonBlue->setStyleSheet("background : blue");
    buttonBlue->setGeometry(QRect(10, 270, 83, 29));
    buttonGreen = new QPushButton(this);
    buttonGreen->setText("Green");
    buttonGreen->setObjectName(QString::fromUtf8("buttonGreen"));
    buttonGreen->setStyleSheet("background : green");
    buttonGreen->setGeometry(QRect(10, 310, 83, 29));
    buttonPurple = new QPushButton(this);
    buttonPurple->setText("Purple");
    buttonPurple->setObjectName(QString::fromUtf8("buttonPurple"));
    buttonPurple->setStyleSheet("background : purple");
    buttonPurple->setGeometry(QRect(10, 350, 83, 29));
    buttonBlack = new QPushButton(this);
    buttonBlack->setText("Black");
    buttonBlack->setObjectName(QString::fromUtf8("pushBlack"));
    buttonBlack->setStyleSheet("background : black");
    buttonBlack->setGeometry(QRect(10, 390, 83, 29));
    buttonPink = new QPushButton(this);
    buttonPink->setText("Pink");
    buttonPink->setObjectName(QString::fromUtf8("pushPink"));
    buttonPink->setStyleSheet("background : pink");
    buttonPink->setGeometry(QRect(10, 430, 83, 29));

}

Play::~Play()
{
    delete ui;
}
void Play::createView(Game game){
    for (size_t i = 0; i < game.getBoard().getRow() ; ++i) {
        for (size_t y = 0; y < game.getBoard().getColumn(); ++y) {
            auto squareView = new QLabel();
            switch (game.getBoard().getSquare(Position(i,y)).getColor()) {
            case Color::RED:
                squareView->setStyleSheet("background : red");
                break;
            case Color::BLUE:
                squareView->setStyleSheet("background : blue");
                break;
            case Color::BLACK:
                squareView->setStyleSheet("background : black");
                break;
            case Color::GREEN:
                squareView->setStyleSheet("background : green");
                break;
            case Color::PURPLE:
                squareView->setStyleSheet("background : purple");
                break;
            case Color::PINK:
                squareView->setStyleSheet("background : pink");
                break;
            }
            this->ui->gridLayout->addWidget(squareView,i,y);
        }
    }
}
void Play::afficheWin(Game game){
    this->ui->nbcoup->setText("The game is win with " + QString::number(game.getNumberOfPlay()) + " click");
}
void Play::afficheLoose(Game game){
    this->ui->nbcoup->setText("The game is loose with " + QString::number(game.getNumberOfPlay()) + " click");

}
void Play::updateNbcoup(Game game){
    this->ui->nbcoup->setText( QString::number(game.getNumberOfPlay())+"/25");
}
void Play::deleteElement(){
    for(auto child:this->ui->gridLayout->children()){
        delete child;
    }
}
void Play::afficheMin(Game game){
    int min;
    min =25*( game.getBoard().getRow()+game.getBoard().getRow()* game.getNbColorGame()/ ((14 + 14) * 6));
    this->ui->nbMinPlay->setText(QString::number(min));
}
