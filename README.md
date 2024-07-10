# Emparelhamento Máximo

Código e dados de suporte para o trabalho prático no problema do emparelhamento máximo

## Gerador de instâncias

O gerador de instâncias gera grafos bipartidos com $n_1$ e $n_2$ vértices nas duas partes. As arestas são aleatórias com uma densidade $\rho$, i.e. das $nm$ possíveis arestas $\rho nm$ são selecionados aleatoriamente.

## Instâncias grandes para o "bottleneck matching"

Se encontram no subdiretório "bm". As instâncias são do [Matrix Market](https://math.nist.gov/MatrixMarket). O formate é o seguinte. Na primeira linha a dimensão da matriz $n\times m$ e o número de não-zeros $z$. Nas próximas $z$ linhas, para cada entrada não zero a linha $i\in[n]$, coluna $j\in[m]$ e valor $v$.
