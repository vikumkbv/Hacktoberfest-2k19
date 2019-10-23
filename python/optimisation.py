# -*- coding: utf-8 -*-
"""
Created on 22/10/19

@author: Angeliki.Loukatou

# This script sets up and solves a simple linear problem.

"""

# load the libraries
import numpy as np
from scipy.optimize import linprog

# coefficients of the objective function
c = np.array(np.mat('-1 -0.6667'))

# set coefficients for the inequality constraints of the problem
A_ub = np.array(np.mat('1 1; 1 0.25; 1 -1; -0.25 -1; -1 -1; -1 1'))
b_ub = np.array(np.mat('2; 1; 2; 1; -1; 2'))

# set coefficients for the equality constraints
A_eq = np.array(np.mat('1 0.25'))
b_eq = np.array(np.mat('0.5'))

# set lower and upper bounds
bounds_x0 = (-1, 1.5)
bounds_x1 = (-0.5, 1.25)

# run the solver and get back the optimal vector
res = linprog(c, A_ub, b_ub, A_eq, b_eq, bounds=[bounds_x0, bounds_x1], method='simplex')

# print the optimal solution
print(res)


