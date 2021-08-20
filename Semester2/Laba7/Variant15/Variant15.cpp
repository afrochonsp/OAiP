#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

struct Node
{
	Node *left = NULL;
	Node *right = NULL;
	string info;
	int key;
};

void Add(Node *&, int, string);
void DeleteNode(Node *&);
void DeleteTree(Node *&);
void ShowTree(Node *, int = 0);
void Traversal(Node *, bool);
void GetNodes(Node *, vector<Node*> &);
void BubbleSort(vector<Node*> &);
Node *Balance(Node *&, vector<Node*> &, int = -1, int = 0);
Node *&GetNodeByKey(Node *&, int);
Node *&GetMaxNode(Node *&, Node *** = NULL);
template<typename T = int>
void InputNumber(T &, string = "", T = numeric_limits<T>::min(), T = numeric_limits<T>::max());
int Select(const string *, int, string = "");

int main()
{
	system("chcp 1251");
	system("cls");
	Node *root = NULL;
Start:
	int key;
	string name;
	Node *keyNode;
	vector<Node*> nodes;
	string variants[][100] = { { "Да", "Нет" }, { "Создать", "Задание", "Добавить", "Удалить", "Показать", "Поиск", "Сбалансировать", "Распечатать" },
	{ "Прямой обход", "Обратный обход", "В порядке возрастания ключа" } };
	string names[] = { "Пётр", "Александр", "Олег", "Сергей", "Георгий", "Давид", "Лев", "Павел", "Макар", "Дамир",
		"Иван", "Николай", "Григорий", "Матвей", "Богдан", "Фёдор", "Роман", "Владимир", "Марк", "Максим" };
	srand(static_cast<unsigned int>(time(0)));
	switch (Select(variants[1], 8))
	{
	case 1:
	{
		DeleteTree(root);
		int size, key = -1, nameRange = 20, keyRange;
		InputNumber(size, "Размер: ", 0, 100);
		keyRange = size;
		cout << "\n";
		for (int i = 0; i < size; i++)
		{
			while (key == -1 || GetNodeByKey(root, key)) key = rand() % keyRange + 1;
			name = names[rand() % nameRange];
			cout << name << ": " << key << "\n";
			Add(root, key, name);
		}
		break;
	}
	case 2:
	{
		int count = 0;
		GetNodes(root, nodes);
		for (auto node : nodes) if (node->key > root->key) count++;
		cout << "Количество записей в правой ветви дерева: " << count << "\n";
		break;
	}
	case 3:
		InputNumber(key, "Введите ключ: ");
		while (GetNodeByKey(root, key)) InputNumber(key, "Введите другой ключ: ");
		cout << "Введите имя: ";
		getline(cin, name);
		Add(root, key, name);
		break;
	case 4:
		InputNumber(key, "Введите ключ: ");
		DeleteNode(GetNodeByKey(root, key));
		break;
	case 5:
		ShowTree(root);
		break;
	case 6:
		InputNumber(key, "Введите ключ: ");
		keyNode = GetNodeByKey(root, key);
		if (keyNode) cout << "Имя: " << keyNode->info << "\n";
		else cout << "Элемент не найден\n";
		break;
	case 7:
		GetNodes(root, nodes);
		BubbleSort(nodes);
		Balance(root, nodes);
		break;
	case 8:
		switch (Select(variants[2], 3, "Как распечатать?"))
		{
		case 1:
			Traversal(root, false);
			break;
		case 2:
			Traversal(root, true);
			break;
		case 3:
			GetNodes(root, nodes);
			BubbleSort(nodes);
			for (auto node : nodes) cout << node->info << " ";
			break;
		}
		cout << "\n";
		break;
	}
	cout << "\n";
	goto Start;
}

void Add(Node *&root, int key, string info)
{
	Node **p = &root;
	while (*p) p = key < (*p)->key ? &(*p)->left : &(*p)->right;
	Node* newNode = new Node;
	newNode->key = key;
	newNode->info = info;
	*p = newNode;
}

void DeleteNode(Node *&target)
{
	if (!target) return;
	Node *tempPtr = NULL;
	if ((target->left && !target->right) || (!target->left && target->right))
	{
		tempPtr = target->left ? target->left : target->right;
	}
	else if (target->left && target->right)
	{
		Node **prevPtr = NULL;
		tempPtr = GetMaxNode(target->left, &prevPtr);
		if (!prevPtr) tempPtr->right = target->right;
		else
		{
			if (tempPtr->left) (tempPtr->left->key < (*prevPtr)->key ? (*prevPtr)->left : (*prevPtr)->right) = tempPtr->left;
			else (*prevPtr)->right = NULL;
			tempPtr->right = target->right;
			tempPtr->left = target->left;
		}
	}
	delete target;
	target = tempPtr;
}

void DeleteTree(Node *&root)
{
	while (root) DeleteNode(root);
}

void ShowTree(Node *p, int level)
{
	if (!p) return;
	ShowTree(p->left, level + 1);
	for (int i = 0; i < level; i++) cout << "   ";
	cout << p->key << "\n";
	ShowTree(p->right, level + 1);
}

void Traversal(Node *p, bool post)
{
	if (!p) return;
	if (!post) cout << p->info << " ";
	Traversal(p->left, post);
	Traversal(p->right, post);
	if (post) cout << p->info << " ";
}

void GetNodes(Node *p, vector<Node*> &nodes)
{
	if (!p) return;
	nodes.push_back(p);
	GetNodes(p->left, nodes);
	GetNodes(p->right, nodes);
}

void BubbleSort(vector<Node*> &nodes)
{
	int n = nodes.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (nodes[i]->key > nodes[j]->key)
			{
				Node* temp = nodes[i];
				nodes[i] = nodes[j];
				nodes[j] = temp;
			}
		}
	}
}

Node *Balance(Node *&root, vector<Node*> &nodes, int k, int n)
{
	if (k == -1) k = nodes.size(), root = nodes[k / 2];
	if (n == k) return NULL;
	int m = (n + k) / 2;
	nodes[m]->left = Balance(root, nodes, m, n);
	nodes[m]->right = Balance(root, nodes, k, m + 1);
	return nodes[m];
}

Node *&GetNodeByKey(Node *&root, int key)
{
	Node **p = &root;
	while (*p)
	{
		if ((*p)->key > key) p = &(*p)->left;
		else if ((*p)->key < key) p = &(*p)->right;
		else return *p;
	}
	return *p;
}

Node *&GetMaxNode(Node *&root, Node ***prev)
{
	Node **p = &root;
	while ((*p)->right)
	{
		if (prev) *prev = p;
		p = &(*p)->right;
	}
	return *p;
}

template<typename T>
void InputNumber(T &n, string text, T minVlaue, T maxValue)
{
	cout << text;
	while (!(cin >> n) || n < minVlaue || n > maxValue)
	{
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int Select(const string *variants, int count, string question)
{
	int choice;
	if (question != "") cout << question << "\n";
	for (int i = 0; i < count; i++) cout << i + 1 << " - " << variants[i] << "\n";
	InputNumber(choice, "", 1, count);
	cout << "\n";
	return choice;
}