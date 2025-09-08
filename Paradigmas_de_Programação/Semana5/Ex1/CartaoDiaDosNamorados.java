public class CartaoDiaDosNamorados extends CartaoWeb {
    
    //Pegando da mãe:
    public CartaoDiaDosNamorados(String destinatario) {
        super(destinatario);
    }

    @Override
    public String retornarMensagem(String remetente) {
        String mensagem = "Feliz dia dos namorados " + this.getDestinatario() + ", de " + remetente+ "\n";

        return mensagem;
    }

}