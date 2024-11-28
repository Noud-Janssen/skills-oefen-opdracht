
#include <iostream>
#include "app.hpp"
#include "console.hpp"


int main(int argc, char const *argv[])
{
    app app;
    return !(app.init(argc,argv) && app.run());
}
