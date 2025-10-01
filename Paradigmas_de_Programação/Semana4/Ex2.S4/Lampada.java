public class Lampada {
    protected boolean estado;

    //Método IS:
    public boolean isEstado() {
        return this.estado;
    }

    //Método SET:
    public void setEstado(boolean estado) {
        this.estado = estado;
    }

    //Construtor:
    public Lampada(boolean estado) {
        this.setEstado(estado);
    }

    //Método liga/desliga:
    public void ligaDesliga() {
        if (isEstado())
            this.estado = false;
        else
            this.estado = true;
    }



}