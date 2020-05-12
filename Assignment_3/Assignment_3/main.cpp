//#include <GL/glut.h>
//#include <math.h>
//
//static int shoulderX = 0, elbowX = 0;
//static int bodyBox = 0, legBase = 0, legUp = 0, legBase2 = 0, legUp2 = 0, wholeShape = 0, legX = 0, leg2X = 0;
//int moving, startx, starty;
//double speed = 0.2;
//
//GLfloat angle = 0.0;   /* in degrees */
//GLfloat angle2 = 0.0;   /* in degrees */
//
//static int shoulder = 0, shoulder2 = 0, elbow = 0, fingerBase = 0, fingerUp = 0, rhip = 0, rhip2 = 0, rknee = 0, lknee = 0, lhip = 0, lhip2 = 0;
//double eye[] = { 0, 0, -20 };
//double center[] = { 0, 0, 1 };
//double up[] = { 0, 1, 0 };
//
//double direction[3];
//
//
//void init(void)
//{
//	glMatrixMode(GL_PROJECTION);
//	gluPerspective(65.0, (GLfloat)1024 / (GLfloat)869, 1.0, 60.0);
//}
//
//void drawArm()
//{
//	glPushMatrix();
//
//	//Shoulder
//	glTranslatef(1.125, 1.5, 0.0);
//	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
//	glRotatef((GLfloat)shoulderX, 0.0, 1.0, 0.0);
//	glTranslatef(0.0, -1.0, 0.0);
//
//	glPushMatrix();
//	glColor3f(1.0, 0.5, 0.0);
//	glScalef(0.25, 2.0, 0.5);
//	glutWireCube(1.0);
//	glPopMatrix();
//
//	//Elbow
//	glPushMatrix();
//	glTranslatef(0.0, -1.0, 0.0);
//	glRotatef((GLfloat)elbow, 1.0, 0.0, 0.0);
//	glTranslatef(0.0, -1.0, 0.0);
//
//	glPushMatrix();
//	glColor3f(1.0, 0.5, 0.0);
//	glScalef(0.25, 2.0, 0.5);
//	glutWireCube(1.0);
//	glPopMatrix();
//	glPopMatrix();
//
//	glPopMatrix();
//}
//
//
//void drawLeg()
//{
//	glPushMatrix();
//
//	//=====================================Left Leg==================================
//
//	//Left Leg base
//	glTranslatef(0.625, -1.5, 0.0);
//	glRotatef((GLfloat)legBase, 1.0, 0.0, 0.0);
//	glRotatef((GLfloat)legX, 0.0, 0.0, 1.0);
//
//	glTranslatef(0.0, -1.25, 0.0);
//
//	glPushMatrix();
//	glColor3f(0.0, 0.0, 6.0);
//	glScalef(0.75, 2.5, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//
//	//Leg Flang 
//	glTranslatef(0.0, -1.75, 0.0);
//	glRotatef((GLfloat)legUp, 1.0, 0.0, 0.0);
//	glTranslatef(0.0, -0.75, 0.0);
//
//	glPushMatrix();
//	glScalef(0.75, 2.5, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//
//	//Shoes
//	glTranslatef(0.0, -1.5, 0.0);
//
//	glPushMatrix();
//	glColor3f(1.0, 1.0, 1.0);
//	glScalef(0.75, 0.5, 2.0);
//	glutSolidCube(1.0);
//	glPopMatrix();
//
//
//
//	glPopMatrix();
//}
//
//
//void drawLeg2()
//{
//	glPushMatrix();
//
//	//Leg base
//	glTranslatef(-0.625, -1.5, 0.0);
//	glRotatef((GLfloat)legBase2, 1.0, 0.0, 0.0);
//	glRotatef((GLfloat)leg2X, 0.0, 0.0, 1.0);
//
//	glTranslatef(0.0, -1.25, 0.0);
//
//	glPushMatrix();
//	glColor3f(0.0, 0.0, 6.0);
//	glScalef(0.75, 2.5, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//
//	//Leg Flang 
//	glTranslatef(0.0, -1.75, 0.0);
//	glRotatef((GLfloat)legUp2, 1.0, 0.0, 0.0);
//	glTranslatef(0.0, -0.75, 0.0);
//
//	glPushMatrix();
//	glScalef(0.75, 2.5, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//
//	//Shoes
//	glTranslatef(0.0, -1.5, 0.0);
//
//	glPushMatrix();
//	glColor3f(1.0, 1.0, 1.0);
//	glScalef(0.75, 0.5, 2.0);
//	glutSolidCube(1.0);
//	glPopMatrix();
//
//
//
//	glPopMatrix();
//}
//
//
//
//
//void crossProduct(double a[], double b[], double c[])
//{
//	c[0] = a[1] * b[2] - a[2] * b[1];
//	c[1] = a[2] * b[0] - a[0] * b[2];
//	c[2] = a[0] * b[1] - a[1] * b[0];
//}
//
//void normalize(double a[])
//{
//	double norm;
//	norm = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
//	norm = sqrt(norm);
//	a[0] /= norm;
//	a[1] /= norm;
//	a[2] /= norm;
//}
//
//void rotatePoint(double a[], double theta, double p[])
//{
//
//	double temp[3];
//	temp[0] = p[0];
//	temp[1] = p[1];
//	temp[2] = p[2];
//
//	temp[0] = -a[2] * p[1] + a[1] * p[2];
//	temp[1] = a[2] * p[0] - a[0] * p[2];
//	temp[2] = -a[1] * p[0] + a[0] * p[1];
//
//	temp[0] *= sin(theta);
//	temp[1] *= sin(theta);
//	temp[2] *= sin(theta);
//
//	temp[0] += (1 - cos(theta))*(a[0] * a[0] * p[0] + a[0] * a[1] * p[1] + a[0] * a[2] * p[2]);
//	temp[1] += (1 - cos(theta))*(a[0] * a[1] * p[0] + a[1] * a[1] * p[1] + a[1] * a[2] * p[2]);
//	temp[2] += (1 - cos(theta))*(a[0] * a[2] * p[0] + a[1] * a[2] * p[1] + a[2] * a[2] * p[2]);
//
//	temp[0] += cos(theta)*p[0];
//	temp[1] += cos(theta)*p[1];
//	temp[2] += cos(theta)*p[2];
//
//	p[0] = temp[0];
//	p[1] = temp[1];
//	p[2] = temp[2];
//
//}
//
//void SetDirection(double d[])
//{
//	d[0] = center[0] - eye[0];
//	d[1] = center[1] - eye[1];
//	d[2] = center[2] - eye[2];
//}
//
//void Left()
//{
//	// implement camera rotation arround vertical window screen axis to the left
//	// used by mouse and left arrow
//	rotatePoint(up, 0.05, eye);
//}
//
//void Right()
//{
//	// implement camera rotation arround vertical window screen axis to the right
//	// used by mouse and right arrow
//	rotatePoint(up, -0.05, eye);
//}
//
//void Up()
//{
//	// implement camera rotation arround horizontal window screen axis +ve
//	// used by up arrow
//
//	double sub[3];
//	for (int i = 0; i < 3; i++)
//	{
//		sub[i] = center[i] - eye[i];
//	}
//	double cross[3];
//	crossProduct(sub, up,cross);
//	normalize(cross);
//	rotatePoint(cross, 0.05, eye);
//	rotatePoint(cross, 0.05, up);
//
//}
//
//void Down()
//{
//	// implement camera rotation arround horizontal window screen axis 
//	// used by down arrow
//
//	double sub[3];
//	for (int i = 0; i < 3; i++)
//	{
//		sub[i] = center[i] - eye[i];
//	}
//	double cross[3];
//	crossProduct(sub, up, cross);
//	normalize(cross);
//	rotatePoint(cross, -0.05, eye);
//	rotatePoint(cross, -0.05, up);
//}
//
//void moveForward()
//{
//	SetDirection(direction);
//
//	eye[0] += direction[0] * speed;
//	eye[1] += direction[1] * speed;
//	eye[2] += direction[2] * speed;
//
//	center[0] += direction[0] * speed;
//	center[1] += direction[1] * speed;
//	center[2] += direction[2] * speed;
//}
//
//void moveBack()
//{
//	SetDirection(direction);
//
//	eye[0] -= direction[0] * speed;
//	eye[1] -= direction[1] * speed;
//	eye[2] -= direction[2] * speed;
//
//	center[0] -= direction[0] * speed;
//	center[1] -= direction[1] * speed;
//	center[2] -= direction[2] * speed;
//
//}
//
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);
//
//	glRotatef(angle2, 1.0, 0.0, 0.0);
//	glRotatef(angle, 0.0, 1.0, 0.0);
//
//	glRotatef(wholeShape, 0.0, 1.0, 0.0);
//	glTranslatef(0.0, 0.0, -1.0);
//	glTranslatef(0.0, 1.5, 0.0);
//	glRotatef(bodyBox, 0.0, 1.0, 0.0);
//	glScalef(0.75, 0.75, 0.75);
//
//	// draw head
//	glPushMatrix();
//	glTranslatef(0.0, 2.25, 0.0);
//	glutWireSphere(0.5, 10, 16); /* draw head */
//	glPopMatrix();
//
//	//Neck
//	glPushMatrix();
//	glTranslatef(0.0, 1.75, 0.0);
//	glColor3f(1.0, 1.0, 1.0);
//	glScalef(0.5, 0.5, 0.5);
//	glutWireCube(1.0);
//	glPopMatrix();
//
//
//	// draw trunck
//	//Body box
//	glPushMatrix();
//	glColor3f(1.0, 0.5, 0.0);
//	glScalef(2.0, 3.0, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//
//	// call the robotic body draw function here
//
//	glPushMatrix();
//	drawArm();
//	glPopMatrix();
//
//	glPushMatrix();
//	glRotatef(180.0, 0.0, 1.0, 0.0);
//	drawArm();
//	glPopMatrix();
//
//
//	glPushMatrix();
//	drawLeg();
//	glPopMatrix();
//
//	glPushMatrix();
//	drawLeg2();
//	glPopMatrix();
//
//	glPopMatrix();
//	glutSwapBuffers();
//}
//
//void specialKeys(int key, int x, int y)
//{
//	switch (key)
//	{
//	case GLUT_KEY_LEFT: Left(); break;          
//	case GLUT_KEY_RIGHT: Right(); break;
//	case GLUT_KEY_UP:    Up(); break;
//	case GLUT_KEY_DOWN:  Down(); break;
//	}
//
//	glutPostRedisplay();
//}
//
//
//
////void reshape(int w, int h)
////{
////	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
////	glMatrixMode(GL_PROJECTION);
////	glLoadIdentity();
////	gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
////	glMatrixMode(GL_MODELVIEW);
////	glLoadIdentity();
////	glTranslatef(0.0, 0.0, -5.0);
////}
//
//void keyboard(unsigned char key, int x, int y)
//{
//	// List all youe keyboard keys from assignment two her for body movement
//	switch (key)
//	{
//	case 'f':
//		moveForward();
//		glutPostRedisplay();
//		break;
//	case 'b':
//		moveBack();
//		glutPostRedisplay();
//		break;
//
//	case 's':
//		if (shoulder <= 120 || shoulder <= 120)
//		{
//			shoulder = (shoulder + 5) % 360;
//		}
//		glutPostRedisplay();
//		break;
//	case 'S':
//		if (shoulder >= 60)
//		{
//			shoulder = (shoulder - 5) % 360;
//		}
//		glutPostRedisplay();
//		break;
//
//	case 'd':
//		if (shoulderX <= 90)
//		{
//			shoulderX = (shoulderX + 5) % 360;
//		}
//		glutPostRedisplay();
//		break;
//	case 'D':
//		if (shoulderX >= 60)
//		{
//			shoulderX = (shoulderX - 5) % 360;
//		}
//		glutPostRedisplay();
//		break;
//
//
//	case 'e':
//		if (elbow <= 80 || elbow <= -80)
//		{
//			elbow = (elbow + 5) % 360;
//		}
//		glutPostRedisplay();
//		break;
//	case 'E':
//		if (elbow >= -110)
//		{
//			elbow = (elbow - 5) % 360;
//		}
//		glutPostRedisplay();
//		break;
//
//
//	case 'm':
//		if (legBase <= 70 || legBase <= -70)
//		{
//			legBase = (legBase + 5) % 360;
//		}
//		glutPostRedisplay();
//		break;
//	case 'M':
//		if (legBase >= -70)
//		{
//			legBase = (legBase - 5) % 360;
//		}
//		glutPostRedisplay();
//		break;
//	case 'k':
//		if (legUp <= 70 || legUp <= -70)
//		{
//			legUp = (legUp + 5) % 360;
//		}
//		glutPostRedisplay();
//		break;
//	case 'K':
//		if (legUp >= -15)
//		{
//			legUp = (legUp - 5) % 360;
//		}
//		glutPostRedisplay();
//		break;
//
//	case 'r':
//		if (legX <= 90 || legX <= -90)
//		{
//			legX = (legX + 5) % 360;
//		}
//		glutPostRedisplay();
//		break;
//	case 'R':
//		if (legX >= -5)
//		{
//			legX = (legX - 5) % 360;
//		}
//		glutPostRedisplay();
//		break;
//	case 'l':
//		if (leg2X <= 5 || leg2X <= -5)
//		{
//			leg2X = (leg2X + 5) % 360;
//		}
//		glutPostRedisplay();
//		break;
//	case 'L':
//		if (leg2X >= -90)
//		{
//			leg2X = (leg2X - 5) % 360;
//		}
//		glutPostRedisplay();
//		break;
//
//	case 'h':
//		if (legBase2 <= 70 || legBase2 <= -70)
//		{
//			legBase2 = (legBase2 + 5) % 360;
//		}
//		glutPostRedisplay();
//		break;
//	case 'H':
//		if (legBase2 >= -70)
//		{
//			legBase2 = (legBase2 - 5) % 360;
//		}
//		glutPostRedisplay();
//		break;
//	case 'j':
//		if (legUp2 <= 70 || legUp2 <= -70)
//		{
//			legUp2 = (legUp2 + 5) % 360;
//		}
//		glutPostRedisplay();
//		break;
//	case 'J':
//		if (legUp2 >= -15)
//		{
//			legUp2 = (legUp2 - 5) % 360;
//		}
//		glutPostRedisplay();
//		break;
//
//
//	case 'a':
//		bodyBox = (bodyBox - 5) % 360;
//		glutPostRedisplay();
//		break;
//
//	case 'A':
//		bodyBox = (bodyBox + 5) % 360;
//		glutPostRedisplay();
//		break;
//
//	case 'w':
//		wholeShape = (wholeShape - 5) % 360;
//		glutPostRedisplay();
//		break;
//
//	case 'W':
//		wholeShape = (wholeShape + 5) % 360;
//		glutPostRedisplay();
//		break;
//
//	default:
//		break;
//	}
//}
//
//static void mouse(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON) {
//		if (state == GLUT_DOWN) {
//			moving = 1;
//			startx = x;
//			starty = y;
//		}
//		if (state == GLUT_UP) {
//			moving = 0;
//		}
//	}
//}
//
//
//static void motion(int x, int y)
//{
//	if (moving) {
//		angle = angle + (x - startx);
//		angle2 = angle2 + (y - starty);
//		startx = x;
//		starty = y;
//		glutPostRedisplay();
//	}
//}
//
//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
//
//	glutInitWindowSize(1000, 1000);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("body");
//	init();
//	glutMouseFunc(mouse);
//	glutMotionFunc(motion);
//	glutDisplayFunc(display);
//	//glutReshapeFunc(reshape);
//	glutSpecialFunc(specialKeys);
//	glutKeyboardFunc(keyboard);
//
//	glutMainLoop();
//	return 0;
//}