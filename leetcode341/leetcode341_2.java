
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
import java.util.NoSuchElementException;

public class NestedIterator implements Iterator<Integer> {

    // In Java, the Stack class is considered deprecated. Best practice is to use
    // a Deque instead. We'll use addFirst() for push, and removeFirst() for pop.
    // private Deque<NestedInteger> stack;
    private Stack<NestedInteger> stack;

    public NestedIterator(List<NestedInteger> nestedList) {
        // The constructor puts them on in the order we require. No need to reverse.
        // stack = new ArrayDeque(nestedList);
        stack = new Stack<NestedInteger>();
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            stack.push(nestedList.get(i));
            // stack.addFirst(nestedList.get(i));
        }
    }

    @Override
    public Integer next() {
        // As per java specs, throw an exception if there's no elements left.
        if (!hasNext())
            throw new NoSuchElementException();
        // hasNext ensures the stack top is now an integer. Pop and return
        // this integer.
        // return stack.removeFirst().getInteger();
        return stack.pop().getInteger();
    }

    @Override
    public boolean hasNext() {
        // Check if there are integers left by getting one onto the top of stack.
        makeStackTopAnInteger();
        // If there are any integers remaining, one will be on the top of the stack,
        // and therefore the stack can't possibly be empty.
        return !stack.isEmpty();
    }

    private void makeStackTopAnInteger() {
        // While there are items remaining on the stack and the front of
        // stack is a list (i.e. not integer), keep unpacking.
        // while (!stack.isEmpty() && !stack.peekFirst().isInteger()) {
        while (!stack.isEmpty() && !stack.peek().isInteger()) {
            // Put the NestedIntegers onto the stack in reverse order.
            List<NestedInteger> nestedList = stack.pop().getList();
            // List<NestedInteger> nestedList = stack.removeFirst().getList();
            for (int i = nestedList.size() - 1; i >= 0; i--) {
                stack.push(nestedList.get(i));
                // stack.addFirst(nestedList.get(i));
            }
        }
    }
}
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList); while (i.hasNext()) v[f()]
 * = i.next();
 */

// Runtime: 4 ms, faster than 27.89% of Java online submissions for Flatten
// Nested List Iterator.
// Memory Usage: 41.2 MB, less than 81.93% of Java online submissions for
// Flatten Nested List Iterator.
// time complexity: Constructor: O(N + L) next(): O(1) hasNext(): O(1)
// space complexity: O(N + L)