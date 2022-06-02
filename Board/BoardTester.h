//
// Created by Johannes A. on 02.06.22.
//

#ifndef VIERGEWINNT_JOMANDRE_BOARDTESTER_H
#define VIERGEWINNT_JOMANDRE_BOARDTESTER_H

#pragma once
#include "Board.h"
class TestBoard: public Board{
    //DIAGONAL_BOARDSECTION

    void testTopToBottom(){
        Color c1[2] = {Color::YELLOW,Color::RED};
        this->reset();
        for(auto c : c1){
            this->m_fields[3][2] = c;
            this->m_fields[3][3] = c;
            this->m_fields[3][4] = c;
            this->m_fields[3][5] = c;
            assert(this->checkWin());
        }
        std::cout << "passed TestTopToBottom" << std::endl;
    }

    void testTopLeftBottomRight_bottomleft(){
        Color c1[2] = {Color::YELLOW,Color::RED};
        this->reset();
        for(auto c : c1){
            this->m_fields[3][0] = c;
            this->m_fields[4][1] = c;
            this->m_fields[5][2] = c;
            this->m_fields[6][3] = c;
            assert(this->checkWin());
        }
        std::cout << "passed testTopLeftBottomRight_bottomleft" << std::endl;
    }

    void testTopLeftBottomRight_topRight(){
        Color c1[2] = {Color::YELLOW,Color::RED};
        this->reset();
        for(auto c : c1){
            this->m_fields[3][2] = c;
            this->m_fields[4][3] = c;
            this->m_fields[5][4] = c;
            this->m_fields[6][5] = c;
            assert(this->checkWin());
        }
        std::cout << "passed testTopLeftBottomRight_topRight" << std::endl;
    }


    void testLeftToRight(){
        Color c1[2] = {Color::YELLOW,Color::RED};
        this->reset();
        for(auto c : c1){
            this->m_fields[2][3] = c;
            this->m_fields[3][3] = c;
            this->m_fields[4][3] = c;
            this->m_fields[5][3] = c;
            assert(this->checkWin());
        }
        std::cout << "passed TestTopToBottom" << std::endl;
    }



public:
    void startTests(){
        std::cout << this->toString() << std::endl;
        this->testTopToBottom();
        this->testTopLeftBottomRight_bottomleft();
        this->testTopLeftBottomRight_topRight();

        this->testLeftToRight();
    }
};

#endif //VIERGEWINNT_JOMANDRE_BOARDTESTER_H
