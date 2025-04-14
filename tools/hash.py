import hashlib

# Input values
username = "admin"
password = "admin"
realm = "MyApp"

# Create the input string
input_string = f"{username}:{realm}:{password}"

# Compute MD5 hash
md5_hash = hashlib.md5(input_string.encode()).hexdigest()

print(md5_hash)

# Used to generate the hash for the given input
# https://github.com/ESP32Async/ESPAsyncWebServer/blob/main/examples/Auth/Auth.ino