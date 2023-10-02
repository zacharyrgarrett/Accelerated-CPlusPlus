#include "student.h"

#include <iostream>
#include <vector>

using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y) {
    return x.studentName < y.studentName;
}

istream& read_hw(istream& is, vector<double>& hw) {
    if(is) {
        // Get rid of previous contents
        hw.clear();

        // Read homework grades
        double x;
        while(is >> x)
            hw.push_back(x);

        // Clear the stream so that input will work for the next student
        is.clear();
    }
    return is;
}

istream& read(istream& is, Student_info& s) {
    is >> s.studentName >> s.midterm >> s.finalExam;

    read_hw(is, s.homework);
    return is;
}