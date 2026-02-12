#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream cpuInfo("/proc/cpuinfo");
    string line;

    if (cpuInfo.is_open()) {
        while (getline(cpuInfo, line)) {
            // 只印出包含 "model name" 那一行
            if (line.find("model name") != string::npos) {
                cout << line << endl;
                break;
            }   
        }
        cpuInfo.close();
    } else {
        cout << "無法讀取檔案" << endl;
    }
    return 0;
}