package decisiontree.c45.application;

import decisiontree.c45.*;

import org.w3c.dom.Element;
import org.w3c.dom.Document;
import org.w3c.dom.Node;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import java.io.File;
import java.io.IOException;

import ml.lang.DiscreteRecord;
import java.util.Vector;

public class Console {
	public static void main(String[] args)
	{
		File file=new File("database.xml");
		Document doc=null;
		try{
			DocumentBuilderFactory dbf=DocumentBuilderFactory.newInstance();
			DocumentBuilder db=dbf.newDocumentBuilder();
			doc=db.parse(file);
		}catch(IOException ioe)
		{
			ioe.printStackTrace();
		}
		catch(Exception pce)
		{
			pce.printStackTrace();
		}
		
		
		
		DecisionTree tree=new DecisionTree("class_label");
		Vector<DiscreteRecord> records=new Vector<DiscreteRecord>();
		
		Element xml_root=doc.getDocumentElement();
		for(Node xml_level1=xml_root.getFirstChild(); xml_level1 != null; xml_level1=xml_level1.getNextSibling())
		{
			if(xml_level1.getNodeName().equals("record"))
			{
				String outlook=((Element)xml_level1).getAttribute("outlook");
				int temperature=Integer.parseInt(((Element)xml_level1).getAttribute("temperature"));
				int humidity=Integer.parseInt(((Element)xml_level1).getAttribute("humidity"));
				String windy=((Element)xml_level1).getAttribute("windy");
				String class_label=((Element)xml_level1).getAttribute("class");
				DiscreteRecord rec=new DiscreteRecord();
				rec.put("outlook", outlook);
				rec.put("windy", windy);
				rec.put("class_label", class_label);
				if(temperature < 75)
				{
					rec.put("temperature", "< 75");
				}
				else
				{
					rec.put("temperature", ">= 75");
				}
				if(humidity < 80)
				{
					rec.put("humidity", "< 80");
				}
				else
				{
					rec.put("humidity", ">= 80");
				}
				tree.addRecord(rec);
				records.add(rec);
			}
		}
		
		tree.build(new String[]{"outlook", "windy", "temperature", "humidity"});
		
		System.out.println("ID3 Tree Built!");
		
		for(int i=0; i<records.size(); i++)
		{
			DiscreteRecord rec=records.get(i);
			System.out.print("rec: ");
			for(int j=0; j<rec.size(); ++j)
			{
				System.out.print(rec.getField(j)+"["+rec.getValue(rec.getField(j))+"] ");
			}
			System.out.println(" --> "+tree.predict(records.get(i)));
		}
		
	}
}
