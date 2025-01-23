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
gcc -o bmpSteganography main.c bmpSteganography.c
```
### 🔍 How to Use
Here’s an overview of the main functionalities provided by the library:
1) List BMP Header Information
```bash
./bmpSteganography list image1.bmp [image2.bmp image3.bmp ...]
```
2) Apply Grayscale Filter
```bash
./bmpSteganography grayscale image1.bmp [image2.bmp image3.bmp ...]
```
3) Encode an Image into Another Image
```bash
./bmpSteganography encodeStegano numOffBits coverImg.bmp secretImage.bmp
```
 - numOffBits: Offset in bits for encoding.
 - coverImg.bmp: The host image where the secret image will be hidden.
 - secretImage.bmp: The image to be embedded.
4) Decode a Hidden Image from a BMP File
```bash 
./bmpSteganography decodeStegano numOffBits encryptedImage.bmp
```
- numOffBits: Offset in bits used during encoding.
- encryptedImage.bmp: The image containing the hidden BMP file.
Encode Text into a BMP Image
Command:
```bash
./bmpSteganography encodeText coverImage.bmp inputText.txt
```
- coverImage.bmp: The BMP image where the text will be embedded.
- inputText.txt: The text file containing the message to hide.
Decode Text from a BMP Image
```bash
./bmpSteganography decodeText encryptedImage.bmp msgLength output.txt
```
 - encryptedImage.bmp: The image containing the hidden text.
 - msgLength: Length of the embedded message.
 - output.txt: The file where the extracted text will be saved.
Convert Text to a BMP Image
```bash
./bmpSteganography stringToImage sampleImage.bmp inputText.txt
```
- sampleImage.bmp: The BMP file where the text will be converted into an image.
- inputText.txt: The text file to transform into a BMP image.
Extract Text from a BMP Image
```bash
./bmpSteganography imageToString sampleImage.bmp inputText.txt
```
- sampleImage.bmp: The BMP file containing the hidden text.
- inputText.txt: The file where the extracted text will be saved.
## 🛠 Development Notes
- Binary File Manipulation: The project heavily relies on understanding and manipulating binary data within BMP files.
- Error Handling: The library includes basic error handling for invalid or unsupported BMP files.
- Scalability: This library can be extended to support other image formats or advanced steganographic techniques.
## 📄 Example Output
For the grayscale filter, the result is a BMP image transformed into shades of gray, while the steganography features allow seamless embedding and extraction of hidden data with minimal visible changes to the host image.
