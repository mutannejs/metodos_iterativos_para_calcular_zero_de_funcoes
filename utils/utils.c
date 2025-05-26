#include "utils.h"

void setinitialvars (char name[], function_type *f, function_type *phiMPF, function_type *derivative, value_type *a, value_type *b, value_type *episilon) {
    int option;

    printf("Para qual função você deseja usar o método %s\n", name);
    printf("1: %s\n", f1_formula);
    printf("2: %s\n", f2_formula);
    printf("3: %s\n", f3_formula);
    printf("Opção: ");
    scanf("%d", &option);
    printf("\n");

    switch (option) {
        case 1:
            *a = range1[0];
            *b = range1[1];
            if (f) *f = f1;
            if (phiMPF) *phiMPF = f1_phi;
            if (derivative) *derivative = f1_derivative;
            *episilon = episilon1;
            break;
        case 2:
            *a = range2[0];
            *b = range2[1];
            if (f) *f = f2;
            if (phiMPF) *phiMPF = f2_phi;
            if (derivative) *derivative = f2_derivative;
            *episilon = episilon2;
            break;
        case 3:
            *a = range3[0];
            *b = range3[1];
            if (f) *f = f3;
            if (phiMPF) *phiMPF = f3_phi;
            if (derivative) *derivative = f3_derivative;
            *episilon = episilon3;
            break;
        default:
            exit(1);
    }
}
