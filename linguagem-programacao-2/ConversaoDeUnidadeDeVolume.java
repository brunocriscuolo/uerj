import java.util.*;

class ConversaoDeUnidadeDeVolume{

	private double litro;
	private double metroCubico;
	private double galaoAmericano;

	private ConversaoDeUnidadeDeVolume(){}

	public static double litro2cm3(double litro){
		return litro*1000;
	}
	
	public static double m3tolitro(double metroCubico){
		return metroCubico*1000;
	}

	public static double m3topes(double metroCubico){
		return metroCubico*35.32;
	}

	public static double galao2pol3(double galaoAmericano){
		return galaoAmericano*231;
	}

	public static double galao2litro(double galaoAmericano){
		return galaoAmericano*3785;
	}


	public static void main(String args[]){

	double convertido1 = ConversaoDeUnidadeDeVolume.m3tolitro(1890);
	System.out.println("Valor convertido = " + convertido1 + " litros");

	double convertido2 = ConversaoDeUnidadeDeVolume.m3topes(1890);
	System.out.println("Valor convertido = " + convertido2 + " pés cúbicos");
	
	double convertido3 = ConversaoDeUnidadeDeVolume.litro2cm3(convertido1);
	System.out.println("Valor convertido = " + convertido3 + " cm³");
	
	}
}
