#ifndef GUARD_student_h
#define GUARD_student_h

#include <vector>
#include <string>
#include <istream>

struct Student_info {
    std::string studentName;
    double midterm, finalExam;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
std::istream& read(std::istream&, Student_info&);

#endif