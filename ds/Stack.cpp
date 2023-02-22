//Evaluate postfix
int evaluatePostfix(string S)
{
    // Your code here
    stack<int> numbers;
    int result = 0;
    for (int i = 0; i < s.length(); i++) {
        int x, y;
        if (s[i] == '*') {
            x = numbers.top();
            numbers.pop();
            y = numbers.top();
            numbers.pop();
            numbers.push(x*y);
        }
        else if (s[i] == '/') {
            x = numbers.top();
            numbers.pop();
            y = numbers.top();
            numbers.pop();
            numbers.push(x/y);
        }
        else if (s[i] == '+') {
            x = numbers.top();
            numbers.pop();
            y = numbers.top();
            numbers.pop();
            numbers.push(x+y);
        }
        else if (s[i] == '-') {
            x = numbers.top();
            numbers.pop();
            y = numbers.top();
            numbers.pop();
            numbers.push(x-y);
        }
        else {
            numbers.push(s[i]='0');
        }
    }
    return numbers.top();
}
