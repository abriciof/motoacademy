import java.util.Stack;
import java.util.Scanner;

public class Main 
{

    public static void main(String[] args) 
    {
        Scanner leitor = new Scanner(System.in);
        int tamanho_entrada = leitor.nextInt();
        int aux;
        String operacao;
        Stack<Integer> pilha = new Stack<Integer>();
        Stack<Integer> pilhaMin = new Stack<Integer>();
        
        for(int i = 0; i < tamanho_entrada; i++)
		{
            operacao = leitor.next();

            switch(operacao) {
                case "PUSH":

                    aux = leitor.nextInt();

                    pilha.push(aux);

                    if (pilhaMin.isEmpty() || aux <= pilhaMin.peek()){
                        pilhaMin.push(aux);
                    }

                    break;
                case "POP":
                    if (pilha.isEmpty()){
                        System.out.println("EMPTY");
                    }else{
                        aux = pilha.pop();
                        if (aux == pilhaMin.peek()){
                            pilhaMin.pop();
                        }
                    }

                    break;
                case "MIN":
                    if (pilha.isEmpty()){
                        System.out.println("EMPTY");
                    }else{
                        System.out.println(pilhaMin.peek());
                    }
                    break;
            }

		}
        
        leitor.close();
    }

}