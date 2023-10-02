#include "calculate.h"
#include "median.h"
#include "student.h"

#include <vector>

using std::vector;

double grade(double midterm, double finalExam, vector<double> hw) {
    return 0.4 * (median(hw) + finalExam) + 0.2 * midterm;
}

double grade(const Student_info& s) {
    return grade(s.midterm, s.finalExam, s.homework);
}