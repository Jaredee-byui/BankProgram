// W02ProveJaredEllis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "account.h"
#include <iostream>
#include <string.h>
#include <list>
#include <algorithm>
#include <numeric>
using namespace std;

list<Account>::iterator searchByID(list<Account>& accounts, int inputID);
void searchPrompt(list<Account>& accounts);
void addSearchBalance(list<Account>& accounts);
void removeSearchBalance(list<Account>& accounts);
void displayAccounts(list<Account>& accounts);
void removeAccount(list<Account>& accounts);
void totalBalances(list<Account>& accounts);
void addDividend(list<Account>& accounts);

/*
    Main - handles calling teh otehr classes and performs the operations of the
    program
*/

int main()
{
    // account object is created and attributes are defined by the user
    list<Account> accounts;

    int userInput = 9;


    // while loop to control the user menu
    while (userInput != 0) {
        cout << "Account Menu: " << endl;
        cout << "0. Quit Program" << endl;
        cout << "1. Display Account Info" << endl;
        cout << "2. Make a Deposit" << endl;
        cout << "3. Make a withdrawl" << endl;
        cout << "4. Add a new account" << endl;
        cout << "5. Find account by ID" << endl;
        cout << "6. Remove account" << endl;
        cout << "7. Show total balance for all accounts" << endl;
        cout << "8. Add a divdend to all accounts" << endl;
        cout << "Your Choice: ";
        cin >> userInput;

        if (userInput == 1) {
            // view the details of all accounts in system
            displayAccounts(accounts);
        }
        else if (userInput == 2) {
            // make deposit via search
            addSearchBalance(accounts);
        }
        else if (userInput == 3) {
            // make withdrawl via search
            removeSearchBalance(accounts);
        }
        else if (userInput == 4) {
            // create a new account
            Account newAccount = Account();
            newAccount.createAccount();
            accounts.push_back(newAccount);
        }
        else if (userInput == 5) {
            // search via account ID
            searchPrompt(accounts);
        }
        else if (userInput == 6) {
            // remove account based on ID
            removeAccount(accounts);
        }
        else if (userInput == 7) {
            // find total of all acounts
            totalBalances(accounts);
        }
        else if (userInput == 8) {
            // add dividend to all acounts
            addDividend(accounts);
        }
    }
}

/*
     SearchPrompt: searches through the accounts list for an
     account with an ID that matches the user input.

*/
void searchPrompt(list<Account>& accounts) {
    int inputID;
    cout << "Please enter the search ID: ";
    cin >> inputID;

    // FOR loop iterates through list searching for inputID
    list<Account>::iterator class_iterator;
    class_iterator = searchByID(accounts, inputID);

    // RETURN if found, else says so
    if (class_iterator != accounts.end()) {
        cout << "Account found!" << endl;
        class_iterator->getAccount();
    }
    else {
        cout << "Account not found." << endl;
    }
}

/*
    searchByID: searches throught the accounts list with an ID passed
    to it by searchPrompt, returns if found else returns null

*/
list<Account>::iterator searchByID(list<Account>& accounts, int inputID) {
    // FOR loop iterates through list
    list<Account>::iterator class_iterator;

    for (class_iterator = accounts.begin(); class_iterator != accounts.end(); ++class_iterator) {
        // RETURN if found
        if (class_iterator->getID() == inputID) {
            return class_iterator;
        }
    }

    // ELSE return null
    return class_iterator;
}


/*
    addSearchBalance: takes the account list and searches for an
    ID provided by user, if found prompts for add amount and updates
    object

*/
void addSearchBalance(list<Account>& accounts) {
    int inputID;
    cout << "Please enter the search ID: ";
    cin >> inputID;

    list<Account>::iterator class_iterator;
    class_iterator = searchByID(accounts, inputID);

    if (class_iterator != accounts.end()) {
        cout << "Account found!" << endl;
        class_iterator->getAccount();
        class_iterator->addBalance();
    }
    else {
        cout << "Account not found." << endl;
    }
}

/*
    removeSearchBalance: takes the account list and searches for an
    ID provided by user, if found prompts for remove amount and updates
    object

*/
void removeSearchBalance(list<Account>& accounts) {
    int inputID;
    cout << "Please enter the search ID: ";
    cin >> inputID;

    list<Account>::iterator class_iterator;
    class_iterator = searchByID(accounts, inputID);

    if (class_iterator != accounts.end()) {
        cout << "Account found!" << endl;
        class_iterator->getAccount();
        class_iterator->removeBalance();
    }
    else {
        cout << "Account not found." << endl;
    }
}

void removeAccount(list<Account>& accounts) {
    int inputID;
    cout << "Please enter the account ID to remove: ";
    cin >> inputID;

    auto new_end = remove_if(accounts.begin(), accounts.end(), [inputID](auto& account) {
        return inputID == account.getID();
        }
    );

    accounts.erase(new_end, accounts.end());
}

void displayAccounts(list<Account>& accounts) {
    for_each(accounts.begin(), accounts.end(), [](auto& account) {
        account.getAccount();
        }
    );
}

void totalBalances(list<Account>& accounts) {
    float total = accumulate(accounts.begin(), accounts.end(), 0.0f, [](auto accumulator, auto& account) {
        return accumulator + account.getBalance();
        }
    );

    cout << "Total of all accounts balance is: " << total << endl;
}

void addDividend(list<Account>& accounts) {
    double percentage;
    cout << "Enter the dividend as a percentage: ";
    cin >> percentage;

    transform(accounts.begin(), accounts.end(), accounts.begin(), [percentage](auto& account) {
        account.accumulateBalance(percentage);
        }
    );
}

