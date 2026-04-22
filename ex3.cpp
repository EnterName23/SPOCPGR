#include <GL/glut.h>
#include <stdlib.h> 

// Variáveis Globais
float jogadorX = 0.0f; 
float jogadorY = 0.0f; 
float velocidade = 0.05f; 
float tamanhoDoQuadrado = 0.5f; 

// Cores variáveis
float R = 1.0f;
float G = 1.0f;
float B = 1.0f;

// Função de Desenho
void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT); 

    glPushMatrix(); 
    glTranslatef(jogadorX, jogadorY, 0.0f); 
    
    glBegin(GL_QUADS); 
        // Aplicando a cor baseada nas variáveis globais
        glColor3f(R, G, B); 

        glVertex2f(-tamanhoDoQuadrado,  tamanhoDoQuadrado); 
        glVertex2f( tamanhoDoQuadrado,  tamanhoDoQuadrado); 
        glVertex2f( tamanhoDoQuadrado, -tamanhoDoQuadrado); 
        glVertex2f(-tamanhoDoQuadrado, -tamanhoDoQuadrado); 
    glEnd(); 

    glPopMatrix(); 

    glutSwapBuffers(); 
}

// Função Única de Teclado
void teclado(unsigned char key, int x, int y) {

    switch (key) {
        case '1': // Vermelho
            R = 1.0f; G = 0.0f; B = 0.0f;
            break;
        case '2': // Verde
            R = 0.0f; G = 1.0f; B = 0.0f;
            break;
        case '3': // Azul
            R = 0.0f; G = 0.0f; B = 1.0f;
            break;

        case 'w': case 'W':
            if (jogadorY + velocidade + tamanhoDoQuadrado <= 1.0f) {
                jogadorY += velocidade;
            }
            break;
        case 's': case 'S':
            if (jogadorY - velocidade - tamanhoDoQuadrado >= -1.0f) {
                jogadorY -= velocidade;
            }
            break;
        case 'a': case 'A':
            if (jogadorX - velocidade - tamanhoDoQuadrado >= -1.0f) {
                jogadorX -= velocidade;
            }
            break;
        case 'd': case 'D':
            if (jogadorX + velocidade + tamanhoDoQuadrado <= 1.0f) {
                jogadorX += velocidade;
            }
            break;

        case 27: // ESC
            exit(0); 
            break;
    }
    
    // Essencial: avisa o OpenGL para redesenhar a tela com a nova cor/posição
    glutPostRedisplay(); 
}

// Função Principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600); 
    glutCreateWindow("EXERCICIO 3");

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 

    glutDisplayFunc(desenhaCena); 
    glutKeyboardFunc(teclado); 
    
    glutMainLoop(); 
    return 0;
}
