# Linear Regression


source: https://haltode.fr/algo/ia/apprentissage_artificiel/regression_lin_poly/equation_normale.html


#Modèle mathématique

une régrésion linéaire est une fonction affine sous la forme:

$\hat{y} = a1*x1 + a2*x2 + a3*x3 + .... + a0 = X \cdot \theta$  

	avec y : output estimé du modèle
		 xN: paramètre d'entrée 
		 aN: paramètre du modèle (qu'il faudra ajuster)
		 

Pour #ajuster les paramètres du modèles, on utilise des fonctions telle que la #RMSE (ROOT MEAN SQUARE ERROR) ou #MSE (MEAN SQUARE ERROR).

$$ RMSE = \sqrt{\frac{1}{n} \sum_{i=1}^{n} (y_i - \hat{y}_i)^2} $$

Où :
- $n$ est le nombre d'observation.
- $y_i$ est la valeur en fonction des observations.
- $\hat{y}_i$ est la valeur estimée du modèle


$MSE = \frac{1}{n} \sum_{i=1}^{n} (y_i - \hat{y}_i)^2$

Où :
- n est le nombre d'observations.
- $y_i$ est la valeur réelle (observée) pour la i-ème observation.
- $\hat{y_i}$ est la valeur prédite pour la i-ème observation.



#optimisation 

On peut trouver les paramètres optimales via l'équation normale du modèle


L'équation normale est une méthode algébrique utilisée pour trouver les valeurs optimales des paramètres d'un modèle de régression linéaire. Pour un modèle de régression linéaire simple (une seule caractéristique), l'équation normale est exprimée comme suit :

$\theta = (X^T X)^{-1} X^T y$ 



#linear_regression_code


```python
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error

lin_model = LinearReagression()
lin_model.fit(X_train,y_train)
predict = lin_model.predict(X_test)
rmse = np.sqrt(mean_squared_error(y_test,predict))
