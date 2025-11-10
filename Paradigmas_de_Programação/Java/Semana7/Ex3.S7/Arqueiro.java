public class Arqueiro extends Personagem {

    //Construtor:
    public Arqueiro(String nome, int nivel, int forcaBase) {
        super(nome, nivel, forcaBase);
    }

    public double calcularDano() {
        return this.nivel * this.forcaBase * 15;
    }

}