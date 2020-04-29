class TreeNode{
public:
  TreeNode();
  TreeNode(int key);
  //TreeNode(int key, <type>value);
  ~TreeNode();
  //when working with template classes
  //virtual ~TreeNode();  //RESEARCH WHY WE NEED THIS

  int key;
  TreeNode *left;
  TreeNode *right;
};
