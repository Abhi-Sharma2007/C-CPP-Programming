#include <iostream>
#include <string>
using namespace std;

struct bank
{
    int acno;
    string na, act;
    double bal = 0;
    double interest=7.5/100;

    void deposit(double amt)
    {
        if (amt <= 0)
        {
            cout << "Invalid amount" << endl;
            return;
        }

        bal += amt;
        cout << "Amount deposited successfully" << endl;
    }

    void withdraw(double amt)
    {
        if (amt <= 0)
        {
            cout << "Invalid amount" << endl;
        }
        else if (amt > bal)
        {
            cout << "Insufficient balance" << endl;
        }
        else
        {
            bal -= amt;
            cout << "Amount withdrawn successfully" << endl;
        }
    }

    void transfer(bank &b, double amt)
    {
        if (amt <= 0)
        {
            cout << "Invalid amount" << endl;
        }
        else if (amt > bal)
        {
            cout << "Insufficient balance" << endl;
        }
        else
        {
            bal -= amt;
            b.bal += amt;

            cout << "Amount transferred successfully" << endl;
        }
    }
};

int main()
{
    bank b[100];
    int acn = 0;
    int ch;

    do
    {
        cout << "\n1. Create account\n 2. Deposit\n 3. Withdraw\n 4. Delete account\n 5. Transfer\n 6. Search account\n 7. Display accounts\n 8. Apply interest\n 9. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            b[acn].acno = acn + 1;

            cin.ignore();

            cout << "Enter your name: ";
            getline(cin, b[acn].na);

            cout << "Enter your account type: ";
            getline(cin, b[acn].act);

            b[acn].bal = 0;

            cout << "Account created successfully!" << endl;
            cout << "Your account number is: " << b[acn].acno << endl;

            acn++;
            break;
        }

        case 2:
        {
            int a;
            double amt;
            bool found = false;

            cout << "Enter account number: ";
            cin >> a;

            for (int i = 0; i < acn; i++)
            {
                if (b[i].acno == a)
                {
                    found = true;

                    cout << "Enter amount to deposit: ";
                    cin >> amt;

                    b[i].deposit(amt);
                    break;
                }
            }

            if (!found)
                cout << "Account not found" << endl;

            break;
        }

        case 3:
        {
            int a;
            double amt;
            bool found = false;

            cout << "Enter account number: ";
            cin >> a;

            for (int i = 0; i < acn; i++)
            {
                if (b[i].acno == a)
                {
                    found = true;

                    cout << "Enter amount to withdraw: ";
                    cin >> amt;

                    b[i].withdraw(amt);
                    break;
                }
            }

            if (!found)
                cout << "Account not found" << endl;

            break;
        }

        case 4:
        {
            int a;
            bool found = false;

            cout << "Enter account number: ";
            cin >> a;

            for (int i = 0; i < acn; i++)
            {
                if (b[i].acno == a)
                {
                    found = true;

                    b[i].acno = -1;
                    b[i].na = "";
                    b[i].act = "";
                    b[i].bal = 0;

                    cout << "Account deleted successfully" << endl;
                    break;
                }
            }

            if (!found)
                cout << "Account not found" << endl;

            break;
        }

        case 5:
        {
            int from, to;
            double amt;
            int i1 = -1, i2 = -1;

            cout << "Enter your account number: ";
            cin >> from;

            cout << "Enter account number to transfer to: ";
            cin >> to;

            for (int i = 0; i < acn; i++)
            {
                if (b[i].acno == from)
                    i1 = i;

                if (b[i].acno == to)
                    i2 = i;
            }

            if (i1 == -1 || i2 == -1)
            {
                cout << "One or both accounts not found" << endl;
            }
            else if (i1 == i2)
            {
                cout << "Cannot transfer to the same account" << endl;
            }
            else
            {
                cout << "Enter amount to transfer: ";
                cin >> amt;

                b[i1].transfer(b[i2], amt);
            }

            break;
        }

        case 6:
        {
            int a;
            bool found = false;

            cout << "Enter account number: ";
            cin >> a;

            for (int i = 0; i < acn; i++)
            {
                if (b[i].acno == a)
                {
                    found = true;

                    cout << "\nAccount Details\n";
                    cout << "Account No: " << b[i].acno << endl;
                    cout << "Name: " << b[i].na << endl;
                    cout << "Account Type: " << b[i].act << endl;
                    cout << "Balance: " << b[i].bal << endl;

                    break;
                }
            }

            if (!found)
                cout << "Account not found" << endl;

            break;
        }

        case 7:
        {
            cout << "Displaying all accounts..." << endl;
            for (int i = 0; i < acn; i++)
            {
                if (b[i].acno != -1)
                {
                    cout << "\nAccount Details\n";
                    cout << "Account No: " << b[i].acno << endl;
                    cout << "Name: " << b[i].na << endl;
                    cout << "Account Type: " << b[i].act << endl;
                    cout << "Balance: " << b[i].bal << endl;
                }
            }
            break;
        }

        case 8:
        { int a;
            bool found = false;
            cout << "Enter account number to apply interest: ";
            cin >> a;
            for (int i = 0; i < acn; i++)
            {
                if (b[i].acno == a)
                {   found = true;
                    if(b[i].act == "savings" || b[i].act == "Savings" || b[i].act == "SAVINGS"  )
                    b[i].bal += b[i].bal * b[i].interest;
                    else 
                    cout << "Interest can only be applied to savings accounts. Account No: " << b[i].acno << endl; 
                }
            }
            if (!found)
                cout << "Account not found" << endl;
            break;
        }
        case 9:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }

    } while (ch != 9);

    return 0;
}