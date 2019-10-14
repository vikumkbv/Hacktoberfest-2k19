import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns

a = pd.read_csv("titanic_data.csv")
a.head()

def impute_age(cols):
   Age = cols[0]
   Pclass = cols[1]
   if pd.isnull(Age):
       if Pclass == 1:
           return 37
       elif Pclass == 2:
           return 29
       else:
           return 24
   else:
       return Age

a['Age'] = a[['Age', 'Pclass']].apply(impute_age, axis = 1)

def impute_cabin(col):
   Cabin = col[0]
   if type(Cabin) == str:
       return 1
   else:
       return 0

a['Cabin'] = a[['Cabin']].apply(impute_cabin, axis = 1)


dataset = a

sex = pd.get_dummies(dataset['Sex'],drop_first=True)
embark = pd.get_dummies(dataset['Embarked'],drop_first=True)
dataset.drop(['Sex','Embarked','Name','Ticket'],axis=1,inplace=True)
dataset = pd.concat([dataset,sex,embark],axis=1)


from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score
X_train, X_test, y_train, y_test = train_test_split(dataset.drop('Survived',axis=1),dataset['Survived'], test_size=0.2,random_state=45)

regressor = LogisticRegression()
regressor.fit(X_train, y_train)
pred = regressor.predict(X_test)

print(accuracy_score(y_test, pred))

