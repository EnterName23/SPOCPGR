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

/*
    OpenGL de nave Alienígena que se move por meio das setas e solta um "Raio de Abdução"
    ao apertar espaço
*/
float velocidadeRaioY = -0.35f;

float jogadorX = 0.0f;
float jogadorY = 0.25f;
float velocidade = 0.05f;
bool RaioLaser = false;

// --- Função de Desenho ---
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); 

    // 2. Desenha a Nave
    glPushMatrix();
        glTranslatef(jogadorX, jogadorY, 0.0f); // Move para a posição do jogador
        
        glLineWidth(5.0f); 
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x00FF); 

        glColor3f(0.7f, 0.7f, 0.7f); 
        glBegin(GL_LINES);

            //Corpo
            glVertex2f(-0.5f, 0.1f); 
            glVertex2f(-0.5f, -0.1f);  

            glVertex2f(0.5f, 0.1f); 
            glVertex2f(0.5f, -0.1f);

            glVertex2f(-0.5f, 0.1f); 
            glVertex2f(-0.25f, 0.2f);

            glVertex2f(0.5f, 0.1f); 
            glVertex2f(0.25f, 0.2f);

            glVertex2f(-0.5f, -0.1f); 
            glVertex2f(-0.25f, -0.2f);

            glVertex2f(0.5f, -0.1f); 
            glVertex2f(0.25f, -0.2f);

            glVertex2f(-0.25f, 0.2f); 
            glVertex2f(0.25f, 0.2f);

            glVertex2f(-0.25f, -0.2f); 
            glVertex2f(0.25f,-0.2f);

            //Cápsula
            glColor3f(0.0f, 0.6f, 1.0f); 
            glVertex2f(0.10f, 0.7f); 
            glVertex2f(-0.10f, 0.7f);

            glVertex2f(0.15f, 0.5f); 
            glVertex2f(0.15f, 0.2f);

            glVertex2f(-0.15f, 0.5f); 
            glVertex2f(-0.15f, 0.2f);

            glVertex2f(0.10f, 0.7f); 
            glVertex2f(0.15f, 0.5f);

            glVertex2f(-0.10f, 0.7f); 
            glVertex2f(-0.15f, 0.5f);

            //Luzes
            glColor3f(0.8f, 0.0f, 0.0f); 
            glVertex2f(-0.5f, -0.0f); 
            glVertex2f(0.5f,-0.0f);
            glVertex2f(-0.5f, -0.05f); 
            glVertex2f(0.5f,-0.05f);
            glVertex2f(-0.5f, 0.05f); 
            glVertex2f(0.5f,0.05f);

            if (velocidadeRaioY <= -0.36f){
                //Raio de Abdução
                glColor3f(0.0f, 1.0f, 0.0f);
                glVertex2f(0.2f, 0.1f + velocidadeRaioY); 
                glVertex2f(0.13f, -0.2f);

                glVertex2f(-0.2f, 0.1f + velocidadeRaioY); 
                glVertex2f(-0.13f, -0.2f);

                //Base Raio de Abdução
                glVertex2f(0.10f, velocidadeRaioY); 
                glVertex2f(-0.10f, velocidadeRaioY);

                glVertex2f(0.10f, 0.2f + velocidadeRaioY); 
                glVertex2f(-0.10f, 0.2f + velocidadeRaioY);

                glVertex2f(0.2f, 0.1f + velocidadeRaioY); 
                glVertex2f(0.10f, velocidadeRaioY);

                glVertex2f(-0.2f, 0.1f + velocidadeRaioY); 
                glVertex2f(-0.10f, velocidadeRaioY);

                glVertex2f(0.2f, 0.1f + velocidadeRaioY); 
                glVertex2f(0.10f, 0.2f + velocidadeRaioY);

                glVertex2f(-0.2f, 0.1f + velocidadeRaioY); 
                glVertex2f(-0.10f, 0.2f + velocidadeRaioY);
            }





        glEnd();

        glDisable(GL_LINE_STIPPLE);
    glPopMatrix();

    glutSwapBuffers();
}
// --- Funções de Teclado ---

void tecladoEspecial(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            jogadorY += velocidade; // Sobe no eixo Y
            break;
        case GLUT_KEY_DOWN:
            jogadorY -= velocidade; // Desce no eixo Y
            break;
        case GLUT_KEY_LEFT:
            jogadorX -= velocidade; // Vai para esquerda no eixo X
            break;
        case GLUT_KEY_RIGHT:
            jogadorX += velocidade; // Vai para direita no eixo X
            break;
    }
    glutPostRedisplay();
}

void tecladoNormal(unsigned char key, int x, int y) {
    // A tecla ESC tem o código ASCII 27
    if (key == 27) { 
        exit(0); 
    }
    // Raio Laser
    if (key == 32){
        RaioLaser = !RaioLaser;
    }
}


void atualizaAnimacao(int valor) {
    if(velocidadeRaioY >= -1.0f && RaioLaser == true)
    velocidadeRaioY -= 0.01f;
    if(velocidadeRaioY <= -0.36f && RaioLaser == false)
    velocidadeRaioY += 0.01f;




    glutPostRedisplay();
    glutTimerFunc(16, atualizaAnimacao, 0);
}


// --- Função Principal ---
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("Explorando a Rasterizacao de Linhas Nativa");
    
    glutDisplayFunc(display);
    
    glutSpecialFunc(tecladoEspecial);
    glutKeyboardFunc(tecladoNormal);

    glutTimerFunc(25, atualizaAnimacao, 0);

        
    glutMainLoop();
    return 0;
}
