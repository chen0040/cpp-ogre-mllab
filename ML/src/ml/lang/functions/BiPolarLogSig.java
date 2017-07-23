package ml.lang.functions;

public class BiPolarLogSig implements FunctionX {
	public double calculate(double x)
	{
		return 2/(1+Math.exp(-x)) - 1;
	}
}
