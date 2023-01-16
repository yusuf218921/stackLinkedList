#include <stdio.h>
#include <stdlib.h>

struct Dugum {
	int veri;
	struct Dugum* sonraki;
}*top=NULL;

void push(int s) {
	struct Dugum* yeniDugum;
	yeniDugum = (struct Dugum*)malloc(sizeof(struct Dugum));
	yeniDugum->veri = s;
	if (top == NULL) {
		yeniDugum->sonraki = NULL;
		top = yeniDugum;
	}
	else {
		yeniDugum->sonraki = top;
		top = yeniDugum;
	}
	printf("eleman eklendi\n");
}

void pop() {
	if (top == NULL) {
		printf("yigin bos, silinecek eleman yok\n");
	}
	else {
		struct Dugum* temp = top;
		printf("silinecek eleman -> %d\n", temp->veri);
		top = temp->sonraki;
		free(temp);
	}
}

void peek() {
	if (top == NULL) {
		printf("yigin bos.\n");
	}
	else {
		struct Dugum* temp = top;
		printf("top -> %d\n", temp->veri);
	}
}

void isEmpty() {
	if (top == NULL) {
		printf("yigin bosdur.\n");
	}
	else {
		printf("yigin bos degildir.\n");
	}
}

void read() {
	if (top == NULL) {
		printf("yigin bosdur.\n");
	}
	else {
		struct Dugum* temp = top;
		while (temp != NULL) {
			printf("%d\n", temp->veri);
			temp = temp->sonraki;
		}
	}
}

int main()
{
	push(5);
	push(6);
	push(7);
	push(9);
	push(1);
	push(2);

	peek();

	pop();

	peek();

	isEmpty();

	read();
}


