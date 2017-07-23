package ann.hopfield.application.image;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Random;
import javax.imageio.ImageIO;

import ml.lang.BinaryDataPoint;


import java.awt.Color;
import imagex.PixelRGB;

public class BinaryImage implements BinaryDataPoint {
	protected int m_size;
	protected int m_width;
	protected int m_height;
	protected Random m_rand=new Random();
	protected boolean[] m_data=null;
	
	public BinaryImage(String img_name)
	{
		BufferedImage img=null;
		try{
			img=ImageIO.read(new File(img_name));;
		}catch(IOException ie)
		{
			ie.printStackTrace();
		}
		
		
		m_width=img.getWidth();
		m_height=img.getHeight();
		m_size=m_width * m_height;
		
		m_data=new boolean[m_size];
		
		int rgb=0;
		int l=0;
		for(int y=0; y < m_height; ++y)
		{
			for(int x=0; x<m_width; ++x)
			{
				rgb=img.getRGB(x, y);
				l=PixelRGB.get_luminance(rgb);
				
				if(l < 128)
				{
					m_data[y*m_width+x]=true;
				}
				else
				{
					m_data[y*m_width+x]=false;
				}
			}
		}
		img=null;
	}
	
	public int size()
	{
		return m_size;
	}
	
	public boolean get(int index)
	{
		return m_data[index];
	}
	
	public void set(int index, boolean value)
	{
		m_data[index]=value;
	}
	
	public void mutate(double rate)
	{
		for(int i=0; i<m_data.length; i++)
		{
			if(m_rand.nextDouble() < rate)
			{
				m_data[i]=(!m_data[i]);
			}
		}
	}
	
	public void save(String img_name)
	{
		BufferedImage img=new BufferedImage(m_width, m_height, BufferedImage.TYPE_INT_RGB);
		int rgb_white=Color.white.getRGB();
		int rgb_black=Color.black.getRGB();
		for(int y=0; y<m_height; ++y)
		{
			for(int x=0; x<m_width; ++x)
			{
				if(m_data[y*m_width+x])
				{
					img.setRGB(x, y, rgb_black);
				}
				else
				{
					img.setRGB(x, y, rgb_white);
				}
			}
		}
		try{
			File file=new File(img_name);
			ImageIO.write(img, "bmp", file);
		}catch(IOException ie)
		{
			ie.printStackTrace();
		}
		img=null;
	}
	
	
}
