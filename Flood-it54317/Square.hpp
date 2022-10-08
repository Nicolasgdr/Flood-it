#include<string>

#include"Color.h"
#include "Position.hpp"
class Square
{
public:
    Square()=default;
    /**
     * @brief Square is what are inside my array, its my constructor
     * @param color
     */
    Square(Position position,Color color){
        this->position=position;
        this->color=color;
    }
    /**
     * @brief Square constructor with only a color
     * @param color
     */
    Square(Color color){
        this->color=color;
    }
    /**
     * @brief getColor is the getter for the color of my square
     * @return
     */
    Color getColor(){
        return this->color;
    }
    /**
     * @brief setColor is the setter for the color of my square
     * @param color
     */
    void setColor(Color color){
        this->color = color;
    }
    Position &getPosition(){
        return this->position;
    }

private:
    Color color;
    Position position;
};

