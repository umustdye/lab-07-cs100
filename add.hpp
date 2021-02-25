#ifndef ADD_HPP
#define ADD_HPP

#include "base.hpp"

class Add : public Base {
    public:
        Base *left;
        Base *right;

        Add(Base *l, Base *r) : Base(), left(l), right(r) {}
        ~Add() {
            delete left;
            delete right;
        }

        virtual double evaluate() {
            return left->evaluate() + right->evaluate();
        }
        virtual std::string stringify() {
            return "(" + left->stringify() + "+" + right->stringify() + ")";
        }
};


#endif
