#include "Controller.h"

Controller::Controller()
{
    this->game = Game();
    this->size= new Size(nullptr);
    this->play = new Play(nullptr);
}
void Controller::launch()
{
    QObject::connect(this->size->getbutton5x5(),SIGNAL(clicked()),this,SLOT(setBoardValue5()));
    QObject::connect(this->size->getbutton12x12(),SIGNAL(clicked()),this,SLOT(setBoardValue12()));
    QObject::connect(this->size->getbutton24x24(),SIGNAL(clicked()),this,SLOT(setBoardValue24()));
    QObject::connect(this->size->getbuttonperso(),SIGNAL(clicked()),this,SLOT(setBoardValueperso()));

    this->size->show();

}

void Controller::launchPlay(){
    QObject::connect(this->play-> getbuttonRed(),SIGNAL(clicked()),this,SLOT(actionbuttonRed()));
    QObject::connect(this->play-> getbuttonBlue(),SIGNAL(clicked()),this,SLOT(actionbuttonBlue()));
    QObject::connect(this->play-> getbuttonGreen(),SIGNAL(clicked()),this,SLOT(actionbuttonGreen()));
    QObject::connect(this->play-> getbuttonPink(),SIGNAL(clicked()),this,SLOT(actionbuttonPink()));
    QObject::connect(this->play-> getbuttonBlack(),SIGNAL(clicked()),this,SLOT(actionbuttonBlack()));
    QObject::connect(this->play-> getbuttonPurple(),SIGNAL(clicked()),this,SLOT(actionbuttonPurple()));
    play->createView(game);
    play->createButton(game);
    this->play->show();
    this->play->afficheMin(game);
}
void Controller::updateGame(){
    play->deleteElement();
    play->createView(game);
    if(game.checkEnd() && game.getNumberOfPlay()<=25){
        if(game.getNumberOfPlay()< play->getMin()){
            play->afficheMinBattu(game);
            play->hideButton();
        }else{
            play->afficheWin(game);
            play->hideButton();
        }
    }else if(game.checkEnd() && game.getNumberOfPlay()>25){
        play->afficheLoose(game);
        play->hideButton();
    }else {
        play->updateNbcoup(game);
    }

}
void Controller::startInitial(){
    game.initializeGame(this->rowBoard,this->colBoard,this->nbColor);
}
void Controller::setBoardValue5(){
    this->rowBoard=5;
    this->colBoard=5;
    this->nbColor=6;
    this->size->close_windows();
    startInitial();
    this->launchPlay();
}
void Controller::setBoardValue12(){
    this->rowBoard=12;
    this->colBoard=12;
    this->nbColor=6;
    this->size->close_windows();
    startInitial();
    this->launchPlay();
}
void Controller::setBoardValue24(){
    this->rowBoard=24;
    this->colBoard=24;
    this->nbColor=6;
    this->size->close_windows();
    startInitial();
    this->launchPlay();
}
void Controller::setBoardValueperso(){
    this->rowBoard=size->getrow()->value();
    this->colBoard=size->getCol()->value();
    this->nbColor=size->getColor()->value();
    this->size->close_windows();
    startInitial();
    this->launchPlay();
}

void Controller::actionbuttonRed(){
    this->game.setcolorAsk(RED);
    this->game.checkNeighbor();
    updateGame();

}
void Controller::actionbuttonBlue(){
    this->game.setcolorAsk(BLUE);
    this->game.checkNeighbor();
    updateGame();

}
void Controller::actionbuttonBlack(){
    this->game.setcolorAsk(BLACK);
    this->game.checkNeighbor();
    updateGame();
}
void Controller::actionbuttonPink(){
    this->game.setcolorAsk(PINK);
    this->game.checkNeighbor();
    updateGame();
}
void Controller::actionbuttonGreen(){
    this->game.setcolorAsk(GREEN);
    this->game.checkNeighbor();
    updateGame();
}
void Controller::actionbuttonPurple(){
    this->game.setcolorAsk(PURPLE);
    this->game.checkNeighbor();
    updateGame();
}

