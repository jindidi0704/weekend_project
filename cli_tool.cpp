#include <iostream>
#include <string>

using namespace std;

void executeCommand(string cmd) {
    
    if (cmd == "help") {
        cout << "[System] Commands: help, status, power_on, reboot, exit" << endl;
    }
    
    else if (cmd == "status") {
        cout << "[System] System Status: Normal. Temperature: 45C" << endl;
    }

    else if (cmd == "reboot") {
        cout << "[System] System is rebooting." << endl;
    }

    else if (cmd == "power_on") {
        cout << "[System] System is running." << endl;
    }

    else {
        cout << "[Error] Wrong Input." << endl;
    }
}

int main() {

    string password, userInput;

    bool isRunning = true;

    cout << "Please enter the password." << endl;

    while (true) {
        cout << "Password:" ;
        
        getline(cin, password);

        if (password == "1234"){
            break;
        }
        else {
            cout << "Wrong password!" << endl;
            return 0;
        }
        
    }

    cout << "=== OpenBMC 模擬終端機 (輸入 'exit' 離開) ===" << endl;

    while (isRunning) {
        cout << "admin@bmc:$ "; // 模擬 Linux 的 terminal

        getline(cin, userInput);

        if (userInput == "exit") {
            return 0;
        }
        else {
            if (!userInput.empty()) {
                executeCommand(userInput);
            }
        }
    }
}