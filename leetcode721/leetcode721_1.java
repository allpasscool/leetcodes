class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        Map<String, String> emailToName = new HashMap();
        // graph is "key" email = value email {"a", "b", "c"}
        // that means key email and its value eamils belong to the same person
        Map<String, ArrayList<String>> graph = new HashMap();
        
        // travese all accounts
        for (List<String> account: accounts) {
            String name = "";
            for (String email: account) {
                // account[0] is owner's name
                if (name == "") {
                    name = email;
                    continue;
                }
                graph.computeIfAbsent(email, x-> new ArrayList<String>()).add(account.get(1));
                graph.computeIfAbsent(account.get(1), x-> new ArrayList<String>()).add(email);
                // this "email" belongs to "name"
                emailToName.put(email, name);
            }
        }

        Set<String> seen = new HashSet();
        List<List<String>> ans = new ArrayList();
        
        // traverse all emails
        for (String email: graph.keySet()) {
            
            // if this email is not seen yet
            if (!seen.contains(email)) {
                seen.add(email);
                Stack<String> stack = new Stack();
                stack.push(email);
                // place all emails belong to the same person in "component"
                List<String> component = new ArrayList();
                
                // find all emails belong to the same person
                while (!stack.empty()) {
                    String node = stack.pop();
                    component.add(node);
                    
                    for (String nei: graph.get(node)) {
                        if (!seen.contains(nei)) {
                            seen.add(nei);
                            stack.push(nei);
                        }
                    }
                }
                
                // sort emails in order
                Collections.sort(component);
                // add name in index 0
                component.add(0, emailToName.get(email));
                // add component to ans
                ans.add(component);
            }
        }
        
        return ans;
    }
}

// Runtime: 43 ms, faster than 34.27% of Java online submissions for Accounts Merge.
// Memory Usage: 43.1 MB, less than 86.07% of Java online submissions for Accounts Merge.
// Time Complexity: O(∑ai logai), where ai is the length of accounts[i]. 
// Without the log factor, this is the complexity to build the graph and search for each component. 
// The log factor is for sorting each component at the end.
// Space Complexity: O(∑ai), the space used by our graph and our search.