#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1:
 * @grid2: 
 *
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid1[i][j] += grid2[i][j];

}
