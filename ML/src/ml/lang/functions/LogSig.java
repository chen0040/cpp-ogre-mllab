package ml.lang.functions;



public class LogSig implements FunctionX
{
	public double calculate(double x)
	{
		return 1/(Math.exp(-x)+1);
	}
}
