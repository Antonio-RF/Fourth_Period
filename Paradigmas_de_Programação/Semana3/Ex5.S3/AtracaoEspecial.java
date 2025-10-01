public class AtracaoEspecial {
    private String nomeDaAtracao;
    private int capacidadeMaxima;
    private int qntdPessoasPresentes;

    //Métodos GET:
    public String getNomeDaAtracao() {
        return this.nomeDaAtracao;
    }
    public int getCapacidadeMaxima() {
        return this.capacidadeMaxima;
    }
    public int getQntdPessoasPresentes() {
        return this.qntdPessoasPresentes;
    }

    //Métodos SET:
    public void setNomeDaAtracao(String nomeDaAtracao) {
        if (nomeDaAtracao != null)
            this.nomeDaAtracao = nomeDaAtracao;
    }
    public void setCapacidadeMaxima(int capacidadeMaxima) {
        if (capacidadeMaxima > 0)
            this.capacidadeMaxima = capacidadeMaxima;
    }
    public void setQntdPessoasPresentes(int qntdPessoasPresentes) {
        if (qntdPessoasPresentes > 0)
            this.qntdPessoasPresentes = qntdPessoasPresentes;
    } 

    //Construtor:
    public AtracaoEspecial(String nomeDaAtracao, int capacidadeMaxima, int qntdPessoasPresentes) {
        this.setNomeDaAtracao(nomeDaAtracao);
        this.setCapacidadeMaxima(capacidadeMaxima);
        this.setQntdPessoasPresentes(qntdPessoasPresentes);
    }

    public boolean verificaCapacidadeMaxima() {
        if (this.capacidadeMaxima < this.qntdPessoasPresentes)
            return false;
        return true;
    }
    public void adicionaPessoas(int num) {
        if (num > 0)
            this.qntdPessoasPresentes += num;
    }

}