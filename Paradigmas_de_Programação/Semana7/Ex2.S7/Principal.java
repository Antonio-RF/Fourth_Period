public class Principal {
    public static void main(String[] args) {
        EstudanteMonitor est1 = new EstudanteMonitorBolsista("Antonio", 2024, "Paradigmas");

        EstudanteMonitorBolsista est2 = null;

        if (est1 instanceof EstudanteMonitorBolsista) {
            est2 = (EstudanteMonitorBolsista)est1;
        }

        est2.enviarRelatório();
        est1.disponibilizarHorarios();
    }
}