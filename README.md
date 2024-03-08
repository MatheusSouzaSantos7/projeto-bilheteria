# Projeto bilheteria
O porjeto bilheteria é um exercício dado na aula de Estrutura de Dados, do qual contém 0 seguinte enunciado:

## Enunciado
Projeto Bilheteria:
Um teatro possui 600 lugares dispostos em 15 fileiras com 40 poltronas cada.

Deseja-se um sistema de controle de ocupação que ofereça as seguintes opções, através de um seletor:

0.	Finalizar
1.	Reservar poltrona
2.	Mapa de ocupação
3.	Faturamento

A opção 1 deverá solicitar a informação da fileira e da poltrona. Os dados devem ser consistidos no sentido da garantia de serem válidos.
Caso o lugar esteja vago, efetuar a reserva e informar o usu�rio do sucesso da opera��o. Caso o lugar j� se encontre ocupado, alertar o usu�rio com uma mensagem.

A op��o 2 dever� gerar na tela um �mapa� de ocupa��o do teatro com uma legenda onde:

'.' representa lugar vago
'#' representa lugar ocupado
A opção 3 deverá apresentar na tela as seguintes informações:

Qtde de lugares ocupados: 	999
Valor da bilheteria: 		R$ 9999,99
Sabendo-se que:

- Fileiras 1 a 5:	R$ 50,00
- Fileiras 6 a 10:	R$ 30,00
- Fileiras 11 a 15:	R$ 15,00

## Variáveis blobais
- const int num_fileiras = 15; // Contém o número de fileiras no total.
- const int poltronas_por_fileira = 40; // Contém o número de poltronas totais em cada fileira.
- bool ocupacao_teatro[num_fileiras][poltronas_por_fileira] = {false} // Vetor da qual se cria a matriz dos assentos. Todos os assentos se iniciam como vazios.

## explicação de cada método utilizado
### void mostrarMapaDeOcupacao()
Esse método tem como objetivo pegar a matriz de variáveis booleanas 
Ao pegar essa matriz, da qual todos os assentos se iniciam como vazias, a função percorre toda a matriz, sinalizando onde os valores "true" são poltronas ocupadas e os valores "false" são poltronas vazias.
'.' Indica que está vazio, enquanto '#' indica que está ocupado.

### void reservarPoltrona()
Essa função tem como objetivo reservar a poltrona, ela contém como input a fileira e a poltrona desejada, verifica se a poltrona está ocupada ou se é uma poltrona válida, e marca a poltrona escolhida como ocupada. Ela também atualiza a quantidade de plotronas ocupadas.

### MostrarFaturamento
Calcula o faturamento com base nas poltronas escolhidas, e mostra a quantidade de poltronas ocupadas, além de mostrar o total do valor obtido.

### int main()
É a função principal, que é onde o programa se inicia.