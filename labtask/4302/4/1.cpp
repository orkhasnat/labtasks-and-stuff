#include <iostream>
#include <string>
using std::string, std::cout, std::cin, std::endl;

class Account
{
    string accName;
    float balance;
    string accNo;

public:
    Account(string str = "") : accName(str) {}
    void getInfo()
    {
        cout << "Name: " << accName
             << "\nAccount No: " << accNo
             << "\nBalance: " << balance << std::endl;
    }
    void setBalance(float bal)
    {
        balance = bal;
    }
    void setAccountName(string _n)
    {
        accName = _n;
    }
    void setAccountNo(int prefix, int no)
    {
        accNo = std::to_string(no);
        accNo = std::string(4 - accNo.length(), '0') + accNo;
        accNo = std::to_string(prefix) + accNo;
    }
    string getAccountName() const
    {
        return accName;
    }
    string getAccountNo() const
    {
        return accNo;
    }
    float getBalance() const
    {
        return balance;
    }
};

class CurrentAccount : public Account
{
    const static int serviceCharge = 100;
    const static int prefix = 100;
    static int next;

public:
    CurrentAccount(string str)
    {
        Account::setAccountNo(prefix, next);
        Account::setAccountName(str);
        setBalance(0);
        next++;
    }
    int getServiceCharge() const
    {
        return serviceCharge;
    }
    int getNextAccount() const
    {
        return next;
    }
    void description() const
    {
        cout << "Account Name: " << Account::getAccountName() << endl
             << "Account Number: " << Account::getAccountNo() << endl
             << "Current Balance: " << Account::getBalance() << endl;
    }
};
int CurrentAccount::next = 1;

class SavingsAccount : public Account
{
private:
    float interestRate;
    float monthlyDepositAmount;
    const static int prefix = 200;
    static int next;

public:
    SavingsAccount(string str)
    {
        Account::setAccountNo(prefix, next);
        Account::setAccountName(str);
        setBalance(0);
        setInterestRate(0);
        setMonthlyDepositAmount(0);
        next++;
    }
    void setInterestRate(float rate)
    {
        interestRate = rate;
    }
    void setMonthlyDepositAmount(float amount)
    {
        monthlyDepositAmount = amount;
    }
    float getInterestRate() const
    {
        return interestRate;
    }
    float getMonthlyDeposit() const
    {
        return monthlyDepositAmount;
    }

    void description() const
    {
        cout << "Account Name: " << Account::getAccountName() << endl
             << "Account Number: " << Account::getAccountNo() << endl
             << "Current Balance: " << Account::getBalance() << endl;
    }
};
int SavingsAccount::next = 1;

class LoanAccount : public Account
{
private:
    float interestRate;
    float monthlyDepositAmount;
    const static int prefix = 900;
    static int next;

public:
    LoanAccount(string str)
    {
        Account::setAccountNo(prefix, next);
        Account::setAccountName(str);
        setBalance(0);
        setInterestRate(0);
        setMonthlyDepositAmount(0);
        next++;
    }
    void setInterestRate(float _ir)
    {
        interestRate = _ir;
    }
    void setMonthlyDepositAmount(float amount)
    {
        monthlyDepositAmount = amount;
    }
    float getInterestRate() const
    {
        return interestRate;
    }
    float getMonthlyDepositAmount() const
    {
        return monthlyDepositAmount;
    }
    int getAccountPrefix() const
    {
        return prefix;
    }
    void description() const
    {
        cout << "Account Name: " << getAccountName() << endl
             << "Account Number: " << Account::getAccountNo() << endl
             << "Current Loan Amount: " << Account::getBalance() << endl
             << "Monthly downpayment is " << monthlyDepositAmount << " and interest rate is "
             << interestRate << "%\n";
    }
};
int LoanAccount::next = 1;

class monthlyDepositScheme : public Account
{

private:
    float interestRate;
    float monthlyDepositAmount;
    const static int prefix = 300;
    static int next;

public:
    //setter
    void setInterestRate(float _ir)
    {
        interestRate = _ir;
    }
    void setMonthlyDepositAmount(float amount)
    {
        monthlyDepositAmount = amount;
    }
    void _nextAccount()
    {
        this->next++;
    }
    //getter
    int getNextAccount() const
    {
        return next;
    }
    float getInterestRate() const
    {
        return interestRate;
    }
    float getMonthlyDepositAmount() const
    {
        return monthlyDepositAmount;
    }
    int getAccountPrefix() const
    {
        return prefix;
    }
};
int monthlyDepositScheme::next = 1;

class initialDepositMDS : public monthlyDepositScheme
{
private:
    float MaximumInterest;
    float initialDepositAmount;

public:
    initialDepositMDS(string str)
    {
        monthlyDepositScheme::setAccountNo(getAccountPrefix(), getNextAccount());
        monthlyDepositScheme::setAccountName(str);
        setBalance(0);
        setMaximumInterest(0);
        setInitialDepositAmount(0);
        setInterestRate(0);
        setMonthlyDepositAmount(0);
        _nextAccount();
    }
    float getinitialDepositAmount() const
    {
        return initialDepositAmount;
    }
    float getMaximumInterest() const
    {
        return MaximumInterest;
    }
    void description() const
    {
        cout << "Account Name: " << Account::getAccountName() << endl
             << "Account Number: " << Account::getAccountNo() << endl
             << "Current Balance: " << Account::getBalance() << endl
             << "You need to deposit atleast " << monthlyDepositScheme::getMonthlyDepositAmount() << " every month to get " << monthlyDepositScheme::getInterestRate() << '%' << " interest\n"
             << "If you don't close within 2 years you will get maximum " << MaximumInterest << "% interest\n";
    }
    void setInitialDepositAmount(float amount)
    {
        initialDepositAmount = amount;
    }
    void setMaximumInterest(float rate)
    {
        MaximumInterest = rate;
    }
};

class fiveYearMDS : public monthlyDepositScheme
{
private:
    float minimumInterest;

public:
    fiveYearMDS(string str)
    {
        monthlyDepositScheme::setAccountNo(getAccountPrefix(), getNextAccount());
        monthlyDepositScheme::setAccountName(str);
        setBalance(0);
        setMinimumInterest(0);
        setInterestRate(0);
        setMonthlyDepositAmount(0);
        _nextAccount();
    }
    float getMinimumInterest() const
    {
        return minimumInterest;
    }
    void description() const
    {
        cout << "Account Name: " << Account::getAccountName() << endl
             << "Account Number: " << Account::getAccountNo() << endl
             << "Current Balance: " << Account::getBalance() << endl
             << "Five Year Monthly Deposit Scheme, You need to deposit a fixed amount of money each month\n";
    }
    void setMinimumInterest(float rate)
    {
        minimumInterest = rate;
    }
};

class twoYearMDS : public monthlyDepositScheme
{
private:
    float minimumInterest;

public:
    twoYearMDS(string str)
    {
        monthlyDepositScheme::setAccountNo(getAccountPrefix(), getNextAccount());
        monthlyDepositScheme::setAccountName(str);
        setBalance(0);
        setMinimumInterest(0);
        setInterestRate(0);
        setMonthlyDepositAmount(0);
        _nextAccount();
    }
    float getMinimumInterest() const
    {
        return minimumInterest;
    }
    void description() const
    {
        cout << "Account Name: " << Account::getAccountName() << endl
             << "Account Number: " << Account::getAccountNo() << endl
             << "Current Balance: " << Account::getBalance() << endl
             << "Two Year Monthly Deposit Scheme, You need to deposit a fixed amount of money each month\n";
    }
    void setMinimumInterest(float rate)
    {
        minimumInterest = rate;
    }
};

int main()
{
    CurrentAccount c1("A");

    c1.description();

    CurrentAccount c2("B");

    c2.description();

    c1.setBalance(5000);
    c1.description();

    SavingsAccount s1("C");
    s1.description();

    SavingsAccount s2("D");
    s2.setInterestRate(3);
    s2.description();

    LoanAccount l1("E");

    l1.description();

    LoanAccount l2("F");
    l2.description();

    initialDepositMDS i1("G");

    i1.description();

    initialDepositMDS i2("H");
    i2.description();

    twoYearMDS t1("I");

    t1.description();

    twoYearMDS t2("J");
    t2.description();

    fiveYearMDS f1("K");

    f1.description();

    fiveYearMDS f2("L");
    f2.description();

    return 0;
}