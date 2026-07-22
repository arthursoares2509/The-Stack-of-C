#include <stdio.h>
#include <math.h>

// --- 1. PROBABILITY & BAYES ---
// P(A|B) = P(B|A) * P(A) / P(B)
double bayes_theorem(double p_b_given_a, double p_a, double p_b) {
    return (p_b_given_a * p_a) / p_b;
}

// --- 2. DISTRIBUTIONS & RANDOM VARIABLES ---
// Binomial: P(X = k) = C(n,k) * p^k * (1-p)^(n-k)
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r;
    long long res = 1;
    for (int i = 1; i <= r; i++) res = res * (n - i + 1) / i;
    return res;
}

double binomial_pmf(int n, int k, double p) {
    return nCr(n, k) * pow(p, k) * pow(1.0 - p, n - k);
}

// Poisson: P(X = k) = (lambda^k * e^-lambda) / k!
double poisson_pmf(double lambda, int k) {
    double fact = 1.0;
    for (int i = 1; i <= k; i++) fact *= i;
    return (pow(lambda, k) * exp(-lambda)) / fact;
}

// Gaussian Standard Score: Z = (X - mu) / sigma
double z_score(double x, double mu, double sigma) {
    return (x - mu) / sigma;
}

// --- 3. DESCRIPTIVE & INFERENTIAL STATISTICS ---
typedef struct {
    double mean;
    double variance; // Sample variance (n - 1)
    double std_dev;
} SampleStats;

SampleStats compute_stats(const double *data, int n) {
    SampleStats s = {0.0, 0.0, 0.0};
    if (n <= 1) return s;

    // Mean
    double sum = 0.0;
    for (int i = 0; i < n; i++) sum += data[i];
    s.mean = sum / n;

    // Variance
    double sq_diff = 0.0;
    for (int i = 0; i < n; i++) sq_diff += (data[i] - s.mean) * (data[i] - s.mean);
    s.variance = sq_diff / (n - 1);
    s.std_dev = sqrt(s.variance);

    return s;
}

// Central Limit Theorem: Standard Error = sigma / sqrt(n)
double standard_error(double sigma, int n) {
    return sigma / sqrt((double)n);
}

// t-statistic = (x_bar - mu_0) / (s / sqrt(n))
double t_statistic(double sample_mean, double h0_mean, double sample_std, int n) {
    return (sample_mean - h0_mean) / (sample_std / sqrt((double)n));
}

int main(void) {
    // 1. Bayes Example
    double p_disease_given_test = bayes_theorem(0.99, 0.01, 0.05);

    // 2. Sample Data
    double dataset[] = {12.5, 14.2, 13.8, 15.1, 12.9, 16.0, 14.5};
    int n = sizeof(dataset) / sizeof(dataset[0]);
    SampleStats stats = compute_stats(dataset, n);

    // Output quick verification
    printf("Bayes P(A|B): %.4f\n", p_disease_given_test);
    printf("Binomial(n=10, k=3, p=0.5): %.4f\n", binomial_pmf(10, 3, 0.5));
    printf("Poisson(lambda=2.5, k=4): %.4f\n", poisson_pmf(2.5, 4));
    printf("Sample Mean: %.2f | Std Dev: %.2f\n", stats.mean, stats.std_dev);
    printf("t-stat (H0=13.0): %.4f\n", t_statistic(stats.mean, 13.0, stats.std_dev, n));

    return 0;
}