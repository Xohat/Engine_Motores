class Scene
{
	Incremental_Memory_Pool memory_pool;
	
	vector< Sprite* > sprites;
	
	...
	
public:
	
	Scene()
	{
		for (auto * sprite : sprites)
		{
			memory_pool::free(sprite);
		}
	}
	
private:

	void load_scene_xml (const string & xml_patch)
	{
		sprites.push_back(memory_pool.allocate<Sprite> ();
	}
}
