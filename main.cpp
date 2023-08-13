
#include <iomanip>
#include <random>
using namespace std;

int32_t g_Val1 = 2;
int32_t g_Val2 = 100;

extern "C" int32_t CalcZ_(int32_t* z, const int8_t* x, const int16_t* y, int32_t n);

void Init(int8_t* x, int16_t* y, int32_t n);
int32_t CalcZ(int32_t* z, const int8_t* x, const int16_t* y, int32_t n);

void Init(int8_t* x, int16_t* y, int32_t n) {
    unsigned int seed = 7;
    uniform_int_distribution<> dist(-128, 127);
		mt19937 rng(seed);

    for (int32_t i = 0; i < n; i++) {
        x[i] = static_cast<int8_t>(dist(rng));
        y[i] = static_cast<int16_t>(dist(rng));
    }
}

int32_t CalcZ(int32_t* z, const int8_t* x, const int16_t* y, int32_t n) {
    int32_t sum = 0;
    for (int32_t i = 0; i < n; i++) {
        int32_t temp;
        if (x[i] < 0)
            temp = y[i] * g_Val1;
        else
            temp = y[i] * g_Val2;
        sum += temp;
        z[i] = temp;
    }
    return sum;
}

int main() {
    const int32_t n = 12;
    int8_t x[n];
    int16_t y[n];
    int32_t z1[n], z2[n];
    Init(x, y, n);
    int32_t sum_z1 = CalcZ(z1, x, y, n);
    int32_t sum_z2 = CalcZ_(z2, x, y, n);

    return 0;
}
