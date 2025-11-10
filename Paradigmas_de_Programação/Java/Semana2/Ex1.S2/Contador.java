public class Contador {
    private int contador;

    public int getContador() {
        return this.contador;
    }
    public void setContador(int contador) {
        if (contador >= 0)
            this.contador = contador;
    }

    public void ZeraContador() {
        this.contador = 0;
    }
    public void IncrementaContador(int valor) {
        if (valor > 0)
            this.contador += valor;
    }
    public void DecrementaContador(int valor) {
        if (valor > 0) {
            if (this.contador - valor >= 0) 
                this.contador -= valor; 
            else
                this.contador = 0;
        }
    }

}