/*  Author: R. Bourquin
 *  Copyright: (C) 2014 R. Bourquin
 *  License: GNU GPL v2 or above
 *
 *  A library of helper functions to search for
 *  Kronrod extensions of Gauss quadrature rules.
 */

#ifndef __HH__switch
#define __HH__switch

#include "flint/flint.h"
#include "flint/fmpq.h"

#include "polynomials.h"
#include "numerics.h"

inline void polynomial(fmpq_poly_t Pn, const int n);
inline void integrate(fmpq_t M, const int n);
inline long validate_roots(const fmpcb_ptr, const long, const long, const int);
inline long validate_weights(const fmpcb_ptr, const long, const long, const int);


inline void polynomial(fmpq_poly_t Pn, const int n) {
    /*hermite_polynomial_pro(Pn, n);*/
    legendre_polynomial(Pn, n);
}

inline void integrate(fmpq_t M, const int n) {
    /*integrate_hermite_pro(M, n);*/
    integrate_legendre(M, n);
}

inline long validate_roots(const fmpcb_ptr roots,
                           const long n,
                           const long prec,
                           const int loglevel) {
    /*return validate_real_roots(roots, n, prec, loglevel);*/
    /*return validate_real_nonnegative_roots(roots, n, prec, loglevel);*/
    return validate_real_interval_roots(roots, n, prec, loglevel);
}

inline long validate_weights(const fmpcb_ptr weights,
                             const long n,
                             const long prec,
                             const int loglevel) {
    return validate_positive_weights(weights, n, prec, loglevel);
}

#endif
