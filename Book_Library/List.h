#pragma once
template <class T1, class T2>
struct Node
{
	T1 numberofbooks_;
	T2 genre_;
	Node* next_;
	Node* prev_;
	Node<T1, T2>(T1 numberofbooks, T2 genre, Node* next = nullptr, Node* prev = nullptr) :
		numberofbooks_(numberofbooks), genre_(genre), next_(next), prev_(prev) {}
};
extern String GENRE_2;
extern String GENRE_4;
extern String GENRE_6;
template <class T1, class T2>
class List
{
private:
	Node<T1, T2>* head_;
	Node<T1, T2>* tail_;
	int size_;
public:
	List() :size_(0), head_(nullptr), tail_(nullptr) {}
	List(const List& list) :head_(nullptr), size_(list.size_)
	{
		Node<T1, T2>* current = list.head_;
		Node<T1, T2>* last = nullptr;
		Node<T1, T2>* prev = nullptr;
		while (current != nullptr)
		{
			Node<T1, T2>* newnode = new Node<T1, T2>(current->numberofbooks_, current->genre_);
			if (last == nullptr)head_ = newnode;
			else
			{
				last->next_ = newnode;
				last->prev_ = prev;
				prev = last;
			}

			last = newnode;
			current = current->next_;
		}
		delete current;
		delete last;
		delete prev;
	}
	int getsize() { return size_; }
	~List()
	{
		for (int i = 0;i < size_;i++)
		{
			Node<T1, T2>* head = head_;
			head_ = head_->next_;
			delete head;
		}
	}
	void append(T1 numberofbooks, T2 genre)
	{
		Node<T1, T2>* element = new Node<T1, T2>(numberofbooks, genre);
		if (head_ == nullptr)
		{
			head_ = element;
			tail_ = element;
		}
		else
		{
			Node<T1, T2>* current = head_;
			Node<T1, T2>* last = head_;
			while (current != nullptr and numberofbooks > current->numberofbooks_)
			{
				last = current;
				current = current->next_;
			}
			if (current == head_)
			{
				head_ = element;
				element->next_ = current;
				current->prev_ = element;
			}
			else
			{
				if (current == nullptr)
				{
					last->next_ = element;
					element->prev_ = last;
					tail_ = element;

				}
				else
				{
					last->next_ = element;
					current->prev_ = element;
					element->next_ = current;
					element->prev_ = last;
				}
			}
		}
		size_++;
	}
	friend ostream& operator <<(ostream& out, List<T1, T2>& list)
	{
		int setting = 30;
		out << endl << "                                  ";
		for (int i = 0; i < 71; i++)
			out << '-';
		out << endl;
		Node<T1, T2>* current = list.head_;
		for (int i = 0; i < list.getsize(); i++)
		{
			if (current->genre_ == GENRE_2) setting = 28;
			if (current->genre_ == GENRE_6)  setting = 36;
			if (current->genre_ == GENRE_4)setting = 33;
			out << "                                                     " << current->numberofbooks_ << "        " << setw(setting - current->genre_.getsize()) << current->genre_ << endl;
			current = current->next_;
			out << "                                  ";
			for (int i = 0; i < 71; i++)
				out << '-';
			out << endl;
			setting = 30;
		}
		return out;
	}
};
