class Solution:
    def calculate(self, s: str) -> int:
        st = []

        ans = 0
        num = 0
        sign = 1

        for ch in s:

            if ch.isdigit():
                num = num * 10 + int(ch)

            elif ch == '+':
                ans += sign * num
                num = 0
                sign = 1

            elif ch == '-':
                ans += sign * num
                num = 0
                sign = -1

            elif ch == '(':
                st.append(ans)
                st.append(sign)

                ans = 0
                sign = 1

            elif ch == ')':
                ans += sign * num
                num = 0

                prevSign = st.pop()
                prevAns = st.pop()

                ans = prevAns + prevSign * ans

        ans += sign * num

        return ans