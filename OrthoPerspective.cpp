#include <GL/glut.h>

int larguraJanela = 800;
int alturaJanela = 600;

void configuraProjecaoOrtografica() {
    // 1. Avisa o OpenGL que vamos alterar a matriz de projeção (a lente da câmera)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // Reseta a matriz

    // 2. Define a projeção Ortográfica
    // Parâmetros: esquerda, direita, baixo, cima, perto (near), longe (far)
    // Se a janela tiver 800x600, isso mapeia os pixels diretamente
    glOrtho(0.0, larguraJanela, 0.0, alturaJanela, -1.0, 1.0); 

    // 3. Volta para a matriz de Modelagem/Visualização (onde desenhamos os objetos)
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void configuraProjecaoPerspectiva() {
    // 1. Avisa o OpenGL que vamos alterar a matriz de projeção
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // Reseta a matriz

    // Calcula a proporção da tela (Aspect Ratio) para a imagem não ficar esticada
    float proporcao = (float)larguraJanela / (float)alturaJanela;

    // 2. Define a projeção em Perspectiva (requer a biblioteca GLU)
    // Parâmetros: 
    // - FOV (Campo de Visão em graus, ex: 45.0)
    // - Aspect Ratio (largura / altura)
    // - Near (distância mínima de corte, ex: 0.1) NUNCA USE 0.0 AQUI!
    // - Far (distância máxima de corte, ex: 100.0)
    gluPerspective(45.0f, proporcao, 0.1f, 100.0f);

    // 3. Volta para a matriz de Modelagem
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Na perspectiva, a câmera nasce no ponto (0,0,0). 
    // Precisamos recuar a câmera (mover no eixo Z) para ver os objetos
    glTranslatef(0.0f, 0.0f, -5.0f); 
}