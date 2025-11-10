import java.util.Scanner;

public class Principal {
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);

        Estudante[] alunos = new Estudante[5];
        for (int i=0 ; i<5 ; i++) {
            alunos[i] = new Estudante();

            String ni = teclado.next();
            int notai = teclado.nextInt();

            alunos[i].cadastrarEstudante(ni, notai);
        }

        int media = 0;
        int exame = 0;
        int reprovados = 0;
        for (int i=0 ; i<5 ; i++) {
            int temp_nota = alunos[i].getNotaFinal();
            media += temp_nota;

            if (temp_nota >= 40 && temp_nota <= 69)
                exame++;

            else if (temp_nota < 40)
                reprovados++;
        }

        System.out.printf("Média final: %d\n", media/5);
        System.out.printf("Alunos de exame: %d\n", exame);
        System.out.printf("Alunos reprovados: %d\n", reprovados);

        teclado.close();

    }
}