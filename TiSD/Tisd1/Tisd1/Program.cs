using System;
using System.Text.RegularExpressions;

namespace Tisd1
{
	class MainClass
	{
		public struct number
		{
			//sign=true => +
			public bool sign; //true означает +, false означает -
			public int[] mantissa;
			public int eps;
		}

		//конвертирование строки в структуру
		public static void Converter(string line, ref number num)
		{
			string temp;
			int eps_pos=0;
			num.sign = true;
			if  (line [0] == '-') {
				num.sign = false;
			}
			//mantissa

			try
			{	//выделяем часть между знаком и Е
				temp=line.Split(new Char [] { 'e', 'E' }) [0];
				try
				{
					temp=temp.Split(new Char [] { '+', '-' }) [1];
				}
				catch{}

				int j;
				int i;
				int mantis_length=30;
				num.mantissa=new int [mantis_length];

				//заполняем мантиссу с конца пропуская точку
				for(i=temp.Length-1, j=mantis_length-1; ((i>=0) && (j>=0)) ; i--,j--)
				{					
					if ((temp[i]==',')||(temp[i]=='.'))
					{
						eps_pos=temp.Length-1-i;
						j++;
					}
					else {
						num.mantissa[j]=temp[i]-'0';
					}
				}				
			}
			catch {
				num.eps = 0;
			}

			//Сохраняем показатель степени сдвинув его на количество символов после точки
			try	 {				
				num.eps = Convert.ToInt32(line.Split(new Char [] { 'e', 'E' }) [1])-eps_pos;
			}
			catch {
				num.eps = 0-eps_pos;
			}

			if (Math.Abs(num.eps) > 99999)
			{
				Console.WriteLine ("Ошибка показателя E");
				System.Environment.Exit(0);
			}
		}

		//Проверка ввода
		public static int  CheckInput(string line, string[] regarray)
		{
			if (line.Length == 0)
				return -1;
			string answer;
			//char [] sp=new
			if ((line [0] == '+') || (line [0] == '-')) {
				if (line.Split (new Char [] { 'e', 'E' }) [0].Length > 31)
					return -1;
			}
			else {
				if (line.Split (new Char [] { 'e', 'E' }) [0].Length > 30)
					return -1;
			}
			for (int i = 0; i < regarray.Length ; i++) 
			{
				answer=Regex.Match(line, regarray[i]).Value;
				if (answer == line) 
					return 0;
			}
							
			return -1;
			
		}

		//Печать мантиссы на экран
		public static void mantisePrint(int [] mantiss)
		{			
			Console.Write ("0.");

			//узнаем сколько символов с конца нам не нужно печатать
			int not_for_print = 0;
			for (int i = mantiss.Length - 1; i > 0; i--)
			{
			
				if (mantiss [i] == 0)
					not_for_print++;
				else
					break;				
			}

			int already_printed = 0;
			bool print_flag = false;
			//Печать на экран с обрезанием нулей  в начале, конце, и  обрезанием 30+ символов
			for( int i=0; (i<mantiss.Length-not_for_print) && (already_printed<30) ; i++)
			{
				if(mantiss[i]!=0)
					print_flag=true;
				
				if (print_flag==true)
				{
					already_printed++;
					Console.Write(mantiss[i]);
				}
			}
			if (already_printed == 0) {
				Console.Write(0);
			}

		}


		//умножение мантисс и изменение eps на количество вычесленных
		public static void countmantiss(number num1, number num2, ref number rez)
		{
			int pointer = 0;

			for (int i = num1.mantissa.Length-1 ; i >= 0; i--)
			{
				pointer = 0;
				for (int j = num2.mantissa.Length-1 ; j >= 0; j--)
				{
					rez.mantissa[i+j+1] += pointer + num1.mantissa[i]*num2.mantissa[j];
					//rez.mantissa[i+j]= rez.mantissa[i+j+1] / 10;						
					pointer = rez.mantissa[i+j+1] / 10;
					rez.mantissa[i+j+1] %= 10;	

				}
				rez.mantissa [i] += pointer;
			}

			//Изменение степени
			for (int i = 0; i < rez.mantissa.Length; i++) {
				if (rez.mantissa [i] != 0) 
				{
					rez.eps = 60 - i;
					break;
				}
			}


		}

		//Округление
		public static void round(ref number rez)
		{
			int k=0;
			for (int i = 0; (i < rez.mantissa.Length); i++)
			{
				if (rez.mantissa [i] != 0)
				{					
					k=i;
					break;
				}
			}
			if (k <= 30) 
			{
				if (rez.mantissa [30 + k] > 5) 
				{   
					int pointer = 1;
					int []result = new int [61];
					for (int i = 30 + k; i > k; i--)
					{
						result [i] = (pointer + rez.mantissa [i - 1]) % 10;
						pointer = (pointer + rez.mantissa [i - 1]) / 10;
					}
					rez.mantissa = result;
				}

			}
	
		}

		//подсчет показателя
		public static void couteps(number num1, number num2, ref number rez)
		{
			rez.eps += num1.eps + num2.eps;
		}

		//вычисление знака
		public static void coutsign(number num1, number num2, ref number rez)
		{
			rez.sign = num1.sign ^ num2.sign;
		}

		public static void Main (string[] args)
		{	
			//Регулярка для второго числа
			string [] regarray=new string[3];
			regarray[0] = "[+-]{0,1}[0-9]{0,30}[.,]{0,1}[0-9]{1,30}[eE]{0,1}[+-]{0,1}[0-9]{1,5}";
			regarray[1] = "[+-]{0,1}[0-9]{0,30}[.,]{0,1}[0-9]{1,30}";
			regarray[2] = "[+-]{0,1}[0-9]{0,30}";

			//Регулярка для первого числа
			string [] regarray2=new string[1];
			regarray2[0] = "[+-]{0,1}[0-9]{0,30}";

			number num1 = new number ();
			number num2 = new number ();
			number rez = new number ();
			rez.eps = 0;
			rez.mantissa = new int[60];
			rez.sign = true;
			string line;

			Console.WriteLine ("Умножение целого числа на действительное");
			Console.WriteLine ("------------------------------");
			Console.WriteLine ("Введите целое число");
			line = Console.ReadLine ();

			while (CheckInput (line, regarray2) != 0) {
				Console.WriteLine ("Ошибка в формате ввода.");
				System.Environment.Exit(0);
				line = Console.ReadLine ();
			}
				
			Converter (line, ref num1);
			Console.WriteLine ("------------------------------");
			Console.WriteLine ("Введите действительное число");			
			line = Console.ReadLine ();
			while (CheckInput (line, regarray) != 0) {
				Console.WriteLine ("Ошибка в формате ввода.");
				System.Environment.Exit(0);
				line = Console.ReadLine ();
			}

			Converter (line, ref num2);

			//вычисления
			countmantiss (num1, num2, ref rez);
			couteps (num1, num2, ref rez);
			coutsign (num1, num2, ref rez);
			round (ref rez);
			if (Math.Abs (rez.eps) > 99999)
			{
				Console.WriteLine ("Ошибка показателя E");
			}
			else 
			{
			
				//Печать результата на экран
				if (rez.sign) {
					Console.Write ('-');
				}
				else
					Console.Write ('+');
				mantisePrint (rez.mantissa);
				Console.Write ("E{0}", rez.eps);
				Console.Write ("\n");	
			}

		}
	}
}