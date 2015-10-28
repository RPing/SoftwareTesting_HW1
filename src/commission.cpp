#include "commission.h"

float commission(int lock, int stock, int barrel)
{
    float sales;
    float commission;
    if (lock == -1)
        return 0.0f;
    else if (lock < 1 || lock > 70)
        return -1.0f;
    if (stock < 1 || stock > 80)
        return -1.0f;
    if (barrel < 1 || barrel > 90)
        return -1.0f;
    sales = lock * 45.0f + stock * 30.0f + barrel * 25.0f;
    if (sales < 1000)
        commission = sales * 0.1f;
    else if (sales < 1800) {
        commission = 1000.0 * 0.1f;
        commission += (sales - 1000.0f) * 0.15f;
    }
    else {
        commission = 1000.0 * 0.1f;
        commission += 800.0 * 0.15f;
        commission += (sales - 1800.0f) * 0.2f;
    }
    return commission;
}
