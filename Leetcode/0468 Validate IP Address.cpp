class Solution {
public:
    vector<string> splitString(string &IP, char sp) {
        vector<string> nums;
        string num = "";
        for (auto &it: IP) {
            if (it == sp) {
                nums.push_back(num);
                num = "";
            } else {
                num.push_back(it);    
            }
        }
        nums.push_back(num);
        return nums;
    }
    
    int strToNum(string &num) {
        int numInt = 0;
        for (auto &it: num) {
            numInt *= 10;
            if ('0' <= it && it <= '9') {
                numInt += (it - '0');
            } else {
                return -1;
            }
        }
        return numInt;
    }
    
    string checkIPv4(string &IP) {
        vector<string> nums = splitString(IP, '.');
        if (nums.size() != 4) return "Neither";
        for (auto &it: nums) {
            if (it.size() > 1 && it[0] == '0') return "Neither";
            if (!(1 <= it.size() && it.size() <= 3)) return "Neither";
            int num = strToNum(it);
            if (!(0 <= num && num < 256)) return "Neither";
        }
        return "IPv4";
    }
    
    string checkIPv6(string &IP) {
        vector<string> nums = splitString(IP, ':');
        if (nums.size() != 8) return "Neither";
        for (auto &it: nums) {
            if (it.size() > 4 || it.size() < 1) return "Neither";
            for (auto &it2: it) {
                if ('0' <= it2 && it2 <= '9') continue;
                if ('A' <= it2 && it2 <= 'F') continue;
                if ('a' <= it2 && it2 <= 'f') continue;
                return "Neither";
            }
        }
        return "IPv6";
    }
    
    string validIPAddress(string IP) {
        bool check4 = false, check6 = false;
        for (auto& it: IP) {
            if (it == '.') check4 = true;
            if (it == ':') check6 = true;
        }
        if ((check4 && check6) || (!check4 && !check6))
            return "Neither";
        if (check4)
            return checkIPv4(IP);
        else
            return checkIPv6(IP);
    }
};