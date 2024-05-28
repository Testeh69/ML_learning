# Linear Regression


source: https://haltode.fr/algo/ia/apprentissage_artificiel/regression_lin_poly/equation_normale.html


### Math

A linear regression is an affine function under the form:

$\hat{y} = a1*x1 + a2*x2 + a3*x3 + .... + a0 = X \cdot \theta$  

	avec y : output estimé du modèle
		 xN: paramètre d'entrée 
		 aN: paramètre du modèle (qu'il faudra ajuster)
		 

To adjust the parameters of the model, we use the loss function such as #RMSE , #MSE.

$$ RMSE = \sqrt{\frac{1}{n} \sum_{i=1}^{n} (y_i - \hat{y}_i)^2} $$



$$MSE = \frac{1}{n} \sum_{i=1}^{n} (y_i - \hat{y}_i)^2$$


Where :
- $n$ is the number of observation
- $y_i$ is the real value
- $\hat{y}_i$ is the estimation value by the model



### Analytic Resolution

We can find the parametrer optimal by using the normal equation. The **normal equation** is an algrebric method that permit us to find the optimal value of the parameter of the linear regression model. To a model of linear regression (one features), the normal equation is exprimed by the following equation.

$\theta = (X^T X)^{-1} X^T y$ 

Where :
- X is a matrice colonne composed of n parameters with n an int


#linear_regression_code


```python
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error

lin_model = LinearReagression()
lin_model.fit(X_train,y_train)
predict = lin_model.predict(X_test)
rmse = np.sqrt(mean_squared_error(y_test,predict))

```

### Use of Linear Regression or Regularisation

Ridge regression is a good default choice when you have a large number of features and you believe that most of them are relevant for predicting the target variable. It penalizes the sum of squared coefficients, leading to smaller but non-zero coefficients for less important features.

On the other hand, Lasso regression tends to produce sparse coefficients by driving some coefficients to exactly zero, effectively performing feature selection. This can be useful when you suspect that many of your features are irrelevant or redundant.

ElasticNet regularization combines both L1 and L2 penalties, striking a balance between Ridge and Lasso. It offers the flexibility of Lasso in selecting features while also benefiting from the stabilizing effects of Ridge.

If you believe that your dataset contains both useful and irrelevant features, ElasticNet regularization could be a suitable choice. It allows you to control the mix of L1 and L2 penalties using a hyperparameter called `l1_ratio`. A `l1_ratio` of 1 corresponds to pure Lasso, while a `l1_ratio` of 0 corresponds to pure Ridge.

Here's how you can use ElasticNet regularization in scikit-learn:
```python
from sklearn.linear_model import ElasticNet 
model = ElasticNet(alpha=0.1, l1_ratio=0.5)  
model.fit(X, y)
predictions = model.predict(X)
```

You can adjust the `alpha` and `l1_ratio` parameters based on your specific dataset and problem. Increasing `alpha` increases the strength of regularization, while adjusting `l1_ratio` allows you to control the mix of Lasso and Ridge regularization.

Link: [[Ridge Regression]], [[Least Absolute Shrinkage]], [[Gradient Descent]]


reference: Machine Learning avec scikit-learn
