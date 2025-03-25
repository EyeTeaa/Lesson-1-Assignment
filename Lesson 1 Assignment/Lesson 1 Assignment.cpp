// Lesson 1 Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

/*This is the bank class and it handles all of the variables involving
what the user chooses, the name, balance, and account number*/
class BankAccount
{
private:
    string accountHolderName;
    int accountNumber;
    double balance;
    int choice; 
public:
    BankAccount(std::string accountHolderName, int accountNumber, double balance, int choice)
    {
        this->accountHolderName = accountHolderName;
        this->accountNumber = accountNumber; 
        this->balance = balance; 
        this->choice = choice; 
    }


    double deposit(double amount)
    {
        balance = balance + amount; 
        return balance; 
    }

    double withdraw(double amount)
    {
        if (amount > balance)
        {
            return balance; 
        }
        else
        {
            balance = balance - amount; 
            return balance; 
        }
    }

/*assigning and extracting */
    void setChoice(int choice)
    {
        this->choice = choice; 
    }

    string getAccountHolderName()
    {
        return accountHolderName; 
    }

    double getBalance()
    {
        return balance; 
    }

    int getChoice()
    {
        return choice; 
    }

};// end BankAccount 


/*the menu that shows before the user 
creates an account or enables one */
void starterMenu()
{
    cout << "Welcome to the Simple Bank System\n"; 
    cout << "1. Create Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Check Balance\n"; 
    cout << "5. Exit\n\n";
    cout << "Enter your choice: "; 
}


/*The menu that is shown one time after the 
account initializes */
void showMenu()
{
    cout << "1. Deposit Money\n";
    cout << "2. Withdraw Money\n";
    cout << "3. Check Balance\n";
    cout << "4. Exit\n";
}

/*stand alone function that handles the connection between 
the user's deposit within the class */
void deposit(BankAccount& user)
{
    double amount; 
    cout << "How much would you like to deposit? "; 

    while (true)
    {
        try
        {
            if (!(cin >> amount) || amount < 0 ) // if the deposit amount is less than 0 or not a number
            {
                throw invalid_argument("Invalid Argument");
            }
            else
            {
                user.deposit(amount); 
                cout << "Deposit successful! New Balance: $" << user.getBalance() << "\n";
                break; 
            }
            
        }
        catch(const invalid_argument& e)
        {
            cout << "You must enter a positive amount to deposit\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}


/*stand alone function that handles the user's choice to withdraw
and the balance in the bank account */
void withdraw(BankAccount& user)
{
    double amount; 
    while (true)
    {
        try
        {
            cout << "Enter the amount you would like to withdraw: "; 
            if (!(cin >> amount)) // if t
            {
                throw invalid_argument("Invalid Argument");
            }
            else if (amount > user.getBalance())
            {
                cout << "Insufficient Funds!\n";
                break; 
            }
            else
            {
                user.withdraw(amount);
                break;
            }

        }
        catch (const invalid_argument& e)
        {
            cout << "You must enter a number\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

/*handles the user's choice to display balance and the class */
void displayBalance(BankAccount& user)
{
    cout << "Current Balance: $" << user.getBalance() << "\n";

}


/*switch cases that handle  the user's input 
and redirects it to the appropriate function */
int menuInput(BankAccount& user)
{
    int choice = user.getChoice(); 
    switch (choice)
    {
        case 1: 
            deposit(user); 
            break;
        case 2: 
            withdraw(user); 
            break;
        case 3: 
            displayBalance(user); 
            break; 
        case 4: 
            cout << "Thanks for using the simple bank system!";
            break;
    } 
    return 1; 
}

/*The initialization of the user input */
BankAccount firstAsk()
{
    int firstAnswer;
    string accountHolderName = "John"; 
    int accountNumber = 234; 
    double balance = 0; 
    starterMenu();

    while (true)
    {
        try
        {
            if (!(cin >> firstAnswer)) // if the input was not an integer 
            {
                throw invalid_argument("Invalid Argument");
            }
            else if (firstAnswer > 5 || firstAnswer < 1) // if the answer was not between 5 and 1 
            {
                throw invalid_argument("Invalid Argument");
            }
        }
        catch (const invalid_argument& e)
        {
            cout << "You must enter an int between 1 - 5:\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (firstAnswer == 1) // creating an account with their parameters 
        {
            cout << "Enter account holder name: ";
            cin >> accountHolderName; 
            cout << "Enter initial deposit: ";
            while (true)
            {
                try
                {
                    if (!(cin >> balance) || balance < 0) // if they don't enter an double at least 0 
                    {
                        throw invalid_argument("Invalid Argument");
                    }
                    else
                    {
                        break; 
                    }
                }
                catch (const invalid_argument& e)
                {
                    cout << "You must enter a positive num or 0: "; 
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                }

            }
            
            cout << "Account Created Successfully!";
            return BankAccount(accountHolderName, 1234, balance, firstAnswer);
        }
        else if (firstAnswer <= 5 && firstAnswer >= 2 ) // creating an account where they didn't initialize anything
        {
            return BankAccount("John Doe", accountNumber, balance, firstAnswer);
        }

    }

}//end first ask  



/*main driver of the program , wraps everything together */
int main()
{
    BankAccount user = firstAsk();
    cout << "Welcome to your account " + user.getAccountHolderName()  << "\n\n";

    showMenu(); 

    int choice; 
    choice = user.getChoice() - 1; 


    if (choice != 0)
    {
        menuInput(user);

    }


    while (true)
    {
        if (choice == 4)
        {
            break;
        }

        cout << "\nEnter your choice: "; 

        try
        {
            if (!(cin >> choice) || (choice < 1 || choice > 4))
            {
                throw invalid_argument("Invalid argument");
            }

            user.setChoice(choice);
            menuInput(user);
            
        }
        catch(const invalid_argument& e)
        {
            cout << "You must enter an int from 1 to 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }

        
    }


}

