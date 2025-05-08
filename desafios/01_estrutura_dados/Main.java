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
        String operacao;

        Main pilha_class = new Main();
        Stack<Integer> pilha = pilha_class.getPilha();
        
        for(int i = 0; i < tamanho_entrada; i++)
		{

            operacao = leitor.next();

            switch(operacao) {
                case "PUSH":
                    aux = leitor.nextInt();
        			pilha.push(aux);
                    pilha_class.setPilha(pilha);

                    if (pilha.size() == 1){
                        pilha_class.setMenor(pilha.peek());
                    }
                    System.out.println(pilha);

                    

                    break;
                case "POP":
                    pilha.pop();
                    pilha_class.setPilha(pilha);
                    System.out.println(pilha);

                    break;
                case "MIN":
                    if (pilha.empty()){
                        System.out.println("EMPTY");
                    }else{
                        pilha_class.calculaMenor();
                        System.out.println(pilha_class.getMenor());
                    }
                    break;
                
                default:
                    System.out.println(pilha);
                }

            // System.out.println(pilha);
            
		}

    }

    public Stack<Integer> getPilha()
    {
        return this.pilha;
    }

    public void setPilha(Stack<Integer> pilha)
    {
        this.pilha = pilha;
        System.out.println(this.pilha);

    }

    public int getMenor(){
        return this.menor;
    }

    public void setMenor(int menor){
        this.menor = menor;
    }

    public void calculaMenor(){
        Stack<Integer> pilha_ordenada = this.getPilha();

        System.out.println("dENTRO");
        
        System.out.println(pilha_ordenada);
        
        int menor = pilha_ordenada.peek();

        for(int i = 0; i < pilha_ordenada.size(); i++){
            if (pilha_ordenada.peek() < menor){
                menor = pilha_ordenada.peek();
            }
            pilha_ordenada.pop();
        }

        this.setMenor(menor);

    }



}