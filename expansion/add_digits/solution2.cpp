class Solution {
// Any number where the digits add up to 9 is always divisible by 9.
// Therefore, the digital root for any number divisible by 9 is always 9.
// The digital root for 0 is always 0.
// For any number that isn't 0 and isn't divisible by 9, the root will always be n % 9, where n is the given number.
// This is because the difference between the given number and the nearest number that is divisible by 9 will always be a multiple of 9, and therefore have a digital root of 9.

public:
    int addDigits(int num) {
        if(num==0) return 0;
        return (num%9==0)? 9 : num%9;
    }
};