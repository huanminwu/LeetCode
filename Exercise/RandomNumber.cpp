/// <summary>
/// The class is used to generate a series of random integer so we can used it in algorithm
/// </summary>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "RandomNumber.h"

/// <summary>
/// Initializes the random seed, do it once at very beginning
/// </summary>
void RandomNumber::Initialize()
{
    srand((unsigned int)time(NULL));
}

/// <summary>
/// Gets the random number. which is from 0 to max_value -1
/// </summary>
/// <param name="max_value">The maximum value.</param>
/// <returns></returns>
int RandomNumber::GetRandomNumber(int max_value)
{
    return rand() % max_value;
};
