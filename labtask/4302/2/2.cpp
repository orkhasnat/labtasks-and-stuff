#include <iostream>
#include <string>
using std::cin, std::cout, std::endl;

class BankAcc
{
    int accN;
    std::string name;
    int balance;
    int min;

public:
    enum AccType
    {
        Current,
        Savings
    } type;
    BankAcc(int _accN, std::string& _name, AccType _type, int _balance = 0)
    {
        accN = _accN;
        name = _name;
        if (_type == AccType::Current)
            min = 500;
        else
            min = 1000;
        type = _type;
        if (_balance > 0)
        {
            if (_balance >= min)
                balance = _balance;
            else
                cout << "you need to deposit " << _balance - min << "amount of money more\nDeposit Failed\nDeposit Again" << endl;
        }
    }
    void showInfo()
    {
        cout << "Name: " << name;
        if (type == Savings)
            cout << "Savings ";
        else
            cout << "Current ";
        cout << "\nAccount Number: " << accN << endl;
        showBalance();
    }
    void showBalance()
    {
        cout << "Current Balance: " << balance << " Tk\n";
    }
    void deposit(int amount)
    {
        balance += amount;
        cout << amount << " deposited successfully\n";
        showBalance();
    }
    void withdraw(int amount)
    {
        if (balance - amount < min)
            cout << "Cant withdraw below the minimum balance\n";
        else
        {
            balance -= amount;
            cout << amount << " withdrawn successfully\n";
        }
        showBalance();
    }
    void giveInterest(float rate = 2.5f)
    {
        int interest = (int)balance * rate / 100;
        int tax = (int)interest / 10;
        balance += interest - tax;
        showBalance();
    }
    ~BankAcc()
    {
        cout << "Account of " << name << " with account no: " << accN << " is destroyed with a balance BDT " << balance;
    }
};

int main()
{
    std::string name = "Tasnimul Hasnat";
    int accNum = 14569;
    BankAcc a1(accNum, name, BankAcc::Current,5100);
    a1.deposit(790);
    a1.deposit(600);
    a1.showInfo();
    a1.giveInterest();
    a1.showBalance();
}