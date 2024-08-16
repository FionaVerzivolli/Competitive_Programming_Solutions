import pandas as pd

def dropDuplicateEmails(customers: pd.DataFrame) -> pd.DataFrame:
    new = customers.drop_duplicates('email')
    return new
