#pragma once

template <typename T>
class LinkedList {
	struct Item {
		T value;
		Item* next;

		Item() : next(nullptr) {}
		Item(const T& value) : value(value), next(nullptr) {}
		Item(const T& value, Item* next) : value(value), next(next) {}
	};

public:
	LinkedList()
		: first(nullptr)
	{
	}

	~LinkedList()
	{
		clear();
	}

	void insertLast(const T& val) {
		if (!first)
			first = new Item(val);
		else {
			Item* last = getLastItem();
			last->next = new Item(val);
		}
	}

	void insertFirst(const T& val) {
		Item* item = new Item(val, first);
		first = item;
	}

	void insertAtPos(const T& val, int pos) {
		if (pos == 0) {
			insertFirst(val);
		}
		else {
			Item* prev = getItemAt(pos - 1);
			Item* next = prev->next;
			Item* item = new Item(val, next);
			prev->next = item;
		}
	}

	void deleteByValue(const T& val) {
		Item* curr = first;
		Item* prev = nullptr;
		while (curr) {
			if (curr->value == val) {
				deleteItem(curr, prev);
				return;
			}
			prev = curr;
			curr = curr->next;
		}
	}

	void deleteLast() {
		if (!first)
			throw std::out_of_range("List is empty");
		Item* prev;
		Item* last = getLastItem(&prev);
		deleteItem(last, prev);
	}

	void deleteFirst() {
		if (!first)
			throw std::out_of_range("List is empty");
		deleteItem(first, nullptr);
	}

	void deleteAtPos(int pos) {
		Item* prev;
		Item* item = getItemAt(pos, &prev);
		deleteItem(item, prev);
	}

	void clear() {
		Item* curr = first;
		while (curr) {
			Item* next = curr->next;
			delete curr;
			curr = next;
		}
		first = nullptr;
	}

	T& getLast() const {
		if (!first)
			throw std::out_of_range("List is empty");
		Item* last = getLastItem();
		return last->value;
	}

	T& getFirst() const {
		if (!first)
			throw std::out_of_range("List is empty");
		return first->value;
	}

	T& getAtPos(int pos) const {
		Item* item = getItemAt(pos);
		return item->value;
	}

	bool isContains(const T& val) const
	{
		Item* curr = first;
		while (curr) {
			if (curr->value == val)
				return true;
			curr = curr->next;
		}
		return false;
	}

	bool isEmpty() const
	{
		return first == nullptr;
	}

	int size() const
	{
		int size = 0;
		Item* curr = first;
		while (curr) {
			++size;
			curr = curr->next;
		}
		return size;
	}

private:
	Item* first = nullptr;

	Item* getItemAt(int pos, Item** prev = nullptr) const {
		if (pos < 0 || !first)
			throw std::out_of_range("Index is out of range");
		if (prev)
			*prev = nullptr;
		Item* curr = first;
		while (pos > 0) {
			--pos;
			if (prev)
				*prev = curr;
			curr = curr->next;
			if (!curr)
				throw std::out_of_range("Index is out of range");
		}
		return curr;
	}

	Item* getLastItem(Item** prev = nullptr) const {
		if (!first)
			throw std::out_of_range("List is empty");
		if (prev)
			*prev = nullptr;
		Item* curr = first;
		while (curr->next) {
			if (prev)
				*prev = curr;
			curr = curr->next;
		}
		return curr;
	}

	Item* deleteItem(Item* item, Item* prev) {
		Item* next = item->next;
		if (item == first)
			first = next;
		if (prev)
			prev->next = next;
		delete item;
		return next;
	}
};