/*Exercícios
1- Explorando a Rasterização de Linhas Nativa
Objetivo: Usar as primitivas de linha do OpenGL e modificar o estado do
rasterizador para alterar como os pixels são desenhados.
- Crie uma janela básica usando GLUT.
- Dentro da função de desenho (display), utilize a primitiva GL_LINES para
desenhar o contorno de uma nave espacial simples (ou um controle de
videogame) usando apenas retas conectadas.
- Use a função glLineWidth(5.0f); antes do glBegin e observe o que
acontece com a espessura.
- Ative o modo de linha tracejada usando glEnable(GL_LINE_STIPPLE); e
configure o padrão com glLineStipple(1, 0x00FF);. Rode o programa
e veja como o OpenGL "quebra" a rasterização da reta.
2- Preenchimento automático e Interpolação de Cores.
Objetivo: Usar polígonos preenchidos e observar como a GPU interpola cores
nativamente (Gouraud Shading), substituindo a necessidade de um algoritmo de
Flood Fill manual.
- Desenhe um triângulo grande ocupando a maior parte da tela usando a
primitiva GL_TRIANGLES.-
- Para cada vértice (glVertex2f), declare uma cor diferente antes dele
usando glColor3f.
● Vértice 1: Vermelho (1.0, 0.0, 0.0)
● Vértice 2: Verde (0.0, 1.0, 0.0)
● Vértice 3: Azul (0.0, 0.0, 1.0)
- Rode o programa. Observe o gradiente perfeito gerado pelo rasterizador.
- Adicione o comando glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
no início do programa. O que aconteceu com o preenchimento? A tela deve
mostrar apenas as arestas do triângulo, revelando o "esqueleto" do polígono.*/

#include <GL/glut.h>
#include <stdlib.h>

// --- Função de Desenho ---
void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);

    
    // 2. Desenha o Triângulo
    glPushMatrix();
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(5.0f); 

        
        glBegin(GL_TRIANGLES);

        // Vértice 1: Esquerda-Inferior (Cor Vermelha)
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(-0.5f, -0.5f);
        
            // Vértice 2: Direita-Inferior (Cor Verde)
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex2f(0.5f, -0.5f);
        
            // Vértice 3: Topo-Centro (Cor Azul)
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2f(0.0f, 0.5f);
        
            // 3. Finaliza o desenho do triângulo
        glEnd();

        glDisable(GL_LINE_STIPPLE);
    glPopMatrix();

    glutSwapBuffers();
}


// --- Função Principal ---
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("- Preenchimento automatico e Interpolacao de Cores.");
    
    glutDisplayFunc(desenhaCena);
        
    glutMainLoop();
    return 0;
}
