class Solution {
    public List<String> findItinerary(List<List<String>> tickets) {
        Map<String, PriorityQueue<String>> targets = new HashMap<>();
        List<String> route = new LinkedList();

        for (List<String> ticket : tickets)
            targets.computeIfAbsent(ticket.get(0), k -> new PriorityQueue()).add(ticket.get(1));
        visit(targets, route, "JFK");
        return route;
    }
    
    

    void visit(Map<String, PriorityQueue<String>> targets, List<String> route, String airport) {
        while(targets.containsKey(airport) && !targets.get(airport).isEmpty())
            visit(targets, route, targets.get(airport).poll());
        route.add(0, airport);
    }
}

// Runtime: 5 ms, faster than 76.49% of Java online submissions for Reconstruct Itinerary.
// Memory Usage: 39.2 MB, less than 94.18% of Java online submissions for Reconstruct Itinerary.
// time Complexity: O(n)
// space complexity: O(n)
// https://leetcode.com/problems/reconstruct-itinerary/discuss/78768/Short-Ruby-Python-Java-C%2B%2B