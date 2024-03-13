-- Define a data type for a 2-3 Tree. A 2-3 Tree can have nodes with one or two values.
data TwoThreeTree t = Empty 
                    | Node t (TwoThreeTree t) (TwoThreeTree t)                     -- Node in the tree which only has one variable
                    | Node2 t t (TwoThreeTree t) (TwoThreeTree t) (TwoThreeTree t) -- Node in the tree which has 2 variables
                    deriving (Eq, Show)

-- Function to add an element to a 2-3 Tree.
add :: Ord t => t -> TwoThreeTree t -> TwoThreeTree t
add x Empty = Node x Empty Empty

-- When adding to a node, check if the value can be upgraded to a 3-node, or split into multiple nodes.
add x (Node y left right)
    | x < y     = upgradeNode x y left right  -- Try upgrading to a 3-node
    | otherwise = upgradeNode y x left right  -- Try upgrading to a 3-node

-- When adding to a 3-node, handle the possible cases for the value positions.
add x (Node2 y z left middle right)
    | x < y     = Node2 y z (add x left) middle right  -- Add to the left subtree
    | x < z     = Node2 y z left (add x middle) right  -- Add to the middle subtree
    | otherwise = Node2 y z left middle (add x right)  -- Add to the right subtree

-- Function to try upgrading a node to a 3-node.
upgradeNode :: Ord t => t -> t -> TwoThreeTree t -> TwoThreeTree t -> TwoThreeTree t
upgradeNode a b left right
    | a == b    = Node a left right           -- No upgrade if values are equal
    | a < b     = Node2 a b left Empty right  -- Upgrade to a 3-node
    | otherwise = Node2 b a left Empty right  -- Ensure correct order in a 3-node

-- Function to check if a value is a member of the 2-3 Tree.
member :: Ord t => t -> TwoThreeTree t -> Bool
member _ Empty = False -- If the tree is empty, return False.

-- If the tree is a 2-node (single value), check if the target value (x) matches the value in the node (y).
-- If they match, return True, indicating that the value is found.
-- Otherwise, recursively search in both the left and right subtrees.
member x (Node y left right) = x == y || member x left || member x right

-- If the tree is a 3-node (two values), check if the target value (x) matches either of the values in the node (y and z).
-- If x equals y or z, return True to indicate that the value is present.
-- If not, recursively search in all three subtrees (left, middle, and right).
member x (Node2 y z left middle right) = x == y || x == z || member x left || member x middle || member x right


-- Function to compute the height of a 2-3 Tree.
height :: TwoThreeTree t -> Int
height Empty = 0  -- If the root of the tree is empty, the height is 0.
height (Node _ left right) = 1 + max (height left) (height right)  -- If the tree provided starts with a 2-node (contains only one value), calculate the height recursively.
height (Node2 _ _ left middle right) = 1 + maximum [height left, height middle, height right]  -- If the tree provided starts with a 3-node (contains two values), calculate the height recursively and take note of the maximum height along its left, middle, and right subtrees.


-- Function to pretty print a 2-3 Tree.
prettyPrint :: Show t => TwoThreeTree t -> IO ()
prettyPrint tree = printSubtree "" tree
  where
    -- Recursive helper function for printing subtrees, takes an indentation string and a tree.
    printSubtree indent Empty = putStrLn $ indent ++ "nil"  -- Print "nil" for an empty node in a tree or if the tree is empty.
    printSubtree indent (Node x left right) = do
        putStrLn $ indent ++ show x  -- Print the value of the current node.
        -- Recursively print the left and right subtrees with increased indentation.
        printSubtree (indent ++ "  ") left   -- Left child of a 2-node
        printSubtree (indent ++ "  ") right  -- Right child of a 2-node
    printSubtree indent (Node2 x y left middle right) = do
        -- Print the values of the 3-node separated by a comma.
        putStrLn $ indent ++ show x ++ "," ++ show y
        -- Recursively print the left, middle, and right subtrees with increased indentation.
        printSubtree (indent ++ "  ") left    -- Left child of a 3-node
        printSubtree (indent ++ "  ") middle  -- Middle child of a 3-node
        printSubtree (indent ++ "  ") right   -- Right child of a 3-node


main :: IO ()
main = do
    -- The seqence for this tree is 3, 10, 6, 15, 20, 18.
    let tree1 = add 3 Empty
    let tree2 = add 10 tree1
    let tree3 = add 6 tree2
    let tree4 = add 15 tree3
    let tree5 = add 20 tree4
    let tree6 = add 18 tree5

    -- Testing the prettyPrint function
    prettyPrint tree6

    --Rigorous testing of member
    print (member 18 tree6)
    print (member 6 tree6)
    print (member 10 tree6)
    print (member 15 tree6)
    print (member 20 tree6)
    print (member 3 tree6)
    print (member 5 tree6)
    --Printing the height
    print (height tree6)
