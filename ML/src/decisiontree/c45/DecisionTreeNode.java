package decisiontree.c45;

import java.util.Vector;
import org.w3c.dom.Element;
import java.util.HashMap;
import java.util.Iterator;

import ml.lang.Record;

public class DecisionTreeNode {
	Vector<Record> m_records=new Vector<Record>();
	String m_class_label;
	String m_attribute_label=null;
	HashMap<String, DecisionTreeNode> m_children;
	double m_information_gain=0;
	
	public void clear_children()
	{
		if(m_children != null)
		{
			m_children.clear();
		}
	}
	
	public DecisionTreeNode(String class_label)
	{
		m_class_label=class_label;
	}
	
	public void addRecord(Record record)
	{
		m_records.add(record);
	} 
	
	public int record_count()
	{
		return m_records.size();
	}
	
	public Record get_record(int index)
	{
		return m_records.get(index);
	}
	
	public boolean isLeave()
	{
		return m_children.size()==0;
	}
	
	public String get_class_label()
	{
		return m_class_label;
	}
	
	public final double get_information_gain()
	{
		return m_information_gain;
	}
	
	public String predict(Record record)
	{
		if(m_attribute_label==null)
		{
			String correct_output=null;
			int max_count=0;
			Iterator<String> kis=m_children.keySet().iterator();
			while(kis.hasNext())
			{
				String output=kis.next();
				int rscount=m_children.get(output).record_count();
				if(rscount > max_count)
				{
					max_count=rscount;
					correct_output=output;
				}
			}
			
			return correct_output;
		}
		else 
		{
			String attribute_value=record.getValue(m_attribute_label);
			if(m_children.containsKey(attribute_value))
			{
				
				DecisionTreeNode child= m_children.get(attribute_value);
				return child.predict(record);
			}
			else
			{
				return null;
			}
		}
	}
	
	public void split(Vector<String> attribute_labels)
	{
		m_information_gain=0;
		for(int i=0; i<attribute_labels.size(); i++)
		{
			String attribute_label=attribute_labels.get(i);
			double g=gain(attribute_label);
			if(m_information_gain < g)
			{
				m_information_gain=g;
				m_attribute_label=attribute_label;
			}
		}
	
		if(m_attribute_label==null)
		{
			m_children=this.split(this, m_class_label);
		}
		else
		{
			m_children=this.split(this, m_attribute_label);
			
			Vector<String> child_attribute_labels=new Vector<String>();
			for(int i=0; i<attribute_labels.size(); i++)
			{
				String attribute_label=attribute_labels.get(i);
				if(!attribute_label.equals(m_attribute_label))
				{
					child_attribute_labels.add(attribute_label);
				}
			}
			
			if(child_attribute_labels.size() > 0)
			{
				Iterator<String> kis=m_children.keySet().iterator();
				while(kis.hasNext())
				{
					String ki=kis.next();
					DecisionTreeNode child=m_children.get(ki);
					child.split(child_attribute_labels);
				}
			}
			else //unlikely to be executed but included here any way :D
			{
				Iterator<String> kis=m_children.keySet().iterator();
				while(kis.hasNext())
				{
					String ki=kis.next();
					DecisionTreeNode child=m_children.get(ki);
					child.split(m_class_label);
				}
			}
		}
	}
	
	public void BuildXml(Element parent_node)
	{
		
	}
	
	public void split(String attribute_label)
	{
		m_children=split(this, attribute_label);
	}
	
	protected HashMap<String, DecisionTreeNode> split(DecisionTreeNode partition, String attribute_label)
	{
		HashMap<String, DecisionTreeNode> subpartitions=new HashMap<String, DecisionTreeNode>();
		
		for(int i=0; i<partition.record_count(); i++)
		{
			Record rec=partition.get_record(i);
			String attrvalue=rec.getValue(attribute_label);
			if(subpartitions.containsKey(attrvalue))
			{
				subpartitions.get(attrvalue).addRecord(rec);
			}
			else
			{
				DecisionTreeNode subpartition=new DecisionTreeNode(m_class_label);
				subpartition.addRecord(rec);
				subpartitions.put(attrvalue, subpartition);
			}
		}
		
		return subpartitions;
	}
	
	protected double calcEntropy(HashMap<String, DecisionTreeNode> subpartitions, int partition_size)
	{
		double prob=0;
		double entropy=0;
	
		Iterator<String> is = subpartitions.keySet().iterator();
		
	    while(is.hasNext()){
	      String kis = is.next();
	      prob=(double)subpartitions.get(kis).record_count() / partition_size;
	      entropy+=(-prob * Math.log(prob) / Math.log(2));
	    }
	    
		return entropy;
	}
	
	public double gain(String attribute_label)
	{
		HashMap<String, DecisionTreeNode> partitions=this.split(this, attribute_label);
		
		HashMap<String, DecisionTreeNode> pp=this.split(this, m_class_label);
		double gain=calcEntropy(pp, this.record_count());
		
		Iterator<String> is=partitions.keySet().iterator();
		
		while(is.hasNext())
		{
			String kis=is.next();
			DecisionTreeNode partition=partitions.get(kis);
			HashMap<String, DecisionTreeNode> subpartitions=this.split(partition, m_class_label);
			double entropy=calcEntropy(subpartitions, partition.record_count());
			gain-=(partition.record_count() * entropy / this.record_count());
		}
		
		return gain;
	}
	
}
