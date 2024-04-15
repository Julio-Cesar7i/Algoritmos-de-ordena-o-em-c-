Repositório de Algoritmos de Ordenação em C++
Este repositório contém implementações de seis algoritmos de ordenação diferentes em C++: InsertionSort, QuickSort, SelectionSort (classificação por seleção), BubbleSort (classificação por bolha), ShellSort (classificação por cascas) e MergeSort (classificação por intercalação).

1. InsertionSort (Classificação por Inserção)
O InsertionSort classifica uma matriz de inteiros no local (std::vector<int>& arr).

Explicação:
- A função insertionSort recebe um vetor de inteiros (arr) como entrada.
- A variável n armazena o tamanho do vetor.
- O loop externo itera do segundo elemento (i = 1) até o final do vetor (i < n).
- A variável key armazena o valor do elemento atual (arr[i]).
- O loop interno (while) itera para trás a partir do elemento anterior (j = i - 1) até encontrar a posição correta para a chave.
- Se o elemento no índice anterior (arr[j]) for maior que a chave, ele é deslocado uma posição para frente (arr[j + 1] = arr[j]).
- A variável j é decrementada para continuar verificando os elementos anteriores.
- Uma vez que a posição correta é encontrada, a chave é inserida naquele índice (arr[j + 1] = key).
- 
2. QuickSort (Classificação Rápida)
O QuickSort classifica uma matriz de inteiros no local (vector<int> &arr).

Explicação:
- A função quickSort recebe um vetor de inteiros (arr), o índice inicial (baixo) e o índice final (alto) como entrada.
- Caso base: Se o índice inicial for maior ou igual ao índice final, significa que a submatriz possui um ou zero elementos, portanto já está ordenada.
- A variável pivo armazena o elemento pivô, que é escolhido como o elemento do meio ((baixo + alto) / 2).
- As variáveis i e j são usadas para particionar a matriz.
- O loop while continua até que i e j se cruzem.
- O loop interno do-while para i incrementa i até encontrar um elemento maior que o pivo.
- O loop interno do-while para j decrementa j até encontrar um elemento menor que o pivo.
- Se i e j não se cruzaram, os elementos nesses índices são trocados (swap(arr[i], arr[j])).
- A função quickSort é chamada recursivamente para as submatrizes antes e depois do pivô (quickSort(arr, baixo, j) e quickSort(arr, j + 1, alto)).

3. SelectionSort (Classificação por Seleção)
O SelectionSort classifica uma matriz de inteiros no local (std::vector<int>& arr).

Explicação:
- A função selectionSort recebe um vetor de inteiros (arr) como entrada.
- A variável n armazena o tamanho do vetor.
- O loop externo itera do primeiro elemento (i = 0) ao penúltimo elemento (i < n-1) do vetor.
- A variável min_idx armazena o índice do elemento mínimo atual. É inicializado com o índice atual (i).
- O loop interno (for) itera do próximo elemento (j = i+1) até o final do vetor.
- Se um elemento no índice j for menor que o elemento mínimo atual (arr[j] < arr[min_idx]), o min_idx é atualizado para j.
- Após o loop interno, o elemento no índice mínimo (arr[min_idx]) é trocado com o elemento no índice atual (i) usando std::swap.

4. BubbleSort (Classificação por Bolha)
Como observado anteriormente, o código fornecido para bubbleSort tinha o mesmo nome da função de selectionSort. Vamos corrigi-lo aqui e explicar o BubbleSort:

Explicação:
- O BubbleSort itera através do vetor repetidamente, compara elementos adjacentes e os troca se estiverem na ordem incorreta.
- Os elementos maiores vão "subindo" para o final do vetor a cada iteração.
- A função bubbleSort (corrigida para o nome correto) recebe um vetor de inteiros (std::vector<int>& arr) como entrada.
- Variáveis n armazena o tamanho do vetor.
- O loop externo (for) executa n-1 iterações (pois a comparação é feita com o elemento seguinte).
- A variável trocou é usada para saber se houve alguma troca na iteração atual. Se não houver troca, significa que o vetor já está ordenado.
- O loop interno (for) itera de 0 até n-2 comparando elementos adjacentes.
- Se o elemento atual (arr[j]) for maior que o próximo (arr[j + 1]), eles são trocados usando std::swap.
- A variável trocou é marcada como verdadeira para indicar que houve troca.

5. MergeSort (Classificação por Intercalação)
O MergeSort classifica um vetor de inteiros dividindo-o recursivamente em subvetores menores, ordenando esses subvetores e então intercalando-os de volta em um vetor ordenado.

Explicação:
- A função mergeSort recebe um vetor de inteiros (arr), o índice inicial (l) e o índice final (r) como entrada.
- Caso base: Se o índice inicial for maior ou igual ao índice final, significa que o subvetor tem zero ou um elemento, portanto já está ordenado.
- O índice do meio (m) é calculado como o ponto médio do subvetor (m = l + (r - l) / 2).
- A função mergeSort é chamada recursivamente para as metades esquerda (mergeSort(arr, l, m)) e direita (mergeSort(arr, m + 1, r)) do vetor.
- A função merge junta as metades esquerda e direita ordenadas do vetor em um único vetor ordenado.
- A função merge recebe o vetor (arr), os índices inicial (l), do meio (m) e final (r) como entrada.
- Ele cria arrays temporários L e R para armazenar as metades esquerda e direita do vetor original.
- Ele copia os elementos das metades esquerda e direita para os arrays temporários L e R.
- Ele então mescla ordenadamente os elementos de volta para o vetor original (arr) comparando os elementos de L e R e copiando o menor elemento para arr.
- Esse processo continua até que todos os elementos de L ou R sejam copiados para arr.
- Este código fornece implementações para seis algoritmos de ordenação comuns em C++. Você pode usá-lo para comparar a eficiência e o tempo de execução desses algoritmos para diferentes tamanhos de vetor.

6. ShellSort (Classificação por Cascas)
O ShellSort é uma variação do InsertionSort que usa incrementos decrescentes para mover elementos para suas posições ordenadas.

Explicação:
- A função shell_sort recebe um vetor de inteiros (arr) e o tamanho do vetor (n) como entrada.
- O loop externo itera por gaps (gap = n / 2), que vão sendo reduzidos pela metade a cada iteração (gap /= 2) até chegarem a 1.
- O loop interno (for) itera pelos elementos do vetor com deslocamento igual ao gap atual (i += gap).
- O valor do elemento atual (temp) é armazenado em uma variável temporária.
- Um loop interno while percorre o vetor para trás a partir do elemento atual (j = i) com o deslocamento do gap (j >= gap).
- Se o elemento anterior (arr[j - gap]) for maior que o elemento atual (temp), eles são trocados (arr[j] = arr[j - gap]).
- O índice j é decrementado para continuar verificando os elementos anteriores com o deslocamento do gap.
- Uma vez que a posição correta é encontrada (j < gap), o elemento temporário (temp) é colocado na posição final (arr[j] = temp).
- O ShellSort geralmente tem um desempenho melhor que o InsertionSort para grandes vetores devido aos saltos maiores realizados durante a ordenação.
