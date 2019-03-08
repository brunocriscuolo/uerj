import java.util.Scanner;

class Ponto2d{
	private int x;
	private int y;

	public Ponto2d(){
		this.x = 0;
		this.y = 0;	
	}

	public void setX(int a){
		this.x = a;	
	}

	public void setY(int b){
		this.y = b;
	}

	public String toString(){
		return "O ponto (x,y) é ("+x+","+y+")";
	}


	public static void main(String args[]){
		Ponto2d p = new Ponto2d();
		Scanner s = new Scanner(System.in);
		
		System.out.print("Coordenada x: ");		
		p.setX(s.nextInt());

		System.out.print("Coordenada y: ");
		p.setY(s.nextInt());

		System.out.println(p);
	}
}
