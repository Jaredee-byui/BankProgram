/***********************************************************************
 * Source File:
 *    Account: the details of an account in a bank
 * Author:
 *    Jared Ellis
 * Summary:
 *    Everything we need to handle the interaction between the system and
 *    the account.
 ************************************************************************/
#include "account.h"
#include <iostream>
#include <list>
using namespace std;

 /******************************************
   * Account : CONSTRUCTOR WITH accountID, accountName, accountBalance
   * Initialize the account with the passed
   * accountID, accountName, accountBalance
   *****************************************/


void Account::createAccount() {
	setName();
	setBalance();
}

void Account::getAccount() {
	// outputs the account info the user
	cout << "Account ID: " << getID()
		<< "| Name: " << getName()
		<< "| Balance: " << getBalance()
		<< endl;
}

void Account::setName() {
	string newName;
	cout << "Please enter the account name: ";
	cin >> newName;
	accountName = newName;

}

void Account::setBalance() {
	double newBalance;
	cout << "Please enter the initial balance: ";
	cin >> newBalance;
	accountBalance = newBalance;
}

void Account::addBalance() {
	double addAmount;
	cout << "Please enter the deposit amount: ";
	cin >> addAmount;
	accountBalance += addAmount;
}

void Account::removeBalance() {
	double removeAmount;
	cout << "Please enter the withdrawl amount: ";
	cin >> removeAmount;
	accountBalance -= removeAmount;
}

void Account::accumulateBalance(double percentage) {
	double percentageDecimal = (percentage / 100);
	double accountPercentage = getBalance() * percentageDecimal;
	accountBalance += accountPercentage;
}

int Account::accountID = 0;
