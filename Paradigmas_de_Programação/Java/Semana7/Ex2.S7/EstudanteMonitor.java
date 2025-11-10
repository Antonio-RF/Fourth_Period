public class EstudanteMonitor extends Estudante implements Acoes {
    protected String materia;

    //Método GET:
    public String getMateria() {
        return this.materia;
    }

    //Método SET:
    public void setMateria(String materia) {
        if (materia != null)
            this.materia = materia;
    }

    //Construtor:
    public EstudanteMonitor(String nome, int matricula, String materia) {
        super(nome, matricula);
        this.setMateria(materia);
    }

    public void disponibilizarHorarios() {
        System.out.printf("Os horários do monitor %s da matéria %s são às 18:00!\n", getNome(), getMateria());
    }
    public void tiraAsDuvidas() {
        System.out.printf("Dúvidas tiradas.\n");
    }



}