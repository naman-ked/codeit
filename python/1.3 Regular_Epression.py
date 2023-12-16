import re
text= "This is my Phone number 123-456-7890. Call me soon"

print("phone" in text)
print("Phone" in text)

pattern = "Phone"
match = re.search(pattern,text)
print(match.span())
print(match.start())
print(match.end())

text2 = "This is my Phone number 123-456-7890. Call me on my Phone soon"
pattern2 = "Phone"
matches = re.findall(pattern2,text2)
print(matches)
print(len(matches))
for mat in re.finditer(pattern2,text2):
    print(mat.span())
    # print(mat.group())
    # print(mat.start())
    # print(mat.end())

pattern3 = r'\d\d\d-\d\d\d-\d\d\d\d';
#r allows python to understand that \ in the pattern is not an escape character
# \d = digit
# \W = non-word character
# \s = whitespace character
# \w = word character
# . = any character except new line
# + = one or more
# * = zero or more
# ? = zero or one
# {3} = exact number
# {3,4} = range of numbers (minimum, maximum)
# | = either or
# [] = range of characters
# [^] = not
# $ = end of string
# ^ = beginning of string
# \ = escape character
# () = capture group


match3 = re.search(pattern3,text2)
print(match3.group())

pattern4 = r'(\d{3})-(\d{3})-(\d{4})';
match4 = re.search(pattern4,text2)
print(match4.group())
print(match4.group(1))

pattern5 = r"study|learn" 
print(re.search(pattern5,"I want to study Python"))
print(re.search(pattern5,"I want to learn Python"))
print(re.search(pattern5,"I want to study and learn Python"))

pattern6= r"\S+at"
print(re.findall(pattern6,"The cat sat!. The rat splat on the mat."))
