#include <stdio.h>
#include "../example_functions/functions.h"
#include "../utils/utils.h"

void showinteraction (int interactions, value_type fa, value_type fb, value_type x, value_type fx, value_type bminusa) {
    printf("%d:\t", interactions);
    printf("x = %.12llf;\t", x);
    printf("f(x) = %.12llf;\t", fx);
    printf("b-a = %.12llf\n", bminusa);
}

int stopcriteria (value_type a, value_type b, value_type episilon, int interactions) {
    return fabs(b - a) < episilon || interactions > MAX_INTERACTIONS;
}

int main () {
    function_type f;
    value_type a, b, episilon;
    value_type x, fx, fa, fb;
    int interactions;

    /* Pergunta ao usuário qual das três funções disponíveis ele quer usar de exemplo.
       Baseado na opção escolhida, é atribuído valores iniciais para as seguintes variáveis:
          f: um ponteiro para a implementação da função escolhida
          a e b: extremos do intervalo onde a raíz conhecida se encontra
          episilon: o valor de épisilon para a função escolhida (varia dependendo do exercício)
       O primeiro argumento é o nome do método
       O segundo e terceiro argumentos são usados para setar a função phi (própria para o MPF)
       e a derivada de f, porém, como ambas não são usadas nesse método, é passada a constante
       nula (não recebe valor nenhum)
    */
    setinitialvars("da bissecção", &f, NULL, NULL, &a, &b, &episilon);

    /* interactions: é um contador que informa a iteração atual
       fa: resultado de f(a)
       fb: resultado de f(b)
    */
    interactions = 0;
    fa = f(a);
    fb = f(b);

    /* o corpo do método da bissecção */
    do {
        x = (a + b) / 2;

        fx = f(x);

        if (fa * fx > 0) {
            a = x;
            fa = fx;
        } else {
            b = x;
            fb = fx;
        }

        interactions += 1;

        /* exibe na tela os valores passados como argumento */
        showinteraction(interactions, fa, fb, x, fx, b - a);
    } while (!stopcriteria(a, b, episilon, interactions));

    printf("\n(%d iterações) x aproximado é %.12llf\n", interactions, x);

    return 0;
}
