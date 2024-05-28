# Ridge Regression

The ridge regression also called Tikhonov regularisation is a regularisation version of the linear regression (l2). A term of $\alpha \sum_{i=1}^{n} \theta_i^2$ is added at the loss function.

### Math

So initially we have the loss function that is noted $J(\theta)$ that is equal to MSE or RMSE (for this example we use MSE):

$$
MSE = \frac{1}{n} \sum_{i=1}^{n} (y_i - \hat{y}_i)^2
$$

$$
J(\theta) = \frac{1}{n} \sum_{i=1}^{n} (y_i - \hat{y}_i)^2
$$

After this we just add to the loss function the $\alpha \sum_{i=1}^{n} \theta_i^2$ :

> we can also add a $\frac{1}{2}$ in front the equation so that when we derivate the equation, the equation is simpler. 

$$J(\theta) = \frac{1}{n} \sum_{i=1}^{n} (y_i - \hat{y}_i)^2 + \alpha \sum_{i=1}^{n} \theta_i^2 $$

then we can just replace the $\sum_{i=1}^{n} \theta_i$ by a ponderation vector **w**, so we obtain the following equation.


$$
J(\theta) = \frac{1}{n} \sum_{i=1}^{n} (y_i - \hat{y}_i)^2 + \alpha w^2 
$$

**For the solution of the gradient descent, we derivate, the function loss:**

for this equation $\hat{y}_i =\theta_1x_1 +\theta_0$

$$
∇_J(\theta) = [∂(MSE + aw^2)/∂\theta₀, ∂(MSE+ aw^2)/∂\theta₁]
$$

so for:

$$
∂(MSE + aw^2)/∂\theta₀ = -\frac{2}{n}\sum_{i=1}^{n}(y_i - (\theta_1x_1 + \theta_0)) + 2a\theta_0
$$
$$
∂(MSE + aw^2)/∂\theta_1 = -\frac{2}{n}\sum_{i=1}^{n} (x_1)(y_i - (\theta_1x_1 + \theta_0)) + 2a\theta_1
$$

We update the parameter of the model using gradient descent (the formula below is for one parameter):

$$θ_1​=θ_1​−η⋅​∂J(θ)​/∂θ_1$$

**But we can also adjust the solution by analytic**

$$
\hat{\theta}_n = (X^T X + aA)^{-1} X^T y 
$$
#### Code


```python
from sklearn.linear_model import Ridge.

alpha = 1.0
ridge = Ridge(alpha=alpha) 
ridge.fit(X_train, y_train) # Make predictions
```

> [!NOTE]
> We just want the regularisation during the training stage and not during the test stage.
> We need to normalized our data, because this model is very sensible about the difference in scale between data.
> 

Link: [[Linear regression]], [[Least Absolute Shrinkage]], [[Gradient Descent]]


reference: Machine Learning avec scikit-**learn**
