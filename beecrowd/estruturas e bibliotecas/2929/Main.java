import java.util.Stack;
import java.util.Scanner;

public class Main 
{
    public static void main(String[] args) 
    {   
        // Variáveis
        Scanner leitor = new Scanner(System.in);
        int tamanho_entrada = leitor.nextInt();
        int aux;
        String operacao;
        Stack<Integer> pilha = new Stack<Integer>();
        Stack<Integer> pilhaMin = new Stack<Integer>();

        // Para passar no teste de Tempo de Execução
        StringBuilder saida = new StringBuilder();
        
        // Loop de Entradas
        for(int i = 0; i < tamanho_entrada; i++)
		{
            operacao = leitor.next();

            switch(operacao) {
                case "PUSH":
                    
                    // Lendo valor do terminal
                    aux = leitor.nextInt();

                    // Adicionando na Pilha Principal
                    pilha.push(aux);

                    // Adicionando na pilha dos Menores
                    // Se for o primeiro ou se for menor que o topo da Pilha dos Menores
                    // Tem que ser menor ou igual (<=) para funcionar com valores repetidos na Pilha Principal
                    // Exemplo: 
                        // 6
                        // PUSH 2 -> P.O: [2] P.M: [2]         <- Primeiro elemento é sempre o primeiro Menor  
                        // PUSH 3 -> P.O: [2,3] P.M: [2]       <- Não adicionado na Pilha dos Menores por ser maior que o topo dela
                        // PUSH 2 -> P.O: [2,3,2] P.M: [2,2]   <- Adicionando repetidos de propósito  
                        // MIN    -> TOPO(P.M) -> 2            <- Topo da Pilha dos Menores 
                        // POP    -> P.O: [2,3] P.M: [2]       <- Removendo um dos menor repetidos
                        // MIN    -> TOPO(P.M) -> 2            <- Topo da Pilha dos Menores
                    if (pilhaMin.isEmpty() || aux <= pilhaMin.peek()){
                        // Novo menor - Topo de Pilha dos Menores
                        pilhaMin.push(aux);
                    }

                    break;
                case "POP":
                    if (pilha.isEmpty()){
                        saida.append("EMPTY\n");
                        // System.out.println("EMPTY");
                    }else{
                        aux = pilha.pop();
                        // Se o topo da Pilha Principal for o menor (Topo da Pilha dos Menores)
                        if (aux == pilhaMin.peek()){
                            pilhaMin.pop();
                        }
                    }

                    break;
                case "MIN":
                    if (pilha.isEmpty()){
                        // System.out.println("EMPTY");
                        saida.append("EMPTY\n");
                    }else{
                        // Mostrando o topo da Pilha de Menores

                        // System.out.println(pilhaMin.peek());
                        saida.append(pilhaMin.peek());
                        saida.append('\n');
                    }
                    break;
            }
		}

        System.out.print(saida);
        leitor.close();
    }
}