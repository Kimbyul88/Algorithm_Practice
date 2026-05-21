#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    set<int> s(nums.begin(), nums.end());

    int kind = s.size();
    int limit = nums.size() / 2;

    return min(kind, limit);
}