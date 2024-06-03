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
		printf("\n메뉴\n ");
		printf("1. 숫자 입력 받아서 리스트 처음에 추가\n");
		printf("2. 숫자 입력 받아서 리스트 마지막에 추가\n");
		printf("3. 리스트 처음 노드 삭제\n");
		printf("4. 리스트 마지막 노드 삭제\n");
		printf("5. 리스트 프린트\n");
		printf("6. 종료\n");
		printf("메뉴를 선택하세요: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("추가할 숫자를 입력하세요: ");
			scanf("%d", &n);
			tail = insert_first(tail, n);
			break;
		case 2:
			printf("추가할 숫자를 입력하세요: ");
			scanf("%d", &n);
			tail = insert_last(tail, n);
			break;
		case 3:
			printf("처음 노드 삭제\n");
			tail = delete_first(tail);
			break;
		case 4:
			printf("마지막 노드 삭제\n");
			tail = delete_last(tail);
			break;
		case 5:
			print_list(tail);
			break;
		case 6:
			printf("프로그램을 종료합니다.\n");
			exit(0);
		default:
			printf("잘못된 입력입니다. 다시 선택하세요\n");
			break;
		}
	}
	return 0;
}