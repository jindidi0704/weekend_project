#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void showCPUInfo() {
    string line;
    // 2. 開啟 Linux 的系統資訊檔 (在 WSL 或任何 Linux 都存在)
    ifstream cpuFile("/proc/cpuinfo"); 

    if (cpuFile.is_open()) {
        while (getline(cpuFile, line)) {
            // 3. 搜尋包含 "model name" 的那一行
            // string::npos 是一個常數，代表「找不到」的意思
            if (line.find("model name") != string::npos) {
                cout << "[系統資訊] " << line << endl;
                break; // 找到一行就夠了，不用把所有核心都印出來
            }
        }
        cpuFile.close(); // 4. 記得關檔
    } else {
        cout << "[錯誤] 無法讀取系統資訊！" << endl;
    }
}

void executeCommand(string cmd) {
    
    if (cmd == "help") {
        cout << "[System] Commands: help, status, sys_info, power_on, reboot, exit" << endl;
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

    else if (cmd == "sys_info") {
        showCPUInfo();
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
        
        if (!password.empty()) {
            if (password == "1234"){
                break;
            }
            else {
                cout << "Wrong password!" << endl;
            }
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