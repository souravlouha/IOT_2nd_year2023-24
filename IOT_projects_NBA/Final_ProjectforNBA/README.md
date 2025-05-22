# 🌿 Plant Disease Detection Using Machine Learning

---
### 📘 Abstract
Plant diseases significantly reduce agricultural productivity and pose a threat to global food security. This project presents an end-to-end deep learning-based system for early detection of plant diseases using leaf images. The proposed system employs a Convolutional Neural Network (CNN) trained on a curated dataset of healthy and diseased plant leaves. A Streamlit-powered web interface allows for real-time predictions, making it accessible for farmers and agricultural professionals.

---
### 🧠 Introduction
Timely and accurate identification of plant diseases is critical for ensuring high agricultural yield and food safety. Traditional manual methods are not only time-consuming but also require expert knowledge. In this project, we explore a data-driven approach that uses machine learning to classify plant diseases from images, enabling automated and scalable disease diagnosis.

---
### 🎯 Objectives
To develop a CNN-based model capable of classifying plant leaf diseases with high accuracy.

To build an intuitive user interface for non-technical users to perform predictions.

To provide a scalable and efficient solution that can be extended for mobile or IoT-based applications.

---
### 🛠️ System Architecture
#### 1. Data Collection & Preprocessing
Collected from publicly available datasets (e.g., PlantVillage).

Preprocessing steps included:

Image resizing and normalization

Data augmentation using OpenCV (rotation, flipping, zoom)

Conversion to grayscale/RGB format (as per model input)

#### 2. Model Training
Architecture: CNN with multiple convolutional and pooling layers

Framework: TensorFlow/Keras

Optimizer: Adam

Loss Function: Categorical Crossentropy

Epochs: 25–50 (tunable)

Evaluation Metrics: Accuracy, Precision, Recall, F1-score

### 3. Deployment
The trained model was integrated into a Streamlit web app.

Allows users to upload images and view predictions in real-time.

Visual feedback provided with confidence scores and classification labels.

---

## 🌾 PlantVillage Crop Image Dataset Overview

This repository provides a detailed breakdown and usage overview of the **PlantVillage** dataset, commonly used for machine learning and computer vision tasks focused on plant disease detection and classification.

---

## 📊 Dataset Summary

| Crop Type | Number of Classes | Total Images |
|-----------|-------------------|--------------|
| Tomato    | 10                | 18,000+      |
| Potato    | 3                 | 2,200+       |
| Corn      | 4                 | 4,000+       |
| Others    | Varies            | 1,000+       |

**Total Images:** ~30,000  
**Image Formats:** `.jpg`, `.png`  
**Source:** [PlantVillage Dataset](https://www.kaggle.com/datasets/emmarex/plantdisease)

---

## 📁 Directory Structure (Example)
# 🌿 PlantVillage Crop Disease Image Dataset

This repository contains a structured image dataset of various crops affected by different diseases. It is organized for use in machine learning and deep learning projects focused on plant disease detection and classification.

---

## 📊 Dataset Summary

| Crop Type | Number of Classes | Image Count |
| --------- | ----------------- | ----------- |
| Tomato    | 10                | 18,000+     |
| Potato    | 3                 | 2,200+      |
| Corn      | 4                 | 4,000+      |
| Others    | Varies            | 1,000+      |

**Total Images:** \~30,000
**Formats:** `.jpg`, `.png`
**Source:** [PlantVillage Dataset](https://www.kaggle.com/datasets/emmarex/plantdisease)

---

## 📂 Dataset Directory Structure
```bash
dataset/
├── Tomato/
│ ├── Tomato\_\_\_Bacterial\_spot/
│ ├── Tomato\_\_\_Late\_blight/
│ └── ...
├── Potato/
│ ├── Potato\_\_\_Early\_blight/
│ └── Potato\_\_\_Late\_blight/
├── Corn/
│ ├── Corn\_\_\_Cercospora\_leaf\_spot/
│ └── ...
└── Others/
├── Bell\_pepper/
└── Others/
```
---
###  📈 Results & Performance

| Metric         | Value     |
|----------------|-----------|
| Accuracy       | ~95%      |
| Precision      | ~94.5%    |
| Recall         | ~93%      |
| F1 Score       | ~93.5%    |
| Training Time  | ~20 mins (on GPU) |

Visualizations of the confusion matrix, ROC curves, and loss/accuracy plots are available in the `results/` directory.

---

### 🌐 Web Application
#### Features:
Upload leaf image and detect disease

Confidence score with class label

Simple and responsive UI using Streamlit

Secure and local-only inference (no external API)

---
#### Running the App:
```bash

 streamlit run app.py 
 ```
You’ll be able to upload an image and view predictions in your browser.

---
### 🔭 Future Work
Edge Deployment: Optimizing the model for deployment on Raspberry Pi and Android devices.

More Crops: Expanding the dataset to include more regional crops.

Multilingual Interface: Adding support for regional languages to increase accessibility.

Self-learning System: Continuous model improvement with user feedback loop.

### 🧪 Research Significance
Demonstrates the effectiveness of deep learning in precision agriculture.

Provides a cost-effective and scalable solution to a real-world problem.

Can reduce dependency on expert agronomists for early-stage diagnosis.

Helps in reducing pesticide misuse and improving crop yield.

### 📂 File Structure

``` bash
Final_ProjectforNBA/
├── app.py                 # Streamlit app
├── model/
│   └── plant_disease_model.h5
├── utils/
│   ├── preprocessing.py
│   └── predict.py
├── dataset/
│   └── images/
├── requirements.txt
└── README.md
```

---
### 📚 References
Mohanty, S. P., Hughes, D. P., & Salathé, M. (2016). Using deep learning for image-based plant disease detection. Frontiers in Plant Science.

PlantVillage Dataset – Kaggle

TensorFlow Documentation – https://www.tensorflow.org

### 👨‍💻 Author
Sourav Louha -
[GitHub Profile](https://github.com/souravlouha)
Third-year Engineering Student | ML Enthusiast | Open Source Contributor




<h1>Plant Disease Detection Using Machine Learning</h1>

<url>![Screenshot (129)](https://github.com/user-attachments/assets/9c142875-973e-43ce-848e-dbea3e4cda3c)</url>
<url>![Screenshot (130)](https://github.com/user-attachments/assets/b053a9e7-fb8e-466b-b2b7-0143b416831b)</url>


