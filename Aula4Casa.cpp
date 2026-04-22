// Faça uma casa

#include <GL/glut.h>

void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.7f, 0.0f); 
    glVertex2f(0.6f, -0.5f);    
    glVertex2f(0.6f, 0.3f);   
    glVertex2f(-0.6f, 0.3f);    
    glVertex2f(-0.6f, -0.5f);    
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.7f, 0.0f, 0.0f); 
    glVertex2f(0.6f, 0.3f);   
    glVertex2f(0.0f, 0.7f);    
    glVertex2f(-0.6f, 0.3f);    
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.6f); 
    glVertex2f(-0.25f, -0.5f);    
    glVertex2f(-0.25f, -0.25f);   
    glVertex2f(-0.45f, -0.25f);    
    glVertex2f(-0.45f, -0.5f);    
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.65f, 0.4f); 
    glVertex2f(0.2f, -0.25f);    
    glVertex2f(0.2f, 0.0f);   
    glVertex2f(0.5f, 0.0f);    
    glVertex2f(0.5f, -0.25f);    
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    // Inicializa a biblioteca GLUT
    glutInit(&argc, argv);

    // Configura o modo do display: Single Buffer (desenho direto) e cores RGB
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Configura o tamanho e a posição inicial da janela
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);

    // Cria a janela e define o título
    glutCreateWindow("Quadrado Clássico com GLUT");

    // Registra a função "desenhaCena" para ser chamada sempre que a tela precisar ser atualizada
    glutDisplayFunc(desenhaCena);

    // Entrega o controle do programa para o GLUT (inicia o loop infinito)
    glutMainLoop();

    return 0;
}
