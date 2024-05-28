
# Gradient Descent

Gradient Descent (GD) is a machine learning algorithm that works by progressively changing the model parameters in the direction of the steepest gradient of the loss function.

There exist multiple versions of Gradient Descent, such as **Stochastic Gradient Descent**, **Mini-Batch Gradient Descent**, and **Batch Gradient Descent**.

The normal gradient descent algorithm (Batch Gradient Descent) tends to move slowly towards the global minimum of the function but can have trouble escaping local minima.

On the other hand, Stochastic and Mini-Batch Gradient Descent algorithms are better at escaping local minima but tend to approximate the global minimum rather than finding it exactly.

### Definitions:

**Mini-Batch Gradient Descent**:

- This method updates the model parameters using a small, randomly selected subset of the training data (a mini-batch) at each iteration. This approach balances the trade-off between the noisy updates of Stochastic Gradient Descent and the stability of Batch Gradient Descent.

**Stochastic Gradient Descent (SGD)**:

- This method updates the model parameters using only one training example at a time. By employing mini-batches or random subsets of the training data in each iteration, it introduces a degree of randomness. This randomness can help the algorithm escape local minima.

---

# Mathématique

Soit une fonction #loss ([[Vocabulaire]]) $J(θ)$ (pour cette exemple la fonction loss est la fonction hinge loss) qui permet d'estimer la différence entre  le résultat trouvé par une fonction $hθ​(xi​)$ et le résultat véritable.

$$
J(θ)=max(0,1−y_i​f(x_i​))
$$


On fait le gradient de la fonction loss en fonction des poids de la fonction $hθ​(xi​)$. Puis on cherche à trouver le minimum de la fonction loss, ce qui veut dire que le gradient doit etre le plus négatif possible.

#Cas 1: $1−𝑦_𝑖(𝜃^𝑇𝑥_𝑖)≤0$

$$∇J(θ)=0$$

#Cas 2: $1−𝑦_𝑖(𝜃^𝑇𝑥_𝑖)>0$


$$∇J(θ)=−y_i​x_i$$​
For one parameter:


$$θ_1​:=θ_1​−η⋅​∂J_i​(θ)​/∂θ_1$$




$η$ est le taux d'apprentissage 

---

Parameters:
Learning Rate (𝜂): Controls the step size of each update.
Batch Size: Number of training examples used in each iteration.
Convergence Criteria: Conditions for stopping the training process.
Regularization (L1, L2): Techniques to prevent overfitting.
Loss Function: Function that measures the error.
Momentum: Helps accelerate SGD in the relevant direction and dampens oscillations.
Early Stopping: Stops training when the performance on a validation set stops improving.

Advantages:
Efficient with Large Data: Handles large datasets effectively.
Online Learning: Can adapt to new data incrementally.
Rapid Convergence: Often converges faster than Batch Gradient Descent.
Regularization Support: Supports L1 and L2 regularization.

Disadvantages:
Stochastic Nature: Introduces randomness, which can lead to noisy updates.
Tuning Learning Rate: Requires careful tuning for optimal performance.
Sensitivity to Feature Scaling: Features need to be scaled properly.
Limited Modeling Capabilities: Primarily suited for linear models.
---

#SGD_Codes:

**Classifier**

```python
from sklearn.linear_model import SGDClassifier

sgd_clf = SGDClassifier(random_state = 42)
sgd_clf.fit(X_train, y_train_5)
```
