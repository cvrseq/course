#include "student.h"
#include "studentManage.h"

int main() {
    StudentManager::decrypt("data.enc", "data.txt");
    StudentManager manager;
    manager.loadStudents("data.txt");

    int option, sessionIndex = 1;
    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
    std::cout << "!!!                     Menu program =)                                 !!!" << std::endl;
    std::cout << "!!!                                                                     !!!" << std::endl;
    std::cout << "!!!   Select an option:                                                 !!!" << std::endl;
    std::cout << "!!!   1. Sort by the second session (default)                           !!!" << std::endl;
    std::cout << "!!!   2. Choose another session to sort by (up to session 8)            !!!" << std::endl;
    std::cout << "!!!   3. Exit program                                                   !!!" << std::endl;
    std::cout << "!!!                                                                     !!!" << std::endl;
    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
    std::cin >> option;

    switch (option) {
        case 1:
            sessionIndex = 1; // second session
            break;
        case 2:
            std::cout << "Enter the session number to sort by (1-8): ";
            std::cin >> sessionIndex;
            sessionIndex = (sessionIndex < 1 || sessionIndex > 8) ? 1 : sessionIndex - 1;
            break;
        case 3:
            std::cout << "Exiting the program.\n";
            return 0;
        default:
            std::cout << "Invalid option, sorting by the second session by default.\n";
            break;
    }

    manager.sortStudentsBySession(sessionIndex);
    manager.printAndSaveStudents("result.txt", sessionIndex);
    std::cout << "Sorting complete. Results are saved to result.txt and displayed in the console." << std::endl;

    StudentManager::encrypt("data.txt", "data.enc");

    return 0;
}
