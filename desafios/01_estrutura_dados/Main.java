import java.util.Stack;
import java.util.Scanner;

public class Main 
{

    private Stack<Integer> pilha;
    private int menor;

    Main(){
        this.pilha = new Stack<>();
    }

    public static void main(String[] args) 
    {
        Scanner leitor = new Scanner(System.in);
        int tamanho_entrada = leitor.nextInt();
        int aux;

        Main pilha_class = new Main();
        Stack<Integer> pilha = pilha_class.getPilha();
        
        for(int i = 0; i < tamanho_entrada; i++)
		{
            aux = leitor.nextInt();
			pilha.push(aux);
		}

        System.out.println(pilha);

        pilha.pop();

        System.out.println(pilha);


    }

    public Stack<Integer> getPilha()
    {
        return this.pilha;
    }

    public int menor(){
        return 0;
    }


}