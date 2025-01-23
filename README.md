@mainpage bmpSteganography
@author Aliki Vasili Panagiotis Papadopoulos

# bmpSteganography
bmpSteganography is a powerful library designed to manipulate BMP image files and embed hidden messages or images within them using steganography techniques. The library provides a range of functionality, from applying filters to encrypting and decrypting data inside BMP images.

## 🌟 Features
- Header Information: List the header information of BMP image files for better understanding of their structure.
- Image Processing: Apply a grayscale filter to BMP images.
- Steganography: Encrypt and decrypt one BMP image inside another BMP image., Encrypt and decrypt text inside BMP images., Transform text to BMP images and vice versa.
## 📚 Educational Purpose
This project was developed as part of an academic assignment and served as a fantastic introduction to working with binary files and steganography. It allowed us to create tangible results beyond simple console messages, providing a deeper understanding of BMP file structures and binary file manipulation.
## 🚀 Getting Started
### Prerequisites
Ensure you have the following installed on your system:
- C Compiler: A compiler like GCC or Clang to build and run the code.
### Installation
- Clone the repository:
```bash
git clone https://github.com/username/bmpSteganography.git
cd bmpSteganography
```
- Build the project:
Use your preferred C compiler to compile the code. For example:
```
gcc -o bmpSteganography main.cpp bmpSteganography.cpp
```
### 🔍 How to Use
Here’s an overview of the main functionalities provided by the library:
1️⃣ List BMP Header Information
Retrieve detailed header information of a BMP file:
```bash
listHeader("example.bmp");
```
2️⃣ Apply Grayscale Filter
Transform a BMP image to grayscale:
```bash
applyGrayscale("input.bmp", "output_grayscale.bmp");
```
3️⃣ Encrypt BMP Image Inside Another BMP
Hide one BMP image inside another:
```bash 
encryptImage("host.bmp", "secret.bmp", "output.bmp");
```
4️⃣ Decrypt BMP Image
Retrieve a hidden BMP image:
```bash
decryptImage("encrypted.bmp", "extracted_secret.bmp");
```
5️⃣ Encrypt and Decrypt Text in BMP
Encrypt text:
```bash
encryptText("input.bmp", "message.txt", "output_with_text.bmp");
```
Decrypt text:
```bash
decryptText("output_with_text.bmp", "extracted_message.txt");
```
6️⃣ Convert Text to BMP and Vice Versa
Convert a text file into a BMP image:
```bash
textToImage("message.txt", "output_image.bmp");
```
Extract text from a BMP image:
```bash
imageToText("output_image.bmp", "extracted_message.txt");
```
## 🛠 Development Notes
- Binary File Manipulation: The project heavily relies on understanding and manipulating binary data within BMP files.
- Error Handling: The library includes basic error handling for invalid or unsupported BMP files.
- Scalability: This library can be extended to support other image formats or advanced steganographic techniques.
## 📄 Example Output
For the grayscale filter, the result is a BMP image transformed into shades of gray, while the steganography features allow seamless embedding and extraction of hidden data with minimal visible changes to the host image.
