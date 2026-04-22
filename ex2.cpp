#include <GL/glut.h>
#include <stdlib.h> 
#include <math.h>

// Variáveis Globais
float jogadorX = 0.0f; // Posição X do CENTRO do quadrado
float jogadorY = 0.0f; // Posição Y do CENTRO do quadrado
float velocidade = 0.1f; 

float tamanhoDoQuadrado = 0.5f; 

// Função de Desenho
void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT); 

    glPushMatrix(); 
    glTranslatef(jogadorX, jogadorY, 0.0f); 
    
    glBegin(GL_QUADS); 
        glColor3f(0.0f, 1.0f, 1.0f); 

        glVertex2f(-tamanhoDoQuadrado,  tamanhoDoQuadrado); // Canto Superior Esquerdo
        glVertex2f( tamanhoDoQuadrado,  tamanhoDoQuadrado); // Canto Superior Direito
        glVertex2f( tamanhoDoQuadrado, -tamanhoDoQuadrado); // Canto Inferior Direito
        glVertex2f(-tamanhoDoQuadrado, -tamanhoDoQuadrado); // Canto Inferior Esquerdo
    glEnd(); 

    glPopMatrix(); 

    glutSwapBuffers(); 
}

// Função Única de Teclado
void teclado(unsigned char key, int x, int y) {
    // Variáveis auxiliares para calcular a próxima posição ANTES de aplicar
    switch (key) {


        // MOVIMENTO PARA CIMA
        case 'w':
        case 'W':
            if (jogadorY + velocidade + tamanhoDoQuadrado <= 1.0f) {
                jogadorY += velocidade;
            }
            break;

        // MOVIMENTO PARA BAIXO
        case 's':
        case 'S':
            if (jogadorY - velocidade - tamanhoDoQuadrado >= -1.0f) {
                jogadorY -= velocidade;
            }
            break;

        // MOVIMENTO PARA ESQUERDA
        case 'a':
        case 'A':
            if (jogadorX - velocidade - tamanhoDoQuadrado >= -1.0f) {
                jogadorX -= velocidade;
            }
            break;

        // MOVIMENTO PARA DIREITA
        case 'd':
        case 'D':
            if (jogadorX + velocidade + tamanhoDoQuadrado <= 1.0f) {
                jogadorX += velocidade;
            }
            break;

        // Sair do programa
        case 27: // ESC
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
    glutCreateWindow("EXERCICIO 2");

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 

    glutDisplayFunc(desenhaCena); 
    glutKeyboardFunc(teclado); 
    
    glutMainLoop(); 
    return 0;
}
