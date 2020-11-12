/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buyPrice;
        int sellPrice;
        for (int price : prices)
        {
            if ((priceStack.size() == 0) ||
                (price >= priceStack.top()))
            {
                priceStack.push(price);
            }
            else if (price < priceStack.top())
            {
                if (priceStack.size() <= 1)
                {
                    priceStack.pop();
                }
                else
                {
                    sellPrice = priceStack.top();
                    priceStack.pop();
                    do
                    {
                        buyPrice = priceStack.top();
                        priceStack.pop();
                    } while (priceStack.size() > 0);
                    maxAdd += (sellPrice - buyPrice);
                }
                priceStack.push(price);
            }
        }
        if (priceStack.size() > 1)
        {
            sellPrice = priceStack.top();
            priceStack.pop();
            do
            {
                buyPrice = priceStack.top();
                priceStack.pop();
            } while (priceStack.size() > 0);
            maxAdd += (sellPrice - buyPrice);
        }
        // 需要修改
        return maxAdd;
    }

private:
    stack<int> priceStack;
    int maxAdd;
};
// @lc code=end

int main(int argc, char **args)
{
    Solution solution;
    vector<int> intput = {7, 1, 5, 3, 6, 4};
    // vector<int> intput = {1, 2, 3, 4, 5};
    solution.maxProfit(intput);
}
