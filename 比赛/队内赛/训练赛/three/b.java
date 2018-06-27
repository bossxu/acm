import java.util.*;
import java.math.BigDecimal;
public class Main {


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int t;
		t = in.nextInt();
		while(t!=0){
		BigDecimal []x = new BigDecimal[6];
		BigDecimal []y = new BigDecimal[6];
		for(int i  = 1 ;i<=4;i++)
		{
			x[i] = in.nextBigDecimal();
			y[i] = in.nextBigDecimal();
		}
		BigDecimal a,b,c,d,e,f,two;
		two = new BigDecimal("2.0");
		// ax+by = c; a = 2(x2-x1) b = 2(y2-y1) c = y2^2 -y1^2+x2^2-x1^2;
		a = two.multiply(x[2].subtract(x[1]));
		b = two.multiply(y[2].subtract(y[1]));
		c = y[2].multiply(y[2]).add(x[2].multiply(x[2])).subtract(x[1].multiply(x[1])).subtract(y[1].multiply(y[1]));
		d = two.multiply(x[2].subtract(x[3]));
		e = two.multiply(y[2].subtract(y[3]));
		f = y[2].multiply(y[2]).add(x[2].multiply(x[2]).subtract(x[3].multiply(x[3])).subtract(y[3].multiply(y[3])));
		x[5] = (b.multiply(f).subtract(c.multiply(e))).divide(b.multiply(d).subtract(a.multiply(e)));
		y[5] = (a.multiply(f).subtract(c.multiply(d))).divide(a.multiply(e).subtract(b.multiply(d)));
		BigDecimal r,dis;
		r = (x[3].subtract(x[5])).multiply(x[3].subtract(x[5])).add((y[3].subtract(y[5])).multiply(y[3].subtract(y[5])));
		dis = (x[5].subtract(x[4])).multiply(x[5].subtract(x[4])).add((y[5].subtract(y[4])).multiply(y[5].subtract(y[4])));
		//System.out.println(x[5]);
		if(dis.compareTo(r) == 1)
		{
			System.out.println("Accepted");
		}
		else
		{
			System.out.println("Rejected");
		}
		t--;
		}
	}

}
