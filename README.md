# SO-06-pipes

Objetivos:
* Conceito e operação com pipes
* Implementar composição de comandos

# Atividade 01 - pipes

## Revisão

Como dois processos podem cooperar entre si?
* `exit-wait` comunicando 1 byte
* sinais, que transmitem muito pouca informação

Como transmitir maiores quantidades de dados?
* Arquivos? Possível, mas com desvantagens
* Surge o conceito de `pipe`

## Tópicos

`man 2 pipe`

O que observar?
* Similaridade com arquivos
* Semântica bloqueante
* Convenção de uso: array de dois inteiros (descritores de arquivos)
* Estrutura interna do kernel

Uso combinado com `fork`:
* Fechar as pontas não usadas logo de cara
* Para as demais, redirecionar `stdin` e `stdout`, e fechar os descritores de arquivos em seguida
* Comportamento quando pontas fecham

![Pipes](https://ocaml.github.io/ocamlunix/ocamlunix-image6.png)

# Atividade 02 - Composição de comandos no shell

`cat sos | grep BSD | sort | head -n 1`

* Filosofia Unix: cada comando é especializado em uma única função (na prática, nem sempre), depois "combinam-se" comandos isolados para obter efeitos complexos

## Passo 2.1 - Fazer a composição programaticamente

Para compor N comandos, fazer um laço de N - 1 iterações.

Situação numa iteração genérica:
![01](https://ocaml.github.io/ocamlunix/ocamlunix-image13.png)

Logo após o `fork`:
![02](https://ocaml.github.io/ocamlunix/ocamlunix-image14.png)

Redirecionando o processo pai:
![03](https://ocaml.github.io/ocamlunix/ocamlunix-image15.png)

Redirecionando o processo filho:
![04](https://ocaml.github.io/ocamlunix/ocamlunix-image16.png)

## Passo 2.2 (opcional) - Parsing de expressões com `|` , `>` , `<` , etc.

