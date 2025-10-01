public class IngressoVipCamarote extends IngressoVip {
    private int valorAdicionalCamarote;

    //Método GET:
    public int getValorAdicionalCamarote() {
        return this.valorAdicionalCamarote;
    }

    //Método SET:
    public void setValorAdicionalCamarote(int valorAdicionalCamarote) {
        if (valorAdicionalCamarote > 0)
            this.valorAdicionalCamarote = valorAdicionalCamarote;
    }

    //Construtor:
    public IngressoVipCamarote(int valorIngresso, int valorAdicionalVip, int valorAdicionalCamarote) {
        super(valorIngresso, valorAdicionalVip);
        this.setValorAdicionalCamarote(valorAdicionalCamarote);
    }

    //Método adicionaPrecoVip:
    public int adicionarValorCamarote() {
        this.valorIngresso += this.valorAdicionalCamarote;
        return this.valorIngresso;
    }


}