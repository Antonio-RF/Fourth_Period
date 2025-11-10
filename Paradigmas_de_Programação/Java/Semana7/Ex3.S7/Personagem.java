public abstract class Personagem implements Comparable<Personagem>{
    protected String nome;
    protected int nivel;
    protected int forcaBase;

    //Métodos GET:
    public String getNome() {
        return this.nome;
    } 
    public int getNivel() {
        return this.nivel;
    }
    public int getForcaBase() {
        return this.forcaBase;
    }

    //Métodos SET:
    public void setNome(String nome) {
        if (nome != null)
            this.nome = nome;
    }
    public void setNivel(int nivel) {
        if (nivel > 0)
            this.nivel = nivel;
    }
    public void setForcaBase(int forcaBase) {
        if (forcaBase > 0)
            this.forcaBase = forcaBase;
    }

    //Construtor:
    public Personagem(String nome, int nivel, int forcaBase) {
        this.setNome(nome);
        this.setNivel(nivel);
        this.setForcaBase(forcaBase);
    }

    public abstract double calcularDano();

    public int compareTo(Personagem outro) {
        int cmp = Double.compare(outro.calcularDano(), this.calcularDano());
        if (cmp == 0) return this.nome.compareTo(outro.nome);
        return cmp;
    }

}