#include "OpenGLWidget.hpp"

GLfloat const vertices[] = {
    -1.f, -1.f, 0.0f,
    -1.f, 1.f, 0.0f,
    1.f, -1.f, 0.0f,
    -1.f, 1.f, 0.0f,
    1.f, -1.f, 0.0f,
    1.f, 1.f, 0.f
};

void OpenGLWidget::initializeGL()
{
    makeCurrent();
    initializeOpenGLFunctions();

    loadingBarProgram = new QOpenGLShaderProgram();
    loadingBarProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, shaderPath + "load.frag");
    loadingBarProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, shaderPath + "dummy.vert");
    loadingBarProgram->link();
    qDebug() << loadingBarProgram->log(); // TODO: display error text on screen
    loadingBarProgram->bind();

    vertexBufferObject.create();
    vertexBufferObject.bind();
    vertexBufferObject.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vertexBufferObject.allocate(vertices, sizeof(vertices));

    vertexArrayObject.create();
    vertexArrayObject.bind();

    loadingBarProgram->enableAttributeArray(0);
    loadingBarProgram->setAttributeBuffer(0, GL_FLOAT, 0, 3);

    vertexBufferObject.release();
    vertexArrayObject.release();
    loadingBarProgram->release();

    // Initialize ifs program
    ifsProgram = new QOpenGLShaderProgram();
    ifsProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, shaderPath + "ifs.frag");
    ifsProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, shaderPath + "dummy.vert");
    ifsProgram->link();
    qDebug() << ifsProgram->log();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void OpenGLWidget::resizeGL()
{
    // Update projection matrix and other size related settings:
    m_projection.setToIdentity();
    m_projection.perspective(45.0f, w / float(h), 0.01f, 100.0f);
}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    ifsProgram->bind();
    vertexBufferObject.bind();
    vertexArrayObject.bind();
    ifsProgram->setUniformValue("iResolution", size());
    ifsProgram->setUniformValue("iTime",(GLfloat)((double)mediaPlayer->position() / 1000.));
    ifsProgram->setUniformValue("iFader0",(GLfloat).06);
    ifsProgram->setUniformValue("iFader1",(GLfloat).97);
        
    glDrawArrays(GL_TRIANGLES, 0, 6);

    vertexBufferObject.release();
    vertexArrayObject.release();
    ifsProgram->release();

    update();
}