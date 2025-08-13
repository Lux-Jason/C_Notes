#include<iostream>
using namespace std;
//����ʽ��һ��Ϊ�����һ����㣬��ͷ���
struct polynode
{
	int coef;
	int exp;
	polynode* link;
};
typedef polynode* polypointer;

//������ʽ��һ����������β��
void Attach(int c, int e, polypointer& d)
{
	polypointer x;

	x = new polynode;
	x->coef = c;
	x->exp = e;
	d->link = x;
	x->link = NULL;
	d = d->link;
}
//�û��������ʽ��һ��
void Input(polypointer& L)
{
	int c, e;
	cout << "������һԪ����ʽf/g��--��ʽ�ǣ�ϵ�� ָ������0 0����" << endl;
	cin >> c >> e;
	polypointer p = L;
	while (c)
	{
		Attach(c, e, p);
		cout << "������һԪ����ʽf����һ�����0 0������" << endl;
		cin >> c >> e;
	}
}

//�ӷ����������ؽ��cָ��L1
polypointer PolyAdd(polypointer L1, polypointer L2)
{
	polypointer p, q, d, c;
	int x;
	p = L1->link;
	q = L2->link;
	c = new polynode;
	c->link = NULL;
	d = c;
	while ((p != NULL) && (q != NULL))
	{
		if (p->exp == q->exp)
		{
			x = p->coef + q->coef;
			if (x != 0)
				Attach(x, p->exp, d);
			p = p->link;
			q = q->link;
		}
		else if (p->exp > q->exp)
		{
			Attach(p->coef, p->exp, d);
			p = p->link;
		}
		else if (p->exp < q->exp)
		{
			Attach(q->coef, q->exp, d);
			q = q->link;
		}
	}
	while (p != NULL)
	{
		Attach(p->coef, p->exp, d);
		p = p->link;
	}
	while (q != NULL)
	{
		Attach(q->coef, q->exp, d);
		q = q->link;
	}
	return c;
}

//��������,��ӷ�������ͬ
polypointer PolyMinus(polypointer L1, polypointer L2) {
	polypointer p, q, c, d;
	int x;
	p = L1->link;
	q = L2->link;
	c = new polynode;
	c->link = NULL;
	d = c;
	while ((p != NULL) && (q != NULL))
	{
		if (p->exp == q->exp)
		{
			x = p->coef - q->coef;
			if (x != 0)
				Attach(x, p->exp, d);
			p = p->link;
			q = q->link;
		}
		else if (p->exp > q->exp)
		{
			Attach(p->coef, p->exp, d);
			p = p->link;
		}
		else if (p->exp < q->exp)
		{
			int m = q->coef * (-1);
			Attach(m, q->exp, d);
			q = q->link;
		}
	}
	while (p != NULL)
	{
		Attach(p->coef, p->exp, d);
		p = p->link;
	}
	while (q != NULL)
	{
		Attach(q->coef * (-1), q->exp, d);
		q = q->link;
	}
	return c;
}

//������ϲ�����
polypointer Sort(polypointer& L)
{
	int temp1, temp2;
	polypointer r = NULL;
	bool isChange = true;
	while (r != L->link->link && isChange)
	{
		polypointer q = L->link;
		isChange = false; //��־��ǰ��һ������û�з���Ԫ�ؽ��������û�����ʾ�����Ѿ�����
		for (; q->link && q->link != r; q = q->link)
			if (q->exp < q->link->exp) {
				temp1 = q->exp;
				q->exp = q->link->exp;
				q->link->exp = temp1;

				temp2 = q->coef;
				q->coef = q->link->coef;
				q->link->coef = temp2;
				isChange = true;
			}
		r = q;
	}
	return L;
}
void SameUnit(polypointer& L)
{
	polypointer r, h;
	r = L->link;
	while (r->link != NULL)
	{
		if (r->exp == r->link->exp) {
			r->coef = r->link->coef + r->coef;
			h = r->link;
			r->link = r->link->link;
			delete h;
		}
		r = r->link;
	}
}
//�˷��������˷����㷨��1���Ա����ķ�ʽ�������������㣬ÿһ����ϵ�����ָ����ӣ������±�֮��  2����ָ����ð������֮������������ϲ�ͬ���������
polypointer PolyMultiply(polypointer L1, polypointer L2)
{
	polypointer p, q, c, d;
	int x, y;

	c = new polynode;
	c->link = NULL;
	d = c;
	for (p = L1->link; p != NULL; p = p->link) {
		for (q = L2->link; q != NULL; q = q->link) {
			x = p->coef * q->coef;
			y = p->exp + q->exp;
			Attach(x, y, d);
		}
	}
	Sort(c);
	SameUnit(c);
	return c;
}

//�������㷨��Ĭ�ϵ�һ������ʽ���ָ�����ڵڶ������������������
	//1���ο�����ʽ������ķ�ʽ��һλһλ������ʽ�������ӵ���ʽ�������
	//2��ÿ����һ�Σ��µı���ʽ = ԭ����ʽ������ʽ * ��һλ����ʽ��
	//3�������ó���������������ʽ����ߴ�С�ڳ�ʽ����ߴ�ʱ�������
void PolyDivide(polypointer& L3, polypointer& L4, polypointer& L1/*����ʽ*/, polypointer& L2/*��ʽ*/)
{
	polypointer r, s, t;
	r = L1->link;
	s = L2->link;
	int c, e;
	c = r->coef / s->coef;
	e = r->exp - s->exp;
	t = L3;
	while (t->link != NULL)
		t = t->link;
	Attach(c, e, t);

	polypointer temp = new polynode;
	temp->link = NULL;
	polypointer a = temp;
	Attach(c, e, a);

	polypointer temp2 = PolyMultiply(L2, temp);
	L1 = PolyMinus(L1, temp2);
	if (L1->link == NULL || L1->link->exp < L2->link->exp) {
		L4 = L1;
		return;
	}
	PolyDivide(L3, L4, L1, L2);
}

//ִ�г������Ⱦ�����������ϵ��Ϊ0���ȫ
void Insert0(polypointer p, polypointer& L)
{
	polypointer q;
	q = new polynode;
	q->coef = 0;
	q->exp = p->exp - 1;
	q->link = p->link;
	p->link = q;
}
void MakeFull(polypointer& L1)
{
	polypointer p;
	for (p = L1->link; p->link != NULL; p = p->link) {
		if (p->exp != p->link->exp + 1)
			Insert0(p, L1);
	}
	while (p->exp != 0)
	{
		Attach(0, p->exp - 1, p);
	}

}

//�������洢�Ķ���ʽ
void Print(polypointer& L) {
	polypointer p = L->link;
	if (p == NULL) {
		cout << 0;
	}
	while (p != NULL) {
		if (p->exp != 0) {
			cout << p->coef << "x^" << p->exp;
		}
		else {
			cout << p->coef;
		}
		p = p->link;
		if (p == NULL) {
			break;
		}
		else if (p->coef > 0) {
			cout << "+";
		}
	}
	cout << endl;
}

//�ͷ�����Ŀռ�
void destoryPoly(polypointer& q) {
	polypointer node = q;
	while (node != NULL) {
		node = node->link;  //pָ����һ�������ٵĽ��
		delete q;  //���ٵ�ǰ���
		q = node;   //
	}
}

//����洢��������ʽ�Ŀռ䣬��������������
void minorMain(int a) {
	polypointer L1, L2;
	L1 = new polynode;
	L1->link = NULL;
	L2 = new polynode;
	L2->link = NULL;

	Input(L1);          //���뵥����L1
	cout << "f(x)=";
	Print(L1);         //���������L1

	Input(L2);         //���뵥����L2
	cout << "g(x)=";
	Print(L2);         //���������L2

	switch (a)
	{
	case 1: {
		polypointer L0;
		L0 = PolyAdd(L1, L2);          //���üӷ�����
		cout << "F(x)=f(x)+g(x)=";
		Print(L0);
		destoryPoly(L1);
		destoryPoly(L2);
		destoryPoly(L0);
		break;
	}

	case 2: {
		polypointer L9;
		L9 = PolyMinus(L1, L2);          //���ü�������
		cout << "F(x)=f(x)-g(x)=";
		Print(L9);
		destoryPoly(L1);
		destoryPoly(L2);
		destoryPoly(L9);
		break;
	}

	case 3: {
		polypointer L8;
		L8 = PolyMultiply(L1, L2);         //���ó˷�������
		cout << "F(x)=f(x)*g(x)=";
		Print(L8);
		destoryPoly(L1);
		destoryPoly(L2);
		destoryPoly(L8);
		break;
	}

	case 4: {
		MakeFull(L1);
		MakeFull(L2);
		polypointer L3, L4;
		L3 = new polynode;
		L3->link = NULL;
		L4 = new polynode;
		L4->link = NULL;
		PolyDivide(L3, L4, L1, L2);              //���õݹ��������
		cout << "F(x)=f(x)/g(x):" << endl;
		cout << "��ʽ: ";
		Print(L3);
		cout << endl;
		cout << "��ʽ: ";
		Print(L4);
		break;
	}
	}
}

int main()
{
	cout << "0.�˳�" << endl;
	cout << "1.����һԪ����ʽ���" << endl;
	cout << "2.����һԪ����ʽ���" << endl;
	cout << "3.����һԪ����ʽ���" << endl;
	cout << "4.����һԪ����ʽ���" << endl;
	int a;
	while (1) {                //ѭ������ֱ������0
		cout << "��ѡ�������"; 
		cin >> a;
		if (a == 1) {
			cout << "��ѡ��Ĳ����Ƕ���ʽ��ӣ�" << endl;
			minorMain(a);
		}
		else if (a == 2) {
			cout << "��ѡ��Ĳ����Ƕ���ʽ�����" << endl;
			minorMain(a);
		}
		else if (a == 3) {
			cout << "��ѡ��Ĳ����Ƕ���ʽ��ˣ�" << endl;
			minorMain(a);
		}
		else if (a == 4) {
			cout << "��ѡ��Ĳ����Ƕ���ʽ�����" << endl;
			minorMain(a);
		}
		else if (a == 0) {
			break;
		}
		else {
			cout << "�������" << endl;
		}
	}
}