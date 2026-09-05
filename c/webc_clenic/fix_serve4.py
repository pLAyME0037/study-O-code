with open('core/serve.c', 'rb') as f:
    content = f.read()

# The file has three double quote bytes (0x22 0x22 0x22) in the string
# We want to replace with: 0x22 0x26 0x71 0x75 0x6F 0x74 0x3B 0x22
# which is the bytes for """

old = b'sb_append_cstr(sb, """);'
new = b'sb_append_cstr(sb, """);'

content = content.replace(old, new)

with open('core/serve.c', 'wb') as f:
    f.write(content)
print("Fixed")