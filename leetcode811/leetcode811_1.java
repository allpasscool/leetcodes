class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> counts = new HashMap();
        for (String domain: cpdomains) {
            String[] cpinfo = domain.split(" ");
            String[] frags = cpinfo[1].split("[.]");
            int count = Integer.valueOf(cpinfo[0]);
            String cur = "";
            for (int i = frags.length - 1; i >= 0; --i) {
                cur = frags[i] + (i < frags.length - 1 ? "." : "") + cur;
                counts.put(cur, counts.getOrDefault(cur, 0) + count);
            }
        }

        List<String> ans = new ArrayList();
        for (String dom: counts.keySet())
            ans.add("" + counts.get(dom) + " " + dom);
        return ans;
    }
}

// Runtime: 34 ms, faster than 19.64% of Java online submissions for Subdomain Visit Count.
// Memory Usage: 39.9 MB, less than 73.35% of Java online submissions for Subdomain Visit Count.
// time complexity: O(n)
// space complexity: O(n)