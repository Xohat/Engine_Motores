#pragma once

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <memory>

namespace Xohat 
{

 //   // Implementación de Variant utilizando plantillas
 //   template<typename... Types>
 //   struct Variant
 //   {
 //       // Índice para realizar operaciones en tiempo de ejecución
 //       size_t index;

 //       // Almacenamiento para los diferentes tipos
 //       union Storage {
 //           std::aligned_union_t<0, Types...> data;
 //           Storage() {}
 //           ~Storage() {}
 //       } storage;

 //       // Constructor
 //       template<typename T>
 //       Variant(const T& value)
 //           : index(GetIndex<T, Types...>())
 //       {
 //           new (&storage.data) T(value);
 //       }

 //       // Destructor
 //       ~Variant()
 //       {
 //           Reset();
 //       }

 //       // Asignación
 //       template<typename T>
 //       Variant& operator=(const T& value)
 //       {
 //           Reset();
 //           index = GetIndex<T, Types...>();
 //           new (&storage.data) T(value);
 //           return *this;
 //       }

 //       // Obtener el valor almacenado
 //       template<typename T>
 //       T& Get()
 //       {
 //           if (index != GetIndex<T, Types...>())
 //               throw std::bad_variant_access();

 //           return *reinterpret_cast<T*>(&storage.data);
 //       }

 //       // Resetear el valor almacenado
 //       void Reset()
 //       {
 //           Visit([](auto& value) { value.~decltype(value)(); });
 //       }

 //       // Visitar los tipos almacenados
 //       template<typename F>
 //       void Visit(F&& f)
 //       {
 //           using FuncType = void (*)(void*, F&&);
 //           static const FuncType funcs[] = { &CallFunc<Types, F>... };
 //           funcs[index](&storage.data, std::forward<F>(f));
 //       }

 //   private:
 //       // Obtener el índice del tipo en la lista de tipos
 //       template<typename T, typename... Rest>
 //       static constexpr size_t GetIndex()
 //       {
 //           if constexpr (std::is_same_v<T, typename std::tuple_element<0, std::tuple<Types...>>::type>)
 //               return 0;
 //           else
 //               return 1 + GetIndex<T, Rest...>();
 //       }

 //       // Función auxiliar para llamar al operador () del objeto f con el tipo T
 //       template<typename T, typename F>
 //       static void CallFunc(void* data, F&& f)
 //       {
 //           f(*reinterpret_cast<T*>(data));
 //       }
 //   };

	//struct Message
	//{
 //       // Alias para simplificar el uso de Variant
 //       template<typename... Types>
 //       using Variant = Xohat::Variant<Types...>;

	//	string id;
	//	std::map < string, Variant<int, float, vec3, string>> parameters;
	//};

	//class Message_Listener
	//{
	//public:
	//	virtual void handle(const Message& m) = 0;
	//};

	//class Message_Dispatcher
	//{
	//	// messageId
	//	map< string, list< shared_ptr<Message_Listener> > > listeners;

	//public:

	//	void register_listener(const string& message_id, shared_ptr<Message_Listener> listener)
	//	{
 //           assert(listener != nullptr);

 //           if (listener)
 //           {
 //               listeners[message_id].push_back(listener);
 //           }
	//	}

	//	void send(const Message& messsage)
	//	{
	//		auto handlers = listeners.find(messsage.id);

	//		if (handlers != listeners.end())
	//		{
	//			list<std::shared_ptr<Message_Listener>>& handlerList = handlers->second;

	//			// * es un iterador de la lista
	//			for (auto& handler : handlerList)
	//			{
	//				handler->handle(messsage);
	//			}
	//		}

	//		else
	//			cout << "meesage with ID = " << messsage.id << " lost!" << endl;
	//	}
	//};
}

/*
int main()
{
    // Ejemplo de uso
    Message message;
    message.id = "example_message";
    message.parameters["param1"] = 42;
    message.parameters["param2"] = std::string("Hello");

    // Crear un listener y registrarlo en el dispatcher
    class ExampleListener : public Message_Listener
    {
    public:
        void handle(const Message& m) override
        {
            std::cout << "Received message with ID: " << m.id << std::endl;
            for (const auto& param : m.parameters)
            {
                std::cout << "Parameter: " << param.first << ", Value: ";
                param.second.Visit([](const auto& value) { std::cout << value; });
                std::cout << std::endl;
            }
        }
    };

    auto listener = std::make_shared<ExampleListener>();
    Message_Dispatcher dispatcher;
    dispatcher.register_listener("example_message", listener);

    // Enviar el mensaje al dispatcher
    dispatcher.send(message);

    return 0;
}
*/