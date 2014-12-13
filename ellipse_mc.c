/* 
 * Monte Carlo calculation Pi
 */
#include <stdio.h>
#include <math.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_statistics.h>
     
/* mc_pi.c */
double mc_pi (long m, gsl_rng *r);

#define POINTS 524288     /* 2^19, initial number of random points to generate */
#define NEXP 64           /* number of experiments for each value of points */
#define M 11              /* number of different points values */

int main(void) {
    gsl_rng *r;
    int i;
    float x1,x2,x3,x4,x5;
    float x;
    int n = 9;
    unsigned long seed = 1UL;
    long p = POINTS;
     
    /* allocate random number generator */
    r = gsl_rng_alloc(gsl_rng_taus2);

    /* seed the random number generator */
    gsl_rng_set(r, seed);

    for (i = 1; i <= n; i++) {
        x1 = gsl_rng_uniform(r);
        x2 = gsl_rng_uniform(r);
        x3 = gsl_rng_uniform(r);
        x4 = gsl_rng_uniform(r);
        x5 = gsl_rng_uniform(r);
        printf("%f %f %f %f %f\n",x1,x2,x3,x4,x5);
        x = pow(x1,i)+pow(x2,i)+pow(x3,i)+pow(x4,i)+pow(x5,i);
        printf("%f\n",x);
        p *= 2;
    }

    gsl_rng_free(r);

    return(0);
}
