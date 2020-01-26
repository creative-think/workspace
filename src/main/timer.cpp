//
// Created by creative on 2020/1/26.
//
#include "common.h"
#include "boost/progress.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"
using namespace boost;
using namespace boost::gregorian;

TEST(timer, elapsed) {
    vector<string> v(100, "a");
    v[1] = "";
    v[55] = "";

    progress_display pd(v.size());
    vector<string>::iterator pos;
    for (pos = v.begin(); pos != v.end(); pos++) {
        ++pd;
        if (pos->empty()) {
            cout << "string empty : " << pos - v.begin() << endl;
        }
    }
}

TEST(date, show) {
    date d1(2020, 01, 26), d2(2020, 01, 30);
    cout << "相隔天数：" << d2 - d1 << endl;
}