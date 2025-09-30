import java.util.ArrayList;
public class Turma {
    private int codigo;
    private String nomeProfessor;
    private ArrayList<Aluno> alunos;

    //Métodos GET:
    public int getCodigo() {
        return this.codigo;
    }
    public String getNomeProfessor() {
        return this.nomeProfessor;
    }
    public ArrayList<Aluno> getAlunos() {
        return this.alunos;
    }

    //Métodos SET:
    public void setCodigo(int codigo) {
        if (codigo > 0)
            this.codigo = codigo;
    }
    public void setNomeProfessor(String nomeProfessor) {
        if (nomeProfessor != null)
            this.nomeProfessor = nomeProfessor;
    }

    //Construtores:
    public Turma(String nomeProfessor, int codigo) {
        this.setNomeProfessor(nomeProfessor);
        this.setCodigo(codigo);
        this.alunos = new ArrayList<>();
    }
    public Turma(int codigo, String nomeProfessor) {
        this.setCodigo(codigo);
        this.setNomeProfessor(nomeProfessor);
        this.alunos = new ArrayList<>();
    }

    //Método adicionar aluno:
    public void adicionarAluno(Aluno alu) {
        this.alunos.add(alu);
    }
    //Método para exibir alunos:
    public void exibirAlunos() {
        for (Aluno a : alunos) {
            System.out.printf("Aluno: %s com matrícula %d\n", a.getNome(), a.getGRR());
        }
    }


}