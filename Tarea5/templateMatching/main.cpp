/*#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>


void showMatriz(const cv::Mat& mat) {
    unsigned char* input1 = (unsigned char*)(mat.data);

    //std::cout << input1 << std::endl;

    std::cout << "{";
    for (int i = 0; i < mat.cols; ++i) {       
        for (int j = 0; j < mat.rows; ++j) {
            int prom_img = input1[mat.step * j + i];
            std::cout << prom_img << ",";
        }
        std::cout << std::endl;
    }
    std::cout << "}\n";
}

// Función para calcular la distancia euclidiana entre dos matrices
double calcularDistanciaEuclidiana(const cv::Mat& mat1, const cv::Mat& mat2) {
    if (mat1.size() != mat2.size()) {
        std::cout << "Las matrices deben tener el mismo tamaño\n";
        return -1;
    }

    showMatriz(mat1);
    showMatriz(mat2);

    unsigned char* input1 = (unsigned char*)(mat1.data);
    unsigned char* input2 = (unsigned char*)(mat2.data);
    double sum = 0.0;
    int r, g, b, r_t, g_t, b_t;

    for (int i = 0; i < mat1.rows; ++i) {
        for (int j = 0; j < mat1.cols; ++j) {

            b = input1[mat1.cols * j + i];
            g = input1[mat1.cols * j + i + 1];
            r = input1[mat1.cols * j + i + 2];
            float prom_img = (b + g + r) / 3;


            b_t = input2[mat1.cols * j + i];
            g_t = input2[mat1.cols * j + i + 1];
            r_t = input2[mat1.cols * j + i + 2];
            float prom_tem = (b_t + g_t + r_t) / 3;
            //std::cout << "Datos " << mat1.at<float>(i, j) << " " << mat2.at<float>(i, j) << std::endl;
            double diff = prom_img - prom_tem;
            sum += diff * diff;
            std::cout << "La suma hasta ahora es: " << sum << std::endl;
        }
    }
    return std::sqrt(sum);
}

// Función para generar submatrices de la imagen principal
int* generarSubmatrices(const cv::Mat& img, const cv::Mat& templ) {

    int x_point, y_point;
    std::cout << "Filas: " << img.rows << std::endl;
    std::cout << "Columnas: " << img.cols << std::endl;

    std::cout << "Template Filas: " << templ.rows << std::endl;
    std::cout << "Template Columnas: " << templ.cols << std::endl;

    showMatriz(img);
    showMatriz(templ);

    for (int i = 0; i <= img.rows - templ.rows; ++i) {
        for (int j = 0; j <= img.cols - templ.cols; ++j) {
            cv::Mat subImg = img(cv::Rect(j, i, templ.cols, templ.rows));

            double distancia = calcularDistanciaEuclidiana(subImg, templ);
            std::cout << distancia << "\n";
            if (distancia == 0) {
                x_point = j;
                y_point = i;
                return new int[x_point, y_point];
            }
        }
    }
    return new int[0, 0];
}

int main() {
    // Cargar la imagen y la plantilla
    cv::Mat img = cv::imread("F:\\Jesus\\UNSA\\Maestria\\Cursos\\VisionArtificial\\golum_mini.png", cv::IMREAD_GRAYSCALE);
    cv::Mat templ = cv::imread("F:\\Jesus\\UNSA\\Maestria\\Cursos\\VisionArtificial\\golum_minitemplate.png", cv::IMREAD_GRAYSCALE);

    if (img.empty() || templ.empty())
    {
        std::cout << "Error al cargar las imagenes\n";
        return -1;
    }
    // Generar submatrices y calcular la distancia euclidiana
    int* resultado = generarSubmatrices(img, templ);
    std::cout << "Resultados de puntos encontrados: x -> " << resultado[0] << " y -> " << resultado[0] << std::endl;
    return 0;
}*/



#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Cargar la imagen y la plantilla
    cv::Mat img = cv::imread("F:\\Jesus\\UNSA\\Maestria\\Cursos\\VisionArtificial\\golum_mini.PNG", cv::IMREAD_GRAYSCALE);
    cv::Mat templ = cv::imread("F:\\Jesus\\UNSA\\Maestria\\Cursos\\VisionArtificial\\golum_minitemplate.PNG", cv::IMREAD_GRAYSCALE);

    if (img.empty() || templ.empty())
    {
        std::cout << "Error al cargar las imagenes\n";
        return -1;
    }

    // Crear la matriz de resultados
    cv::Mat result;
    result.create(img.rows - templ.rows + 1, img.cols - templ.cols + 1, CV_32FC1);

    // Realizar el template matching con método de correlación normalizada
    cv::matchTemplate(img, templ, result, cv::TM_CCOEFF_NORMED);

    // Localizar la mejor coincidencia con minMaxLoc
    double minVal;
    double maxVal;
    cv::Point minLoc;
    cv::Point maxLoc;
    cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat());

    // La mejor coincidencia es el máximo valor en TM_CCOEFF_NORMED
    cv::Point matchLoc = maxLoc;

    // Dibujar un rectángulo alrededor de la mejor coincidencia
    cv::rectangle(img, matchLoc, cv::Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), cv::Scalar::all(0), 2, 8, 0);

    // Mostrar la imagen
    cv::imshow("Imagen", img);

    // Esperar a que el usuario presione una tecla
    cv::waitKey(0);

    return 0;
}
