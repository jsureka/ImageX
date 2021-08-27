# Imagex - Image Processing Tools Software

Submitted by:
Jitesh Sureka
	
Supervised By:
Dr. Ahmedul Kabir
Designation: Assistant Professor
Institute of Information Technology
University of Dhaka


ImageX is an image processing software that consists of a number of image processing tools. The tools in this software are helpful in editing an image very efficiently. The software also gives option to save the processed images to use the image for different purposes of the user. User can input a 24-bit bitmap image to the software and use the tools on it. I tried to implement eight image processing tools which are more often used in image processing related fields.
The tools are : Edge Detection, Greyscale, Smoothing, Brightening, Blurring, Noise Generation, Image Halftoning and Sharpening. The results obtained are perfectly reusable and can also be re-used in the software to edit the edited image again.

This software is a small-scale implementation of a large image processing software that we often use in our regular life. Many more tools can be added to to the software to upscale the usage of software. 

The scopes of my project are: -
	Creating an image processing system that takes an image as input and outputs an edited image 
	Implementing the following image processing algorithms: -
o	Edge Detection
o	Grey Scaling
o	Smoothing
o	Brightening
o	Blurring
o	Noise Generation
o	Halftoning
o	Sharpening

	Using C/C++ as a programming language to implement the given algorithms and processes
	Using internal C libraries to complete the project (Avoid using any external library)

#User Manual 

	The user will see the following interface after running the ImageX program
 
	User has to input path of a bmp file format image in the indicated place of command line. The initial preview of the image will be shown when enter is pressed.
 

	The user will be shown a small preview at the top of the menu, then he can enter the tools section without any error popup to start using the image processing tools. 


	The tools have menu has different tools that can be used upon clicking. The results and usage of each tool is given below: 


 Edge Detect

On clicking the edge detect option, an edge detected output image will be shown with the option to save it. 
			
 Grey Scale

On clicking the grey scale option, a grey scaled image of the input image will popup as the desired output. 

 Smoothing

On clicking the smoothing option, user will be asked to input the smoothing threshold between the values 2 – 10 . The intensity of the smoothing will increase by the given value times. The figure shows a smoothing with value 6.

 Brightening

Brightening option gives the user option to input the value between -255 to +255. If a user chooses a positive value, the brightness of the image will increase by that value, if a user chooses a negative value, the brightness will decrease. The figure uses a brightness value of + 128
 

 Blurring 

The image will be blurred by the threshold that is given by the user upon clicking this option. The threshold values lie between 2 -10, where increased threshold will cause increased blurring of image. The figure shows an image with 5 blur thresholds


 Noise 

A noisy image is generated as an output if this option is clicked. 

 Halftoning

Image is halftoned with respect to a threshold that is inputted by the user upon clicking this option. The threshold lies between 0 – 255. Standard halftoning threshold is 128.

 Sharpening

An image is sharpened between the threshold 2 – 10 if this option is chosen. The user will input the threshold value and the output sharpened image will be produced accordingly. The figure shows a sharpened image of value 5.


	The “Return” option is used to get back to the main menu of the software
	After having the desired output, if user clicks the save option, he/she will be asked to name the file to save. Image will be saved when enter is pressed. The “Output image” of the main menu contains the most recently edited version of the input image. 
	The manual option contains the user manual of the software.
	The “Exit” button shows a popup and closes the software. 


