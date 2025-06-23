class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum = 0;
        int minimum = INT_MAX;
        int maximum = INT_MIN;

        // Find total bananas and the max pile size
        for (int i = 0; i < piles.size(); i++) {
            sum += piles[i];
            minimum = min(piles[i], minimum);
            maximum = max(piles[i], maximum); // ✅ use max here
        }

        int s = sum/h;            // ✅ minimum speed should be 1
        int e = maximum;      // ✅ max speed = largest pile
        int ans = e;
        if(s==0) {
            s=1;
        }

        while (s <= e) {
            int mid = s + (e - s) / 2;
            long long count = 0;

            for (int i = 0; i < piles.size(); i++) {
                count += piles[i] / mid;
                if (piles[i] % mid) count++; // ✅ for odd ones
            }

            if (count > h) {
                s = mid + 1; // \U0001f422 Too slow, increase speed
            } else {
                ans = mid;   // ✅ Possible answer, try to minimize
                e = mid - 1;
            }
        }

        return ans;
    }
};
