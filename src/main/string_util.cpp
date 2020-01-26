//
// Created by creative on 2020/1/24.
//

#include "string_util.h"

using namespace work;

string StringUtil::ltrim(string str) {
    string chars = "\t\n\v\f\r ";
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

string StringUtil::rtrim(string str) {
    string chars = "\t\n\v\f\r ";
    str.erase(str.find_last_not_of(chars) +1);
    return str;
}

string StringUtil::trim(string str) {
    return ltrim(rtrim(str));
}

#ifdef EVN_DEBUG
TEST(string_util, trim)
{
    string str1 = " 空格校验 ";
    string str2 = StringUtil::trim(str1);
    EXPECT_STREQ("空格校验", str2.c_str());
    EXPECT_STREQ("空格校验 ", str2.c_str());
}
#endif