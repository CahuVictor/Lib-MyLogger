# Lib-MyLogger
 Repositorio da biblioteca MyLogger para IDE Arduino

Funcionalidades da Biblioteca:
    Parâmetros de logs, o objetivo é acelerar o desenvolvimento e correção de bugs:
        DEBUG - Setando este parâmetro nos logs de desenvolvimento, você pode ocultar após o desenvolvimento sem precisar atualizar o código
	    INFO  - logs necessários do sistema em produção
	    WARNING - logs de Warning de algum parâmetro acompanhado, os warnings não impedem uma tarefa
	    ERROR   - logs de erro;

    Para o log terá que ser passado as seguintes informações:
        Interface - Essa biblioteca foi construída para funcionar na interface serial ou em outras interfaces, sendo necessário informar qual é a interface utilizada.
        Parâmetro de Debug - Explicado acima
        Mensagem
    
    O log registrará as seguintes informações:
        Parâmetro de Debug - Explicado acima
        Mensagem
        *Funcion - Informará qual é a função que o log está sendo executado
        *Linha - Informará qual é a linha que o log for executado

Ao identificar alguma anormalidade, com o log é possível saber qual linha e qual função foi registrado a anormalidade facilitando a identificação do problema.