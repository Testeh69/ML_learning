
### Fine-Tuning

Fine-tuning is the process of selecting the best parameters for a machine learning model to optimize its performance according to specific metrics. This involves iterating over the same dataset to find the best combination of parameters that yield the best results.

In this example, we use the `GridSearchCV` function from the `sklearn` library for fine-tuning.

#code 

```python
from sklearn.model_selection import GridSearchCV


param_grid = {"parameter_one": [variable, variable_one ....],
			  "Parameter_two": ......}

grid_search = GridSearchCV(ML_Model, param_grid, cv = int , scoring = "str", n_jobs = int , verbose = int)
grid_search.fit(X_train, y_train)
```
cv: number of cross validation
n_jobs: use of CPU for parrallel processing

#Sélectionner_le_meilleur_modèle


```Python
best_knn = grid_search.best_estimator_
```


> [!NOTE]
> A good practice for me is to always have verbose stick to Two so that we can follow the advancement of the training of the algorithm.
