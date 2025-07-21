# Entropy-Based Feature Analysis in C++

This project implements entropy-based feature analysis and selection techniques using C++. It reads a CSV dataset where each row represents a data instance, columns represent features, and the last column is treated as the class label. The tool computes entropy and related measures to help evaluate the relevance of features.

## 📦 Features

- Entropy and conditional entropy calculations
- Modular and extendable C++ code structure
- Lightweight and fast
- Examples using vectors, arrays, and linked lists

## 🛠️ Compilation

To compile the project, run the following command:

```bash
g++ -std=c++11 -o entropy \
  entropy.cpp \
  examples_vector.cpp \
  examples_vector_array.cpp \
  linkedlist.cpp \
  linkedlistarray.cpp
```

## 🚀 Usage

```bash
./entropy INPUTFILE.csv
```

- **INPUTFILE.csv** must be in the following format:
  - Comma-separated values
  - The **first row** should be a **header line** with column names
  - Each row is a data instance
  - Each column (except the last) is a feature
  - The **last column** is the class label

### Example:

```csv
sepal_length,sepal_width,petal_length,petal_width,label
5.1,3.5,1.4,0.2,setosa
4.9,3.0,1.4,0.2,setosa
...
```

## 📂 File Structure

```
.
├── entropy.cpp                # Main logic
├── examples_vector.cpp       # Vector-based implementation
├── examples_vector_array.cpp # Vector with array implementation
├── linkedlist.cpp            # Linked list implementation
├── *.h                       # Header files
├── README.md                 # This file
```

## 📚 References

This code is inspired by traditional entropy-based feature selection techniques used in data mining and machine learning.

## 🤝 Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

---

© 2025 Ahmet Aksoy – Licensed under the MIT License
