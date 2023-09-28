<h1>PROJETO 01: SISTEMAS OPERACIONAIS</h1>
<p>Este é um programa <i>open-source</i> desenvolvido por <strong>Pedro Henrique Araujo Farias</strong>.</p>

<h2>Sobre o problema proposto</h2>
<p>No código demonstrado no enunciado do projeto, nota-se que o desenvolvedor deste não se atentou a estabelecer uma política de condição de corrida na execução de seu programa.</p>
<p>Dado este fato, ocorrem conflitos na execução do programa, uma vez que as diversas operações realizadas nos saldos das contas bancárias, compartilhados pelos diferentes subprocessos, tornam-se dessincronizadas.</p>
<p>Sendo assim, o objetivo do projeto é propor uma condição de corrida para garantir que as transações estejam sempre sincronizadas entre si, isto é, que estas sempre acessem os dados atualizados de saldo das contas bancárias.</p>

<h2>Desenvolvimento</h2>
<p>Como proposta de solução ao problema apresentado, foi implementada uma abordagem que se baseia na utilização de <i><strong>threads</strong></i> e do <i><strong>mutex</strong></i>:</p>
<ul>
  <li>Cada <i>thread</i> será responsável por executar uma transação;</li>
  <li>A partir do <i>mutex</i>, será estabelecida uma condição de corrida que manterá as transações sincronizadas entre si.</li>
</ul>
<p>O código-fonte deste projeto se encontra em [mainProj01.c](./mainProj01.c)</p>
