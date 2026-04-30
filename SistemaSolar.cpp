#include <GL/glut.h>
#include <math.h>

//Relógio Global
float tempoGlobal = 0.0f;

GLfloat luzBranca[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat luzAmbienteFraca[] = { 0.2f, 0.2f, 0.2f, 1.0f };

// Função que calcula o ângulo exato para qualquer planeta
float calculaAnguloPlaneta(float velocidade) {
    // Multiplica o tempo pela velocidade do planeta
    float anguloReal = tempoGlobal * velocidade;

    // Divide o valor por 360 e retorna o resto, impedindo que chegue em 360
    return fmod(anguloReal, 360.0f);
}

void configuraLuz() {
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbienteFraca);
 
   // LÂMPADA 0: O Sol irradiando luz (Luz Pontual) ---
   glEnable(GL_LIGHT0);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, luzBranca);
   // Posição no centro
   GLfloat posPontual[] = { 0.0f, 0.0f, 0.0f, 1.0f };
   glLightfv(GL_LIGHT0, GL_POSITION, posPontual);


   // LÂMPADA 1: Iluminação do Sol (Luz Pontual) ---
   glEnable(GL_LIGHT1);
   glLightfv(GL_LIGHT1, GL_DIFFUSE, luzBranca);
   // Posição pouco a frente do Sol, iluminando o próprio Sol
   GLfloat posPontual1[] = { 0.0f, 1.0f, 2.0f, 1.0f };
   glLightfv(GL_LIGHT1, GL_POSITION, posPontual1);
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();
  
   gluLookAt(0.0, 4.0, 12.0,
      0.0, 0.0, 0.0,
      0.0, 1.0, 0.0);
   configuraLuz();
  
   // 1. Sol (No centro de tudo)
   glPushMatrix();
         
   // Como o Sol agora reage à luz direcional, a cor dele vai sofrer sombreamento
   glColor3f(1.0f, 0.75f, 0); // Amarelo Alaranjado
   glutSolidSphere(1.0f, 32, 32);

   glPopMatrix();


   // 2. Mercúrio
   glPushMatrix();
      // Orbita do Sol
      glRotatef(calculaAnguloPlaneta(3.0f), 0.0f, 1.0f, 0.0f); 
      glTranslatef(2.0f, 0.0f, 0.0f);

      // Desenha Mercúrio
      glColor3f(1.0f, 1.0f, 1.0f); // Branco
      glutSolidSphere(0.1f, 32, 32);

   glPopMatrix();

   // 3. Vênus
   glPushMatrix();
      // Orbita do Sol
      glRotatef(calculaAnguloPlaneta(2.0f), 0.0f, 1.0f, 0.0f); 
      glTranslatef(3.5f, 0.0f, 0.0f);

      // Desenha Vênus
      glColor3f(1.0f, 0.5f, 0); // Vermelho Alaranjado
      glutSolidSphere(0.3f, 32, 32);

   glPopMatrix();


   // 4. Terra
   glPushMatrix();
    
      // Orbita do Sol
      glRotatef(calculaAnguloPlaneta(1.5f), 0.0f, 1.0f, 0.0f); 
      glTranslatef(5.0f, 0.0f, 0.0f);
      
      // Desenha a Terra
      glColor3f(0.0f, 0.5f, 1.0f); // Azul pouco Esverdeado
      glutSolidSphere(0.4f, 32, 32);

      // 4.1. Lua
      glPushMatrix();

         // Orbita da Terra
         glRotatef(calculaAnguloPlaneta(5.0f), 0.0f, 1.0f, 0.0f); 
         glTranslatef(0.8f, 0.0f, 0.0f); 
         
         // Desenha a Lua
         glColor3f(0.7f, 0.7f, 0.7f); // Cinza
         glutSolidSphere(0.15f, 32, 32);
         
      glPopMatrix();

   glPopMatrix();

   // 5. Marte
   glPushMatrix();
      // Orbita do Sol
      glRotatef(calculaAnguloPlaneta(1.0f), 0.0f, 1.0f, 0.0f); 
      glTranslatef(6.5f, 0.0f, 0.0f);

      // Desenha Marte
      glColor3f(0.3f, 0.0f, 0.0f); // Vermelho
      glutSolidSphere(0.2f, 32, 32);

   glPopMatrix();

   glutSwapBuffers();
}

   void inicializa() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL); // Inicializa as cores em materiais difusos
   }
   void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
   }


   void atualizaAnimacao(int value) {
      tempoGlobal += 1.0f; // O tempo avança 1 passo por frame
      
      glutPostRedisplay(); 
      glutTimerFunc(16, atualizaAnimacao, 0); 
  }

  int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(800, 800);
   glutCreateWindow("Sistema Solar");
  
   inicializa();
  
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
  
   glutTimerFunc(16, atualizaAnimacao, 0); 
  
   glutMainLoop();
   return 0;
}
