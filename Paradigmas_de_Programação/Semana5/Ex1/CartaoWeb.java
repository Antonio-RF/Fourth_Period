public abstract class CartaoWeb {
    protected String destinatario;

    //Construtor da super classe:
    public CartaoWeb(String destinatario) {
        this.setDestinatario(destinatario);
    }

    //Métodos get e set:
    public String getDestinatario() {
        return this.destinatario;
    }
    public void setDestinatario(String destinatario) {
        if (destinatario != null)
            this.destinatario = destinatario;
    }

    //Método abstrato que você vai usar nas classes filhas:
    public abstract String retornarMensagem(String remetente);

}