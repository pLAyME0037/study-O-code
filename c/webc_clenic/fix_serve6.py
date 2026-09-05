with open('core/serve.c', 'rb') as f:
    content = f.read()

# The three double quote bytes: 0x22 0x22 0x22
# We want: " (0x22) & (0x26) q (0x71) u (0x75) o (0x6f) t (0x74) ; (0x3b) " (0x22)
# So the 3 bytes at position of """ should become 8 bytes

# Find and replace the specific pattern
# The pattern is: b'sb_append_cstr(sb, ' + b'"""' + b'); break'
# We want to replace the middle b'"""' with b'"""'

# Let's find the exact location
idx = content.find(b'sb_append_cstr(sb, """); break')
if idx >= 0:
    print(f"Found at index {idx}")
    # The three quotes start at idx + 18
    quote_start = idx + 18
    # Replace 3 bytes with 8 bytes
    before = content[:quote_start]
    after = content[quote_start+3:]
    replacement = b'"""'
    content = before + replacement + after
    print("Replaced!")
else:
    print("Not found")

with open('core/serve.c', 'wb') as f:
    f.write(content)
print("Fixed")