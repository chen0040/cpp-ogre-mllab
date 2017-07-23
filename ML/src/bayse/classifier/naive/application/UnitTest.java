package bayse.classifier.naive.application;

import bayse.classifier.naive.*;

import java.io.File;
import java.io.IOException;
import java.util.Vector;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import ml.lang.DiscreteRecord;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;

public class UnitTest {
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
		
		NaiveBayseClassifier nbc=new NaiveBayseClassifier();
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
				nbc.addRecord(rec);
				records.add(rec);
			}
		}
		
		
		
		for(int i=0; i<records.size(); i++)
		{
			DiscreteRecord rec=records.get(i);
			System.out.print("rec: ");
			for(int j=0; j<rec.size(); ++j)
			{
				System.out.print(rec.getField(j)+"["+rec.getValue(rec.getField(j))+"] ");
			}
			
			System.out.println(" --> "+nbc.predict(rec,	"class_label"));
			
		}
	}
}
