package ca.cmpt213.as4.bank;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SavingsAccountTest {

    SavingsAccount account1, account2;
    double balance = 200.0;
    double annualInterestRate = 24.0;

    //valid account
    @BeforeEach
    void setUp() {
        account1 = new SavingsAccount(balance, annualInterestRate);

    }

    //clean up after
    @AfterEach
    void tearDown() {
        account1 = null;
        account2 = null;
    }

    //test invalid inputs when creating new account
    @Test
    void testInvalidConstructor() {
        assertThrows(IllegalArgumentException.class, () ->
                account2 = new SavingsAccount(-10.10, -10.10)
        );
        assertThrows(IllegalArgumentException.class, () ->
                account2 = new SavingsAccount(-10.10, 10.10)
        );
        assertThrows(IllegalArgumentException.class, () ->
                account2 = new SavingsAccount(10.10, -10.10)
        );
    }

    //test deposit
    @Test
    void testDeposit() {
        assertThrows(IllegalArgumentException.class, () ->
                account1.deposit(-10)
        );
        double depositAmount = 50;
        account1.deposit(depositAmount);
        assertEquals(balance + depositAmount, account1.balance);
    }

    //test withdraw
    @Test
    void testWithdraw() {
        assertThrows(IllegalArgumentException.class, () ->
                account1.withdraw(-1)
        );
        assertThrows(IllegalArgumentException.class, () ->
                account1.withdraw(300)
        );
        double withdrawAmount = account1.balance - 25;
        account1.withdraw(withdrawAmount);
        assertEquals(balance - withdrawAmount, account1.balance);
        account1.withdraw(10);
        assertEquals(balance - withdrawAmount, account1.balance);

    }

    //test monthly process
    @Test
    void testMonthlyProcess() {
        double withdrawAmount = 10.0;
        account1.withdraw(withdrawAmount);
        account1.monthlyProcess();
        assertEquals((balance - withdrawAmount) * (1 + annualInterestRate/1200), account1.balance);

        account1.balance = balance;
        int withdrawTimes = 1;
        for (int i = 0; i < withdrawTimes + 4; i++) {
            account1.withdraw(withdrawAmount);
        }
        account1.monthlyProcess();
        assertEquals((balance - withdrawTimes - withdrawAmount * (withdrawTimes + 4)) * (1 + annualInterestRate/1200), account1.balance);
    }
}