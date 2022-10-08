#ifndef PLAY_H
#define PLAY_H

#include "Game.h"
#include "qlabel.h"
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
     * @return
     */
    QPushButton * getbuttonRed(){
        return buttonRed;
    }
    /**
     * @brief getbuttonBlue getter
     * @return
     */
    QPushButton * getbuttonBlue(){
        return buttonBlue;
    }
    /**
     * @brief getbuttonBlack getter
     * @return
     */
    QPushButton * getbuttonBlack(){
        return buttonBlack;
    }
    /**
     * @brief getbuttonPink getter
     * @return
     */
    QPushButton * getbuttonPink(){
        return buttonPink;

    }
    /**
     * @brief getbuttonGreen getter
     * @return
     */
    QPushButton * getbuttonGreen(){
        return buttonGreen;
    }
    /**
     * @brief getbuttonPurple getter
     * @return
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

private:
    Ui::Play *ui;
    QPushButton *buttonRed;
    QPushButton *buttonBlue;
    QPushButton *buttonBlack;
    QPushButton *buttonPink;
    QPushButton *buttonGreen;
    QPushButton *buttonPurple;


};

#endif // PLAY_H
