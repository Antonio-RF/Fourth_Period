public class Principal {
    public static void main (String[] args) {
        CartaoWeb[] cartoes = new CartaoWeb[10];

        for (int i=0 ; i<10 ; i++) {
            if (i % 3 == 0) {
                cartoes[i] = new CartaoDiaDosNamorados("Enzo");
            }
            else if (i % 3 == 1) {
                cartoes[i] = new CartaoNatal("Ricardo");
            }
            else {
                cartoes[i] = new CartaoAniversario("Davi");
            }
        }

        for (int j=0 ; j<10 ; j++) {
            cartoes[j].retornarMensagem("Antonio");
        }



    }
}