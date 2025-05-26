/**
 * Implementação das três funções de exemplo, junto com o valor de épisilon
 * e do intervalo onde a raíz conhecida de cada função se encontra
 */

#include "functions.h"

 /**
 * f(x) = x^3 - 9x + 3
 * f'(x) = 3x^2 - 9
 * phi(x) = (x^3)/9 + 1/3
 */
const char f1_formula[] = "f(x) = x^3 - 9x + 3";

const value_type episilon1 = 0.000001;

const value_type range1[2] = {0, 1};

value_type f1 (value_type x) {
    return pow(x, 3) - 9*x + 3;
}

value_type f1_derivative (value_type x) {
    return 3*pow(x, 2) - 9;
}

value_type f1_phi (value_type x) {
    return pow(x, 3)/9 + 1/3;
}

/**
 * f(x) = 2x^3 - 20x - 13
 * f'(x) = 6x - 20
 * phi(x) = x^3/10 - 13/20
 */
const char f2_formula[] = "f(x) = 2x^3 - 20x - 13";

const value_type episilon2 = 0.000001;

const value_type range2[2] = {3, 4};

value_type f2 (value_type x) {
    return 2*pow(x, 3) - 20*x - 13;
}

value_type f2_derivative (value_type x) {
    return 6*x - 20;
}

value_type f2_phi (value_type x) {
    return pow(x, 3)/10 - 13/20;
}


/**
 * f(x) = xlog(x) - 1
 * f'(x) = log(x) + 1
 * phi(x) = x - 1.3 * (xlog(x) - 1)
 */
const char f3_formula[] = "f(x) = xlog(x) - 1";

const value_type episilon3 = 0.000001;

const value_type range3[2] = {2, 3};

value_type f3 (value_type x) {
    return x*log(x) - 1;
}

value_type f3_derivative (value_type x) {
    return log(x) + 1;
}

value_type f3_phi (value_type x) {
    return x - 1.3*f3(x);
}
