registration
    struct login
    {
       char Name[100] ;
       char Username[20];
       char Password[20];
    };
    regi()
    {
        FILE *log;
        log=fopen("Login.txt","w");
        struct login l;
        printf("Enter Name: ");
        scanf("%s",l.Name);
        printf("Enter User Name: ");
        scanf("%s",l.Username);
        printf("Enter pass word: ");
        scanf("%s",l.Password);
        //adding the entered data in a txt file
        fwrite(&l,sizeof(l),1,log);
        fclose(log);
        printf("Registration compleat");
        printf("\n Press any key to continue");
        getch();
        system("CLS");
        login();
    }
    login()
    {
        char username[20];
        char password[20];
        FILE *log;
        log=fopen("Login.txt","r");
        struct login l;
        printf("Enter User Name: ");
        scanf("%s",&username);
        printf("Enter Password: ");
        scanf("%s",&password);
        //running loop to compare the user name and password
        while(fread(&l,sizeof(l),1,log))
        {
            if(strcmp(username,l.Username)==0&&strcmp(password,l.Password)==0)
            {
                printf("Login Successful");
                menu();
            }
            else
            {
                printf("Wrong User Name or Password");
            }
        }
        fclose(log);

    }