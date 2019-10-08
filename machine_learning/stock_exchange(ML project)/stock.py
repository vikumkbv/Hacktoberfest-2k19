import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.ensemble import GradientBoostingRegressor
import matplotlib.pyplot as plt

df = pd.read_csv('tesla10.csv')
rows = df.values.tolist()

x_train = []
y_train = []
x_test = []
y_test = []
X = []
Y = []
for row in rows:
    X.append(int(''.join(row[0].split('/'))))
    Y.append(row[3])
x_train, x_test, y_train, y_test = train_test_split(X,Y,train_size=0.9,test_size=0.1)

x_train = np.array(x_train)
y_train = np.array(y_train)
x_test = np.array(x_test)
y_test = np.array(y_test)

x_train = x_train.reshape(-1,1)
x_test = x_test.reshape(-1,1)

model = GradientBoostingRegressor(n_estimators=100000)
model.fit(x_train,y_train)
predict = model.predict(x_test)

f,(ax1,ax2) = plt.subplots(1,2,figsize=(30,10))
ax1.scatter(range(len(y_test)),y_test,label='data')
ax1.plot(range(len(y_test)),predict,color='red',label='GB model')
ax1.legend()
plt.savefig('stock.png')
