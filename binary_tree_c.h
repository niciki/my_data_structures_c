#ifndef binary_tree.h
#define binary_tree.h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  int data;#endif
  struct node *left;
  struct node *right;
  struct node *parent;
} tree;

tree * tree_create (int value) {
  tree *node = malloc (sizeof (tree));
  node->data = value;
  node->right = NULL;
  node->left = NULL;
  node->parent == NULL;
  return node;
}

tree *search_leaf(tree *node) {
    while (node->right || node->left) {
        if (node->right) node = node->right;
        if (node->left) node = node->left;
    }
    return node;
}

void tree_print (tree * node) {
  if (node == NULL) {
      printf(";");
      return;
  }
  printf ("%d->",node->data);
  tree_print (node->left);
  tree_print (node->right);
}

tree *tree_add(tree *node, int val) {
    tree *new = node;
    tree *parent = NULL;
    tree *tmp = malloc(sizeof(tree)); 
    tmp->data = val; 
    while (new != NULL) { 
        parent = new;
        if (val < new->data) {
            new = new->left;
        } else {
            new = new->right;
        }
    }
    tmp->parent = parent;
    tmp->left = NULL;
    tmp->right = NULL;
    if (val < parent->data) {
        parent->left = tmp;
    } else {
        parent->right = tmp;
    }
    return node;
}

bool is_a_leaf (tree * node) {
  if (node->left == NULL && node->right == NULL) {
      return true;
  }
  return false;
}

tree* search(tree *node, int val)
{
    if (node == NULL) {
        printf("There is no %d\n", val);
        return NULL;
    }
    if (node->data == val) {
        return node;
    }
    if (val < node->data){
        return search(node->left, val);    
    }
    else return search(node->right, val);
}

tree * tree_min(tree * node){
    if(node -> left == NULL){
        return node;
    }
    return tree_min(node -> left);
}

tree * tree_max(tree * node){
    if(node -> right == NULL){
        return node;
    }
    return tree_max(node -> right);
}

int search_a_leaf (tree * node, int number) {
  tree * t[number];
  t[0] = node;
  int i = 1, j = 0;
  while(true){
      if(t[j]->left == NULL && t[j]->right == NULL){
          return t[j]->data;
      } else {
          t[i++] = node->left;
          t[i++] = node->right;
      }
      j++;
  }
}

tree *delete_node(tree **node, int value)
{
    tree *del_node = NULL, *_1 = NULL;
    if (search(*node, value) == NULL) {
        return 0;
    }
    del_node = search(*node, value);
    if ((del_node->left == NULL) && (del_node->right == NULL))
    {
        if (*node == del_node) {
            free(*node);
            *node = NULL;
            return 0;
        }
        _1 = del_node->parent; 
        if (del_node == _1->right) _1->right == NULL;
        else _1->left == NULL;
        if (del_node->parent->left == del_node) {
            free(del_node);
            del_node->parent->left = NULL;
        }
        if (del_node->parent->right == del_node) {
            free(del_node);
            del_node->parent->right = NULL;
        }
        return 0;
    }
    if ((del_node->left == NULL) && (del_node->right != NULL)) {
        _1 = del_node;
        del_node = tree_min(del_node->right);
        _1-> data = del_node-> data;
        if (del_node->parent->left == del_node) {
            free(del_node);
            del_node->parent->left = NULL;
        }
        if (del_node->parent->right == del_node) {
            free(del_node);
            del_node->parent->right = NULL;
        }
        return 0;
    }
    if ((del_node->left != NULL) && (del_node->right == NULL)) {
        _1 = del_node;
        del_node = tree_max(del_node->left);
        _1->data = del_node->data;
        if (del_node->parent->left == del_node) {
            free(del_node);
            del_node->parent->left = NULL;
            return 0;
        }
        if (del_node->parent->right == del_node) {
            free(del_node);
            del_node->parent->right = NULL;
            return 0;
        }
        return 0;
    }
    if ((del_node->left != NULL) && (del_node->right != NULL)) {
        _1 = del_node;
        del_node = tree_min(del_node->right);
        _1->data = del_node->data;
        if (del_node->parent->left == del_node) {
            free(del_node);
            del_node->parent->left = NULL;
        }
        if (del_node->parent->right == del_node) {
            free(del_node);
            del_node->parent->right = NULL;
        }
        return 0;
    }
    return 0;
}

void draw_tree(tree *node, int n) {
    if (node->left != NULL){
        draw_tree(node->left, n + 2);
    }
    for (int i = 0; i < n; ++i){
        printf("  ");
    }
    printf("%d\n", node->data);
    if (node->right) {
        draw_tree(node->right, n + 2);
    }
}
#endif
