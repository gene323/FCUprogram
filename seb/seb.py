#!/usr/bin/python3

import gzip
import zlib
import rncryptor

class RNCryptor_modified(rncryptor.RNCryptor):
    def post_decrypt_data(self, data):
        data = data[:-(data[-1])]
        return data

def decrypt_SEB(password):
    cryptor = RNCryptor_modified()

    # change to your seb filename
    with gzip.open('test.seb', 'rb') as f:
        file_content = f.read()

    decrypted_data = cryptor.decrypt(file_content[4:], password)
    decompressed_data = zlib.decompress(decrypted_data,15 + 32)

    with open("result.deb", "wb") as f:
        f.write(decompressed_data)

# input password
decrypt_SEB("level3")
