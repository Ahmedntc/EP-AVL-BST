# EP-AVL-BST

Funções de benchmark
    
    Recebem como parâmetro a quantidade de arvores a ser gerada e a quantidade de nos que cada uma vai possuir, 
    isso é executado em dois loops for um até a quantidade de árvores 
    e outro dentro do mesmo até a quantidade de nós. No fim dos loops é calculado o total de tempo em clocks por segundo 
    que levou para criar cada árvore e altura total delas, 
    com esses dois valores uma funçao que calcula as médias é executada 
    que divide a altura total e o tempo total pela quantidade de árvores.

Assegurando que as chaves dos nós sejam distintas    
    
    Para assegurar que valores de chave não se repitam, uma função bool que busca por um dado elemento foi criada
    retornando false quando não achar um elemento com a chave dada na árvore e true quando o encontrar. 
    Nos loops de criação da árvore existe um while que gera novos números aleatórios 
    enquanto o retorno da função de busca for diferente de false.
 						    
                            
 Conclusões
    
    As árvores binárias são uma estrutura de dados que tem como um de seus atrativos 
    o fato da complexidade de tempo de operações ser O(log N) 
    porém as árvores de busca binária não são muito efetivas em manter essa propriedade 
    pois podem ocorrer casos em que uma árvore pode se assemelhar a uma lista ligada
    já as AVL existem para que essa propriedade se mantenha sempre
    rebalanceando a árvore por meio de rotações durante as inserções e deleções
    usando o chamado fator de balanceamento como referência para isso.
    
    Se tornando mais vantajoso a utilização das AVLs por se manterem muito eficientes em relação a tempo de execução de busca 
    mesmo que não mantenham uma altura perfeita ainda assim uma altura suficientemente boa é mantida.
    Por outro lado as BST são mais rápidas para inserir números aleatórios por não precisarem executar rebalanceamentos.
