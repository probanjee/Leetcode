class Solution {
    public String reverseWords(String s) {

        Stack<String> stack = new Stack<>();
        String[] words = s.trim().split("\\s+");
        StringBuilder sb = new StringBuilder();

        for (String word : words) {
            stack.push(word);
        }

        while (!stack.isEmpty()) {
            sb.append(stack.pop());
            sb.append(" ");
        }

        return sb.toString().trim();
    }
}