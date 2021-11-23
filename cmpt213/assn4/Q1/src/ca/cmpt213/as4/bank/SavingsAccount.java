package ca.cmpt213.as4.bank;

/*
 * savings account class, extends bank account class
 */

public class SavingsAccount extends BankAccount{

    protected boolean accountStatus; //is the account active

    //constructor
    SavingsAccount(double balance, double annualInterestRate) throws IllegalArgumentException {
        super(balance, annualInterestRate);
        setStatus();
    }

    //check the balance of the account and set status based on it
    private void setStatus() {
        accountStatus = balance > 25;
    }

    //call on super class to deposit and set status after
    protected void deposit(double amount) throws IllegalArgumentException {
        super.deposit(amount);
        setStatus();
    }

    //call on super class to withdraw and set status after
    protected void withdraw(double amount) throws IllegalArgumentException {
        if (accountStatus) {
            super.withdraw(amount);
            setStatus();
        }
    }

    //call on super class to do the monthly process and set status after
    protected void monthlyProcess() {
        if (withdrawals > 4) {
            monthlyServiceCharge = withdrawals - 4;
        }
        super.monthlyProcess();
        setStatus();
    }
}
