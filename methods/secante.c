#include <stdio.h>
#include "../example_functions/functions.h"
#include "../utils/utils.h"

value_type phiSec (function_type f, value_type x_k, value_type x_kminus1) {
    return (x_kminus1 * f(x_k) - x_k * f(x_kminus1)) / (f(x_k) - f(x_kminus1));
}

void showinteraction (int interactions, value_type x_kminus1, value_type x_k, value_type fx) {
    printf("%d:\t", interactions);
    printf("x_k = %.12llf;\t", x_k);
    printf("x_kminus1 = %.12llf;\t", x_kminus1);
    printf("fx = %.12llf\n", fx);
}

int stopcriteria (function_type f, value_type episilon, value_type x_k, value_type x_kminus1, int interactions) {
    return fabs(f(x_k)) < episilon || fabs(x_k - x_kminus1) < episilon && interactions > MAX_INTERACTIONS;
}

int main () {
    function_type f;
    value_type a, b, episilon;
    value_type x_k, x_kminus1, x_temp, fx;
    int interactions;

    /* Pergunta ao usuário qual das três funções disponíveis ele quer usar de exemplo.
       Baseado na opção escolhida, é atribuído valores iniciais para as seguintes variáveis:
          f: um ponteiro para a implementação da função escolhida
          a e b: extremos do intervalo onde a raíz conhecida se encontra
          episilon: o valor de épisilon para a função escolhida (varia dependendo do exercício)
       O segundo e terceiro argumentos são usados para setar a função phi (própria para o MPF)
       e a derivada de f, porém, como ambas não são usadas nesse método, é passada a constante
       nula (não recebe valor nenhum)
    */
    setinitialvars("da secante", &f, NULL, NULL, &a, &b, &episilon);

    /* interactions: é um contador que informa a iteração atual
       fa: resultado de f(a)
       fb: resultado de f(b)
    */
    interactions = 0;
    x_k = b;
    x_kminus1 = a;

    /* verifica se fx0 ou fx1 já é raíz aproximada da função */
    fx = f(x_kminus1);
    if (fabs(fx) < episilon) return 0;
    fx = f(x_k);
    if (fabs(fx) < episilon || fabs(x_k - x_kminus1) < episilon) return 0;

    /* exibe na tela os valores passados como argumento */
    showinteraction(interactions, x_k, x_kminus1, fx);

    /* o corpo do método da secante */
    do {
        x_temp = x_k;
        x_k = phiSec(f, x_k, x_kminus1);
        x_kminus1 = x_temp;

        fx = f(x_k);

        interactions += 1;
        showinteraction(interactions, x_k, x_kminus1, fx);
    } while (!stopcriteria(f, episilon, x_k, x_kminus1, interactions));

    printf("\n(%d iterações) x aproximado é %.12llf\n", interactions, x_k);

    return 0;
}
