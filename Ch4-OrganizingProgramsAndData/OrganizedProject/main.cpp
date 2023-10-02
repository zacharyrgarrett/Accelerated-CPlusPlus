#include "student.h"
#include "calculate.h"

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

using std::vector;
using std::string;
using std::cin; using std::cout; using std::endl;
using std::sort; using std::max;
using std::streamsize; using std::setprecision;
using std::domain_error;

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