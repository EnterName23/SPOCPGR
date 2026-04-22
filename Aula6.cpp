/*
Tarefa: Observar visualmente a diferença entre as
técnicas de interpolação.
➢ Passos:
○ 1. No C++, desenhe uma glutSolidSphere(1.0, 16, 16) (esfera de
baixa resolução com poucos triângulos).
○ 2. Configure a API com glShadeModel(GL_FLAT); e re-compile. A
esfera parecerá uma bola de discoteca facetada.
*/

#include <GL/glut.h>

// Configura a iluminação inicial
void inicializaSombra() {
 // Habilita o motor de iluminação do OpenGL e o Z-Buffer (teste de profundidade)
 glEnable(GL_LIGHTING);
 glEnable(GL_DEPTH_TEST);
 // Habilita a Lâmpada 0
 glEnable(GL_LIGHT0);

 glShadeModel(GL_FLAT);
}

   void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
   
    // Move a câmera um pouco para trás
    glTranslatef(0.0f, 0.0f, -5.0f);
      
    // Desenha a Esfera (função nativa do GLUT que já calcula as Normais para nós)
    glutSolidSphere(1.0, 16, 16);
    glutSwapBuffers();
   }


   void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
   }

   int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Aula 6 - Esfera de Luz Multifacetada");

    inicializaSombra();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
   }
