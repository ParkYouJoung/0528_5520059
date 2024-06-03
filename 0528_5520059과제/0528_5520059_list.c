#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {
	element data;
	struct listNode* link;
} ListNode;

ListNode* insert_first(ListNode* tail, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (tail == NULL) {
		tail = node;
		node->link = tail;
	}
	else {
		node->link = tail->link;
		tail->link = node;
	}
	return tail;
}

void print_list(ListNode* tail) {
	ListNode* p;

	if (tail == NULL) return;
	p = tail->link;
	do {
		printf("%d-> ", p->data);
		p = p->link;
	} while (p != tail);
	printf("%d (head)\n ", p->data);
}

ListNode* insert_last(ListNode* tail, element data) {

	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (tail == NULL) {
		tail = node;
		node->link = node;
	}
	else {
		node->link = tail->link;
		tail->link = node;
		tail = node;
	}
	return tail;
}

ListNode* delete_first(ListNode* tail) {
	if (tail == NULL) return NULL;

	ListNode* head = tail->link;
	if (head == tail) {
		free(tail);
		return NULL;
	}

	tail->link = head->link;
	free(head);
	return tail;
}

ListNode* delete_last(ListNode* tail) {
	if (tail == NULL) return NULL;

	ListNode* prev = NULL;
	ListNode* curr = tail->link;

	if (tail == tail->link) {
		free(tail);
		return NULL;
	}

	while (curr != tail) {
		prev = curr;
		curr = curr->link;
	}

	prev->link = tail->link;
	free(tail);
	return prev;
}

int main() {
	int choice, n;
	ListNode* tail = NULL;

	while (1) {
		printf("\n�޴�\n ");
		printf("1. ���� �Է� �޾Ƽ� ����Ʈ ó���� �߰�\n");
		printf("2. ���� �Է� �޾Ƽ� ����Ʈ �������� �߰�\n");
		printf("3. ����Ʈ ó�� ��� ����\n");
		printf("4. ����Ʈ ������ ��� ����\n");
		printf("5. ����Ʈ ����Ʈ\n");
		printf("6. ����\n");
		printf("�޴��� �����ϼ���: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("�߰��� ���ڸ� �Է��ϼ���: ");
			scanf("%d", &n);
			tail = insert_first(tail, n);
			break;
		case 2:
			printf("�߰��� ���ڸ� �Է��ϼ���: ");
			scanf("%d", &n);
			tail = insert_last(tail, n);
			break;
		case 3:
			printf("ó�� ��� ����\n");
			tail = delete_first(tail);
			break;
		case 4:
			printf("������ ��� ����\n");
			tail = delete_last(tail);
			break;
		case 5:
			print_list(tail);
			break;
		case 6:
			printf("���α׷��� �����մϴ�.\n");
			exit(0);
		default:
			printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���\n");
			break;
		}
	}
	return 0;
}