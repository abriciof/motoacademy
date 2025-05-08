import java.util.Stack;
import java.util.Scanner;

public class Main 
{

    private Stack<Integer> pilha;
    private int menor;

    Main(){
        this.pilha = new Stack<Integer>();
    }

    public static void main(String[] args) 
    {
        Scanner leitor = new Scanner(System.in);
        int tamanho_entrada = leitor.nextInt();
        int aux;
        String operacao;

        Main app = new Main();
        
        for(int i = 0; i < tamanho_entrada; i++)
		{

            operacao = leitor.next();

            switch(operacao) {
                case "PUSH":

                    aux = leitor.nextInt();

                    app.empilha(aux);

                    break;
                
                case "POP":

                    app.desenpilha();

                    break;

                case "MIN":

                    if (app.ehVazia()){
                        System.out.println("EMPTY");
                    }else{
                        app.calculaMenor();
                        System.out.println(app.getMenor());
                    }
                    break;
                
                default:
                }

		}
        
        leitor.close();
    }

    public Stack<Integer> getPilha()
    {
        return this.pilha;
    }

    public void setPilha(Stack<Integer> pilha)
    {
        this.pilha = pilha;
    }

    public void empilha(int valor){
        Stack<Integer> _pilha = this.getPilha();
        
        _pilha.push(valor);

        this.setPilha(_pilha);
    }

    public int desenpilha(){
        Stack<Integer> _pilha = this.getPilha();

        int valor = _pilha.pop();

        this.setPilha(_pilha);

        return valor;
    }

    public boolean ehVazia(){
        Stack<Integer> _pilha = this.getPilha();

        return _pilha.isEmpty();
    }

    public int getMenor(){
        return this.menor;
    }

    public void setMenor(int menor){
        this.menor = menor;
    }

    public void calculaMenor(){
        Stack<Integer> _pilha = this.getPilha();

        int menor = _pilha.peek();

        for (int valor : _pilha) {
            if (valor < menor) {
                menor = valor;
            }
        }

        this.setMenor(menor);
    }



}