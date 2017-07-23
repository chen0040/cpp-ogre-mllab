package ann.art.art1.application.sequence;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import java.io.File;
import java.io.IOException;
import java.util.Vector;

import ann.art.art1.ARTNN;

public class Console {
	public static void main(String[] args)
	{
		File docFile=new File("data.xml");
		Document doc=null;
		try{
			
			DocumentBuilderFactory dbf=DocumentBuilderFactory.newInstance();
			DocumentBuilder db=dbf.newDocumentBuilder();
			doc=db.parse(docFile);
		}catch(IOException ioe)
		{
			ioe.printStackTrace();
		}catch(Exception e)
		{
			e.printStackTrace();
		}
		
		Element xml_root=doc.getDocumentElement();
		
		ARTNN net=new ARTNN(5, 10);
		net.initialize();
		
		for(Node xml_level1=xml_root.getFirstChild(); xml_level1 != null; xml_level1=xml_level1.getNextSibling())
		{
			if(xml_level1.getNodeName().equals("input"))
			{
				Vector<Integer> input=new Vector<Integer>();
				for(Node xml_level2=xml_level1.getFirstChild(); xml_level2 != null; xml_level2=xml_level2.getNextSibling())
				{
					if(xml_level2.getNodeName().equals("entry"))
					{
						int value=Integer.parseInt(((Element)xml_level2).getAttribute("value"));
						input.add(new Integer(value));
					}
				}
				for(int i=0; i<input.size(); ++i)
				{
					System.out.print(input.get(i).intValue());
				}
				System.out.print("-> class");
				System.out.println(net.simulate(input));
			}
		}
	} 
}
