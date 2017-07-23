package decisiontree.c45;

import java.util.Vector;

import ml.lang.Record;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

public class DecisionTree {
	DecisionTreeNode m_root;
	
	public DecisionTree(String class_label)
	{
		m_root=new DecisionTreeNode(class_label);
	}
	
	public void addRecord(Record record)
	{
		m_root.addRecord(record);
	}
	
	public void build(Vector<String> attribute_labels)
	{
		//create a copy of attributes that exclude the class label
		Vector<String> actlab=new Vector<String>();
		for(int i=0; i<attribute_labels.size(); i++)
		{
			String label=attribute_labels.get(i);
			if(!label.equals(m_root.get_class_label()))
			{
				actlab.add(label);
			}
		}
		m_root.clear_children();
		m_root.split(actlab);
	}
	
	public void build(String[] attribute_labels)
	{
		//create a copy of attributes that exclude the class label
		Vector<String> actlab=new Vector<String>();
		for(int i=0; i<attribute_labels.length; i++)
		{
			String label=attribute_labels[i];
			if(!label.equals(m_root.get_class_label()))
			{
				actlab.add(label);
			}
		}
		m_root.clear_children();
		m_root.split(actlab);
	}
	
	public String predict(Record record)
	{
		return m_root.predict(record);
	}
	
	public Document ToXml()
	{
		Document doc=null;
		try{
			DocumentBuilderFactory dbf=DocumentBuilderFactory.newInstance();
			DocumentBuilder db=dbf.newDocumentBuilder();
			doc=db.newDocument();
		}catch(Exception e)
		{
			e.printStackTrace();
		}
		
		Element xml_root=doc.createElement("decision_tree");
		
		m_root.BuildXml(xml_root);
		
		return doc;
	}
}
