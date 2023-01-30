import pandas as pd
import matplotlib.pyplot as plt

file_path = "tses.csv"
data = pd.read_csv(file_path, sep = " ", header=0)


print(data.iloc[0])
initial_start = data.iloc[0]['start']
initial_end = data.iloc[0]['end']
initial_pc = data.iloc[0]['pc']
data = data.drop(data.index[[0]])
print(data)


data["pc"] = data["pc"] - initial_pc
data["start"] = data["start"] - initial_start
data["end"] = data["end"] - initial_start



print(data)
diffs = data["pc"] - data["start"]
print(diffs.min(0))
diffs = diffs + abs(diffs.min(0))
# print(data["pc"] - data["start"])
#     pc_synchronized_ts = row['PC_TS'] - synchro[0]


    
    
#     camera_ts = row["C_TS"] - synchro[1]
#     diff = pc_synchronized_ts - camera_ts
#     # print(pc_synchronized_ts - camera_ts )
#     # print(pc_synchronized_ts - camera_tses)
#     # diff = pc_synchronized_ts - camera_ts
#     differences.append(diff)
#     camera_tses.append(camera_ts)
#     # print(pc_synchronized_ts, camera_ts, diff)
#     # differences.append(diff)

#     # print(pc_synchronized_ts, row['C_TS'], pc_synchronized_ts - row['C_TS'])
#     # print(pc_synchronized_ts - (row['C_TS']*1000))

plt.plot(data["pc"], diffs)

plt.show()