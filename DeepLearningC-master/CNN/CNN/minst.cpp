#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cassert>
#include "minst.h"

// 反转整数的字节序
int ReverseInt(int i) {
    return ((i & 0xFF) << 24) |
        ((i & 0xFF00) << 8) |
        ((i & 0xFF0000) >> 8) |
        ((i & 0xFF000000) >> 24);
}

ImgArr read_Img(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("open file failed");
        exit(EXIT_FAILURE);
    }

    int magic_number = 0;
    int number_of_images = 0;
    int n_rows = 0;
    int n_cols = 0;

    fread(&magic_number, sizeof(magic_number), 1, fp);
    magic_number = ReverseInt(magic_number);

    fread(&number_of_images, sizeof(number_of_images), 1, fp);
    number_of_images = ReverseInt(number_of_images);

    fread(&n_rows, sizeof(n_rows), 1, fp);
    n_rows = ReverseInt(n_rows);

    fread(&n_cols, sizeof(n_cols), 1, fp);
    n_cols = ReverseInt(n_cols);

    ImgArr imgarr = (ImgArr)malloc(sizeof(MinstImgArr));
    imgarr->ImgNum = number_of_images;
    imgarr->ImgPtr = (MinstImg*)malloc(number_of_images * sizeof(MinstImg));

    for (int i = 0; i < number_of_images; ++i) {
        imgarr->ImgPtr[i].r = n_rows;
        imgarr->ImgPtr[i].c = n_cols;
        imgarr->ImgPtr[i].ImgData = (float**)malloc(n_rows * sizeof(float*));
        for (int r = 0; r < n_rows; ++r) {
            imgarr->ImgPtr[i].ImgData[r] = (float*)malloc(n_cols * sizeof(float));
            for (int c = 0; c < n_cols; ++c) {
                unsigned char temp = 0;
                fread(&temp, sizeof(temp), 1, fp);
                imgarr->ImgPtr[i].ImgData[r][c] = (float)temp / 255.0;
            }
        }
    }

    fclose(fp);
    return imgarr;
}

LabelArr read_Label(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("open file failed");
        exit(EXIT_FAILURE);
    }

    int magic_number = 0;
    int number_of_labels = 0;
    int label_long = 10;

    fread(&magic_number, sizeof(magic_number), 1, fp);
    magic_number = ReverseInt(magic_number);

    fread(&number_of_labels, sizeof(number_of_labels), 1, fp);
    number_of_labels = ReverseInt(number_of_labels);

    LabelArr labarr = (LabelArr)malloc(sizeof(MinstLabelArr));
    labarr->LabelNum = number_of_labels;
    labarr->LabelPtr = (MinstLabel*)malloc(number_of_labels * sizeof(MinstLabel));

    for (int i = 0; i < number_of_labels; ++i) {
        labarr->LabelPtr[i].l = label_long;
        labarr->LabelPtr[i].LabelData = (float*)calloc(label_long, sizeof(float));
        unsigned char temp = 0;
        fread(&temp, sizeof(temp), 1, fp);
        labarr->LabelPtr[i].LabelData[(int)temp] = 1.0;
    }

    fclose(fp);
    return labarr;
}

char* intTochar(int i) {
    if (i == 0) {
        char* ptr = (char*)malloc(2 * sizeof(char));
        ptr[0] = '0';
        ptr[1] = '\0';
        return ptr;
    }

    int is_negative = i < 0;
    i = abs(i);

    int num_digits = 0;
    int temp = i;
    while (temp > 0) {
        num_digits++;
        temp /= 10;
    }

    if (is_negative) {
        num_digits++;
    }

    char* ptr = (char*)malloc((num_digits + 1) * sizeof(char));
    ptr[num_digits] = '\0';

    int index = num_digits - 1;
    while (i > 0) {
        ptr[index] = (i % 10) + '0';
        i /= 10;
        index--;
    }

    if (is_negative) {
        ptr[0] = '-';
    }

    return ptr;
}

char* combine_strings(const char* a, const char* b) {
    int lena = strlen(a);
    int lenb = strlen(b);
    char* ptr = (char*)malloc((lena + lenb + 1) * sizeof(char));
    strcpy(ptr, a);
    strcpy(ptr + lena, b);
    return ptr;
}

void save_Img(ImgArr imgarr, const char* filedir) {
    int img_number = imgarr->ImgNum;

    for (int i = 0; i < img_number; i++) {
        char* filename = combine_strings((char*)filedir, combine_strings(intTochar(i), ".gray"));
        FILE* fp = fopen(filename, "wb");
        if (fp == NULL) {
            perror("write file failed");
            free(filename);
            continue;
        }

        for (int r = 0; r < imgarr->ImgPtr[i].r; r++) {
            fwrite(imgarr->ImgPtr[i].ImgData[r], sizeof(float), imgarr->ImgPtr[i].c, fp);
        }

        fclose(fp);
        free(filename);
    }
}