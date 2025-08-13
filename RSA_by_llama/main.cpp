#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define LOWER_LIMIT 100000 // Minimum value for six-digit prime
#define UPPER_LIMIT 999999 // Maximum value for six-digit prime

// Function to check if a number is prime
bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Function to generate a random six-digit prime number
long long generate_random_prime() {
    long long prime;
    do {
        prime = rand() % (UPPER_LIMIT - LOWER_LIMIT + 1) + LOWER_LIMIT;
    } while (!is_prime(prime));
    return prime;
}

// Function to calculate the greatest common divisor of two numbers
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Modular exponentiation function to compute a^b mod n efficiently
long long pow_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Extended Euclidean algorithm to find the modular inverse
long long mod_inverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;

        m = a % m, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

// RSA encryption function
long long rsa_encrypt(long long message, long long e, long long n) {
    return pow_mod(message, e, n);
}

// RSA decryption function
long long rsa_decrypt(long long encrypted_message, long long d, long long n) {
    return pow_mod(encrypted_message, d, n);
}

int main() {
    srand(time(0));

    // Generate two large random six-digit prime numbers
    long long p = generate_random_prime();
    long long q = generate_random_prime();
    while (p == q) {  // Ensure p and q are different
        q = generate_random_prime();
    }

    // Calculate n (modulus) and phi(n)
    long long n = p * q;
    long long phi_n = (p - 1) * (q - 1);

    // Find e (public exponent) such that 1 < e < phi(n) and gcd(e, phi_n) = 1
    long long e = 3;
    while (gcd(e, phi_n) != 1) {
        e++;
    }

    // Calculate d (private exponent) as modular inverse of e mod phi(n)
    long long d = mod_inverse(e, phi_n);

    // Sample message to encrypt
    long long message = 123456;

    // Encrypt and decrypt the message
    long long encrypted_message = rsa_encrypt(message, e, n);
    long long decrypted_message = rsa_decrypt(encrypted_message, d, n);

    // Output results
    printf("Prime numbers p and q: %lld, %lld\n", p, q);
    printf("Modulus (n): %lld\n", n);
    printf("Euler's Totient (phi_n): %lld\n", phi_n);
    printf("Public Key (e, n): (%lld, %lld)\n", e, n);
    printf("Private Key (d, n): (%lld, %lld)\n", d, n);
    printf("Original Message: %lld\n", message);
    printf("Encrypted Message: %lld\n", encrypted_message);
    printf("Decrypted Message: %lld\n", decrypted_message);

    return 0;
}
