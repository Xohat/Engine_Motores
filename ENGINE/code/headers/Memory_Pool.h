#pragma once
#include <vector>
#include <thread>
#include <assert.h>

class Incremental_Memory_Pool 
{
public:
	Incremental_Memory_Pool(size_t pool_size);
	
private:
	void* allocate(size_t chunk_size);
};

template<size_t CHUNK_SIZE>
class Chunked_Memory_Pool 
{
protected:

	struct Node 
	{
		char   chunk[CHUNK_SIZE];
		Node * prev;
		Node * next;
	};

	std::vector< Node > pool;

	Node * used_nodes;
	Node * free_nodes;

public:

	Chunked_Memory_Pool(size_t pool_size) : pool(pool_size / sizeof(Node))
	{
		for (size_t i = 0; i < pool.size(); ++i)
		{
			Node & node = pool[i];

			node.prev = i > 0 ? &pool[i - 1] : nullptr;
			node.next = i < pool.size() - 1 ? &pool[i + 1] : nullptr;
		}

		used_nodes = nullptr;
		free_nodes = &pool[0];
	}

	void free(void * chunk) 
	{
		Node * node = reinterpret_cast<Node*>(chunk);

		// Se quita el nodo de la lista de nodos en uso:

		if (node->prev)
			node->prev->next = node->next;
		else
			used_nodes = nullptr;

		if (node->next) node->next->prev = node->prev;

		// Se añade al principio de la lista de nodos libres:

		if (free_nodes) 
		{
			free_nodes->prev = node;
		}

		node->next = free_nodes;
		free_nodes = node;
	}

protected:

	void* allocate() 
	{
		if (free_nodes) 
		{
			Node* reserved = free_nodes;

			// Se quita el nodo de la lista de nodos libres

			if (reserved->next) 
			{
				reserved->next->prev = nullptr;
			}

			free_nodes = reserved->next;

			//Se añade a la lista de nodos en uso:

			if (used_nodes) 	
			{
				used_nodes->prev = reserved;
			}

			reserved->prev = nullptr;
			reserved->next = used_nodes;

			used_nodes = reserved;

			return reserved;
		}

		return nullptr;
	}
};

template < typename TYPE >
class Object_Pool : public Chunked_Memory_Pool< sizeof(TYPE) > 
{
public:
	Object_Pool(size_t number_of_objects) : Chunked_Memory_Pool(number_of_objects * sizeof(Chunked_Memory_Pool::Node)) 
	{

	}

	TYPE* allocate() 
	{
		return new (Chunked_Memory_Pool::allocate()) TYPE ();
	}

	void free(TYPE* element) 
	{
		if (element) 
		{
			element->~TYPE();

			Chunked_Memory_Pool::free(element);
		}
	}
};

class Thread_Pool
{
	std::vector< std::thread > pool;

	bool exit;

public:

	Thread_Pool() : pool(std::thread::hardware_concurrency())
	{
		assert(pool.size() > 0);

		exit = false;
	}

	~Thread_Pool() 
	{
		exit = true;

		for (auto & t : pool)
		{
			t.join ();
		}
	}

private:

	static void thread_function(Thread_Pool* thread_pool)
	{
		while (!thread_pool->exit)
		{

		}
	}
};