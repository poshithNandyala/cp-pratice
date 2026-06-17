# Sieve of Eratosthenes

### Complete Template (Easy to Copy)

```cpp
vector<bool> isPrime;
vector<int> primes;

void sieve(int n) {
    isPrime.assign(n + 1, true);

    if (n >= 0) isPrime[0] = false;
    if (n >= 1) isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    primes.clear();
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}
```

### Usage Examples

```cpp
int main() {
    sieve(1e6); // Generate primes up to 10^6

    // 1. Check if a number 'x' is prime
    if (isPrime[x]) {
        // x is prime
    }

    // 2. Access the k-th prime (0-indexed)
    cout << primes[k] << '\n';

    // 3. Iterate over all generated primes
    for (int p : primes) {
        cout << p << " ";
    }
}
```
