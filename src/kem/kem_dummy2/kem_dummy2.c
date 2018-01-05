#include <stdlib.h>

#include <oqs/kem_dummy2.h>

#ifdef OQS_ENABLE_KEM_dummy2

#include "upstream/api.h"

OQS_KEM *OQS_KEM_dummy2_new() {

	OQS_KEM *kem = malloc(sizeof(OQS_KEM));
	if (kem == NULL) {
		return NULL;
	}
	kem->method_name = CRYPTO_ALGNAME;

	kem->claimed_nist_level = 0;
	kem->ind_cca = false;

	kem->length_public_key = OQS_KEM_dummy2_length_public_key;
	kem->length_secret_key = OQS_KEM_dummy2_length_secret_key;
	kem->length_ciphertext = OQS_KEM_dummy2_length_ciphertext;
	kem->length_shared_secret = OQS_KEM_dummy2_length_shared_secret;

	kem->keypair = OQS_KEM_dummy2_keypair;
	kem->encaps = OQS_KEM_dummy2_encaps;
	kem->decaps = OQS_KEM_dummy2_decaps;

	return kem;

}

#endif
