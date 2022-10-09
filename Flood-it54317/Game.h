#ifndef GAME_H
#define GAME_H
#include "Board.hpp"
#include "Color.h"
#include <vector>
class Game
{
public:
    /**
     * @brief Constructor of Game
     */
    Game();
    /**
     * @brief initializeGame is a class that intitalize all the things need to play the game
     */
    void initializeGame(int i, int y,int x);
    /**
     * @brief checkWin will check after each round if all the square have the same color or not
     * @return
     */
    bool checkEnd();
    /**
     * @brief checkNeighbor will check if the squares next of the group are the same color or not
     */
    bool checkNeighbor();
    /**
     * @brief changeColorOfNeighbor will change the color for all the neighbor ( color chose buy the player)
     */
    void changeColorOfGroupe(Color color);
    /**
     * @brief addSquareToGroupe will just add a square to the group of square that will change color( new neighbor)
     */
    void addNeighborToGroupe();
    /**
     * @brief getGroupe getter for the group
     * @return
     */
    std::vector<Square>  &getGroupe() {
        return Groupe;
    }
    /**
     * @brief lookPlacement check if the next square are on the right position
     * @param position
     * @return
     */
    bool lookPlacement(Position position);
    /**
     * @brief setcolorAsk setter of colorAsk
     * @param color
     */
    void setcolorAsk(Color color){
        this->colorAsk = color;
    }
    /**
     * @brief getNumberOfPlay getter of my number of round
     * @return
     */
    int getNumberOfPlay(){
        return NumberOfPlay;
    }
    /**
     * @brief getBoard getter
     * @return
     */
    Board getBoard(){
        return board;
    }
    /**
     * @brief setnbcolorAsk setter
     * @param color
     */
    void setnbcolorAsk(int color){
        this->nbColorGame = color;
    }
    /**
     * @brief getNbColorGame getter
     * @return
     */
    int getNbColorGame(){
        return nbColorGame;
    }

private :
    size_t rowBoard;
    size_t colBoard;
    Color colorAsk;
    Board board;
    int NumberOfPlay =0;
    std::vector<Square> Groupe;
    std::vector<Square> Neighbors;
    int nbColorGame;

};



#endif // GAME_H
