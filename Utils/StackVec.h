//
// Created by Johannes A. on 30.05.22.
//

#ifndef VIERGEWINNT_JOMANDRE_STACKVEC_H
#define VIERGEWINNT_JOMANDRE_STACKVEC_H
#pragma once
#include "Option.h"
#include "string"
template <class T,unsigned int SIZE> class StackVec {
private:
    unsigned int len = 0;
    T buffer[SIZE] = {};
public:
    //returns index of element if pushed, else return -1
    unsigned int push(T t){
        if(this->getRemainingSpace() > 0){
            this->buffer[this->len] = t;
            this->len+=1;
            return this->len - 1;
        }else{
            return -1;
        }
        std::array<int,1>().begin();
    }

    T* begin() _NOEXCEPT {return buffer;}
    T* end() _NOEXCEPT {return buffer + len;}

    unsigned int indexOf(T t){
        for(int i = 0;i < this->len;i++){
            if(buffer[i] == t){
                return i;
            }
        }
        return -1;
    }

    bool set(unsigned int index, T t){
        if(index >= this->len){
            return false;
        }else{
            this->buffer[index] = t;
            return true;
        }
    }

    Option<T> getAt(unsigned int index){
        if(index < this->len){
            return Option<T>(this->buffer[index]);
        }
        return Option<T>();
    }

    bool swapRemoveAt(unsigned int index){
        if(index < this->len){
            this->buffer[index] = this->buffer[this->len-1];
            this->len--;
            return true;
        }else{
            return false;
        }
    }

    std::string toString(){
        std::string builder = "[";
        for(int i = 0;i < this->len;i++){
            builder+= std::to_string(this->buffer[i]) += ", ";
        }
        builder +="]";
        return builder;
    }

    unsigned int getCapacity(){
        return SIZE;
    }

    unsigned int length(){
        return len;
    }

    unsigned int getRemainingSpace(){
        return SIZE - len;
    }
};

#endif //VIERGEWINNT_JOMANDRE_STACKVEC_H