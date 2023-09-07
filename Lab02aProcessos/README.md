<h1>Lab02a - Processos</h1>

<h3>Componentes do grupo SOsV01D</h3>
NOME: Pedro Henrique Araujo Farias

<h2>Evidências de compilação e execução das atividades no ambiente AWS</h2>
<img src="https://github-production-user-asset-6210df.s3.amazonaws.com/123918243/266227876-dc050d53-492a-457c-8702-61bb58be0cff.png" 
  alt="Compilação e execução dos arquivos no ambiente AWS.">
Obs: Utilizou-se o comando "vi output.txt" para organizar a saída dos arquivos correspondentes aos exemplos relacionados na formatação. Nenhuma das saídas resultantes da execução dos arquivos foi alterada.

<h2>EXERCÍCIOS</h2>

<h3>EXERCÍCIO 01</h3>
Executando o programa para n = 200:

<img src="https://github-production-user-asset-6210df.s3.amazonaws.com/123918243/266230612-2f15d9f3-67e0-4d7b-b009-5849ecba45ac.png" 
  alt="Execução do arquivo stderrProcessChain com passagem de argumento n = 200">

<img src="https://github-production-user-asset-6210df.s3.amazonaws.com/123918243/266231069-4725fb9b-26ac-4937-b1a4-07fc495511c8.png" 
  alt="Término de impressão da saída resultante da execução do arquivo stderrProcessChain.out">

Com base nas imagens, é possível confirmar que o programa criará uma quantidade n de processos-filhos ao longo de um for loop, o qual incrementará o valor de i, o qual determinará a ordenação da saída com as informações de cada processo criado.

<h3>EXERCÍCIO 02</h3>
Caso o programa utilize print para sys.stdout, a seguinte mensagem do compilador seria exibida:

<img src="https://github-production-user-asset-6210df.s3.amazonaws.com/123918243/266237746-b01459b8-22e1-45bc-8b91-690d62dae55b.png"
  alt="Exibição da mensagem de erro do compilador">

<p>Isso ocorre pois a função printf assume por padrão que será utilizado como mensagem de saída no terminal, o que equivale ao argumento "stdout" da função fprintf. Sendo assim, a função printf não necessita do argumento "stdout", que gera uma mensagem de saída, utilizado pela função fprintf. Analogamente, a função fprintf utiliza o argumento "stderr" para exibir uma mensagem de erro no terminal, a qual não pode ser escrita em um arquivo .txt, por exemplo, uma vez que representa uma mensagem de erro no terminal de execução, e não uma mensagem de saída. Por esse motivo, é possível observar que o EXEMPLO 07 não gera saída alguma no arquivo output.txt, uma vez que "stderr" gera apenas uma mensagem de erro no terminal, não uma mensagem de saída.</p>
Para utilizar a função printf, deve-se remover, portanto, o argumento "stdout". Um modo de obter um resultado equivalente é utilizando a função fprintf com o argumento "stdout". No arquivo stdoutProcessChain.c, executa-se a função fprintf com argumento "stdout". Todavia, uma alternativa para executá-lo com apenas a função printf, sem uso de argumento "stdout", foi inserida como comentário no mesmo arquivo. 
