#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dlitelnost 100 
#define vremya_odnogo 3     
#define veroyatnost_prihoda 30   

int main() {
    srand(time(NULL));

 
    int dlina_ocheredi = 0;   
    int obslujivaniye_clienta = 0;   
    

    int vsego_prishlo = 0;    
    int vsego_obslujili = 0;  
    int max_dlina_ocheredi = 0;   
    int vremya_ojidaniya = 0;  

    printf("=== Старт симуляции очереди (на 'Удовлетворительно') ===\n\n");

    // Основной цикл симуляции по тактам времени
    for (int vremya = 1; vremya <= dlitelnost; vremya++) {
        if (rand() % 100 < veroyatnost_prihoda) {
            dlina_ocheredi++;
            vsego_prishlo++;
            printf("[Минута %d] Пришел новый клиент. В очереди: %d\n", vremya, dlina_ocheredi);
        }

   
        if (dlina_ocheredi > 0) {
          
            if (obslujivaniye_clienta > 0) {
                vremya_ojidaniya += dlina_ocheredi;
            } else {
                vremya_ojidaniya += (dlina_ocheredi - 1);
            }
        }

      
        if (obslujivaniye_clienta > 0) {
        
            obslujivaniye_clienta--;
            if (obslujivaniye_clienta == 0) {
                vsego_obslujili++;
                printf("[Минута %d] Касса освободилась. Клиент обслужен.\n", vremya);
            }
        }

    
        if (obslujivaniye_clienta == 0 && dlina_ocheredi > 0) {
            dlina_ocheredi--; 
            obslujivaniye_clienta = vremya_odnogo; 
            printf("[Минута %d] Касса взяла клиента на обслуживание на %d мин. В очереди осталось: %d\n", 
                   vremya, vremya_odnogo, dlina_ocheredi);
        }

        if (dlina_ocheredi > max_dlina_ocheredi) {
            max_dlina_ocheredi = dlina_ocheredi;
        }
    }

    double srednee = 0;
    if (vsego_prishlo > 0) {
        srednee = (double)vremya_ojidaniya / vsego_prishlo;
    }

    printf("\n РЕЗУЛЬТАТЫ СИМУЛЯЦИИ \n");
    printf("Общее время работы:            %d мин.\n", dlitelnost);
    printf("Фиксированное время работы кассы: %d мин.\n", vremya_odnogo);
    printf("Всего пришло клиентов:         %d\n", vsego_prishlo);
    printf("Успешно обслужено клиентов:    %d\n", vsego_obslujili);
    printf("Осталось в очереди в конце:    %d\n", dlina_ocheredi);
    printf("МАКСИМАЛЬНАЯ ДЛИНА ОЧЕРЕДИ:    %d чел.\n", max_dlina_ocheredi);
    printf("СРЕДНЕЕ ВРЕМЯ ОЖИДАНИЯ:        %.2f мин.\n", srednee);

    FILE *file = fopen("simulation_report.txt", "w");
    if (file != NULL) {
        fprintf(file, "                  РЕЗУЛЬТАТЫ СИМУЛЯЦИИ\n");
        fprintf(file, "Общее время работы:            %d мин.\n", dlitelnost);
        fprintf(file, "Фиксированное время работы кассы: %d мин.\n", vremya_odnogo);
        fprintf(file, "Всего пришло клиентов:         %d\n", vsego_prishlo);
        fprintf(file, "Успешно обслужено клиентов:    %d\n", vsego_obslujili);
        fprintf(file, "Осталось в очереди в конце:    %d\n", dlina_ocheredi);
        fprintf(file, "МАКСИМАЛЬНАЯ ДЛИНА ОЧЕРЕДИ:    %d чел.\n", max_dlina_ocheredi);
        fprintf(file, "СРЕДНЕЕ ВРЕМЯ ОЖИДАНИЯ:        %.2f мин.\n", srednee);
        fclose(file);
        printf("\n[Успешно] Результаты сохранены в файл 'simulation_report.txt'\n");
    } else {
        printf("\n[Ошибка] Не удалось сохранить результаты в файл.\n");
    }

    return 0;
}