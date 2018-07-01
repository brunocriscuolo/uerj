### Trab 1 - Manipulação de Imagens Digitais
* Resolva a Lista de Exercícios de Manipulação de Imagens no Octave (Tópico 2).
* Para cada exercício devem ser apresentadas as imagens de entrada e saída, e o respectivo código Octave.
* Os resultados devem ser apresentados e submetidos em um arquivo PDF.  

---  

### Trab 2 - Transformações Geométricas Tarefa

###### Primeira Parte

* Crie uma função no Octave que realize a rotação de um objeto geométrico sobre o seu centro.
* A função deve ter como parâmetros o ângulo de rotação (em graus) e uma matriz com os pontos que representam os vértices do objeto (o objeto pode ter um número arbitrário de pontos). Cada ponto deve corresponder a uma coluna da matriz, como por exemplo:

```
[0 0 1 1;
 0 1 1 0;
 1 1 1 1];
```
   
   A matriz acima representa o quadrado unitário com o primeiro vértice na origem.

 * Mostre em figuras diferentes o objeto original e o objeto rotacionado.
 * Considere utilizar as seguintes funções do Octave: axis, hold on, line; e lembre-se de que as funções trigonométricas têm como entrada ângulos em radianos.
    Submeta o código da função e um script que chame a função (em arquivos .m).  
    
###### Segunda Parte

* Crie uma função no Octave que realize a rotação do objeto geométrico sobre o seu centro como uma animação, ou seja, variando o ângulo de rotação.
* Considere utilizar as seguintes funções do Octave: drawnow e pause.
* Na plotagem você deve trabalhar com handles dos objetos gráficos (linhas), conforme:

  ```
  h(i) = line(...)
  ```
  
* A cada iteração (do ângulo de rotação), você deve apagar os objetos gráficos já plotados com a função delete(h(:)).
* Submeta o código da função e um script que chame a função (em arquivos .m).

###### Terceira Parte

* Crie uma função no Octave que realize a rotação do objeto geométrico sobre o seu centro e que, simultaneamente, gire o centro do objeto sobre a origem do espaço, ou seja, sobre o ponto [0 0 1]’)
* Como na segunda parte do trabalho, o resultado da função deve ser uma animação, onde os ângulos de rotação sobre o centro do objeto e sobre a origem devem variar indefinidamente.

---  

### Trab 3 - Transformação Projetiva em Imagem Tarefa

* Crie um programa no Octave que reconstrua uma imagem com distorções de perspectiva a através de uma transformação projetiva.
* A imagem a ser reconstruída é Placa_Estacionamento.png (disponível no AVA através do link Imagens Teste). O programa deve ter como saída uma imagem correspondente à imagem original, onde a placa de trânsito esteja em formato retangular.
* O cálculo da transformação projetiva deve ser feito a partir de uma matriz que contém quatro pares de pontos correspondentes (homólogos) na imagem original e na imagem reconstruída. Para a criação desta matriz, deve-se considerar que a placa de trânsito tem 1m de altura por 50cm de largura.
* Abaixo, um exemplo da matriz de pares de pontos. A primeira linha indica que o ponto 1,1 (x=1 e y=1) na imagem original corresponde ao ponto 50,50 (x=50 e y=50) na imagem reconstruída.

```
 [1      1      50     50;
  1     350     1     300;
 390     1     390     1;
 390    350    300    350];
 ```

* Considere que a imagem reconstruída deve ter três bandas (tricromática).
* Gere duas imagens reconstruídas tricromáticas, em que as intensidades dos pixels devem ser calculadas através de:  
  1. núcleo de reconstrução constante (vizinho mais próximo);
  2. núcleo de reconstrução triangular 2D (bilinear).
* Não é permitida a utilização das seguintes funções do Octave: *cp2tform*; *fitgeotrans*; *imtransform*; *imwarp*; e *maketform*.
* Submeta o código completo do programa dentro de um arquivo .pdf onde se mostre também a imagem original e a reconstruída.
