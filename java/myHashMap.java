import java.util.*;

// template<typename K, V>
public class myHashMap<K, V>
{
	private LinkedList<Pair>[] buckets;
	private int size = 0;
	private class Pair
	{
		K key;
		V value;
		
		Pair(K key, V value)
		{
			this.key = key;
			this.value = value;
		}
	}
	
	private int hashFunction(K key)
	{
		int hc = key.hashCode();
		int bi = Math.abs(hc) % buckets.length;
		return bi;
	}
	
	private int findWithinBucket(K key, int bi)
	{
		int di = 0;
		for(Pair p: buckets[bi])
		{
			if(p.key.equals(key))
				return di;
			di++;
		}
		return -1;
	}
	
	private void rehash()
	{
		LinkedList<Pair>[] ob = buckets;
		buckets = new LinkedList[ob.length * 2];
		for(int i = 0; i < buckets.length; i++)
			buckets[i] = new LinkedList<>();
		
		size = 0;
		
		for(int bi = 0; bi < ob.length; bi++)
		{
			for(Pair p: ob[bi])
			{
				put(p.key, p.value);
			}
		}
	}
	
	public myHashMap()
	{
		buckets = new LinkedList[4];
		for(int i = 0; i < buckets.length; i++)
			buckets[i] = new LinkedList<>();
		
		size = 0;
	}
	
	public void put(K key, V value)
	{
		int bi = hashFunction(key);
		int di = findWithinBucket(key, bi);
		
		if(di == -1)
		{
			Pair p2a = new Pair(key, value);
			buckets[bi].add(p2a);
			size++;
		}
		else
		{
			Pair p2u = buckets[bi].get(di);
			p2u.value = value;
		}
	
		double lambda = size * 1.0 / buckets.length;
		if(lambda > 2.0)
			rehash();
	}
	
	public boolean containsKey(K key)
	{
		int bi = hashFunction(key);
		int di = findWithinBucket(key, bi);
		if(di == -1)
			return false;
		else
			return true;
	}
	
	public V remove(K key)
	{
		int bi = hashFunction(key);
		int di = findWithinBucket(key, bi);
		if(di == -1)
			return null;
		else
		{
			Pair p2 = buckets[bi].remove(di);
			size--;
			return p2.value;
		}
	}
	
	public V get(K key)
	{
		int bi = hashFunction(key);
		int di = findWithinBucket(key, bi);
		if(di == -1)
			return null;
		else
		{
			Pair p2 = buckets[bi].get(di);
			return p2.value;
		}
	}
	
	public ArrayList<K> keySet()
	{
		ArrayList<K> list = new ArrayList<>();
		for(int bi = 0; bi < buckets.length; bi++)
		{
			for(Pair p: buckets[bi])
			{
				list.add(p.key);
			}
		}
		
		return list;
	}
	
	public void display() // obj.display()
	{
		System.out.println("-----------------------------------------------------------------------");
		for(int bi = 0; bi < buckets.length; bi++)
		{
			System.out.print("Bucket: " + bi);
			for(Pair p: buckets[bi])
			{
				System.out.print("[" + p.key + " -> " + p.value + "]");
			}
			System.out.println();
		}	
		System.out.println("-----------------------------------------------------------------------");
	}
}