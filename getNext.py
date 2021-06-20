# Read in the file
with open('copy.txt', 'r') as file :
  filedata = file.read()

# Replace the target string
filedata = filedata.replace("_8_", '_9_')
filedata = filedata.replace("_7_", '_8_')
filedata = filedata.replace("_6_", '_7_')
filedata = filedata.replace("_5_", '_6_')
filedata = filedata.replace("_4_", '_5_')
filedata = filedata.replace("_3_", '_4_')
filedata = filedata.replace("_2_", '_3_')
filedata = filedata.replace("_1_", '_2_')

# Write the file out again
with open('copy.txt', 'w') as file:
  file.write(filedata)