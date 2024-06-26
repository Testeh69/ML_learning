# Classification Algorithm

A classification algorithm is designed to handle discrete data and categorize it into distinct classes. It can be used for multi-class problems (where there are multiple possible categories) or for binary problems (where there are only two categories, for example, "is it a 5 or not?").

### 1. Type of Classification

#### A. **Binary Classification**

This type of classification is used when the algorithm needs to differentiate between two distinct classes. These classes can be labeled in various ways, but a common labeling convention is "true" or "false," "positive" or "negative," or "1" and "0." In binary classification, the model is trained to predict which of the two classes a given input belongs to.

For example:

- **Spam Detection**: Classifying emails as "spam" or "not spam."
- **Medical Diagnosis**: Determining if a patient has a disease ("positive") or not ("negative").
- **Fraud Detection**: Identifying transactions as "fraudulent" or "non-fraudulent."

#### B. Multi-Class Classification

This type of classification is used when the algorithm needs to differentiate between n distinc classes with n an integer. 

For this multiple strategies are deployed depending on the algorithm of the machine learning that we are running.

#Strategies_classification:

OvO (One versus One), we train a binary classificator for each pair of classes, then for N label we need to train $\frac{N(N-1)}{2}$.

OvR (One versus Rest) or OvA (One versus All): We train a classificator for each class and then selected the classificator with the best result.


#### C. **Multi-Label Classification**

This type of classification is used when each instance in the dataset can belong to multiple classes simultaneously. The goal is to predict all relevant classes for each instance.

For example:

- **Tagging a Document**: A document might be tagged with multiple topics such as "machine learning," "data science," and "AI."
- **Medical Diagnosis**: A patient might have multiple diseases at the same time, such as "diabetes" and "hypertension."

#### D. **Multi-Output Classification**

This type of classification involves predicting multiple outputs for each input instance. Each output corresponds to a separate classification task, and the model aims to provide predictions for all tasks simultaneously.

For example:

- **Image Processing**: Predicting the class of the object in the image (classification task) and simultaneously predicting the bounding box coordinates (regression task).
- **Text Processing**: Predicting the sentiment of a text (classification task) and generating a summary of the text (sequence-to-sequence task).

### 2. Importance of Metrics for Imbalanced Datasets

**Accuracy** is not always the best metric to measure the performance of a classification algorithm, especially if the dataset is imbalanced. 
In such cases, using a confusion matrix can provide more insight by detailing true positives, false positives, true negatives, and false negatives.
But we can also used Precision, Recall, ROC ...

##### A) Precision, Recall and F1



#Mathématique 
$$Precision= \frac{TP}{TP+FP}$$
#Precision_code

```Python
from sklearn.metrics import precision_score

precision_score(label,prediction)

```

#Mathématique 
$$Recall = \frac{TP}{TP+FN}$$

#Recall_code

```Python
from sklearn.metrics import recall_score

recall_scpre(label,prediction)
```



#Mathématique 
$$F1 = \frac{2}{\frac{1}{Precision} + \frac{1}{Recall}}$$

#F1_code

```Python
from sklearn.metrics import f1_score

f1_score(y_train_5,y_train_pred)
```

> [!NOTE]
> ==A high precision is useless if its recall is low.==

###### Balancing Precision and Recall

Precision and recall are often in tension with each other: as one increases, the other tends to decrease. To balance these, we set a **threshold** to adjust the trade-off between precision and recall.

###### Example Code

First, compute decision scores:





```PYTHON
y_scores = sgd_clf.decision_function(some_digit) 
y_some_digit_pred = (y_scores > 8000)  
y_scores = cross_val_predict(sgd_clf, X_train, y_train_5, cv=3, method="decision_function")
```

Next, obtain precision-recall pairs:

```Python
from sklearn.metrics import precision_recall_curve  
precisions, recalls, thresholds = precision_recall_curve(y_train_5, y_scores)
```

###### Plotting Precision and Recall vs. Threshold

**Option 1: Precision and Recall vs. Threshold**


```Python
import matplotlib.pyplot as plt  

def plot_precision_recall_vs_threshold(precisions, recalls, thresholds):     
	plt.plot(thresholds, precisions:-1, "b--", label="Precision")     
	plt.plot(thresholds, recalls:-1, "g-", label="Recall")     
	plt.xlim(-50000, 50000)     plt.xlabel("Threshold")     
	plt.ylabel("Value")     
	plt.title("Precision and Recall vs. Threshold")     
	plt.legend()     
	plt.show()  
	
plot_precision_recall_vs_threshold(precisions, recalls, thresholds)
```

**Option 2: Precision vs. Recall**


```Python
plt.plot(recalls[:-1], precisions[:-1], "r--") 
plt.xlabel("Recall") 
plt.ylabel("Precision") 
plt.title("Precision vs. Recall") 
plt.show()
```

> [!NOTE]
> This code helps visualize the trade-off between precision and recall, which is critical for selecting an appropriate threshold for your classification model.



#### B) ROC


The ROC, or **Receiver Operating Characteristic**, is a tool for binary classification that links the false positive rate (FPR) with the true positive rate (TPR).

**Mathematics:**

The ROC curve is not simply 1−False Negative Rate. Instead, it plots the True Positive Rate (TPR) against the False Positive Rate (FPR) at various threshold settings. The True Positive Rate is also known as recall or sensitivity, and it is defined as:

$$
TPR=\frac{TP}{TP+FN}​
$$

The False Positive Rate is defined as:


$$
FPR= \frac{FP}{FP + TN}
$$


**CODE :**

```Python
from sklearn.model_selection import cross_val_predict
from sklearn.metrics import roc_curve

y_probas_forest = cross_val_predict(forest_clf, X_train, y_train_5, cv=3, method="predict_proba")
y_scores_forest = y_probas_forest[:, 1]  # score = proba of positive class
fpr_forest, tpr_forest, thresholds_forest = roc_curve(y_train_5, y_scores_forest)
```

```Python
def plot_roc_curve(fpr = fpr, tpr = tpr, label = None):
    plt.plot(fpr,tpr,linewidth=2, label = label)
    plt.plot([0,1], [0,1], "k--")

plot_roc_curve()
plt.show()
```

> [!NOTE]
> To determine if a model has a good ROC curve, you look at how much the curve bows towards the top-left corner. Another method to compare models is to measure the Area Under the Curve (AUC). An AUC near 0.5 indicates a bad model (no better than random guessing), whereas an AUC near 1 indicates a good model.

**CODE :**

```Python
from sklearn.metrics import roc_auc_score

roc_auc_score(y_train_5, y_scores)
