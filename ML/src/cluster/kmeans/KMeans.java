package cluster.kmeans;

import java.util.Vector;
import ml.lang.DataPoint;

public class KMeans {
	protected Vector<KCluster> m_clusters=new Vector<KCluster>();
	protected Vector<DataPoint> m_data=new Vector<DataPoint>();
	
	public KMeans()
	{
		
	}
	
	public void add_point(DataPoint pt)
	{
		m_data.add(pt);
	}
	
	public void add_cluster(KCluster cluster)
	{
		m_clusters.add(cluster);
	}
	
	public final int get_point_count()
	{
		return m_data.size();
	}
	
	public final int get_cluster_count()
	{
		return m_clusters.size();
	}
	
	public KCluster get_cluster(int index)
	{
		return m_clusters.get(index);
	}
	
	public DataPoint get_point(int index)
	{
		return m_data.get(index);
	}
	
	public void cluster()
	{
		for(int i=0; i<m_clusters.size(); ++i)
		{
			m_clusters.get(i).clear();
		}
		
		for(int i=0; i<m_data.size(); i++)
		{
			assign_to_cluster(m_data.get(i));
		}
		
		for(int i=0; i<m_clusters.size(); ++i)
		{
			m_clusters.get(i).adjust_center();
		}
	}
	
	protected void assign_to_cluster(DataPoint pt)
	{
		double min_distance=Double.MAX_VALUE;
		KCluster winner=null;
		for(int i=0; i<m_clusters.size(); ++i)
		{
			double distance=m_clusters.get(i).distance(pt);
			if(min_distance > distance)
			{
				min_distance=distance;
				winner=m_clusters.get(i);
			}
		}
		winner.assign(pt);
	}
}
