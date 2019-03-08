import java.util.*;

public class Soma
{
	public static void main(String args[])
	{
		int num1;
		int num2;
		int soma;
		Scanner input;

		input = new Scanner(System.in);
		
		System.out.println("Informe o primeiro numero:");
		num1 = input.nextInt();

		System.out.println("Informe o segundo numero:");
		num2 = input.nextInt();

		soma = num1 + num2;

		System.out.println("A soma é:" + soma + " aula de java!");
		System.out.printf("A soma é: %d aula de java!\n",soma);

	}
}
