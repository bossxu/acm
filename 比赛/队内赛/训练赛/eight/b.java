import java.util.*;
import java.math.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s1,s2,s3;
		Scanner in = new Scanner(System.in);
		s1 = in.next();
		int len = s1.length();
		//System.out.println(len);
		int tot = 0;
		for(int i =0;i<len;i++)
		{
			if(s1.charAt(i)=='e')
			{
				tot = i;
				break;
			}
		}
		//System.out.println(tot);
		s2 = s1.substring(0,tot);
		s3 = s1.substring(tot+1);
		BigDecimal a = new BigDecimal(s2);
		BigInteger b = new BigInteger(s3);
		BigDecimal ten = new BigDecimal("10");
		BigInteger o = new BigInteger("0");
		while(!b.equals(o))
		{
			//System.out.println(b);
			a = a.multiply(ten);
			b = b.subtract(new BigInteger("1"));
		}
		System.out.println(a.stripTrailingZeros().toPlainString());
	}

}
