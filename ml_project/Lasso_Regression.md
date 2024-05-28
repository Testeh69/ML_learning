
# Lasso Regression

The lasso regression also called Least Absolute Shrinkage is a regularisation version of the linear regression (L1). A term of $\alpha \sum_{i=1}^{n} |\theta_i|$ is added at the loss function.


### Math

So initially we have the loss function that is noted $J(\theta)$ that is equal to MSE or RMSE (for this example we use MSE):

$$
MSE = \frac{1}{n} \sum_{i=1}^{n} (y_i - \hat{y}_i)^2
$$

$$
J(\theta) = \frac{1}{n} \sum_{i=1}^{n} (y_i - \hat{y}_i)^2
$$
After this we just add to the loss function the $\alpha \sum_{i=1}^{n} |\theta_i|$ :


$$J(\theta) = \frac{1}{n} \sum_{i=1}^{n} (y_i - \hat{y}_i)^2 + \alpha \sum_{i=1}^{n} |\theta_i| $$

**For the solution of the gradient descent, we derivate, the function loss:**

for this equation $\hat{y}_i =\theta_1x_1 +\theta_0$

$$
∇_J(\theta) = [∂(MSE + L1)/∂\theta₀, ∂(MSE+ L1)/∂\theta₁]
$$

so for:

$$
∂(MSE + aw^2)/∂\theta₀ = -\frac{2}{n}\sum_{i=1}^{n}(y_i - (\theta_1x_1 + \theta_0)) + \alpha.sgn(\theta_0)
$$

$$
∂(MSE + aw^2)/∂\theta_1 = -\frac{2}{n}\sum_{i=1}^{n} (x_1).(y_i - (\theta_1x_1 + \theta_0)) + \alpha.sgn(\theta_1)
$$



[[Definitions Maths]] : #sgn

We update the parameter of the model using gradient descent (the formula below is for one parameter):

$$θ_1​=θ_1​−η⋅​∂J(θ)​/∂θ_1$$



### Code


```Python 
from sklearn.linear_model import Lasso


model = Lasso(alpha = 0.1)
model.fit(X,y)
predictions = model.predict(X)
```




Link: [[Ridge Regression]] , [[Linear regression]], [[Gradient Descent]]



reference: Machine Learning avec scikit-learn
