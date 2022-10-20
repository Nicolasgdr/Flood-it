#ifndef BOARD_H
#define BOARD_H
#include"Square.hpp"
#include <vector>
#include "Position.hpp"
#include <random.hpp>

class Board
{
public:
    Board()=default;
    /**
     * @brief Board where my game will take place, size depend on what the player choose
     */
    Board(int x, int y,int nbcolor){
        plateau = std::vector<std::vector<Square>>(x, std::vector<Square>(y));
        he2b::nvs::randomize();
        for (size_t i = 0; i < getRow(); ++i) {
            for (size_t y = 0; y < getColumn(); ++y) {
                Color color = randomColor(nbcolor);
                plateau.at(i).at(y)=Square(Position(i,y),color);
            }
        }
    }
    /**
     * @brief getPlateau is the getter for my game place
     * @return vector plateau
     */
    std::vector<std::vector<Square>> &getPlateau(){
        return plateau;
    }

    /**
     * @brief getSquare return a square of the plateau
     * @param position
     * @return square
     */
    Square & getSquare(Position position){
        return plateau.at(position.getRow()).at(position.getColumn());
    }
    /**
     * @brief getRow getter for the row of my plateau
     * @return size_t row
     */
    size_t getRow(){
        return this->plateau.size();;
    }
    /**
     * @brief getColumn  getter for the column of my plateau
     * @return size_t col
     */
    size_t getColumn(){
        return this->plateau.at(0).size();
    }
    /**
     * @brief randomColor will return a color randomly
     * @return a Color of the square
     */
    Color randomColor(int i){
        int index;
        index = he2b::nvs::random_value(0,i-1);
        return static_cast<Color>(index);

    }
    /**
     * @brief isInside check the position
     * @param position
     * @return boolean
     */
    bool isInside(Position position){
        if(position.getRow() >= 0 && position.getColumn()>=0){
            if(plateau.size()>position.getRow() && plateau[0].size()>position.getColumn())
                return true;
        }
        return false;
    }
private :
    std::vector<std::vector<Square>> plateau;


};


#endif // BOARD_H
