#ifndef BASE_FACTORY_HPP
#define BASE_FACTORY_HPP

#include <cstring>
#include <cctype>
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
using std::isdigit;

class BaseFactory {
private:
    Base *lNum;
    Base *rNum;
    Base *oper;
    bool isNum(char *str) {
        char *pos;
        strtod(str, &pos);
        return strlen(str) == (pos - str);
    }

public:
    BaseFactory() : lNum(nullptr), rNum(nullptr), oper(nullptr) {}
    Base* parse(char **argv, int argc) {
        //Check for correct length of string including exe name, odd means operator has no right value. ex.) 3 + 4 / 
        if(argc & 1) return nullptr;

        //Check for correctness of string
        for(int i = 1; i < argc; ++i) {
            if(i & 1) {//Odd must be number
                if(!isNum(argv[i])) return nullptr;
            } else {//Even must be operation
                char operations[][3] = {"+", "-", "*", "/", "**"};
                bool isOp = false;
                for(int j = 0; j < 5; ++j) {//Check if matches one of possible operations
                    if(strcmp(argv[i], operations[j]) == 0) isOp = true;
                }
                if(!isOp) return nullptr;
            }
        }

        //Create Base object
        char *x;
        lNum = new Op(strtod(argv[1], &x));//Create first left number
        for(int i = 2; i < argc; i += 2) {
            //Create right num
            rNum = new Op(strtod(argv[i + 1], &x));

            //Combine two numbers
            if(strcmp(argv[i], "+") == 0) {
                oper = new Add(lNum, rNum);
            }  
            else if(strcmp(argv[i], "-")== 0) {
                oper = new Sub(lNum, rNum);
            }
            else if(strcmp(argv[i], "*")== 0) {
                oper = new Mult(lNum, rNum);
            }
            else if(strcmp(argv[i], "/")== 0) {
                oper = new Div(lNum, rNum);
            }
            else if(strcmp(argv[i], "**")== 0) {
                oper = new Pow(lNum, rNum);
            }

            //Assign to left
            lNum = oper;
        }

        //Return created base
        return lNum;
    }
};



#endif
