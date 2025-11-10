public class LampadaFluorecente extends Lampada{
    private int comprimento;

    //Método GET:
    public int getComprimento() {
        return this.comprimento;
    }

    //Método SET:
    public void setComprimento(int comprimento) {
        if (comprimento > 0)
            this.comprimento = comprimento;
    }

    //Construtor:
    public LampadaFluorecente(boolean estado, int comprimento) {
        super(estado);
        this.setComprimento(comprimento);
    }


}