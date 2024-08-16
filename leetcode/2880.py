import pandas as pd

def selectData(students: pd.DataFrame) -> pd.DataFrame:
    student_name = students[students["student_id"] == 101]
    return student_name[["name", "age"]].head()
