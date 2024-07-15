class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        unordered_set<int> check;
        for (int i : nums)
            check.insert(i);

        int longSequence = 0;

        for (int i : nums)
        {

            //finding the minimum of sequence
            if (!check.count(i - 1))
            {
                int curr = i;
                int currSequence = 1;

                //counting the numbers in sequence
                while (check.count(curr + 1))
                {
                    curr++;
                    currSequence++;
                }

                //getting the maximum of the sequences
                longSequence = max(longSequence, currSequence);
            }
        }

        return longSequence;
    }
};