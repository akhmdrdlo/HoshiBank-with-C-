#include <iostream>
#include <conio.h>
using namespace std;

void garis();
void login();
void regis();
void bank();
void menu();

int pilih,limit;

string uname[1000];
string pass[1000];
int main(){
	cout<<"Welcome to HoshiBank!!\n";
	garis();
	regis();
	cout<<"Thank you for using our services!!"<<endl;
}

void garis(){
	cout<<"==================================="<<endl;
}
void regis(){
	int cont;
	string user,password;
	regist:
	cout<<"Register Yourself to Use our Services!!\n";
	garis();
	cout<<"Insert your Username : ";
	getline(cin,uname[0]);
	cout<<"Insert your Password : ";
	getline(cin,pass[0]);
	cout<<"You've entered "<<uname[0]<<" as Username and "<<pass[0]<<" as your Password\n";
	cout<<"Do you want to continue\n"
	<<"1.Yes			2.No\n";
	cin>>cont;
	if (cont == 1){
		system("CLS");
		login();
	} else {
		goto regist;
	}
}

void login(){
	string user,password;
	int chance = 2;
	relog:
	do {
	cout<<"Please Login First to Experience our Services!!"<<endl;
	garis();
	cout<<"Enter your username : "; //input akhmad
	getline(cin,user);
	getline(cin,user); //for decoy to enter your username
	cout<<"Enter your password : "; //input akhmad
	getline(cin,password);
			if(user==uname[0] && password==pass[0]){
					cout<<"Successfully Login!! Hello "<<uname[0]<<endl;
					system("CLS");
					menu();
			} else {		
				if(chance != 0){
					cout<<"You have "<<chance--<<" more chance left\n\n"<<endl;
					goto relog;
				} else {
					cout<<"You're being blocked out from our system!!"<<endl;
					break;
				}
			}
	}while (true);
}

void menu(){
	//Local variable declarations
	int command = 0;
	int money = 0;
	int balance = 100;
	// Print cmd
	transaction:
	cout<<"Welcome, "<<uname[0]<<"!!\n"
	<<"=============================\n";
	balance = balance;
	cout<<"Balance on your account : "<<balance<<endl;
	cout<<"Enter command number:\n"
	<<" 0 - Quit\n"
	<<" 1 - Deposit Money\n"
	<<" 2 - Withdraw Money\n"
	<<" 3 - Print Balance\n";

	//Read and handle banking command
	cin >> command;
	switch(command){
		case 0: //Quit
			cout << "See you later!" <<endl;
		case 1: //Deposit
			cout<<"Enter deposit amount: ";
			cin>>money;
			if(money<=60){ //you can't deposit above 60 balance at once
				balance = balance + money;
				break;
			}else{
				cout<<"Sorry you reached your Deposit Limit(max 60 for each transaction)\n";
				break;
			}
		case 2: //Withdraw
			retry_withdraw:
			cout <<"Enter withdraw amount: ";
			cin>>money;
			limit=balance - money < 10;
			if(balance>10){ //if you don't have enough balance to withdraw
				if(money>=balance){
					cout<<"Your balance are not enough to do this"<<endl;
					goto retry_withdraw;
				} else if (limit) {
					cout<<"Your balance are not enough to do this"<<endl;
					goto retry_withdraw;
				} else {
					balance = balance - money;
					break;
				}
			} else {
				cout<<"Your balance are not enough to do this"<<endl;
				break;
			}

		case 3: //Print Balance
			cout << "Your current balance = " << balance <<endl;
			break;
		default: //Handle other values
			cout << "Oops! your value are invalid!!"<<endl;
			break;
	}
	//print final balance
	int cont;
	string password;
	cout<<"=============================\n";
	cout<<"Your final balance are : "<<balance<<endl;
	cout<<"=============================\n";
	cout<<"Do you want to continue the transaction?\n"
	<<"1.Yes			2.No\n";
	cin>>cont;
	if (cont == 1){
		cout<<"=============================\n\n";
		cout<<"Input Password :"; //input akhmad if you want to continue your transaction
		getline(cin,password);
		getline(cin,password);
		if (password == pass[0]){
			system("CLS");
			goto transaction;
		} 
	} else {
		cout<<"Thank you,Please come back later!!"<<endl;
	}
}
