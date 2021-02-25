#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

using namespace std;

class Sub: public Base
{
        public:
		Base* left;
		Base* right;
                Sub(Base* left, Base* right)
		: Base()
                {
			this->left = left;
			this->right = right;
                }

		~Sub()
		{
			delete left;
			delete right;			
		}


                virtual double evaluate()
                {
                        return left->evaluate() - right->evaluate();
                }

                virtual string stringify()
                {
                        return "(" + left->stringify() + "-" + right->stringify() + ")";
                }
};

#endif //__SUBOPMOCK_HPP__

