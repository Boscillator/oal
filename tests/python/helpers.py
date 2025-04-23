from hypothesis import strategies as st

def sample_from_enum(enum):
  values = [v[0] for v in enum.__entries.values()]
  return st.sampled_from(values)
