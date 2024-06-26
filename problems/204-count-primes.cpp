class Solution
{
public:
    int countPrimes(int n){
        vector<bool> isPrime(n);

        for (int i = 2; i < n; i++)
            isPrime[i] = true;

        /*Loop's ending condition is i * i < n instead of i < sqrt(n)
          to avoid repeatedly calling an expensive function sqrt()*/

        for (int i = 2; i * i < n; i++) {
            if (!isPrime[i]) continue;

            //marking all the multiples of prime numbers as false
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
        }

        int count = 0;

        for (int i = 2; i < n; i++)
            if (isPrime[i]) count++;

        return count;
    }
};