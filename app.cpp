#include "app.hpp"

int main(int argc,char* filename[])
{
    loadData(filename[1]);
    menu();
    return argc;
}