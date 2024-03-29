#ifndef SIZE_H
#define SIZE_H
#include "qpushbutton.h"
#include "qspinbox.h"
#include <QWidget>


namespace Ui {
class Size;
}

class Size : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Size page
     * @param parent
     */
    explicit Size(QWidget *parent = nullptr);
    ~Size();
    /**
     * @brief close_windows
     */
    void close_windows();
    /**
     * @brief getbutton5x5 getter
     * @return QpushButton
     */
    QPushButton* getbutton5x5(){
        return  button5x5;
    }
    /**
     * @brief getbutton12x12 getter
     * @return QpushButton
     */
    QPushButton* getbutton12x12(){
        return button12x12;
    }
    /**
     * @brief getbutton24x24 getter
     * @return QpushButton
     */
    QPushButton* getbutton24x24(){
        return button24x24;
    }
    /**
     * @brief getbuttonperso getter
     * @return QpushButton
     */
    QPushButton* getbuttonperso(){
        return buttonperso;
    }
    /**
     * @brief getrow getter
     * @return QSpinBox
     */
    QSpinBox* getrow(){
        return row;
    }
    /**
     * @brief getCol getter
     * @return QSpinBox
     */
    QSpinBox *getCol(){
        return col;
    }
    /**
     * @brief getColor getter
     * @return QSpinBox
     */
    QSpinBox *getColor(){
        return color;
    }
private:
    Ui::Size *ui;
    QPushButton *button5x5;
    QPushButton *button12x12;
    QPushButton *button24x24;
    QPushButton *buttonperso;
    QSpinBox * row;
    QSpinBox *col;
    QSpinBox *color;
};

#endif // SIZE_H
