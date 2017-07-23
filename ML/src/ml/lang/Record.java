package ml.lang;

public interface Record {
	public String getValue(String name);
	public String getField(int index);
	public int size();
}
