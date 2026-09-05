with open('core/serve.c', 'rb') as f:
    content = f.read()

# The exact bytes to find: sb_append_cstr(sb, """); break
# The three double quotes are at offset 18-20 in this substring
# We want to replace the three bytes 0x22 0x22 0x22 with the 8 bytes for """

old_bytes = b'sb_append_cstr(sb, """); break'
new_bytes = b'sb_append_cstr(sb, """); break'

content = content.replace(old_bytes, new_bytes)

with open('core/serve.c', 'wb') as f:
    f.write(content)
print("Fixed")