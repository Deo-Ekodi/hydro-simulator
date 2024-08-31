#include "inputhandler.hpp"

int main()
{
    InputHandler input("data.tsv");
    input.get_input_data();
    input.log();
    return 0;
}