import java.util.Scanner;
import java.util.Stack;
import java.util.Queue;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Collections;

public class Main {

    private static String adivinharEstrutura(int quantidadeOperacoes, Scanner leitor) {
        Stack<Integer> pilha = new Stack<>();
        Queue<Integer> fila = new LinkedList<>();
        PriorityQueue<Integer> filaPrioridade = new PriorityQueue<>(Collections.reverseOrder());

        boolean pilhaValida       = true;
        boolean filaValida        = true;
        boolean prioridadeValida  = true;

        for (int i = 0; i < quantidadeOperacoes; i++) {
            int operacao = leitor.nextInt();
            int elemento = leitor.nextInt();

            if (operacao == 1) {
                if (pilhaValida)      pilha.push(elemento);
                if (filaValida)       fila.offer(elemento);
                if (prioridadeValida) filaPrioridade.offer(elemento);
            }
            else { // operacao == 2
                if (pilhaValida) {
                    if (pilha.isEmpty() || pilha.pop() != elemento)
                        pilhaValida = false;
                }
                if (filaValida) {
                    if (fila.isEmpty() || fila.poll() != elemento)
                        filaValida = false;
                }
                if (prioridadeValida) {
                    if (filaPrioridade.isEmpty() || filaPrioridade.poll() != elemento)
                        prioridadeValida = false;
                }
            }
        }

        if (pilhaValida && !filaValida && !prioridadeValida) {
            return "stack";
        } else if (!pilhaValida && filaValida && !prioridadeValida) {
            return "queue";
        } else if (!pilhaValida && !filaValida && prioridadeValida) {
            return "priority queue";
        } else if (!pilhaValida && !filaValida && !prioridadeValida) {
            return "impossible";
        } else {
            return "not sure";
        }
    }

    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);
        StringBuilder saida = new StringBuilder();

        while (leitor.hasNextInt()) {
            int quantidadeOperacoes = leitor.nextInt();
            saida.append(adivinharEstrutura(quantidadeOperacoes, leitor));
            saida.append('\n');
        }

        System.out.print(saida);
        leitor.close();
    }
}
