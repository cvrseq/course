//
// Created by Aleksandr Suslin on 10.05.2024.
//

#ifndef PRACTICE_STUDENT_H
#define PRACTICE_STUDENT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

class Student {
public:
    std::string fullName;
    std::string birthDate;
    int entryYear;
    std::string faculty;
    std::string department;
    std::string group;
    std::string recordBookNumber;
    char gender;
    std::vector<std::vector<std::pair<std::string, int>>> sessions;

    double averageForSession(int sessionIndex) const;

    friend std::istream& operator>>(std::istream& is, Student& s);
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
};






#endif //PRACTICE_STUDENT_H
