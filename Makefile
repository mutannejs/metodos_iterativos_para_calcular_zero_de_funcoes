all: dir bis pon new sec

dir:
	@ if [ ! -d build/ ]; then mkdir build; fi

bis: methods/bisseccao.c
	@ gcc -o build/bis methods/bisseccao.c example_functions//functions.c utils/utils.c -lm

pon: methods/ponto_fixo.c
	@ gcc -o build/pon methods/ponto_fixo.c example_functions//functions.c utils/utils.c -lm

new: methods/newton_raphson.c
	@ gcc -o build/new methods/newton_raphson.c example_functions//functions.c utils/utils.c -lm

sec: methods/secante.c
	@ gcc -o build/sec methods/secante.c example_functions//functions.c utils/utils.c -lm
