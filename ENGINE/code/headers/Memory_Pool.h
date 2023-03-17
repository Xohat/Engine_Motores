#pragma once
#include <vector>
#include <thread>
#include <assert.h>
#include <iostream>
#include <list>
#include <queue>
#include <mutex>

/*
* 
* class Incremental_Memory_Pool 
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

class Task 
{
public:

	enum Status { WAITING, RUNNING, FINISHED, CANCELED };

private:

	int priority;

	Status status;

public:

	Task(int given_priority = 0) 
	{
		status = WAITING;
		priority = given_priority;
	}

	bool operator < (const Task& other) const 
	{
		return this->priority < other.priority;
	}

	Status get_Status() const { return status; }

	void start()
	{
		status = RUNNING;

		if (status != CANCELED) 		
		{
			run();
		}

		status = FINISHED;
	}

	void cancel() 
	{
		if (status != FINISHED) status = CANCELED;
	}

	bool is_not_cancelled() const { return status != CANCELED; };	
	bool is_cancelled() const { return status == CANCELED; };
	bool has_not_finished() const { return status != FINISHED; };
	bool has_finished() const { return status == FINISHED; };
	bool is_waiting() const { return status == WAITING; };
	bool is_not_waiting() const { return status != WAITING; };

protected:

	virtual void run () = 0;
};

class Task_Group : public Task 
{
	std::list< Task * > tasks;

	Thread_Pool& thread_pool;

public:

	Task_Group(Thread_Pool& given_thread_pool) : thread_pool(given_thread_pool) 
	{
	}

	void add_task(Task* task) 
	{
		if (this->is_waiting())
		{
			tasks.push_back(task);
		}
	}

	void run() override
	{
		for (auto current_task = tasks.begin(); current_task != tasks.end(); ++current_task)
		{
			thread_pool.add_task(*current_task);

			while ((*current_task)->has_not_finished())
			{
				std::this_thread::yield();
			}
		}
	}
};

class Thread_Pool
{
	std::list< std::shared_ptr <std::thread>> threads;

	std::queue< Task* > task_queue;

	std::mutex task_queue_mutex;

	bool running;

	//std::vector< std::thread > pool;

	//Cosas a mejorar, prioridad de tareas
	//Priority queue
	/*
	
	*/

/*
public:

	Thread_Pool()
	{
		running = false;

		for (int i = 0; i < std::thread::hardware_concurrency(); i++)
		{
			threads.push_back(std::make_shared<std::thread>(thread_function, this));
		}

		running = true;
	}

	void stop()
	{
		if (running)
		{
			running = false;

			for (auto& t : threads)
			{
				t->join();
			}
		}
	}

	void add_task(Task* task)
	{
		std::lock_guard<std::mutex> lock(task_queue_mutex);

		task_queue.push(task);
	}

private:

	static void thread_function(Thread_Pool* thread_pool)
	{
		while (!thread_pool->running)
		{
			Task* task;

			// Hueco de sentencias para tener variables locales y que se destruyan
			{
				std::lock_guard<std::mutex> lock(thread_pool->task_queue_mutex);

				do
				{
					task = nullptr;

					if (not thread_pool->task_queue.empty())
					{
						task = thread_pool->task_queue.front();

						thread_pool->task_queue.pop();
					}

				} while (task->is_cancelled());
			}

			if (task)
			{
				task->start();
			}
		}
	}

 public:

	 Thread_Pool() : pool(std::thread::hardware_concurrency())
	 {
		 assert(pool.size() > 0);

		 running = false;
	 }

	 ~Thread_Pool()
	 {
		 running = true;

		 for (auto& t : pool)
		 {
			 t.join();
		 }
	 }
};
*/