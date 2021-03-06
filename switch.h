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
#include "quadrature.h"


inline void polynomial(fmpq_poly_t, const int);
inline void integrate(fmpq_t, const int);
inline void moments(fmpq_mat_t, const int);
inline void transcendental_factor(arb_t, const long);
inline long validate_roots(const acb_ptr, const long, const long, const int);
inline long validate_weights(const acb_ptr, const long, const long, const int);
inline void evaluate_weights_formula(acb_ptr, const acb_ptr, const int, long);


inline void polynomial(fmpq_poly_t Pn, const int n) {
#ifdef LEGENDRE
    legendre_polynomial(Pn, n);
#endif
#ifdef LAGUERRE
    laguerre_polynomial(Pn, n);
#endif
#ifdef HERMITEPRO
    hermite_polynomial_pro(Pn, n);
#endif
#ifdef HERMITE
    hermite_polynomial_phy(Pn, n);
#endif
#ifdef CHEBYSHEVT
    chebyshevt_polynomial(Pn, n);
#endif
#ifdef CHEBYSHEVU
    chebyshevu_polynomial(Pn, n);
#endif
}

inline void integrate(fmpq_t M, const int n) {
#ifdef LEGENDRE
    integrate_legendre(M, n);
#endif
#ifdef LAGUERRE
    integrate_laguerre(M, n);
#endif
#ifdef HERMITEPRO
    integrate_hermite_pro(M, n);
#endif
#ifdef HERMITE
    integrate_hermite_phy(M, n);
#endif
#ifdef CHEBYSHEVT
    integrate_chebyshevt(M, n);
#endif
#ifdef CHEBYSHEVU
    integrate_chebyshevu(M, n);
#endif
}

inline void moments(fmpq_mat_t M, const int n) {
#ifdef LEGENDRE
    moments_legendre(M, n);
#endif
#ifdef LAGUERRE
    moments_laguerre(M, n);
#endif
#ifdef HERMITEPRO
    moments_hermite_pro(M, n);
#endif
#ifdef HERMITE
    moments_hermite_phy(M, n);
#endif
#ifdef CHEBYSHEVT
    moments_chebyshevt(M, n);
#endif
#ifdef CHEBYSHEVU
    moments_chebyshevu(M, n);
#endif
}

inline void transcendental_factor(arb_t T, const long prec) {
#ifdef LEGENDRE
    transcendental_factor_legendre(T, prec);
#endif
#ifdef LAGUERRE
    transcendental_factor_laguerre(T, prec);
#endif
#ifdef HERMITEPRO
    transcendental_factor_hermite_pro(T, prec);
#endif
#ifdef HERMITE
    transcendental_factor_hermite_phy(T, prec);
#endif
#ifdef CHEBYSHEVT
    transcendental_factor_chebyshevt(T, prec);
#endif
#ifdef CHEBYSHEVU
    transcendental_factor_chebyshevu(T, prec);
#endif
}

inline long validate_roots(const acb_ptr roots,
                           const long n,
                           const long prec,
                           const int loglevel) {
#ifdef LEGENDRE
    return validate_real_interval_roots(roots, n, prec, loglevel);
#endif
#ifdef LAGUERRE
    return validate_real_nonnegative_roots(roots, n, prec, loglevel);
#endif
#ifdef HERMITEPRO
    return validate_real_roots(roots, n, prec, loglevel);
#endif
#ifdef HERMITE
    return validate_real_roots(roots, n, prec, loglevel);
#endif
#ifdef CHEBYSHEVT
    return validate_real_interval_roots(roots, n, prec, loglevel);
#endif
#ifdef CHEBYSHEVU
    return validate_real_interval_roots(roots, n, prec, loglevel);
#endif
    return 0;
}

inline long validate_weights(const acb_ptr weights,
                             const long n,
                             const long prec,
                             const int loglevel) {
    return validate_positive_weights(weights, n, prec, loglevel);
}

inline void evaluate_weights_formula(acb_ptr weights,
                                     const acb_ptr nodes,
                                     const int n,
                                     const long prec) {
#ifdef LEGENDRE
    evaluate_weights_formula_legendre(weights, nodes, n, prec);
#endif
#ifdef LAGUERRE
    evaluate_weights_formula_laguerre(weights, nodes, n, prec);
#endif
#ifdef HERMITEPRO
    evaluate_weights_formula_hermite_pro(weights, nodes, n, prec);
#endif
#ifdef HERMITE
    evaluate_weights_formula_hermite_phy(weights, nodes, n, prec);
#endif
#ifdef CHEBYSHEVT
    evaluate_weights_formula_chebyshevt(weights, nodes, n, prec);
#endif
#ifdef CHEBYSHEVU
    evaluate_weights_formula_chebyshevu(weights, nodes, n, prec);
#endif
    return;
}


#endif
