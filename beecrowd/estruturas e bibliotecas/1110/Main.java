import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
import java.util.List;
import java.util.ArrayList;

public class Main {

    private static void processarCards(int quantidadeCartas, StringBuilder saida) {
        Queue<Integer> filaCartas = new LinkedList<>();
        
        for (int i = 1; i <= quantidadeCartas; i++) {
            filaCartas.offer(i);
        }

        List<Integer> cartasDescartadas = new ArrayList<>();

        while (filaCartas.size() >= 2) {
            // descarta o topo
            // move a próxima carta para o final da fila

            cartasDescartadas.add(filaCartas.poll());
            filaCartas.offer(filaCartas.poll());
        }

        if (cartasDescartadas.isEmpty()) {
            saida.append("Discarded cards:\n");
        } else {
            saida.append("Discarded cards: ");
            for (int i = 0; i < cartasDescartadas.size(); i++) {
                if (i > 0) {
                    saida.append(", ");
                }
                saida.append(cartasDescartadas.get(i));
            }
            saida.append("\n");
        }

        saida.append("Remaining card: ");
        saida.append(filaCartas.peek());
        saida.append("\n");
    }

    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);
        StringBuilder saida = new StringBuilder();

        while (true) {
            int quantidadeCartas = leitor.nextInt();
            if (quantidadeCartas == 0) break;
            processarCards(quantidadeCartas, saida);
        }

        System.out.print(saida);
        leitor.close();
    }
}
