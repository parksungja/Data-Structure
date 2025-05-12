#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 연락처 노드 구조체
typedef struct Contact {
    char name[50];
    char phone[20];
    struct Contact* next;
} Contact;

// 연락처 추가 (맨 뒤에 삽입)
Contact* addContact(Contact* head, const char* name, const char* phone) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = NULL;

    if (head == NULL) {
        return newContact;
    }

    Contact* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newContact;
    return head;
}

// 연락처 검색 (이름 기준)
void searchContact(Contact* head, const char* name) {
    Contact* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("이름: %s\n전화번호: %s\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }
    printf("'%s' 연락처를 찾을 수 없습니다.\n", name);
}

// 연락처 삭제 (이름 기준)
Contact* deleteContact(Contact* head, const char* name) {
    if (head == NULL) {
        printf("연락처가 비어 있습니다.\n");
        return NULL;
    }

    if (strcmp(head->name, name) == 0) {
        Contact* temp = head;
        head = head->next;
        free(temp);
        printf("'%s' 연락처가 삭제되었습니다.\n", name);
        return head;
    }

    Contact* current = head;
    while (current->next != NULL && strcmp(current->next->name, name) != 0) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("'%s' 연락처를 찾을 수 없습니다.\n", name);
        return head;
    }

    Contact* temp = current->next;
    current->next = current->next->next;
    free(temp);
    printf("'%s' 연락처가 삭제되었습니다.\n", name);
    return head;
}

// 연락처 목록 출력
void printContacts(Contact* head) {
    printf("\n=== 전화번호부 ===\n");
    Contact* current = head;
    while (current != NULL) {
        printf("이름: %s, 전화번호: %s\n", current->name, current->phone);
        current = current->next;
    }
    printf("=================\n");
}

// 모든 연락처 메모리 해제
void freeContacts(Contact* head) {
    Contact* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// 메인 함수
int main() {
    Contact* phoneBook = NULL;
    int choice;
    char name[50];
    char phone[20];

    while (1) {
        printf("\n==== 전화번호부 메뉴 ====\n");
        printf("1. 연락처 추가\n");
        printf("2. 연락처 검색\n");
        printf("3. 연락처 삭제\n");
        printf("4. 전체 출력\n");
        printf("5. 전체 삭제\n");
        printf("기타. 종료\n");
        printf("========================\n");
        printf("선택 >> ");
        scanf("%d", &choice);
        getchar(); // 입력 버퍼 클리어

        switch (choice) {
            case 1:
                printf("이름 입력: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // 줄바꿈 제거

                printf("전화번호 입력: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = '\0';

                phoneBook = addContact(phoneBook, name, phone);
                printf("연락처가 추가되었습니다.\n");
                break;

            case 2:
                printf("검색할 이름 입력: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                searchContact(phoneBook, name);
                break;

            case 3:
                printf("삭제할 이름 입력: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                phoneBook = deleteContact(phoneBook, name);
                break;

            case 4:
                printContacts(phoneBook);
                break;

            case 5:
                freeContacts(phoneBook);
                phoneBook = NULL;
                printf("모든 연락처가 삭제되었습니다.\n");
                break;

            default:
                printf("프로그램을 종료합니다.\n");
                freeContacts(phoneBook);
                return 0;
        }
    }
}