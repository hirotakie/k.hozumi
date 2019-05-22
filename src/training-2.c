/*コマンドライン引数1 >>>ユーザー指定の読み込み用.csv  argv[1]
  コマンドライン引数2 >>>ユーザー指定のファイル出力用.csv argv[2]
  */
  /*printf("%d",argc);
    printf("%s",argv[1]);*/
//構造体 
typedef struct input_data{
    //店名
    char restaurant_name[20];
    //評価
    //double restaurant_evaluation;
    char restaurant_evaluation[4];
    //場所
    char restaurant_place[100];
    //ジャンル
    char restaurant_type[20];
    //URL
    char restaurant_URL[100];
    //概要
    char restaurant_outline[200];
    //リスト構造体用のポインタ変数
    struct input_data* next;
}DATA;

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//プロトタイプ宣言s
DATA file_data_read(char* temp_argv);
int input_restaurant_data();
int search_restaurant_data();

//main
int main(int argc, char* argv[]){
    //処理判断の引数:num FILE用:before_csvFile カウンタ変数:i
    int num = 0;
    FILE* before_csvFile = NULL;
    int i = 0;
    DATA before_data;
    
    //引数の数チェック
    if(argc != 3){
        printf("E0001: 引数の数が不一致です。");
        return 1;
    }

    //ファイルが存在するか確認 <<<開く必要あるか?
    before_csvFile = fopen(argv[1],"r");
    if(before_csvFile == NULL){
        printf("E0002: CSVファイルが指定されていません。\n");
        return 1;
    }else{
        fclose(before_csvFile);
    }

    //ファイルオープン確認
    before_csvFile = fopen(argv[1],"a");
    if(before_csvFile == NULL){ 
        printf("E0003: ファイルオープンに失敗しました。\n");
        return 1;
    }
    fclose(before_csvFile);
    
    //ファイル読み込み
    before_data = file_data_read(argv[1]);
    
    /*if(before_data.restaurant_name[0] == NULL){
        return 1;
    }*/
    //printf("%s",before_data.restaurant_name);

    //引数の入力
    printf("行いたい処理を選択してください。 データ入力<<< 1  検索<<< 2 \n");
    scanf("%d",&num);
    //引数の判断
    if(num == 1){
        input_restaurant_data();
    }else if(num == 2){
        search_restaurant_data();
    }else{
        printf("E0004: 引数が正しく入力されていません。");
        return 1;
    }


    return 0;
}

//ファイル読み込み用関数:data_read 入力用ファイル受け取り:temp_argv  before_dataの参照:data
DATA file_data_read(char* temp_argv){
    //変数
    FILE* csvFile = NULL;
    char memory = '\0';
    int i = 0;
    DATA data;
    //ファイルオープン
    csvFile = fopen(temp_argv,"r");
    if(csvFile == NULL){ 
        printf("E0003: ファイルオープンに失敗しました。\n");
        //data.restaurant_name[0] = '0';
        return data;
    }

    //読み込み
    //店名
    for(i = 0; i < 20; i++){
        int input = fgetc(csvFile);
        memory = input;
        putchar(memory);
        if(memory == ',' || input == EOF){
            data.restaurant_name[i] = '\0';
            break;
        }else{
            data.restaurant_name[i] = memory;
        }
    }
    //printf("%s",data.restaurant_name);
    //評価 atofで変換したい　   double restaurant_evaluation
    for(i = 0; i < 3; i++){
        int input = fgetc(csvFile);
        memory = input;
        putchar(memory);
        if(memory == ',' || input == EOF){
            data.restaurant_evaluation[i] = '\0';
            break;
        }else{
            data.restaurant_evaluation[i] = memory;
        }
    }
    //printf("%s",data.restaurant_evaluation);

    //場所
    memory = '\0';
    for(i = 0; i < 100; i++){
        int input = fgetc(csvFile);
        memory = input;
        putchar(memory);
        if(memory == ',' || input == EOF){
            data.restaurant_place[i] = '\0';
            break;
        }else{
            data.restaurant_place[i] = memory;
        }
    }
    //printf("%s",data.restaurant_place);
    //ジャンル
    memory = '\0';
    for(i = 0; i < 20; i++){
        int input = fgetc(csvFile);
        memory = input;
        putchar(memory);
        if(memory == ',' || input == EOF){
            data.restaurant_type[i] = '\0';
            break;
        }else{
            data.restaurant_type[i] = memory;
        }
    }
    //printf("%s",data.restaurant_type);
    //URL
    memory = '\0';
    for(i = 0; i < 100; i++){
        int input = fgetc(csvFile);
        memory = input;
        putchar(memory);
        if(memory == ',' || input == EOF){
            data.restaurant_URL[i] = '\0';
            break;
        }else{
            data.restaurant_URL[i] = memory;
        }
    }
    //printf("%s",data.restaurant_URL);
    //概要
    /*memory = '\0';
    for(i = 0; i < 100; i++){
        int input = fgetc(csvFile);
        memory = input;
        putchar(memory);
        if(memory == ',' || input == EOF){
            data.restaurant_outline[i] = '\0';
            break;
        }else{
            data.restaurant_outline[i] = memory;
        }
    }*/
    fgets(data.restaurant_outline,200,csvFile);
    printf("%s",data.restaurant_outline);
    //printf("%s",data.restaurant_outline);
    

    return data;
}

//データ入力 input_restaurant_data
int input_restaurant_data( ){

    




    return 0;
}

//検索　search_restaurant_data
int search_restaurant_data(){


    return 0;
}
