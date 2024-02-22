#let project(title: "", logo: none, body) = {
  set document(title: title)
  set text(font: "Fira Sans",lang: "en",fill: luma(30))


  v(0.6fr)
  align(center,text(5em, weight: 800, title,fill:navy))
  
  if logo != none {
    align(center, image(logo, width: 40%))
  }
  v(4fr)

  // v(0.5fr)
  align(end,text(2.5em, weight: 600,"CSE 4851: Design Pattern",fill:luma(100)))
  v(0.8fr)
  align(end,text(3em, weight: 900,"Tasnimul Hasnat",fill:luma(30)))
  v(0.5fr)
  align(end,text(2.8em, weight: 600,"190041113",fill:luma(30)))
  v(1fr)
  align(end,text(1.8em, weight: 800,"February 14, 2024",fill:luma(70)))
  


  v(2.4fr)
  pagebreak()

  // Main body.
  set par(justify: true)
  set text(hyphenate: false)
  show heading: set block(above:1.5em, below: 1.5em)

  // code block prettier
  set raw(theme: "halcyon.tmTheme")
  show raw.where(block:true): it => block(
    width: 100%,
    fill: rgb("#1d2433"),
    inset: (left:40pt,top:20pt,bottom:20pt,right:20pt),
    radius: 10pt,
    text(fill: rgb("#a2aabc"), it)
  )

  // use the other way instead
  // show heading: it=>[
  //   #if it.level==1 {
  //   set align(center)
  //   text(18pt)[#it.body]
  //   } else [
  //     #it.body\
  //   ]
  // ]
  
  // the following works the same way but more preferred + cleaner
  show heading.where(level:1): it=>[
    #set block(below: 1.5em) // yes i need to re-apply the rule :(
    #set align(center)
    #set text(20pt,fill:navy)
    #it.body
  ]
  show heading.where(level:2): it=>[
    #set text(18pt)
    #it
  ]

  body
}

#show: project.with(
  title: "Assignment 1",
    logo: "iut.png"
)
#set page(numbering: "1", number-align: center)
#counter(page).update(1)


= Financial Institution Account Management System
In a financial institution, there's a need for an account management system that can handle various types of accounts such as savings accounts and checking accounts. Each account may have different interest calculation methods and additional features. Let's explore how each design pattern is applied in this scenario:
#v(10pt)
#text(14pt,weight:700)[
  1. Strategy Pattern:
]
*Scenario:* Different interest calculation methods are required for different types of accounts. For instance, savings accounts might have a simple interest calculation method, while checking accounts might have a compound interest calculation method.

*Application:* The Strategy pattern is applied by defining an interface `InterestCalculationStrategy` that declares a method  `calculate_interest()`. Concrete implementations such as `SimpleInterestStrategy` and `CompoundInterestStrategy` are then created, each implementing the `calculate_interest()` method differently. This allows the system to encapsulate these algorithms independently of the clients that use them.

#text(14pt,weight:700)[
  2. Factory Pattern:
]
*Scenario:* The system needs to create different types of accounts without exposing the instantiation logic directly to the client code. Each type of account may have different initialization procedures or dependencies.

*Application:* The Factory pattern is used to provide an interface `AccountFactory` with a method `create_account()`. Concrete factory implementations like `SavingsAccountFactory` and `CheckingAccountFactory` are responsible for creating instances of specific account types, such as savings accounts or checking accounts. This decouples the client code from the actual object creation process and allows for easier extension when new types of accounts are introduced.

#text(14pt,weight:700)[
  3. Decorator Pattern:
]
*Scenario:* Additional features or bonuses need to be added to accounts dynamically without modifying their structure. For instance, a bonus might be applied to a savings account, or an extra fee might be added to a checking account.

*Application:* The Decorator pattern is employed by defining a base class `Account` representing the core functionality of an account. Concrete account implementations like `SavingsAccount` and `CheckingAccount` extend this base class. Additionally, decorators such as `BonusDecorator` and `InterestRateDecorator` are created to add extra functionalities dynamically to account objects. This allows for flexible composition of behaviors at runtime without altering the existing codebase.

#pagebreak()

== Taking User Choice
To take user choices, I implemented a simple console-based input mechanism where users
can select the type of account they want to set up, the interest calculation method, and any additional customization options.

== Implementation

=== Interface for different types of accounts
```java
interface Account {
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance();
}
```
=== Concrete implementation of a savings account
```java
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
        System.out.println("Interest calculated for savings account.");
    }
}
```
#v(100pt)
=== Concrete implementation of a checking account
```java
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
         System.out.println("Checks processed for checking account.");
    }
}
```

=== Interface for different interaction channels
```java
interface BankingChannel {
    void login();
    void viewBalance();
    void transferFunds();
}
```
=== Concrete implementation of online banking
```java
class OnlineBanking implements BankingChannel {
    @Override
    public void login() {
        System.out.println("Logged into online banking.");
    }

    @Override
    public void viewBalance() {
        System.out.println("Viewing balance in online banking.");
    }


    
    @Override
    public void transferFunds() {
        System.out.println("Transferring funds in online banking.");
    }

    public void payBills() {
        System.out.println("Paying bills in online banking.");
    }
}
```
=== Concrete implementation of mobile banking
```java
class MobileBanking implements BankingChannel {
    @Override
    public void login() {
        System.out.println("Logged into mobile banking.");
    }

    @Override
    public void viewBalance() {
        /System.out.println("Viewing balance in mobile banking.");
    }

    @Override
    public void transferFunds() {
        System.out.println("Transferring funds in mobile banking.");
    }

    public void depositCheck() {
        System.out.println("Depositing a check in mobile banking.")
    }
}
```
=== Concrete implementation of automated phone system
```java
class AutomatedPhoneSystem implements BankingChannel {
    @Override
    public void login() {
        System.out.println("Authenticated through automated phone system.");
    }

    @Override
    public void viewBalance() {
        System.out.println("Viewing balance through automated phone system.");
    }

    @Override
    public void transferFunds() {
        System.out.println("Transferring funds through automated phone system.");
    }
}
```
=== Concrete implementation of a chatbot
```java
class Chatbot implements BankingChannel {
    @Override
    public void login() {
        System.out.println("Chat session started with the chatbot.");
    }

    @Override
    public void viewBalance() {
        System.out.println("Viewing balance through the chatbot.");
    }

    @Override
    public void transferFunds() {
        System.out.println("Transferring funds through the chatbot.");
    }
}
```

#pagebreak()

== UML Diagram
#image("uml_diagram.svg")
In this diagram:

- `User` interacts with the system through various channels such as `OnlineBanking`, `MobileBanking`, `AutomatedPhoneSystem`, or `Chatbot`.
- `Account` represents the core functionality of bank accounts, with `SavingsAccount` and `CheckingAccount` as specific types of accounts.
- `OnlineBanking`, `MobileBanking`, `AutomatedPhoneSystem`, and `Chatbot` are different interaction channels available to users for managing their accounts.

== Conclusion
The implemented financial institution account management system showcases a well-structured Java application, leveraging interfaces and classes to model diverse account types and interaction channels. Through interfaces like Account and BankingChannel, the system achieves encapsulation and abstraction, hiding implementation details while exposing essential functionalities. The flexibility and modularity of the design enable seamless extension and customization, allowing for the addition of new account types or interaction channels without disrupting existing code. With its emphasis on scalability, maintainability, and adherence to software design principles, the system serves as a robust foundation for building sophisticated banking applications capable of meeting the evolving needs of users in a dynamic financial landscape.