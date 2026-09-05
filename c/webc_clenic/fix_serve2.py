with open('core/serve.c', 'r') as f:
    content = f.read()

# The file has: sb_append_cstr(sb, """);  -- three double quotes
# We need:    sb_append_cstr(sb, """);  -- HTML entity

# Use chr(34) for double quote to avoid escaping issues
old = 'sb_append_cstr(sb, ' + chr(34)*3 + ');'
new = 'sb_append_cstr(sb, ' + chr(34) + '"' + chr(34) + ');'

content = content.replace(old, new)

with open('core/serve.c', 'w') as f:
    f.write(content)
print("Fixed")