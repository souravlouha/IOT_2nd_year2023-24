import pandas as pd
df=pd.read_csv('data.csv')
df.head(5)

x=df.iloc[:,1:3].values
x

y=df.iloc[:,3].values
y

df

x

y

import matplotlib.pyplot as plt
plt.scatter(x[y==0,0],x[y==0,1],c='red', s=50,label="no pump")
plt.scatter(x[y==1,0],x[y==1,1],c='blue', s=50,label="pump")
plt.xlabel("Moisture")
plt.ylabel("Temperature")
plt.title("Irrigation data")
plt.show()

from sklearn.model_selection import train_test_split
x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=.2,
                                               random_state=0)

x_train.shape

x_test.shape

from sklearn.neighbors import KNeighborsClassifier
knn_model=KNeighborsClassifier()
knn_model.fit(x_train,y_train)

x_test

y_pred=knn_model.predict(x_test)

y_pred

y_test

from sklearn.metrics import accuracy_score
accuracy_score(y_test,y_pred)

knn_model.predict([[419,17]])

knn_model.predict([[537,44]])

from sklearn.svm import SVC
svc_model=SVC()
svc_model.fit(x_train,y_train)
y_pred=svc_model.predict(x_test)
print("Accuracy=",accuracy_score(y_test,y_pred))

from sklearn.naive_bayes import GaussianNB
nb_model=GaussianNB()
nb_model.fit(x_train,y_train)
y_pred=nb_model.predict(x_test)
print("Accuracy=",accuracy_score(y_test,y_pred))