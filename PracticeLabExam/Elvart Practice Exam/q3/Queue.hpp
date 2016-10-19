/**
*	@file Queue.hpp
*	@author John Gibbons
*	@date 2014.04.02
*/

template <typename T>
Queue<T>::Queue() : m_size(0), m_front(nullptr), m_back(nullptr)
{ }


template <typename T>
Queue<T>::~Queue()
{
	while(!isEmpty())
	{
		dequeue();
	}
}

template <typename T>
bool Queue<T>::isEmpty() const 
{
	return (m_size==0);
}


template <typename T>
void Queue<T>::enqueue(T newEntry)
{
	if(m_front == nullptr)
	{
		m_front = new Node<T>(newEntry);
		m_back = m_front;
	}
	else
	{
		Node<T>* temp = new Node<T>(newEntry);
		m_back->setNext(temp);			
		m_back = temp;
	}
	
	m_size++;
}

template <typename T>
T Queue<T>::dequeue() throw(std::runtime_error)
{

}

template <typename T>
void Queue<T>::backOfTheLine() throw (std::runtime_error)
{

}

template <typename T>
T Queue<T>::peekFront() const throw(std::runtime_error)
{
	if(m_size > 0)
	{
		return(m_front->getValue());
	}
	else
	{
		throw( std::runtime_error("Peak attempted on empty queue") );
	}
}

template <typename T>
int Queue<T>::size() const
{
	return(m_size);
}


template <typename T>
void Queue<T>::print() const
{	

}
