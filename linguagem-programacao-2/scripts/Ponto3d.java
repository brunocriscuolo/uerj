import java.util.Scanner;

class Ponto3d{
	private int x;
	private int y;
	private int z;

	public Ponto3d(){
		this.x = 0;
		this.y = 0;
		this.z = 0;	
	}

	public void setX(int a){
		this.x = a;	
	}

	public void setY(int b){
		this.y = b;
	}

	public void setZ(int c){
		this.z = c;
	}

	public String toString(){
		return "O ponto (x,y,z) é ("+x+","+y+","+z+")";
	}


	public static void main(String args[]){
		Ponto3d p = new Ponto3d();
		Scanner s = new Scanner(System.in);
		
		System.out.print("Coordenada x: ");		
		p.setX(s.nextInt());

		System.out.print("Coordenada y: ");
		p.setY(s.nextInt());

		System.out.print("Coordenada z: ");
		p.setZ(s.nextInt());

		System.out.println(p);
	}
}
