void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Configuração da Câmara:
    // Posicionada em (5, 5, 5), olhando para a origem (0, 0, 0), 
    // com o eixo Y a apontar para cima.
    gluLookAt(5.0, 5.0, 5.0,  // Eye (Posição)
              0.0, 0.0, 0.0,  // Center (Alvo)
              0.0, 1.0, 0.0); // Up (Vetor para cima)

    // Desenha o teu objeto (ex: um bule ou cubo)
    glutWireTeapot(1.0);

    glutSwapBuffers();
}