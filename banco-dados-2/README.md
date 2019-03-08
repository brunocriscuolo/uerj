# EXECUÇÃO EM LINUX/UBUNTU


### Instalção do cURL

Primeiro vamos instalar esse utilitário, pois ele é necessário para porterior instalação do Apache CouchDB. Para instalar o cURL usando o comando `apt-get install`, execute os seguintes passos

Digite o seguinte comando para baixar as listas de pacotes dos repositórios e atualizá-los:

	$ sudo apt-get update
    
Digite o seguinte comando para instalar o cURL:

	$ sudo apt-get install curl
    
Para verificar se o cURL está sendo executado corretamente, execute o seguinte comando:
    
	$ curl --version
  

### Instalação do Apache CouchDB

No terminal, executar o comando:

    $ echo "deb https://apache.bintray.com/couchdb-deb {distribution} main" \
        | sudo tee -a /etc/apt/sources.list

e substituir {distribution} com a escolha apropriada para sua versão de SO:

    Debian 8: jessie
    Debian 9: stretch
    Ubuntu 14.04: trusty
    Ubuntu 16.04: xenial
    Ubuntu 18.04: bionic

Primeiro, instalamos a chave do repositório:

    $ curl -L https://couchdb.apache.org/repo/bintray-pubkey.asc \
        | sudo apt-key add -

Então, atualizamos o o cache do repositório e instalamos o pacote:

    $ sudo apt-get update && sudo apt-get install couchdb

Acesse a interface web do CouchDB digitando `http://127.0.0.1:5984/_utils/` na barra de endereços do seu browser.  
Para executar corretamente a aplicação, é necessário criar um banco de dados (inicialmente vazio, sem documentos JSON) chamado 'person', clicando na opção 'Create Database' nessa interface do CouchDB.


### Intalação do ambiente de desenvolvimento Python

Neste ambiente o Pyhton já é nativo e por isso não necessita de instalação. Para verificar a versão do Python que está rodando na sua distribuição execute o seguinte comando no terminal:

    $ python --version

ou

    $ python -V

Para rodar essa aplicação, a versão recomendada é a 2.7.x  
Vamos começar executando:

    $ sudo apt-get update
    $ sudo apt-get install python-dev python-setuptools
    $ sudo easy_install pip

O pacote 'python-setuptools' é necessário para instalar o 'easy_install' que, por sua vez, é utilizado na instalção do 'pip'.  
O 'pip' é um sistema de gerenciamento de pacotes usado para instalar e gerenciar módulos do Python.  
Construíremos uma 'virtualenv' (ambiente virtual do Python) para isolar os módulos importados e garantir o funcionamento das dependências, evitando conflitos entre os pacotes. A partir de agora sempre usaremos o pip para instalar os pacotes necessários.
    
    $ pip install virtualenv

Pra testar se a virtualenv foi corretamente instalada execute no terminal:
    
    $ virtualenv --version

Após a instalação do pacote 'virtualenv', podemos seguir com a criação do ambiente virtual.  
Navegue até o diretório do projeto, neste caso:

    $ cd /home/<nome_usuario>/trabalho-bd2

Crie o ambiente virtual no diretório corrente, com o nome que desejar. Por convenção foi usado o nome 'venv'. Observe que no diretório do projeto, será criada uma pasta com o nome dado ao ambiente virtual do python.

    $ virtualenv --python python2 <nome_ambiente_virtual>
    $ virtualenv --python python2 venv

ou

    $ virtualenv -P python2 venv

Antes de iniciar a instalação dos pacotes da aplicação com 'pip', ative o seu ambiente virtual, para garantir que todas as libs serão carregadas nesse ambiente e não diretamente no sistema operacional. Para ativar a 'venv', use:

    $ source venv/bin/activate

Caso você precise desativá-la, basta digitar no terminal:
    
    $ deactivate

Após a ativação da sua virtualenv, você pode instalar todos os pacotes necessários para rodar a aplicação.  Esses pacotes estão listados em um arquivo chamado 'requirements.txt'. Para iniciar a instalção dos pacotes, execute:

    (venv)$ pip install -r requirements.txt


### Executando a aplicação

Agora que o ambiente de execução já está preparado podemos, finalmente, rodar a aplicação:

    (venv)$ cd /home/<nome_usuario>/trabalho-bd2/app
    (venv)$ python main.py

Acesse o endereço localhost que aparecerá no terminal: `http://127.0.0.1:5000/`


