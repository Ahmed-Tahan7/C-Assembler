#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <bitset>

using namespace std;

// opcodes for instructions
map<string, string> opcode_map = {
    {"AND", "0000"}, {"ADD", "0001"}, {"LDA", "0010"}, {"STA", "0011"},
    {"BUN", "0100"}, {"BSA", "0101"}, {"ISZ", "0110"}, {"CLA", "7800"},
    {"CLE", "7400"}, {"CMA", "7200"}, {"CME", "7100"}, {"CIR", "7080"},
    {"CIL", "7040"}, {"INC", "7020"}, {"SPA", "7010"}, {"SNA", "7008"},
    {"SZA", "7004"}, {"SZE", "7002"}, {"HLT", "7001"}, {"INP", "F800"},
    {"OUT", "F400"}, {"SKI", "F200"}, {"SKO", "F100"}, {"ION", "F080"},
    {"IOF", "F040"}
};

// static memory addresses for labels
map<string, int> label_map = {
    {"SUB", 0x200},
    {"MIN", 0x300}, 
    {"DIF", 0x400}
};

string to_binary(int value) {
    bitset<16> binary(value);
    return binary.to_string();
}

string process_instruction(const string& instruction) {
    stringstream ss(instruction);
    string opcode, operand;
    
    ss >> opcode;  
    
    if (opcode_map.find(opcode) == opcode_map.end()) {
        return "";
    }
    
    string machine_code = opcode_map[opcode];
    
    if (ss >> operand) {
        if (label_map.find(operand) != label_map.end()) {
            int address = label_map[operand];
            machine_code += to_binary(address);
        }
        else if (operand.substr(0, 3) == "HEX") {
            string hex_value = operand.substr(4);
            int value = stoi(hex_value, nullptr, 16);
            machine_code += to_binary(value);
        } else {
            int address = stoi(operand);  
            machine_code += to_binary(address);
        }
    }
    
    return machine_code;
}

int main() {
    cout << "Enter your assembly code or type END to finish: " << endl;
    string line;
    string machine_code;

    while (getline(cin, line)) {
        if (line == "END") {
            break;
        }

        if (line.empty() || line[0] == '#') continue;
        
        machine_code = process_instruction(line);
        
        if (!machine_code.empty()) {
            cout << machine_code << endl;  
        }
    }

    return 0;
}
