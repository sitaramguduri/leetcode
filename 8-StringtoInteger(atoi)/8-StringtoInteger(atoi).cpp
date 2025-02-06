class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long long result = 0; // Using long long to handle overflow during calculations
        int sign = 1; // 1 for positive, -1 for negative
        
        // 1. Skip leading whitespace
        while (i < n && isspace(s[i])) {
            i++;
        }

        // 2. Handle optional sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Process digits and build the number
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // 4. Check for overflow before multiplying by 10
            if (result > (LLONG_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        // 5. Apply sign and return clamped result
        result *= sign;
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;
        return static_cast<int>(result);
    }
};