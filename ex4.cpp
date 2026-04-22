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
        glColor3f(R, G, B); 
        glVertex2f(-tamanhoDoQuadrado,  tamanhoDoQuadrado); 
        glVertex2f( tamanhoDoQuadrado,  tamanhoDoQuadrado); 
        glVertex2f( tamanhoDoQuadrado, -tamanhoDoQuadrado); 
        glVertex2f(-tamanhoDoQuadrado, -tamanhoDoQuadrado); 
    glEnd(); 

    glPopMatrix(); 

    glutSwapBuffers(); 
}

// Teclado Normal
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
        case 27: // ESC
            exit(0); 
            break;
    }
    glutPostRedisplay(); // Atualiza a tela após mudar a cor
}

// Teclado Especial
void tecladoEspecial(int key, int x, int y) {

    switch (key) {
        case GLUT_KEY_UP:
            if (jogadorY + velocidade + tamanhoDoQuadrado <= 1.0f) {
                jogadorY += velocidade; 
            }
            break;
        case GLUT_KEY_DOWN:
            if (jogadorY - velocidade - tamanhoDoQuadrado >= -1.0f) {
                jogadorY -= velocidade;
            }
            break;
        case GLUT_KEY_LEFT:
            if (jogadorX - velocidade - tamanhoDoQuadrado >= -1.0f) {
                jogadorX -= velocidade;
            }
            break;
        case GLUT_KEY_RIGHT:
            if (jogadorX + velocidade + tamanhoDoQuadrado <= 1.0f) {
                jogadorX += velocidade;
            }
            break;
    }
    glutPostRedisplay(); // Atualiza a tela após mover
}

// --- Função Principal ---
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600); 
    glutCreateWindow("EXERCICIO 4");

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 

    // Registrando os Callbacks
    glutDisplayFunc(desenhaCena); 
    glutKeyboardFunc(teclado);            
    glutSpecialFunc(tecladoEspecial);      
    
    glutMainLoop(); 
    return 0;
}
