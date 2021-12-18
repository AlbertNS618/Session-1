void update(Customer *info){
    int tp = 0;
    int tempID;
    char tempRoom[255];
    long long int tempPrice;

    FILE *fpp = fopen("../customer/customer_data.txt", "r");

    while(fscanf(fpp, "C%d,%[^,],%d,%[^,],%[^,],%d,R00%d\n", &info[tp].cus_id, info[tp].cus_name, &info[tp].age, info[tp].death, info[tp].place, &info[tp].died, &info[tp].x.room_id) != EOF){
        // printf("C%d,%s,%d,%s,%s,%d,R%d\n", info[i].cus_id, info[i].cus_name, info[i].age, info[i].death, info[i].place, info[i].died, info[i].x.room_id);

        FILE *fkk = fopen("../room/room.txt", "r");

        while(fscanf(fkk, "R%d,%[^,],%lld\n", &tempID, tempRoom, &tempPrice) != EOF){
            if(tempID == info[tp].x.room_id){
                strcpy(info[tp].x.room_name, tempRoom);
                info[tp].x.price = tempPrice;
            }

        }
        fclose(fkk);

        tp++;
    }
    
    fclose(fpp);
}

void read(Customer *info){
    terbaru(info);

    printf("|   | ID   | Name  | Age | Room   |\n");
    printf("|---|------|-------|-----|--------|\n");
    for(int k = 0; k < i; k++){
        if(info[k].cus_id < 10){
            printf("| %d | C00%d ", k+1, info[k].cus_id);
        }
        else if(info[k].cus_id < 100){
            printf("| %d | C0%d ", k+1, info[k].cus_id);
        }
        else{
            printf("| %d | C%d ", k+1, info[k].cus_id);
        }
        printf("| %s | %d  | %s |\n", info[k].cus_name, info[k].age, info[k].x.room_name);
    }
}

void create(Customer *info){
    char name[255];
    int flag;

    do{
        flag = 0;
        printf("Name (lowercaase letters): ");
        getchar();
        scanf("%[^\n]", name);
        for(int l = 0; l < strlen(name); l++){
            if(name[l] < 'a' || name[l] > 'z'){
                flag++;
            }
        }
    }while(flag != 0);

    int umur;
    do{
        printf("Age (0 - 100): ");
        scanf("%d", &umur);
    }while(umur < 0 || umur > 100);

    char cause[255]; getchar();
    printf("Cause of Death (max 255 letters): ");
    scanf("%[^\n]", cause);

    char rest[255];
    getchar();
    printf("Resting Place (max 255 letters): ");
    scanf("%[^\n]", rest);

    char type[255];
    char pantai[] = "Pantai";
    char roof[] = "Rooftop";
    char taman[] = "Taman";
    char bar[] = "Bar";
    do{
        printf("Room Type (Pantai, Rooftop, Taman, Bar): ");
        getchar();
        scanf("%[^\n]", type);
    }while(strcmp(type, pantai) != 0 && strcmp(type, roof) != 0 && strcmp(type, taman) != 0 && strcmp(type, bar) != 0);
    
    printf("\nWelcome to Hotel del Jojo!\n");

    Customer *newInfo = (Customer*)malloc(sizeof(Customer));

    info[i].cus_id = i+1;
    strcpy(info[i].cus_name, name);
    info[i].age = umur;
    strcpy(info[i].death, cause);
    strcpy(info[i].place, rest);