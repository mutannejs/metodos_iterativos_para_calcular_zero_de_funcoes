/**
 * Headers dos métodos e constantes usadas na implementação das funções de exemplo
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <math.h>

typedef long double value_type;

typedef value_type (* function_type)(value_type x);

#define MAX_INTERACTIONS 30

extern const char f1_formula[];

extern const value_type episilon1;

extern const value_type range1[2];

value_type f1 (value_type x);

value_type f1_derivative (value_type x);

value_type f1_phi (value_type x);

extern const char f2_formula[];

extern const value_type episilon2;

extern const value_type range2[2];

value_type f2 (value_type x);

value_type f2_derivative (value_type x);

value_type f2_phi (value_type x);

extern const char f3_formula[];

extern const value_type episilon3;

extern const value_type range3[2];

value_type f3 (value_type x);

value_type f3_derivative (value_type x);

value_type f3_phi (value_type x);


#endif /* FUNCTIONS_H */
