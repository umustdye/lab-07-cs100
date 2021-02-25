#ifndef POW_HPP
#define POW_HPP

#include "base.hpp"
#include <cmath>

class Pow : public Base {
    public:
        Base *left;
        Base *right;

        Pow(Base *l, Base *r) : Base(), left(l), right(r) {}
        ~Pow() {
            delete left;
            delete right;
        }

        virtual double evaluate() {
            return std::pow(left->evaluate(), right->evaluate());
        }
        virtual std::string stringify() {
            return "(" + left->stringify() + "**" + right->stringify() + ")";
        }
};

#endif
