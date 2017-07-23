package bayse.classifier.naive;

import java.util.HashMap;
import java.util.Vector;
import ml.lang.Record;
import java.util.Iterator;

public class NaiveBayseClassifier {
	protected Vector<Record> m_records=new Vector<Record>();
	
	public NaiveBayseClassifier()
	{
		
	}
	
	public void addRecord(Record rec)
	{
		m_records.add(rec);
	}
	
	public String predict(Record rec, String class_label)
	{
		String correct_value=null;
		
		HashMap<String, Vector<Record>> class_partitions=split(m_records, class_label);
		
		double max_prob=0;
		Iterator<String> is=class_partitions.keySet().iterator();
		while(is.hasNext())
		{
			String kis=is.next();
			double prob=calcProbability(class_partitions.get(kis), m_records.size(), rec, class_label);
			if(prob > max_prob)
			{
				max_prob=prob;
				correct_value=kis;
			}
		}
		
		return correct_value;
	}
	
	public double calcProbability(Vector<Record> class_partition, int record_count, Record rec, String class_label)
	{
		//probability P(C)
		double PC=(double)class_partition.size() / record_count;
		double prob=PC;
		for(int i=0; i<rec.size(); i++)
		{
			String field=rec.getField(i);
			if(!field.equals(class_label))
			{
				//probability P(f_i | C)
				double PfC=(double)getRecordCount(class_partition, field, rec.getValue(field)) / class_partition.size();
				
				prob*=PfC;
			}
		}
		
		//prob P(C | f_0, f_1, f_2, ... , f_N)=P(C) * P(f_0 | C) * P(f_1 | C) * ... * P(f_N | C)
		return prob; 
	}
	
	public int getRecordCount(Vector<Record> partition, String field, String target_value)
	{
		int count=0;
		for(int i=0; i<partition.size(); i++)
		{
			Record rec=partition.get(i);
			if(rec.getValue(field).equals(target_value))
			{
				count++;
			}
		}
		
		return count;
	}
	
	protected HashMap<String, Vector<Record>> split(Vector<Record> partition, String attribute_label)
	{
		HashMap<String, Vector<Record>> subpartitions=new HashMap<String, Vector<Record>>();
		
		for(int i=0; i<partition.size(); i++)
		{
			Record rec=partition.get(i);
			String attrvalue=rec.getValue(attribute_label);
			if(subpartitions.containsKey(attrvalue))
			{
				subpartitions.get(attrvalue).add(rec);
			}
			else
			{
				Vector<Record> subpartition=new Vector<Record>();
				subpartition.add(rec);
				subpartitions.put(attrvalue, subpartition);
			}
		}
		
		return subpartitions;
	}
	
	
}
