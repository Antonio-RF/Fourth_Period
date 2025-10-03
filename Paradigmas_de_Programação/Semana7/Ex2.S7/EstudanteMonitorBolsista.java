public class EstudanteMonitorBolsista extends EstudanteMonitor {

    //Construtor:
    public EstudanteMonitorBolsista(String nome, int matricula, String materia)  {
        super(nome, matricula, materia);
    }

    public void enviarRelatório() {
        System.out.printf("Relatório do monitor %s enviado com sucesso!\n", getNome());
    }

}