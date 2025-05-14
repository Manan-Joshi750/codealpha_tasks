#include <bits/stdc++.h>
using namespace std;

class Subject {
public:
    string name;
    int credits;
    double gradePoint;

    Subject(string n, int c, string grade) {
        name = n;
        credits = c;
        gradePoint = convertGrade(grade);
    }

    double convertGrade(string grade) {
        if (grade == "A+") return 10.0;
        if (grade == "A") return 9.0;
        if (grade == "B+") return 8.0;
        if (grade == "B") return 7.0;
        if (grade == "C") return 6.0;
        if (grade == "D") return 5.0;
        return 0.0;
    }
};

int main() {
    int n;
    cout << "Enter the number of subjects :  ";
    cin >> n;

    vector<Subject> subjects;
    for (int i = 0; i < n; i++) {
        string name, grade;
        int credit;
        cout << "Enter the name of the subject " << i + 1 << " : ";
        cin >> name;
        cout << "Credits : ";
        cin >> credit;
        cout << "Grade (A+ / A / B+ / B / C / D / F) : ";
        cin >> grade;

        subjects.push_back(Subject(name, credit, grade));
    }

    double totalPoints = 0, totalCredits = 0;
    for (int i = 0; i < subjects.size(); i++) {
        totalPoints += subjects[i].gradePoint * subjects[i].credits;
        totalCredits += subjects[i].credits;
    }

    cout << fixed << setprecision(2);
    cout << "Your CGPA is calculated out to be : " << (totalPoints / totalCredits) << endl;
}