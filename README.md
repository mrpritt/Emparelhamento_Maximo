# Emparelhamento Máximo

Código e dados de suporte para o trabalho prático no problema do emparelhamento máximo

## Gerador de instâncias

O gerador de instâncias gera grafos bipartidos com $n_1$ e $n_2$ vértices nas duas partes. As arestas são aleatórias com uma densidade $\rho$, i.e. das $nm$ possíveis arestas $\rho nm$ são selecionados aleatoriamente.

## Instâncias grandes para testar a decomposição Birkhoff-von Neumann (BvN)

Se encontram no subdiretório "bm". As instâncias são do [Matrix Market](https://math.nist.gov/MatrixMarket). O nomes "matrix.mtx.gz" são as matrizes originais, os "matrix.dsm.mtx.gz" as versões duplamente estocásticas. O formato é o seguinte. Na primeira linha a dimensão da matriz $n\times m$ e o número de não-zeros $z$. Nas próximas $z$ linhas, para cada entrada não zero a linha $i\in[n]$, coluna $j\in[m]$ e valor $v$.

Lembrando a decomposição BvN: uma matriz quadrada $M$ é duplamente estocástica sse ela pode ser decomposta de forma $M=\lambda_1 P_1+\lambda_2 P_2+\cdots\lambda_k P_k$ com $\lambda_i\leq 1$ e $P_i$ uma matriz de permutação.

A nossa abordagem vai ser a seguinte: para uma matriz $M$, encontra o emparalhemento perfeito entre linhas e colunas de maior coeficiente mínimo (o "maximum bottleneck matching"). Isso custa no máximo $O(\sqrt n n\log_2 n^2)=O(n^{3/2}\log n)$. Seja $\lambda$ o menor valor (o "bottleneck") e $P$ a matriz de permutação representado o emparelhamento perfeito. Atualiza $M:=M-\lambda P$ e repete, até o maior coeficiente de $M$ é menor que uma precisão $\epsilon\approx 10^{-5}$. O tamanho da decomposição é o número de iterações.
