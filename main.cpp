#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void registerUser() {
  string username, password, user, pass;
  cout << "\nEnter Username: ";
  cin >> username;
  cout << "\nEnter Password: ";
  cin >> password;

  ifstream read("users.txt");
  while (read >> user >> pass) {
    if (user == username) {
      cout << "Username already exists!\n";
      read.close();
      return;
    }
  }
  read.close();

  ofstream write(users.txt", ios::app);
  write << username << " " << password << endl;
  write.close();

  cout << "Registration Successful!\n";
}

void loginUser() {
  string username, password, user, pass;
  cout << "\nEnter Username: ";
  cin >> username;
  cout << "\nEnter Password: ";
  cin >> password;

  ifstream read("users.txt");
  while (read >> user >> pass) {
    if (user == username && pass == password) {
      cout << "Login Successful!\n";
        read.close();
        return;
    }
  }
  read.close();

  cout << "Invalid Username or Password!\n";
}

int main() {
  int choice;

  do {
    cout << "\n===== Login & Registration System ====\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
          registerUser();
          break;
      case 2:
          loginUser();
          break;
      case 3:
          cout << "thank you!\n";
          break;
      default:
          cout << "Invalid Choice!\n";
    }
  } while (choice !=3);

    return 0;
}

