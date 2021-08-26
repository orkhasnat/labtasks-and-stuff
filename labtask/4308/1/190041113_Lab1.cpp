#include <bits/stdc++.h>
using namespace std;

vector<string> stField, gField;
string line, word, input;

void getFields(vector<string> &fields, string filename) {
    fstream fp(filename,ios::in);
    getline(fp,line);
    stringstream ss(line);
    while(ss >> word) fields.push_back(word);
    fp.close();
}

void showOptions() {
    string ss = R"(what would like to do?
1.Insert a new record
2.Show a record
3.Remove invalid records
4.Rename Comilla to Cumilla
5.Exit
Enter your choice: )";

    cout << ss;
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
          cout << "-----------------------------------\n";
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
    for(string field : gField) tmp << field << " ";
    tmp << "\n";
    while(getline(fp, line)) {
        int count = 0;
        stringstream ss(line);
        while(ss >> word) count++;
        if(count == gField.size()) tmp << line << "\n";
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

    for(string field : stField) {
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
    getFields(stField, "student.txt");
    getFields(gField, "grade.txt");

      cout << "-----------------------------------\n";
    bool run = true;
    while(run) {
        showOptions();
        cin >> input;
        if(input != "5")   cout << "-----------------------------------\n";
        int choice = stoi(input);
        if(choice == 1) {
            addNewRecord(stField, "student.txt");
              cout << "-----------------------------------\n";
            cout << "Record has been added!\n";
        } else if(choice == 2) {
            cout << "Enter ID: ";
            cin >> input;
            showRecord(input, "student.txt", stField);
            showRecord(input, "grade.txt", gField);
        } else if(choice == 3) {
            removeInvalidRecords();
        } else if(choice == 4) {
            removeComillaToCumilla();
        } else if(choice == 5) {
            run = false;
            break;
        }
          cout << "-----------------------------------\n";
    }
    cout << "------------------x----------------\n";
}

// student.txt
// student_id name age blood_group dept_name no_of_faculties hometown mobile_number 
// 1 Kuri 20 O- CSE 20 Dhaka 12345 
// 2 Jill 20 O+ EEE 32 Cumilla 58963 
// 3 Fork 25 AB+ ME 14 Dhaka 78965 
// 4 Towl 34 AB- EEE 32 Cumilla 74123 

// grade.txt
// student_id GPA Semester 
// 1 4 3rd
// 2 2.9 1st
// 3 3.8 7th
// 4 3.5 Msc
