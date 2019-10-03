//  Bank Account class

class BankAccount {
    constructor(name, balance) {
        this.name = name;
        this.balance = balance;
    }

    deposit(amount) {
        this.balance += amount;
        console.log(`Deposit of ${amount} successful.
        Your account balance is ${this.balance}`);
    }

    withdraw(amount) {
        if (this.balance >= amount) {
            this.balance -= amount;
            console.log(`withdrawal of ${amount} successful.
            Your account balance is ${this.balance}`);
        } else {
            console.log('Your account balance is insufficient for this withdrawal')
        }
    }
}

let user1 = new BankAccount('John', 5000);