public class Guerreiro extends Personagem {

    //Construtor:
    public Guerreiro(String nome, int nivel, int forcaBase) {
        super(nome, nivel, forcaBase);
    }

    public double calcularDano() {
        return this.nivel * this.forcaBase * 1.2;
    }


}