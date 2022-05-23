# EP-AVL-BST
    Study about time complexity of operations in avl and binary search trees.
### Funções de benchmark
    Recebem como parâmetro a quantidade de arvores a ser gerada e a quantidade de nos que cada uma vai possuir, isso é executado em dois loops for 
    um até a quantidade de árvores e outro dentro do mesmo até a quantidade de nós. 
    No fim dos loops é calculado o total de tempo em clocks por segundo que levou para criar cada árvore e altura total delas, 
    com esses dois valores uma funçao que calcula as médias é executada que divide a altura total e o tempo total pela quantidade de árvores.

### Assegurando que as chaves dos nós sejam distintas    
    Para assegurar que valores de chave não se repitam, uma função bool que busca por um dado elemento foi criada retornando false quando não achar um elemento com a chave dada na árvore e true quando o encontrar. Nos loops de criação da árvore um while que gera novos números aleatórios enquanto o retorno da função de busca for       diferente de false.
 						    
    
