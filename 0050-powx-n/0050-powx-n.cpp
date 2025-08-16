class Solution {
public:
    double myPow(double base, int exponent) {
        long long longExponent = exponent;
        
        if (longExponent < 0) {
            base = 1 / base;
            longExponent = -longExponent;
        }

        double result = 1.0;
        
        while (longExponent > 0) {
            // If the exponent is odd, multiply the base with the result
            if (longExponent % 2 == 1) {
                result *= base;
            }
            
            // Square the base and halve the exponent in each step
            base *= base;
            longExponent /= 2;
        }
        
        return result;
    }
};