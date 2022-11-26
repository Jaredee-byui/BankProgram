/***********************************************************************
 * Header File:
 *    Account: the details of an account in a bank
 * Author:
 *    Jared Ellis
 * Summary:
 *    Everything we need to handle the interaction between the system and
 *    the account.
 ************************************************************************/

#pragma once
#include <string>
#include <list>
using namespace std;

/*
* Account
* The details related to a given account object
*/

class Account
{
public:
	// constructors
	Account() : accountName(""), accountBalance(0.0), currentID(accountID++) {};

	void createAccount();

	// getters and setters
	int getID() { return currentID; }
	

	string getName() { return accountName; }
	void setName();

	double getBalance() { return accountBalance; }
	void setBalance();
	
	void addBalance();
	void removeBalance();
	
	void accumulateBalance(double percentage);

	void getAccount();

	
private:
	// attributes
	static int accountID;
	string accountName;
	double accountBalance;
	int currentID;
};



