import java.util.Scanner;

class Contador{
	
	private int cont;


	public Contador(){
 		zerar();
	}

	public void setContador(int c){
 		this.cont=c;
	}

	public void incrementar(int x){
		cont=cont+x;
	}

	public void zerar(){
		cont=0;
	}

	public String toString(){
		return ""+cont;
	}


	public static void main(String args[]){
	
		Contador c = new Contador();
		Scanner s = new Scanner(System.in);

		c.zerar();

		System.out.print("Valor inicial do contador = ");
		c.setContador(s.nextInt());
		System.out.println("O contador está sendo iniciado com valor "+c);

		System.out.print("Valor de incremento = ");
		c.incrementar(s.nextInt());
		System.out.println("O novo valor do contador é "+c);
	}
}
