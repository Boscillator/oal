from oal import units

import pytest
import math
import sys
from hypothesis import given, strategies as st
import numpy as np

@given(st.floats(allow_nan=False))
def test_round_trip_radians(x):
  """Test that converting from degrees to radians and back gives the original value. NaN excluded for equality check."""
  result = units.to_degrees(units.to_radians(x))
  assert result == pytest.approx(x, rel=1e-5)

@given(st.floats(allow_nan=False))
def test_round_trip_degrees(x):
  """Test that converting from radians to degrees and back gives the original value. NaN excluded for equality check."""
  x_deg = units.to_degrees(x)

  if x > sys.float_info.max / (180 / math.pi):
    # If the routine will overflow, to_degrees should return infinity
    assert x_deg == math.inf
  elif x < -sys.float_info.max / (180 / math.pi):
    # Routine would underflow, assert -inf is returned
    assert x_deg == -math.inf
  else:
    # Otherwise, try to convert back and check result
    result = units.to_radians(x_deg)
    assert result == pytest.approx(x, rel=1e-5)
