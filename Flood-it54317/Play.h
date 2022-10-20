#ifndef PLAY_H
#define PLAY_H
#include "Game.h"
#include "qpushbutton.h"
#include <QWidget>

namespace Ui {
class Play;
}

class Play : public QWidget
{
    Q_OBJECT

public:
    explicit Play(QWidget *parent = nullptr);
    ~Play();
    /**
     * @brief onbuttonRed define the action of the button red
     */
    void onbuttonRed();
    /**
     * @brief onbuttonPink define the action of the button pink
     */
    void onbuttonPink();
    /**
     * @brief onbuttonBlue define the action of the button blue
     */
    void onbuttonBlue();
    /**
     * @brief onbuttonGreen define the action of the button green
     */
    void onbuttonGreen();
    /**
     * @brief onbuttonPurple define the action of the button purple
     */
    void onbuttonPurple();
    /**
     * @brief onbuttonBlack define the action of the button black
     */
    void onbuttonBlack();
    /**
     * @brief getbuttonRed getter
     * @return QPushButton
     */
    QPushButton * getbuttonRed(){
        return buttonRed;
    }
    /**
     * @brief getbuttonBlue getter
     * @return QPushButton
     */
    QPushButton * getbuttonBlue(){
        return buttonBlue;
    }
    /**
     * @brief getbuttonBlack getter
     * @return QPushButton
     */
    QPushButton * getbuttonBlack(){
        return buttonBlack;
    }
    /**
     * @brief getbuttonPink getter
     * @return QPushButton
     */
    QPushButton * getbuttonPink(){
        return buttonPink;

    }
    /**
     * @brief getbuttonGreen getter
     * @return QPushButton
     */
    QPushButton * getbuttonGreen(){
        return buttonGreen;
    }
    /**
     * @brief getbuttonPurple getter
     * @return QPushButton
     */
    QPushButton *getbuttonPurple(){
        return buttonPurple;
    }
    /**
     * @brief createView create the view with the color of the square
     * @param game
     */
    void createView(Game game);
    /**
     * @brief afficheWin change the text
     * @param game
     */
    void afficheWin(Game game);
    /**
     * @brief afficheLoose change text
     * @param game
     */
    void afficheLoose(Game game);
    /**
     * @brief updateNbcoup refresh the text for the nb of play
     * @param game
     */
    void updateNbcoup(Game game);
    /**
     * @brief deleteElement delete each view
     */
    void deleteElement();
    /**
     * @brief afficheMin
     */
    void afficheMin(Game game);
    /**
     * @brief afficheMinBattu check if the min is < of nbcoup
     * @param game
     */
    void afficheMinBattu(Game game);
    /**
     * @brief getMin getter
     * @return int
     */
    int getMin(){
        return min;
    }
    /**
     * @brief createButton show the button
     * @param game
     */
    void createButton(Game game);
    /**
     * @brief blockButton
     */
    void hideButton();
private:
    Ui::Play *ui;
    QPushButton *buttonRed;
    QPushButton *buttonBlue;
    QPushButton *buttonBlack;
    QPushButton *buttonPink;
    QPushButton *buttonGreen;
    QPushButton *buttonPurple;
    int min;


};

#endif // PLAY_H
