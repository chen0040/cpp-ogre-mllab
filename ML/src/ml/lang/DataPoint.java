package ml.lang;
import java.util.Vector;

public abstract class DataPoint {	
	public abstract int size();
	public abstract double get(int i);
	public abstract Vector<Double> getLowerBounds();
	public abstract Vector<Double> getUpperBounds();
	public abstract DataPoint clone();
	public abstract void set(int index, double value);
	
	public double distance(DataPoint pt)
	{
		double distance=0;
		for(int i=0; i < this.size(); ++i)
		{
			double d=(this.get(i)-pt.get(i));
			distance+=(d*d);
		}
		return Math.sqrt(distance);
	}
}
