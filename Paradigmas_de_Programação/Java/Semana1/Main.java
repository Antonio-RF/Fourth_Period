import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Estudante[] classe = new Estudante[5];
        Scanner input = new Scanner(System.in);
        int media = 0;

        //Lendo e colocando no vetor:
        for (int i=0 ; i<5 ; i++) {
            classe[i] = new Estudante();
            
            System.out.print("Digite o nome: ");
            String nome = input.nextLine();
            System.out.print("Digite a nota: ");
            int nota = input.nextInt();
            //limpando o buffer:
            input.nextLine();

            classe[i].setNome(nome);
            classe[i].setNotaFinal(nota);
        }

        //Calculando a média:
        for (int k=0 ; k<5 ; k++) {
            media += classe[k],getNotaFinal();
        }
        media /= 5;



    }
}