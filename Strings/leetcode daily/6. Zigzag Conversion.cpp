class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        
        int n = int(s.size());
        int sections = ceil(n / (2 * numRows - 2.0));
        int numCols = sections * (numRows - 1);
        
        vector<vector<char>> matrix(numRows, vector<char>(numCols, ' '));
        
        int currRow = 0, currCol = 0;
        int i = 0;
        
        // Iterate in zig-zag pattern on matrix and fill it with string characters.
        while (i < n) {
            // Move down.
            while (currRow < numRows && i < n) {
                matrix[currRow][currCol] = s[i];
                currRow++;
                i++;
            }
            
            currRow -= 2;
            currCol++;
            
            // Move up (with moving right also).
            while (currRow > 0 && currCol < numCols && i < n) {
                matrix[currRow][currCol] = s[i];
                currRow--;
                currCol++;
                i++;
            }
        }
        
        string res;
        for (auto& row: matrix) {
            for (auto& character: row) {
                if (character != ' ') {
                    res += character;
                }
            }
        }
        
        return res;
    }
};