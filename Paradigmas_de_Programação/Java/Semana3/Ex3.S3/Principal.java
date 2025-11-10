public class Principal {
    public static void main(String[] args) {
        Turma bcc = new Turma("Rachel", 101);

        Aluno alu1 = new Aluno("Antonio", 2024);
        Aluno alu2 = new Aluno("Enzo", 2023);
        Aluno alu3 = new Aluno("Victor", 2020);

        bcc.adicionarAluno(alu1);
        bcc.adicionarAluno(alu2);
        bcc.adicionarAluno(alu3);
        
        bcc.exibirAlunos();
    }
}