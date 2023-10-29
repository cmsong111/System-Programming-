#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 학생 정보를 저장할 구조체
struct Student {
  char name[50];
  int midterm;
  int final;
  struct Student* left;
  struct Student* right;
};

// 새 학생 노드를 생성하고 초기화
struct Student* createStudent(const char* name, int midterm, int final) {
  struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
  if (newStudent == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }
  strcpy(newStudent->name, name);
  newStudent->midterm = midterm;
  newStudent->final = final;
  newStudent->left = NULL;
  newStudent->right = NULL;
  return newStudent;
}

// 학생 정보를 트리에 추가
struct Student* insertStudent(struct Student* root,
                              const char* name,
                              int midterm,
                              int final) {
  if (root == NULL) {
    return createStudent(name, midterm, final);
  }

  int cmp = strcmp(name, root->name);
  if (cmp < 0) {
    root->left = insertStudent(root->left, name, midterm, final);
  } else if (cmp > 0) {
    root->right = insertStudent(root->right, name, midterm, final);
  }

  return root;
}

// 학생 정보를 중위 순회로 출력
void inorderTraversal(struct Student* root) {
  if (root != NULL) {
    inorderTraversal(root->left);
    printf("Name: %s, Midterm: %d, Final: %d\n", root->name, root->midterm,
           root->final);
    inorderTraversal(root->right);
  }
}

int main() {
  int numStudents;
  printf("Enter the number of students: ");
  scanf("%d", &numStudents);
  getchar();  // newline character 처리

  struct Student* root = NULL;

  for (int i = 0; i < numStudents; i++) {
    char name[50];
    int midterm, final;
    printf("Enter student name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // newline character 제거
    printf("Enter midterm score for %s: ", name);
    scanf("%d", &midterm);
    printf("Enter final score for %s: ", name);
    scanf("%d", &final);
    getchar();  // newline character 처리

    root = insertStudent(root, name, midterm, final);
  }

  printf("\nStudent Information:\n");
  inorderTraversal(root);

  // 메모리 해제
  // (학습 목적의 간단한 예제이므로 메모리 해제는 생략합니다)

  return 0;
}
