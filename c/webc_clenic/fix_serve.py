with open('core/serve.c', 'r') as f:
    content = f.read()

# Fix the double quote case - the file has three double quotes which is invalid C
old = 'sb_append_cstr(sb, """);'
new = 'sb_append_cstr(sb, """);'

content = content.replace(old, new)

with open('core/serve.c', 'w') as f:
    f.write(content)
print("Fixed")