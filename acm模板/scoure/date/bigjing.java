import java.util.*;
import java.math.*;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
         Scanner cin = new Scanner(System.in);
         while(cin.hasNext())
         {
           int n = cin.nextInt();//输入的方式比较的麻烦
           BigInteger a = new BigInteger(); //里面是字符串
           BigDecimal b = new BigDecimal();
           //接下来是比较常见的函数以及用法。
           a = a.add(a);a = a.multiply(a);
           BigInteger c = new BigInteger.valueOf(n);//类型转换
           subtract();//减法
           multiply();
           divide();    //相除取整
           remainder(); //取余
           pow();   a.pow(b)=a^b
           gcd();   //最大公约数
           abs(); //绝对值
           negate(); //取反数
           mod(); a.mod(b)=a%b=a.remainder(b);
         }
       }
     }
