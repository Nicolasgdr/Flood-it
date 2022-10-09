#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Game.h"
#include "QObject"
#include "Size.h"
#include "Play.h"


class Controller: public QObject
{
    Q_OBJECT
    Game game;
    Size *size;
    Play *play;

public:
    /**
     * @brief Controller constructor
     */
    Controller();
    /**
     * @brief launch class that launch the first view
     */
    void launch();
    /**
     * @brief updateGame update the game each time when you clicked the button
     */
    void updateGame();
    /**
     * @brief launchPlay
     */
    void launchPlay();
    /**
     * @brief setvalueBoard setter for valueBoard
     * @param valueBoard
     */
    void setvalueBoard(int i, int y){
        this->rowBoard = i;
        this->colBoard =y;
    }
    /**
     * @brief startInitial launch the initialization of the game
     */
    void startInitial();


public slots:
    void setBoardValue5();
    void setBoardValue12();
    void setBoardValue24();
    void actionbuttonRed();
    void actionbuttonBlue();
    void actionbuttonBlack();
    void actionbuttonPink();
    void actionbuttonGreen();
    void actionbuttonPurple();
    void setBoardValueperso();



private :
    int rowBoard;
    int colBoard;
    int nbColor;
};


#endif // CONTROLLER_H
