class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if token == "+":
                b = stack.pop()
                a = stack.pop()
                c = a + b
                stack.append(c)
            elif token == "-":
                b = stack.pop()
                a = stack.pop()
                c = a - b
                stack.append(c)
            elif token == "/":
                b = stack.pop()
                a = stack.pop()
                c = int(a / b)
                stack.append(c)
            elif token == "*":
                b = stack.pop()
                a = stack.pop()
                c = a * b
                stack.append(c)
            else:
                try:
                    stack.append(int(token))
                except ValueError:
                    # Handle invalid input
                    return None
        if len(stack) != 1:
            # Handle invalid RPN expression
            return None
        return stack.pop()