<h1>Lab03: Pthreads - Parte 2</h1>
<h3>Componentes do grupo SOsV01D</h3>
NOME: Pedro Henrique Araujo Farias

<h2>Como compilar o programa?</h2>
<p>Para compilar o programa desenvolvido, basta utilizar o compilador gcc. Para isso, insira a linha de comando <code>gcc nomeDoArquivo.c</code>. Recomenda-se também que determine-se o nome de saída deste a partir do argumento <code>-o</code>. Segue exemplo:</p>
<img src="https://github.com/K4NS0KUSH4/SOsV01D/blob/main/Lab03PthreadsParte2/assets/compilacao.png" alt="Compilação do programa">

<h2>Como executar o programa?</h2>
<p>Para executar o programa desenvolvido, utilize a linha de comando <code>./nomeDoArquivo.bin numeroDeThreads</code>. Observe que o programa requer que o número de <i>threads</i> desejado seja informado na linha de comando. Caso contrário, será exibida uma mensagem demonstrando a forma correta de executar o programa.</p>
<img src="https://github.com/K4NS0KUSH4/SOsV01D/blob/main/Lab03PthreadsParte2/assets/execucao.png" alt="Execução do programa">

<h2>Verificando o êxito da implementação</h2>
<p>Como é possível observar nos arquivos <code>noMutexLog.txt</code> e <code>mutexLog.txt</code>, o algoritmo fornece como saída uma aproximação do número irracional Pi. Note que, como se trata de uma aproximação, alguns algarismos variam indevidamente. Isso ocorre por alguns fatores que serão discutidos mais a frente.</p>

<h2>Evidência da geração dos <code>logs.txt</code> no ambiente AWS</h2>
<img src="https://github.com/K4NS0KUSH4/SOsV01D/blob/main/Lab03PthreadsParte2/assets/evidenciaLogsAWS.png" alt="Geração de logs no ambiente AWS">

<h2>Sobre o algoritmo proposto</h2>
<p>O algoritmo proposto vale-se da <a href="https://en.wikipedia.org/wiki/Leibniz_formula_for_%CF%80">série de Leibniz</a> para calcular uma aproximação do valor de Pi. Para calcular os seus diversos termos para obter uma aproximação satisfatória do valor de Pi, estabeleceu-se neste algoritmo que <strong>cada <i>thread</i> calculará 30000 termos da série</strong>.</p>

<h2>Questões propostas</h2>
<p>Abaixo, discorre-se acerca das questões realizadas a respeito deste laboratório.</p>

<h3>a) Implemente uma solução utilizando Mutex e compare com a anterior. O que mudou? Por quê?</h3>
<p>A utilização do Mutex faz com que seja estabelecida uma relação de exclusão mútua entre as <i>threads</i>: Quando uma delas chega à região crítica, as outras devem esperar até que a primeira conclua suas operações.</p>

<p>Desta forma, com a implementação do Mutex, as <i>threads</i> calculam os seus respectivos 30000 termos da série de Leibniz, uma de cada vez. Embora a operação de soma seja associativa, nota-se divergência nos valores causada, não necessariamente, pela existência ou ausência de um Mutex. Portanto, com base nas execuções analisadas, não é possível afirmar que o Mutex garante maior integridade das operações.</p>

<h3>b) No final, entregue no README do repositório uma explicação resumida sobre as diferenças entre os valores atingidos. Quais foram as causas das divergências? Por que elas aconteceram?</h3>
<p>Como comentado anteriormente, a implementação do Mutex não foi suficiente para amenizar as divergências notadas ao calcular os dígitos de Pi. Então, qual seria a causa da dificuldade de se obter uma aproximação acurada?</p>

<p>Considerando que estamos fazendo uso de números de <strong>ponto flutuante</strong>, convenção estabelecida pela <strong>IEEE754</strong>, conclui-se que podemos estar enfrentando <strong>erros de arredondamento</strong> no cálculo da soma resultante dos termos da série de Leibniz. As divergências ocorrem, portanto, devido aos métodos de representação de números reais em números de ponto flutuante, os quais podem ser acometidos por erros de arredondamento.</p>
