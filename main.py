#!/usr/bin/env python3
import time
import base64
import requests
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.hashes import BLAKE2b
from cryptography.hazmat.primitives.asymmetric.ed25519 import (
    Ed25519PrivateKey, Ed25519PublicKey
)

# ─────────────────────────────────────────────────────────────────────────────
# 1. Embedded BAP Credentials, Endpoint & Payload
# ─────────────────────────────────────────────────────────────────────────────
# Change this to your ngrok endpoint for real testing
BAP_URL = "https://43d3-27-59-34-106.ngrok-free.app/search"

# Base64-encoded 64-byte ed25519 keypair
BAP_PRIVATE_KEY_B64 = (
    "YMtO/vQsnPA7tZkSIiymGy47dqOg1kV1aWuKkxFob7EC026y8bHWrmzAcR8KLPQGfOxoF2hFXmBVMkaUMcmSpg=="
)
BAP_PUBLIC_KEY_B64 = (
    "AtNusvGx1q5swHEfCiz0BnzsaBdoRV5gVTJGlDHJkqY="
)
BAP_UNIQUE_KEY_ID = "a14b3231-3037-4c2e-96fa-4fa1722e0009"

# Inline Beckn search_request JSON payload
RAW_BODY = '''{
  "context": {
    "domain": "ONDC:RET11",
    "country": "IND",
    "city": "std:080",
    "action": "search",
    "core_version": "1.2.0",
    "bap_id": "ootadelivery.in",
    "bap_uri": "https://43d3-27-59-34-106.ngrok-free.app/protocol/v1",
    "transaction_id": "5a497990-0d4d-4c3f-9b69-43638195b50c",
    "message_id": "9c35874b-505f-44c9-849d-59f7fb5aa89e",
    "timestamp": "2024-01-24T10:00:00.000Z"
  },
  "message": {
    "intent": {
      "item": { "descriptor": { "name": "biryani" } },
      "fulfillment": { "type": "Delivery" },
      "payment": {
        "@ondc/org/buyer_app_finder_fee_type": "Percentage",
        "@ondc/org/buyer_app_finder_fee_amount": "3"
      }
    }
  }
}'''.encode()

# ─────────────────────────────────────────────────────────────────────────────
# 2. Deserialize ed25519 keys and validate locally
# ─────────────────────────────────────────────────────────────────────────────
key_bytes = base64.b64decode(BAP_PRIVATE_KEY_B64)
if len(key_bytes) == 64:
    priv_seed = key_bytes[:32]
else:
    raise ValueError(f"Unexpected private key length: {len(key_bytes)} bytes")
priv_key = Ed25519PrivateKey.from_private_bytes(priv_seed)
pub_key  = Ed25519PublicKey.from_public_bytes(
    base64.b64decode(BAP_PUBLIC_KEY_B64)
)

# Quick sign-and-verify test
def validate_keypair():
    msg = b"hello beckn"
    sig = priv_key.sign(msg)
    try:
        pub_key.verify(sig, msg)
        print("✔ ed25519 keypair is VALID")
    except Exception as e:
        print("✘ keypair mismatch!", e)
        exit(1)

validate_keypair()

# ─────────────────────────────────────────────────────────────────────────────
# 3. Compute BLAKE2b-512 digest of the body
# ─────────────────────────────────────────────────────────────────────────────
blake2b = hashes.Hash(BLAKE2b(64))
blake2b.update(RAW_BODY)
digest_b64 = base64.b64encode(blake2b.finalize()).decode()

# ─────────────────────────────────────────────────────────────────────────────
# 4. Create HTTP Signature header
# ─────────────────────────────────────────────────────────────────────────────
created = int(time.time())
expires = created + 60
signing_string = (
    f"(created): {created}\n"
    f"(expires): {expires}\n"
    f"digest: BLAKE-512={digest_b64}"
).encode()

sig = priv_key.sign(signing_string)
sig_b64 = base64.b64encode(sig).decode()
# Use ngrok host in keyId for production
keyId = f"{BAP_URL.split('//')[-1]}|{BAP_UNIQUE_KEY_ID}|ed25519"
auth_header = (
    f'Signature keyId="{keyId}",'
    f'algorithm="ed25519",'
    f'created="{created}",'
    f'expires="{expires}",'
    f'headers="(created) (expires) digest",'
    f'signature="{sig_b64}"'
)
print("\n→ Authorization header:")
print(auth_header)

# ─────────────────────────────────────────────────────────────────────────────
# 5. Send the search POST
# ─────────────────────────────────────────────────────────────────────────────
print(f"\n→ POST {BAP_URL}")
resp = requests.post(
    BAP_URL,
    data=RAW_BODY,
    headers={
        "Content-Type": "application/json",
        "Authorization": auth_header
    },
    # If your ngrok endpoint is HTTPS without mTLS, omit cert; use verify=False only if self-signed
    verify=False
)
print(f"← HTTP {resp.status_code} {resp.reason}")
print(resp.text)
