#include "core/system.h"
#include <random>

int64_t System::GenerateNumber(int64_t minimum, int64_t maximum)
{
    using namespace std;
    random_device device;
    mt19937_64 engine(device());
    uniform_int_distribution<int> dist(minimum, maximum);
    return dist(engine);
}