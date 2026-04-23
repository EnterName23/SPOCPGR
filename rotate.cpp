#include <GL/glut.h>

// Variável global para controlar o ângulo de rotação
float angulo = 0.0f;

// Função de Desenho
void desenhaCena() {
    // Limpa a tela
    glClear(GL_COLOR_BUFFER_BIT); 

    // Salva a matriz atual (para não acumular rotações infinitamente)
    glPushMatrix(); 

    // Aplica a rotação
    // Parâmetros: (ângulo em graus, eixo X, eixo Y, eixo Z)
    // Para 2D, giramos ao redor do eixo Z (0, 0, 1)
    glRotatef(angulo, 0.0f, 0.0f, 1.0f); 

    // Desenha um quadrado centralizado
    glBegin(GL_QUADS); 
        glColor3f(0.0f, 0.5f, 1.0f); // Cor azul
        glVertex2f(-0.4f, -0.4f); // Canto inferior esquerdo
        glVertex2f( 0.4f, -0.4f); // Canto inferior direito
        glVertex2f( 0.4f,  0.4f); // Canto superior direito
        glVertex2f(-0.4f,  0.4f); // Canto superior esquerdo
    glEnd(); 

    // Restaura a matriz salva
    glPopMatrix(); 

    // Troca os buffers para mostrar o desenho na tela
    glutSwapBuffers(); 
}

// Função de atualização (Timer) para criar a animação
void atualizaAnimacao(int value) {
    // Incrementa o ângulo em 2 graus por quadro
    angulo += 2.0f; 
    
    // Mantém o ângulo entre 0 e 360 para evitar números gigantes na memória
    if (angulo > 360.0f) {
        angulo -= 360.0f;
    }
    glutPostRedisplay(); 

    glutTimerFunc(16, atualizaAnimacao, 0); 
}

// Função Principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600); 
    glutCreateWindow("Exemplo de Rotacao - Quadrado Girando");


    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 


    glutDisplayFunc(desenhaCena); 

    // Inicia o timer da animação (chama 'atualizaAnimacao' após 16ms)
    glutTimerFunc(16, atualizaAnimacao, 0); 

    glutMainLoop(); 
    return 0;
}