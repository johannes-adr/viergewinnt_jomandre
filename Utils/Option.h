//
// Created by Johannes A. on 30.05.22.
//

#ifndef VIERGEWINNT_JOMANDRE_OPTION_H
#define VIERGEWINNT_JOMANDRE_OPTION_H
#pragma once
#include <stdexcept>

template<class T>class Option{
    bool none = true;
    T t;

public:
    explicit Option(T t){
        this->none = false;
        this->t = t;
    }

    Option(){
        this->none = true;
        this->t = 0;
    }

    bool isNone(){
        return this->none;
    }

    bool isSome(){
        return !this->none;
    }

    T unwrap(){
        if(this->isNone()){
            throw std::runtime_error("Option is null");
        }
        return this->t;
    }
};

#endif //VIERGEWINNT_JOMANDRE_OPTION_H
