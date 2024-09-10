import streamlit as st
import pandas as pd
import numpy as np
import matplotlib.pyplot as mlt
st.title('Regression Model ????')
st.write('Hello World!, this is a Multivariate Regression model under construction.Please stand by')

dataset = pd.read_csv('data.csv')
X = dataset.iloc[:, 1:-1].values
y = dataset.iloc[:, -1].values
