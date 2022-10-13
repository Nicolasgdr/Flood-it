#include "Game.h"
#include "qdebug.h"

Game::Game()
{

}

void Game::initializeGame(int i, int y, int x){
    board=Board(i,y,x);
    getGroupe().push_back(board.getSquare(Position(0,0)));
    this->nbColorGame = x;
}

bool Game::checkEnd(){
    if(Groupe.size() == (rowBoard*colBoard)){
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
            auto p = Position(i,y);
            auto s = board.getSquare(p);
            if(!std::any_of(Groupe.begin(),Groupe.end(),s)) // je vérifie si une case est déjà dans le groupe
                //si elle et dans le groupe alors je la prend pas en compte
            {
                if(value == colorAsk){
                    auto placement = lookPlacement(Position(i,y));
                    if (placement) {
                        check = true;
                        Groupe.push_back(board.getSquare(Position(i,y)));
                        if(board.isInside(Position(i-1,y)) && board.getSquare(Position(i-1,y)).getColor()==colorAsk){
                            Groupe.push_back(board.getSquare(Position(i-1,y)));
                        }else if(board.isInside(Position(i+1,y)) && board.getSquare(Position(i+1,y)).getColor()==colorAsk){
                            Groupe.push_back(board.getSquare(Position(i+1,y)));
                        }
                        else if(board.isInside(Position(i,y+1)) && board.getSquare(Position(i,y+1)).getColor()==colorAsk){
                            Groupe.push_back(board.getSquare(Position(i,y+1)));

                        }else if(board.isInside(Position(i,y-1)) && board.getSquare(Position(i,y-1)).getColor()==colorAsk){
                            Groupe.push_back(board.getSquare(Position(i,y-1)));
                        }
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
        std::for_each(Neighbors.begin(),Neighbors.end(),[this](Square s){
            auto p = s.getPosition();
            qDebug()<< " voisin Position r: "+QString::number(p.getRow())+" voisin Position c:"+QString::number(p.getColumn())+"\n";
            this->Groupe.push_back(s);
        });
    }
    std::for_each(Groupe.begin(),Groupe.end(),[](Square s){
        auto p = s.getPosition();
        qDebug()<< "Group Position r: "+QString::number(p.getRow())+" Group Position c: "+QString::number(p.getColumn());
    });

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

