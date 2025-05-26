#include <stdio.h>
#include "../example_functions/functions.h"
#include "../utils/utils.h"

void showinteraction (int interactions, value_type x, value_type fx) {
    printf("%d:\t", interactions);
    printf("x = %.12llf;\t", x);
    printf("fx = %.12llf\n", fx);
}

int stopcriteria (function_type f, value_type episilon, value_type x_k, value_type x_kminus1, int interactions) {
    return fabs(x_k - x_kminus1) < episilon || fabs(f(x_k)) < episilon || interactions > MAX_INTERACTIONS;
}

int main () {
    function_type f, phiMPF;
    value_type a, b, episilon;
    value_type x_k, x_kminus1, fx;
    int interactions;

    /* Pergunta ao usuário qual das três funções disponíveis ele quer usar de exemplo.
       Baseado na opção escolhida, é atribuído valores iniciais para as seguintes variáveis:
          f: um ponteiro para a implementação da função escolhida
          phiMPF: um ponteiro para a implementação da função phi da função escolhida
          a e b: extremos do intervalo onde a raíz conhecida se encontra
          episilon: o valor de épisilon para a função escolhida (varia dependendo do exercício)
       O terceiro argumento é usado para setar a derivada de f, porém, como ela não é usada
       nesse método, é passada a constante nula (não recebe valor nenhum)
    */
    setinitialvars("do ponto fixo", &f, &phiMPF, NULL, &a, &b, &episilon);

    /* interactions: é um contador que informa a iteração atual
       fa: resultado de f(a)
       fb: resultado de f(b)
    */
    interactions = 0;
    x_k = (b + a) / 2;
    fx = f(x_k);

    if (fabs(fx) < episilon) return 0;

    /* o corpo do método do ponto fixo */
    do {
        /* exibe na tela os valores passados como argumento */
        showinteraction(interactions, x_k, fx);

        x_kminus1 = x_k;
        x_k = phiMPF(x_kminus1);
        fx = f(x_k);

        interactions += 1;
    } while (!stopcriteria(f, episilon, x_k, x_kminus1, interactions));

    showinteraction(interactions, x_k, fx);
    printf("\n(%d iterações) x aproximado é %.12llf\n", interactions, x_k);

    return 0;
}
