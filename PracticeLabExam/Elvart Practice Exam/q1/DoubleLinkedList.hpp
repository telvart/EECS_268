/**
*	@file DoubleLinkedList.hpp
*	@date 2014.02.23
*	Updated: 2014.09.30
*	@author John Gibbons
*/

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	m_front = nullptr;
	m_back = nullptr;
	m_size = 0;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	Node<T>* temp = m_front;
	Node<T>* next = nullptr;	

	while(temp != nullptr)
	{
		next = temp->getNext();
		delete temp;
		m_size--;		
		temp = next;
	}
}

template <typename T>
int DoubleLinkedList<T>::size()
{
	return(m_size);
}


template <typename T>
bool DoubleLinkedList<T>::isEmpty()
{
	return(m_size == 0);
}



template <typename T>
void DoubleLinkedList<T>::pushFront(T value)
{
	Node<T>* temp = new Node<T>();
	temp->setValue(value);

	if(m_size == 0)
	{
		m_front = temp;
		m_back = temp;
		temp->setPrevious(nullptr);
		temp->setNext(nullptr);
	}
	else
	{
		temp->setPrevious(nullptr);
		temp->setNext(m_front);
		m_front->setPrevious(temp);	
		m_front = temp;
	}	
	
	m_size++;
}

template <typename T>
void DoubleLinkedList<T>::insertAhead(T listValue, T value) throw (std::runtime_error)
{
 	Node<T>* location=find(listValue);
	if (isEmpty() || location==nullptr)
	{
		throw std::runtime_error("The List is Empty, nothing to add in front of");
	}
	else if (location==m_front)
	{
		pushFront(value);
	}
	else
	{
		Node<T>* temp=new Node<T>;
		temp->setValue(value);

		temp->setPrevious(location->getPrevious());
		temp->setNext(location);
		location->setPrevious(temp);
		temp->getPrevious()->setNext(temp);
		m_size++;
	}
}



template <typename T>
Node<T>* DoubleLinkedList<T>::find(T value)
{
	Node<T>* temp = m_front;

	while(temp != nullptr)
	{
		if(temp->getValue() == value)
		{
			return(temp);
		}
		else
		{
			temp = temp->getNext();
		}
	}
	
	return(nullptr);
}


template <typename T>
void DoubleLinkedList<T>::printList() const
{
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		std::cout << temp->getValue();
		if(temp->getNext() != nullptr)
		{
			std::cout << " ";
		}

		temp = temp->getNext();
	}
}


template <typename T>
void DoubleLinkedList<T>::printReverse() const
{
	Node<T>* traverse=m_back;
	while (traverse!=nullptr)
	{
		std::cout<<traverse->getValue()<<" ";
		traverse=traverse->getPrevious();
	}
}

	












