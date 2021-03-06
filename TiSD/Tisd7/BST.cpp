//
// Created by alexey on 12.12.16.
//

#include "BST.h"


#include "BST.h"

extern void log(const char *str);

template<typename T>
BST<T> &BST<T>::operator=(const BST<T> &obj)
{
	log("=");
	operator_copy(&head, obj.head);
}

template<typename T>
void BST<T>::operator_copy(element<T> **head, element<T> *tmp)
{
	log("copy");
	element<T> *a = *head;
	if (tmp)
	{
		a = new element<T>(tmp->key);
		operator_copy(&a->left, tmp->left);
		operator_copy(&a->right, tmp->right);
	}
}

template<typename T>
int BST<T>::Memory()
{
	//cout << count_of_element << endl;
	return sizeof(element<T>) * count_of_element;
}

template<typename T>
void BST<T>::Insert(T x)
{
	log("insert");
	//cout << x << endl;
	element<T> *new_elem = new element<T>(x);
	//cout << new_elem->key << endl;
	element<T> *tmp = head;
	if (!head)
	{
		head = new_elem;
		count_of_element++;
		return;
	}
	while (1)
	{
		if (!tmp)
		{
			tmp = new_elem;
			count_of_element++;
			break;
		}
		if (tmp->key == x)
		{
			tmp->key.count++;
			break;
		}
		if (tmp->key < x)
		{
			if (tmp->right)
			{
				tmp = tmp->right;
			} else
			{
				tmp->right = new_elem;
				count_of_element++;
				break;
			}
		} else
		{
			if (tmp->left)
			{
				tmp = tmp->left;
			} else
			{
				tmp->left = new_elem;
				count_of_element++;
				break;
			}
		}
	}
}

template<typename T>
void BST<T>::delete_remove(element<T> *prev, element<T> *tmp)
{
	element<T> *b = NULL;
	count_of_element--;
	int flag = 0;
	if ((!tmp->left) && (!tmp->right))
	{
		b = NULL;
		flag = 1;
	}
	if (tmp->left && !tmp->right)
	{
		b = tmp->left;
		flag = 1;
	}
	if (!tmp->left && tmp->right)
	{
		b = tmp->right;
		flag = 1;
	}
	if (flag)
	{
		if (prev == NULL || prev == tmp)
		{
			head = b;
		} else
		{
			if (prev->left == tmp)
			{
				prev->left = b;
			} else if (prev->right == tmp)
			{
				prev->right = b;
			}
		}
		delete tmp;
		return;
	}
	element<T> *a = tmp->right;
	element<T> *new_elem = tmp;
	while (a)
	{
		if (a->left)
		{
			new_elem = a;
			a = a->left;
		} else
		{
			break;
		}
	}
	tmp->key = a->key;
	if (new_elem->left == a)
	{
		new_elem->left = a->right;
	} else
	{
		new_elem->right = a->right;
	}
	delete a;
}

template<typename T>
bool BST<T>::Remove(T x)
{
	element<T> *tmp = head;
	element<T> *prev = NULL;
	int cmp = 0;
	while (1)
	{
		if (!tmp)
		{
			return false;
		}
		if (x == tmp->key)
		{
			tmp->key.count--;
			if (tmp->key.count == 0)
				delete_remove(prev, tmp);
			return true;
		}
		prev = tmp;
		if (x > tmp->key)
		{
			if (tmp->right)
			{
				tmp = tmp->right;
			} else
			{
				return false;
			}
		} else
		{
			if (tmp->left)
			{
				tmp = tmp->left;
			} else
			{
				return false;
			}
		}
	}

}

template<typename T>
BST<T>::~BST()
{
	log("~");
	delete_tree(head);
	head = NULL;
}

template<typename T>
void BST<T>::delete_tree(element<T> *tmp)
{
	if (tmp)
	{
		delete_tree(tmp->left);
		delete_tree(tmp->right);
		delete tmp;
		tmp = NULL;
		count_of_element = 0;
	}
}

template<typename T>
BST<T>::BST(const BST &obj)
{
	log("copy");
	if (&obj != this)
	{
		*this = obj;
	}
}

template<typename T>
BST<T>::BST()
{
	head = NULL;
	count_of_element = 0;
}

template<typename T>
bool BST<T>::Search(T x)
{
	element<T> *tmp = head;
	while (tmp)
	{
		if (tmp->key == x)
		{
			return true;
		}
		if (tmp->key < x)
		{
			tmp = tmp->right;
		} else
		{
			tmp = tmp->left;
		}
	}
	return false;
}