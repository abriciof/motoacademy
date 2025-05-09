import java.util.Scanner;
import java.util.Stack;

public class Main {
    private static int quantidadeDiamantes(String linha) {
        Stack<Character> pilha = new Stack<>();
        int diamantes = 0;

        for (char c : linha.toCharArray()) {
            if (c == '<') {
                pilha.push(c);
            } else if (c == '>' && !pilha.isEmpty()) {
                pilha.pop();
                diamantes++;
            }
        }

        return diamantes;
    }

    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);
        int tamanho_entrada = leitor.nextInt();
        StringBuilder saida = new StringBuilder();

        for (int i = 0; i < tamanho_entrada; i++) {
            String linha = leitor.next();
            saida.append(quantidadeDiamantes(linha));
            saida.append('\n');
        }

        System.out.print(saida);
        leitor.close();
    }
}