//
// Created by Aleksandr Suslin on 10.05.2024.
//

#ifndef PRACTICE_STUDENTMANAGE_H
#define PRACTICE_STUDENTMANAGE_H

#include "student.h"

class StudentManager {
private:
    std::vector<Student> students;

public:
    void loadStudents(const std::string &filename);

    void sortStudentsBySession(int sessionIndex);

    void printAndSaveStudents(const std::string &filename, int sessionIndex);

    static void encrypt (const std::string filenameIn, const std::string filenameOut);

    static void decrypt (const std::string filenameIn, const std::string filenameOut);
};
#endif //PRACTICE_STUDENTMANAGE_H
