#include "median.h"

#include <vector>
#include <stdexcept>
#include <algorithm>

using std::vector;
using std::domain_error;
using std::sort;

double median(vector<double> hw) {
    typedef vector<double>::size_type vec_sz;

    vec_sz size = hw.size();
    if(size == 0)
        throw domain_error("Median of an empty vector");

    sort(hw.begin(), hw.end());

    vec_sz mid = size / 2;
    return size % 2 == 0 ? (hw[mid] + hw[mid - 1]) / 2 : hw[mid];
}