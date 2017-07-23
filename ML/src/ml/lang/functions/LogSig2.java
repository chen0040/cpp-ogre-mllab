package ml.lang.functions;

public class LogSig2 extends LogSig{
	public double calculate(double x)
	{
		if(super.calculate(x) < 0.5)
		{
			return 0;
		}
		return 1;
	}
}
