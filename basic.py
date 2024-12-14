import cv2
import numpy as np
import face_recognition

img1 = face_recognition.load_image_file('Messi1.webp')
img1 = cv2.cvtColor(img1,cv2.COLOR_BGR2RGB)
img2 = face_recognition.load_image_file('images/Elon Musk.jpg')
img2 = cv2.cvtColor(img2,cv2.COLOR_BGR2RGB)

faceloc = face_recognition.face_locations(img1)[0]
encodeimg1 = face_recognition.face_encodings(img1)[0]
cv2.rectangle(img1,(faceloc[3],faceloc[0]),(faceloc[1],faceloc[2]),(255,0,255),2)

facelocimg2 = face_recognition.face_locations(img2)[0]
encodeimg2 = face_recognition.face_encodings(img2)[0]
cv2.rectangle(img2,(facelocimg2[3],facelocimg2[0]),(facelocimg2[1],facelocimg2[2]),(255,0,255),2)

results = face_recognition.compare_faces([encodeimg1],encodeimg2)
faceDis = face_recognition.face_distance([encodeimg1],encodeimg2)
print(results,faceDis)
cv2.putText(img2,f'{results} {round(faceDis[0],2)}',(50,50),cv2.FONT_HERSHEY_COMPLEX,1,(0,0,255),2)


cv2.imshow('Messi',img1)
cv2.imshow('ELON MUSK',img2)
cv2.waitKey(0)