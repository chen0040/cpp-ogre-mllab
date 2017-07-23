package ml.lang;

public interface BinaryDataPoint {
	public int size();
	public boolean get(int index);
	public void set(int index, boolean value);
	//public double avgValue();
}
