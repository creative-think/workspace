#include "common.h"
#include "string_util.h"
#include <boost/version.hpp>
using namespace work;

#ifndef EVN_DEBUG
int main(int argc, char** argv) {
    string str = "  OK !    ";
    cout << StringUtil::trim(str) << endl;

    return 0;
}

#else
GTEST_API_ int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);

    cout << "BOOST 版本: " << BOOST_VERSION << endl;

    return RUN_ALL_TESTS();
}
#endif