//
// Created by Johannes A. on 30.05.22.
//

#ifndef VIERGEWINNT_JOMANDRE_UNIQUEOBJECT_H
#define VIERGEWINNT_JOMANDRE_UNIQUEOBJECT_H
#pragma once
#include "memory"
class UniqueObject{
public:
    UniqueObject()= default;
    virtual bool equals(UniqueObject &o){
       void* a = this;
       void* b = &o;
       if(a==b){
           return true;
       }
       return false;
    }
};



#endif //VIERGEWINNT_JOMANDRE_UNIQUEOBJECT_H
