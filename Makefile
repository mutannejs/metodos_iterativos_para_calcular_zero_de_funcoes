all: dir bis pon new sec

dir:
	@ if [ ! -d build/ ]; then mkdir build; fi

bis: methods/bisseccao.c
	@ gcc -o build/bisseccao methods/bisseccao.c example_functions/functions.c utils/utils.c -lm

pon: methods/ponto_fixo.c
	@ gcc -o build/ponto_fixo methods/ponto_fixo.c example_functions/functions.c utils/utils.c -lm

new: methods/newton_raphson.c
	@ gcc -o build/newton_raphson methods/newton_raphson.c example_functions/functions.c utils/utils.c -lm

sec: methods/secante.c
	@ gcc -o build/secante methods/secante.c example_functions/functions.c utils/utils.c -lm
