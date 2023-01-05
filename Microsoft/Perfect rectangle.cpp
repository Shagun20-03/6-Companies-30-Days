class Solution {
    inline bool insert_corner(unordered_map<int, unordered_map<int, int>>& corner_cnt, int x, int y, int pos) {
    int& m = corner_cnt[x][y];
    if (m & pos) return false;
    m |= pos;
    return true;
}
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<int, unordered_map<int, int>> corner_cnt;
        int minx=INT_MAX, maxx=INT_MIN, miny=INT_MAX, maxy=INT_MIN;
        
        for(auto &rect:rectangles) {
            minx=min(minx, rect[0]);
            maxx=max(maxx, rect[2]);
            miny=min(miny, rect[1]);
            maxy=max(maxy, rect[3]);
            
            if(!insert_corner(corner_cnt, rect[0], rect[1], 1))
                return false;
            if(!insert_corner(corner_cnt, rect[2], rect[1], 2))
                return false;
            if(!insert_corner(corner_cnt, rect[0], rect[3], 4))
                return false;
            if(!insert_corner(corner_cnt, rect[2], rect[3], 8))
                return false;
        }
        //step2: checking
        bool valid_corner[16] = {false};
        bool valid_interior[16] = {false};
        valid_corner[1] = valid_corner[2] = valid_corner[4] = valid_corner[8] = true;
        valid_interior[3] = valid_interior[5] = valid_interior[10] = valid_interior[12] = valid_interior[15] = true;
        
        for (auto itx = corner_cnt.begin(); itx != corner_cnt.end(); ++itx) {
            int x = itx->first;
            for (auto ity = itx->second.begin(); ity != itx->second.end(); ++ity) {
                int y = ity->first;
                int mask = ity->second;
                if (((x != minx && x != maxx) || (y != miny && y != maxy)) && !valid_interior[mask]) 
                    return false;
            }
        }
        return true;
    }
};
