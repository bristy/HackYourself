import java.util.*;

class UndirectedGraphNode {
  int label;
  List<UndirectedGraphNode> neighbors;
  UndirectedGraphNode(int x){
    label = x;
    neighbors = new ArrayList<UndirectedGraphNode>();
  }
}

public class GraphClone{
  public UndirectedGraphNode cloneGraph(UndirectedGraphNode node){
    if(node == null){
      return null;
    }
    Queue<UndirectedGraphNode> Q = new LinkedList<UndirectedGraphNode>();
    Map<UndirectedGraphNode, UndirectedGraphNode> map = 
      new HashMap<UndirectedGraphNode, UndirectedGraphNode>();
    
    Q.add(node);
    UndirectedGraphNode clonedNode = new UndirectedGraphNode(node.label);
    // used for store visited status
    map.put(node, clonedNode);

    while(!Q.isEmpty()){
      UndirectedGraphNode curr = Q.poll();
      
      if(curr == null){
        continue;
      }
      UndirectedGraphNode currClonedNode = map.get(curr);
      List<UndirectedGraphNode> neighbors = curr.neighbors;
      if(neighbors != null){
        for(UndirectedGraphNode v : neighbors){
          UndirectedGraphNode newClone = null;
          // if v is not visited
          if(!map.containsKey(v)){
            newClone = new UndirectedGraphNode(v.label);
            currClonedNode.neighbors.add(newClone);
            map.put(v, newClone);
            Q.add(v);
          } else {
            newClone = map.get(v);
            currClonedNode.neighbors.add(newClone);

          }
        }
      }
    }
    return clonedNode;
  }
}
