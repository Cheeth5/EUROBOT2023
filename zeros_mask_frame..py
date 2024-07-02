import cv2
import numpy as np

# Initialize the video capture object
cap = cv2.VideoCapture(2)

while True:
    # Read the next frame from the video stream
    _, frame = cap.read()

    # Convert the frame to grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Blur the image to reduce high frequency noise
    gray = cv2.medianBlur(gray, 5)

    # Create a mask of zeros
    mask = np.zeros(gray.shape, dtype=np.uint8)

    # Use the HoughCircles function to detect circles in the frame
    circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT, 1, 20, param1=50, param2=30, minRadius=0, maxRadius=0)

    # Draw the circles on the mask
    circles = np.int16(np.around(circles))


    for c in circles[0,:]:
        cv2.circle(mask,(c[0], c[1]), c[2], (255, 255, 255), -1)
    # Mask the frame with the circles mask
    result = cv2.bitwise_and(mask, mask, mask=mask)

    # Show the result
    cv2.imshow('Result', mask)

    # Check if the user pressed the 'q' key
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the video capture object and close all windows
cap.release()
cv2.destroyAllWindows()
