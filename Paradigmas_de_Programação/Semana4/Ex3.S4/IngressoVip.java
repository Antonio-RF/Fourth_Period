public class IngressoVip extends Ingresso {
    protected int valorAdicionalVip;

    //Método GET:
    public int getValorAdicionalVip() {
        return this.valorAdicionalVip;
    }

    //Método SET:
    public void setValorAdicionalVip(int valorAdicionalVip) {
        if (valorAdicionalVip > 0)
            this.valorAdicionalVip = valorAdicionalVip;
    }

    //Construtor:
    public IngressoVip(int valorIngresso, int valorAdicionalVip) {
        super(valorIngresso);
        this.setValorAdicionalVip(valorAdicionalVip);
    } 

    public int adicionarValorVip() {
        this.valorIngresso += this.valorAdicionalVip;
        return this.valorIngresso;
    }

}