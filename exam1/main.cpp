#include <iostream>
#include "puzzle1.h"
#include "puzzle2.h"
#include "ultimate.h"
#include "bonus_puzzle.h"

using std::cout;
using std::endl;

// try to figure out the output from running the following
// code. Note that there are some errors in the code, so,
// though output will be produced, it may not be what you
// would expect
int main() {
    cout << "puzzle 1:" << endl;
    puzzle1();

    cout << "\npuzzle 2:" << endl;
    puzzle2();

    cout << "\nultimate example:" << endl;
    ultimate();

    // cout << "bonus puzzle:" << endl;
    // bonus_puzzle();
    return 0;
}
