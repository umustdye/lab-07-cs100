#include <iostream>
#include "base_factory.hpp"
#include "base.hpp"

using std::cout;
using std::endl;

int main(int argc, char **argv) {
    if(argc < 2) {
        cout<<"No expression passed\n";
    } else {
        BaseFactory factory;
        Base *base = factory.parse(argv, argc);
        if(base) {
            cout<<base->stringify()<<" = "<<base->evaluate()<<endl;
        } else {
            cout<<"Bad Expression\n";
        }
        delete base;
    }

    return 0;
}
