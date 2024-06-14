{
    "targets": [
        {
            "target_name": "hashing",
            "sources": [
                "hashing.cc",
                "algorithms/flex/flex.c",
                "algorithms/flex/utils/aes_helper.c",
                "algorithms/flex/utils/extra.c",
                "algorithms/flex/utils/gost_streebog.c",
                "algorithms/flex/utils/lyra2.c",
                "algorithms/flex/utils/sph_blake.c",
                "algorithms/flex/utils/sph_bmw.c",
                "algorithms/flex/utils/sph_cubehash.c",
                "algorithms/flex/utils/sph_echo.c",
                "algorithms/flex/utils/sph_fugue.c",
                "algorithms/flex/utils/sph_groestl.c",
                "algorithms/flex/utils/sph_hamsi.c",
                "algorithms/flex/utils/sph_haval.c",
                "algorithms/flex/utils/sph_jh.c",
                "algorithms/flex/utils/sph_keccak.c",
                "algorithms/flex/utils/sph_luffa.c",
                "algorithms/flex/utils/sph_shabal.c",
                "algorithms/flex/utils/sph_shavite.c",
                "algorithms/flex/utils/sph_simd.c",
                "algorithms/flex/utils/sph_skein.c",
                "algorithms/flex/utils/sph_tiger.c",
                "algorithms/flex/utils/sph_whirlpool.c",
                "algorithms/flex/utils/sponge.c",
                "algorithms/flex/utils/cryptonote/cryptonight_dark_lite.c",
                "algorithms/flex/utils/cryptonote/cryptonight_dark.c",
                "algorithms/flex/utils/cryptonote/cryptonight_fast.c",
                "algorithms/flex/utils/cryptonote/cryptonight_lite.c",
                "algorithms/flex/utils/cryptonote/cryptonight_soft_shell.c",
                "algorithms/flex/utils/cryptonote/cryptonight_turtle_lite.c",
                "algorithms/flex/utils/cryptonote/cryptonight_turtle.c",
                "algorithms/flex/utils/cryptonote/cryptonight.c",
                "algorithms/flex/utils/crypto/aesb.c",
                "algorithms/flex/utils/crypto/c_blake256.c",
                "algorithms/flex/utils/crypto/c_groestl.c",
                "algorithms/flex/utils/crypto/c_jh.c",
                "algorithms/flex/utils/crypto/c_keccak.c",
                "algorithms/flex/utils/crypto/c_skein.c",
                "algorithms/flex/utils/crypto/hash.c",
                "algorithms/flex/utils/crypto/oaes_lib.c",
                "algorithms/sha3d/sha3d.c",
                "algorithms/sha256d/sha256d.c",
                "algorithms/sha256d/utils/sph_sha2.c",
            ],
            "include_dirs": [
                ".",
                "<!(node -e \"require('nan')\")",
            ],
            "cflags_cc": [
                "-std=c++0x",
                "-fPIC",
                "-fexceptions"
            ],
            "defines": [
                "HAVE_DECL_STRNLEN=1",
                "HAVE_BYTESWAP_H=1"
            ],
            "link_settings": {
                "libraries": [
                    "-Wl,-rpath,./build/Release/",
                ]
            },
            'conditions': [
                ['OS=="mac"', {
                    'xcode_settings': {
                        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES'
                    }
                }]
            ]
        }
    ]
}
