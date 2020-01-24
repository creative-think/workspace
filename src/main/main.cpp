#include "common.h"
#include "string_util.h"

using namespace work;

int main(int argc, char** argv) {
    string str = "  OK !    ";
    cout << StringUtil::trim(str) << endl;

    return 0;
}
