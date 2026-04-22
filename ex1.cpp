#include <GL/glut.h>
#include <stdlib.h> 
#include <math.h>

// Variáveis Globais 
float jogadorX = 0.0f;
float jogadorY = 0.0f;
float velocidade = 0.05f; 
float raio = 0.5f;

// Função de Desenho
void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT); 

    glPushMatrix(); 
    glTranslatef(jogadorX, jogadorY, 0.0f); 
    
    glBegin(GL_TRIANGLE_FAN); 
        glColor3f(0.8f, 0.5f, 0.8f); 
        glVertex2f(0.0f, 0.0f); 

        int numVertices = 100; 
        for (int i = 0; i <= numVertices; i++) {
            float angulo = 2 * M_PI * i / numVertices; 
            float x = raio * cos(angulo); 
            float y = raio * sin(angulo); 
            glVertex2f(x, y); 
        }    
    glEnd(); 
    glPopMatrix(); 

    glutSwapBuffers(); 
}

// Função Única de Teclado
void teclado(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
        case 'W':
            jogadorY += velocidade; 
            break;
        case 's':
        case 'S':
            jogadorY -= velocidade; 
            break;
        case 'a':
        case 'A':
            jogadorX -= velocidade; 
            break;
        case 'd':
        case 'D':
            jogadorX += velocidade; 
            break;
        // Sair do programa
        case 27:
            exit(0); 
            break;
    }
    glutPostRedisplay(); 
}

// Função Principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600); 
    glutCreateWindow("EXERCICIO 1");

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 

    // Registrando os Callbacks
    glutDisplayFunc(desenhaCena); 
    
    glutKeyboardFunc(teclado); 
    
    glutMainLoop(); 
    return 0;
}
