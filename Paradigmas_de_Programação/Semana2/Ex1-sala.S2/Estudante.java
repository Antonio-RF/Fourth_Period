public class Estudante {
    private String nome;
    private int notaFinal;

    public String getNome() {
        return this.nome;
    }
    public int getNotaFinal() {
        return this.notaFinal;
    }

    public void setNome(String nome) {
        if (nome != null)
            this.nome = nome;
    }
    public void setNotaFinal(int notaFinal) {
        if (notaFinal > 0 && notaFinal < 100)
            this.notaFinal = notaFinal;
    }

    public void cadastrarEstudante(String nome, int notaFinal) {
        setNome(nome);
        setNotaFinal(notaFinal);
    }

    public void exibirDados() {
        System.out.printf("O estudante %s é muito inteligente. Sua nota foi: %d%n", getNome(), getNotaFinal());
    }

}