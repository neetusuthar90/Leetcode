# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxLevelSum(self, root):
        if(root == None):
            return 0

        max_sum = float('-inf')
        result = 0

        queue = deque()
        queue.append(root)
        level = 0

        while queue:
            size = len(queue)
            sum = 0

            for _ in range(size):
                curNode = queue.popleft()
                sum += curNode.val

                if curNode.left:
                    queue.append(curNode.left)
                if curNode.right:
                    queue.append(curNode.right)
            
            level += 1

            if sum > max_sum:
                max_sum = sum
                result = level

        return result;