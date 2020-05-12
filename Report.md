# Assignment 2 report.

### Name: Amira Ahmad Noaman 
### Code: 1170400
______________________
### This report is to show some screenshots of the main movements which are:
1. Moving the camera to the left
2. Moving the camera to the right 
3. Moving the camera below the object
4. Moving the camera above the object
5. Moving forward to get closer to the object
6. Moving backward to get away from the object
___________________________

#### 1) Moving the camera to the left
Sample code:
```
void Left()
{
	rotatePoint(up, 0.05, eye);
}
```
![image](Capture.jpg)

#### 2) Moving the camera to the right 
The code is similar but we change the angle to be -0.05 to rotate in the other side

![image](Capture1.jpg)

##### Notice that now both buttons if pressed can make you rotate around the shape but we can add boundaries to this rotation so we can stop them from rotating 360 degrees.


#### 3) Moving the camera below the object
Sample code:
```
void Up()
{
	// implement camera rotation arround horizontal window screen axis +ve
	// used by up arrow

	double sub[3];
	for (int i = 0; i < 3; i++)
	{
		sub[i] = center[i] - eye[i];
	}
	double cross[3];
	crossProduct(sub, up,cross);
	normalize(cross);
	rotatePoint(cross, 0.05, eye);
	rotatePoint(cross, 0.05, up);

}
```
![image](Capture2.jpg)

### 4) Moving the camera above the object
Same thing happens concerning the negative angle
![image](Capture3.jpg)

### 5) Moving forward to get closer to the object
Sample code:
```
void moveForward()
{
	SetDirection(direction);

	eye[0] += direction[0] * speed;
	eye[1] += direction[1] * speed;
	eye[2] += direction[2] * speed;

	center[0] += direction[0] * speed;
	center[1] += direction[1] * speed;
	center[2] += direction[2] * speed;
}
```
![image](Capture4.jpg)

### 6) Moving backward to get away from the object
Sample code:
```
void moveForward()
{
	SetDirection(direction);

	eye[0] -= direction[0] * speed;
	eye[1] -= direction[1] * speed;
	eye[2] -= direction[2] * speed;

	center[0] -= direction[0] * speed;
	center[1] -= direction[1] * speed;
	center[2] -= direction[2] * speed;
}
```
![image](Capture5.jpg)



### If you press these keys you'll get something very similar like the gif posted on the assignment page.
______________________
