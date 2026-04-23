#include <GL/glut.h>
#include <math.h> // Necessário para a função sin()

// Variável para controlar a animação do pulso
float tempo = 0.0f;

// Função de Desenho
void desenhaCena() {
    // Limpa a tela
    glClear(GL_COLOR_BUFFER_BIT); 

    // Salva a matriz atual
    glPushMatrix(); 

    // Calcula o fator de escala usando a função seno
    // O seno varia de -1 a 1. Queremos que a escala varie, por exemplo, de 0.5 a 1.5.
    // Assim, 1.0 (tamanho original) + 0.5 * (valor entre -1 e 1) resulta nesse intervalo.
    float fatorEscala = 1.0f + 0.5f * sin(tempo);

    // Aplica a escala
    // Parâmetros: (escala X, escala Y, escala Z)
    // Em 2D, mantemos o Z como 1.0f (sem alteração de escala na profundidade)
    glScalef(fatorEscala, fatorEscala, 1.0f); 

    // Desenha um triângulo centralizado
    glBegin(GL_TRIANGLES); 
        glColor3f(0.2f, 0.8f, 0.2f); // Cor verde
        glVertex2f(-0.4f, -0.4f); // Canto inferior esquerdo
        glVertex2f( 0.4f, -0.4f); // Canto inferior direito
        glVertex2f( 0.0f,  0.4f); // Topo central
    glEnd(); 

    // Restaura a matriz salva
    glPopMatrix(); 

    // Troca os buffers para mostrar o desenho na tela
    glutSwapBuffers(); 
}

// Função de atualização (Timer) para criar a animação
void atualizaAnimacao(int value) {
    // Incrementa a variável de tempo para o cálculo do seno
    tempo += 0.05f; 

    // Avisa a GLUT que a tela precisa ser redesenhada
    glutPostRedisplay(); 

    // Re-registra o timer (~60 FPS)
    glutTimerFunc(16, atualizaAnimacao, 0); 
}

// Função Principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600); 
    glutCreateWindow("Exemplo de Escala - Triangulo Pulsando");

    // Define o sistema de coordenadas da janela
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 

    // Registra a função de desenho
    glutDisplayFunc(desenhaCena); 

    // Inicia o timer da animação
    glutTimerFunc(16, atualizaAnimacao, 0); 

    glutMainLoop(); 
    return 0;
}