
using namespace std;

class Solution {
public:
    int reverse(int x) {
		int y = 0;
		while (x != 0) {
            int remainder = x % 10;
			int next = y * 10 + remainder;
            if ((next - remainder) / 10 != y) {
                return 0;
            }
            y = next;
			x = x / 10;
		}
        return y;
    }
};
