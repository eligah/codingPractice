class Solution(object):
    def maxProfit(self, prices):
        if not prices:
            return 0
        prices.reverse()
        minval = [prices[-1]]
        maxval = [prices[0]]
        for idx, val in enumerate(prices[1:], 1):
            minval.append(min(minval[idx - 1], prices[len(prices)-idx-1]))
            maxval.append(max(maxval[idx - 1], prices[idx]))
        minval.reverse()
        vallist = list(map(lambda x, y: x - y, maxval, minval))
        return sum(vallist)


s = Solution()
a = s.maxProfit([7, 1, 5, 3, 6, 4])
print(a)
