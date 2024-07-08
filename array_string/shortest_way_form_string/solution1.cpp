#include <string>
using namespace std;

class Solution {
    public:
        int shortestWay(string source, string target) {
            int numSubsequences = 0;
            string remaining = target;
            string subsequence;
            while(remaining.length() > 0){
                subsequence = "";
                int i = 0;
                int j = 0;
                while(i < source.length() && j < remaining.length()){
                    if(source[i] == remaining[j]){
                        subsequence += remaining[j];
                        j++;
                    }
                    i++;
                }
                if(subsequence.length()==0) return -1;
                numSubsequences++;
                remaining = remaining.substr(subsequence.length());
            }
            return numSubsequences;
        }
};