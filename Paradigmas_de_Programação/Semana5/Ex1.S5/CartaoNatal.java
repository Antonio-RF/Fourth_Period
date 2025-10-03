public class CartaoNatal extends CartaoWeb {

    //Construtor:
    public CartaoNatal(String destinatario) {
        super(destinatario);
    }

    public void retornarMensagem(String remetente) {
        System.out.printf("\nFeliz natal %s. De -%s\n", remetente, getDestinatario());
    }

}