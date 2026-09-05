with open('core/serve.c', 'r') as f:
    content = f.read()

# The exact string in the file: 'case '"':  sb_append_cstr(sb, """); break;'
# We need to replace the three double quotes with """

# In the file, the bytes are: sb_append_cstr(sb, """);  (three double quotes)
# We want: sb_append_cstr(sb, """);  (double quote, ", double quote)

old = 'case \'"\':  sb_append_cstr(sb, """); break;'
new = 'case \'"\':  sb_append_cstr(sb, """); break;'

content = content.replace(old, new)

with open('core/serve.c', 'w') as f:
    f.write(content)
print("Fixed")