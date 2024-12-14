# Face_Recognition_System
Overview
This is a Python-based Face Recognition System that uses OpenCV and the face_recognition library to identify faces in real-time. The project demonstrates the implementation of facial encoding, detection, and recognition using a webcam or pre-existing images.

Features
Detects faces in real-time from a webcam feed.
Matches detected faces with known faces stored in a dataset.
Displays the name of the recognized individual on the video stream.
Simple and efficient facial encoding using the face_recognition library.
Technologies Used
Python
OpenCV
face_recognition library
NumPy
How It Works
Encoding Known Faces:
Images of known individuals are stored in the images folder.
Each image is encoded into a numerical representation using the face_recognition library.
Real-time Face Detection:
The webcam feed is processed frame by frame.
Faces in the frame are detected, encoded, and compared to the known encodings.
Recognition:
If a match is found, the system displays the name of the individual on the webcam feed.
