#pragma once

struct Message 
{
	using Variant = std::variant< int, float, vec3, string >;

	string id;
	map < string, Variant > parameters;
};

class Message_Listener 
{
public:
	virtual void handle(const Message & m) = 0;
};

class Message_Dispatcher 
{
	// messageId
	map< string, list< Message_Listener > > listeners;

public:

	void register_listener (string message_id, Message_Listener& listener) 
	{
		listeners[message_id].push_back (&listener);
	}

	void send (const Message & messsage)
	{
		auto handlers = listeners.find(messsage.id);

		if (handlers != listeners.end())
		{
			// * es un iterador de la lista
			for (auto& handler : *handlers)
			{
				handler->handle(messsage);
			}
		}

		else
			cout << "meesage with ID=" << messsage.id << " lost!" << endl;
	}
};