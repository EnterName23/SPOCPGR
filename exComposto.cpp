/* 1- Controle de um Quadrado com Teclado e Clique do Mouse
Objetivo:
-Criar um programa em C++ com OpenGL onde:
-Um quadrado se move pela tela com as teclas W, A, S, D.
-Ao clicar com o botão esquerdo do mouse, o quadrado muda de cor para vermelho.
-Ao clicar com o botão direito do mouse, o quadrado volta à cor original (azul).
-Utilize GLUT_LEFT_BUTTON e GLUT_RIGHT_BUTTON e
glutPostRedisplay();
2- Comente as funções keyboard() e mouse() explicando o que cada linha faz.
3- Adapte o código para que:
-O quadrado aumente de tamanho com a tecla +.
-Diminua com a tecla -.
4- Faça com que o clique do botão do meio reinicie a posição do quadrado para (0,0).*/

#include <GL/glut.h>
#include <stdlib.h> 

// Variáveis Globais
float jogadorX = 0.0f; 
float jogadorY = 0.0f; 
float velocidade = 0.1f; 
float tamanhoDoQuadrado = 0.2f; 

// Cores variáveis
float R = 0.0f;
float G = 0.0f;
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
    // Permite que o usuário mova o objeto por meio das teclas WASD,
    // em que o objeto é translocado através da soma de sua posição + velocidade.
    // Além disso, também permite sair do site e aumentar ou reduzir o tamanho
    // objeto através de + e -.
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
        case '+': // Aumenta o Tamanho do Quadrado
            tamanhoDoQuadrado *= 1.1; 
            break;
        case '-': // Reduz o Tamanho do Quadrado
            tamanhoDoQuadrado /= 1.1; 
            break;
        case 27:  // Sair do programa
            exit(0); 
            break;
    }
    glutPostRedisplay(); // Atualiza a tela após mover

}

// Teclado Especial
void tecladoEspecial(int key, int x, int y) {
    // Permite que o usuário mova o objeto por meio das setas,
    // em que o objeto é translocado através da soma de sua posição + velocidade
    //Além disso, também permite sair do site 
    switch (key) {
        case GLUT_KEY_UP:
                jogadorY += velocidade; 
            break;
        case GLUT_KEY_DOWN:
                jogadorY -= velocidade;
            break;
        case GLUT_KEY_LEFT:
                jogadorX -= velocidade;
            break;
        case GLUT_KEY_RIGHT:
                jogadorX += velocidade;
            break;
    }
    glutPostRedisplay(); // Atualiza a tela após mover
}
void mouse(int key, int state, int x, int y) {
    // Permite a alteração das cores originais através de uma atualização das
    // variáveis R, G e B.
    switch (key) {
        case GLUT_LEFT_BUTTON: // Vermelho
            R = 1.0f; G = 0.0f; B = 0.0f;
            break;
        case GLUT_RIGHT_BUTTON: // Azul
            R = 0.0f; G = 0.0f; B = 1.0f;
            break;
        case GLUT_MIDDLE_BUTTON: // Retorna a posição original
            jogadorX = 0.0f; jogadorY = 0.0f;

    }
    glutPostRedisplay(); // Atualiza a tela trocar de cor
}
// --- Função Principal ---
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600); 
    glutCreateWindow("EXERCICIO 1, 2, 3 e 4");

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 

    // Registrando os Callbacks
    glutDisplayFunc(desenhaCena); 
    glutKeyboardFunc(teclado);            
    glutSpecialFunc(tecladoEspecial);
    glutMouseFunc(mouse);
    
    glutMainLoop(); 
    return 0;
}
