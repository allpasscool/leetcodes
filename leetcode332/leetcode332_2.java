class Solution {
    public List<String> findItinerary(List<List<String>> tickets) {
        Map<String, PriorityQueue<String>> targets = new HashMap<>();
        
        for (List<String> ticket : tickets)
            targets.computeIfAbsent(ticket.get(0), k -> new PriorityQueue()).add(ticket.get(1));
        
        List<String> route = new LinkedList();
        Stack<String> stack = new Stack<>();
        stack.push("JFK");
        
        // dfs
        while (!stack.empty()) 
        {
            while (targets.containsKey(stack.peek()) && !targets.get(stack.peek()).isEmpty())
            {
                stack.push(targets.get(stack.peek()).poll());
            }
            route.add(0, stack.pop());
        }
        
        return route;
    }
}

// Runtime: 8 ms, faster than 21.56% of Java online submissions for Reconstruct Itinerary.
// Memory Usage: 39.7 MB, less than 35.99% of Java online submissions for Reconstruct Itinerary.
// time complexity: O(n)
// space complexity: O(n)
// https://leetcode.com/problems/reconstruct-itinerary/discuss/78768/Short-Ruby-Python-Java-C%2B%2B