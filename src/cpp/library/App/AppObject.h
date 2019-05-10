// library/App/AppObject.h
#ifndef _APPOBJECT_H
#define _APPOBJECT_H

/*
 * App Object Virtual Class
*/

class AppObject {
public:
/** Constructors. **/
    AppObject() {}

/** Print functions. **/
    virtual void printAppObject()=0;
};

#endif // _APPOBJECT_H
