class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        if(root==null||target==null)return new ArrayList<>();
        HashMap<TreeNode, TreeNode> root_parent = new HashMap<>();
        populateMap(root_parent, root, null);
        Queue<TreeNode> q = new LinkedList<>();
        q.add(target);
        
        HashSet<Integer> vis = new HashSet<>();
        vis.add(target.val);
        int level=0;
        while(!q.isEmpty()){
            if(level == K){
                return printNodes(q);
            }
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode node = q.remove();
                if(node.left!=null && !vis.contains(node.left.val)){
                    q.add(node.left);
                    vis.add(node.left.val);
                }
                if(node.right!=null && !vis.contains(node.right.val)){
                    q.add(node.right);
                    vis.add(node.right.val);
                }
                TreeNode parent = root_parent.get(node);
                if(parent!=null && !vis.contains(parent.val)){
                    q.add(parent);
                    vis.add(parent.val);
                }
            }
            level++;
        }
        return new ArrayList<>();
    }
    public static void populateMap(HashMap<TreeNode, TreeNode> root_parent, TreeNode root, TreeNode parent){
        if(root==null)return;
        root_parent.put(root,parent);
        populateMap(root_parent, root.left,root);
        populateMap(root_parent, root.right,root);
    }
    public static List<Integer> printNodes(Queue<TreeNode> q){
        List<Integer> res = new ArrayList<>();
        while(!q.isEmpty()){
            res.add(q.remove().val);
        }
        return res;
    }
}