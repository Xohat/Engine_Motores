clase allocator --> Para guardar memoria mejor (Muy enrevesado) 

libstd --> memory_pool
		   thread_pool (Permite alojar memoria mucho mejor y mejorar rendimiento)
		   
class Incremental_Memory_Pool
{
	using Pol = std::vector< byte >
	
	std::list<Pool> segments;
	
	Pool * current_pool;
	
	size_t pool_size
	size_t allocated;
	
	template<typename TYPE, typename ARGS ... Args>
	TYPE * allocate(Args ... args)
	{
		auto object = reinterpret_cast<TYPE *>(allocate (sizeof(TYPE)));
		
		return new (object) TYPE(args);
	}
	
	template<typename TYPE>
	static void free(TYPE * object)
	{
		object->TYPE();
	}
		
private:

	Incremental_Memory_Pool(size_t pool_size) : 
		pool(1)
		pool_size(pool_size)
	{
		allocated = 0;
		current_pool = nullptr;
	}
	
	void * allocate (size_t chunk_size)
	{
		if (chunk_size < pool_size)
		{
			if (allocated + chunk_size < pool.size ())
			{
				void * chunk = pool.data() + allocated;
				allocated += chunk_size;
				return chunk;
			}
		
			else
			{
				pool.emplace_back (pool_size);
				allocated = 0;
				current_pool = &segments.back();
				
				return this->allocate(chunk_size);
			}
		}
	
		return nullptr;
	}
}

