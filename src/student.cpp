//
// Created by Aleksandr Suslin on 10.05.2024.
//

#include "student.h"

double Student::averageForSession(int sessionIndex) const {
    if (sessionIndex >= sessions.size() || sessions[sessionIndex].empty()) return 0.0;
    double sum = 0.0;
    for (const auto& subject : sessions[sessionIndex]) {
        sum += subject.second;
    }
    return sessions[sessionIndex].empty() ? 0.0 : sum / sessions[sessionIndex].size();
}

std::istream& operator>>(std::istream& is, Student& s) {
    std::string line;
    if (std::getline(is, line)) {
        std::istringstream iss(line);
        getline(iss, s.fullName, ',');
        getline(iss, s.birthDate, ',');
        iss >> s.entryYear; iss.get();
        getline(iss, s.faculty, ',');
        getline(iss, s.department, ',');
        getline(iss, s.group, ',');
        getline(iss, s.recordBookNumber, ',');
        iss >> s.gender; iss.get();

        s.sessions.clear(); // Make sure to clear previous data
        std::string sessionData;
        while (getline(iss, sessionData, ',')) {
            std::istringstream sessionStream(sessionData);
            std::string gradePair;
            std::vector<std::pair<std::string, int>> sessionGrades;
            while (getline(sessionStream, gradePair, ';')) {
                auto pos = gradePair.find('-');
                sessionGrades.emplace_back(gradePair.substr(0, pos), stoi(gradePair.substr(pos + 1)));
            }
            if (!sessionGrades.empty()) {
                s.sessions.push_back(sessionGrades);
            }
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << "Full Name: " << s.fullName << "\n"
       << "Birth Date: " << s.birthDate << "\n"
       << "Entry Year: " << s.entryYear << "\n"
       << "Faculty: " << s.faculty << "\n"
       << "Department: " << s.department << "\n"
       << "Group: " << s.group << "\n"
       << "Record Book Number: " << s.recordBookNumber << "\n"
       << "Gender: " << (s.gender == 'M' ? "Male" : "Female") << "\n";
    return os;
}