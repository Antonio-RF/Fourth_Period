public class CartaoNatal extends CartaoWeb {
    
    //Pegando da mãe:
    public CartaoNatal(String destinatario) {
        super(destinatario);
    }

    @Override
    public String retornarMensagem(String remetente) {
        String mensagem = "Feliz natal " + this.getDestinatario() + ", de " + remetente+ "\n";

        return mensagem;
    }

}