#include <GL/glut.h>
#include <stdlib.h> 

// Variáveis Globais
// Quadrado 1 (WASD)
float quad1X = -0.5f; 
float quad1Y =  0.0f; 

// Quadrado 2 (IJKL)
float quad2X =  0.5f; 
float quad2Y =  0.0f; 

float velocidade = 0.05f; 
float tamanhoDoQuadrado = 0.2f;

// Função Genérica de Desenho
void drawSquare(float x, float y, float r, float g, float b) {
    glPushMatrix(); 
    glTranslatef(x, y, 0.0f); // Move para a posição X e Y passada como parâmetro
    
    glBegin(GL_QUADS); 
        glColor3f(r, g, b); // Aplica a cor passada como parâmetro
        glVertex2f(-tamanhoDoQuadrado,  tamanhoDoQuadrado); 
        glVertex2f( tamanhoDoQuadrado,  tamanhoDoQuadrado); 
        glVertex2f( tamanhoDoQuadrado, -tamanhoDoQuadrado); 
        glVertex2f(-tamanhoDoQuadrado, -tamanhoDoQuadrado); 
    glEnd(); 

    glPopMatrix(); 
}

// Função Principal de Desenho da Cena
void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT); 

    drawSquare(quad1X, quad1Y, 1.0f, 1.0f, 1.0f);
    drawSquare(quad2X, quad2Y, 0.2f, 0.2f, 0.2f);

    glutSwapBuffers(); 
}

// Função Única de Teclado (Letras ASCII)
void teclado(unsigned char key, int x, int y) {
    switch (key) {
        // Controle Quadrado 1
        case 'w': case 'W':
            if (quad1Y + velocidade + tamanhoDoQuadrado <= 1.0f) quad1Y += velocidade;
            break;
        case 's': case 'S':
            if (quad1Y - velocidade - tamanhoDoQuadrado >= -1.0f) quad1Y -= velocidade;
            break;
        case 'a': case 'A':
            if (quad1X - velocidade - tamanhoDoQuadrado >= -1.0f) quad1X -= velocidade;
            break;
        case 'd': case 'D':
            if (quad1X + velocidade + tamanhoDoQuadrado <= 1.0f) quad1X += velocidade;
            break;

        // Controle Quadrado 2 
        case 'i': case 'I':
            if (quad2Y + velocidade + tamanhoDoQuadrado <= 1.0f) quad2Y += velocidade;
            break;
        case 'k': case 'K':
            if (quad2Y - velocidade - tamanhoDoQuadrado >= -1.0f) quad2Y -= velocidade;
            break;
        case 'j': case 'J':
            if (quad2X - velocidade - tamanhoDoQuadrado >= -1.0f) quad2X -= velocidade;
            break;
        case 'l': case 'L':
            if (quad2X + velocidade + tamanhoDoQuadrado <= 1.0f) quad2X += velocidade;
            break;

        // Sair
        case 27: // ESC
            exit(0); 
            break;
    }
    
    glutPostRedisplay(); // Atualiza a tela após mover qualquer um deles
}

// Função Principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600); 
    glutCreateWindow("EXERCICIO 5");

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 

    glutDisplayFunc(desenhaCena); 
    glutKeyboardFunc(teclado); // Apenas uma função de teclado para todas as letras
    
    glutMainLoop(); 
    return 0;
}
