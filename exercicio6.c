/*6) Um motorista acaba de retornar de um feriado prolongado. Em cada parada de reabastecimento ele
registrou a leitura de seu odômetro, a quantidade de gasolina comprada (suponha que ele tenha enchido o
tanque cada vez) e o preço pago. Além disso, suponha também que ele tenha enchido o tanque antes de
partir e imediatamente após retornar. Escreva um programa em C para ler, em primeiro lugar, o número total
de reabastecimentos feitos (incluindo o primeiro e o último) e, a seguir, os dados relativos à compra de
gasolina e calcular : */

/*a) a quilometragem obtida por litro de gasolina entre cada par de paradas de reabastecimento;
b) a quilometragem obtida por litro de gasolina em toda a viagem
c) custo do combustível por quilometro rodado em toda a viagem */

#include <stdio.h>

int main(){
    float kilometros, paradas, reabastecimentos, litros ,kilometrosTotal=0;
    float precoGasolina, precoGasolinaTotal = 0;
    printf("Digite o numero de vezes reabastecidas: \n");
    scanf("%f", &reabastecimentos);

    for (int i = 1; i<=reabastecimentos; i++){
        printf("Digite o preço da gasolina: \n");
        scanf("%f", &precoGasolina);
        precoGasolinaTotal += precoGasolina;

        printf("Digite a quantidade de litros: \n");
        scanf("%f", &litros);

        printf("Digite o numero de km rodados: \n");
        scanf("%f", &kilometros);
        kilometrosTotal += kilometros;
        printf("kilometragem é: %f\n", kilometros/litros);

}
printf("o custo do combustível por quilometro rodado em toda a viagem é %f\n", kilometrosTotal/precoGasolinaTotal);
}
