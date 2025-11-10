public class CartaoAniversario extends CartaoWeb {

    //Construtor:
    public CartaoAniversario(String destinatario) {
        super(destinatario);
    }

    public void retornarMensagem(String remetente) {
        System.out.printf("\nFeliz aniversário %s. De -%s\n", remetente, getDestinatario());
    }

}