class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        Map<String, List<Integer>> email_to_account = new HashMap<>();
        int n = accounts.size();
        
        // traverse accounts
        for (int i = 0; i < n; i++) {
            int emails = accounts.get(i).size();
            
            // traverse each account's emails
            for (int j = 1; j < emails; j++) {
                // if first time meet this email 
                if (email_to_account.get(accounts.get(i).get(j)) == null) 
                {
                    email_to_account.put(accounts.get(i).get(j), new ArrayList<Integer>());
                }
                
                email_to_account.get(accounts.get(i).get(j)).add(i);
            }
        }
        
        List<List<String>> ans = new ArrayList<>();
        boolean[] checked = new boolean[accounts.size()];
        
        // merge accounts
        dfs(ans, checked, email_to_account, accounts);
        
        return ans;
    }
    
    private void dfs(List<List<String>> ans, boolean[] checked, Map<String, 
                List<Integer>> email_to_account, List<List<String>> accounts) {
        Stack<Integer> st = new Stack<>();
        
        // traverse all accounts
        for (int i = 0; i < accounts.size(); i++) {
            Set<String> email_set = new TreeSet<>();
            List<String> new_account = new ArrayList<>();
            
            // if this accounts is not added yet
            if (checked[i] == false) {
                checked[i] = true;
                st.push(i);
                new_account.add(accounts.get(i).get(0));
                
                // add all email for this account to email_set
                while (!st.isEmpty()) {
                    int ac = st.pop();
                    
                    for (int j = 1; j < accounts.get(ac).size(); j++) {
                        String e = accounts.get(ac).get(j);
                        email_set.add(e);
                        
                        // checked all account use this email
                        for(Integer acc : email_to_account.get(e)) {
                            if (checked[acc] == false) {
                                checked[acc] = true;
                                st.push(acc);
                            }
                        }
                    }
                }
                
                // add all emails in email_set to new_account
                for (String email : email_set) {
                    new_account.add(email);
                }
                
                // add this new account to ans
                ans.add(new_account);
            }
        }
    }
}

// Runtime: 37 ms, faster than 55.09% of Java online submissions for Accounts Merge.
// Memory Usage: 44.4 MB, less than 47.63% of Java online submissions for Accounts Merge.
// time complexity : O(n * maxE + n * maxE log maxE) which n is number of accounts, maxE is maximum emails nuber of an accountt
// space complexity: O(n * maxE ) 