#ifndef POSITION_H
#define POSITION_H
#include <corecrt.h>
class Position
{
public:
    Position()=default;
    /**
     * @brief Position is compose of two value that represent the row and the column of my array
     * @param row
     * @param column
     */
    Position( size_t row,  size_t column){
        this->row = row;
        this->column=column;
    }
    /**
     * @brief getRow is the getter of my row
     * @return
     */
    size_t getRow(){
        return this->row;
    }
    /**
     * @brief getColumn is the getter of my column
     * @return
     */
    size_t getColumn(){
        return this->column;
    }
    /**
     * @brief operator ==
     * @param position
     * @return
     */
    bool operator == (Position &position){
        return this->row==position.row && this->column==position.column;
    }
private:
    size_t row;
    size_t column;
};

#endif // POSITION_H
