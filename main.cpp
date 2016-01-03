//
// Created by Ha on 16. 1. 3..
//

/*
 * page 184
 * 한 문자열에 들어있는 단어의 순서를 뒤집는 함수를 작성하라. 예를 들어
 * "Do or do not there is no try."는 "try. no is there no to or Do"로 변환된어야 한다.
 * 모든 단어는 스페이스로 구분되고 문장부호는 글자와 똑같은 것으로 간주한다.
 */

#include <stdio.h>
#include <string.h>


// 문자열을 뒤집는 함수
void reverse(char *str, int start, int end){
    char temp;
    while(end > start){
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++; end--;
    }
}

// space로 각 단어를 구분하는 함수
// str에서 start부터 시작하여 다음에 나오는 space 직전의 indexf를 반환
int tokenizer(char *str, int start){
    int len = strlen(str);

    for(; start < len; start++){
        if(str[start] == ' ')
            break;
    }

    return --start;
}

// 문장 속 단어 뒤집기
void reverseWords(char str[]){
    int len = strlen(str);
    int start = 0, end = len - 1;
    int wordend;

    while(start < end){
        // space로 구분되는 한 단어의 끝의 위치
        wordend = tokenizer(str, start);

        // 한 단어를 reverse
        reverse(str, start, wordend);

        // space 이전 위치이므로 다음 단어 시작은 +2
        start = wordend + 2;
    }
}


int main(){
    char str[] = "Do or do not there is no try.\0";

    // 우선 문장 전체를 뒤집는다
    reverse(str, 0, strlen(str) - 1);

    // 뒤집혀진 문장안의 각 단어들을 뒤집는다
    reverseWords(str);

    printf(str);

    return 0;
}