## Banking Management ##
Team Member Names : 
211116 - Hitanshu Kaushik 
211133 - Siddhartha Sharma

Problem Statement :
Implementing a Banking Management System in C++ program using OOPs concepts.

Details :
Generally the code contains some basic and 
important information such as creating an account
by verifying user name and pin, deposit money,
withdrawal of money, checking the minimum balance,
in pin also it possesses some required coditions for checking,
in this program user can also add his/her account
Finally, user can also delete an account as per his/her 
requirements.If user name or pin is same then we should

We also created csv file in which all the data
can be stored. It shows us remaining balances.

Methodology :
In this project, we made three classes i.e. for
Accounts, Transactions and AccountActions.

-->Class Accounts: -
"bool VerifyUser" function works for making account of a 
User which includes username, pin for an account
--Another function is vector used with function name
"AccountDetails" which uses csv files to store correct
information of account holder.

-->Class Transactions: -
In this class, function name "bool MoneyActions" is used
which uses float as data-type for amount. In this class
it verify's that username is already exists or not. Also 
it searches for minimum(sufficient) balance amount.
--"bool TransferMoney" function is used to checking an 
account with each and every detail. it also opens a new
account general required information.

-->Class AccountActions: -
Initially it consists of string function named "AccountNo"
is there for making a new account.
--"bool verifyCred" is used for verification of users
credentials such pin, username, etc.
--"bool verifyUserCharacter" uses 'iswalnum' for checking
an alphanumneric characters in pin. Also in this function
size of the username and pin is verified.
--"bool AddAccount" and "void DeleteAccount" functions
are used for adding and deleting accounts with correct
username and pin.

-->Main Function: -
In main function, as usual all the functions of the
respective class are called and input is given.

Assumptions :
In assumptions, the only assumption is that there is
no way transferring an amount from one bank account
to another bank account.

To run program :
It firstly asks for having account or not?
Then to select actions i.e. for deposit, withdraw,
getting account detail, transfer of money, deletion
of account and logout. After selecting, you have to
enter an username with minimum 6 characters, then 
pin for an account with minimum 6 characters which
must includes alphanumeric characters.

![WhatsApp Image 2022-12-08 at 17 24 39](https://user-images.githubusercontent.com/118196801/206626712-3f6ca7c1-7b1d-4add-bf13-11b732304be4.jpg)

