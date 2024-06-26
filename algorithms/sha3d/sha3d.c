#include "sha3d.h"

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "../flex/utils/sph_keccak.h"

void sha3d_hash(const char* input, char* output, uint32_t len)
{
	uint32_t buffer[16], hash[16];
	sph_keccak_context ctx_keccak;

	sph_keccak256_init( &ctx_keccak );
	sph_keccak256 ( &ctx_keccak, input, len );
	sph_keccak256_close( &ctx_keccak, (void*) buffer );

	sph_keccak256_init( &ctx_keccak );
	sph_keccak256 ( &ctx_keccak, buffer, 32 );
	sph_keccak256_close( &ctx_keccak, (void*) hash );

	memcpy(output, hash, 32);
}
