public class ContaBancaria {
    private String nomeDoTitulo;
    private int saldo;
    private int limiteDeSaque;

    //Métodos Get:
    public String getNomeDoTitulo() {
        return this.nomeDoTitulo;
    }
    public int getSaldo() {
        return this.saldo;
    }
    public int getLimiteDeSaque() {
        return this.limiteDeSaque;
    }

    //Métodos Set:
    public void setNomeDoTitulo(String nomeDoTitulo) {
        if (nomeDoTitulo != null)
            this.nomeDoTitulo = nomeDoTitulo;
    }
    public void setSaldo(int saldo) {
        if (saldo > 0)
            this.saldo = saldo;
    }
    public void setLimiteDeSaque(int limiteDeSaque) {
        if (limiteDeSaque < this.saldo)
            this.limiteDeSaque = limiteDeSaque;
    }

    //Métodos pedidos:
    public void Depositar(int valor) {
        if (valor > 0)
            this.saldo += valor;
    }
    public int Sacar(int valor) {
        if (valor > 0 && valor <= this.limiteDeSaque) {
            this.saldo -= valor;
            return valor;
        }
        return -1;
    }

}