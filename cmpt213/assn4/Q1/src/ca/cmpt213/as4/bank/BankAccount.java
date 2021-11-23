package ca.cmpt213.as4.bank;

/*
 * abstract bank account class, cannot be instantiated, contains all the base methods for bank accounts
 */

public abstract class BankAccount {

    protected double balance, annualInterestRate, monthlyServiceCharge = 0;
    protected int deposits, withdrawals;
    private int test = 0;

    //constructor, makes sure arguments are non-negative
    BankAccount(double balance, double annualInterestRate) throws IllegalArgumentException {
        if (balance < 0) {
            if (annualInterestRate < 0) {
                throw new IllegalArgumentException("Balance and annual interest rate cannot be negative");
            } else {
                throw new IllegalArgumentException("Balance cannot be negative");
            }
        }
        if (annualInterestRate < 0) {
            throw new IllegalArgumentException("Annual interest rate cannot be negative");
        }
        this.balance = balance;
        this.annualInterestRate = annualInterestRate;
        deposits = 0;
        withdrawals = 0;
    }

    //deposit
    protected void deposit(double amount) throws IllegalArgumentException {
        if (amount <= 0) {
            throw new IllegalArgumentException("Deposit amount cannot be negative or zero");
        }
        balance += amount;
        deposits++;
    }

    //withdraw
    protected void withdraw(double amount) throws IllegalArgumentException {
        if (amount <= 0) {
            throw new IllegalArgumentException("Withdrawal amount cannot be negative or zero");
        }
        if (amount > balance) {
            throw new IllegalArgumentException("You cannot withdraw more than you have");
        }
        balance -= amount;
        withdrawals++;
    }

    //calculate interest
    protected void calcInterest() {
        double monthlyInterestRate = annualInterestRate/1200;
        balance += balance * monthlyInterestRate;
    }

    //monthly process
    protected void monthlyProcess() {
        balance -= monthlyServiceCharge;
        calcInterest();
        deposits = 0;
        withdrawals = 0;
        monthlyServiceCharge = 0;
    }
}
