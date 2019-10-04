import tensorflow as tf
from tensorflow import keras
import pandas as pd

model = keras.Sequential()
input_layer = keras.layers.Dense(3, input_shape=[3], activation='tanh')
model.add(input_layer)

output_layer = keras.layers.Dense(1, activation='sigmoid')
model.add(output_layer)

gd = tf.train.GradientDescentOptimizer(0.01)

model.compile(optimizer=gd,loss='mean_squared_error')

# Data input
x = tf.Variable([[1,1,0],[1,1,1],[0,1,0],[-1,1,0],[-1,0,0],[-1,0,1],[0,0,1],[1,1,0],[1,0,0],[-1,0,0],[1,0,1],[0,1,1],[0,0,0],[-1,1,1]])
y = tf.Variable([[0],[0],[1],[1],[1],[0],[1],[0],[1],[1],[1],[1],[1],[0]])

# testing data set
test = tf.Variable([[1,0,0]])

init=tf.global_variables_initializer()
with tf.Session() as sess:
    sess.run(init)
    model.fit(x, y, epochs=2000, steps_per_epoch=10)
    model.save_weights('model_weights.h5')
    results = model.predict(test, verbose=0, steps=1)
    print(results)
