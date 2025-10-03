public class Mago extends Personagem {

    //Construtor:
    public Mago(String nome, int nivel, int forcaBase) {
        super(nome, nivel, forcaBase);
    }

    public double calcularDano() {
        return (this.nivel * this.forcaBase * 1.5) - 10;
    }

}