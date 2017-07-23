package cluster.kmeans;

import java.util.Vector;
import ml.lang.DataPoint;

public class KCluster {
	protected DataPoint m_center;
	protected Vector<DataPoint> m_points=new Vector<DataPoint>();
	
	public KCluster()
	{
		
	}
	
	public void set_center(DataPoint point)
	{
		m_center=point;
	}
	
	public void clear()
	{
		m_points.clear();
	}
	
	public double distance(DataPoint point)
	{
		return m_center.distance(point);
	}
	
	public void assign(DataPoint point)
	{
		m_points.add(point);
	}
	
	public void adjust_center()
	{		
		for(int j=0; j<m_center.size(); j++)
		{
			double sum=0;
			for(int i=0; i<m_points.size(); ++i)
			{
				sum+=m_points.get(i).get(j);
			}
			sum/=m_points.size();
			m_center.set(j, sum);
		}
	}
	
	public int get_point_count()
	{
		return m_points.size();
	}
	
	public DataPoint get_point(int index)
	{
		return m_points.get(index);
	}
	
	public DataPoint get_center()
	{
		return m_center;
	}
}
