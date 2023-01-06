#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.test.h"
#include "../../src/file.h"
#include "../fixtures/fixtures.h"

/**
 * @brief test_create_file
 * @return 
 **/ 
void test_create_file(){
    int check_create_file = 0;
    FILE* fichier = NULL;
    create_file();
    fichier = fopen("resultGame.csv", "r");
    char line[256];
    
    if(fichier != NULL) {
        check_create_file = 1;

        if (fgets(line, sizeof (line), fichier)) {
            assert(strcmp(line, "game_id;max_round;round;player_1_response;player_1_time;player_1_montant;player_2_response;player_2_time;player_2_montant;\n") == 0);
        }
        fclose(fichier);
       
    }
    assert(check_create_file == 1);
    
}
/**
 * @brief test_addResultFile
 * @return 
 **/ 
void test_add_result_file(){
    create_file();
    Game* some_game_value = malloc(100);
    some_game_value = some_game();
    add_result_file(some_game_value);
    char* game_value_string = char_to_file(some_game_value);

    FILE* fichier = NULL;
    fichier = fopen("resultGame.csv", "r");
    char line[256];
    
    if(fichier != NULL) {
      
        while (fgets(line, sizeof (line), fichier)) {
        }
        assert(strcmp(game_value_string, line) == 0);
        fclose(fichier);
    }
}
/**
 * @brief test_file
 * @return 
 **/ 
void test_file(){
    test_create_file();
    test_add_result_file();
}