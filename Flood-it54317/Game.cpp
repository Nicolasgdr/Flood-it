#include "Game.h"
#include <algorithm>


Game::Game()
{

}

void Game::initializeGame(int i, int y, int x){
    board=Board(i,y,x);
    getGroupe().push_back(board.getSquare(Position(0,0)));
    this->nbColorGame = x;
    rowBoard = i;
    colBoard = y;
}

bool Game::checkEnd(){
    if(Groupe.size() == (rowBoard*colBoard)){
        return true;
    }
    return false;
}

void Game::checkNeighbor(){
    changeColorOfGroupe(colorAsk);
    for (size_t i = 0; i < board.getPlateau().size(); ++i) {
        for (size_t y = 0; y < board.getPlateau()[i].size(); ++y) {
            Color value = board.getSquare(Position(i,y)).getColor();
            auto p = Position(i,y);
            auto s = board.getSquare(p);
            if(!std::any_of(Groupe.begin(),Groupe.end(),s)){
                if(value == colorAsk){
                    auto placement = lookPlacement(Position(i,y));
                    if (placement) {
                        Groupe.push_back(board.getSquare(Position(i,y)));
                        if(board.isInside(Position(i-1,y)) && board.getSquare(Position(i-1,y)).getColor()==colorAsk){
                            Groupe.push_back(board.getSquare(Position(i-1,y)));
                        }if(board.isInside(Position(i+1,y)) && board.getSquare(Position(i+1,y)).getColor()==colorAsk){
                            Groupe.push_back(board.getSquare(Position(i+1,y)));
                        }if(board.isInside(Position(i,y+1)) && board.getSquare(Position(i,y+1)).getColor()==colorAsk){
                            Groupe.push_back(board.getSquare(Position(i,y+1)));
                        }if(board.isInside(Position(i,y-1)) && board.getSquare(Position(i,y-1)).getColor()==colorAsk){
                            Groupe.push_back(board.getSquare(Position(i,y-1)));
                        }
                    }
                }
            }
        }
    }
}

void Game::changeColorOfGroupe(Color color){
    for (size_t i = 0; i < getGroupe().size(); ++i) {
        Groupe.at(i).setColor(color);
        auto p = Groupe.at(i).getPosition();
        board.getSquare(p).setColor(color);
    }
    NumberOfPlay++;
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

