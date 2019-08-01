import hashlib
import helpers
import os
import os.path
import pytest

@pytest.mark.parametrize('program', ['example_kem', 'example_sig', 'test_aes', 'test_sha3'])
def test_program(program):
    helpers.run_subprocess(
        [os.path.join('tests', program)],
    )

@pytest.mark.parametrize('kem_name', helpers.available_kems_by_name())
def test_kem(kem_name):
    if not(helpers.is_kem_enabled_by_name(kem_name)): pytest.skip('Not enabled')
    helpers.run_subprocess(
        [os.path.join('tests', 'test_kem'), kem_name],
    )

@pytest.mark.parametrize('sig_name', helpers.available_sigs_by_name())
def test_sig(sig_name):
    if not(helpers.is_sig_enabled_by_name(sig_name)): pytest.skip('Not enabled')
    helpers.run_subprocess(
        [os.path.join('tests', 'test_sig'), sig_name],
    )

if __name__ == "__main__":
    import sys
    pytest.main(sys.argv)

