#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

using namespace std;

class Div: public Base
{
        public:
		Base* left;
		Base* right;
                Div(Base* left, Base* right)
		: Base()
                {
			this->left = left;
			this->right = right;
                }

		~Div()
		{
			delete left;
			delete right;			
		}


                virtual double evaluate()
                {
			if(right->evaluate() == 0.0)
			{
				return 0;
			}

			else
			{
                        	return left->evaluate() / right->evaluate();
			}
                }

                virtual string stringify()
                {
			if(right->evaluate() == 0.0)
			{
				return "Invalid Operation";
			}
		
			else
			{
                        	return "(" + left->stringify() + "/" + right->stringify() + ")";
			}
                }
};

#endif //__DIVOPMOCK_HPP__
