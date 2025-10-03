public class CartaoDiaDosNamorados extends CartaoWeb {

    //Construtor:
    public CartaoDiaDosNamorados(String destinatario) {
        super(destinatario);
    }

    public void retornarMensagem(String remetente) {
        System.out.printf("\nQuerido %s, feliz dia dos namorados. De -%s\n", remetente, getDestinatario());
    }

}