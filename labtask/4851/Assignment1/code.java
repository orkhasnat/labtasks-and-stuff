// Interface for different types of accounts
interface Account {
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance();
}

// Concrete implementation of a savings account
class SavingsAccount implements Account {
    private double balance;

    @Override
    public void deposit(double amount) {
        balance += amount;
    }

    @Override
    public void withdraw(double amount) {
        balance -= amount;
    }

    @Override
    public double getBalance() {
        return balance;
    }

    public void calculateInterest() {
        // Logic to calculate interest
        System.out.println("Interest calculated for savings account.");
    }
}

// Concrete implementation of a checking account
class CheckingAccount implements Account {
    private double balance;

    @Override
    public void deposit(double amount) {
        balance += amount;
    }

    @Override
    public void withdraw(double amount) {
        balance -= amount;
    }

    @Override
    public double getBalance() {
        return balance;
    }

    public void processChecks() {
        // Logic to process checks
        System.out.println("Checks processed for checking account.");
    }
}

// Interface for different interaction channels
interface BankingChannel {
    void login();
    void viewBalance();
    void transferFunds();
}

// Concrete implementation of online banking
class OnlineBanking implements BankingChannel {
    @Override
    public void login() {
        // Logic for logging into online banking
        System.out.println("Logged into online banking.");
    }

    @Override
    public void viewBalance() {
        // Logic for viewing balance in online banking
        System.out.println("Viewing balance in online banking.");
    }

    @Override
    public void transferFunds() {
        // Logic for transferring funds in online banking
        System.out.println("Transferring funds in online banking.");
    }

    public void payBills() {
        // Logic for paying bills in online banking
        System.out.println("Paying bills in online banking.");
    }
}

// Concrete implementation of mobile banking
class MobileBanking implements BankingChannel {
    @Override
    public void login() {
        // Logic for logging into mobile banking
        System.out.println("Logged into mobile banking.");
    }

    @Override
    public void viewBalance() {
        // Logic for viewing balance in mobile banking
        System.out.println("Viewing balance in mobile banking.");
    }

    @Override
    public void transferFunds() {
        // Logic for transferring funds in mobile banking
        System.out.println("Transferring funds in mobile banking.");
    }

    public void depositCheck() {
        // Logic for depositing a check in mobile banking
        System.out.println("Depositing a check in mobile banking.");
    }
}

// Concrete implementation of automated phone system
class AutomatedPhoneSystem implements BankingChannel {
    @Override
    public void login() {
        // Logic for authenticating through automated phone system
        System.out.println("Authenticated through automated phone system.");
    }

    @Override
    public void viewBalance() {
        // Logic for checking balance through automated phone system
        System.out.println("Viewing balance through automated phone system.");
    }

    @Override
    public void transferFunds() {
        // Logic for transferring funds through automated phone system
        System.out.println("Transferring funds through automated phone system.");
    }
}

// Concrete implementation of a chatbot
class Chatbot implements BankingChannel {
    @Override
    public void login() {
        // Logic for starting a chat session with the chatbot
        System.out.println("Chat session started with the chatbot.");
    }

    @Override
    public void viewBalance() {
        // Logic for viewing balance through the chatbot
        System.out.println("Viewing balance through the chatbot.");
    }

    @Override
    public void transferFunds() {
        // Logic for transferring funds through the chatbot
        System.out.println("Transferring funds through the chatbot.");
    }
}
