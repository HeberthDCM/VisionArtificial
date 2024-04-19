#include <opencv2/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // Leer la imagen original
    cv::Mat original_image = cv::imread("F:/Jesus/UNSA/Maestria/Cursos/VisionArtificial/Tareas/Tarea2Ecualizar/kodim08_grayscale.png", cv::IMREAD_GRAYSCALE);
    if (original_image.empty()) {
        std::cerr << "No se pudo cargar la imagen original." << std::endl;
        return -1;
    }

    // Leer el histograma ecualizado 
    int histograma_ecualizado[256] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 10, 10, 10, 10, 10, 13, 13, 13, 13, 16, 16, 16, 20, 20, 20, 20, 24, 25, 25, 29, 30, 30, 34, 34, 34, 38, 38, 42, 42, 43, 46, 46, 50, 50, 54, 54, 58, 58, 61, 61, 65, 65, 69, 69, 72, 72, 76, 76, 79, 79, 82, 85, 85, 88, 88, 91, 94, 94, 98, 100, 100, 103, 106, 106, 109, 114, 114, 117, 119, 122, 122, 124, 126, 128, 128, 129, 131, 133, 134, 134, 136, 137, 139, 140, 141, 143, 144, 144, 146, 147, 148, 149, 151, 152, 153, 155, 156, 158, 159, 161, 163, 164, 166, 168, 169, 171, 172, 174, 175, 176, 178, 179, 180, 181, 182, 182, 183, 184, 185, 186, 186, 187, 188, 189, 189, 190, 191, 191, 192, 192, 193, 194, 194, 195, 195, 196, 196, 197, 197, 198, 198, 199, 199, 200, 200, 200, 201, 201, 202, 202, 203, 203, 203, 204, 204, 204, 205, 205, 206, 206, 206, 207, 207, 208, 208, 208, 209, 209, 209, 210, 210, 211, 211, 212, 212, 212, 213, 213, 214, 214, 215, 216, 216, 217, 217, 218, 219, 220, 221, 222, 223, 225, 226, 227, 229, 231, 233, 234, 235, 237, 238, 239, 240, 241, 242, 243, 243, 244, 244, 245, 245, 245, 246, 246, 246, 247, 247, 247, 248, 248, 249, 255 }; // Aquí estarían los valores del histograma ecualizado

    // Crear una matriz cv::Mat para almacenar el histograma ecualizado
    cv::Mat histogram_mat(256, 1, CV_32SC1);

    // Copiar los valores del array al contenido de la matriz cv::Mat
    for (int i = 0; i < 256; ++i) {
        histogram_mat.at<int>(i, 0) = histograma_ecualizado[i];
    }

    
    cv::Mat ecualizada;
    cv::LUT(original_image, histogram_mat, ecualizada);

    // Mostrar la imagen ecualizada
    cv::imshow("Imagen ecualizada", ecualizada);
    cv::waitKey(0);

    return 0;
}