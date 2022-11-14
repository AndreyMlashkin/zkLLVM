
namespace nil{
    namespace crypto3{
        namespace algebra {
            struct bls12381{
                typedef field_bls12381b value_type;
            };
        }

        namespace hashes {
            __attribute__((ext_vector_type(3))) field_bls12381b poseidon(__attribute__((ext_vector_type(3))) field_bls12381b input_block);
        }
    }
}

using nil::crypto3;

__attribute__((ext_vector_type(3))) typename algebra::bls12381::value_type poseidon_example1(
    typename algebra::bls12381::value_type a,
    typename algebra::bls12381::value_type b,
    typename algebra::bls12381::value_type c) {

    __attribute__((ext_vector_type(3))) typename algebra::bls12381::value_type input_block =
        {a + b, b+c, a*c};

    __attribute__((ext_vector_type(3))) typename algebra::bls12381::value_type hash_result =
        hashes::poseidon(input_block);

    return hash_result;
}