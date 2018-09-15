/*
 Escreva um programa que verifica se uma compra de um cliente é válida. 
 Os argumentos devem ser o cliente, o item e a quantidade solicitada. 
 O predicado deve ter sucesso apenas se o cliente for cliente válido e com
 uma boa taxa de crédito e tem quantidade do item em estoque e a quantidade solicitada seja inferior ao estoque disponível. 
*/


cliente(Cliente, Saldo, QtdItensComprados):- 
    write('Nome do comprador:'), nl,
    read(Cliente),
    write('Saldo do comprador:'),nl,
    read(Saldo),
    write('Quantos itens deseja comprar?'), nl,
    read(QtdItensComprados).

item(Item, Preco, Qtd):-  
    write('Qual item está sendo comprado?'), nl,
    read(Item),
    write('Qual o preço do ítem comprado?'), nl,
    read(Preco),
    write('Quantas unidades do item estão disponíveis?'),
    read(Qtd).

valida_item:-
    cliente(Cliente, Saldo, QtdItensComprados), 
    item(Item, Preco, Qtd),
    validacao(V, Qtd, QtdItensComprados, Preco, Saldo),
    nl, nl, 
    write(V),

validacao(V, Qtd, QtdItensComprados, Preco, Saldo):-
    (QtdItensComprados =< Qtd),((QtdItensComprados * Preco) =< Saldo) ->  V = 'A compra é válida!';
    (Qtd =< 0) ->  V = 'Compra inválida! Estoque indisponível.';
    (QtdItensComprados > Qtd), (Qtd > 0) -> V = 'Compra inválida! Não há essa quantidade de ítens disponíveis para a compra solicitada.';
    ((QtdItensComprados * Preco) > Saldo) ->  V = 'Compra inválida! O cliente não possui credito suficuente para efetuar a compra.'.
