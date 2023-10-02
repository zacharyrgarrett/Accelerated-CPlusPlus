#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

using std::string;
using std::vector;
using std::istream;
using std::domain_error;
using std::streamsize; using std::setprecision;
using std::cin; using std::cout;
using std::sort;
using std::max;
using std::endl;

struct Student_info {
    string studentName;
    double midterm, finalExam;
    vector<double> homework;
};

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

double median(vector<double> hw) {
    typedef vector<double>::size_type vec_sz;

    vec_sz size = hw.size();
    if(size == 0)
        throw domain_error("Median of an empty vector");

    sort(hw.begin(), hw.end());

    vec_sz mid = size / 2;
    return size % 2 == 0 ? (hw[mid] + hw[mid - 1]) / 2 : hw[mid];
}

double grade(double midterm, double finalExam, vector<double> hw) {
    return 0.4 * (median(hw) + finalExam) + 0.2 * midterm;
}

double grade(const Student_info& s) {
    return grade(s.midterm, s.finalExam, s.homework);
}

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    // Read and store all the records, and find the length of the longest name
    while(read(cin, record)) {
        maxlen = max(maxlen, record.studentName.length());
        students.push_back(record);
    }

    // Alphabetize
    sort(students.begin(), students.end(), compare);

    for(vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        // Write the name, padded on the right to maxlen + 1 characters
        cout << students[i].studentName << string(maxlen + 1 - students[i].studentName.size(), ' ');

        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch(domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    return 0;
}