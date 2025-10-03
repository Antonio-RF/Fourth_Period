public abstract class CartaoWeb {
    protected String destinatario;

    //Métodos GET:
    public String getDestinatario() {
        return this.destinatario;
    }

    //Métodos SET:
    public void setDestinatario(String destinatario) {
        if (destinatario != null)
            this.destinatario = destinatario;
    }

    //Construtor:
    public CartaoWeb(String destinatario) {
        this.setDestinatario(destinatario);
    }

    public abstract void retornarMensagem(String remetente); 


}