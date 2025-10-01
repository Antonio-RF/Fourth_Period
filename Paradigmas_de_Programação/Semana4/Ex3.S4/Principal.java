public class Principal {
    public static void main(String[] args) {

        IngressoNormal[] normais = new IngressoNormal[25];
        IngressoVip[] vips = new IngressoVip[25];
        IngressoVipCamarote[] camarotes = new IngressoVipCamarote[25];

        for (int i=0 ; i<25 ; i++) {
            normais[i] = new IngressoNormal(100);
            vips[i] = new IngressoVip(100, 50);
            camarotes[i] = new IngressoVipCamarote(100, 50, 1130);
        }

        System.out.printf("Ingressos Normais: \n");
        for (IngressoNormal i : normais) {
            i.exibirDados();
        }

        System.out.printf("\nIngressos Vips:\n");
        for (IngressoVip i : vips) {
            i.exibirDados();
        }

        System.out.printf("\nIngressos Camarotes:\n");
        for (IngressoVip i : camarotes) {
            i.exibirDados();
        }

    }
}