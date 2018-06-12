# -*- coding: cp1252 -*-

def menu():

    esc = int(raw_input('\nSelecione o modo de Jogo:\n\n[1] SinglePlayer ( 2 Jogadores Mesmo PC )\n\n[2] Multiplayer ( Conecta 2 Players )\n\nEscolha: '))

    if esc == 1: iniciar()

    if esc == 2: multiplayer()

def multiplayer():

    esc = int(raw_input('\nSelecione o Modo de Conexão:\n\n[1] Cliente (Conecta a um outro parceiro através de IP)\n\n[2] Servidor (Serve de Host para que outro jogador possa se conectar)\n\n[3] Ver Meu IP'))

def servidor():

    import socket
    
    port = 8081
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.bind(("", port))

    print "Esperando por conexao do outro Player...:",'Porta:', port,'\n'

    while 1:
    
        data, addr = s.recvfrom(1024)
        print data

def cliente():

    import socket
    port = 8081
    host = "localhost"
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.bind(("", 0))

    while True:

        msg = str(raw_input('Digite a mensagem a ser enviada: '))

        if msg == 'pare': break
    
        s.sendto(msg, (host, port))


def iniciar(): #Começa o jogo e desenha o hashtag gigante simulando uma Matriz 3x3.

    global linha,coluna
    
    linha = coluna = velha = 0

    print '\nO 1º jogador sera representado com X e o 2º jogador com O.\n'

    print ''.center(50,'_')

    print '\n      1     2     3\n'
    print '1    ',jogo[0][0],' | ',jogo[0][1],' | ',jogo[0][2]
    print '    -----|-----|-----'
    print '2    ',jogo[1][0],' | ',jogo[1][1],' | ',jogo[1][2]
    print '    -----|-----|-----'
    print '3    ',jogo[2][0],' | ',jogo[2][1],' | ',jogo[2][2],'\n\n'


    while True: #Pede a posição da jogada e trata o erro para não fuder com tudo.
        
        try:

            print 'Vez do %dº Jogador! '.center(50,'_') % (player[0])
        
            posicao = str(raw_input('\nDigite o numero da linha que você ira jogar. \nEx: 2x3 , Linha 2 e Coluna 3\n\nPosicão: '))
            
            if len(posicao) > 3 or len(posicao) < 3: raise ValueError

            if int(posicao[0]) > 3 or int(posicao[2]) > 3: raise ValueError
            
            if posicao[0].isdigit() == False or posicao[1] != 'x' or posicao[2].isdigit() == False: raise ValueError

            linha = posicao[0]
            coluna = posicao[2]

            if jogo[int(linha)-1][int(coluna)-1] != ' ': raise NameError
            
            break

        except ValueError:

            print '\nDigite a posição apenas no formato axb, a E Z e b E Z\n'

        except NameError:

            print '\nEssa jogada ja foi feita, escolha outra posição!\n'
    
    atualizar() # Atualiza o jogo e adiciona na matriz os dados.

    if ganhei[0] == 0: # Checa se alguém ganhou.

        for i in range(3): # Loop para que o jogo continue, até dar velha ou alguém ganhar.

            if ganhei[0] == 1: break

            for k in range(3):

                if ganhei[0] == 1: break

                if jogo[i][k] == ' ':

                    iniciar()

                else:
                    
                    velha += 1

            if velha == 9:

                print '\n'
                
                print 'Deu Velha!'.center(50,'_')

                reset = str(raw_input('\nDeseja recomeçar? ( sim ou nao ): '))

                if reset == 'sim':

                    jogador()
                    design()
                    iniciar()

                else:

                    exit()
        
    else:

        pass

    
def design(): #Cria a Matriz 3x3 e a variavel ganhei que vai funcionar com 0 para ninguém ganhou e 1 para alguém ganhou.
    
    global jogo,ganhei

    ganhei = ['']
    
    ganhei[0] = 0
    
    jogo = [''] * 3 #Cria uma lista com 3 valores.

    for i in range(3): #Adiciona a cada indice um vetor com mais 3 valores, simulando uma matriz 3x3.

        jogo[i] = [' '] * 3

def jogador(): #Cria a variavel jogador, para alternar entre X(P1) e O(P2).

    global player

    player = ['']
    
    player[0] = 1


def atualizar(): #Atualiza a Matriz conforme a jogada e o jogador.

    linhai = int(linha)
    colunai = int(coluna)
    
    if player[0] == 1:
    
        jogo[linhai-1][colunai-1] = 'X'

    elif player[0] == 2:
        
        jogo[linhai-1][colunai-1] = 'O'

    if player[0] == 1: player[0] = 2

    else: player[0] = 1

    ganhou()

def ganhou(): #Faz a checagem para ver se alguém completou o jogo.

    # Checagem Linha Horizontal.

    if jogo[0][0] == jogo[0][1] == jogo[0][2] == 'X': # 1ª Linha Horizontal

        ganhei[0] = 1
        
        print '\n\nO player 1 ganhou o jogo!'

    elif jogo[0][0] == jogo[0][1] == jogo[0][2] == 'O':

        ganhei[0] = 1

        print '\n\nO player 2 ganhou o jogo!'

    if jogo[1][0] == jogo[1][1] == jogo[1][2] == 'X': # 2ª Linha Horizontal

        ganhei[0] = 1
        
        print '\n\nO player 1 ganhou o jogo!'

    elif jogo[1][0] == jogo[1][1] == jogo[1][2] == 'O':

        ganhei[0] = 1

        print '\n\nO player 2 ganhou o jogo!'

    if jogo[2][0] == jogo[2][1] == jogo[2][2] == 'X': # 3ª Linha Horizontal

        ganhei[0] = 1
        
        print '\n\nO player 1 ganhou o jogo!'

    elif jogo[2][0] == jogo[2][1] == jogo[2][2] == 'O':

        ganhei[0] = 1

        print '\n\nO player 2 ganhou o jogo!'

    # Começa aqui a Checagem da linha Vertical:

    if jogo[0][0] == jogo[1][0] == jogo[2][0] == 'X': # 1ª Linha Vertical

        ganhei[0] = 1
        
        print '\n\nO player 1 ganhou o jogo!'

    elif jogo[0][0] == jogo[1][0] == jogo[2][0] == 'O':

        ganhei[0] = 1

        print '\n\nO player 2 ganhou o jogo!'

    if jogo[0][1] == jogo[1][1] == jogo[2][1] == 'X': # 2ª Linha Vertical

        ganhei[0] = 1
        
        print '\n\nO player 1 ganhou o jogo!'

    elif jogo[0][1] == jogo[1][1] == jogo[2][1] == 'O':

        ganhei[0] = 1

        print '\n\nO player 2 ganhou o jogo!'

    if jogo[0][2] == jogo[1][2] == jogo[2][2] == 'X': # 3ª Linha Vertical

        ganhei[0] = 1
        
        print '\n\nO player 1 ganhou o jogo!'

    elif jogo[0][2] == jogo[1][2] == jogo[2][2] == 'O':

        ganhei[0] = 1

        print '\n\nO player 2 ganhou o jogo!'

    # Começa aqui a Checagem das Diagonais:

    if jogo[0][0] == jogo[1][1] == jogo[2][2] == 'X': # 1ª Diagonal

        ganhei[0] = 1
        
        print '\n\nO player 1 ganhou o jogo!'

    elif jogo[0][0] == jogo[1][1] == jogo[2][2] == 'O':

        ganhei[0] = 1

        print '\n\nO player 2 ganhou o jogo!'

    if jogo[2][0] == jogo[1][1] == jogo[0][2] == 'X': # 2ª Diagonal

        ganhei[0] = 1
        
        print '\n\nO player 1 ganhou o jogo!'

    elif jogo[2][0] == jogo[1][1] == jogo[0][2] == 'O':

        ganhei[0] = 1

        print '\n\nO player 2 ganhou o jogo!'
   
jogador()

design()
menu()
#iniciar()

raw_input('\nAperte Enter para Sair do Programa!')
