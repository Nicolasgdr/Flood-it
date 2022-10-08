#include "Game.h"

Game::Game()
{

}

void Game::initializeGame(int i, int y){
    board=Board(i,y);
    getGroupe().push_back(board.getSquare(Position(0,0)));
}

bool Game::checkEnd(){
    if(Groupe.size() == (rowBoard*colBoard)-1){
        return true;
    }
    return false;
}

bool Game::checkNeighbor(){
    bool check = false;
    Neighbors.clear();
    changeColorOfGroupe(colorAsk);
    for (size_t i = 0; i < board.getPlateau().size(); ++i) {
        for (size_t y = 0; y < board.getPlateau()[i].size(); ++y) {
            Color value = board.getSquare(Position(i,y)).getColor();
            if(value == colorAsk){
                auto placement = lookPlacement(Position(i,y));
                if (placement) {
                    check = true;
                    Neighbors.push_back(board.getSquare(Position(i,y)));
                    if(board.isInside(Position(i-0,y-1)) && board.getSquare(Position(i-0,y-1)).getColor()==colorAsk){
                        Neighbors.push_back(board.getSquare(Position(i-0,y-1)));
                    }else if(board.isInside(Position(i+0,y+1)) && board.getSquare(Position(i+0,y+1)).getColor()==colorAsk){
                        Neighbors.push_back(board.getSquare(Position(i+0,y+1)));
                    }
                    else if(board.isInside(Position(i+1,y-0)) && board.getSquare(Position(i+1,y-0)).getColor()==colorAsk){
                        Neighbors.push_back(board.getSquare(Position(i+1,y-0)));

                    }else if(board.isInside(Position(i-1,y+0)) && board.getSquare(Position(i-1,y+0)).getColor()==colorAsk){
                        Neighbors.push_back(board.getSquare(Position(i-1,y+0)));
                    }
                }
            }
        }
    }
    return check;
}

void Game::changeColorOfGroupe(Color color){
    for (size_t i = 0; i < getGroupe().size(); ++i) {
        Groupe.at(i).setColor(color);
        auto p = Groupe.at(i).getPosition();
        board.getSquare(p).setColor(color);
    }
    NumberOfPlay++;
}

void Game::addNeighborToGroupe(){
    if(checkNeighbor()){
        bool present = false;
        for (size_t i = 0; i < Neighbors.size(); ++i) {
            Position valuepos = Neighbors.at(i).getPosition();

            for (size_t y = 0; y < Groupe.size(); ++y) {

                if(Groupe.at(y).getPosition() == valuepos){
                    present = true;
                }

            }
            if(present == false){
                Groupe.push_back(Neighbors[i]);
            }

        }

    }
}



bool Game::lookPlacement(Position position){
    for (size_t i = 0; i < Groupe.size(); ++i) {
        if(Position(position.getRow()+1,position.getColumn())==Groupe.at(i).getPosition()){
            return true;
        }else if (Position(position.getRow()-1,position.getColumn())==Groupe.at(i).getPosition()) {
            return true;
        }else if (Position(position.getRow(),position.getColumn()+1)==Groupe.at(i).getPosition()) {
            return true;
        }else if (Position(position.getRow(),position.getColumn()-1)==Groupe.at(i).getPosition()) {
            return true;
        }
    }
    return false;
}

