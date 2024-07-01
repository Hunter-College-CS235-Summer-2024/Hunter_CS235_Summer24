#ifndef Visitor_hpp
#define Visitor_hpp

#include <string>

template<class T>
class Visitor
{
    public:
        virtual void operator()(const T& x) = 0;
};

#endif
