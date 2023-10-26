<h1>Lab03: Pthreads - Parte 1</h1>
<h3>Componentes do grupo SOsV01D</h3>
NOME: Pedro Henrique Araujo Farias

<h2>Evidências de compilação e execução das atividades no ambiente AWS</h2>
<img src="https://raw.githubusercontent.com/K4NS0KUSH4/SOsV01D/main/PthreadsParte1/assets/pthreads1compilacao.png" alt="Compilação e execução dos arquivos no ambiente AWS.">

<h2>Comprovando êxito nos resultados obtidos</h2>
<p>A abordagem convencional para o problema da multiplicação matriz-vetor é tratar o vetor como uma <strong>matriz de colunas</strong> e, então, realizar a multiplicação destas.</p>
<p>Todavia, essa abordagem resulta também em uma matriz de colunas, a qual se trata de um <strong>vetor bidimensional</strong>. De modo a obter como resultado um <strong>vetor unidimensional</strong>, a abordagem utilizada neste algoritmo não considera o vetor como uma matriz de colunas.</p>
<p>É necessário explicitar esse fato pois, nas calculadoras <i>online</i>, foi necessário tornar o vetor uma matriz de colunas. Portanto, <strong>considere o vetor [a, b, c] correspondente à matriz {{1}, {2}, {3}}</strong>.</p>

<h3>Operação realizada</h3>
<img src="https://raw.githubusercontent.com/K4NS0KUSH4/SOsV01D/main/PthreadsParte1/assets/operacaomultmatriz.png" alt="Operação de multiplicação de matrizes.">

<h3>Resultado obtido na multiplicação de matrizes</h3>
<img src="https://raw.githubusercontent.com/K4NS0KUSH4/SOsV01D/main/PthreadsParte1/assets/resultmultmatriz.png" alt="Resultado da multiplicação de matrizes.">

<h3>Resultado obtido na execução do algoritmo desenvolvido</h3>
<img src="https://raw.githubusercontent.com/K4NS0KUSH4/SOsV01D/main/PthreadsParte1/assets/resultalgoritmo.png" alt="Resultado da execução do código desenvolvido.">

<h3>Interpretando os resultados</h3>
<p>Como comentado anteriormente, embora a abordagem convencional da multiplicação matriz-vetor resulte em uma matriz de colunas, optou-se por obter o resultado em um <strong>vetor unidimensional</strong>.</p>
<p>Portanto, para comprovar o êxito do algoritmo desenvolvido, deve-se valer da seguinte afirmação: <strong>o vetor [a, b, c] é equivalente à matriz de colunas {{a}, {b}, {c}}</strong>.</p>
<p>Observando as imagens dos resultados, temos uma matriz de colunas (vetor bidimensional) <strong>{{55}, {70}, {85}, {100}, {115}}</strong>, a qual <strong>equivale</strong> ao vetor unidimensional <strong>[55, 70, 85, 100, 115]</strong>.</p>
<p>Dessa forma, constata-se o <strong>êxito da solução implementada pelo algoritmo</strong>.</p>
