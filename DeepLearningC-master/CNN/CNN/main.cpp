#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <matio.h>
#include "cnn.h"
#include "minst.h"
#include "Eigen\Dense"

// Function to read images from .mat file
ImgArr read_Img(const char* filename) {
    Mat_File* matfp = Mat_Open(filename, MAT_ACC_READ);
    if (matfp == NULL) {
        printf("Cannot open %s\n", filename);
        exit(1);
    }

    matvar_t* images_var = Mat_VarRead(matfp, "images");
    if (images_var == NULL) {
        printf("Cannot read variable 'images' from %s\n", filename);
        Mat_Close(matfp);
        exit(1);
    }

    double* data = (double*)images_var->data;
    int num_images = images_var->dims[0]; 
    int pixels = images_var->dims[1];

    if (pixels != 784) {
        printf("Invalid number of pixels in images matrix\n");
        Mat_VarFree(images_var);
        Mat_Close(matfp);
        exit(1);
    }

    ImgArr imgarr = (ImgArr)malloc(sizeof(MinstImgArr));
    imgarr->ImgNum = num_images;
    imgarr->ImgPtr = (MinstImg*)malloc(num_images * sizeof(MinstImg));

    for (int i = 0; i < num_images; i++) {
        imgarr->ImgPtr[i].r = 28;
        imgarr->ImgPtr[i].c = 28;
        imgarr->ImgPtr[i].ImgData = (float**)malloc(28 * sizeof(float*));
        for (int r = 0; r < 28; r++) {
            imgarr->ImgPtr[i].ImgData[r] = (float*)malloc(28 * sizeof(float));
            for (int c = 0; c < 28; c++) {
                int pixel_index = i * 784 + r * 28 + c;
                imgarr->ImgPtr[i].ImgData[r][c] = (float)data[pixel_index] / 255.0;
            }
        }
    }

    Mat_VarFree(images_var);
    Mat_Close(matfp);

    return imgarr;
}

// Function to read labels from .mat file
LabelArr read_Label(const char* filename) {
    Mat_File* matfp = Mat_Open(filename, MAT_ACC_READ);
    if (matfp == NULL) {
        printf("Cannot open %s\n", filename);
        exit(1);
    }

    matvar_t* labels_var = Mat_VarRead(matfp, "labels");
    if (labels_var == NULL) {
        printf("Cannot read variable 'labels' from %s\n", filename);
        Mat_Close(matfp);
        exit(1);
    }

    double* labels_data = (double*)labels_var->data;
    int num_labels = labels_var->dims[0];

    LabelArr labarr = (LabelArr)malloc(sizeof(MinstLabelArr));
    labarr->LabelNum = num_labels;
    labarr->LabelPtr = (MinstLabel*)malloc(num_labels * sizeof(MinstLabel));

    for (int i = 0; i < num_labels; i++) {
        labarr->LabelPtr[i].l = 10;
        labarr->LabelPtr[i].LabelData = (float*)calloc(10, sizeof(float));
        int label = (int)labels_data[i];
        if (label >= 0 && label < 10) {
            labarr->LabelPtr[i].LabelData[label] = 1.0;
        }
        else {
            printf("Invalid label: %d\n", label);
            // Handle error
        }
    }

    Mat_VarFree(labels_var);
    Mat_Close(matfp);

    return labarr;
}

// Function to free ImgArr memory
void free_ImgArr(ImgArr imgarr) {
    for (int i = 0; i < imgarr->ImgNum; i++) {
        for (int r = 0; r < imgarr->ImgPtr[i].r; r++) {
            free(imgarr->ImgPtr[i].ImgData[r]);
        }
        free(imgarr->ImgPtr[i].ImgData);
    }
    free(imgarr->ImgPtr);
    free(imgarr);
}

// Function to free LabelArr memory
void free_LabelArr(LabelArr labarr) {
    for (int i = 0; i < labarr->LabelNum; i++) {
        free(labarr->LabelPtr[i].LabelData);
    }
    free(labarr->LabelPtr);
    free(labarr);
}

// Main function
int main() {
    // Update file paths to your directory
    LabelArr trainLabel = read_Label("D:\\Codes\\C_programme\\DeepLearningC-master\\CNN\\Minst\\train_labels.mat");
    ImgArr trainImg = read_Img("D:\\Codes\\C_programme\\DeepLearningC-master\\CNN\\Minst\\train_images.mat");
    LabelArr testLabel = read_Label("D:\\Codes\\C_programme\\DeepLearningC-master\\CNN\\Minst\\test_labels.mat");
    ImgArr testImg = read_Img("D:\\Codes\\C_programme\\DeepLearningC-master\\CNN\\Minst\\test_images.mat");

    nSize inputSize = { testImg->ImgPtr[0].c, testImg->ImgPtr[0].r };
    int outSize = testLabel->LabelPtr[0].l;

    // CNN setup and training/testing code here

    // Free allocated memory
    free_ImgArr(trainImg);
    free_LabelArr(trainLabel);
    free_ImgArr(testImg);
    free_LabelArr(testLabel);

    return 0;
}