public class Estudante {
    private String nome;
    private int notafinal;

    public String getNome(){
        if (this.nome != null)
            return this.nome;
        return null;
    }
    public int getNotaFinal() {
        if (this.notafinal > 0 && this.notafinal < 100)
            return this.notafinal; 
    }

    public void setNome(nome) {
        if (this.nome != null)
            this.nome = nome;
    }
    public void setNotaFinal(notafinal) {
        if (this.notafinal > 0 && this.notafinal < 100)
            this.notafinal = notafinal;
    }

    public String toString() {
        return String.format("A pessoa %s ficou com a nota final: %d\n", this.nome, this.nota);
    }
}
