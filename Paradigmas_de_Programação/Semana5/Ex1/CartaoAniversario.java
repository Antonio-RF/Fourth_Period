public class CartaoAniversario extends CartaoWeb {
    
    //Pegando da mãe:
    public CartaoAniversario(String destinatario) {
        super(destinatario);
    }

    @Override
    public String retornarMensagem(String remetente) {
        String mensagem = "Feliz aniversario " + this.getDestinatario() + ", de " + remetente + "\n";

        return mensagem;
    }

}