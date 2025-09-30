public class Time {
    private int hora;
    private int minuto;

    //Métodos GET:
    public int getHora() {
        return this.hora;
    }
    public int getMinuto() {
        return this.minuto;
    }

    //Métodos SET:
    public void setHora(int hora) {
        if (hora >= 0 && hora < 24)
            this.hora = hora;
    }
    public void setMinuto(int minuto) {
        if (minuto >= 0 && minuto < 60)
            this.minuto = minuto;
    }

    public boolean anterior(int h, int m) {
        if (h < this.hora)
            return true;
        if (h > this.hora)
            return false;
        
        if (m < this.minuto)
            return true;
        return false;
    }
    public boolean posterior(int h, int m) {
        if (h < this.hora)
            return false;
        if (h > this.hora)
            return true;
        
        if (m > this.minuto)
            return true;
        return false;
    }
    public boolean equals(int h, int m) {
        if (h == this.hora && m == this.minuto)
            return true;
        return false;
    }
    public String toString() {
        return String.format("%02d:%02d", this.hora, this.minuto);
    }
}