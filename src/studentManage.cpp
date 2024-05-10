//
// Created by Aleksandr Suslin on 10.05.2024.
//

#include "studentManage.h"


void StudentManager::loadStudents(const std::string& filename) {
    std::ifstream inFile(filename);
    Student student;
    while (inFile >> student) {
        students.push_back(student);
    }
    inFile.close();
}

void StudentManager::sortStudentsBySession(int sessionIndex) {
    std::sort(students.begin(), students.end(), [&](const Student& a, const Student& b) {
        return a.averageForSession(sessionIndex) > b.averageForSession(sessionIndex);
    });
}

void StudentManager::printAndSaveStudents(const std::string& filename, int sessionIndex) {
    std::ofstream outFile(filename);
    for (const Student& s : students) {
        std::cout << s << "Average for session " << sessionIndex + 1 << ": " << s.averageForSession(sessionIndex) << "\n\n";
        outFile << s << "Average for session " << sessionIndex + 1 << ": " << s.averageForSession(sessionIndex) << "\n\n";
    }
    outFile.close();
}

void StudentManager::encrypt (const std::string filenameIn, const std::string filenameOut) {
    std::string key;
    char alphabet[63] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz1234567890";
    srand(time(NULL));
    for (int i = 0; i < 16; ++i) {
        key += alphabet[rand() % 62];
    }
    std::ofstream file("key.txt", std::ios::trunc);
    file << key;
    file.close();
    std::string commandAES = "openssl aes-128-cbc -salt -in " + filenameIn + " -out " + filenameOut + " -pass pass:" + key;
    std::system(commandAES.c_str());
    if (std::remove(filenameIn.c_str()) != 0) {
        std::cerr << "CANNOT DELETE >>> " + filenameIn << std::endl;
    }
    std::string commandRSA = "openssl rsautl -encrypt -inkey rsa.public -pubin -in key.txt -out key.txt.enc";
    std::system(commandRSA.c_str());
    if (std::remove("key.txt") != 0) {
        std::cerr << "CANNOT DELETE >>> key.txt" << std::endl;
    }
}

void StudentManager::decrypt (std::string filenameIn, std::string filenameOut) {
    std::string commandRSA = "openssl rsautl -decrypt -inkey rsa.private -in key.txt.enc -out key.txt";
    std::system(commandRSA.c_str());
    std::string key;
    std::ifstream file("key.txt", std::ios::in);
    file >> key;
    file.close();
    if (std::remove("key.txt.enc") != 0) {
        std::cerr << "CANNOT DELETE >>> key.txt.enc" << std::endl;
    }
    std::string commandAES = "openssl aes-128-cbc -d -in " + filenameIn + " -out " + filenameOut + " -pass pass:" + key;
    std::system(commandAES.c_str());
    if (std::remove(filenameIn.c_str()) != 0) {
        std::cerr << "CANNOT DELETE >>> " + filenameIn << std::endl;
    }
}
