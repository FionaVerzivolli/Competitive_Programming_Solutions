import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> List[int]:
    a = players.shape
    return [a[0],a[1]]     
