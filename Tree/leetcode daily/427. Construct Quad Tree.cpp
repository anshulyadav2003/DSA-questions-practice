/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    // Check if all elements in the quadrant are the same
    bool areSame(vector<vector<int>>& grid, int r1, int r2, int c1, int c2)
    {
        for(int i=r1; i<=r2; i++){
            for(int j=c1; j<=c2; j++){
                if(grid[i][j] != grid[r1][c1])
                    return false;
            }
        }
        return true;
    }

    Node* solve(vector<vector<int>>& grid, int r1, int r2, int c1, int c2, int n)
    {
        if(r1>r2 || c1>c2)  return NULL;

        bool isLeaf = areSame(grid,r1,r2,c1,c2);
        int val = grid[r1][c1];
        
        // if isLeaf = TRUE, then all four children are null
        if(isLeaf){
            return new Node(val,isLeaf);
        }
        
        int midR = (r1+r2)/2, midC = (c1+c2)/2;
        Node* topLeft = solve(grid,r1,midR,c1,midC,n);
        Node* topRight = solve(grid,r1,midR,midC+1,c2,n);
        Node* bottomLeft = solve(grid,midR+1,r2,c1,midC,n);
        Node* bottomRight = solve(grid,midR+1,r2,midC+1,c2,n);
        return new Node(val,isLeaf,topLeft,topRight,bottomLeft,bottomRight);
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        int r1=0, r2=n-1, c1=0, c2=n-1;
        return solve(grid,r1,r2,c1,c2,n);
    }
};