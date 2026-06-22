#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;


struct Student {
    string id;
    string name;
    int score;
};


// Template 延伸挑戰題
template <class T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

template <class T>
T getMin(T a, T b) {
    return (a < b) ? a : b; 
}


bool isIdExists(const vector<Student>& students, const string& id) {
    for (const auto& student : students) {
        if (student.id == id) return true;
    }
    return false;
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n=== 學生成績管理系統 ===" << endl;
        cout << "1. Add student" << endl;
        cout << "2. List all students" << endl;
        cout << "3. Sort by score" << endl;
        cout << "4. Search by id" << endl;
        cout << "5. Show statistics" << endl;
        cout << "0. Exit" << endl;
        cout << "Pleace choice the function: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error.Pleace enter the number！\n";
            choice=-1;
            continue;
        }

        switch (choice) {
            case 1: { // 新增學生
                Student newStudent;
                cout << "Enter student ID: ";
                cin >> newStudent.id;
                
                if (isIdExists(students, newStudent.id)) {
                    cout << "Error! ID: " << newStudent.id << " has existed.\n";
                    break;
                }

                cout << "Enter name: ";
                cin.ignore(); // 
                getline(cin, newStudent.name);
                cout << "Enter score: ";
                cin >> newStudent.score;

                students.push_back(newStudent);
                cout << "Successfully added student information！\n";
                break;
            }
            case 2: { // 列出所有學生
                if (students.empty()) {
                    cout << "There is currently no student data.\n";
                    break;
                }
                cout << "\n--- Student list ---\n";
                cout << left << setw(10) << "ID" << setw(15) << "Name" << "Score\n";
                cout << "--------------------------------\n";
                for (const auto& s : students) {
                    cout << left << setw(10) << s.id << setw(15) << s.name << s.score << "\n";
                }
                break;
            }
            case 3: { // 依成績排序 (由高到低)
                if (students.empty()) {
                    cout << "There is currently no student data to sort.\n";
                    break;
                }
                sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                    return a.score > b.score;
                });
                cout << "The scores have been sorted from highest to lowest！\n";
                break;
            }
            case 4: { // 查詢學生
                string targetId;
                cout << "Enter the student ID you want to search: ";
                cin >> targetId;
                
                bool found = false;
                for (const auto& s : students) {
                    if (s.id == targetId) {
                        cout << "\nfind student data：\n";
                        cout << "ID: " << s.id << ", Name: " << s.name << ", Score: " << s.score << "\n";
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "can't find the ID: " << targetId << " in student data.\n";
                break;
            }
            case 5: { // 統計成績
                if (students.empty()) {
                    cout << "There is currently no student data available for statistics.\n";
                    break;
                }

                int totalScore = 0;
                int maxScore = students[0].score;
                int minScore = students[0].score;
                int passCount = 0;
                int failCount = 0;

                for (const auto& s : students) {
                    totalScore += s.score;
                    maxScore = getMax(maxScore, s.score); 
                    minScore = getMin(minScore, s.score);

                    if (s.score >= 60) passCount++;
                    else failCount++;
                }

                double average = static_cast<double>(totalScore) / students.size();

                cout << "\n--- 成績統計 ---\n";
                cout << "全班平均: " << fixed << setprecision(2) << average << "\n";
                cout << "最高分: " << maxScore << "\n";
                cout << "最低分: " << minScore << "\n";
                cout << "及格人數: " << passCount << "\n";
                cout << "不及格人數: " << failCount << "\n";
                break;
            }
            case 0:
                cout << "System shutdown";
                break;
            default:
                cout << "Invalid input.Please enter again!\n";
        }
    } while (choice != 0);

    return 0;
}