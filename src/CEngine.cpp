#include <cstdlib>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "shine/CEngine.hpp"


bool opengl_inited = false;
bool glfw_inited = false;
bool loadOpenGL() {
	if (!gladLoadGL()) {
//		std::cout << "Failed to initialize OpenGL context" << std::endl;
		opengl_inited = false;
		return false;
	}
	opengl_inited = true;
	return true;
}

bool loadGLFW() {
	if(!glfwInit()) {
		glfw_inited = false;
		return false;
	}
	glfw_inited = true;
	return true;
}

bool CEngine::init() {
	if(!loadGLFW()) return false;
	
	win = glfwCreateWindow(100,100,"hello",NULL,NULL);
	
	glfwMakeContextCurrent(this->win);

	if(!loadOpenGL()) return false;

	return true;
}

bool CEngine::run() {
	
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	

	while(!glfwWindowShouldClose(win))
		update();

	return true;
}

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path){

    // Создаем шейдеры
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    // Загружаем код Вершинного Шейдера из файла
    std::string VertexShaderCode;
    std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
    if(VertexShaderStream.is_open())
    {
        std::stringstream sstr;
        sstr << VertexShaderStream.rdbuf();
        VertexShaderCode = sstr.str();
        VertexShaderStream.close();
    }

    // Загружаем код Фрагментного шейдера из файла
    std::string FragmentShaderCode;
    std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
    if(FragmentShaderStream.is_open()){
        std::stringstream sstr;
        sstr << FragmentShaderStream.rdbuf();
        FragmentShaderCode = sstr.str();
        FragmentShaderStream.close();
    }

    GLint Result = GL_FALSE;
    int InfoLogLength;

    // Компилируем Вершинный шейдер
    printf("Компиляция шейдера: %sn", vertex_file_path);
    char const * VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
    glCompileShader(VertexShaderID);

    // Выполняем проверку Вершинного шейдера
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
      std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
      glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
      fprintf(stdout, "%sn", &VertexShaderErrorMessage[0]);
    }

    // Компилируем Фрагментный шейдер
    printf("Компиляция шейдера: %sn", fragment_file_path);
    char const * FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
    glCompileShader(FragmentShaderID);

    // Проверяем Фрагментный шейдер
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
      std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
      glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
      fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);
    }

    // Создаем шейдерную программу и привязываем шейдеры к ней
    fprintf(stdout, "Создаем шейдерную программу и привязываем шейдеры к нейn");
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);

    // Проверяем шейдерную программу
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
      std::vector<char> ProgramErrorMessage(InfoLogLength+1);
      glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
      fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);
    }

    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);

    return ProgramID;
}

bool CEngine::update() {
	GLuint programID = LoadShaders("vertex.vsh","frag.fsh");
	
	GLuint vertexbuffer;

	// Создадим 1 буфер и поместим в переменную vertexbuffer его идентификатор
	glGenBuffers(1, &vertexbuffer);

	// Сделаем только что созданный буфер текущим
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	
	static const GLfloat g_vertex_buffer_data[] = {
	   -1.0f, -1.0f, 0.0f,
	   1.0f, -1.0f, 0.0f,
	   0.0f,  1.0f, 0.0f,
	};



	// Передадим информацию о вершинах в OpenGL
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	// Указываем, что первым буфером атрибутов будут вершины
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
	   0,                  // Атрибут 0. Подробнее об этом будет рассказано в части, посвященной шейдерам.
		   3,                  // Размер
	   GL_FLOAT,           // Тип
	   GL_FALSE,           // Указывает, что значения не нормализованы
	   0,                  // Шаг
	   (void*)0            // Смещение массива в буфере
	);

	// Вывести треугольник!
	glDrawArrays(GL_TRIANGLES, 0, 3); // Начиная с вершины 0, всего 3 вершины -> один треугольник

	glDisableVertexAttribArray(0);	

	glClearColor(0.1,0.3,0.5,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glFlush();
	glfwSwapBuffers(win);
	glfwPollEvents();
	glUseProgram(programID);
	return true;
}

bool CEngine::destroy() {
	if(!glfw_inited)
		return false;
	glfwTerminate();
	glfw_inited = false;
	return true;
}

CEngine::CEngine() {
}
CEngine::~CEngine() {
	destroy();
}


