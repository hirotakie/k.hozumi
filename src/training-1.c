//コマンドライン引数>>>　da:データ入力　se::検索
//構造体 
typedef struct input_data{
    //店名
    char restaurant_name[20];
    //評価
    double restaurant_evaluation;
    //char restaurant_evaluation[4];
    //場所
    char restaurant_place[100];
    //ジャンル
    char restaurant_type[20];
    //URL
    char restaurant_URL[100];
    //概要
    char restaurant_outline[100];
    //リスト構造体用のポインタ変数
    struct input_data* next;
}DATA;

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//プロトタイプ宣言s
int file_data_read();
int input_restaurant_data();
int search_restaurant_data();

//main
int main(int argc, char* argv[]){
    /*printf("%d",argc);
    printf("%s",argv[1]);*/
    //処理判断の引数:num FILE用:before_csvfile カウンタ変数:i
    int num = 0;
    FILE* before_csvfile = NULL;
    int i = 0;
    
    //引数の数チェック
    if(argc != 2){
        printf("E0001: 引数の数が不一致です。");
        return 1;
    }

    //ファイルが存在するか確認
    before_csvfile = fopen("restaurant_data.csv","r");
    if(before_csvfile == NULL){
        printf("E0002: CSVファイルが指定されていません。\n");
        return 1;
    }else{
        fclose(before_csvfile);
    }
    
    //ファイルが開くか確認
    file_data_read();
    
    /*引数の入力
    printf("行いたい処理を選択してください。 データ入力<<< 1  検索<<< 2 \n");
    scanf("%d",&num);*/
    //引数の判断
    if(argv[1] == "da"){
        input_restaurant_data();
    }else if(argv[1] == "se"){
        search_restaurant_data();
    }else{
        printf("E0004: 引数が正しく入力されていません。");
        return 1;
    }


    return 0;
}

//ファイル読み込み用関数: data_read
int file_data_read(){
    //変数
    FILE* csvfile = NULL;
    DATA data;
    char memory = '\0';
    int i = 0;

    //ファイルオープン確認
    csvfile = fopen("restaurant_data.csv","w");
    if(csvfile == NULL){ 
        printf("E0003: ファイルオープンに失敗しました。\n");
        return 1;
    }

    //読み込み
    //店名
    int input = fgetc(csvfile);
        memory = input;
        putchar(input);
    for(i = 0; i < 20; i++){
        int input = fgetc(csvfile);
        memory = input;
        //putchar(memory);
        if(memory == ',' || input == EOF){
            data.restaurant_name[i] = '\0';
            break;
        }else{
            data.restaurant_name[i] = memory;
        }
    }
    printf("%s",data.restaurant_name);
    //評価
    /*for(i = 0; i < 3; i++){
        int input = fgetc(csvfile);
        memory = input;
        if(memory == ',' || input == EOF){
            data.restaurant_evaluation[i] = '\0';
            break;
        }else{
            data.restaurant_evaluation[i] = memory;
        }
    }*/
    //場所
    /*memory = '\0';
    for(i = 0; i < 100; i++){
        int input = fgetc(csvfile);
        memory = input;
        if(memory == ',' || input == EOF){
            data.restaurant_place[i] = '\0';
            break;
        }else{
            data.restaurant_place[i] = memory;
        }
    }
    //ジャンル
    memory = '\0';
    for(i = 0; i < 20; i++){
        int input = fgetc(csvfile);
        memory = input;
        if(memory == ',' || input == EOF){
            data.restaurant_type[i] = '\0';
            break;
        }else{
            data.restaurant_type[i] = memory;
        }
    }
    //URL
    memory = '\0';
    for(i = 0; i < 100; i++){
        int input = fgetc(csvfile);
        memory = input;
        if(memory == ',' || input == EOF){
            data.restaurant_URL[i] = '\0';
            break;
        }else{
            data.restaurant_URL[i] = memory;
        }
    }
    //概要
    memory = '\0';
    for(i = 0; i < 100; i++){
        int input = fgetc(csvfile);
        memory = input;
        if(memory == ',' || input == EOF){
            data.restaurant_outline[i] = '\0';
            break;
        }else{
            data.restaurant_outline[i] = memory;
        }
    }

*/
    return 0;
}

//データ入力 input_restaurant_data
int input_restaurant_data( ){

    




    return 0;
}

//検索　search_restaurant_data
int search_restaurant_data(){


    return 0;
}