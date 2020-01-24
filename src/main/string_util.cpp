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