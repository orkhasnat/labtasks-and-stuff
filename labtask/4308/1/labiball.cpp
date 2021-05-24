#include <bits/stdc++.h>
#define sep cout << "-----------------------------------\n";
using namespace std;

vector<string> studentFields, gradeFields;
string line, word, input;

void getFields(vector<string> &fields, string filename) {
    fstream fp(filename,ios::in);
    getline(fp,line);
    stringstream ss(line);
    while(ss >> word) fields.push_back(word);
    fp.close();
}

void showOptions() {
    string s = R"(what would like to do?
1.Insert a new record
2.Show a record
3.Remove invalid records
4.Rename Comilla to Cumilla
5.Exit
Enter your choice: )";

    cout << s;
}

void addNewRecord(vector<string> &fields, string filename) {
    fstream fp(filename, ios::app);
    int total = fields.size();
    fp << "\n";
    for(int i = 0; i < total; i++) {
        cout << "Enter " << fields[i] << ": ";
        cin >> input;
        fp << input << " ";
    }
    fp.close();
}

void showRecord(string ID, string filename, vector<string> &fields) {
    fstream fp(filename, ios::in);

    getline(fp, line);
    while(getline(fp, line)) {
        stringstream ss(line);
        ss >> word;
        if(word != ID) continue;
        sep
        int i = 1;
        cout << fields[0] << ": " << ID << "\n";
        while(ss >> word) {
            cout << fields[i++] << ": " << word << "\n";
        }
        return;
    }

}

void removeInvalidRecords() {
    fstream fp("grade.txt", ios::in);
    fstream tmp("temp.txt", ios::out);
    getline(fp, line);
    for(string field : gradeFields) tmp << field << " ";
    tmp << "\n";
    while(getline(fp, line)) {
        int count = 0;
        stringstream ss(line);
        while(ss >> word) count++;
        if(count == gradeFields.size()) tmp << line << "\n";
    }
    remove("grade.txt");
    rename("temp.txt", "grade.txt");
    cout << "Operation Successful!\n";

    fp.close();
    tmp.close();

}

void removeComillaToCumilla() {
    fstream fp("student.txt", ios::in);
    fstream tmp("temp.txt", ios::out);

    for(string field : studentFields) {
        tmp << field << " ";
    } 
    tmp << "\n";

    getline(fp, line);
    while(getline(fp, line)) {
        stringstream ss(line);
        string templine = "";
        while(ss >> word) {
            if(word == "Comilla") word = "Cumilla";
            templine += word + " ";
        }
        tmp << templine << "\n";
    }
    remove("student.txt");
    rename("temp.txt", "student.txt");

    cout << "Operation Successful!\n";

    fp.close();
    tmp.close();

}


int main() {
    getFields(studentFields, "student.txt");
    getFields(gradeFields, "grade.txt");

    sep
    bool run = true;
    while(run) {
        showOptions();
        cin >> input;
        if(input != "5") sep
        int choice = stoi(input);
        if(choice == 1) {
            addNewRecord(studentFields, "student.txt");
            sep
            cout << "Record has been added!\n";
        } else if(choice == 2) {
            cout << "Enter ID: ";
            cin >> input;
            showRecord(input, "student.txt", studentFields);
            showRecord(input, "grade.txt", gradeFields);
        } else if(choice == 3) {
            removeInvalidRecords();
        } else if(choice == 4) {
            removeComillaToCumilla();
        } else if(choice == 5) {
            run = false;
            break;
        }
        sep
    }

    cout << "Have a great day!\n";
    cout << "------------------x----------------\n";
    


}

// Student_ID Name Age Blood_Group Department_Name No_of_Faculties Hometown Mobile 
// 101 tariq 21 B+ CSE 30 Chittagong 123123
// 115 labib 21 c++ CSE 30 Bogra 123123
// Student_ID CGPA Semester 
// 101 3 3
// 115 2 5