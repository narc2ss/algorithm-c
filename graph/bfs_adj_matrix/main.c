#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
  element queue[MAX_QUEUE_SIZE];
  int front;
  int rear;
} QueueType;

void error(char* message) {
  printf("%s\n", message);
  exit(1);
}

void queue_init(QueueType* q) {
  q->front = 0;
  q->rear = 0;
}

int is_empty(QueueType* q) {
  return q->front == q->rear;
}

int is_full(QueueType* q) {
  return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item) {
  if (is_full(q)) {
    error("queue is overflow");
  }

  q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
  q->queue[q->rear] = item;
}

element dequeue(QueueType* q) {
  if (is_empty(q)) {
    error("underflow");
  }

  q->front = (q->front + 1) % MAX_QUEUE_SIZE;
  return q->queue[q->front];
}

#define MAX_VERTICES 50

typedef struct {
  int n;
  int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;
int visited[MAX_VERTICES];

void graph_init(GraphType* g) {
  g->n = 0;
  for (int i = 0; i < MAX_VERTICES; i++) {
    for (int j = 0; j < MAX_VERTICES; j++) {
      g->adj_mat[i][j] = 0;
    }
  }
}

void insert_vertex(GraphType* g) {
  if (((g->n) + 1) > MAX_VERTICES) {
    error("matrix is overflow");
  }

  g->n++;
}

void insert_edge(GraphType* g, int start, int end) {
  if (start >= g->n || end >= g->n) {
    error("vertex key error");
  }

  g->adj_mat[start][end] = 1;
  g->adj_mat[end][start] = 1;
}

void bfs_mat(GraphType* g, int v) {
  QueueType q;
  queue_init(&q);
  visited[v] = true;
  enqueue(&q, v);
  while (!is_empty(&q)) {
    v = dequeue(&q);
    for (int i = 0; i < g->n; i++) {
      if (g->adj_mat[v][i] && !visited[i]) {
        visited[i] = true;
        printf("%d ", i);
        enqueue(&q, i);
      }
    }
  }
}

int main(void) {
  GraphType* g;
  g = (GraphType*)malloc(sizeof(GraphType));
  graph_init(g);
  for (int i = 0; i < 7; i++) {
    insert_vertex(g);
  }

  insert_edge(g, 2, 6);
  insert_edge(g, 2, 5);
  insert_edge(g, 0, 1);
  insert_edge(g, 1, 4);
  insert_edge(g, 0, 2);
  insert_edge(g, 1, 3);

  bfs_mat(g, 0);

  free(g);

  printf("\n");
  return 0;
}