# ML_learning
this repository contains all the notes and project that i used to developed my skills in machine learning, deep learning and artificial intelligence.

Resources:

-FreeCodeCamp:
Free Certification (Scientific computing with python, data analysis with python and machine learning with python)

-FreeCodeCamp: 
Machine learning for everybody (4 hours video) video https://www.youtube.com/watch?v=i_LwzRVP7bg&list=PLWKjhJtqVAblStefaz_YOVpDWqcRScc2s

-FreeCodeCamp:
Data Structures full courses using C/C++ (9:46 hours video) video https://www.youtube.com/watch?v=B31LgI4Y4DQ&t=3789s

-FreeCodeCamp:
Pointers in C/C++ (3:47 hours video) video https://www.youtube.com/watch?v=zuegQmMdy8M&list=WL&index=4&t=4701s

-Machine Learning avec Scikit-Learn (Book O REILLY) autor Aurélion Géron

# 1) REASONEMENT behind the studies:

As of August 11, 2023, I am a student specializing in Robotics Engineering. The significance of both C++ and Python in this field cannot be overstated. These two programming languages are key tools that enable me to excel in both robotics and my aspirations in AI engineering.

My ambition is to become an AI engineer, focusing on the development and application of cutting-edge technologies in the realm of artificial intelligence. In this pursuit, Python takes center stage due to its dominance in AI and its rich ecosystem of deep learning frameworks. These frameworks are indispensable for creating, training, and deploying complex neural networks and machine learning models.

However, I understand that to build a strong foundation for my career, I need to grasp the fundamentals that underpin programming and computer science. This is why I have dedicated time to thoroughly understanding algorithms and data structures. These concepts are the building blocks of problem-solving and efficient code design. They empower me to think logically and devise effective solutions to various challenges.

In preparation for my data structures course, I recognized the importance of delving into pointers in C and C++. This concept, although complex, plays a pivotal role in memory management and understanding the inner workings of programming languages. By gaining insight into pointers, I can better optimize my code for efficiency, a skill that will prove invaluable in both robotics and AI engineering.

In essence, my journey is an orchestrated sequence, with each step leading to the next. From my foundational studies in Robotics Engineering to mastering Python and deep learning frameworks, and culminating in data structures and pointers, I am cultivating a robust skill set. By merging these skills, I aim to bridge the gap between robotics and AI, working on projects that leverage the synergy of these fields. This holistic approach prepares me for a successful career as an AI engineer, capable of crafting innovative solutions for complex challenges.


# 2) Data Structures

# A) linked list:
![Singly-Linked-List1](https://github.com/Testeh69/ML_learning/assets/123935503/e2a00cfb-236b-4fbb-adc9-3b907ab0e7f7)

A linked list consists of nodes, and each node contains two main components: the data it holds and a reference (link) to the next node in the sequence. This linkage allows for the dynamic arrangement of elements, making linked lists a powerful tool when dealing with changing or unknown data sizes.

In contrast, static arrays, common in languages like C/C++, have a fixed size defined at the time of declaration. These arrays store data in contiguous memory locations, which ensures fast and direct access to elements. However, this contiguous requirement also means that the memory needs to be allocated in one continuous block. This constraint can lead to memory fragmentation and inefficiency, especially when dynamically resizing arrays.

Dynamic arrays, sometimes called "dynamically resizable arrays" or "vectors" in C++, offer a way to resize arrays during runtime. They handle memory allocation and resizing internally. However, they also rely on contiguous memory allocation, which can lead to challenges as the array grows or when memory becomes fragmented.

Linked lists, do not have the constraint of contiguous memory allocation. Each node can reside in a different memory location, and their connections are established through the links. This flexibility allows linked lists to handle dynamic allocation efficiently, making them suitable for scenarios where data size is unpredictable or where memory fragmentation is a concern.

In summary, linked lists shine when it comes to handling variable-sized data structures, allowing for efficient insertion and deletion operations without the need to worry about continuous memory allocation. Dynamic arrays provide similar benefits but still rely on contiguous memory, which can lead to limitations in some cases. Both data structures have their own strengths and trade-offs, and their selection depends on the specific requirements of a given problem.

![Array-Vs-Linked-List-01](https://github.com/Testeh69/ML_learning/assets/123935503/54c1f18b-99f3-4df8-8925-a22d5ff2d1a8)

In terms of Big O notation, linked lists offer distinct advantages and trade-offs:

    Access Cost: Linked List - O(n), Array - O(1)
    Memory Requirements: Linked List - Efficient memory usage, Array - Potentially unused memory
    Insertion Cost: Linked List - O(1) at the beginning, O(n) at nth position, Array - O(n) in general
    Ease of Use: Linked List - More prone to errors, Array - Simpler


Doubly linked lists offers a link to the previous node contrary to the simple linked list. This made the action of deletion an element more suited.

# 3) Machine Learning and Artificial Intelligence

Machine learning is a subfield of AI that depend heavily on data science (How to handle data).
There are 3 common types of algorithms in machine learning:

-Supervised learning: where the data is labeled, we have input and output
   
   =>Two types of problems:
   
       -Classification: predict discrete values (binary classification and multiclass classification) like knn, Naive Bayes, Logistic regression, Neural network and so on.
       
       -Regression: predict continous values like linear regression, neural network

-Unsupervised learning: where the computer determined features through the data that we feed in and gathered into various groups depending on these features.
      - K- means
      - Principal component analysis could be used to reduce the dimensionality of the dataset in fusing features to create a new feature.

-Reinforcement learning: Agent learning in interactive environnment based on rewards and penalties.

Dataset is split into 3 dataset => Training Dataset, Validation Dataset and testing Dataset


# 4) NEURAL NETWORK

# A) The principal of a neural networks:

A neural network is composed of layers of "neurons", the first layers is the input layers depend on how many dimensions of features we have and the last layers depend on how many output we have. Between this two layers there layers called hidden layers.

We use activation function like "sigmoid", "tanh", "relu" so that the neural networks is not linear(not sure on how to describe how this part is important).(Modification 31/07/2023): So this is important because the model can learn non-linear pattern (the dataset if often non-linear).

# B) Neural Networks for linear regression problem:

We use as a input layers a normalization layers so that all features should be on a similar scales. The most common types is features scaling which means that we set the dataset to have a mean of 0 and a standard deviation of 1.



# Note Computer science and Machine Learning:

-The computer does not understand letters so we have to convert letters into numbers.



# Projects:

30/07/23: learning_ml_magic (classification): FreeCodeCamp

31/07/23: linear_ml_algorithm (linear) : FreeCodeCamp

04/08/23: Unsurpevised_learning (unsurpevised) : FreeCodeCamp

04/08/23: projet_ml_california(1) (Decision_tree, linear regression (work in progress))

09/08/23: Linked_list.cpp

11/08/23: Linked_List.cpp (implemented pushFront, insertAfter and pushBack method)

12/08/23: Linked_List.cpp(implemented popFront, popBack, removeNode, getHead, getTail, getNode method)

13/08/23: Linked_List.cpp(implemented isEmpty, size, contains method)

17/08/23:Doubly_Linked_List.cpp(implemented pushFront, pushBack method)

01/09/23:Doubly_Linked_List.cpp(implemented insertAfter method)

02/09/23: Doubly_Linked_List.cpp(implemented popFront, popBack, removeNode, getHead, getTail, getNode, isEmpty, size, contains method) 


# Skills developped: 
Data structures (linked list), C++(pointers, class),C (pointers),Python (class), git, github


# Note: 
Please note that I am a French student studying AI and computer science during my free time. While I strive for accuracy, errors may occur. If you identify any inaccuracies, kindly notify me via email at norefice45@gmail.com.
