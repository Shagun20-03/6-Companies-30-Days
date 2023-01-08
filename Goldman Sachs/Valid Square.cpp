class Solution {
public:
    // function to calculate distance between two points
    double dist(vector<int> &p1, vector<int> &p2){
        return sqrt((p2[0]-p1[0])*(p2[0]-p1[0]) + (p2[1]-p1[1])*(p2[1]-p1[1]));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points={p1, p2, p3, p4};
        set<double> lengths;
        
        //from points vector
        for(int i=0;i<4;i++){
            for(int j=i+1;j<4;j++){
                double curr=dist(points[i], points[j]);
                //if there is some distance insert into set
                if(curr!=0)
                    lengths.insert(curr);
                //if distance is zero we got duplicate points
                else
                    return false;
            }
        }
        //as set contains unique elements we will be left with two values in set (one of side length and other diagnol length) if the side length of all the sides of rectangle is equal
        return lengths.size()==2;
    }
};
