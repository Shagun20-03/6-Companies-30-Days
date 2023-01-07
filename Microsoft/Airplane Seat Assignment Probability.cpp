class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1)
            return 1.0;
        //for nth person he has two choice his nth seat or 1st seat who has lost his ticket becuase 1st seat is vacant
        return 0.5;
    }
};
