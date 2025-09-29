import graphviz

# Define Node class
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

# Insert into BST
def insert(root, key):
    if root is None:
        return Node(key)
    if key < root.key:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
    return root

# Numbers to insert
numbers = [11, 6, 8, 19, 4, 10, 5, 17, 43, 49, 31]

# Build BST
root = None
for num in numbers:
    root = insert(root, num)

# Visualization with colors
def add_nodes_edges_colored(dot, node, level=0):
    if node is None:
        return
    colors = ["lightblue", "lightgreen", "orange", "yellow", "pink", "lightgrey"]
    color = colors[level % len(colors)]
    
    dot.node(str(node.key), str(node.key), style="filled", fillcolor=color)
    if node.left:
        dot.edge(str(node.key), str(node.left.key))
        add_nodes_edges_colored(dot, node.left, level+1)
    if node.right:
        dot.edge(str(node.key), str(node.right.key))
        add_nodes_edges_colored(dot, node.right, level+1)

# Build graph
dot_colored = graphviz.Digraph()
add_nodes_edges_colored(dot_colored, root)

# Export image
dot_colored.render("bst_tree_colored", format="png", view=True)

