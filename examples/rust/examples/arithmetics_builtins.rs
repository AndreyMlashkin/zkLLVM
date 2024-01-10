#![no_main]

// In this example built-in field type is used.
type PallasBase = __zkllvm_field_pallas_base;

fn pow_2(a: PallasBase) -> PallasBase {
    (0..2).fold(1g, |acc, _| acc * a)
}

#[circuit]
pub fn field_arithmetic_example(a: PallasBase, b: PallasBase) -> PallasBase {
    let c = (a + b) * a + b * (a + b) * (a + b);
    const CONSTANT: PallasBase = 0x12345678901234567890g;
    c * c * c / (b - a) + pow_2(a) + CONSTANT
}
