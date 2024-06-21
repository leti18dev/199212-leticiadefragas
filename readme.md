trabalho feito por leticia de fragas, matricula 199212.

O C++ é uma linguagem de programação de propósito geral, criada como uma extensão da linguagem C.
ela incorpora recursos adicionais,como suporte à programação orientada a objetos.
foi desenvolvida no inicio dos anos 70 por Dennis Ritchie. Bjarne Stroustrup, um estudante de doutorado da época, viu a oportunidade de melhorar a linguagem C ao adicionar recursos de programação orientada a objetos.

Minha escolha por essa linguagem foi pela sua fluidez e facil sintaxe, meu trabalho foi um sistema sobre o gerenciamento de estoque de peças de uma mecânica, possui classes como empresa, produtos, estoque e pedidos.

produtos = óleo para cambio(oleo),kit de embreagem(kitembreagem),bomba de direção hidráulica(bombadedirecao),
conversor de torque(conversor),caixa de direção(caixa).
estoque = quantidade de cada produto 
pedidos = armazena as encomendas feitas 
Oficina = classe (mecanica).

Primeiro criei uma classe para produto adicionando nela nome e preço,ela é a classe base
possuie um construtor para inicializar os atributos, declara um metodo virtual para exibirinformacoes
deve ser implementado pelas subclasses, getnome e getpreco para obter o nome e preco dos produtos,
cada uma das subclasses herda de produto, cada uma dessas classes inicializa o produto com um nome e 
preco especifico,com o metodo exibirinformacoes exibe as informacoes do produto.

a classe estoque gerencia a quantidade de produtos, Usa um vetor de pares (vector<pair<Produto*, int>>) para armazenar produtos e suas quantidades.
a classe pedido representa um pedido feito por um cliente, contem um ponteiro para produto e a quantidade desejada.
a classe mecanica gerencia a ofina mecanica, incluindo o estoque e pedidos, contem um nome, um objeto "estoque" e um vetor de pedido.
a funcao principal (main) cria um objeto mecanica para representar a oficina, cria produtos especificos 
(oleo, kit de embreagem, bomba de direcao, conversor de torque, caixa de direcao) e adiciona no estoque.
depois lista o estoque inicial, faz alguns pedidos de produtos, verificando a disponibilidade e atualizando o estoque, logo apos lista o estoque e os pedidos apos a realizacao dos pedidos.

a herança ocorre na classe base "produto" e as classes que derivam dela elas herdam de produto,
a agregacao ocorre com a classe estoque que contem produto e mecanica, estoque tambem contem uma colecao de pedido, o polimosfismo é utilizado com o metodo virtual exibirInformacoes(), na classe principal produto.


