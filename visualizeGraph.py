import networkx as nx 
import sys
import matplotlib.pyplot as plt

g= nx.Graph()

args = sys.argv

options = {
    'node_color': 'green',
    'node_size': 500,
    'width': 3,
    # 'arrowstyle': '-|>',
    'arrowsize': 12,
}

with open(f"{args[1]}", 'r') as f:
    x = f.readlines()
    m = int(x[0].split(' ')[1])
    for i in range(1, 1 + m):
        z = [int(_) for _ in x[i].split(' ')]
        g.add_edge(z[0], z[-1])
        

nx.draw_networkx(g, **options, arrows=True, with_labels=True)
plt.show()        
    