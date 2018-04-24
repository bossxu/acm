import java.math.*;
import java.util.*;
//计蒜课上的一道水题
public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		while(true)
		{
          BigInteger a,b;
          String s;
          s = in.nextLine();
          a = new BigInteger(s);
          StringBuffer o = new StringBuffer(s);
          o.reverse();
          b = new BigInteger(o.toString());
          BigInteger c = new BigInteger("10");
          BigInteger e = new BigInteger("9");
          BigInteger d = a.subtract(b);
          d = d.divide(e);
          BigInteger l = new BigInteger("0");
          if(d.compareTo(l) == -1)
          {
        	  d=d.multiply(new BigInteger("-1"));
          }
          BigInteger f = d.mod(c);
          BigInteger g;
          int flag = 1;
         // System.out.println(d);
          while(!d.equals(l))
          {
        	  g = d.mod(c);
        	  if(!g.equals(f))
        	  {
        		  flag = 0;
        	  }
        	 d = d.divide(c);
        	  //System.out.println(d);
          }

          if(flag==1)
          {
        	  System.out.println("YES");
          }
          else
          {
        	  System.out.println("NO");
          }

		}
	}

}
