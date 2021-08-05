#include <iostream>
#include <string>
#include <vector>
using std::string;
class Lab
{
    int capacity;
    string labName;

public:
    Lab(string name = "", int c = 0)
        : labName(name), capacity(c) {}
    void setCapacity(int cap)
    {
        capacity = cap;
    }
    void setlabName(string name)
    {
        labName = name;
    }
    int getCapacity()
    {
        return capacity;
    }
    string getlabName()
    {
        return labName;
    }
};
class LecturerRoom
{
    int capacity, roomNo;
    string roomName;

public:
    LecturerRoom(string name = "", int no = 0, int c = 0)
        : roomName(name), roomNo(no), capacity(c) {}
    void setCapacity(int cap)
    {
        capacity = cap;
    }
    void setRoomNo(int n)
    {
        roomNo = n;
    }
    void setRoomName(string name)
    {
        roomName = name;
    }
    int getCapacity()
    {
        return capacity;
    }
    int getRoomNo()
    {
        return roomNo;
    }
    string getRoomName()
    {
        return roomName;
    }
};
class N28
{
    std::vector<Lab> labs;
    std::vector<LecturerRoom> room;

public:
    void insert(Lab &_lab)
    {
        labs.push_back(_lab);
    }

    void insert(LecturerRoom &_room)
    {
        room.push_back(_room);
    }
    void showLabs()
    {
        std::cout << "Show all labs:\n";
        for (int i = 0; i < labs.size(); i++)
            std::cout << "Lab " << labs[i].getlabName() << " " << labs[i].getCapacity() << " Capacity\n";
    }
    void showLectureRoom()
    {
        std::cout << "Show all lecturers rooms:\n";
        for (int i = 0; i < room.size(); i++)
            std::cout << room[i].getRoomName() << " " << room[i].getRoomNo() << " " << room[i].getCapacity() << " Capacity\n";
    }
};
int main()
{
    N28 a;
    Lab lab1("MPK1", 60), lab2("MPK2", 60), lab3("MPK3", 50), lab4("MPK4", 50);
    a.insert(lab1);
    a.insert(lab2);
    a.insert(lab3);
    a.insert(lab4);

    LecturerRoom r1("Hafiz", 102, 3), r2("Shafie", 105, 3), r3("Aisha", 202, 3), r4("Rahim", 208, 3);
    a.insert(r1);
    a.insert(r2);
    a.insert(r3);
    a.insert(r4);

    std::cout << "Welcome to N28 Building\n";
    a.showLabs();
    a.showLectureRoom();
}