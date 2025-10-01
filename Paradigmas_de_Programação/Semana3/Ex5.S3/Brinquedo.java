public class Brinquedo {
    private String nomeDoBrinquedo;
    private double alturaMinima;
    private int precoDoIngresso;

    //Métodos GET:
    public String getNomeDoBrinquedo() {
        return this.nomeDoBrinquedo;
    }
    public double getAlturaMinima() {
        return this.alturaMinima;
    }
    public int getPrecoDoIngresso() {
        return this.precoDoIngresso;
    }

    //Métodos SET:
    public void setNomeDoBrinquedo(String nomeDoBrinquedo) {
        if (nomeDoBrinquedo != null)
            this.nomeDoBrinquedo = nomeDoBrinquedo;
    }
    public void setAlturaMinima(double alturaMinima) {
        if (alturaMinima > 0)
            this.alturaMinima = alturaMinima;
    }
    public void setPrecoDoIngresso(int precoDoIngresso) {
        if (precoDoIngresso > 0)
            this.precoDoIngresso = precoDoIngresso;
    }

    //Construtor:
    public Brinquedo(String nomeDoBrinquedo, double alturaMinima, int precoDoIngresso) {
        this.setNomeDoBrinquedo(nomeDoBrinquedo);
        this.setAlturaMinima(alturaMinima);
        this.setPrecoDoIngresso(precoDoIngresso);
    }

    //Métodos:
    public boolean verificaAltura(double alturaPessoa) {
        if (alturaPessoa >= this.alturaMinima)
            return true;
        return false;
    }    
}