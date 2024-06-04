#include <vector>
#include <cstdint>
#include <string>
#include <fstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <sstream>

class Memory {
public:
    Memory(size_t size) : data(size) {} 

    static std::string addressToHexadecimalString(size_t address) {
        std::stringstream ss;
        ss << "0x" << std::hex << std::setw(3) << std::setfill('0') << address;
        return ss.str();
    }

    void write(size_t address, char value) {
        if (address < data.size()) {
            data[address] = value;
        }
    }

    void clear(size_t address) {
        if (address < data.size()) {
            data[address] = 0;
        }
    }

    void test(size_t cell) {
        std::cout << cell << std::endl;
    }

    void writeInt(size_t address, uint8_t value) {
        uint8_t* bytePtr = reinterpret_cast<uint8_t*>(&value);
        for (size_t i = 0; i < sizeof(value); i++) {
            write(address + i, bytePtr[i]);
        }
    }

    void writeFromFile(size_t address, const std::string& filename) {   
        std::ifstream file(filename, std::ios::binary);
        if (!file.is_open()) throw std::runtime_error("Невозможно открыть файл");
        
        for (size_t i = 0; i < data.size(); i++) {
            std::string line;   
            if (std::getline(file, line)) { 
                std::istringstream iss(line);
                std::string remainder;
                int addr;
                try {
                    if (iss >> addr) {
                        std::getline(iss, remainder);
                        write(address + addr, std::stoi(remainder));
                    }
                }
                catch (const std::invalid_argument& e) {
                    for (size_t j = 0; j < data.size(); j++) {
                        char buffer;
                        if (file.get(buffer) && std::getline(file, line)) {
                            std::cout << buffer << std::endl;
                            write(address + j, static_cast<uint8_t>(buffer));
                        }
                    }
                }
            }
        }
    }

    const std::vector<uint8_t>& getData() const {
        return data;
    }

    static std::string byteToBinaryString(uint8_t byte) {
        std::bitset<20> bits(byte);
        return bits.to_string();
    }
    
    private: std::vector<uint8_t> data;
};
